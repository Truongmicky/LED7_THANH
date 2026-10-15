#ifndef LED_7
#define LED_7

#include "stm32f1xx_hal.h"

typedef enum {
    LED7_OK    = 0, // Th?c thi thành công
    LED7_ERR_1 = 1, // L?i truy?n s? vu?t quá ph?m vi (> 9)
    LED7_ERR_2 = 2  // L?i con tr? NULL (hled truy?n vào b? r?ng)
} LED7_Status_t;

// * Data structures private

//1 type LED - ANODE
//1 type LED - CATHODE
// Enum dinh nghia kieu LED (ANODE / CATHODE)
typedef enum{
	LED_ANODE = 0, 	// LED Anode chung (CA) - N?i chân chung vào VCC
	LED_CATHODE = 1 // LED Cathode chung (CC) - N?i chân chung vào GND
}LED_TYPE_t;

//Struct quan ly 1 chan GPIO (port + pin)

typedef struct{
	GPIO_TypeDef *PORT; // Port dieu khien (VD: GPIOA, GPIOB)
	uint16_t PIN;			// Chan GPIO (VD: GPIO_PIN_0, GPIO_PIN_1)
}LED_GPIO_t;

//Struct quan ly 1 LED 7 don (mang 7 chan segments + type)

typedef struct{
	LED_GPIO_t SEG[7];// Mang 7 phân tu tuong ung voi 7 doan : a, b, c, d, e, f, g
	LED_TYPE_t type; // Loai LED (ANODE hoac CATHODE)
}LED_Handler_t;

// cau hinh cho led 7 cau truc tong the cua
void LED_Init(LED_Handler_t *LED , LED_GPIO_t segpin[7] , LED_TYPE_t type);

//hien thi so ra man
LED7_Status_t LED_DisplayNumber(LED_Handler_t *LED , uint8_t number);

//tat led khi can
void LED_Clear(LED_Handler_t *LED);


#endif



