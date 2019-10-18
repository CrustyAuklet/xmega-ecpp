/**
 * XMEGAAU-LOCKBIT (id I6570)
 * Fuses and Lockbits
 *
 *
 */
#pragma once

#include "device/register.hpp"
#include <cstdint>

namespace device {

/**
 * NVM_LOCKBITS
 * Lock Bits
 * Size: 1 bytes
 */
template <addressType BASE_ADDRESS>
struct NVM_LOCKBITS_t {

    /// Lock Bits - 1 bytes
    struct LOCKBITS : public reg8_t<BASE_ADDRESS + 0x0000> {
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0xC0, 6> BLBB;    //< Boot Lock Bits - Boot Section using FUSE_BLBB
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x30, 4> BLBA;    //< Boot Lock Bits - Application Section using FUSE_BLBA
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x0C, 2> BLBAT;    //< Boot Lock Bits - Application Table using FUSE_BLBAT
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x03, 0> LB;    //< Lock Bits using FUSE_LB
    };
};

namespace LOCKBIT {

    // Boot lock bits - boot setcion
    class BLBB {
    private:
        enum BLBB_ {
            RWLOCK_ = 0x00, // Read and write not allowed
            RLOCK_ = 0x01, // Read not allowed
            WLOCK_ = 0x02, // Write not allowed
            NOLOCK_ = 0x03, // No locks
        };
        BLBB_ value_;
    public:
        static const BLBB RWLOCK, RLOCK, WLOCK, NOLOCK;
        explicit BLBB(const BLBB_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Boot lock bits - application section
    class BLBA {
    private:
        enum BLBA_ {
            RWLOCK_ = 0x00, // Read and write not allowed
            RLOCK_ = 0x01, // Read not allowed
            WLOCK_ = 0x02, // Write not allowed
            NOLOCK_ = 0x03, // No locks
        };
        BLBA_ value_;
    public:
        static const BLBA RWLOCK, RLOCK, WLOCK, NOLOCK;
        explicit BLBA(const BLBA_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Boot lock bits - application table section
    class BLBAT {
    private:
        enum BLBAT_ {
            RWLOCK_ = 0x00, // Read and write not allowed
            RLOCK_ = 0x01, // Read not allowed
            WLOCK_ = 0x02, // Write not allowed
            NOLOCK_ = 0x03, // No locks
        };
        BLBAT_ value_;
    public:
        static const BLBAT RWLOCK, RLOCK, WLOCK, NOLOCK;
        explicit BLBAT(const BLBAT_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Lock bits
    class LB {
    private:
        enum LB_ {
            RWLOCK_ = 0x00, // Read and write not allowed
            WLOCK_ = 0x02, // Write not allowed
            NOLOCK_ = 0x03, // No locks
        };
        LB_ value_;
    public:
        static const LB RWLOCK, WLOCK, NOLOCK;
        explicit LB(const LB_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };


} // namespace LOCKBIT
} // namespace device
