#include <cstdint>

#define APB1_BASE_ADDRESS           ((uint32_t)0x40000000)
#define APB2_BASE_ADDRESS           ((uint32_t)0x40010000)
#define AHB_BASE_ADDRESS            ((uint32_t)0x40018000)


#define AHB_RCC_BASE_ADDRESS        ((uint32_t)(AHB_BASE_ADDRESS + 0x9000))
#define AHB_FLASH_BASE_ADDRESS      ((uint32_t)(AHB_BASE_ADDRESS + 0xA000))


#define APB2_AFIO_BASE_ADDRESS      ((uint32_t)(APB2_BASE_ADDRESS))
#define APB2_EXTI_BASE_ADDRESS      ((uint32_t)(APB2_BASE_ADDRESS + 0x400))
#define APB2_GPIOA_BASE_ADDRESS     ((uint32_t)(APB2_BASE_ADDRESS + 0x800))
#define APB2_GPIOB_BASE_ADDRESS     ((uint32_t)(APB2_BASE_ADDRESS + 0xC00))
#define APB2_GPIOC_BASE_ADDRESS     ((uint32_t)(APB2_BASE_ADDRESS + 0x1400))
#define APB2_USART1_BASE_ADDRESS    ((uint32_t)(APB2_BASE_ADDRESS + 0x3800))