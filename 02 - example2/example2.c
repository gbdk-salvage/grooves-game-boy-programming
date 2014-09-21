/*                      Example 2
    --------------------------------------------------------
   | Example program to demonstrate basic user input and    |
   | output to the Gb screen. A simple cls() clears the     |
   | screen by putting a space over every character in      |
   | the display.                                           |
   | Use cursor keys to choose a letter and press button A  |
   | to enter it. Use button B to backspace. Press Start to |
   | enter your name.                                       |
   |--------------------------------------------------------|
   |             stephen.blanksby@virgin.net                |
    --------------------------------------------------------     */


#include <gb.h>
char string[25];           /* input string */

void cls()
{                                /* simple clear screen function */
  int x, y;

  for(y = 0; y < 20; y++)        /* loop for the num of charaters across (x)*/
    for(x = 0; x < 30; x++)      /* loop for the num of charaters high (y)*/
    {    
      gotoxy(x, y);              /* moves the postion to x,y */
      setchar(' ');              /* puts a space on screen */
    }                            /* does the above until we have cleared the screen */
gotoxy(0,0);                     /* returns the position to the top left */
}


void main()                  /* main program */
{

  puts("Enter Name :\n");   
  gets(string);               /* gets users input */
  cls();                      /* clears screen    */

  printf("Hello %s",string);    /* puts the string on screen */

  puts("\n\nWelcome to the");
  puts("World of Game Boy");
  puts("Programming !");

}                                 /* end main */


/* There are probably lots of other (and maybe better) ways 
   of doing this, but thats for you to discover !
   
   If these examples help anyone I would love some feedback,
   comments, suggestions etc.
   If any of the above is incorrect I would also like to know.

   Have Fun !
   stephen.blanksby@virgin.net
   http://freespace.virgin.net/stephen.blanksby                 */