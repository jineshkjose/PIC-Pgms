#include<p16f877.inc>
org 0x00
goto main
org 0x04
goto intrpt
main:
CLRF 0X21
CLRF 0X22
MOVLW 0X00
BANKSEL TRISA
MOVWF TRISA

 MOVLW 80H
 BANKSEL ADCON1
MOVWF ADCON1

MOVLW 81H
BANKSEL ADCON0
MOVWF ADCON0

BSF GO_DONE
LOOP:BTFSC ADCON0,GO_DONE
GOTO LOOP

BANKSEL ADRESH
MOVFW ADRESH
MOVWF 0X21

BANKSEL ADRESL
MOVFW ADRESL
MOVWF 0X22
intrpt:
HERE:GOTO HERE
