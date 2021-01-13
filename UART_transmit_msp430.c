#include <msp430.h>
#include <Library/LunchboxCommon.h>
#include <stdio.h>
#include <string.h>
#define SW  BIT3                    // Switch -> P1.3 (On-board Switch, Pull-Up configuration)
#define LED BIT7                    // Red LED -> P1.7 (On-Board LED, Active High Configuration)

void register_settings_for_UART()
{
    P1SEL = BIT1 + BIT2;              // Select UART RX/TX function on P1.1,P1.2
    P1SEL2 = BIT1 + BIT2;

    UCA0CTL1 |= UCSSEL_1;               // UART Clock -> ACLK
    UCA0BR0 = 3;                        // Baud Rate Setting for 32kHz 9600
    UCA0BR1 = 0;                        // Baud Rate Setting for 32kHz 9600
    UCA0MCTL = UCBRF_0 + UCBRS_3;       // Modulation Setting for 32kHz 9600
    UCA0CTL1 &= ~UCSWRST;               // Initialize UART Module
    IE2 |= UCA0RXIE;                    // Enable RX interrupt
}

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;       //! Stop Watchdog
    P1DIR |= LED;                   // Set LED pin -> Output
    P1DIR &= ~SW;                   // Set SW pin -> Input
    volatile int i;                 // temporary integer for looping
    register_settings_for_UART();

    initialise_SerialPrint_on_lunchbox();
    signed int temp_val=0;            //initializing int value

    while(1)
       {
            printf("%d\n",temp_val);    //send the data serially
            for(i=0;i<20000;i++);       //delay between data transmission
            temp_val=temp_val+1;        //incrementing int value

            if(!(P1IN & SW))            // If SW is Pressed
                 {
                 while(!(P1IN & SW));    // Wait till SW Released
                 P1OUT ^= LED;           // Toggle LED
                 temp_val=0;             // Reset temp_val
                 }
       }
}

