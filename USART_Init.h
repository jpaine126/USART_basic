/*
 * USART_Init.h
 *
 * Created on: May 24, 2020
 *     Author: Jeffrey Paine
 *
 */

#include <avr/io.h>

void USART_Init(unsigned int ubrr)
{
	//UBRR0H = (unsigned char)(ubrr>>8);
	//UBRR0L = (unsigned char)(ubrr);

	UBRR0H = UBRRH_VALUE;
    UBRR0L = UBRRL_VALUE;

    //UCSR0B = (1 << RXEN0)|(1 << TXEN0);
    //UCSR0C = (1 << UCSZ00)|(1 << UCSZ01);

    UCSR0B = _BV(RXEN0) | _BV(TXEN0);
    UCSR0C = _BV(UCSZ01) | _BV(UCSZ00);
}

void USART_transmit_char(unsigned char data)
{
	while( !(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}

void USART_put_string(char* StringPtr)
{
	while( *StringPtr != 0x00 )				//check to see if there are more chars to send
	{
		USART_transmit_char(*StringPtr);	//send the next char
		StringPtr++;						//increment pointer
	}
}

void USART_Recieve(void)
{
	while( !(UCSR0A & (1 << RXC0) ));
	return UDR0;
}








