/*                      Sprite 4
    --------------------------------------------------------
   | Example program to demonstrate basic animated sprites  |
   | using the joypad for positioning.                      |
   |--------------------------------------------------------|
   |             stephen.blanksby@virgin.net                |
    --------------------------------------------------------     */


#include <gb.h>

/* bloke was created in GameBoy Tile Designer, in 8x16 mode */
unsigned char bloke[] =
{
  /* Tile 0 */
  0x00,0x00,0x38,0x38,0x7C,0x44,0x7F,0x7F,
  0x44,0x74,0x46,0x7C,0x40,0x78,0x24,0x3C,
  /* Tile 1 */
  0x18,0x3C,0x00,0x24,0x00,0x24,0x00,0x24,
  0x00,0x24,0x00,0x36,0x00,0x00,0x00,0x00,
  /* Tile 2 */
  0x00,0x00,0x38,0x38,0x7C,0x44,0x7F,0x7F,
  0x44,0x74,0x46,0x7C,0x40,0x78,0x24,0x3C,
  /* Tile 3 */
  0x18,0x3C,0x00,0x22,0x00,0x22,0x00,0x22,
  0x00,0x23,0x00,0x30,0x00,0x00,0x00,0x00,
  /* Tile 4 */
  0x00,0x00,0x38,0x38,0x7C,0x44,0x7F,0x7F,
  0x44,0x74,0x46,0x7C,0x40,0x78,0x24,0x3C,
  /* Tile 5 */
  0x18,0x3C,0x00,0x42,0x00,0x42,0x00,0x42,
  0x00,0x42,0x00,0x63,0x00,0x00,0x00,0x00,
  /* Tile 6 */
  0x00,0x00,0x38,0x38,0x7C,0x44,0x7F,0x7F,
  0x44,0x74,0x46,0x7C,0x40,0x78,0x24,0x3C,
  /* Tile 7 */
  0x18,0x3C,0x00,0x44,0x00,0x44,0x00,0x44,
  0x00,0x64,0x00,0x06,0x00,0x00,0x00,0x00
};

void main()        /* main program */
{
int spr,x,y,old;

SPRITES_8x16;      /* sets sprites to, yep you guessed it, 8x16 mode */

set_sprite_data(0, 8, bloke);   /* defines the sprite data */

set_sprite_tile(0,0);            /* defines the tiles numbers */
set_sprite_tile(1,2);
set_sprite_tile(2,4);
set_sprite_tile(3,6);

spr=0;                          /* sprite number to start with */
x=15;                           /* x cordinate to start at */
y=75;                           /* y cordinate to start at */
old=0;                          /* the last sprite displayed */

move_sprite(spr,14,75);         /* puts the first sprite on screen */

SHOW_SPRITES;

 while(!0)                      /* infinate loop */
 {

 /* checks to see if joypad has been pressed and is equal to right, 
    if so increments x, then moves old sprite out of view then 
    places new sprite at x,y. Waits then saves the current sprite
    number in old and increments spr.
    Lastly checks to see if we have reached the end of the
    animiation (which is 4 sprites long), if so resets spr to 0.    */

  if(joypad()==J_RIGHT)        
   {
   x++; 
   move_sprite(old,200,200);
   move_sprite(spr,x,y);
   delay(75);
   old=spr;  
   spr++;
   if(spr==4) spr=0;
   }

  if(joypad()==J_LEFT)           /* see above */
   {
   x--;
   move_sprite(old,200,200);  
   move_sprite(spr,x,y);
   delay(75);
   old=spr;  
   spr++;
   if(spr==4) spr=0;
   }

  if(joypad()==J_UP)           /* see above */
   {
   y--;
   move_sprite(old,200,200);  
   move_sprite(spr,x,y);
   delay(75);
   old=spr;  
   spr++;
   if(spr==4) spr=0;
   }

  if(joypad()==J_DOWN)           /* see above */
   {
   y++;
   move_sprite(old,200,200);  
   move_sprite(spr,x,y);
   delay(75);
   old=spr;  
   spr++;
   if(spr==4) spr=0;
   }

 }                              /* end of infinate loop */


}                               /* end main */

/* You may have noticed a few flaws in this code (like the bloke
   doing the moonwalk !), it is far from perfect but it does 
   demonstrate the basic principals of sprite movement.
  
   If anyone would like to update this (or any of the examples),
   please email me.

   If these examples help anyone I would really love some feedback,
   comments, suggestions etc.
   If any of the above is incorrect I would also like to know.

   Have Fun !
   stephen.blanksby@virgin.net
   http://freespace.virgin.net/stephen.blanksby

   Thanks to Jeff, Pascal, and many others !                */