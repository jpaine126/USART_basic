/*
 * led.c
 *
 *  Created on: Apr 8, 2020
 *      Author: jpaine
 */


#ifndef F_CPU
#define F_CPU 16000000UL // or whatever may be your frequency
#endif

#define BAUD 9600
#define FOSC 1000000

#define MYUBBR FOSC/16/BAUD-1

#include <avr/io.h>
#include <util/delay.h>                // for _delay_ms()
#include <util/setbaud.h>
#include <stdio.h>

#include "USART_Init.h"

char chararray[] = "this is a string";

int main(void)
{

    // //DDRB |= _BV(DDB5);                      // initialize port B

    USART_Init(MYUBBR);

    while(1)
    {
        USART_put_string(chararray);
        _delay_ms(1000);
        USART_transmit_char('\n');
        USART_transmit_char('\r');
    }


    return 0;
}






