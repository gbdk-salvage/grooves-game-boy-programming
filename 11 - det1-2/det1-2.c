/*              Collision Detection Ver. 1.2
    --------------------------------------------------------
   | Example program to demonstrate basic animated sprites  |
   | and collision detection using arrays.                  |
   |                                                        |
   | To do in next ver.                                     |
   | Use functions for the collision routines..........done |
   | Use include file for tile data....................done |
   | Put X first in the array..........................done |
   | Include another constant in the array to check what    |
   | we are touching, eg wall=1 enemy=2 blah blah           |
   | More comments or                                       |
   | A FAQ cos its getting messy in here ; )                |
   | A level storage system                                 |
   | Tidy up loose ends in the code...................done? |
   |--------------------------------------------------------|
   |             stephen.blanksby@virgin.net                |
    --------------------------------------------------------     */


#include <gb.h>
#include <bloke.c>               /* file containing tiles and data */

int i,j,k,l;
int array_size=8;                  /* the below arrary contains 8 entries */
unsigned int boundx []={ 1, 86 ,17 ,38 ,72 ,120 ,33 ,54 };
unsigned int scrxl=8;              /* boundry left */
unsigned int scrxr=160;            /* boundry right */
unsigned int scryt=8;              /* boundry top */ 
unsigned int scryb=144;            /* boundry bottom */


int collide(int x,int y)                   /* collision detection function */
{
for(i=0;i<array_size;i=i+4)
     {
      j=i+1;
      k=i+2;
      l=i+3;
        if(
         (x>=boundx[i] && x<=boundx[j])        /* check x position against boundrys */
         &&
         (y>=boundx[k] && y<=boundx[l])        /* check y position against boundrys */ 
          )
          {return 1;}                      /* return 1 if we are against a boundry */
     }
return 0;                                  /* return 0 if we are not */
}                                          /* end of collide function */


void main()                                   /* main program  */ 
{
int spr,spl,spud,x,y,old,key;      

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
         (x>=boundx[i] && x<=boundx[j])      /* check y position against boundrys */
         &&
         (y>=boundx[k] && y<=boundx[l])      /* check x position against boundrys */
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

 if(key==J_RIGHT)                /* IF it was right ...    */
  {

x++;                              /* increment x , so we can check boundry before moving */

if(x==scrxr){x--; goto check; }      /* if x position is equal to max screen right, decerement
                                       x and goto check, not allowing movement            */

if(collide(x,y)){x--; goto check;}  /* call the collide function, if it returns true(1) do not
                                       allow right movement   */

   move_sprite(old,200,0);             /* move the old sprite off screen */
   move_sprite(spr,x,y);               /* move new sprite onto screen    */
   delay(25);                          /* little delay  */
   old=spr;                            /* save the current sprite number in old */
   spr++;                              /* increment sprite number */
   if(spr==4) spr=0;                   /* check if we have reached the end of the 
                                          animation, if so start again  */
  }                                     /* end of right IF statment */


  if(key==J_LEFT)           /* see above */
   {
   x--;
if(x==scrxl){x++; goto check; }
if(collide(x,y)){x++; goto check;} 
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
if(collide(x,y)){y++; goto check;} 
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
if(collide(x,y)){y--; goto check;} 
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
