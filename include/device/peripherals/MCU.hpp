/**
 * XMEGAAU-MCU (id I6091)
 * MCU Control
 *
 *
 */
#pragma once

#include "device/register.hpp"
#include <cstdint>

namespace device {

/**
 * MCU
 * MCU Control
 * Size: 12 bytes
 */
template <addressType BASE_ADDRESS>
struct MCU_t {

    /// Device ID byte 0 - 1 bytes
    struct DEVID0 : public reg8_t<BASE_ADDRESS + 0x0000> {
    };

    /// Device ID byte 1 - 1 bytes
    struct DEVID1 : public reg8_t<BASE_ADDRESS + 0x0001> {
    };

    /// Device ID byte 2 - 1 bytes
    struct DEVID2 : public reg8_t<BASE_ADDRESS + 0x0002> {
    };

    /// Revision ID - 1 bytes
    struct REVID : public reg8_t<BASE_ADDRESS + 0x0003> {
    };

    /// JTAG User ID - 1 bytes
    struct JTAGUID : public reg8_t<BASE_ADDRESS + 0x0004> {
    };

    /// MCU Control - 1 bytes
    struct MCUCR : public reg8_t<BASE_ADDRESS + 0x0006> {
        typedef reg_field_t<BASE_ADDRESS + 0x0006, 0x01, 0> JTAGD;    //< JTAG Disable using None
    };

    /// Analog Startup Delay - 1 bytes
    struct ANAINIT : public reg8_t<BASE_ADDRESS + 0x0007> {
        typedef reg_field_t<BASE_ADDRESS + 0x0007, 0x0C, 2> STARTUPDLYB;    //< Analog startup delay Port B using None
        typedef reg_field_t<BASE_ADDRESS + 0x0007, 0x03, 0> STARTUPDLYA;    //< Analog startup delay Port A using None
    };

    /// Event System Lock - 1 bytes
    struct EVSYSLOCK : public reg8_t<BASE_ADDRESS + 0x0008> {
        typedef reg_field_t<BASE_ADDRESS + 0x0008, 0x10, 4> EVSYS1LOCK;    //< Event Channel 4-7 Lock using None
        typedef reg_field_t<BASE_ADDRESS + 0x0008, 0x01, 0> EVSYS0LOCK;    //< Event Channel 0-3 Lock using None
    };

    /// AWEX Lock - 1 bytes
    struct AWEXLOCK : public reg8_t<BASE_ADDRESS + 0x0009> {
        typedef reg_field_t<BASE_ADDRESS + 0x0009, 0x08, 3> AWEXFLOCK;    //< AWeX on T/C F0 Lock using None
        typedef reg_field_t<BASE_ADDRESS + 0x0009, 0x04, 2> AWEXELOCK;    //< AWeX on T/C E0 Lock using None
        typedef reg_field_t<BASE_ADDRESS + 0x0009, 0x02, 1> AWEXDLOCK;    //< AWeX on T/C D0 Lock using None
        typedef reg_field_t<BASE_ADDRESS + 0x0009, 0x01, 0> AWEXCLOCK;    //< AWeX on T/C C0 Lock using None
    };

};

} // namespace device
