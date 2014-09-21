/*                      Sprite 4a
    --------------------------------------------------------
   | Example program to demonstrate efficient animated      |
   | sprites using the joypad for positioning.              |
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
int spr,x,y;
spr=0;                          /* sprite number to start with */
x=15;                           /* x cordinate to start at */
y=75;                           /* y cordinate to start at */


SPRITES_8x16;      /* sets sprites to, yep you guessed it, 8x16 mode */

set_sprite_data(0, 8, bloke);   /* defines the sprite data */

set_sprite_tile(0,spr);            /* defines the tile numbers */

move_sprite(0,14,75);         /* puts the first sprite on screen */

SHOW_SPRITES;

 while(!0)                      /* infinate loop */
 {

 /* checks to see if joypad has been pressed and is equal to right, 
    if so increments x by 1, and spr by 2. Sets sprite 0 to the next 
    frame (sprite). Checks to see if we are inside the loop 
    (4 sprites in 8x16 = 8 tiles) if so, starts the animation again.
    Then we move the new sprite on screen at the new coords and add
    a little delay.                                                 */

  if(joypad()==J_RIGHT)        
   {
   x++; 
   spr+=2;
   if(spr==8) spr=0;
   set_sprite_tile(0,spr);
   set_sprite_prop(0,0);         /* sets properties to normal */
   move_sprite(0,x,y);
   delay(75);
   }

  if(joypad()==J_LEFT)           /* see above */
   {
   x--;
   spr+=2;
   if(spr==8) spr=0;
   set_sprite_tile(0,spr);

  /* this will OR the flip x bit of sprite 0 to the value 1, making the
     sprite flip horizontally */
   set_sprite_prop(0,S_FLIPX | 0x01);  

   move_sprite(0,x,y);
   delay(75);
   }

  if(joypad()==J_UP)           /* see above */
   {
   y--;
   spr+=2;
   if(spr==8) spr=0;
   set_sprite_tile(0,spr);   
   move_sprite(0,x,y);
   delay(75);
   }

  if(joypad()==J_DOWN)           /* see above */
   {
   y++;
   spr+=2;
   if(spr==8) spr=0;
   set_sprite_tile(0,spr);   
   move_sprite(0,x,y);
   delay(75);
   
   } 


 }                              /* end of infinate loop */


}                               /* end main */

/* This example is more efficient than the previous, due to the fact
   that we are only using 1 sprite instead of 4. And we flipx
   instead of using another another 4 sprites, so you we are only
   using 1/8 of the original sprites !

   Thanks to Robert of GenFan. for the ideas and tips !

   If anyone would like to update this (or any of the examples),
   please email me.

   If these examples help anyone I would really love some feedback,
   comments, suggestions etc.
   If any of the above is incorrect I would also like to know.

   Have Fun !
   stephen.blanksby@virgin.net
   http://freespace.virgin.net/stephen.blanksby

   Thanks also to Jeff, Pascal, and many others !                */