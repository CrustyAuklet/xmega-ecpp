/**
 * XMEGAAU-AWEX (id I6090)
 * Timer/Counter Advanced Waveform Extension
 *
 *
 */
#pragma once

#include "device/register.hpp"
#include <cstdint>

namespace device {

/**
 * AWEX
 * Advanced Waveform Extension
 * Size: 13 bytes
 */
template <addressType BASE_ADDRESS>
struct AWEX_t {

    /// Control Register - 1 bytes
    struct CTRL : public reg8_t<BASE_ADDRESS + 0x0000> {
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x20, 5> PGM;    //< Pattern Generation Mode using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x10, 4> CWCM;    //< Common Waveform Channel Mode using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x08, 3> DTICCDEN;    //< Dead Time Insertion Compare Channel D Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x04, 2> DTICCCEN;    //< Dead Time Insertion Compare Channel C Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x02, 1> DTICCBEN;    //< Dead Time Insertion Compare Channel B Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x01, 0> DTICCAEN;    //< Dead Time Insertion Compare Channel A Enable using None
    };

    /// Fault Detection Event Mask - 1 bytes
    struct FDEMASK : public reg8_t<BASE_ADDRESS + 0x0002> {
    };

    /// Fault Detection Control Register - 1 bytes
    struct FDCTRL : public reg8_t<BASE_ADDRESS + 0x0003> {
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x10, 4> FDDBD;    //< Fault Detect on Disable Break Disable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x04, 2> FDMODE;    //< Fault Detect Mode using None
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x03, 0> FDACT;    //< Fault Detect Action using AWEX_FDACT
    };

    /// Status Register - 1 bytes
    struct STATUS : public reg8_t<BASE_ADDRESS + 0x0004> {
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x04, 2> FDF;    //< Fault Detect Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x02, 1> DTHSBUFV;    //< Dead Time High Side Buffer Valid using None
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x01, 0> DTLSBUFV;    //< Dead Time Low Side Buffer Valid using None
    };

    /// Status Set Register - 1 bytes
    struct STATUSSET : public reg8_t<BASE_ADDRESS + 0x0005> {
        typedef reg_field_t<BASE_ADDRESS + 0x0005, 0x04, 2> FDF;    //< Fault Detect Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0005, 0x02, 1> DTHSBUFV;    //< Dead Time High Side Buffer Valid using None
        typedef reg_field_t<BASE_ADDRESS + 0x0005, 0x01, 0> DTLSBUFV;    //< Dead Time Low Side Buffer Valid using None
    };

    /// Dead Time Both Sides - 1 bytes
    struct DTBOTH : public reg8_t<BASE_ADDRESS + 0x0006> {
    };

    /// Dead Time Both Sides Buffer - 1 bytes
    struct DTBOTHBUF : public reg8_t<BASE_ADDRESS + 0x0007> {
    };

    /// Dead Time Low Side - 1 bytes
    struct DTLS : public reg8_t<BASE_ADDRESS + 0x0008> {
    };

    /// Dead Time High Side - 1 bytes
    struct DTHS : public reg8_t<BASE_ADDRESS + 0x0009> {
    };

    /// Dead Time Low Side Buffer - 1 bytes
    struct DTLSBUF : public reg8_t<BASE_ADDRESS + 0x000A> {
    };

    /// Dead Time High Side Buffer - 1 bytes
    struct DTHSBUF : public reg8_t<BASE_ADDRESS + 0x000B> {
    };

    /// Output Override Enable - 1 bytes
    struct OUTOVEN : public reg8_t<BASE_ADDRESS + 0x000C> {
    };

    // Fault Detect Action
    class FDACTv {
    public:
        enum FDACT_ {
            NONE = 0x00, // No Fault Protection
            CLEAROE = 0x01, // Clear Output Enable Bits
            CLEARDIR = 0x03, // Clear I/O Port Direction Bits
        };
        FDACTv(const FDACT_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

};

} // namespace device
