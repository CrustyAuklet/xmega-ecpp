/**
 * None-XOCD (id I6043)
 * On-Chip Debug System
 *
 *
 */
#pragma once

#include "device/register.hpp"
#include <cstdint>

namespace device {

/**
 * OCD
 * On-Chip Debug System
 * Size: 2 bytes
 */
template <addressType BASE_ADDRESS>
struct OCD_t {

    /// OCD Register 0 - 1 bytes
    struct OCDR0 : public reg8_t<BASE_ADDRESS + 0x0000> {
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0xFF, 0> OCDRD;    //< OCDR Dirty using None
    };

    /// OCD Register 1 - 1 bytes
    struct OCDR1 : public reg8_t<BASE_ADDRESS + 0x0001> {
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x01, 0> OCDRD;    //< OCDR Dirty using None
    };

};

} // namespace device
