/**
 * XMEGAAU-IRCOM (id I6090)
 * IR Communication Module
 *
 *
 */
#pragma once

#include "device/register.hpp"
#include <cstdint>

namespace device {

/**
 * IRCOM
 * IR Communication Module
 * Size: 3 bytes
 */
template <addressType BASE_ADDRESS>
struct IRCOM_t {

    /// Control Register - 1 bytes
    struct CTRL : public reg8_t<BASE_ADDRESS + 0x0000> {
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x0F, 0> EVSEL;    //< Event Channel Select using IRDA_EVSEL
    };

    /// IrDA Transmitter Pulse Length Control Register - 1 bytes
    struct TXPLCTRL : public reg8_t<BASE_ADDRESS + 0x0001> {
    };

    /// IrDA Receiver Pulse Length Control Register - 1 bytes
    struct RXPLCTRL : public reg8_t<BASE_ADDRESS + 0x0002> {
    };
};

namespace IRCOM {

    // Event channel selection
    class EVSEL {
    private:
        enum EVSEL_ {
            OFF_ = 0x00, // No Event Source
            _0_ = 0x08, // Event Channel 0
            _1_ = 0x09, // Event Channel 1
            _2_ = 0x0A, // Event Channel 2
            _3_ = 0x0B, // Event Channel 3
            _4_ = 0x0C, // Event Channel 4
            _5_ = 0x0D, // Event Channel 5
            _6_ = 0x0E, // Event Channel 6
            _7_ = 0x0F, // Event Channel 7
        };
        EVSEL_ value_;
    public:
        static const EVSEL OFF, _0, _1, _2, _3, _4, _5, _6, _7;
        explicit EVSEL(const EVSEL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };


} // namespace IRCOM
} // namespace device
