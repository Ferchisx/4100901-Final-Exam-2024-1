/*
 * control.c
 *
 *  Created on: Sep 13, 2024
 *      Author: Felipe
 */
#include <control.h>
#include <main.h>

/*The idea of the following function is to get the numbers in the indicated buffer
 * and store them as a string, returning the string to later work with it*/
char* string(ring_buffer_t *rb){
	uint8_t data;	//Value taken as a number
	uint8_t size = ring_buffer_size(rb);	//Size of the buffer for the loop
	int i = 0;	//Control the loop
	char nums[size];	//Char where I create the string and save the numbers
	while (!ring_buffer_is_empty(rb) && i <  size - 1) {
		if (ring_buffer_read(rb, &data)) {
			nums[i++] = data;
		}
	}
	nums[i] = '\0';	//Null value to make it a valid string
	return nums;
}

/*The idea of the following code is to print the necessary string in the OLED screen*/
void print(char* string){
	if(string == 'keypad_nums'){
		ssd1306_SetCursor(30,20);
		ssd1306_WriteString(string,Font_7x10,White);
		ssd1306_UpdateScreen();
	}
	else if(string == 'usart2_nums'){
		ssd1306_SetCursor(15,20);
		ssd1306_WriteString(string,Font_7x10,White);
		ssd1306_UpdateScreen();
	}
}

/*This funciton is made to do the sum between the numbers entered
 * trough USART2 and the KeyPad
 * I use the atoi function to convert the string to an integer*/
int sum(uint8_t *uart2_buffer, uint8_t *keypad_buffer) {
    // Convert the UART2 buffer to an integer
    int uart_value = atoi(uart2_buffer);

    // Convert the KeyPad buffer to an integer
    int keypad_value = atoi(keypad_buffer);

    // Sum the two values
    int total_sum = uart_value + keypad_value;

    return total_sum;
}
