# withvs14
clear
cd build
write-host "Building ..."
MSBuild.exe .\brecs.sln /target:brecs /m /nologo /clp:"Verbosity=minimal;ShowTimestamp;"
write-host "...Done"
cd ..

