#include <gb/gb.h>

/* a 8*8 tile that will be used for the background */
unsigned char stripes[] = 
{
    0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,
    0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42
};

void main() 
{
    /* sets the background data for 46 tiles of stripes starting at tile 0 */
    set_bkg_data(0, 46 , stripes); 
    
    while(1) 
    {
		SHOW_BKG; /* display the background */ 
    }   
}
