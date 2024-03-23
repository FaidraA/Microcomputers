;
; AssemblerApplication3.asm
;
; Created: 19/5/2021 11:31:31 μμ
; Author : zoe
;


reset: ldi r24 , low(RAMEND) ; αρχικοποίηση stack pointer
       out SPL , r24
       ldi r24 , high(RAMEND)
       out SPH , r24

       ser r26 ; αρχικοποίηση της PORTA
       out DDRA , r26 ; για έξοδο
	   clr r24 ; initialize PORTB
       out DDRB, r24 ; for input

main:  clr r24; μετρητης για την θεση των led
       ldi r26,0x01 ;initialize r26
       rcall left
	   nop
	   rcall right
	   rjmp main

left:    in r25, PINB; ελεγχος εισοδου
         andi r25, 0x04
		 cpi r25, 0x04
		 breq left
		 out PORTA, r26
		 inc r24
		 lsl r26
		 cpi r24,7 
		 breq right
		 rjmp left

		 ret
		 

right:   in r25, PINB; ελεγχος εισοδου
         andi r25, 0x04
		 cpi r25, 0x04
		 breq right
		 out PORTA, r26
		 dec r24
		 lsr r26
		 cpi r24,0 
		 breq left
		 rjmp right

		 ret
		 