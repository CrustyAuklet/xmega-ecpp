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

    // Boot lock bits - boot setcion
    class BLBBv {
    public:
        enum BLBB_ {
            RWLOCK = 0x00, // Read and write not allowed
            RLOCK = 0x01, // Read not allowed
            WLOCK = 0x02, // Write not allowed
            NOLOCK = 0x03, // No locks
        };
        BLBBv(const BLBB_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Boot lock bits - application section
    class BLBAv {
    public:
        enum BLBA_ {
            RWLOCK = 0x00, // Read and write not allowed
            RLOCK = 0x01, // Read not allowed
            WLOCK = 0x02, // Write not allowed
            NOLOCK = 0x03, // No locks
        };
        BLBAv(const BLBA_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Boot lock bits - application table section
    class BLBATv {
    public:
        enum BLBAT_ {
            RWLOCK = 0x00, // Read and write not allowed
            RLOCK = 0x01, // Read not allowed
            WLOCK = 0x02, // Write not allowed
            NOLOCK = 0x03, // No locks
        };
        BLBATv(const BLBAT_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Lock bits
    class LBv {
    public:
        enum LB_ {
            RWLOCK = 0x00, // Read and write not allowed
            WLOCK = 0x02, // Write not allowed
            NOLOCK = 0x03, // No locks
        };
        LBv(const LB_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

};

} // namespace device
