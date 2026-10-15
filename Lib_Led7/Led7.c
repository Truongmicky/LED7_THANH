#include "Led7.h"

/**
 * @brief Bang ma Hex gia ma hien thi cac so tu 0 -> 9 cho LED CATHODE CHUNG.
 * Cac bit tu 0 den 6 dai dien cho trang thai bat/tat cua cac doan [a, b, c, d, e, f, g].
 * Tu khoa 'static' giup gioi han pham vi mang nay chi nam trong file led7.c (Clean Code).
 */
 
 
 static const uint8_t segments[10] = {
		0X3F, //0
		0x06, //1
		0x5B, //2
		0x4F, //3
		0x66, //4
		0x6D, //5
		0x7D, //6
		0x07, //7
		0x7F, //8
		0x6F, //9
 };

void LED_Init(LED_Handler_t *LED , LED_GPIO_t segpin[7] , LED_TYPE_t type){
	
	LED->type = type;// Type LED
	
	// Gan thong tin 7 chan ket noi (a->g) vao struct quan ly tong
	for(int i = 0 ; i < 7 ;i++){
	LED->SEG[i] = segpin[i];
	}
	
	LED_Clear(LED);
	
}

LED7_Status_t LED_DisplayNumber(LED_Handler_t *LED , uint8_t number){
	
	if(LED == NULL){
		return  LED7_ERR_2;
	}
	
	if(number > 9){ 
	return  LED7_ERR_1 ;
	}

	uint8_t data = segments[number];
	
	for(int i = 0 ; i < 7 ; i++){
	
	uint8_t bit = (data >> i) & 0x01;
		
	GPIO_PinState state;
		
	if(LED->type == LED_ANODE){
		state = (bit == 1) ? GPIO_PIN_RESET : GPIO_PIN_SET;
	}else{
		state = (bit == 1) ? GPIO_PIN_SET : GPIO_PIN_RESET;
	}
	
	HAL_GPIO_WritePin(LED->SEG[i].PORT ,LED->SEG[i].PIN ,state);
}
	
	return LED7_OK ;
 }






void LED_Clear(LED_Handler_t *LED){

	for(int i = 0 ; i < 7 ; i++){
		
		GPIO_PinState off_state;
		
		if(LED == LED_ANODE){
		off_state = GPIO_PIN_RESET;
			
		}else{
			
		off_state = GPIO_PIN_SET;
		}
	}
		

}





