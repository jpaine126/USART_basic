/*
 * USART_Init.h
 *
 * Created on: May 24, 2020
 *     Author: Jeffrey Paine
 *
 */

#ifndef F_CPU
#define F_CPU 16000000UL // or whatever may be your frequency
#endif

#define BAUD 9600

#include <avr/io.h>
#include <util/delay.h>                // for _delay_ms()
#include <util/setbaud.h>
#include <stdio.h>

#include "USART_Init.h"

char chararray[] = "this is a string 1234567890 !?<>.(*&";

int main(void)
{
    //DDRB |= _BV(DDB5);                      // initialize port B

    USART_Init();

    while(1)
    {
        USART_put_string(chararray);
        _delay_ms(1000);
        USART_transmit_char('\n');
        USART_transmit_char('\r');
    }


    return 0;
}
