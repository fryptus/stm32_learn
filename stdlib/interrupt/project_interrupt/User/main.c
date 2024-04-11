#include "stm32f10x.h"                  // Device header
#include "LED.h"
#include "Key.h"
#include "Delay.h"

int main(void)
{
	LED_Init();
		
	LED_IBreathing();
}
