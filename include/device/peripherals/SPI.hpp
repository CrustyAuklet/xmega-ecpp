/**
 * XMEGAAU-SPI (id I6090)
 * Serial Peripheral Interface
 *
 *
 */
#pragma once

#include "device/register.hpp"
#include <cstdint>

namespace device {

/**
 * SPI
 * Serial Peripheral Interface
 * Size: 4 bytes
 */
template <addressType BASE_ADDRESS>
struct SPI_t {

    /// Control Register - 1 bytes
    struct CTRL : public reg8_t<BASE_ADDRESS + 0x0000> {
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x80, 7> CLK2X;    //< Enable Double Speed using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x40, 6> ENABLE;    //< Enable Module using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x20, 5> DORD;    //< Data Order Setting using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x10, 4> MASTER;    //< Master Operation Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x0C, 2> MODE;    //< SPI Mode using SPI_MODE
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x03, 0> PRESCALER;    //< Prescaler using SPI_PRESCALER
    };

    /// Interrupt Control Register - 1 bytes
    struct INTCTRL : public reg8_t<BASE_ADDRESS + 0x0001> {
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x03, 0> INTLVL;    //< Interrupt level using SPI_INTLVL
    };

    /// Status Register - 1 bytes
    struct STATUS : public reg8_t<BASE_ADDRESS + 0x0002> {
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x80, 7> IF;    //< Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x40, 6> WRCOL;    //< Write Collision using None
    };

    /// Data Register - 1 bytes
    struct DATA : public reg8_t<BASE_ADDRESS + 0x0003> {
    };

    // SPI Mode
    class MODEv {
    public:
        enum MODE_ {
            _0 = 0x00, // SPI Mode 0
            _1 = 0x01, // SPI Mode 1
            _2 = 0x02, // SPI Mode 2
            _3 = 0x03, // SPI Mode 3
        };
        MODEv(const MODE_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Prescaler setting
    class PRESCALERv {
    public:
        enum PRESCALER_ {
            DIV4 = 0x00, // System Clock / 4
            DIV16 = 0x01, // System Clock / 16
            DIV64 = 0x02, // System Clock / 64
            DIV128 = 0x03, // System Clock / 128
        };
        PRESCALERv(const PRESCALER_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Interrupt level
    class INTLVLv {
    public:
        enum INTLVL_ {
            OFF = 0x00, // Interrupt Disabled
            LO = 0x01, // Low Level
            MED = 0x02, // Medium Level
            HI = 0x03, // High Level
        };
        INTLVLv(const INTLVL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // SPI ISR Vector Offsets (two bytes each)
    class INTERRUPTS {
    public:
        enum INTERRUPTS_ {
            INT = 0, // SPI Interrupt
        };
        INTERRUPTS(const INTERRUPTS_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

};

} // namespace device
