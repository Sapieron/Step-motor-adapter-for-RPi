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
 *                            Includes
\******************************************************************************/
#include "TargetsDefines.hpp"

#include "line_io.hpp"

#include <cstdint>
#include <cstring>

/******************************************************************************\
 *                             CODE
\******************************************************************************/
namespace drivers
{
    namespace uart
    {
        /**
         * @defgroup uart_driver UART Driver
         * @ingroup peripheral_drivers
         * 
         * @{
         */

        /**
         * @brief Class describing UART driver
         * 
         * @tparam UartPort 
         */
        template<typename UartPort>
        class UART final : public ILineIO
        {
        public:
            /** @brief Default Ctor */
            UART();

            /** @brief Initializes peripheral */
            void Initialize();

            /** @brief Call from  */
            void OnReception();

            /** @brief Outputs given string to connected UART peripheral */
            virtual void Puts(const char* text) override;

            /** @brief Returns data stored in rx buffer */
            virtual const char *GetRxBuffer() override;

            /** @brief DMA reception handler */
            void OnDmaReceive();

            /** @brief DMA transmission handler */
            void OnDmaTransmit();

            /** @brief  */
            void CallbackHandler();

        private:
            /** @brief Private handler */
            UART_HandleTypeDef  _huart;

            /** @brief Private DMA handler for uart rx */
            DMA_HandleTypeDef   _hdma_huart_rx;

            /** @brief Private DMA handler for uart Tx */
            DMA_HandleTypeDef   _hdma_huart_tx;

            /** @brief Initializes DMA */
            void InitializeDma();

            /** @brief Enables uart clock */
            void ClockUartEnable() const;

            /** @brief Buffer */
            std::uint8_t _rxBuffer[21];
        };

        /** @} */

        template<typename UartPort> UART<UartPort>::UART(){}

        template<typename UartPort>
        void UART<UartPort>::Initialize()
        {
            this->InitializeDma();
            this->ClockUartEnable();

            _huart.Instance = reinterpret_cast<USART_TypeDef *>(UartPort::Peripheral);
            _huart.Init.BaudRate        = UartPort::Baudrate;
            _huart.Init.WordLength      = UartPort::WordLength;
            _huart.Init.StopBits        = UartPort::StopBits;
            _huart.Init.Parity          = UartPort::ParityBits;
            _huart.Init.Mode            = UartPort::Mode;
            _huart.Init.HwFlowCtl       = UartPort::HwFlowCtl;
            _huart.Init.OverSampling    = UartPort::OverSampling;

            HAL_UART_Init(&_huart);

            HAL_NVIC_SetPriority(UartPort::Interrupt, 0, 0);
            HAL_NVIC_EnableIRQ(UartPort::Interrupt);

            HAL_UART_Receive_DMA(&_huart, _rxBuffer, sizeof(_rxBuffer));
        }

        template<typename UartPort>
        void UART<UartPort>::InitializeDma()
        {
            __HAL_RCC_DMA1_CLK_ENABLE();
            _hdma_huart_rx.Instance = reinterpret_cast<DMA_Channel_TypeDef *>(UartPort::DmaRxChannel);
            _hdma_huart_rx.Init.Direction            = DMA_PERIPH_TO_MEMORY;
            _hdma_huart_rx.Init.MemDataAlignment     = DMA_MDATAALIGN_BYTE;
            _hdma_huart_rx.Init.MemInc               = DMA_MINC_ENABLE;
            _hdma_huart_rx.Init.Mode                 = DMA_NORMAL;
            _hdma_huart_rx.Init.PeriphDataAlignment  = DMA_PDATAALIGN_BYTE;
            _hdma_huart_rx.Init.PeriphInc            = DMA_PINC_DISABLE;
            _hdma_huart_rx.Init.Priority             = DMA_PRIORITY_LOW;

            _hdma_huart_tx.Instance = reinterpret_cast<DMA_Channel_TypeDef *>(UartPort::DmaTxChannel);
            _hdma_huart_tx.Init.Direction            = DMA_MEMORY_TO_PERIPH;
            _hdma_huart_tx.Init.MemDataAlignment     = DMA_MDATAALIGN_BYTE;
            _hdma_huart_tx.Init.MemInc               = DMA_MINC_ENABLE;
            _hdma_huart_tx.Init.Mode                 = DMA_NORMAL;
            _hdma_huart_tx.Init.PeriphDataAlignment  = DMA_PDATAALIGN_BYTE;
            _hdma_huart_tx.Init.PeriphInc            = DMA_PINC_DISABLE;
            _hdma_huart_tx.Init.Priority             = DMA_PRIORITY_LOW;

            HAL_DMA_Init(&_hdma_huart_tx);
            HAL_DMA_Init(&_hdma_huart_rx);

            __HAL_LINKDMA(&_huart, hdmatx, _hdma_huart_tx);
            __HAL_LINKDMA(&_huart, hdmarx, _hdma_huart_rx);

            HAL_NVIC_SetPriority(UartPort::DmaRxIRQn, 0, 0);
            HAL_NVIC_SetPriority(UartPort::DmaTxIRQn, 0, 0);

            HAL_NVIC_EnableIRQ(UartPort::DmaRxIRQn);
            HAL_NVIC_EnableIRQ(UartPort::DmaTxIRQn);
        }


        template<typename UartPort>
        __attribute__((optimize("O3"))) void UART<UartPort>::OnReception()
        {
            HAL_UART_IRQHandler(&_huart);
        }

        template<typename UartPort>
        __attribute__((optimize("O3"))) void UART<UartPort>::OnDmaReceive()
        {
            HAL_DMA_IRQHandler(&_hdma_huart_rx);
        }

        template<typename UartPort>
        __attribute__((optimize("O3"))) void UART<UartPort>::OnDmaTransmit()
        {
            HAL_DMA_IRQHandler(&_hdma_huart_tx);
        }

        template<typename UartPort>
        void UART<UartPort>::CallbackHandler()
        {
            HAL_UART_Receive_DMA(&_huart, _rxBuffer, sizeof(_rxBuffer));
        }

        template<typename UartPort>
        void UART<UartPort>::Puts(const char* text)
        {
            HAL_UART_Transmit_DMA(&_huart, (uint8_t *)text, strlen(text));
        }

        template<typename UartPort>
        const char* UART<UartPort>::GetRxBuffer()
        {
            return reinterpret_cast<const char*>(&this->_rxBuffer);
        }

        template <typename UartPort>
        void UART<UartPort>::ClockUartEnable() const
        {
            constexpr auto selectedClock = UartPort::Peripheral;

            switch(selectedClock)
            {
                #ifdef USART1_BASE
                case USART1_BASE:
                    __HAL_RCC_USART1_CLK_ENABLE();
                    break;
                    #endif /*USART1_BASE */

                #ifdef USART2_BASE
                case USART2_BASE:
                    __HAL_RCC_USART2_CLK_ENABLE();
                    break;
                #endif /*USART2_BASE */

                #ifdef USART3_BASE
                case USART3_BASE:
                    __HAL_RCC_USART3_CLK_ENABLE();
                    break;
                #endif /*USART3_BASE */
            }
        }
    } // namespace uart
} // namespace drivers

/******************************************************************************\
 *                          End of file
\******************************************************************************/
#endif /* UART_DRIVER_HPP */
