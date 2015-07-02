/*
 * To the extent possible under law, the Fiji developers have waived
 * all copyright and related or neighboring rights to this tutorial code.
 *
 * See the CC0 1.0 Universal license for details:
 *     http://creativecommons.org/publicdomain/zero/1.0/
 */

import ij.IJ;
import ij.ImageJ;
import ij.ImagePlus;
import ij.gui.GenericDialog;
import ij.plugin.PlugIn;
import ij.process.ImageProcessor;
import ij.io.OpenDialog;
//import ij.io.Button;

/**
 * Brecs
 *
 * @author Herve Rouault
 */


public class B_recs implements PlugIn {

    public static final String PLUGIN_VERSION = "0.1";
	protected ImagePlus image;

	// image property members
	private int width;
	private int height;

	// plugin parameters
	public double value;
	public String name;

    public native void helloWorld();

    public void run(String ignored) {
        GenericDialog gd = new GenericDialog("B-recs (version: "
                                             + PLUGIN_VERSION + ")");

        gd.addStringField("Image to reconstruct", "input.tif");
        gd.addStringField("background (optional)", "back.tif");
        gd.addStringField("PSF file", "psf.tif");
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
        
    }

	public void showAbout() {
		IJ.showMessage("Brecs",
			"A package for dense localization microscopy reconstruction"
		);
	}
}
