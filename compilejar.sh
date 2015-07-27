cd ~/postdoc/superres/Brecs/src
swig -java Brecs.i
mv *.java ../fiji-plugin/src/main/java/
cd ../buildcmake
make fiji-brecs
cd ../fiji-plugin/src
cp ../../buildcmake/src/libfiji-brecs.dylib main/resources/libB_recs.jnilib
cd ..
mvn package
