///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2007 - 2013.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef MCAL_REG_2010_04_10_H_
  #define MCAL_REG_2010_04_10_H_

  #include <cstdint>

  namespace mcal
  {
    namespace reg
    {
      // System registers.
      constexpr std::uint32_t scb_vtor  = static_cast<std::uint32_t>(0xE000ED08UL);   // 32-bit register.
      constexpr std::uint32_t aircr     = static_cast<std::uint32_t>(0xE000ED0CUL);   // 32-bit register. SCB application interrupt / reset control.

      // Interrupt registers.
      constexpr std::uint32_t rcc_cr    = static_cast<std::uint32_t>(0x40021000UL);   // 32-bit register.
      constexpr std::uint32_t rcc_cfgr  = static_cast<std::uint32_t>(0x40021004UL);   // 32-bit register.
      constexpr std::uint32_t rcc_cir   = static_cast<std::uint32_t>(0x40021008UL);   // 32-bit register.
      constexpr std::uint32_t rcc_cfgr2 = static_cast<std::uint32_t>(0x4002102CUL);   // 32-bit register.

      // Port registers.
      constexpr std::uint32_t gpioa_crl = static_cast<std::uint32_t>(0x40010800UL);   // 32-bit register.
      constexpr std::uint32_t gpioa_crh = static_cast<std::uint32_t>(0x40010804UL);   // 32-bit register.
      constexpr std::uint32_t gpioa_idr = static_cast<std::uint32_t>(0x40010808UL);   // 32-bit register.
      constexpr std::uint32_t gpioa_odr = static_cast<std::uint32_t>(0x4001080CUL);   // 32-bit register.

      constexpr std::uint32_t gpiob_crl = static_cast<std::uint32_t>(0x40010C00UL);   // 32-bit register.
      constexpr std::uint32_t gpiob_crh = static_cast<std::uint32_t>(0x40010C04UL);   // 32-bit register.
      constexpr std::uint32_t gpiob_idr = static_cast<std::uint32_t>(0x40010C08UL);   // 32-bit register.
      constexpr std::uint32_t gpiob_odr = static_cast<std::uint32_t>(0x40010C0CUL);   // 32-bit register.

      constexpr std::uint32_t gpioc_crl = static_cast<std::uint32_t>(0x40011000UL);   // 32-bit register.
      constexpr std::uint32_t gpioc_crh = static_cast<std::uint32_t>(0x40011004UL);   // 32-bit register.
      constexpr std::uint32_t gpioc_idr = static_cast<std::uint32_t>(0x40011008UL);   // 32-bit register.
      constexpr std::uint32_t gpioc_odr = static_cast<std::uint32_t>(0x4001100CUL);   // 32-bit register.

      // Timer registers.
      constexpr std::uint32_t tim4_cr1   = static_cast<std::uint32_t>(0x40000800UL);  // 16-bit register.
      constexpr std::uint32_t tim4_cr2   = static_cast<std::uint32_t>(0x40000804UL);  // 16-bit register.
      constexpr std::uint32_t tim4_smcr  = static_cast<std::uint32_t>(0x40000808UL);  // 16-bit register.
      constexpr std::uint32_t tim4_dier  = static_cast<std::uint32_t>(0x4000080CUL);  // 16-bit register.
      constexpr std::uint32_t tim4_sr    = static_cast<std::uint32_t>(0x40000810UL);  // 16-bit register.
      constexpr std::uint32_t tim4_egr   = static_cast<std::uint32_t>(0x40000814UL);  // 16-bit register.
      constexpr std::uint32_t tim4_ccmr1 = static_cast<std::uint32_t>(0x40000818UL);  // 16-bit register.
      constexpr std::uint32_t tim4_ccmr2 = static_cast<std::uint32_t>(0x4000081CUL);  // 16-bit register.
      constexpr std::uint32_t tim4_ccer  = static_cast<std::uint32_t>(0x40000820UL);  // 16-bit register.
      constexpr std::uint32_t tim4_cnt   = static_cast<std::uint32_t>(0x40000824UL);  // 16-bit register.
      constexpr std::uint32_t tim4_psc   = static_cast<std::uint32_t>(0x40000828UL);  // 16-bit register.
      constexpr std::uint32_t tim4_arr   = static_cast<std::uint32_t>(0x4000082CUL);  // 16-bit register.
      constexpr std::uint32_t tim4_rcr   = static_cast<std::uint32_t>(0x40000830UL);  // 16-bit register.

      // Power management registers.
      constexpr std::uint32_t rcc_apbenr  = static_cast<std::uint32_t>(0x40021014UL); // 32-bit register.
      constexpr std::uint32_t rcc_apb2enr = static_cast<std::uint32_t>(0x40021018UL); // 32-bit register.
      constexpr std::uint32_t rcc_apb1enr = static_cast<std::uint32_t>(0x4002101CUL); // 32-bit register.

      // Watchdog registers.
      constexpr std::uint32_t iwdg_kr     = static_cast<std::uint32_t>(0x40003000UL); // 32-bit register.
      constexpr std::uint32_t iwdg_pr     = static_cast<std::uint32_t>(0x40003004UL); // 32-bit register.
      constexpr std::uint32_t iwdg_rlr    = static_cast<std::uint32_t>(0x40003008UL); // 32-bit register.
      constexpr std::uint32_t iwdg_sr     = static_cast<std::uint32_t>(0x4000300CUL); // 32-bit register.

      // Interrupt control registers.
      constexpr std::uint32_t nvic_iser   = static_cast<std::uint32_t>(0xE000E100 + 0x0000); // 32-bit registers : Interrupt set enable registers.
      constexpr std::uint32_t nvic_icer   = static_cast<std::uint32_t>(0xE000E100 + 0x0080); // 32-bit registers : Interrupt clear enable registers.
      constexpr std::uint32_t nvic_ispr   = static_cast<std::uint32_t>(0xE000E100 + 0x0100); // 32-bit registers : Interrupt set pending registers.
      constexpr std::uint32_t nvic_icpr   = static_cast<std::uint32_t>(0xE000E100 + 0x0180); // 32-bit registers : Interrupt clear pending registers.
      constexpr std::uint32_t nvic_iabr   = static_cast<std::uint32_t>(0xE000E100 + 0x0200); // 32-bit registers : Interrupt active bit registers.
      constexpr std::uint32_t nvic_ip     = static_cast<std::uint32_t>(0xE000E100 + 0x0300); //  8-bit registers : Interrupt priority registers (each one 8 bits wide).

      // USART1 registers
      constexpr std::uint32_t usart1_sr     = static_cast<std::uint32_t>(0x40013800 + 0x0000); //16-bit register
      constexpr std::uint32_t usart1_dr     = static_cast<std::uint32_t>(0x40013800 + 0x0004); //16-bit register
      constexpr std::uint32_t usart1_brr    = static_cast<std::uint32_t>(0x40013800 + 0x0008); //16-bit register
      constexpr std::uint32_t usart1_cr1    = static_cast<std::uint32_t>(0x40013800 + 0x000C); //16-bit register
      constexpr std::uint32_t usart1_cr2    = static_cast<std::uint32_t>(0x40013800 + 0x0010); //16-bit register
      constexpr std::uint32_t usart1_cr3    = static_cast<std::uint32_t>(0x40013800 + 0x0014); //16-bit register
      constexpr std::uint32_t usart1_gtpr   = static_cast<std::uint32_t>(0x40013800 + 0x0018); //16-bit register

      // USART2 registers
      constexpr std::uint32_t usart2_sr     = static_cast<std::uint32_t>(0x40004400 + 0x0000); //16-bit register
      constexpr std::uint32_t usart2_dr     = static_cast<std::uint32_t>(0x40004400 + 0x0004); //16-bit register
      constexpr std::uint32_t usart2_brr    = static_cast<std::uint32_t>(0x40004400 + 0x0008); //16-bit register
      constexpr std::uint32_t usart2_cr1    = static_cast<std::uint32_t>(0x40004400 + 0x000C); //16-bit register
      constexpr std::uint32_t usart2_cr2    = static_cast<std::uint32_t>(0x40004400 + 0x0010); //16-bit register
      constexpr std::uint32_t usart2_cr3    = static_cast<std::uint32_t>(0x40004400 + 0x0014); //16-bit register
      constexpr std::uint32_t usart2_gtpr   = static_cast<std::uint32_t>(0x40004400 + 0x0018); //16-bit register
    }
  }

constexpr std::uint32_t sr_PE               = static_cast<std::uint32_t>(0x0); //Parity error
constexpr std::uint32_t sr_FE               = static_cast<std::uint32_t>(0x1); //Framing error
constexpr std::uint32_t sr_NE               = static_cast<std::uint32_t>(0x2); //Noise error flag
constexpr std::uint32_t sr_ORE              = static_cast<std::uint32_t>(0x3); //Overrun error
constexpr std::uint32_t sr_IDLE             = static_cast<std::uint32_t>(0x4); //IDLE line detected
constexpr std::uint32_t sr_RXNE             = static_cast<std::uint32_t>(0x5); //Read data register not empty
constexpr std::uint32_t sr_TC               = static_cast<std::uint32_t>(0x6); //Transmission complete
constexpr std::uint32_t sr_TXE              = static_cast<std::uint32_t>(0x7); //Transmit data register empty
constexpr std::uint32_t sr_LBD              = static_cast<std::uint32_t>(0x8); //LIN break detection flag
constexpr std::uint32_t sr_CTS              = static_cast<std::uint32_t>(0x9); //CTS flag

constexpr std::uint32_t dr_DR               = static_cast<std::uint32_t>(0x0); //data value

constexpr std::uint32_t brr_DIV_fraction    = static_cast<std::uint32_t>(0x0); //fraction of USARTDIV
constexpr std::uint32_t brr_DIV_mantissa    = static_cast<std::uint32_t>(0x4); //mantissa of USARTDIV

constexpr std::uint32_t cr1_SBK             = static_cast<std::uint32_t>(0x0); //Send break
constexpr std::uint32_t cr1_RWU             = static_cast<std::uint32_t>(0x1); //Receiver wakeup
constexpr std::uint32_t cr1_RE              = static_cast<std::uint32_t>(0x2); //Receiver enable
constexpr std::uint32_t cr1_TE              = static_cast<std::uint32_t>(0x3); //Transmitter enable
constexpr std::uint32_t cr1_IDLEIE          = static_cast<std::uint32_t>(0x4); //IDLE interrupt enable
constexpr std::uint32_t cr1_RXNEIE          = static_cast<std::uint32_t>(0x5); //RXNE interrupt enable
constexpr std::uint32_t cr1_TCIE            = static_cast<std::uint32_t>(0x6); //Transmission complete interrupt enable
constexpr std::uint32_t cr1_TXEIE           = static_cast<std::uint32_t>(0x7); //TXE interrupt enable
constexpr std::uint32_t cr1_PEIE            = static_cast<std::uint32_t>(0x8); //PE interrupt enable
constexpr std::uint32_t cr1_PS              = static_cast<std::uint32_t>(0x9); //Parity selection
constexpr std::uint32_t cr1_PCE             = static_cast<std::uint32_t>(0x10); //Parity control enable
constexpr std::uint32_t cr1_WAKE            = static_cast<std::uint32_t>(0x11); //Wakeup method
constexpr std::uint32_t cr1_M               = static_cast<std::uint32_t>(0x12); //Word length
constexpr std::uint32_t cr1_UE              = static_cast<std::uint32_t>(0x13); //USART Enable

constexpr std::uint32_t cr2_ADD             = static_cast<std::uint32_t>(0x0); //Address of the USART node
constexpr std::uint32_t cr2_res1            = static_cast<std::uint32_t>(0x4); //reserved
constexpr std::uint32_t cr2_LBDL            = static_cast<std::uint32_t>(0x5); //LIN break detection length
constexpr std::uint32_t cr2_LBDIE           = static_cast<std::uint32_t>(0x6); //LIN break detection interrupt enable
constexpr std::uint32_t cr2_res2            = static_cast<std::uint32_t>(0x7); //reserved
constexpr std::uint32_t cr2_LBCL            = static_cast<std::uint32_t>(0x8); //Last bit clock pulse
constexpr std::uint32_t cr2_CPHA            = static_cast<std::uint32_t>(0x9); //Clock phase
constexpr std::uint32_t cr2_CPOL            = static_cast<std::uint32_t>(0x10); //Clock polarity
constexpr std::uint32_t cr2_CLKEN           = static_cast<std::uint32_t>(0x11); //Clock enable
constexpr std::uint32_t cr2_STOP            = static_cast<std::uint32_t>(0x12); //STOP bits
constexpr std::uint32_t cr2_LINEN           = static_cast<std::uint32_t>(0x14); //LIN mode enable

constexpr std::uint32_t cr3_EIE             = static_cast<std::uint32_t>(0x0); //Error interrupt enable
constexpr std::uint32_t cr3_IREN            = static_cast<std::uint32_t>(0x1); //IrDA mode enable
constexpr std::uint32_t cr3_IRLP            = static_cast<std::uint32_t>(0x2); //IrDA low-power
constexpr std::uint32_t cr3_HDSEL           = static_cast<std::uint32_t>(0x3); //Half-duplex selection
constexpr std::uint32_t cr3_NACK            = static_cast<std::uint32_t>(0x4); //Smartcard NACK enable
constexpr std::uint32_t cr3_SCEN            = static_cast<std::uint32_t>(0x5); //Smartcard mode enable
constexpr std::uint32_t cr3_DMAR            = static_cast<std::uint32_t>(0x6); //DMA enable receiver
constexpr std::uint32_t cr3_DMAT            = static_cast<std::uint32_t>(0x7); //DMA enable transmitter
constexpr std::uint32_t cr3_RTSE            = static_cast<std::uint32_t>(0x8); //RTS enable
constexpr std::uint32_t cr3_CTSE            = static_cast<std::uint32_t>(0x9); //CTS enable
constexpr std::uint32_t cr3_CTSIE           = static_cast<std::uint32_t>(0x10); //CTS interrupt enable

constexpr std::uint32_t gtpr_PSC            = static_cast<std::uint32_t>(0x0); //Prescaler value
constexpr std::uint32_t gtpr_GT             = static_cast<std::uint32_t>(0x8); //Guard time value

  #include <mcal/mcal_reg_access_dynamic.h>
  #include <mcal/mcal_reg_access_static.h>


#endif // MCAL_REG_2010_04_10_H_
