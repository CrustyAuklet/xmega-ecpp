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

    // System Clock Selection
    class SCLKSELv {
    public:
        enum SCLKSEL_ {
            RC2M = 0x00, // Internal 2 MHz RC Oscillator
            RC32M = 0x01, // Internal 32 MHz RC Oscillator
            RC32K = 0x02, // Internal 32.768 kHz RC Oscillator
            XOSC = 0x03, // External Crystal Oscillator or Clock
            PLL = 0x04, // Phase Locked Loop
        };
        SCLKSELv(const SCLKSEL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Prescaler A Division Factor
    class PSADIVv {
    public:
        enum PSADIV_ {
            _1 = 0x00, // Divide by 1
            _2 = 0x01, // Divide by 2
            _4 = 0x03, // Divide by 4
            _8 = 0x05, // Divide by 8
            _16 = 0x07, // Divide by 16
            _32 = 0x09, // Divide by 32
            _64 = 0x0B, // Divide by 64
            _128 = 0x0D, // Divide by 128
            _256 = 0x0F, // Divide by 256
            _512 = 0x11, // Divide by 512
        };
        PSADIVv(const PSADIV_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Prescaler B and C Division Factor
    class PSBCDIVv {
    public:
        enum PSBCDIV_ {
            _1_1 = 0x00, // Divide B by 1 and C by 1
            _1_2 = 0x01, // Divide B by 1 and C by 2
            _4_1 = 0x02, // Divide B by 4 and C by 1
            _2_2 = 0x03, // Divide B by 2 and C by 2
        };
        PSBCDIVv(const PSBCDIV_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // RTC Clock Source
    class RTCSRCv {
    public:
        enum RTCSRC_ {
            ULP = 0x00, // 1.024 kHz from internal 32kHz ULP
            TOSC = 0x01, // 1.024 kHz from 32.768 kHz crystal oscillator on TOSC
            RCOSC = 0x02, // 1.024 kHz from internal 32.768 kHz RC oscillator
            TOSC32 = 0x05, // 32.768 kHz from 32.768 kHz crystal oscillator on TOSC
            RCOSC32 = 0x06, // 32.768 kHz from internal 32.768 kHz RC oscillator
            EXTCLK = 0x07, // External Clock from TOSC1
        };
        RTCSRCv(const RTCSRC_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // USB Prescaler Division Factor
    class USBPSDIVv {
    public:
        enum USBPSDIV_ {
            _1 = 0x00, // Divide by 1
            _2 = 0x01, // Divide by 2
            _4 = 0x02, // Divide by 4
            _8 = 0x03, // Divide by 8
            _16 = 0x04, // Divide by 16
            _32 = 0x05, // Divide by 32
        };
        USBPSDIVv(const USBPSDIV_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // USB Clock Source
    class USBSRCv {
    public:
        enum USBSRC_ {
            PLL = 0x00, // PLL
            RC32M = 0x01, // Internal 32 MHz RC Oscillator
        };
        USBSRCv(const USBSRC_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

};

} // namespace device
