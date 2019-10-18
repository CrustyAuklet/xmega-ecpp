/**
 * XMEGAAU-PR (id I6073)
 * Power Reduction
 *
 *
 */
#pragma once

#include "device/register.hpp"
#include <cstdint>

namespace device {

/**
 * PR
 * Power Reduction
 * Size: 7 bytes
 */
template <addressType BASE_ADDRESS>
struct PR_t {

    /// General Power Reduction - 1 bytes
    struct PRGEN : public reg8_t<BASE_ADDRESS + 0x0000> {
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x40, 6> USB;    //< USB using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x10, 4> AES;    //< AES using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x08, 3> EBI;    //< External Bus Interface using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x04, 2> RTC;    //< Real-time Counter using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x02, 1> EVSYS;    //< Event System using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x01, 0> DMA;    //< DMA-Controller using None
    };

    /// Power Reduction Port A - 1 bytes
    struct PRPA : public reg8_t<BASE_ADDRESS + 0x0001> {
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x04, 2> DAC;    //< Port A DAC using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x02, 1> ADC;    //< Port A ADC using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x01, 0> AC;    //< Port A Analog Comparator using None
    };

    /// Power Reduction Port B - 1 bytes
    struct PRPB : public reg8_t<BASE_ADDRESS + 0x0002> {
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x04, 2> DAC;    //< Port B DAC using None
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x02, 1> ADC;    //< Port B ADC using None
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x01, 0> AC;    //< Port B Analog Comparator using None
    };

    /// Power Reduction Port C - 1 bytes
    struct PRPC : public reg8_t<BASE_ADDRESS + 0x0003> {
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x40, 6> TWI;    //< Port C Two-wire Interface using None
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x20, 5> USART1;    //< Port C USART1 using None
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x10, 4> USART0;    //< Port C USART0 using None
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x08, 3> SPI;    //< Port C SPI using None
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x04, 2> HIRES;    //< Port C AWEX using None
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x02, 1> TC1;    //< Port C Timer/Counter1 using None
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x01, 0> TC0;    //< Port C Timer/Counter0 using None
    };

    /// Power Reduction Port D - 1 bytes
    struct PRPD : public reg8_t<BASE_ADDRESS + 0x0004> {
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x40, 6> TWI;    //< Port D Two-wire Interface using None
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x20, 5> USART1;    //< Port D USART1 using None
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x10, 4> USART0;    //< Port D USART0 using None
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x08, 3> SPI;    //< Port D SPI using None
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x04, 2> HIRES;    //< Port D AWEX using None
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x02, 1> TC1;    //< Port D Timer/Counter1 using None
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x01, 0> TC0;    //< Port D Timer/Counter0 using None
    };

    /// Power Reduction Port E - 1 bytes
    struct PRPE : public reg8_t<BASE_ADDRESS + 0x0005> {
        typedef reg_field_t<BASE_ADDRESS + 0x0005, 0x40, 6> TWI;    //< Port E Two-wire Interface using None
        typedef reg_field_t<BASE_ADDRESS + 0x0005, 0x20, 5> USART1;    //< Port E USART1 using None
        typedef reg_field_t<BASE_ADDRESS + 0x0005, 0x10, 4> USART0;    //< Port E USART0 using None
        typedef reg_field_t<BASE_ADDRESS + 0x0005, 0x08, 3> SPI;    //< Port E SPI using None
        typedef reg_field_t<BASE_ADDRESS + 0x0005, 0x04, 2> HIRES;    //< Port E AWEX using None
        typedef reg_field_t<BASE_ADDRESS + 0x0005, 0x02, 1> TC1;    //< Port E Timer/Counter1 using None
        typedef reg_field_t<BASE_ADDRESS + 0x0005, 0x01, 0> TC0;    //< Port E Timer/Counter0 using None
    };

    /// Power Reduction Port F - 1 bytes
    struct PRPF : public reg8_t<BASE_ADDRESS + 0x0006> {
        typedef reg_field_t<BASE_ADDRESS + 0x0006, 0x40, 6> TWI;    //< Port F Two-wire Interface using None
        typedef reg_field_t<BASE_ADDRESS + 0x0006, 0x20, 5> USART1;    //< Port F USART1 using None
        typedef reg_field_t<BASE_ADDRESS + 0x0006, 0x10, 4> USART0;    //< Port F USART0 using None
        typedef reg_field_t<BASE_ADDRESS + 0x0006, 0x08, 3> SPI;    //< Port F SPI using None
        typedef reg_field_t<BASE_ADDRESS + 0x0006, 0x04, 2> HIRES;    //< Port F AWEX using None
        typedef reg_field_t<BASE_ADDRESS + 0x0006, 0x02, 1> TC1;    //< Port F Timer/Counter1 using None
        typedef reg_field_t<BASE_ADDRESS + 0x0006, 0x01, 0> TC0;    //< Port F Timer/Counter0 using None
    };

};

} // namespace device
