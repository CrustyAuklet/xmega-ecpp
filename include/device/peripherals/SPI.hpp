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
};

namespace SPI {

    // SPI Mode
    class MODE {
    private:
        enum MODE_ {
            _0_ = 0x00, // SPI Mode 0
            _1_ = 0x01, // SPI Mode 1
            _2_ = 0x02, // SPI Mode 2
            _3_ = 0x03, // SPI Mode 3
        };
        MODE_ value_;
    public:
        static const MODE _0, _1, _2, _3;
        explicit MODE(const MODE_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Prescaler setting
    class PRESCALER {
    private:
        enum PRESCALER_ {
            DIV4_ = 0x00, // System Clock / 4
            DIV16_ = 0x01, // System Clock / 16
            DIV64_ = 0x02, // System Clock / 64
            DIV128_ = 0x03, // System Clock / 128
        };
        PRESCALER_ value_;
    public:
        static const PRESCALER DIV4, DIV16, DIV64, DIV128;
        explicit PRESCALER(const PRESCALER_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Interrupt level
    class INTLVL {
    private:
        enum INTLVL_ {
            OFF_ = 0x00, // Interrupt Disabled
            LO_ = 0x01, // Low Level
            MED_ = 0x02, // Medium Level
            HI_ = 0x03, // High Level
        };
        INTLVL_ value_;
    public:
        static const INTLVL OFF, LO, MED, HI;
        explicit INTLVL(const INTLVL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };


    // SPI Interrupts
    class INTERRUPTS {
    private:
        enum SPI_VECTORS_ {
            INT_ = 0, // SPI Interrupt
        };
        SPI_VECTORS_ value_;
    public:
        static const SPI INT;
        explicit SPI(const SPI_VECTORS_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

} // namespace SPI
} // namespace device
