/*              Random Number Generator Ver. 1.0
    If using Gb Development Studio please set Font to Courier 

    --------------------------------------------------------
   | Example program to demonstrate how to generate a       |
   | random number from a seed value.                       |
   |                                                        |
   | To do in next ver.                                     |
   | Make the seed value more unpredictable                 |
   |--------------------------------------------------------|
   |     http://freespace.virgin.net/stephen.blanksby       |
   |             stephen.blanksby@virgin.net                |
    --------------------------------------------------------     */
    
#include <gb.h>

unsigned int r,seed,key;


void main()
{
 seed=0;
 key=0;
 r=0;
 
 gotoxy(0,10);
 printf("Press any key !");
 gotoxy(0,0);

  while(!joypad()){seed++; if(seed>=255)seed=1;}  /* creates a seed value for the random number                                                      generator from the time taken to press the                                                      first key  */
  waitpadup();
  initrand(seed);                    /* init the random number generator with our seed value */
  printf("Seed = %u ",seed);         /* prints the seed value (unsigned) on screen */
  
  while(!0)
  {
   r=rand();                         /* call the random number generator */
   gotoxy(0,2);
   printf("Rand = %u  ",r);          /* prints the random number (unsigned) on screen */
   
   while(!joypad());
   waitpadup();  
  }
                                   
}

                         