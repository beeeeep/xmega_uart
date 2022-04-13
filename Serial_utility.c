/*
 * Serial_utility.c
 *
 * Created: 12/2/2021 1:39:19 μμ
 *  Author: Anestman
 */ 

#include "Serial_utility.h"




void Serial_init(uint32_t baudrate)
{
	usart_rs232_options_t usart_options;
	usart_options.baudrate=baudrate;
	usart_options.charlength=USART_CHSIZE_8BIT_gc;
	usart_options.paritytype=USART_PMODE_DISABLED_gc;
	usart_options.stopbits=false;				
	 usart_init_rs232(&USARTD1,&usart_options);
	 
	 ioport_set_pin_dir(RX_SERIAL, IOPORT_DIR_INPUT);
	 ioport_set_pin_dir(TX_SERIAL, IOPORT_DIR_OUTPUT);
}

void Serial_deactivate(void)
{
	sysclk_disable_peripheral_clock(&USARTD1);
	usart_tx_disable(&USARTD1);
	usart_rx_disable(&USARTD1);
	 ioport_set_pin_dir(RX_SERIAL, IOPORT_DIR_INPUT);
	 ioport_set_pin_dir(TX_SERIAL, IOPORT_DIR_INPUT);
}

int Serial_put_char(char data, FILE *stream)
{		
		usart_putchar(&USARTD1,data);	
	return 0;  
}

int Serial_get_char(FILE *stream)
{

	while (usart_rx_is_complete(&USARTD1) == false)
	 {
		 wdt_reset();
	}
	
	return ((uint8_t)(&USARTD1)->DATA);

}

uint8_t Serial_available(void)
{
	if((uint8_t)((&USARTD1)->DATA)=='\n')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
