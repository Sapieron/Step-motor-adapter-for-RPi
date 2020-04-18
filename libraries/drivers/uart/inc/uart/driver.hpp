/**
 * @file driver.hpp
 * @author Pawel Klisz (pawelochojec@gmail.com)
 * @brief  UART driver
 * @version 0.1
 * @date 2020-03-17
 * 
 * @copyright Copyright (c) 2020 by Pawel Klisz. All rights reserved
 * 
 * Released under the terms of the GNU General Public License version 3 or later.
 * For full license please refer to LICENSE.txt
 * 
 * This project can be found on https://github.com/Sapieron/Step-motor-adapter-for-RPi
 * 
 */

#ifndef UART_DRIVER_HPP
#define UART_DRIVER_HPP

#pragma once

/******************************************************************************\
 * 								Includes
\******************************************************************************/
#include "stm32f1xx_hal_dma.h"
#include "stm32f1xx_hal_uart.h"


/******************************************************************************\
 * 							      CODE
\******************************************************************************/
namespace drivers
{
    namespace uart
    {
        /**
         * @defgroup uart_driver UART Driver
         * @ingroup peripheral_driver
         */

        /**
         * @brief UART driver
         * @ingroup uart_driver
         */
        template<typename UartPort>
        class UART final
        {
        public:
            /** @brief Default Ctor */
            UART();

            /** @brief Initializes peripheral */
            void Initialize();

            /** @brief Call from  */
            void OnReceived();

            void Read();

            void Write();

            // void OnDma();    //FIXME add DMA functionality
        private:
            UART_HandleTypeDef  huart;

            DMA_HandleTypeDef   hdma_huart_rx;
            DMA_HandleTypeDef   hdma_huart_tx;

            uint8_t buffer[5];
        };

        template<typename UartPort> UART<UartPort>::UART(){}

        template<typename UartPort>
        void UART<UartPort>::Initialize()
        {
            huart.Instance = reinterpret_cast<USART_TypeDef *>(UartPort::Peripheral);
            huart.Init.BaudRate        = UartPort::Baudrate;
            huart.Init.WordLength      = UartPort::WordLength;
            huart.Init.StopBits        = UartPort::StopBits;
            huart.Init.Parity          = UartPort::ParityBits;
            huart.Init.Mode            = UartPort::Mode;
            huart.Init.HwFlowCtl       = UartPort::HwFlowCtl;
            huart.Init.OverSampling    = UartPort::OverSampling;

            hdma_huart_rx.Instance = reinterpret_cast<DMA_Channel_TypeDef *>(UartPort::DmaRxChannel);
            hdma_huart_rx.Init.Direction            = DMA_PERIPH_TO_MEMORY;
            hdma_huart_rx.Init.MemDataAlignment     = DMA_MDATAALIGN_BYTE;
            hdma_huart_rx.Init.MemInc               = DMA_MINC_ENABLE;
            hdma_huart_rx.Init.Mode                 = DMA_NORMAL;
            hdma_huart_rx.Init.PeriphDataAlignment  = DMA_PDATAALIGN_BYTE;
            hdma_huart_rx.Init.PeriphInc            = DMA_PINC_DISABLE;
            hdma_huart_rx.Init.Priority             = DMA_PRIORITY_LOW;

            hdma_huart_tx.Instance = reinterpret_cast<DMA_Channel_TypeDef *>(UartPort::DmaTxChannel);
            hdma_huart_tx.Init.Direction            = DMA_MEMORY_TO_PERIPH;
            hdma_huart_tx.Init.MemDataAlignment     = DMA_MDATAALIGN_BYTE;
            hdma_huart_tx.Init.MemInc               = DMA_MINC_ENABLE;
            hdma_huart_tx.Init.Mode                 = DMA_NORMAL;
            hdma_huart_tx.Init.PeriphDataAlignment  = DMA_PDATAALIGN_BYTE;
            hdma_huart_tx.Init.PeriphInc            = DMA_PINC_DISABLE;
            hdma_huart_tx.Init.Priority             = DMA_PRIORITY_LOW;

            HAL_DMA_Init(&hdma_huart_tx);
            HAL_DMA_Init(&hdma_huart_rx);

            __HAL_LINKDMA(&huart, hdmatx, hdma_huart_tx);
            __HAL_LINKDMA(&huart, hdmarx, hdma_huart_rx);

            HAL_NVIC_SetPriority(UartPort::DmaRxIRQn, 0, 0);
            HAL_NVIC_EnableIRQ(UartPort::DmaRxIRQn);

            HAL_NVIC_SetPriority(UartPort::DmaTxIRQn, 0, 0);
            HAL_NVIC_EnableIRQ(UartPort::DmaTxIRQn);

            HAL_UART_Init(&huart);

            HAL_NVIC_EnableIRQ(UartPort::Interrupt);
            HAL_UART_Receive_DMA(&huart, buffer, 5);
        }

        template<typename UartPort>
        __attribute__((optimize("03"))) void UART<UartPort>::OnReceived()
        {
            HAL_UART_IRQHandler(&huart);
            // HAL_NVIC_ClearPendingIRQ(UartPort::Interrupt);
        }
    } // namespace uart
} // namespace drivers


#endif /* UART_DRIVER_HPP */