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
//import ij.io.Button;


public class B_recs implements PlugIn {
    private static String image_to_analyze = "";
    private static String psf = "";

    public static final String PLUGIN_VERSION = "0.1";
	//protected ImagePlus image;

    // Native functions (test)
    public native String returnHello(String text);

	// image property members
	private int width;
	private int height;

	// plugin parameters
	public double value;
	public String name;

    // image files
    private static String title_recons = "";
    private static String title_psf = "";

    //public void run(String ignored) {
    public void run(String arg) {
        try {
            NativeUtils.loadLibraryFromJar("/libB_recs.jnilib");
        } catch (IOException e) {
            // This is probably not the best way to handle exception :-)
            e.printStackTrace();
        }
        //System.loadLibrary("B_recs");

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
        gd.addNumericField("Fluorophore mean intensity", 5000.0, 1);
        gd.addNumericField("Fluorophore intensity standard deviation", 500.0, 1);
        gd.addNumericField("Camera amplification factor", 1.0, 1);
        gd.addNumericField("Noise offset", 1000.0, 1);
        gd.addNumericField("Number of iterations", 200, 1);
        gd.addNumericField("Background intensity", 200.0, 1);
        gd.showDialog();
        if (gd.wasCanceled()) {
            return;
        }

        int index_recons = gd.getNextChoiceIndex();
        ImagePlus img_recons = WindowManager.getImage(wList[index_recons]);
        if (img_recons.getBitDepth() != 16) {
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

        Brecs brecsrun = new Brecs();

        imagessimp_t image = new imagessimp_t();
        paramssimp_t params = new paramssimp_t();
        params.setPixmean((float)gd.getNextNumber());
        params.setPixstd((float)gd.getNextNumber());
        params.setMesampli((float)gd.getNextNumber());
        params.setNoiseoffset((float)gd.getNextNumber());
        params.setNbiter((float)gd.getNextNumber());
        params.setMeanback((float)gd.getNextNumber());

        ImageProcessor ipin = img_recons.getChannelProcessor();
        short [] pixels = (short [])(ipin.getPixels());
        int meswidth = ipin.getWidth();
        int mesheight = ipin.getHeight();
        brecsrun.brecs_initin(image, pixels, meswidth, mesheight);

        int kersize = img_psf.getChannelProcessor().getWidth();
        int stacksize = img_psf.getImageStackSize();
        int pixsdiv = (int)Math.sqrt(stacksize);
        brecsrun.brecs_initpsf(image, params, kersize, pixsdiv);
        float [] psf;
        for (int i = 0; i < stacksize; i++) {
            img_psf.setSliceWithoutUpdate(i + 1);
            psf = (float [])(img_psf.getChannelProcessor().getPixels());
            brecsrun.brecs_addpsfslice(image, params, psf, i);
        }

        brecsrun.brecs_initimgmessimp(image, params);


        System.out.println("redisplay images: imgker");
        // Redisplay images
        int widthker = (int)image.getKer().getSize().getSx();
        int heightker = (int)image.getKer().getSize().getSy()
                        * (int)image.getKer().getSize().getSz();
        ImageProcessor ipker = new FloatProcessor(widthker, heightker);
        ipker.setPixels(image.getKer().getImg());
        ImagePlus imgker = new ImagePlus(
                "Replotted psf", ipker);
        imgker.show();

        System.out.println("redisplay images: imgmes");
        int width = (int)image.getImgmes().getSize().getSx();
        int height = (int)image.getImgmes().getSize().getSy();
        ImageProcessor ipmes = new FloatProcessor(width, height);
        ipmes.setPixels(image.getImgmes().getImg());
        ImagePlus imgmes = new ImagePlus(
                "Image in number of photons, background substracted", ipmes);
        imgmes.show();

        System.out.println("redisplay images: ccomp");
        int widthcc = (int)image.getImgmes().getSize().getSx() * 8;
        int heightcc = (int)image.getImgmes().getSize().getSy() * 8;
        System.out.println(widthcc);
        System.out.println(heightcc);
        ImageProcessor ipcc = new ColorProcessor(widthcc, heightcc);
        ipcc.setPixels(image.getCcomp().getImg());
        ImagePlus imgcc = new ImagePlus(
                "Connected component decomposition", ipcc);
        imgcc.show();

        System.out.println("redisplay images: recons");
        ImageProcessor ipres = new FloatProcessor(widthcc / 2, heightcc / 2);
        ipres.setPixels(image.getRecons().getImg());
        ImagePlus imgres = new ImagePlus(
                "Reconstruction", ipres);
        imgres.show();

        return;
    }

    public void showAbout() {
        IJ.showMessage("Brecs",
                "A package for dense localization microscopy reconstruction");
    }
}
