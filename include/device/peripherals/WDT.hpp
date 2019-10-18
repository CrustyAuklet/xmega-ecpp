/**
 * None-WDT (id I6078)
 * Watch-Dog Timer
 *
 *
 */
#pragma once

#include "device/register.hpp"
#include <cstdint>

namespace device {

/**
 * WDT
 * Watch-Dog Timer
 * Size: 3 bytes
 */
template <addressType BASE_ADDRESS>
struct WDT_t {

    /// Control - 1 bytes
    struct CTRL : public reg8_t<BASE_ADDRESS + 0x0000> {
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x3C, 2> PER;    //< Period using WDT_PER
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x02, 1> ENABLE;    //< Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x01, 0> CEN;    //< Change Enable using None
    };

    /// Windowed Mode Control - 1 bytes
    struct WINCTRL : public reg8_t<BASE_ADDRESS + 0x0001> {
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x3C, 2> WPER;    //< Windowed Mode Period using WDT_WPER
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x02, 1> WEN;    //< Windowed Mode Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x01, 0> WCEN;    //< Windowed Mode Change Enable using None
    };

    /// Status - 1 bytes
    struct STATUS : public reg8_t<BASE_ADDRESS + 0x0002> {
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x01, 0> SYNCBUSY;    //< Syncronization busy using None
    };

    // Period setting
    class PERv {
    public:
        enum PER_ {
            _8CLK = 0x00, // 8 cycles (8ms @ 3.3V)
            _16CLK = 0x01, // 16 cycles (16ms @ 3.3V)
            _32CLK = 0x02, // 32 cycles (32ms @ 3.3V)
            _64CLK = 0x03, // 64 cycles (64ms @ 3.3V)
            _128CLK = 0x04, // 128 cycles (0.128s @ 3.3V)
            _256CLK = 0x05, // 256 cycles (0.256s @ 3.3V)
            _512CLK = 0x06, // 512 cycles (0.512s @ 3.3V)
            _1KCLK = 0x07, // 1K cycles (1s @ 3.3V)
            _2KCLK = 0x08, // 2K cycles (2s @ 3.3V)
            _4KCLK = 0x09, // 4K cycles (4s @ 3.3V)
            _8KCLK = 0x0A, // 8K cycles (8s @ 3.3V)
        };
        PERv(const PER_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Closed window period
    class WPERv {
    public:
        enum WPER_ {
            _8CLK = 0x00, // 8 cycles (8ms @ 3.3V)
            _16CLK = 0x01, // 16 cycles (16ms @ 3.3V)
            _32CLK = 0x02, // 32 cycles (32ms @ 3.3V)
            _64CLK = 0x03, // 64 cycles (64ms @ 3.3V)
            _128CLK = 0x04, // 128 cycles (0.128s @ 3.3V)
            _256CLK = 0x05, // 256 cycles (0.256s @ 3.3V)
            _512CLK = 0x06, // 512 cycles (0.512s @ 3.3V)
            _1KCLK = 0x07, // 1K cycles (1s @ 3.3V)
            _2KCLK = 0x08, // 2K cycles (2s @ 3.3V)
            _4KCLK = 0x09, // 4K cycles (4s @ 3.3V)
            _8KCLK = 0x0A, // 8K cycles (8s @ 3.3V)
        };
        WPERv(const WPER_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

};

} // namespace device
