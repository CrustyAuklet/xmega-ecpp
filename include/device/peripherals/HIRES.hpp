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

    // High Resolution Enable
    class HRENv {
    public:
        enum HREN_ {
            NONE = 0x00, // No Fault Protection
            TC0 = 0x01, // Enable High Resolution on Timer/Counter 0
            TC1 = 0x02, // Enable High Resolution on Timer/Counter 1
            BOTH = 0x03, // Enable High Resolution both Timer/Counters
        };
        HRENv(const HREN_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

};

} // namespace device
