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
import ij.measure.ResultsTable;
import ij.plugin.filter.Analyzer;


public class B_recs implements PlugIn {

    public static final String PLUGIN_VERSION = "0.1";

    private static String title_recons = "";
    private static String title_psf = "";
    private static String title_back = "";

    private static Float fluomean_dia = new Float(2000.0);
    private static Float fluosd_dia = new Float(500.0);
    private static Float fluodens_dia = new Float(0.001);
    private static Float camampli_dia = new Float(1.0);
    private static Float noiseoff_dia = new Float(1000.0);
    private static Float convolthr_dia = new Float(200.0);
    private static Integer nbiter_dia = new Integer(200);
    private static Float backintens_dia = new Float(200.0);
    private static Float damp_dia = new Float(0.01);
    private static Float locathr_dia = new Float(1000);

    public void run(String arg) {
        try {
            NativeUtils.loadLibraryFromJar("/libB_recs.jnilib");
        } catch (IOException e) {
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

        String[] titles2 = new String[wList.length + 1];
        titles2[0] = "";
        for (int i=0; i < wList.length; i++) {
            titles2[i + 1] = titles[i];
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

        gd.addChoice("Background (optional):", titles2, title_back);

        gd.addNumericField("Fluorophore mean intensity", fluomean_dia, 1);
        gd.addNumericField("Fluorophore intensity standard deviation",
                           fluosd_dia, 1);
        gd.addNumericField("Fluorophore density", fluodens_dia, 4);
        gd.addNumericField("Camera amplification factor", camampli_dia, 1);
        gd.addNumericField("Noise offset", noiseoff_dia, 1);
        gd.addNumericField("Threshold for connected components",
                           convolthr_dia, 1);
        gd.addNumericField("Number of iterations", nbiter_dia, 0);
        gd.addNumericField("Background intensity", backintens_dia, 1);
        gd.addNumericField("Dampening coefficient", damp_dia, 4);
        gd.addNumericField("Threshold for localization acceptance",
                           locathr_dia, 1);
        gd.showDialog();

        fluomean_dia = (float)gd.getNextNumber();
        fluosd_dia = (float)gd.getNextNumber();
        fluodens_dia = (float)gd.getNextNumber();
        camampli_dia = (float)gd.getNextNumber();
        noiseoff_dia = (float)gd.getNextNumber();
        convolthr_dia = (float)gd.getNextNumber();
        nbiter_dia = (int)gd.getNextNumber();
        backintens_dia = (float)gd.getNextNumber();
        damp_dia = (float)gd.getNextNumber();
        locathr_dia = (float)gd.getNextNumber();

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

        int index_back = gd.getNextChoiceIndex();
        ImagePlus img_back = WindowManager.getImage(wList[index_source]);
        if (index_back != 0) {
            img_back = WindowManager.getImage(wList[index_back - 1]);
            if (img_back.getBitDepth() != 32) {
                IJ.showMessage("Error",
                  "The background image pixel depth should be 32 bit (float)");
                return;
            }
            if (img_back.getWidth() != img_source.getWidth() ||
                    img_back.getHeight() != img_source.getHeight() ||
                    (img_back.getNSlices() != img_source.getNSlices() &&
                     img_back.getNSlices() > 1)) {
                IJ.showMessage("Error",
                 "The source and background images do not have the same size");
                return;
            }

        }

        // Launch the linked Brecs library
        Brecs brecsrun = new Brecs();

        imagessimp_t image = new imagessimp_t();
        paramssimp_t params = new paramssimp_t();

        params.setPixmean(fluomean_dia);
        params.setPixstd(fluosd_dia);
        params.setRho(fluodens_dia);
        params.setMesampli(camampli_dia);
        params.setNoiseoffset(noiseoff_dia);
        params.setConvolthr(convolthr_dia);
        params.setNbiter(nbiter_dia);
        params.setMeanback(backintens_dia);
        params.setDamp(damp_dia);
        params.setLocathr(locathr_dia);

        int kersize = img_psf.getProcessor().getWidth();
        int stacksize = img_psf.getImageStackSize();
        int oversamp = (int)Math.sqrt(stacksize);
        params.setKersize(kersize);
        params.setOversamp(oversamp);
        brecsrun.brecs_initpsf(image, params);
        for (int i = 0; i < stacksize; i++) {
            img_psf.setSliceWithoutUpdate(i + 1);
            float [] psf = (float [])(img_psf.getProcessor().getPixels());
            brecsrun.brecs_addpsfslice(image, params, psf, i);
        }

        if (img_source.getNSlices() == 1) {
            ImageProcessor ipsource = img_source.getProcessor();
            short [] pixels = (short [])(ipsource.getPixels());
            ImageProcessor ipback = img_back.getProcessor();
            float [] pixelsback = (float [])(ipback.getPixels());
            int meswidth = ipsource.getWidth();
            int mesheight = ipsource.getHeight();
            brecsrun.brecs_allocin(image, pixels, pixelsback,
                                  meswidth, mesheight);
            brecsrun.brecs_initin(image, pixels, pixelsback,
                                  meswidth, mesheight);

            brecsrun.brecs_reconstruction(image, params);

            System.out.println("redisplay images");
            // Redisplay images
            int widthcc = (int)image.getCcomp().getSize().getSx();
            int heightcc = (int)image.getCcomp().getSize().getSy();
            int [] ccomp_redisp = new int[widthcc * heightcc];
            int widthrec = (int)image.getRecons().getSize().getSx();
            int heightrec = (int)image.getRecons().getSize().getSy();
            float [] recons_redisp = new float[widthrec * heightrec];
            int [] over_redisp = new int[widthrec * heightrec];
            brecsrun.recopy(image, ccomp_redisp, recons_redisp, over_redisp);

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

            ResultsTable rt = new ResultsTable();
            int ressizex = ipres.getWidth();
            int ressizey = ipres.getHeight();
            float [] reconsdat = (float [])(ipres.getPixels());
            Integer counter = new Integer(0);
            for (int i = 0; i < ressizex * ressizey; i++) {
                if (reconsdat[i] > locathr_dia) {
                    rt.incrementCounter();
                    rt.addValue("#", counter);
                    rt.addValue("x", i % ressizex);
                    rt.addValue("y", i / ressizex);
                    rt.addValue("Intensity", reconsdat[i]);
                    counter++;
                 }
             }
             rt.show("Localizations");
        } else {
            ImageStack stack = img_source.getStack();
            ImageProcessor ipsource = img_source.getProcessor();
            ImageProcessor ipback = img_back.getProcessor();
            int meswidth = ipsource.getWidth();
            int mesheight = ipsource.getHeight();
            short [] pixels = (short [])(ipsource.getPixels());
            float [] pixelsback = (float [])(ipback.getPixels());
            brecsrun.brecs_allocin(image, pixels, pixelsback,
                                   meswidth, mesheight);

            ipsource = stack.getProcessor(1);
            pixels = (short [])(ipsource.getPixels());

            if (img_back.getNSlices() > 1) {
                ipback = img_back.getStack().getProcessor(1);
                pixelsback = (float [])(ipback.getPixels());
            }

            brecsrun.brecs_initin(image, pixels, pixelsback,
                    meswidth, mesheight);

            brecsrun.brecs_reconstruction(image, params);
            for (int i = 2; i <= stack.getSize(); i++) {
                ipsource = stack.getProcessor(i);
                pixels = (short [])(ipsource.getPixels());

                if (img_back.getNSlices() > 1) {
                    ipback = img_back.getStack().getProcessor(i);
                    pixelsback = (float [])(ipback.getPixels());
                }

                brecsrun.brecs_initin(image, pixels, pixelsback,
                                      meswidth, mesheight);

                brecsrun.brecs_reconstruction_nocheck(image, params);
            }

            // Redisplay images
            int widthrec = (int)image.getRecons().getSize().getSx();
            int heightrec = (int)image.getRecons().getSize().getSy();
            float [] recons_redisp = new float[widthrec * heightrec];
            brecsrun.recopy_recons(image, recons_redisp);

            ImageProcessor ipres = new FloatProcessor(widthrec, heightrec);
            ipres.setPixels(recons_redisp);
            ImagePlus imgres = new ImagePlus("Reconstruction", ipres);
            imgres.show();

            ResultsTable rt = new ResultsTable();
            int ressizex = ipres.getWidth();
            int ressizey = ipres.getHeight();
            float [] reconsdat = (float [])(ipres.getPixels());
            Integer counter = new Integer(0);
            for (int i = 0; i < ressizex * ressizey; i++) {
                if (reconsdat[i] > locathr_dia) {
                    rt.incrementCounter();
                    rt.addValue("#", counter);
                    rt.addValue("x", i % ressizex);
                    rt.addValue("y", i / ressizex);
                    rt.addValue("Intensity", reconsdat[i]);
                    counter++;
                 }
             }
             rt.show("Localizations");
        }

        return;
    }

    public void showAbout() {
        IJ.showMessage("Brecs",
                "A package for dense localization microscopy reconstruction");
    }
}
