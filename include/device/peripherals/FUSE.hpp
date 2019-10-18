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

    // Boot Loader Section Reset Vector
    class BOOTRSTv {
    public:
        enum BOOTRST_ {
            BOOTLDR = 0x00, // Boot Loader Reset
            APPLICATION = 0x01, // Application Reset
        };
        BOOTRSTv(const BOOTRST_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Timer Oscillator pin location
    class TOSCSELv {
    public:
        enum TOSCSEL_ {
            ALTERNATE = 0x00, // TOSC1 / TOSC2 on separate pins
            XTAL = 0x01, // TOSC1 / TOSC2 shared with XTAL1 / XTAL2
        };
        TOSCSELv(const TOSCSEL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // BOD operation
    class BODv {
    public:
        enum BOD_ {
            SAMPLED = 0x01, // BOD enabled in sampled mode
            CONTINUOUS = 0x02, // BOD enabled continuously
            DISABLED = 0x03, // BOD Disabled
        };
        BODv(const BOD_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // BOD operation
    class BODACTv {
    public:
        enum BODACT_ {
            SAMPLED = 0x01, // BOD enabled in sampled mode
            CONTINUOUS = 0x02, // BOD enabled continuously
            DISABLED = 0x03, // BOD Disabled
        };
        BODACTv(const BODACT_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Watchdog (Window) Timeout Period
    class WDv {
    public:
        enum WD_ {
            _8CLK = 0x00, // 8 cycles (8ms @ 3.3V)
            _16CLK = 0x01, // 16 cycles (16ms @ 3.3V)
            _32CLK = 0x02, // 32 cycles (32ms @ 3.3V)
            _64CLK = 0x03, // 64 cycles (64ms @ 3.3V)
            _128CLK = 0x04, // 128 cycles (0.125s @ 3.3V)
            _256CLK = 0x05, // 256 cycles (0.25s @ 3.3V)
            _512CLK = 0x06, // 512 cycles (0.5s @ 3.3V)
            _1KCLK = 0x07, // 1K cycles (1s @ 3.3V)
            _2KCLK = 0x08, // 2K cycles (2s @ 3.3V)
            _4KCLK = 0x09, // 4K cycles (4s @ 3.3V)
            _8KCLK = 0x0A, // 8K cycles (8s @ 3.3V)
        };
        WDv(const WD_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Watchdog (Window) Timeout Period
    class WDPv {
    public:
        enum WDP_ {
            _8CLK = 0x00, // 8 cycles (8ms @ 3.3V)
            _16CLK = 0x01, // 16 cycles (16ms @ 3.3V)
            _32CLK = 0x02, // 32 cycles (32ms @ 3.3V)
            _64CLK = 0x03, // 64 cycles (64ms @ 3.3V)
            _128CLK = 0x04, // 128 cycles (0.125s @ 3.3V)
            _256CLK = 0x05, // 256 cycles (0.25s @ 3.3V)
            _512CLK = 0x06, // 512 cycles (0.5s @ 3.3V)
            _1KCLK = 0x07, // 1K cycles (1s @ 3.3V)
            _2KCLK = 0x08, // 2K cycles (2s @ 3.3V)
            _4KCLK = 0x09, // 4K cycles (4s @ 3.3V)
            _8KCLK = 0x0A, // 8K cycles (8s @ 3.3V)
        };
        WDPv(const WDP_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Start-up Time
    class SUTv {
    public:
        enum SUT_ {
            _0MS = 0x03, // 0 ms
            _4MS = 0x01, // 4 ms
            _64MS = 0x00, // 64 ms
        };
        SUTv(const SUT_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Brownout Detection Voltage Level
    class BODLVLv {
    public:
        enum BODLVL_ {
            _1V6 = 0x07, // 1.6 V
            _1V8 = 0x06, // 1.8 V
            _2V0 = 0x05, // 2.0 V
            _2V2 = 0x04, // 2.2 V
            _2V4 = 0x03, // 2.4 V
            _2V6 = 0x02, // 2.6 V
            _2V8 = 0x01, // 2.8 V
            _3V0 = 0x00, // 3.0 V
        };
        BODLVLv(const BODLVL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

};

} // namespace device
