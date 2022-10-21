/*
 *	LCD interface header file
 *	See lcd.c for more info
 */

/* write a byte to the LCD in 4 bit mode */

extern void lcd_write(unsigned char);

/* Clear and home the LCD */

extern void lcd_clear(void);

extern void lcd_scroll(void);

extern void lcd_scroll_right(void);

extern void lcd_cursor_right(void);

extern void lcd_init_cursor_left_end(void);

extern void lcd_scroll_puts(const char *);

/* write a string of characters to the LCD */

extern void lcd_puts(const char * s);

extern void lcd_num_float(float);

extern void lcd_num_dec(int);
/* Go to the specified position */

extern void lcd_goto(unsigned char pos);
	
/* intialize the LCD - call before anything else */

extern void lcd_init(void);

extern void lcd_putch(char);

/*	Set the cursor position */

#define	lcd_cursor(x)	lcd_write(((x)&0x7F)|0x80)
