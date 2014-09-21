/*                      Sprite 2
    --------------------------------------------------------
   | Example program to demonstrate basic sprites on the Gb |
   | screen.                                                |
   |--------------------------------------------------------|
   |             stephen.blanksby@virgin.net                |
    --------------------------------------------------------     */

#include <gb.h>

/* smile was created in GameBoy Tile Designer */
unsigned char smile[] =
{
  0x3C,0x3C,0x42,0x42,0x81,0xA5,0x81,0x91,   /* smile :|  */
  0x81,0x85,0x81,0xB9,0x42,0x42,0x3C,0x3C,               
};

void main()
{

  /* sets the complete sprite data from tile 0 for 1 tile of smile
     (data begins at tile 0 and ends after 1 tile) */
  set_sprite_data(0,1,smile);

  /* sets tile number 0 to tile 0 of smile */
  set_sprite_tile(0,0);

 
  /* moves sprite 0 to X-75 Y-75 */
  move_sprite(0,75,75);

SHOW_SPRITES;
}              /* end main    */



/* There are probably lots of other (and maybe better) ways 
   of doing this, but thats for you to discover !
   
   If these examples help anyone I would love some feedback,
   comments, suggestions etc.
   If any of the above is incorrect I would also like to know.

   Have Fun !
   stephen.blanksby@virgin.net
   http://freespace.virgin.net/stephen.blanksby

   Thanks to Jeff, Pascal and many others !                */