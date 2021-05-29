@echo off
set /a val = 0
g++ rand.cpp -o rand.exe
g++ test_dp.cpp -o bug.exe 2> nul
g++ std_dfs.cpp -o std.exe 2> nul
:loop
rand.exe > rand.in
bug.exe < rand.in > my.out
std.exe < rand.in > std.out
fc my.out std.out > nul
if not errorlevel 1 (
	set /a val = %val% + 1
	echo Corret %val% times!
	goto loop
)else (
	echo Wrong found!
)
pause