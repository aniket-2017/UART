# UART using MSP430 and Arduino UNO
This is the examle of configuration of UART in C using MSP430g2553 and Arduino UNO. Simple routines are used for better understanding of the peripheral.

## Getting Started
Clone or download this repository on your computer. In the docs folder there is the x5xx manual. In the src folder is the header and the implementation of the functions.

## Prerequisites
### Boards used
- MSP430G253 lunchbox kit 
- Arduino UNO

### Connections
- (msp430) P1.1 > TX(1) Arduino UNO
- (msp430) P1.2 > RX(0) Arduino UNO
- 7(Arduino UNO) > LED1 +ve
- 8(Arduino UNO) > LED2 +ve

### Compatibility
I have written this code using MSP430G253 lunchbox kit which was is manufactured by sincgrid. This code will also work well with the MSP430 launchpad kit offered by Texas Instruments.
This code does not use interrupts and LPM modes, and it is not intended to be used in industry.
 
## Built With
- IDE: Code Composer Studio  Version: 9.3.0.00012
- Compiler: TI v4.4.5
- Arduino IDE  Version: 1.8.13

## Useful Links
- Buy MSP4340: https://store.sincgrid.com/index.php?route=product/product&product_id=68
- Buy Arduino UNO: https://store.arduino.cc/usa/arduino-uno-rev3
- More projects on: https://github.com/ticepd/EmbSysDesign_NPTEL_Course.git

## Video
- https://www.linkedin.com/posts/aniketarya17_texasinstruments-arduino-embeddedc-activity-6755417729445990400-KKZR
