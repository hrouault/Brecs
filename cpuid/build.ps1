# withvs14
clear
cd build
write-host "Building ..."
cl ..\src\cpuid.c /nologo
cl ..\src\avx2.c /nologo
.\avx2.exe
write-host "...Done"
cd ..

