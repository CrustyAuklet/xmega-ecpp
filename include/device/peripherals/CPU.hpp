/**
 * None-CPU (id I6000)
 * CPU
 *
 *
 */
#pragma once

#include "device/register.hpp"
#include <cstdint>

namespace device {

/**
 * CPU
 * CPU registers
 * Size: 16 bytes
 */
template <addressType BASE_ADDRESS>
struct CPU_t {

    /// Configuration Change Protection - 1 bytes
    struct CCP : public reg8_t<BASE_ADDRESS + 0x0004> {
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0xFF, 0> CCP;    //< CCP signature using CCP
    };

    /// Ramp D - 1 bytes
    struct RAMPD : public reg8_t<BASE_ADDRESS + 0x0008> {
    };

    /// Ramp X - 1 bytes
    struct RAMPX : public reg8_t<BASE_ADDRESS + 0x0009> {
    };

    /// Ramp Y - 1 bytes
    struct RAMPY : public reg8_t<BASE_ADDRESS + 0x000A> {
    };

    /// Ramp Z - 1 bytes
    struct RAMPZ : public reg8_t<BASE_ADDRESS + 0x000B> {
    };

    /// Extended Indirect Jump - 1 bytes
    struct EIND : public reg8_t<BASE_ADDRESS + 0x000C> {
    };

    /// Stack Pointer Low - 1 bytes
    struct SPL : public reg8_t<BASE_ADDRESS + 0x000D> {
    };

    /// Stack Pointer High - 1 bytes
    struct SPH : public reg8_t<BASE_ADDRESS + 0x000E> {
    };

    /// Status Register - 1 bytes
    struct SREG : public reg8_t<BASE_ADDRESS + 0x000F> {
        typedef reg_field_t<BASE_ADDRESS + 0x000F, 0x80, 7> I;    //< Global Interrupt Enable Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000F, 0x40, 6> T;    //< Transfer Bit using None
        typedef reg_field_t<BASE_ADDRESS + 0x000F, 0x20, 5> H;    //< Half Carry Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000F, 0x10, 4> S;    //< N Exclusive Or V Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000F, 0x08, 3> V;    //< Two's Complement Overflow Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000F, 0x04, 2> N;    //< Negative Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000F, 0x02, 1> Z;    //< Zero Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000F, 0x01, 0> C;    //< Carry Flag using None
    };
};

namespace CPU {

    // CCP signatures
    class CCP {
    private:
        enum CCP_ {
            SPM_ = 0x9D, // SPM Instruction Protection
            IOREG_ = 0xD8, // IO Register Protection
        };
        CCP_ value_;
    public:
        static const CCP SPM, IOREG;
        explicit CCP(const CCP_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };


} // namespace CPU
} // namespace device
