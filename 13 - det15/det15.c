/*              Collision Detection Ver. 1.5
    --------------------------------------------------------
   | Example program to demonstrate basic animated sprites  |
   | and collision detection using arrays.                  |
   |                                                        |
   | New in Ver. 1.5                                        |
   | Player and gravity funcs in a routine                  |
   | More efficient use of sprite tiles (only 1 used)       |
   | Bkg now in a func.                                     |
   |                                                        |
   | To do in next ver.                                     |
   | Improve on ladder/wall thingy                          |
   | Improve and tidy up falling routine                    |
   | Level Storage system                                   |
   | Come up with a game idea                               |
   | A FAQ cos its getting messy in here ; )                |
   |--------------------------------------------------------|
   |             stephen.blanksby@virgin.net                |
    --------------------------------------------------------     */


#include <gb.h>
#include <bloke.c>               /* file containing tiles and data */

int i,j,k,l,m,x,y,key,current,fall,updwn;
int array_size=15;                  /* the below arrary contains 15 entries */
                                    /* x,x,y,y,object : 1=bricks 2=ladder */
unsigned int boundx []={ 1, 86 ,17 ,38,1 ,72 ,117 ,33 ,54, 1, 117, 124, 32, 145, 2 };
unsigned int scrxl=8;              /* boundry left */
unsigned int scrxr=160;            /* boundry right */
unsigned int scryt=8;              /* boundry top */ 
unsigned int scryb=145;            /* boundry bottom */
unsigned int test;

void back()                       /* bkg func */
{
 set_bkg_data(1,3,briks);          /* start bkg display (platforms,ladders etc.) */
 for(x=0;x<20;x++)
 {
   for(y=0;y<40;y++)
   set_bkg_tiles(x,y,1,1,bkgtilea); 
 }

 for(x=0;x<10;x++)
  {
   set_bkg_tiles(x,2,1,1,brik); 
  }
 for(x=9;x<14;x++)
  {
   set_bkg_tiles(x,4,1,1,brik);
  }
 for(y=4;y<18;y++)
  {
   set_bkg_tiles(14,y,1,1,ladder); 
  }
 SHOW_BKG;                             
}                                    /* end of bkg func */ 


int player()                     /* player moving func (see sprite4a.zip for more info) */
{
 key=joypad();                    /* key = what was pressed */

 if(key==J_RIGHT)
  {
   x++;         
   if(collide(x,y)==1){x--; return 0;}    /* check we can move right */
    if(!fall)
     {
      current+=2;                      /* if we aren't falling continue animation */
      if(current==8) current=0;
      set_sprite_tile(0,current);
     }
   set_sprite_prop(0,0); 
   move_sprite(0,x,y);               /* put sprite on screen */
   if(!fall)
    { delay(25); }          /* delay if not falling */
  return 1;
  } 

 if(key==J_LEFT)
  {
   x--;
   if(collide(x,y)==1){x++; return 0;}
    if(!fall)
     {
      current+=2;
      if(current==8) current=0;
      set_sprite_tile(0,current);
     }
   set_sprite_prop(0,S_FLIPX | 0x01); 
   move_sprite(0,x,y);
   if(!fall)
    { delay(25); }          
  return 1;
  } 

 if(key==J_UP)
  {
   y--;
   if(collide(x,y)!=2){y++; return 0;}
   updwn+=2;
   if(updwn==16)
     { updwn=8; }
   set_sprite_tile(0,updwn);
   move_sprite(0,x,y);
   if(!fall)
    { delay(25); }
  return 1;
  }

 if(key==J_DOWN)
  {
   y++;
   if(collide(x,y)!=2){y--; return 0;}
   updwn+=2;
   if(updwn==16)
    { updwn=8; }
   set_sprite_tile(0,updwn);
   move_sprite(0,x,y);
   if(!fall)
    { delay(25); }
  return 1;
  }

if(key==J_B)              /* just for testing purposes */
  {
  move_sprite(0,200,200);
  delay(500);
  for(test=0;test<128;test++)
   {
    scroll_bkg(0,2);
    delay(5);  
   }
  delay(500);
  move_sprite(0,15,16);
  x=15;
  y=16;
  return 1;
  }
return 0;
}                        /* end of player func */


int collide(int x,int y)         /* collision detection function */
{
 if(x==scrxl || x==scrxr || y==scryt || y==scryb) {return 1;}  /* check screen boundrys */
 for(i=0;i<array_size;i=i+5)
     {
      j=i+1;
      k=i+2;
      l=i+3;
      m=i+4;
        if(
         (x>=boundx[i] && x<=boundx[j])        /* check x position against boundrys */
         &&
         (y>=boundx[k] && y<=boundx[l])        /* check y position against boundrys */ 
          )
          {return boundx[m];}                      /* return m if we are against a boundry */
     }
 return 0;                                  /* return 0 if we are not */
}                                 /* end of collide function */


int grav()                       /* gravity and falling func. */
{
 y++;                                     /* check we are stood on something using the arrary*/
 if(collide(x,y)){y--; fall=0; return 0; }
 fall=1;                                   /* if NOT, we fall.... */
 move_sprite(0,x,y);
 delay(10); 
 y++;                                     /* Do this twice so we fall down 2 before l/r movement*/
 if(collide(x,y)){y--; fall=0; return 0; }
 move_sprite(0,x,y); 
 delay(10);    
return 1;    
}                               /* end of gravity and falling func. */


/* ------------------------------------- main program-----------------------------------------*/
void main()                                  
{
 back();                         /* draw the background (platforms and ladders) */

 updwn=6;                        /* first up and down tile number */
 current=0;                      /* first left right tile number */
 x=15;                           /* x cordinate to start at */
 y=16;                           /* y cordinate to start at */

 SPRITES_8x16;                     /* sets sprites to, yep you guessed it, 8x16 mode */
 set_sprite_data(0, 16, bloke);    /* defines the main sprite data */
 set_sprite_tile(0, current);
 move_sprite(current, x, y);         /* puts the first sprite on screen */
 SHOW_SPRITES;

  while(!0)                        /* infinate game loop */
  {
   grav();                         /* check we are stood on something and fall if we are'nt */
   player();                       /* player movement and collision detection routines      */
  }                                /* end of infinate loop */

}                                 /* end main */

/* ---------------------------------end of main program----------------------------------------*/

/* 
   There are probably lots of other (and maybe better) ways 
   of doing this, but thats for you to discover !

   Thanks to Robert of GenFan. for the ideas and tips !

   If these examples help anyone I would love some feedback,
   comments, suggestions etc.
   If any of the above is incorrect I would also like to know.

   Have Fun !
   stephen.blanksby@virgin.net
   http://freespace.virgin.net/stephen.blanksby

   Thanks to Jeff, Pascal and many others !                */
