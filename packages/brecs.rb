class Brecs < Formula
  desc "Package for dense localization microscopy reconstruction"
  homepage "https://bitbucket.org/transimcon/brecs"
  url "https://bitbucket.org/transimcon/brecs.git", :using => :git
  version "0.2"

  depends_on "cmake" => :build
  depends_on "pkg-config"
  depends_on "fftw"
  depends_on "swig"
  depends_on "libtiff"
  depends_on "sphinx-doc"
#  depends_on "maven" => :optional

  def install
    system "cmake", ".", *std_cmake_args
    system "make", "install"
  end

  test do
    system "#{bin}/brecs-reconssparse --version"
  end
end
