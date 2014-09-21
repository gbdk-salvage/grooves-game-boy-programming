@IF ERRORLEVEL 1 PAUSE
@echo off
@echo Stephen Blanksbys example C files for the Game Boy
@echo Compiling.............
 ..\bin\lcc -Wa-l -Wl-m -o det1-2.gb det1-2.c
@PAUSE

@echo Done !

