@echo off
set /a val = 0
g++ rand.cpp -o rand.exe
g++ test.cpp -o std.exe 2> nul
:loop
rand.exe > rand.in 
rand.in >> my.out
std.exe < rand.in >> my.out
if not errorlevel 1 (
	set /a val = %val% + 1
	echo Corret %val% times!
	goto loop
)else (
	echo Wrong found!
)
pause