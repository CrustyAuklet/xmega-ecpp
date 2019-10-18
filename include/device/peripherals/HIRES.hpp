/**
 * XMEGAAU-HIRES (id I6090)
 * Timer/Counter High-Resolution Extension
 *
 *
 */
#pragma once

#include "device/register.hpp"
#include <cstdint>

namespace device {

/**
 * HIRES
 * High-Resolution Extension
 * Size: 1 bytes
 */
template <addressType BASE_ADDRESS>
struct HIRES_t {

    /// Control Register - 1 bytes
    struct CTRLA : public reg8_t<BASE_ADDRESS + 0x0000> {
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x04, 2> HRPLUS;    //< High Resolution Plus using HIRES_HRPLUS
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x03, 0> HREN;    //< High Resolution Enable using HIRES_HREN
    };
};

namespace HIRES {

    // High Resolution Enable
    class HREN {
    private:
        enum HREN_ {
            NONE_ = 0x00, // No Fault Protection
            TC0_ = 0x01, // Enable High Resolution on Timer/Counter 0
            TC1_ = 0x02, // Enable High Resolution on Timer/Counter 1
            BOTH_ = 0x03, // Enable High Resolution both Timer/Counters
        };
        HREN_ value_;
    public:
        static const HREN NONE, TC0, TC1, BOTH;
        explicit HREN(const HREN_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };


} // namespace HIRES
} // namespace device
