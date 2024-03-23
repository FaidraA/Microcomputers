#include <avr/io.h>

char SW0, SW1, SW2, SW3,led;

int main(void)
{
	DDRA=0xFF;
	DDRC=0x00;
	led=1;
	while (1){
		SW0=PINA & 0x01;
		SW1=PINA & 0x02;
		SW2=PINA & 0x04;
		SW3=PINA & 0x08;
		if (SW0 == 1){
			while (SW0 == 1);
			if (led== 128){
				led=1;
			}
		else{
			led =led << 1;
		}
		if (SW1 == 2){
			while (SW1 == 2);
			if (led== 1){
				led=128;
			}
			else{
				led =led >> 1;
			}
		if (SW2 == 4){
			while (SW2 == 4);
			led=128;
		}
		if (SW3 == 8){
			while (SW0 == 1);
			led=1;
		}
		PORTA= led;	
		}
	}
}