/*
 * control.c
 *
 *  Created on: Sep 13, 2024
 *      Author: Felipe
 */
#include <control.h>

char* string(ring_buffer_t *rb){
	uint8_t data;
	uint8_t size = ring_buffer_size(rb);
	int i = 0;
	char nums[size];
	while (!ring_buffer_is_empty(rb) && i <  size - 1) {
		if (ring_buffer_read(rb, &data)) {
			nums[i++] = data;
		}
	}
	nums[i] = '\0';
	return nums;
}

void print(char* string){
	if(string == 'keypad_nums'){
		ssd1306_Fill(Black);
		ssd1306_SetCursor(30,20);
		ssd1306_WriteString(string,Font_7x10,White);
		ssd1306_UpdateScreen();
	}
	else if(string == 'usart2_nums'){
		ssd1306_Fill(Black);
		ssd1306_SetCursor(15,20);
		ssd1306_WriteString(string,Font_7x10,White);
		ssd1306_UpdateScreen();
	}
}
