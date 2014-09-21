/*              Collision Detection Ver. 1.61
    If using Gb Development Studio please set Font to Courier 

         New Graphic's supplied by Russellkum@aol.com !

    --------------------------------------------------------
   | Example program to demonstrate basic animated sprites  |
   | and collision detection using arrays.                  |
   |                                                        |
   | New in Ver. 1.61                                       |
   | Level Storage system                                   |
   | Automatic calculation of collision array               |
   | Jump feature                                           |
   |                                                        |
   | To do in next ver.                                     |
   | Improve Level storage                                  |
   | Improve Jump                                           |
   | Front end ?                                            |
   | Bad Guys ?                                             |
   | Come up with a game idea                               |
   |--------------------------------------------------------|
   |             stephen.blanksby@virgin.net                |
    --------------------------------------------------------     */


#include <gb.h>
#include <bloke.c>               /* file containing tiles and data */

int test=0;                      /* change 0 to 1, to turn off gravity */
unsigned int temp;

int i,j,k,l,m,x,y,key,current,fall,updwn,p,q,t,u,v,w;

int array_size=40;                  /* lev_data contains 40 enteries */
unsigned int bound [40];            /* lev_data contains 40 enteries */

/* level data, if altered adjust the two 40's above */
/* x,x,y,y,object : 1=bricks 2=ladder */

unsigned int lev_data []=
{ 0, 10, 3, 5, 1, 8, 14, 4, 6, 1, 5, 14, 10, 12, 1, 2, 6, 12, 14, 1, 
7, 10, 14, 16, 1, 16,20,13,15,1,14, 15, 3, 18, 2, 10, 11, 13, 18, 2}; /* contains 40 enteries */

unsigned int scrxl=8;              /* screen boundry left */
unsigned int scrxr=160;            /* screen boundry right */
unsigned int scryt=14;             /* screen boundry top */
unsigned int scryb=145;            /* screen boundry bottom */


void data_arary()             /* cretaes the collision detection array from the lev_data */
{
  for(i=0;i<array_size;i=i+5)
   {
    j=i+1;
    k=i+2;
    l=i+3;
    m=i+4;  
    bound[i]=((lev_data[i]*8)+2); /* +2,+6,+1 and +6 are my sprite offsets */
    bound[j]=((lev_data[j]*8)+6);
    bound[k]=((lev_data[k]*8)+1);
    bound[l]=((lev_data[l]*8)+6);
    bound[m]=lev_data[m];
   }
}


void back()                  /* bkg func */
{
 set_bkg_data(1,3,briks);      /* start bkg display (platforms,ladders etc.) */
 for(x=0;x<20;x++)
 {
   for(y=0;y<40;y++)
   set_bkg_tiles(x,y,1,1,bkgtilea); 
 }

  for(i=0;i<array_size;i=i+5) /* gets the x,y coords from lev_data array */
   {
    j=i+1;
    k=i+2;
    l=i+3;
    m=i+4;  
    x=lev_data[i];
    u=lev_data[j];
    y=lev_data[k];
    v=lev_data[l];
    w=lev_data[m];

     if(w==1)                /* draws the bricks */
      {  for(x;x<u;x++)
          {
           set_bkg_tiles(x,y,1,1,brik);
           }

       if((v-y)!=2)
        { for(y;y<u;y++)
           {
            set_bkg_tiles(x,y,1,1,brik);
            }
        }
       }
    if(w==2)                 /* draws the ladders */
      {  
       if((v-y)!=2)
        { for(y;y<v;y++)
           {
            set_bkg_tiles(x,y,1,1,ladder);
            }
        }
       }
    }
 SHOW_BKG;                             
}                            /* end of bkg func */ 


int player()                 /* player moving func (see sprite4a.zip for more info) */
{
 key=joypad();                   /* key = what was pressed */

 if(key==J_RIGHT)
  {
   x++;         
   if(collide(x,y)==1){x--; return 0;} /* check we can move right */
    if(!fall)
     {
      current+=2;                      /* if we aren't falling continue animation */
      if(current==8) current=0;
      set_sprite_tile(0,current);
     }
   set_sprite_prop(0,0); 
   move_sprite(0,x,y);                 /* put sprite on screen */
   if(!fall)
    { delay(25); }                     /* delay if not falling */
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
   set_sprite_prop(0,S_FLIPX | 0x01);  /* flips horizontatly l/r sprite */
   move_sprite(0,x,y);
   if(!fall)
    { delay(25); }          
  return 1;
  } 

 if(key==J_UP)
  {
   y--;
  if(test){ if (collide(x,y)==1) {y++; return 0;} }  /* for testing purposes */
  else if(collide(x,y)!=2){y++; return 0;}
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
   if(test){ if (collide(x,y)==1) {y--; return 0;} }
   else if(collide(x,y)!=2){y--; return 0;}
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
  for(temp=0;temp<=127;temp++)
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

if(key==J_A+J_RIGHT || key==J_A+J_LEFT || key==J_A)
 {
 if(!fall){ jump();}
 return 1;
 }

return 0;
}                        /* end of player func */


int jump()               /* jump function */
{
 for(q=0;q<12;q++)
 {
  if(key==J_A+J_RIGHT){x++;}
  if(key==J_A+J_LEFT){x--;}

  for(p=0;p<2;p++)
   {
    y--;
    if(collide(x,y))
     {
      if(key==J_A+J_RIGHT){x--; y++; return 0;}
      if(key==J_A+J_LEFT){x++; y++; return 0;}
      y++; return 0;
     }
    move_sprite(0,x,y);
    delay(7);
  }
 }
 return 1;
}


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
         (x>=bound[i] && x<=bound[j])        /* check x position against boundrys */
         &&
         (y>=bound[k] && y<=bound[l])        /* check y position against boundrys */ 
          )  
          {return bound[m];}                 /* return m (object) if we are against a boundry */
     }
 return 0;                                   /* return 0 if we are not */
}                                /* end of collide function */


int grav()                       /* gravity and falling func. */
{
if(test){fall=0; return 0;}          /* test turns off gravity */
 y++;                                   /* check we are stood on something using the arrary*/
 if(collide(x,y)){y--; fall=0; return 0; }
 fall=1;                                /* if NOT, we fall.... */
 move_sprite(0,x,y);
 delay(7); 
 y++;                                   /* Do this twice so we fall down 2 before l/r movement*/
 if(collide(x,y)){y--; fall=0; return 0; }
 move_sprite(0,x,y); 
 delay(7);    
return 1;    
}                               /* end of gravity and falling func. */


/* ------------------------------------- main program-----------------------------------------*/
void main()                                  
{

 back();                         /* draw the background (platforms and ladders) */
 data_arary();                   /* create the collision detection array */
 updwn=6;                        /* first up and down tile number */
 current=0;                      /* first left right tile number */
 x=15;                           /* x cordinate to start at */
 y=16;                           /* y cordinate to start at */

 SPRITES_8x16;                     /* sets sprites to, yep you guessed it, 8x16 mode */
 set_sprite_data(0, 16, bloke);    /* defines the main sprite data */
 set_sprite_tile(0, current);
 move_sprite(current, x, y);       /* puts the first sprite on screen */
 SHOW_SPRITES;

  while(!0)                        /* infinate game loop */
  {
   grav();                         /* check we are stood on something and fall if we are'nt */
   player();                       /* player movement and collision detection routines      */
                                   /* returned values have no meaning here, just for tests  */
  }                                /* end of infinate loop */

}                            /* end main */

/* --------------------------------end of main program----------------------------------------*/

/* 
   There are probably lots of other (and maybe better) ways 
   of doing this, but thats for you to discover !
   
   If these examples help anyone I would love some feedback,
   comments, suggestions etc.
   If any of the above is incorrect I would also like to know.

   If anyone has turned this (or anyother) example into a game,
   email it to me....

   Have Fun !
   stephen.blanksby@virgin.net
   http://freespace.virgin.net/stephen.blanksby

   Thanks to Jeff, Pascal and many others !                */
