
/*
 * USART_Init.h
 *
 * Created on: May 24, 2020
 *     Author: Jeffrey Paine
 *
 */

#include <avr/io.h>

void USART_Init(void)
{
	//set baud
	UBRR0H = UBRRH_VALUE;
    UBRR0L = UBRRL_VALUE;

    //2X mode
#if USE_2X
    UCSR0A |= _BV(U2X0);
#else
    UCSR0A &= ~(_BV(U2X0));
#endif

    //enable rx and tx
    UCSR0B = _BV(RXEN0) | _BV(TXEN0);

    //set frame format: 8data, 2stop
    UCSR0C = _BV(UCSZ01) | _BV(UCSZ00) | _BV(USBS0);
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
