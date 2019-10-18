/**
 * None-AES (id I6096)
 * AES Module
 *
 *
 */
#pragma once

#include "device/register.hpp"
#include <cstdint>

namespace device {

/**
 * AES
 * AES Module
 * Size: 5 bytes
 */
template <addressType BASE_ADDRESS>
struct AES_t {

    /// AES Control Register - 1 bytes
    struct CTRL : public reg8_t<BASE_ADDRESS + 0x0000> {
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x80, 7> START;    //< Start/Run using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x40, 6> AUTO;    //< Auto Start Trigger using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x20, 5> RESET;    //< AES Software Reset using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x10, 4> DECRYPT;    //< Decryption / Direction using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x04, 2> XOR;    //< State XOR Load Enable using None
    };

    /// AES Status Register - 1 bytes
    struct STATUS : public reg8_t<BASE_ADDRESS + 0x0001> {
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x80, 7> ERROR;    //< AES Error using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x01, 0> SRIF;    //< State Ready Interrupt Flag using None
    };

    /// AES State Register - 1 bytes
    struct STATE : public reg8_t<BASE_ADDRESS + 0x0002> {
    };

    /// AES Key Register - 1 bytes
    struct KEY : public reg8_t<BASE_ADDRESS + 0x0003> {
    };

    /// AES Interrupt Control Register - 1 bytes
    struct INTCTRL : public reg8_t<BASE_ADDRESS + 0x0004> {
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x03, 0> INTLVL;    //< Interrupt level using AES_INTLVL
    };
};

namespace AES {

    // Interrupt level
    class INTLVL {
    private:
        enum INTLVL_ {
            OFF_ = 0x00, // Interrupt Disabled
            LO_ = 0x01, // Low Level
            MED_ = 0x02, // Medium Level
            HI_ = 0x03, // High Level
        };
        INTLVL_ value_;
    public:
        static const INTLVL OFF, LO, MED, HI;
        explicit INTLVL(const INTLVL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };


    // AES Interrupts
    class INTERRUPTS {
    private:
        enum AES_VECTORS_ {
            INT_ = 0, // AES Interrupt
        };
        AES_VECTORS_ value_;
    public:
        static const AES INT;
        explicit AES(const AES_VECTORS_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

} // namespace AES
} // namespace device
