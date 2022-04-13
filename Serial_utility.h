/*
 * Serial_utility.h
 *
 * Created: 12/2/2021 1:32:03 μμ
 *  Author: Anestman
 */ 


#ifndef SERIAL_UTILITY_H_
#define  SERIAL_UTILITY_H_

#include <stdio.h>
#include <asf.h>
#include "../ASF/xmega/drivers/usart/usart.h"
#include "../ASF/xmega/drivers/usart/usart.h"
#include "../ASF/xmega/drivers/wdt/wdt.h"
#include "../ASF/xmega/utils/status_codes.h"
#include "sysclk.h"

#define RX_SERIAL IOPORT_CREATE_PIN(PORTD, 6)
#define TX_SERIAL IOPORT_CREATE_PIN(PORTD, 7)


void Serial_init(uint32_t baudrate);
void Serial_deactivate(void);
int Serial_put_char(char data, FILE *stream);
int Serial_get_char(FILE *stream);
uint8_t Serial_available(void);

static FILE Serial_print = FDEV_SETUP_STREAM(Serial_put_char, NULL, _FDEV_SETUP_WRITE);

static FILE Serial_read = FDEV_SETUP_STREAM(NULL, Serial_get_char, _FDEV_SETUP_READ);















#endif /*  SERIAL_UTILITY_H_ */