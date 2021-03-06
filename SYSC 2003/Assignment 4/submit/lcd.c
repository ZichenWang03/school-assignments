// By Korey Conway and Tanzeel Rana

asm (".include 'basicLCD.s'");

extern void LCD_display(char ascii_char);
extern void Lcd2PP_Init(void);
extern void LCD_instruction(char instruction);

void lcd_init(void);
void lcd_print(char *string, int address);
void lcd_print_top(char *string);
void lcd_print_bottom(char *string);

#define	LCD_ROW_TOP		0x00
#define	LCD_ROW_BOTTOM	0xC0

/*
	Initialize the lcd
*/
void lcd_init()
{
	Lcd2PP_Init();
}

/*
	Print a string at the given location
*/
void lcd_print(char *string, int address)
{
	DDRT = 0x0F; // Setup port T
	PTT = 0x00;
	DDRM = 0xFE; // Setup port M
	PTM = 0x00;
	DDRP |= 0x0F; // Set P0-3 as outputs
	SPI1CR1 &= ~0x40; // Disable SP by turning SPI1 off
	
	LCD_instruction(address);
	while (0 != *string) {
		LCD_display(*string++);
	}
}

/*
	Print a string on the top line
*/
void lcd_print_top(char *string)
{
	lcd_print(string, LCD_ROW_TOP);
}

/*
	Print a string on the bottom line
*/
void lcd_print_bottom(char *string)
{
	lcd_print(string, LCD_ROW_BOTTOM);
}
