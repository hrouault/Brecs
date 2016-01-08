/**
 * Brecs
 *
 * @author Herve Rouault
 */

//package ij.plugin;
import ij.*;
import ij.process.*;
import ij.gui.GenericDialog;
import ij.plugin.PlugIn;
import cz.adamh.utils.NativeUtils;
import java.io.IOException;


public class B_recs implements PlugIn {

    public static final String PLUGIN_VERSION = "0.1";

    private static String title_recons = "";
    private static String title_psf = "";

    public void run(String arg) {
        try {
            NativeUtils.loadLibraryFromJar("/libB_recs.jnilib");
        } catch (IOException e) {
            // This is probably not the best way to handle exception :-)
            e.printStackTrace();
        }

        int[] wList = WindowManager.getIDList();
        if (wList==null) {
            IJ.noImage();
            return;
        }
        String[] titles = new String[wList.length];
        for (int i=0; i<wList.length; i++) {
            ImagePlus imp = WindowManager.getImage(wList[i]);
            if (imp!=null)
                titles[i] = imp.getTitle();
            else
                titles[i] = "";
        }

        GenericDialog gd = new GenericDialog("B-recs (version: "
                + PLUGIN_VERSION + ")");

        String defaultItem;
        if (title_recons.equals(""))
			defaultItem = titles[0];
		else
			defaultItem = title_recons;
        gd.addChoice("Image to reconstruct:", titles, defaultItem);

        if (title_psf.equals(""))
			defaultItem = titles[0];
		else
			defaultItem = title_psf;
        gd.addChoice("PSF:", titles, defaultItem);
        gd.addStringField("background (optional)", "");
        gd.addNumericField("Fluorophore mean intensity", 2000.0, 1);
        gd.addNumericField("Fluorophore intensity standard deviation", 500.0, 1);
        gd.addNumericField("Fluorophore density", 0.001, 1);
        gd.addNumericField("Camera amplification factor", 1.0, 1);
        gd.addNumericField("Noise offset", 1000.0, 1);
        gd.addNumericField("Number of iterations", 200, 1);
        gd.addNumericField("Background intensity", 200.0, 1);
        gd.showDialog();
        if (gd.wasCanceled()) {
            return;
        }

        int index_source = gd.getNextChoiceIndex();
        ImagePlus img_source = WindowManager.getImage(wList[index_source]);
        if (img_source.getBitDepth() != 16) {
            IJ.showMessage("Error",
                           "The input image pixel depth should be 16 bit");
            return;
        }
        int index_psf = gd.getNextChoiceIndex();
        ImagePlus img_psf = WindowManager.getImage(wList[index_psf]);
        if (img_psf.getBitDepth() != 32) {
            IJ.showMessage("Error",
                           "The psf image pixel depth should be 32 bit (float)");
            return;
        }

        // Launch the linked Brecs library
        Brecs brecsrun = new Brecs();

        imagessimp_t image = new imagessimp_t();
        paramssimp_t params = new paramssimp_t();
        params.setPixmean((float)gd.getNextNumber());
        params.setPixstd((float)gd.getNextNumber());
        float rho = (float)gd.getNextNumber();
        params.setMesampli((float)gd.getNextNumber());
        params.setNoiseoffset((float)gd.getNextNumber());
        params.setNbiter((float)gd.getNextNumber());
        params.setMeanback((float)gd.getNextNumber());

        ImageProcessor ipsource = img_source.getChannelProcessor();
        short [] pixels = (short [])(ipsource.getPixels());
        int meswidth = ipsource.getWidth();
        int mesheight = ipsource.getHeight();
        brecsrun.brecs_initin(image, pixels, meswidth, mesheight);

        int kersize = img_psf.getChannelProcessor().getWidth();
        int stacksize = img_psf.getImageStackSize();
        int pixsdiv = (int)Math.sqrt(stacksize);
        brecsrun.brecs_initpsf(image, params, kersize, pixsdiv);
        for (int i = 0; i < stacksize; i++) {
            img_psf.setSliceWithoutUpdate(i + 1);
            float [] psf = (float [])(img_psf.getChannelProcessor().getPixels());
            brecsrun.brecs_addpsfslice(image, params, psf, i);
        }

        brecsrun.brecs_reconstruction(image, params);

        System.out.println("redisplay images");
        // Redisplay images
        int kerheight = kersize * pixsdiv * pixsdiv;
        float [] ker_redisp = new float[kersize * kerheight];
        int widthmes = (int)image.getImgmes().getSize().getSx();
        int heightmes = (int)image.getImgmes().getSize().getSy();
        float [] imgmes_redisp = new float[widthmes * heightmes];
        int widthcc = (int)image.getCcomp().getSize().getSx();
        int heightcc = (int)image.getCcomp().getSize().getSy();
        int [] ccomp_redisp = new int[widthcc * heightcc];
        int widthrec = (int)image.getRecons().getSize().getSx();
        int heightrec = (int)image.getRecons().getSize().getSy();
        float [] recons_redisp = new float[widthrec * heightrec];
        int [] over_redisp = new int[widthrec * heightrec];
        brecsrun.recopy(image, ker_redisp, imgmes_redisp,
                        ccomp_redisp, recons_redisp, over_redisp);

        ImageProcessor ipker = new FloatProcessor(kersize, kerheight);
        ipker.setPixels(ker_redisp);
        ImagePlus imgker = new ImagePlus("Replotted psf", ipker);
        imgker.show();

        ImageProcessor ipmes = new FloatProcessor(widthmes, heightmes);
        ipmes.setPixels(imgmes_redisp);
        ImagePlus imgmes = new ImagePlus(
                "Image in number of photons, background substracted", ipmes);
        imgmes.show();

        ImageProcessor ipcc = new ColorProcessor(widthcc, heightcc);
        ipcc.setPixels(ccomp_redisp);
        ImagePlus imgcc = new ImagePlus(
                "Connected component decomposition", ipcc);
        imgcc.show();

        ImageProcessor ipres = new FloatProcessor(widthrec, heightrec);
        ipres.setPixels(recons_redisp);
        ImagePlus imgres = new ImagePlus("Reconstruction", ipres);
        imgres.show();

        ImageProcessor ipover = new ColorProcessor(widthrec, heightrec);
        ipover.setPixels(over_redisp);
        ImagePlus imgover = new ImagePlus("Overlay", ipover);
        imgover.show();

        return;
    }

    public void showAbout() {
        IJ.showMessage("Brecs",
                "A package for dense localization microscopy reconstruction");
    }
}
