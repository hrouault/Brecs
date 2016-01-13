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

    private static Float numap_dia = new Float(1.2);
    private static Float emwavelen_dia = new Float(588);
    private static Float psffwhm_dia = new Float(250);
    private static Integer imgwidth_dia = new Integer(16);
    private static Float pixsize_dia = new Float(100);
    private static Integer oversamp_dia = new Integer(8);

    public void run(String arg) {
        try {
            NativeUtils.loadLibraryFromJar("/libB_recs.jnilib");
        } catch (IOException e) {
            e.printStackTrace();
        }

        GenericDialog gd = new GenericDialog("B-recs PSF generator(version: "
                + PLUGIN_VERSION + ")");

        gd.addNumericField("Numerical aperture of the objective",
                           numap_dia, 1);
        gd.addNumericField("Emission wavelength of the fluorophore (nm)",
                           emwavelen_dia, 1);
        gd.addNumericField("PSF width (FWHM in nm)", psffwhm_dia, 1);
        gd.addNumericField("Image width (in pixels)", imgwidth_dia, 1);
        gd.addNumericField("Pixel size (in nm)", pixsize_dia, 1);
        gd.addNumericField("Pixel oversampling (level of superresolution)",
                           oversamp_dia, 1);

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

        numap_dia = (float)gd.getNextNumber();
        emwavelen_dia = (float)gd.getNextNumber();
        psffwhm_dia = (float)gd.getNextNumber();
        imgwidth_dia = (int)gd.getNextNumber();
        pixsize_dia = (float)gd.getNextNumber();
        oversamp_dia = (int)gd.getNextNumber();

        psf_par.setPsfwidth(psffwhm_dia / (float)2.355);
        psf_par.setImagewidth(imgwidth_dia);
        psf_par.setPixsize(pixsize_dia);
        psf_par.setOversampling(oversamp_dia);

        brecsrun.brecs_psfgen(psf_par);

        int imgwidth2 = imgwidth_dia * imgwidth_dia;
        int oversamp2 = oversamp_dia * oversamp_dia;
        int psfsize = imgwidth2 * oversamp2;
        float [] psf_redisp = new float[psfsize];
        brecsrun.recopypsf(psf_par, psf_redisp);
        ImageStack psf_proc = new ImageStack(imgwidth_dia, imgwidth_dia);
        for (int i = 0; i < oversamp2; i++) {
            float [] subArray = Arrays.copyOfRange(psf_redisp,
               i * imgwidth2, (i + 1) * imgwidth2);
            FloatProcessor slice = new FloatProcessor(imgwidth_dia,
                                                      imgwidth_dia);
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
