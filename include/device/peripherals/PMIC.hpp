/**
 * None-PMIC (id I6057)
 * Programmable Multi-level Interrupt Controller
 *
 *
 */
#pragma once

#include "device/register.hpp"
#include <cstdint>

namespace device {

/**
 * PMIC
 * Programmable Multi-level Interrupt Controller
 * Size: 16 bytes
 */
template <addressType BASE_ADDRESS>
struct PMIC_t {

    /// Status Register - 1 bytes
    struct STATUS : public reg8_t<BASE_ADDRESS + 0x0000> {
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x80, 7> NMIEX;    //< Non-maskable Interrupt Executing using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x04, 2> HILVLEX;    //< High Level Interrupt Executing using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x02, 1> MEDLVLEX;    //< Medium Level Interrupt Executing using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x01, 0> LOLVLEX;    //< Low Level Interrupt Executing using None
    };

    /// Interrupt Priority - 1 bytes
    struct INTPRI : public reg8_t<BASE_ADDRESS + 0x0001> {
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0xFF, 0> INTPRI;    //< Interrupt Priority using None
    };

    /// Control Register - 1 bytes
    struct CTRL : public reg8_t<BASE_ADDRESS + 0x0002> {
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x80, 7> RREN;    //< Round-Robin Priority Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x40, 6> IVSEL;    //< Interrupt Vector Select using None
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x04, 2> HILVLEN;    //< High Level Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x02, 1> MEDLVLEN;    //< Medium Level Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x01, 0> LOLVLEN;    //< Low Level Enable using None
    };
};

namespace PMIC {


} // namespace PMIC
} // namespace device
