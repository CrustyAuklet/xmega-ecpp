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

    // Oscillator Frequency Range
    class FRQRANGEv {
    public:
        enum FRQRANGE_ {
            _04TO2 = 0x00, // 0.4 - 2 MHz
            _2TO9 = 0x01, // 2 - 9 MHz
            _9TO12 = 0x02, // 9 - 12 MHz
            _12TO16 = 0x03, // 12 - 16 MHz
        };
        FRQRANGEv(const FRQRANGE_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // External Oscillator Selection and Startup Time
    class XOSCSELv {
    public:
        enum XOSCSEL_ {
            EXTCLK = 0x00, // External Clock - 6 CLK
            _32KHz = 0x02, // 32.768 kHz TOSC - 32K CLK
            XTAL_256CLK = 0x03, // 0.4-16 MHz XTAL - 256 CLK
            XTAL_1KCLK = 0x07, // 0.4-16 MHz XTAL - 1K CLK
            XTAL_16KCLK = 0x0B, // 0.4-16 MHz XTAL - 16K CLK
        };
        XOSCSELv(const XOSCSEL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // PLL Clock Source
    class PLLSRCv {
    public:
        enum PLLSRC_ {
            RC2M = 0x00, // Internal 2 MHz RC Oscillator
            RC32M = 0x02, // Internal 32 MHz RC Oscillator
            XOSC = 0x03, // External Oscillator
        };
        PLLSRCv(const PLLSRC_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // 2 MHz DFLL Calibration Reference
    class RC2MCREFv {
    public:
        enum RC2MCREF_ {
            RC32K = 0x00, // Internal 32.768 kHz RC Oscillator
            XOSC32K = 0x01, // External 32.768 kHz Crystal Oscillator
        };
        RC2MCREFv(const RC2MCREF_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // 32 MHz DFLL Calibration Reference
    class RC32MCREFv {
    public:
        enum RC32MCREF_ {
            RC32K = 0x00, // Internal 32.768 kHz RC Oscillator
            XOSC32K = 0x01, // External 32.768 kHz Crystal Oscillator
            USBSOF = 0x02, // USB Start of Frame
        };
        RC32MCREFv(const RC32MCREF_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // OSC ISR Vector Offsets (two bytes each)
    class INTERRUPTS {
    public:
        enum INTERRUPTS_ {
            OSCF = 0, // Oscillator Failure Interrupt (NMI)
        };
        INTERRUPTS(const INTERRUPTS_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

};

} // namespace device
