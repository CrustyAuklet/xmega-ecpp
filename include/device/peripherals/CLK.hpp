/**
 * XMEGAAU-CLK (id I6073)
 * Clock System
 *
 *
 */
#pragma once

#include "device/register.hpp"
#include <cstdint>

namespace device {

/**
 * CLK
 * Clock System
 * Size: 5 bytes
 */
template <addressType BASE_ADDRESS>
struct CLK_t {

    /// Control Register - 1 bytes
    struct CTRL : public reg8_t<BASE_ADDRESS + 0x0000> {
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x07, 0> SCLKSEL;    //< System Clock Selection using CLK_SCLKSEL
    };

    /// Prescaler Control Register - 1 bytes
    struct PSCTRL : public reg8_t<BASE_ADDRESS + 0x0001> {
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x7C, 2> PSADIV;    //< Prescaler A Division Factor using CLK_PSADIV
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x03, 0> PSBCDIV;    //< Prescaler B and C Division factor using CLK_PSBCDIV
    };

    /// Lock register - 1 bytes
    struct LOCK : public reg8_t<BASE_ADDRESS + 0x0002> {
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x01, 0> LOCK;    //< Clock System Lock using None
    };

    /// RTC Control Register - 1 bytes
    struct RTCCTRL : public reg8_t<BASE_ADDRESS + 0x0003> {
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x0E, 1> RTCSRC;    //< Clock Source using CLK_RTCSRC
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x01, 0> RTCEN;    //< Clock Source Enable using None
    };

    /// USB Control Register - 1 bytes
    struct USBCTRL : public reg8_t<BASE_ADDRESS + 0x0004> {
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x38, 3> USBPSDIV;    //< Prescaler Division Factor using CLK_USBPSDIV
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x06, 1> USBSRC;    //< Clock Source using CLK_USBSRC
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x01, 0> USBSEN;    //< Clock Source Enable using None
    };
};

namespace CLK {

    // System Clock Selection
    class SCLKSEL {
    private:
        enum SCLKSEL_ {
            RC2M_ = 0x00, // Internal 2 MHz RC Oscillator
            RC32M_ = 0x01, // Internal 32 MHz RC Oscillator
            RC32K_ = 0x02, // Internal 32.768 kHz RC Oscillator
            XOSC_ = 0x03, // External Crystal Oscillator or Clock
            PLL_ = 0x04, // Phase Locked Loop
        };
        SCLKSEL_ value_;
    public:
        static const SCLKSEL RC2M, RC32M, RC32K, XOSC, PLL;
        explicit SCLKSEL(const SCLKSEL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Prescaler A Division Factor
    class PSADIV {
    private:
        enum PSADIV_ {
            _1_ = 0x00, // Divide by 1
            _2_ = 0x01, // Divide by 2
            _4_ = 0x03, // Divide by 4
            _8_ = 0x05, // Divide by 8
            _16_ = 0x07, // Divide by 16
            _32_ = 0x09, // Divide by 32
            _64_ = 0x0B, // Divide by 64
            _128_ = 0x0D, // Divide by 128
            _256_ = 0x0F, // Divide by 256
            _512_ = 0x11, // Divide by 512
        };
        PSADIV_ value_;
    public:
        static const PSADIV _1, _2, _4, _8, _16, _32, _64, _128, _256, _512;
        explicit PSADIV(const PSADIV_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Prescaler B and C Division Factor
    class PSBCDIV {
    private:
        enum PSBCDIV_ {
            _1_1_ = 0x00, // Divide B by 1 and C by 1
            _1_2_ = 0x01, // Divide B by 1 and C by 2
            _4_1_ = 0x02, // Divide B by 4 and C by 1
            _2_2_ = 0x03, // Divide B by 2 and C by 2
        };
        PSBCDIV_ value_;
    public:
        static const PSBCDIV _1_1, _1_2, _4_1, _2_2;
        explicit PSBCDIV(const PSBCDIV_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // RTC Clock Source
    class RTCSRC {
    private:
        enum RTCSRC_ {
            ULP_ = 0x00, // 1.024 kHz from internal 32kHz ULP
            TOSC_ = 0x01, // 1.024 kHz from 32.768 kHz crystal oscillator on TOSC
            RCOSC_ = 0x02, // 1.024 kHz from internal 32.768 kHz RC oscillator
            TOSC32_ = 0x05, // 32.768 kHz from 32.768 kHz crystal oscillator on TOSC
            RCOSC32_ = 0x06, // 32.768 kHz from internal 32.768 kHz RC oscillator
            EXTCLK_ = 0x07, // External Clock from TOSC1
        };
        RTCSRC_ value_;
    public:
        static const RTCSRC ULP, TOSC, RCOSC, TOSC32, RCOSC32, EXTCLK;
        explicit RTCSRC(const RTCSRC_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // USB Prescaler Division Factor
    class USBPSDIV {
    private:
        enum USBPSDIV_ {
            _1_ = 0x00, // Divide by 1
            _2_ = 0x01, // Divide by 2
            _4_ = 0x02, // Divide by 4
            _8_ = 0x03, // Divide by 8
            _16_ = 0x04, // Divide by 16
            _32_ = 0x05, // Divide by 32
        };
        USBPSDIV_ value_;
    public:
        static const USBPSDIV _1, _2, _4, _8, _16, _32;
        explicit USBPSDIV(const USBPSDIV_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // USB Clock Source
    class USBSRC {
    private:
        enum USBSRC_ {
            PLL_ = 0x00, // PLL
            RC32M_ = 0x01, // Internal 32 MHz RC Oscillator
        };
        USBSRC_ value_;
    public:
        static const USBSRC PLL, RC32M;
        explicit USBSRC(const USBSRC_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };


} // namespace CLK
} // namespace device
