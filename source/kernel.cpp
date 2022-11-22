typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

#define VGA_ADDRESS 0xB8000
#define BUFSIZE 220

uint16* vga_buffer;

#define NULL 0

enum vga_color {
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    GREY,
    DARK_GREY,
    BRIGHT_BLUE,
    BRIGHT_GREEN,
    BRIGHT_CYAN,
    BRIGHT_RED,
    BRIGHT_MAGENTA,
    YELLOW,
    WHITE,
};

uint16 vga_entry(unsigned char ch, uint8 fore_color, uint8 back_color)
{
	uint16 ax = 0;
	uint8 ah = 0, al = 0;

	ah = back_color;
	ah <<= 4;
	ah |= fore_color;
	ax = ah;
	ax <<= 8;
	al = ch;
	ax |= al;

	return ax;
}

uint16 vga_pixel(uint8 back_color)
{
	uint16 ax = 0;
        uint8 ah = 0, al = 0;

        ah = back_color;
        ah <<= 4;
        ax = ah;
	ax <<= 8;

	return ax;
}

//clear video buffer array
void clear_vga_buffer(uint16 **buffer, uint8 fore_color, uint8 back_color)
{
	uint32 i;
	for (i = 0; i < BUFSIZE; i++)
	{
		(*buffer)[i] = vga_entry(NULL, fore_color, back_color);
		(*buffer)[i] = vga_pixel(back_color);
	}
}

//initialize vga buffer
void init_vga(uint8 fore_color, uint8 back_color)
{
	vga_buffer = (uint16*)VGA_ADDRESS; //point vga_buffer pointer to VGA_ADDRESS
	clear_vga_buffer(&vga_buffer, fore_color, back_color); //clear buffer
}

//main function
extern "C" void main()
{
	init_vga(WHITE, BLACK);
	
	vga_buffer[1] = vga_pixel(BLACK);
	vga_buffer[2] = vga_pixel(BLUE);
	vga_buffer[3] = vga_pixel(GREEN);
	vga_buffer[4] = vga_pixel(CYAN);
	vga_buffer[5] = vga_pixel(RED);
	vga_buffer[6] = vga_pixel(MAGENTA);
	vga_buffer[7] = vga_pixel(BROWN);
	vga_buffer[8] = vga_pixel(GREY);
	vga_buffer[9] = vga_pixel(DARK_GREY);
	vga_buffer[10] = vga_pixel(BRIGHT_BLUE);
	vga_buffer[11] = vga_pixel(BRIGHT_GREEN);
	vga_buffer[12] = vga_pixel(BRIGHT_CYAN);
	vga_buffer[13] = vga_pixel(BRIGHT_RED);
	vga_buffer[14] = vga_pixel(BRIGHT_MAGENTA);
	vga_buffer[15] = vga_pixel(YELLOW);
	vga_buffer[16] = vga_pixel(WHITE);

	return;
}
