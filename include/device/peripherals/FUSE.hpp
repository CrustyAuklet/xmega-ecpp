/**
 * XMEGAAU-FUSE (id I6570)
 * Fuses and Lockbits
 *
 *
 */
#pragma once

#include "device/register.hpp"
#include <cstdint>

namespace device {

/**
 * NVM_FUSES
 * Fuses
 * Size: 6 bytes
 */
template <addressType BASE_ADDRESS>
struct NVM_FUSES_t {

    /// JTAG User ID - 1 bytes
    struct FUSEBYTE0 : public reg8_t<BASE_ADDRESS + 0x0000> {
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0xFF, 0> JTAGUSERID;    //< JTAG User ID using None
    };

    /// Watchdog Configuration - 1 bytes
    struct FUSEBYTE1 : public reg8_t<BASE_ADDRESS + 0x0001> {
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0xF0, 4> WDWP;    //< Watchdog Window Timeout Period using WD
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x0F, 0> WDP;    //< Watchdog Timeout Period using WDP
    };

    /// Reset Configuration - 1 bytes
    struct FUSEBYTE2 : public reg8_t<BASE_ADDRESS + 0x0002> {
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x40, 6> BOOTRST;    //< Boot Loader Section Reset Vector using BOOTRST
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x20, 5> TOSCSEL;    //< Timer Oscillator pin location using TOSCSEL
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x03, 0> BODPD;    //< BOD Operation in Power-Down Mode using BOD
    };

    /// Start-up Configuration - 1 bytes
    struct FUSEBYTE4 : public reg8_t<BASE_ADDRESS + 0x0004> {
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x10, 4> RSTDISBL;    //< External Reset Disable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x0C, 2> SUT;    //< Start-up Time using SUT
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x02, 1> WDLOCK;    //< Watchdog Timer Lock using None
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x01, 0> JTAGEN;    //< JTAG Interface Enable using None
    };

    /// EESAVE and BOD Level - 1 bytes
    struct FUSEBYTE5 : public reg8_t<BASE_ADDRESS + 0x0005> {
        typedef reg_field_t<BASE_ADDRESS + 0x0005, 0x30, 4> BODACT;    //< BOD Operation in Active Mode using BODACT
        typedef reg_field_t<BASE_ADDRESS + 0x0005, 0x08, 3> EESAVE;    //< Preserve EEPROM Through Chip Erase using None
        typedef reg_field_t<BASE_ADDRESS + 0x0005, 0x07, 0> BODLVL;    //< Brownout Detection Voltage Level using BODLVL
    };
};

namespace FUSE {

    // Boot Loader Section Reset Vector
    class BOOTRST {
    private:
        enum BOOTRST_ {
            BOOTLDR_ = 0x00, // Boot Loader Reset
            APPLICATION_ = 0x01, // Application Reset
        };
        BOOTRST_ value_;
    public:
        static const BOOTRST BOOTLDR, APPLICATION;
        explicit BOOTRST(const BOOTRST_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Timer Oscillator pin location
    class TOSCSEL {
    private:
        enum TOSCSEL_ {
            ALTERNATE_ = 0x00, // TOSC1 / TOSC2 on separate pins
            XTAL_ = 0x01, // TOSC1 / TOSC2 shared with XTAL1 / XTAL2
        };
        TOSCSEL_ value_;
    public:
        static const TOSCSEL ALTERNATE, XTAL;
        explicit TOSCSEL(const TOSCSEL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // BOD operation
    class BOD {
    private:
        enum BOD_ {
            SAMPLED_ = 0x01, // BOD enabled in sampled mode
            CONTINUOUS_ = 0x02, // BOD enabled continuously
            DISABLED_ = 0x03, // BOD Disabled
        };
        BOD_ value_;
    public:
        static const BOD SAMPLED, CONTINUOUS, DISABLED;
        explicit BOD(const BOD_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // BOD operation
    class BODACT {
    private:
        enum BODACT_ {
            SAMPLED_ = 0x01, // BOD enabled in sampled mode
            CONTINUOUS_ = 0x02, // BOD enabled continuously
            DISABLED_ = 0x03, // BOD Disabled
        };
        BODACT_ value_;
    public:
        static const BODACT SAMPLED, CONTINUOUS, DISABLED;
        explicit BODACT(const BODACT_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Watchdog (Window) Timeout Period
    class WD {
    private:
        enum WD_ {
            _8CLK_ = 0x00, // 8 cycles (8ms @ 3.3V)
            _16CLK_ = 0x01, // 16 cycles (16ms @ 3.3V)
            _32CLK_ = 0x02, // 32 cycles (32ms @ 3.3V)
            _64CLK_ = 0x03, // 64 cycles (64ms @ 3.3V)
            _128CLK_ = 0x04, // 128 cycles (0.125s @ 3.3V)
            _256CLK_ = 0x05, // 256 cycles (0.25s @ 3.3V)
            _512CLK_ = 0x06, // 512 cycles (0.5s @ 3.3V)
            _1KCLK_ = 0x07, // 1K cycles (1s @ 3.3V)
            _2KCLK_ = 0x08, // 2K cycles (2s @ 3.3V)
            _4KCLK_ = 0x09, // 4K cycles (4s @ 3.3V)
            _8KCLK_ = 0x0A, // 8K cycles (8s @ 3.3V)
        };
        WD_ value_;
    public:
        static const WD _8CLK, _16CLK, _32CLK, _64CLK, _128CLK, _256CLK, _512CLK, _1KCLK, _2KCLK, _4KCLK, _8KCLK;
        explicit WD(const WD_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Watchdog (Window) Timeout Period
    class WDP {
    private:
        enum WDP_ {
            _8CLK_ = 0x00, // 8 cycles (8ms @ 3.3V)
            _16CLK_ = 0x01, // 16 cycles (16ms @ 3.3V)
            _32CLK_ = 0x02, // 32 cycles (32ms @ 3.3V)
            _64CLK_ = 0x03, // 64 cycles (64ms @ 3.3V)
            _128CLK_ = 0x04, // 128 cycles (0.125s @ 3.3V)
            _256CLK_ = 0x05, // 256 cycles (0.25s @ 3.3V)
            _512CLK_ = 0x06, // 512 cycles (0.5s @ 3.3V)
            _1KCLK_ = 0x07, // 1K cycles (1s @ 3.3V)
            _2KCLK_ = 0x08, // 2K cycles (2s @ 3.3V)
            _4KCLK_ = 0x09, // 4K cycles (4s @ 3.3V)
            _8KCLK_ = 0x0A, // 8K cycles (8s @ 3.3V)
        };
        WDP_ value_;
    public:
        static const WDP _8CLK, _16CLK, _32CLK, _64CLK, _128CLK, _256CLK, _512CLK, _1KCLK, _2KCLK, _4KCLK, _8KCLK;
        explicit WDP(const WDP_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Start-up Time
    class SUT {
    private:
        enum SUT_ {
            _0MS_ = 0x03, // 0 ms
            _4MS_ = 0x01, // 4 ms
            _64MS_ = 0x00, // 64 ms
        };
        SUT_ value_;
    public:
        static const SUT _0MS, _4MS, _64MS;
        explicit SUT(const SUT_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Brownout Detection Voltage Level
    class BODLVL {
    private:
        enum BODLVL_ {
            _1V6_ = 0x07, // 1.6 V
            _1V8_ = 0x06, // 1.8 V
            _2V0_ = 0x05, // 2.0 V
            _2V2_ = 0x04, // 2.2 V
            _2V4_ = 0x03, // 2.4 V
            _2V6_ = 0x02, // 2.6 V
            _2V8_ = 0x01, // 2.8 V
            _3V0_ = 0x00, // 3.0 V
        };
        BODLVL_ value_;
    public:
        static const BODLVL _1V6, _1V8, _2V0, _2V2, _2V4, _2V6, _2V8, _3V0;
        explicit BODLVL(const BODLVL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };


} // namespace FUSE
} // namespace device
