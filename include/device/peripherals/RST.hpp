/**
 * XMEGAAU-RST (id I6083)
 * Reset
 *
 *
 */
#pragma once

#include "device/register.hpp"
#include <cstdint>

namespace device {

/**
 * RST
 * Reset
 * Size: 2 bytes
 */
template <addressType BASE_ADDRESS>
struct RST_t {

    /// Status Register - 1 bytes
    struct STATUS : public reg8_t<BASE_ADDRESS + 0x0000> {
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x40, 6> SDRF;    //< Spike Detection Reset Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x20, 5> SRF;    //< Software Reset Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x10, 4> PDIRF;    //< Programming and Debug Interface Interface Reset Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x08, 3> WDRF;    //< Watchdog Reset Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x04, 2> BORF;    //< Brown-out Reset Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x02, 1> EXTRF;    //< External Reset Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x01, 0> PORF;    //< Power-on Reset Flag using None
    };

    /// Control Register - 1 bytes
    struct CTRL : public reg8_t<BASE_ADDRESS + 0x0001> {
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x01, 0> SWRST;    //< Software Reset using None
    };
};

namespace RST {


} // namespace RST
} // namespace device
