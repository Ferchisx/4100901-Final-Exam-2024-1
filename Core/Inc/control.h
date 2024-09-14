/*
 * control.h
 *
 *  Created on: Sep 13, 2024
 *      Author: Felipe
 */

#ifndef INC_CONTROL_H_
#define INC_CONTROL_H_

#include <main.h>
#include <ring_buffer.h>
#include <stdint.h>
#include "ssd1306.h"
#include "ssd1306_fonts.h"

char* string(ring_buffer_t *rb);
void print(char* string);
int sum(uint8_t *uart2_buffer, uint8_t *keypad_buffer);

#endif /* INC_CONTROL_H_ */
