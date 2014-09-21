@IF ERRORLEVEL 1 PAUSE
@echo off
@echo Stephen Blanksbys example C files for the Game Boy
@echo Compiling.............
 ..\bin\lcc -Wa-l -Wl-m -o collide.gb collide.c
@PAUSE
@echo Done !

