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
};

namespace SLEEP {

    // Sleep Mode
    class SMODE {
    private:
        enum SMODE_ {
            IDLE_ = 0x00, // Idle mode
            PDOWN_ = 0x02, // Power-down Mode
            PSAVE_ = 0x03, // Power-save Mode
            STDBY_ = 0x06, // Standby Mode
            ESTDBY_ = 0x07, // Extended Standby Mode
        };
        SMODE_ value_;
    public:
        static const SMODE IDLE, PDOWN, PSAVE, STDBY, ESTDBY;
        explicit SMODE(const SMODE_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };


} // namespace SLEEP
} // namespace device
