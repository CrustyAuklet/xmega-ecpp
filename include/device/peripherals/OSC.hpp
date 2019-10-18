/**
 * XMEGAAU-OSC (id I6079)
 * Oscillator
 *
 *
 */
#pragma once

#include "device/register.hpp"
#include <cstdint>

namespace device {

/**
 * OSC
 * Oscillator
 * Size: 7 bytes
 */
template <addressType BASE_ADDRESS>
struct OSC_t {

    /// Control Register - 1 bytes
    struct CTRL : public reg8_t<BASE_ADDRESS + 0x0000> {
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x10, 4> PLLEN;    //< PLL Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x08, 3> XOSCEN;    //< External Oscillator Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x04, 2> RC32KEN;    //< Internal 32.768 kHz RC Oscillator Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x02, 1> RC32MEN;    //< Internal 32 MHz RC Oscillator Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x01, 0> RC2MEN;    //< Internal 2 MHz RC Oscillator Enable using None
    };

    /// Status Register - 1 bytes
    struct STATUS : public reg8_t<BASE_ADDRESS + 0x0001> {
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x10, 4> PLLRDY;    //< PLL Ready using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x08, 3> XOSCRDY;    //< External Oscillator Ready using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x04, 2> RC32KRDY;    //< Internal 32.768 kHz RC Oscillator Ready using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x02, 1> RC32MRDY;    //< Internal 32 MHz RC Oscillator Ready using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x01, 0> RC2MRDY;    //< Internal 2 MHz RC Oscillator Ready using None
    };

    /// External Oscillator Control Register - 1 bytes
    struct XOSCCTRL : public reg8_t<BASE_ADDRESS + 0x0002> {
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0xC0, 6> FRQRANGE;    //< Frequency Range using OSC_FRQRANGE
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x20, 5> X32KLPM;    //< 32.768 kHz XTAL OSC Low-power Mode using None
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x10, 4> XOSCPWR;    //< 16 MHz Crystal Oscillator High Power mode using None
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x0F, 0> XOSCSEL;    //< External Oscillator Selection and Startup Time using OSC_XOSCSEL
    };

    /// Oscillator Failure Detection Register - 1 bytes
    struct XOSCFAIL : public reg8_t<BASE_ADDRESS + 0x0003> {
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x08, 3> PLLFDIF;    //< PLL Failure Detection Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x04, 2> PLLFDEN;    //< PLL Failure Detection Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x02, 1> XOSCFDIF;    //< XOSC Failure Detection Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x01, 0> XOSCFDEN;    //< XOSC Failure Detection Enable using None
    };

    /// 32.768 kHz Internal Oscillator Calibration Register - 1 bytes
    struct RC32KCAL : public reg8_t<BASE_ADDRESS + 0x0004> {
    };

    /// PLL Control Register - 1 bytes
    struct PLLCTRL : public reg8_t<BASE_ADDRESS + 0x0005> {
        typedef reg_field_t<BASE_ADDRESS + 0x0005, 0xC0, 6> PLLSRC;    //< Clock Source using OSC_PLLSRC
        typedef reg_field_t<BASE_ADDRESS + 0x0005, 0x20, 5> PLLDIV;    //< Divide by 2 using None
        typedef reg_field_t<BASE_ADDRESS + 0x0005, 0x1F, 0> PLLFAC;    //< Multiplication Factor using None
    };

    /// DFLL Control Register - 1 bytes
    struct DFLLCTRL : public reg8_t<BASE_ADDRESS + 0x0006> {
        typedef reg_field_t<BASE_ADDRESS + 0x0006, 0x06, 1> RC32MCREF;    //< 32 MHz DFLL Calibration Reference using OSC_RC32MCREF
        typedef reg_field_t<BASE_ADDRESS + 0x0006, 0x01, 0> RC2MCREF;    //< 2 MHz DFLL Calibration Reference using OSC_RC2MCREF
    };
};

namespace OSC {

    // Oscillator Frequency Range
    class FRQRANGE {
    private:
        enum FRQRANGE_ {
            _04TO2_ = 0x00, // 0.4 - 2 MHz
            _2TO9_ = 0x01, // 2 - 9 MHz
            _9TO12_ = 0x02, // 9 - 12 MHz
            _12TO16_ = 0x03, // 12 - 16 MHz
        };
        FRQRANGE_ value_;
    public:
        static const FRQRANGE _04TO2, _2TO9, _9TO12, _12TO16;
        explicit FRQRANGE(const FRQRANGE_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // External Oscillator Selection and Startup Time
    class XOSCSEL {
    private:
        enum XOSCSEL_ {
            EXTCLK_ = 0x00, // External Clock - 6 CLK
            _32KHz_ = 0x02, // 32.768 kHz TOSC - 32K CLK
            XTAL_256CLK_ = 0x03, // 0.4-16 MHz XTAL - 256 CLK
            XTAL_1KCLK_ = 0x07, // 0.4-16 MHz XTAL - 1K CLK
            XTAL_16KCLK_ = 0x0B, // 0.4-16 MHz XTAL - 16K CLK
        };
        XOSCSEL_ value_;
    public:
        static const XOSCSEL EXTCLK, _32KHz, XTAL_256CLK, XTAL_1KCLK, XTAL_16KCLK;
        explicit XOSCSEL(const XOSCSEL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // PLL Clock Source
    class PLLSRC {
    private:
        enum PLLSRC_ {
            RC2M_ = 0x00, // Internal 2 MHz RC Oscillator
            RC32M_ = 0x02, // Internal 32 MHz RC Oscillator
            XOSC_ = 0x03, // External Oscillator
        };
        PLLSRC_ value_;
    public:
        static const PLLSRC RC2M, RC32M, XOSC;
        explicit PLLSRC(const PLLSRC_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // 2 MHz DFLL Calibration Reference
    class RC2MCREF {
    private:
        enum RC2MCREF_ {
            RC32K_ = 0x00, // Internal 32.768 kHz RC Oscillator
            XOSC32K_ = 0x01, // External 32.768 kHz Crystal Oscillator
        };
        RC2MCREF_ value_;
    public:
        static const RC2MCREF RC32K, XOSC32K;
        explicit RC2MCREF(const RC2MCREF_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // 32 MHz DFLL Calibration Reference
    class RC32MCREF {
    private:
        enum RC32MCREF_ {
            RC32K_ = 0x00, // Internal 32.768 kHz RC Oscillator
            XOSC32K_ = 0x01, // External 32.768 kHz Crystal Oscillator
            USBSOF_ = 0x02, // USB Start of Frame
        };
        RC32MCREF_ value_;
    public:
        static const RC32MCREF RC32K, XOSC32K, USBSOF;
        explicit RC32MCREF(const RC32MCREF_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };


    // OSC Interrupts
    class INTERRUPTS {
    private:
        enum OSC_VECTORS_ {
            OSCF_ = 0, // Oscillator Failure Interrupt (NMI)
        };
        OSC_VECTORS_ value_;
    public:
        static const OSC OSCF;
        explicit OSC(const OSC_VECTORS_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

} // namespace OSC
} // namespace device
