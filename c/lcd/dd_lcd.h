#ifndef DD_LCD_H
#define DD_LCD_H

#define LCD_COMMAND_DATA PORTD
#define LCD_RS           RC0
#define LCD_EN           RC2

#define LCD_INIT       0x38
#define LCD_DISPLAY_ON 0x0C
#define LCD_CLEAR      0x01
#define LCD_ROW1       0x80
#define LCD_ROW2       0xC0


void lcd_en(void);
void clr_lcd(void);
void Config_IO(void);
void Init_LCD(void);
void Set_LCD_Command(unsigned char lcd_cmd);
void Set_LCD_Data(unsigned char lcd_data);
void LCD_Delay(void);
void LCD_Scrol_String(const char *str);
void LCD_Delay_Scrol(void);
void lcd_puts(const char * s);
void lcd_goto(unsigned char pos);
void Set_LCD_Num(int num);
void lcd_write(unsigned char);
void lcd_num_float(float num);
#endif 



