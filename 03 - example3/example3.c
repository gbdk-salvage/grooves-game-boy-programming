/*                      Example 3
    --------------------------------------------------------
   | Example program to demonstrate basic user input and    |
   | output to the Gb screen. A simple cls() clears the     |
   | screen by putting a space over every character in      |
   | the display. The pasword is all in capitals, so the    |
   | users input is converted into upper case by calling    |
   | toupper and passing the input string to it until we    |
   | reach the NULL terminator at the end.                  |
   | Use cursor keys to choose a letter and prees button A  |
   | to enter it. Use button B to backspace. Press Start to |
   | enter the password.                                    |
   |--------------------------------------------------------|
   |             stephen.blanksby@virgin.net                |
    --------------------------------------------------------     */


#include <gb.h>

char string[10];           /* input string, max length 10 characters */
char password[]="TEST";    /* the password */

void cls()
{                                /* simple clear screen function */
  int x, y;

  for(y = 0; y < 20; y++)        /* loop for the num of charaters across (x)*/
    for(x = 0; x < 30; x++)      /* loop for the num of charaters high (y)*/
    {    
      gotoxy(x, y);              /* moves the postion to x,y */
      setchar(' ');              /* puts a space on screen */
    }                            /* does the above until we have cleared the screen */
gotoxy(0,0);                     /* returns the position to the top left */
}


void main()                  /* main program */
{
char c='a';
int x=0;

  puts("Login Password :\n");   
  gets(string);               /* gets users input */
  
 while(c)                /* converts (input) string to upper case until it reaches a NULL character */
 {
 c=string[x];            /* makes c equal to letter x of the input string */
 c=toupper(c);           /* converts that letter to upper case */
 string[x]=c;            /* puts the letter back where it found it */
 x++;                    /* moves to the next letter */
 }

cls(); 


x=strcmp(string,password);         /*re-uses x ,strcmp returns 0 if both strings match */
  if(x==0)                         /* checks if x is equal to 0 if so, executes the code in the first {brackets} */
  {
  puts("Correct Password !\n");    
  puts("You have gained ");
  puts("access to");  
  puts("\n     City Bank");
  puts("\nYour account has ");
  puts("been credited with");
  puts("\n    $1,000,000");
  puts("\n\nHave a Nice Day !");
  }
    else                           /* if not, executes the below code in brackets */
    {
    puts("\n\n    Incorrect");
    puts("\n The FBI have been");
    puts("     notified");
    }
}                                 /* end main */


/* There are probably lots of other (and maybe better) ways 
   of doing this, but thats for you to discover !
   
   If these examples help anyone I would love some feedback,
   comments, suggestions etc.
   If any of the above is incorrect I would also like to know.

   Have Fun !
   stephen.blanksby@virgin.net
   http://freespace.virgin.net/stephen.blanksby                 */