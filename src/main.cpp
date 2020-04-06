/**
 * @file main.cpp
 * @author https://github.com/Sapieron
 * @brief Main application - this is where we start right after
 * 		  startup_stm32f103xb.s
 * @version 0.1
 * @date 2020-03-03
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <cstdint>

#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_uart.h"
#include "stm32f1xx.h"
#include "system_stm32f1xx.h"

#include "gpio/forward.hpp"
#include "mcu/board.hpp"

/** @brief Instance of Board. Delivers access to peripherals */
BOARD Main;

void SetupHardware()
{
	__HAL_RCC_GPIOA_CLK_ENABLE();      //FIXME make it pretty!
	__HAL_RCC_GPIOB_CLK_ENABLE();
	Main.Hardware.Initialize();
}

/******************************************************************************\
 * 						TEMPORARY CODE TO TEST ON
\******************************************************************************/
// UART_HandleTypeDef uartInitInstance;

// void SetupTerminal()
// {
// 	/* TX on PA2, RX on PA3 */
// 	//1. turn on clock
// 	__HAL_RCC_GPIOA_CLK_ENABLE();
// 	__HAL_RCC_USART2_CLK_ENABLE();

// 	//2. configure RX and TX pins
// 	GPIO_InitTypeDef gpioOfUart2;
// 	gpioOfUart2.Mode = GPIO_MODE_AF_PP;
// 	gpioOfUart2.Speed = GPIO_SPEED_FREQ_LOW;
// 	gpioOfUart2.Pull = GPIO_NOPULL;
// 	gpioOfUart2.Pin = GPIO_PIN_2;
// 	HAL_GPIO_Init(GPIOA, &gpioOfUart2);

// 	gpioOfUart2.Mode = GPIO_MODE_AF_INPUT;
// 	gpioOfUart2.Speed = GPIO_SPEED_FREQ_LOW;
// 	gpioOfUart2.Pull = GPIO_NOPULL;
// 	gpioOfUart2.Pin = GPIO_PIN_3;
// 	HAL_GPIO_Init(GPIOA, &gpioOfUart2);
	
// 	//3. configure usart2
// 	uartInitInstance.Instance = USART2;
// 	uartInitInstance.Init.BaudRate = 115200;
// 	uartInitInstance.Init.Mode = UART_MODE_TX_RX;
// 	uartInitInstance.Init.Parity = UART_PARITY_NONE;
// 	uartInitInstance.Init.StopBits = UART_STOPBITS_1;
// 	uartInitInstance.Init.WordLength = UART_WORDLENGTH_8B;
// 	uartInitInstance.Init.HwFlowCtl = UART_HWCONTROL_NONE;
// 	uartInitInstance.Init.OverSampling = UART_OVERSAMPLING_16;
// 	HAL_UART_Init(&uartInitInstance);

// }

// #include <cstring>
// void uartSendString(char const* wordToSend)
// {
// 	//4. use HAL to send string
// 	auto wordLength = static_cast<std::uint16_t>(strlen(wordToSend) );
// 	HAL_UART_Transmit(&uartInitInstance, (std::uint8_t*)wordToSend, wordLength, 1000);		//check UART_Transmit_DMA
// }

// FIXME oscillator does not oscillate, please check hardware
// void ConfigureClockSource()
// {
// 	RCC_OscInitTypeDef RCC_oscInitInstance;

// 	RCC_oscInitInstance.OscillatorType = RCC_OSCILLATORTYPE_HSE;
// 	RCC_oscInitInstance.HSEState = RCC_HSE_ON;
// 	HAL_RCC_OscConfig(&RCC_oscInitInstance);
// }

void wait()
{
	for(int i = 0; i < 15000; i++);
}

/******************************************************************************\
 * 								MAIN APPLICATION
\******************************************************************************/
int main(void)
{
	SystemCoreClock = 8000000;
	HAL_Init();

	SetupHardware();

	// ConfigureClockSource();

	// SetupTerminal();

	// HAL_NVIC_EnableIRQ(USART2_IRQn);

	// char const *dataToSend = "Hello\r\n";
	// uartSendString(dataToSend);


	/** @brief Events are handled with interrupts */
	while(1)
	{
		Main.Hardware.Pins.LedCommOk.High();
		wait();
		Main.Hardware.Pins.LedCommOk.Low();
		wait();
	}
}

/******************************************************************************\
 * 								IRQ Handlers
\******************************************************************************/
// void USART2_IRQHandler(void)
// {
// 	Main.Hardware.Pins.LedCommOk.High();
// 	HAL_NVIC_ClearPendingIRQ(USART2_IRQn);
// }

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);

void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}

#ifdef __cplusplus
}
#endif
