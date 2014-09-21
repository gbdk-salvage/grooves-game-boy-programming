/*                Collision Detection Ver. 1
    --------------------------------------------------------
   | Example program to demonstrate basic animated sprites  |
   | and collision detection using arrays.                  |
   | Ver.1 is FAR from perfect and incomplete, but it works |
   |                                                        |
   | To do in Ver. 2                                        |
   | Use functions for the collision routines               |
   | Use include file for tile data                         |
   | Put X first in the array                               |
   | Include another constant in the array to check what    |
   | we are touching, eg wall=1 enemy=2 blah blah           |
   | More comments or                                       |
   | A FAQ cos its getting messy in here ; )                |
   | A level storage system                                 |
   | Tidy up loose ends in the code                         |
   |--------------------------------------------------------|
   |             stephen.blanksby@virgin.net                |
    --------------------------------------------------------     */


#include <gb.h>

/* bloke was created in GameBoy Tile Designer, in 8x16 mode 
   i should really make this an include file               */

unsigned char bloke[] =
{
  0x00,0x00,0x38,0x38,0x7C,0x44,0x7F,0x7F,
  0x44,0x74,0x46,0x7C,0x40,0x78,0x24,0x3C,
  0x18,0x3C,0x00,0x24,0x00,0x24,0x00,0x24,
  0x00,0x24,0x00,0x24,0x00,0x24,0x00,0x36,
  0x00,0x00,0x38,0x38,0x7C,0x44,0x7F,0x7F,
  0x44,0x74,0x46,0x7C,0x40,0x78,0x24,0x3C,
  0x18,0x3C,0x00,0x22,0x00,0x22,0x00,0x22,
  0x00,0x22,0x00,0x23,0x00,0x20,0x00,0x30,
  0x00,0x00,0x38,0x38,0x7C,0x44,0x7F,0x7F,
  0x44,0x74,0x46,0x7C,0x40,0x78,0x24,0x3C,
  0x18,0x3C,0x00,0x42,0x00,0x42,0x00,0x42,
  0x00,0x42,0x00,0x42,0x00,0x42,0x00,0x63,
  0x00,0x00,0x38,0x38,0x7C,0x44,0x7F,0x7F,
  0x44,0x74,0x46,0x7C,0x40,0x78,0x24,0x3C,
  0x18,0x3C,0x00,0x44,0x00,0x44,0x00,0x44,
  0x00,0x44,0x00,0x64,0x00,0x04,0x00,0x06,
  0x00,0x00,0x1C,0x1C,0x3E,0x22,0xFE,0xFE,
  0x22,0x2E,0x62,0x3E,0x02,0x1E,0x24,0x3C,
  0x18,0x3C,0x00,0x24,0x00,0x24,0x00,0x24,
  0x00,0x24,0x00,0x24,0x00,0x24,0x00,0x6C,
  0x00,0x00,0x1C,0x1C,0x3E,0x22,0xFE,0xFE,
  0x22,0x2E,0x62,0x3E,0x02,0x1E,0x24,0x3C,
  0x18,0x3C,0x00,0x44,0x00,0x44,0x00,0x44,
  0x00,0x44,0x00,0xC4,0x00,0x04,0x00,0x0C,
  0x00,0x00,0x1C,0x1C,0x3E,0x22,0xFE,0xFE,
  0x22,0x2E,0x62,0x3E,0x02,0x1E,0x24,0x3C,
  0x18,0x3C,0x00,0x42,0x00,0x42,0x00,0x42,
  0x00,0x42,0x00,0x42,0x00,0x42,0x00,0xC6,
  0x00,0x00,0x1C,0x1C,0x3E,0x22,0xFE,0xFE,
  0x22,0x2E,0x62,0x3E,0x02,0x1E,0x24,0x3C,
  0x18,0x3C,0x00,0x22,0x00,0x22,0x00,0x22,
  0x00,0x22,0x00,0x26,0x00,0x20,0x00,0x60,
  0x00,0x00,0x3C,0x3C,0x7E,0x42,0x7E,0x7E,
  0x42,0x7E,0x42,0x7E,0x42,0x7E,0x24,0x3C,
  0x18,0x3C,0x00,0x24,0x00,0x24,0x00,0x24,
  0x00,0x24,0x00,0x24,0x00,0x24,0x00,0x66,
  0x00,0x00,0x3C,0x3C,0x7E,0x42,0x7E,0x7E,
  0x42,0x7E,0x42,0x7E,0x42,0x7E,0x24,0x3C,
  0x18,0x3C,0x00,0x24,0x00,0x24,0x00,0x24,
  0x00,0x24,0x00,0x26,0x00,0x20,0x00,0x60,
  0x00,0x00,0x3C,0x3C,0x7E,0x42,0x7E,0x7E,
  0x42,0x7E,0x42,0x7E,0x42,0x7E,0x24,0x3C,
  0x18,0x3C,0x00,0x24,0x00,0x24,0x00,0x24,
  0x00,0x24,0x00,0x64,0x00,0x06,0x00,0x00,
  0x00,0x00,0x3C,0x3C,0x7E,0x42,0x7E,0x7E,
  0x42,0x7E,0x42,0x7E,0x42,0x7E,0x24,0x3C,
  0x18,0x3C,0x00,0x24,0x00,0x24,0x00,0x24,
  0x00,0x24,0x00,0x64,0x00,0x04,0x00,0x06
};


unsigned char briks[] =
{

  0x58,0x04,0xF9,0x04,0xFB,0x04,0x00,0xFF,
  0x8A,0x40,0x9F,0x40,0xBF,0x40,0x00,0xFF,

};

unsigned char bkgtilea[] =         /* display tile 1 from briks */
{
  1
};

int array_size=8;                  /* the below arrary contains 8 entries */
unsigned int boundx []={ 17, 38, 1, 86, 33,54, 72, 120};
unsigned int scrxl=8;              /* boundry left */
unsigned int scrxr=160;            /* boundry right */
unsigned int scryt=8;              /* boundry top */ 
unsigned int scryb=144;            /* boundry bottom */

void main()                                   /* main program  */ 
{
int spr,spl,spud,x,y,old,i,j,k,l,key;      

set_bkg_data(1,1,briks);          /* start bkg display (platforms) */

for(x=0;x<10;x++)
{
set_bkg_tiles(x,2,1,1,bkgtilea); 
}
for(x=9;x<14;x++)
{
set_bkg_tiles(x,4,1,1,bkgtilea); 
}
SHOW_BKG;                         /* end bkg */


SPRITES_8x16;      /* sets sprites to, yep you guessed it, 8x16 mode */

set_sprite_data(0, 24, bloke);   /* defines the main sprite data */

for(i=0;i<=11;i++)
{
set_sprite_tile(i,i*2);            /* defines the tiles numbers */
}


/* spr = sprite movement right (sprite numbers 0 - 3)
   spl = sprite movement left (sprite numbers 4 - 7)
   spud = sprite movement up/down (sprite numbers 8 - 11)  */

spr=0;                          /* right movement sprite starts at no.0 */
spl=4;                          /* left movement sprite starts at no.4 */
spud=8;                         /* up / down movement sprite starts at no.8 */
x=15;                           /* x cordinate to start at */
y=16;                           /* y cordinate to start at */
old=0;                          /* the last sprite displayed */

move_sprite(spr,x,y);         /* puts the first sprite on screen */
old=spr;
SHOW_SPRITES;

 while(!0)                      /* infinate loop */
 {

check:     
y++;                                     /* check we are stood on something using the arrary*/
    for(i=0;i<array_size;i=i+4)
     {
      j=i+1;
      k=i+2;
      l=i+3;
        if(
         (y>=boundx[i] && y<=boundx[j])      /* check y position against boundrys */
         &&
         (x>=boundx[k] && x<=boundx[l])      /* check x position against boundrys */
          || y==scryb)                       /* or that y is equal to bottom boundry */
          { y--; goto ok; }              /* if we ARE stood on something, goto ok */
     }
                                   /* if NOT, we fall.... */
move_sprite(old,200,0);            /* move the old sprite off screen */
move_sprite(spud,x,y);             /* move new sprite onto screen    */
old=spud;                          /* save the current sprite number in old */
delay(10); 
goto check;                        /* then check again */

ok:

key=joypad();                    /* key = what was pressed */

 if(key==J_RIGHT)                /* if it was right ...    */
  {

x++;                              /* increment x , so we can check boundry before moving */

if(x==scrxr){x--; goto check; }      /* if x position is equal to max screen right, decerement
                                        x and goto check, not allowing movement            */

    for(i=0;i<array_size;i=i+4)      /* loop through the array */
     {
      j=i+1;
      k=i+2;
      l=i+3;
        if(
         (y>=boundx[i] && y<=boundx[j])      /* check y position against boundrys */
         &&
         (x>=boundx[k] && x<=boundx[l])      /* check x position against boundrys */
          )
          {x--; goto check;}                 /* if both of the above return true we are
                                                at a boundry, so goto check, not allowing
                                                right movement                           */
     }                                /* end of array loop */     

   move_sprite(old,200,0);             /* move the old sprite off screen */
   move_sprite(spr,x,y);               /* move new sprite onto screen    */
   delay(25);                          /* little delay  */
   old=spr;                            /* save the current sprite number in old */
   spr++;                              /* increment sprite number */
   if(spr==4) spr=0;                   /* check if we have reached the end of the 
                                          animation, if so start again  */
  }                     /* end of right IF statment */


  if(key==J_LEFT)           /* see above */
   {
   x--;
if(x==scrxl){x++; goto check; }
    for(i=0;i<array_size;i=i+4)
     {
      j=i+1;
      k=i+2;
      l=i+3;
        if(
         (y>=boundx[i] && y<=boundx[j])
         &&
         (x>=boundx[k] && x<=boundx[l])  
         )
         {x++; goto check;}
     }

   move_sprite(old,200,0);  
   move_sprite(spl,x,y);
   delay(25);
   old=spl;  
   spl++;
   if(spl==8) spl=4;
   }

  if(key==J_UP)           /* see above */
   {
   y--;
if(y==scryt){y++; goto check; }
    for(i=0;i<array_size;i=i+4)
     {
      j=i+1;
      k=i+2;
      l=i+3;
        if(
         (y>=boundx[i] && y<=boundx[j])
         &&
         (x>=boundx[k] && x<=boundx[l])  
          )
          {y++; goto check;}
      }

   move_sprite(old,200,0);  
   move_sprite(spud,x,y);
   delay(25);
   old=spud;  
   spud++;
   if(spud==12) spud=8;
   }

  if(key==J_DOWN)           /* see above */
   {
   y++;
if(y==scryb){y--; goto check; }
    for(i=0;i<array_size;i=i+4)
     {
      j=i+1;
      k=i+2;
      l=i+3;
        if(
         (y>=boundx[i] && y<=boundx[j])
         &&
         (x>=boundx[k] && x<=boundx[l])  
          )
          {y--; goto check;}
     }

   move_sprite(old,200,0);  
   move_sprite(spud,x,y);
   delay(25);
   old=spud;  
   spud++;
   if(spud==12) spud=8;
   }

  if(key==J_B)
  {
  spr=0;
  move_sprite(old,200,200);
  move_sprite(spr,15,16);
  x=15;
  y=16;
  old=spr;
  }

 }                              /* end of infinate loop */


}                               /* end main */


/* 
   There are probably lots of other (and maybe better) ways 
   of doing this, but thats for you to discover !
   
   If these examples help anyone I would love some feedback,
   comments, suggestions etc.
   If any of the above is incorrect I would also like to know.

   Have Fun !
   stephen.blanksby@virgin.net
   http://freespace.virgin.net/stephen.blanksby

   Thanks to Jeff, Pascal and many others !                */
