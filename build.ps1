# withvs14
clear
cd build
write-host "Building ..."
MSBuild.exe .\brecs.sln /target:brecs /m /nologo /clp:"Verbosity=minimal;ShowTimestamp;"
.\src\Debug\brecs.exe
write-host "...Done"
cd ..

