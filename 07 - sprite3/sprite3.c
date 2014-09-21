/*                      Sprite 3
    --------------------------------------------------------
   | Example program to demonstrate basic animated sprites  |
   | on the Gb screen.                                      |
   |--------------------------------------------------------|
   |             stephen.blanksby@virgin.net                |
    --------------------------------------------------------     */

#include <gb.h>

/* smile was created in GameBoy Tile Designer */
unsigned char smile[] =
{
  0x3C,0x3C,0x42,0x42,0x81,0xA5,0x81,0x91,   /* smile :|  */
  0x81,0x85,0x81,0xB9,0x42,0x42,0x3C,0x3C,               
  0x3C,0x3C,0x42,0x42,0x81,0xA5,0x81,0x91,   /* smile :)  */
  0x81,0x81,0x81,0x99,0x42,0x42,0x3C,0x3C
};

void main()
{
SPRITES_8x8;

  /* sets the complete sprite data from tile 0 for 2 tiles of smile
     (data begins at 0 and ends after 2 tiles) */
  set_sprite_data(0,2,smile);

  /* sets tile number 0 to tile 0 of smile */
  set_sprite_tile(0,0);

  /* sets tile number 1 to tile 1 of smile */
  set_sprite_tile(1,1);

SHOW_SPRITES;

while(!0)        /* infinate loop */
  {
  /* moves sprite 0 to X-75 Y-75 */
  move_sprite(0,75,75);

  /* pause */
  delay(500);

  /* moves sprites 0 out of view */
  move_sprite(0,200,200);

  /* moves sprite 1 to replace sprite 0 */
  move_sprite(1,75,75);

  /* pause */
  delay(500);

  /* moves sprites 1 out of view */
  move_sprite(1,200,200);
  }            /* end of loop */

}              /* end main    */

/* All we have done is, display a sprite, pause, remove it, then 
   replace it with another. 

   There are probably lots of other (and maybe better) ways 
   of doing this, but thats for you to discover !
   
   If these examples help anyone I would love some feedback,
   comments, suggestions etc.
   If any of the above is incorrect I would also like to know.

   Have Fun !
   stephen.blanksby@virgin.net
   http://freespace.virgin.net/stephen.blanksby

   Thanks to Jeff, Pascal and many others !                */