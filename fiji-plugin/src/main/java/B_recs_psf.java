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
import java.util.Arrays;
import java.util.List;
import java.awt.TextField;
import java.awt.event.TextListener;
import java.awt.event.TextEvent;
import java.awt.Color;


public class B_recs_psf implements PlugIn {

    public static final String PLUGIN_VERSION = "0.1";

    private static String title_recons = "";
    private static String title_psf = "";

    public void run(String arg) {
        try {
            NativeUtils.loadLibraryFromJar("/libB_recs.jnilib");
        } catch (IOException e) {
            e.printStackTrace();
        }

        GenericDialog gd = new GenericDialog("B-recs PSF generator(version: "
                + PLUGIN_VERSION + ")");

        gd.addNumericField("Numerical aperture of the objective", 1.2, 1);
        gd.addNumericField("Emission wavelength of the fluorophore (nm)",
                           588, 1);
        gd.addNumericField("PSF width (FWHM in nm)", 250.0, 1);
        gd.addNumericField("Image width (in pixels)", 16, 1);
        gd.addNumericField("Pixel size (in nm)", 100.0, 1);
        gd.addNumericField("Pixel oversampling (level of superresolution)",
                           8, 1);

        final TextField numap = (TextField)gd.getNumericFields().get(0);
        final TextField lambda = (TextField)gd.getNumericFields().get(1);
        final TextField width = (TextField)gd.getNumericFields().get(2);

        TextListener changedtext = new TextListener() {
            public void textValueChanged(TextEvent e) {
                Float numapval = Float.parseFloat(numap.getText());
                Float lambdaval = Float.parseFloat(lambda.getText());
                width.setText(String.format("%.1f",
                                            0.4 * lambdaval / numapval));
            }
        };

        numap.addTextListener(changedtext);
        lambda.addTextListener(changedtext);
        Float numapval = Float.parseFloat(numap.getText());
        Float lambdaval = Float.parseFloat(lambda.getText());
        width.setText(String.format("%.1f",
                    0.4 * lambdaval / numapval));

        gd.showDialog();
        if (gd.wasCanceled()) {
            return;
        }

        // Launch the linked Brecs library
        Brecs brecsrun = new Brecs();

        psf_params_t psf_par = new psf_params_t();

        float fnumap = (float)gd.getNextNumber();
        float flambda = (int)gd.getNextNumber();
        float psfwidth = (float)gd.getNextNumber();
        int imagewidth = (int)gd.getNextNumber();
        float pixsize = (float)gd.getNextNumber();
        int oversampling = (int)gd.getNextNumber();

        psf_par.setPsfwidth(psfwidth);
        psf_par.setImagewidth(imagewidth);
        psf_par.setPixsize(pixsize);
        psf_par.setOversampling(oversampling);

        brecsrun.brecs_psfgen(psf_par);

        int psfsize = imagewidth * imagewidth * oversampling * oversampling;
        float [] psf_redisp = new float[psfsize];
        brecsrun.recopypsf(psf_par, psf_redisp);
        ImageStack psf_proc = new ImageStack(imagewidth, imagewidth);
        for (int i = 0; i < oversampling * oversampling; i++) {
            float [] subArray = Arrays.copyOfRange(psf_redisp,
               i * imagewidth * imagewidth, (i + 1) * imagewidth * imagewidth);
            FloatProcessor slice = new FloatProcessor(imagewidth, imagewidth);
            slice.setPixels(subArray);
            psf_proc.addSlice(slice);
        }
        ImagePlus psfimg = new ImagePlus("PSF images", psf_proc);
        psfimg.show();

        return;
    }

    public void showAbout() {
        IJ.showMessage("Brecs",
                "A package for dense localization microscopy reconstruction");
    }
}
