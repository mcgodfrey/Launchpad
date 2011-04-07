#include "msp430g2231.h"
#include "signal.h"

#define c2 65.41
#define cs2 69.30
#define dc 73.42
#define ds2 77.78
#define e2 82.41
#define f2 87.31
#define fs2 92.50
#define g2 98.00
#define gs2 103.83
#define a3 110.00
#define as3 116.54
#define b3 123.47
#define c3 130.81
#define cs3 138.59
#define d3 146.83
#define ds3 155.56
#define e3 164.81
#define f3 174.61
#define fs3 185.00
#define g3 196.00
#define gs3 207.65
#define a4 220.00
#define as4 233.08
#define b4 246.94
#define c4 261.63
#define cs4 277.18
#define d4 293.66
#define ds4 311.13
#define e4 329.63
#define f4 349.2
#define fs4 369.99
#define g4 392.00
#define gs4 415.30
#define a5 440.00
#define as5 466.16
#define c5 523.25

void playNote(int note, int time);
void delay_ms(int time);




void main(void){

  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  P1DIR |= 0x0C;                            // P1.2 and P1.3 output
  P1SEL |= 0x0C;                            // P1.2 and P1.3 TA1/2 options
  CCR0 = 0;                             // PWM Period
  CCTL1 = OUTMOD_7;                         // CCR1 reset/set
  TACTL = TASSEL_2 + MC_1;                  // SMCLK, up mode
  

  int delay1=300;
  int delay2=250;
  playNote(c4,delay1);
  playNote(ds4,delay2);
  playNote(f4,delay1);
  playNote(fs4,delay2);
  playNote(g4,delay1);
  playNote(as5,delay2);
  playNote(c5,delay1);
  playNote(as5,delay2);
  playNote(g4,delay1);
  playNote(fs4,delay2);
  playNote(f4,delay1);
  playNote(ds4,delay2);
  playNote(c4,delay1);
  /*
  playNote(c3,delay);
  playNote(cs3,delay);
  playNote(d3,delay);
  playNote(ds3,delay);
  playNote(e3,delay);
  playNote(f3,delay);
  playNote(fs3,delay);
  playNote(g3,delay);
  playNote(gs3,delay);
  playNote(a4,delay);
  playNote(as4,delay);
  playNote(b4,delay);
  */

     /*
  int k;
  for(k=0;k<5;k++){
     volatile unsigned int i;
     for (i = 0; i<= 100; i++){
        volatile int j;
        for(j=0;j<1000;j++);
     }
     
     CCR0=d;
     CCR1=CCR0/2;
     
     for (i = 0; i<= 100; i++){
        volatile int j;
        for(j=0;j<1000;j++);
     }
     
     CCR0=c;
     CCR1=CCR0/2;
    
  }
 
     */

  CCR0=0;

  _BIS_SR(CPUOFF);                          // Enter LPM0
}


     
void playNote(note,time){
   
   CCR0=1000000/note;
   CCR1=CCR0/2;
   delay_ms(time);
}

void delay_ms(time){

   volatile unsigned int i;
   for(i=0;i<100;i++){
      volatile unsigned int j;
      for(j=0;j<time;j++);
   }
}
