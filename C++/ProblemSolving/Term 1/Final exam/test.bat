@echo off
D:\\mingw64\\bin\\g++.exe A.cpp -o bug.exe 2> nul
bug.exe < sample.in > my.out
fc my.out sample.out > nul
if not errorlevel 1 (
echo Corret!
)else (
echo Wrong found!
)
pause