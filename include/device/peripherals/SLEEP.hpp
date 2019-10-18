/**
 * XMEGAAU-SLEEP (id I6081)
 * Sleep Controller
 *
 *
 */
#pragma once

#include "device/register.hpp"
#include <cstdint>

namespace device {

/**
 * SLEEP
 * Sleep Controller
 * Size: 1 bytes
 */
template <addressType BASE_ADDRESS>
struct SLEEP_t {

    /// Control Register - 1 bytes
    struct CTRL : public reg8_t<BASE_ADDRESS + 0x0000> {
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x0E, 1> SMODE;    //< Sleep Mode using SLEEP_SMODE
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x01, 0> SEN;    //< Sleep Enable using None
    };

    // Sleep Mode
    class SMODEv {
    public:
        enum SMODE_ {
            IDLE = 0x00, // Idle mode
            PDOWN = 0x02, // Power-down Mode
            PSAVE = 0x03, // Power-save Mode
            STDBY = 0x06, // Standby Mode
            ESTDBY = 0x07, // Extended Standby Mode
        };
        SMODEv(const SMODE_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

};

} // namespace device
