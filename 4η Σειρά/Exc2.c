/*
 * GccApplication1.c
 *
 */ 

#include <avr/io.h>

char A,B,C,D,F0,F1;

int main(void)
{
	DDRB=0xFF;
	DDRA=0x00;
    while (1) 
    {
		A=PINA & 0x01;
		B=PINA & 0x02;
		C=PINA & 0x04;
		D=PINA & 0x08;
		B=B>>1;
		C=C>>2;
		D=D>>3;
		F0= !((A & B & (!C)) | (C & D));
		F1= ((A | B) & (C | D)) <<1;
		PORTB = (F0 | F1);
			
    }
}
/*A=PINA & 0x01;
		B=PINA & 0x02;
		C=PINA & 0x04;
		D=PINA & 0x08;
		if ((A==1 && B==2 && C==0) || (C==4 && D==8)){
			F0=0b00000000;
			}
		else{
			F0=0b00000001;	
			}
		if ((A==1 || B==2) && (C==4 || D==8)){
				F1=0b00000010;
			}
		else {
				F1=0b00000000;
			}
		F0= ~((A & B & (~C)) | (C & D));
		F1= ((A | B) & (C | D));
		F1<<1;*/
