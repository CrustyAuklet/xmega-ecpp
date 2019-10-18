#ifndef UT_HAL_DEVICE_FILE_XMEGA128A1U
#define UT_HAL_DEVICE_FILE_XMEGA128A1U

#include "peripherals/AC.hpp"
#include "peripherals/ADC.hpp"
#include "peripherals/AES.hpp"
#include "peripherals/AWEX.hpp"
#include "peripherals/CLK.hpp"
#include "peripherals/CPU.hpp"
#include "peripherals/CRC.hpp"
#include "peripherals/DAC.hpp"
#include "peripherals/DFLL.hpp"
#include "peripherals/DMA.hpp"
#include "peripherals/EBI.hpp"
#include "peripherals/EVSYS.hpp"
#include "peripherals/FUSE.hpp"
#include "peripherals/GPIO.hpp"
#include "peripherals/HIRES.hpp"
#include "peripherals/IRCOM.hpp"
#include "peripherals/LOCKBIT.hpp"
#include "peripherals/MCU.hpp"
#include "peripherals/NVM.hpp"
#include "peripherals/OSC.hpp"
#include "peripherals/PMIC.hpp"
#include "peripherals/PORT.hpp"
#include "peripherals/PORTCFG.hpp"
#include "peripherals/PR.hpp"
#include "peripherals/RST.hpp"
#include "peripherals/RTC.hpp"
#include "peripherals/SIGROW.hpp"
#include "peripherals/SLEEP.hpp"
#include "peripherals/SPI.hpp"
#include "peripherals/TC.hpp"
#include "peripherals/TC2.hpp"
#include "peripherals/TWI.hpp"
#include "peripherals/USART.hpp"
#include "peripherals/USB.hpp"
#include "peripherals/VPORT.hpp"
#include "peripherals/WDT.hpp"
#include "peripherals/XOCD.hpp"

/********** Peripheral Instances. Mapped to memory. **********/
typedef device::GPIO_t< 0x0000 > GPIO;    // General Purpose IO Registers
typedef device::VPORT_t< 0x0010 > VPORT0;    // Virtual Port 0
typedef device::VPORT_t< 0x0014 > VPORT1;    // Virtual Port 1
typedef device::VPORT_t< 0x0018 > VPORT2;    // Virtual Port 2
typedef device::VPORT_t< 0x001C > VPORT3;    // Virtual Port 3
typedef device::OCD_t< 0x002E > OCD;    // On-Chip Debug System
typedef device::CPU_t< 0x0030 > CPU;    // CPU registers
typedef device::CLK_t< 0x0040 > CLK;    // Clock System
typedef device::SLEEP_t< 0x0048 > SLEEP;    // Sleep Controller
typedef device::OSC_t< 0x0050 > OSC;    // Oscillator
typedef device::DFLL_t< 0x0060 > DFLLRC32M;    // DFLL RC32M
typedef device::DFLL_t< 0x0068 > DFLLRC2M;    // DFLL RC2M
typedef device::PR_t< 0x0070 > PR;    // Power Reduction
typedef device::RST_t< 0x0078 > RST;    // Reset
typedef device::WDT_t< 0x0080 > WDT;    // Watch-Dog Timer
typedef device::MCU_t< 0x0090 > MCU;    // MCU Control
typedef device::PMIC_t< 0x00A0 > PMIC;    // Programmable Multi-level Interrupt Controller
typedef device::PORTCFG_t< 0x00B0 > PORTCFG;    // I/O port Configuration
typedef device::AES_t< 0x00C0 > AES;    // AES Module
typedef device::CRC_t< 0x00D0 > CRC;    // Cyclic Redundancy Checker
typedef device::DMA_t< 0x0100 > DMA;    // DMA Controller
typedef device::EVSYS_t< 0x0180 > EVSYS;    // Event System
typedef device::NVM_t< 0x01C0 > NVM;    // Non-volatile Memory Controller
typedef device::ADC_t< 0x0200 > ADCA;    // Analog-to-Digital Converter A
typedef device::ADC_t< 0x0240 > ADCB;    // Analog-to-Digital Converter B
typedef device::DAC_t< 0x0300 > DACA;    // Digital-to-Analog Converter A
typedef device::DAC_t< 0x0320 > DACB;    // Digital-to-Analog Converter B
typedef device::AC_t< 0x0380 > ACA;    // Analog Comparator A
typedef device::AC_t< 0x0390 > ACB;    // Analog Comparator B
typedef device::RTC_t< 0x0400 > RTC;    // Real-Time Counter
typedef device::EBI_t< 0x0440 > EBI;    // External Bus Interface
typedef device::TWI_t< 0x0480 > TWIC;    // Two-Wire Interface C
typedef device::TWI_t< 0x0490 > TWID;    // Two-Wire Interface D
typedef device::TWI_t< 0x04A0 > TWIE;    // Two-Wire Interface E
typedef device::TWI_t< 0x04B0 > TWIF;    // Two-Wire Interface F
typedef device::USB_t< 0x04C0 > USB;    // Universal Serial Bus
typedef device::PORT_t< 0x0600 > PORTA;    // I/O Ports A
typedef device::PORT_t< 0x0620 > PORTB;    // I/O Ports B
typedef device::PORT_t< 0x0640 > PORTC;    // I/O Ports C
typedef device::PORT_t< 0x0660 > PORTD;    // I/O Ports D
typedef device::PORT_t< 0x0680 > PORTE;    // I/O Ports E
typedef device::PORT_t< 0x06A0 > PORTF;    // I/O Ports F
typedef device::PORT_t< 0x06E0 > PORTH;    // I/O Ports H
typedef device::PORT_t< 0x0700 > PORTJ;    // I/O Ports J
typedef device::PORT_t< 0x0720 > PORTK;    // I/O Ports K
typedef device::PORT_t< 0x07C0 > PORTQ;    // I/O Ports Q
typedef device::PORT_t< 0x07E0 > PORTR;    // I/O Ports R
typedef device::TC0_t< 0x0800 > TCC0;    // 16-bit Timer/Counter 0 C0
typedef device::TC2_t< 0x0800 > TCC2;    // 16-bit Timer/Counter type 2 C2
typedef device::TC1_t< 0x0840 > TCC1;    // 16-bit Timer/Counter 1 C1
typedef device::AWEX_t< 0x0880 > AWEXC;    // Advanced Waveform Extension C
typedef device::HIRES_t< 0x0890 > HIRESC;    // High-Resolution Extension C
typedef device::USART_t< 0x08A0 > USARTC0;    // Universal Synchronous/Asynchronous Receiver/Transmitter C0
typedef device::USART_t< 0x08B0 > USARTC1;    // Universal Synchronous/Asynchronous Receiver/Transmitter C1
typedef device::SPI_t< 0x08C0 > SPIC;    // Serial Peripheral Interface C
typedef device::IRCOM_t< 0x08F8 > IRCOM;    // IR Communication Module
typedef device::TC0_t< 0x0900 > TCD0;    // 16-bit Timer/Counter 0 D0
typedef device::TC2_t< 0x0900 > TCD2;    // 16-bit Timer/Counter type 2 D2
typedef device::TC1_t< 0x0940 > TCD1;    // 16-bit Timer/Counter 1 D1
typedef device::HIRES_t< 0x0990 > HIRESD;    // High-Resolution Extension D
typedef device::USART_t< 0x09A0 > USARTD0;    // Universal Synchronous/Asynchronous Receiver/Transmitter D0
typedef device::USART_t< 0x09B0 > USARTD1;    // Universal Synchronous/Asynchronous Receiver/Transmitter D1
typedef device::SPI_t< 0x09C0 > SPID;    // Serial Peripheral Interface D
typedef device::TC0_t< 0x0A00 > TCE0;    // 16-bit Timer/Counter 0 E0
typedef device::TC2_t< 0x0A00 > TCE2;    // 16-bit Timer/Counter type 2 E2
typedef device::TC1_t< 0x0A40 > TCE1;    // 16-bit Timer/Counter 1 E1
typedef device::AWEX_t< 0x0A80 > AWEXE;    // Advanced Waveform Extension E
typedef device::HIRES_t< 0x0A90 > HIRESE;    // High-Resolution Extension E
typedef device::USART_t< 0x0AA0 > USARTE0;    // Universal Synchronous/Asynchronous Receiver/Transmitter E0
typedef device::USART_t< 0x0AB0 > USARTE1;    // Universal Synchronous/Asynchronous Receiver/Transmitter E1
typedef device::SPI_t< 0x0AC0 > SPIE;    // Serial Peripheral Interface E
typedef device::TC0_t< 0x0B00 > TCF0;    // 16-bit Timer/Counter 0 F0
typedef device::TC2_t< 0x0B00 > TCF2;    // 16-bit Timer/Counter type 2 F2
typedef device::TC1_t< 0x0B40 > TCF1;    // 16-bit Timer/Counter 1 F1
typedef device::HIRES_t< 0x0B90 > HIRESF;    // High-Resolution Extension F
typedef device::USART_t< 0x0BA0 > USARTF0;    // Universal Synchronous/Asynchronous Receiver/Transmitter F0
typedef device::USART_t< 0x0BB0 > USARTF1;    // Universal Synchronous/Asynchronous Receiver/Transmitter F1
typedef device::SPI_t< 0x0BC0 > SPIF;    // Serial Peripheral Interface F

#endif  // UT_HAL_DEVICE_FILE_XMEGA128A1U
