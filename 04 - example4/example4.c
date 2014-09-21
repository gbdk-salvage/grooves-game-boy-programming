/*                      Example 4
    --------------------------------------------------------
   | Example program to demonstrate basic user input using  |
   | the joypad and buttons.  The return value of the       |
   | function joypad() is stored in key, and compared       |
   | against the various buttons.
   |--------------------------------------------------------|
   |             stephen.blanksby@virgin.net                |
    --------------------------------------------------------     */

#include <gb.h>

void main()                     /* main program */
{
int key;

 while(!0)                      /* infinate loop */
 {
  key=joypad();                 /* puts the returned value from joypad() into key */

  if(key & J_RIGHT)             /* check to see if joypad() has been pressed */
  {                             /* and that Right has also been pressed */
  gotoxy(0,0);
  puts("You pressed Right !  ");
  }

  if(key & J_LEFT)             /* same as above, but check for left press */
  {
  gotoxy(0,0);
  puts("You pressed Left !   ");
  }

  if(key & J_UP)               /* I think you get the idea */
  {
  gotoxy(0,0);
  puts("You pressed Up !     ");
  }

  if(key & J_DOWN)
  {
  gotoxy(0,0);
  puts("You pressed Down !   ");
  }

  if(key & J_A)
  {
  gotoxy(0,0);
  puts("You pressed A !      ");
  }

  if(key & J_B)
  {
  gotoxy(0,0);
  puts("You pressed B !      ");
  }

  if(key & J_START)
  {
  gotoxy(0,0);
  puts("You pressed Start !  ");
  }

  if(key & J_SELECT)
  {
  gotoxy(0,0);
  puts("You pressed Select ! "); 
  }

 }                              /* end of loop */


}                               /* end main */


/* There are probably lots of other (and maybe better) ways 
   of doing this, but thats for you to discover !
   
   If these examples help anyone I would love some feedback,
   comments, suggestions etc.
   If any of the above is incorrect I would also like to know.

   Have Fun !
   stephen.blanksby@virgin.net
   http://freespace.virgin.net/stephen.blanksby                 */