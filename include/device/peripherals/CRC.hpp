/**
 * XMEGAAU-CRC (id I6111)
 * Cyclic Redundancy Checker
 *
 *
 */
#pragma once

#include "device/register.hpp"
#include <cstdint>

namespace device {

/**
 * CRC
 * Cyclic Redundancy Checker
 * Size: 8 bytes
 */
template <addressType BASE_ADDRESS>
struct CRC_t {

    /// Control Register - 1 bytes
    struct CTRL : public reg8_t<BASE_ADDRESS + 0x0000> {
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0xC0, 6> RESET;    //< Reset using CRC_RESET
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x20, 5> CRC32;    //< CRC Mode using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x0F, 0> SOURCE;    //< Input Source using CRC_SOURCE
    };

    /// Status Register - 1 bytes
    struct STATUS : public reg8_t<BASE_ADDRESS + 0x0001> {
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x02, 1> ZERO;    //< Zero detection using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x01, 0> BUSY;    //< Busy using None
    };

    /// Data Input - 1 bytes
    struct DATAIN : public reg8_t<BASE_ADDRESS + 0x0003> {
    };

    /// Checksum byte 0 - 1 bytes
    struct CHECKSUM0 : public reg8_t<BASE_ADDRESS + 0x0004> {
    };

    /// Checksum byte 1 - 1 bytes
    struct CHECKSUM1 : public reg8_t<BASE_ADDRESS + 0x0005> {
    };

    /// Checksum byte 2 - 1 bytes
    struct CHECKSUM2 : public reg8_t<BASE_ADDRESS + 0x0006> {
    };

    /// Checksum byte 3 - 1 bytes
    struct CHECKSUM3 : public reg8_t<BASE_ADDRESS + 0x0007> {
    };
};

namespace CRC {

    // Reset
    class RESET {
    private:
        enum RESET_ {
            NO_ = 0x00, // No Reset
            RESET0_ = 0x02, // Reset CRC with CHECKSUM to all zeros
            RESET1_ = 0x03, // Reset CRC with CHECKSUM to all ones
        };
        RESET_ value_;
    public:
        static const RESET NO, RESET0, RESET1;
        explicit RESET(const RESET_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Input Source
    class SOURCE {
    private:
        enum SOURCE_ {
            DISABLE_ = 0x00, // Disabled
            IO_ = 0x01, // I/O Interface
            FLASH_ = 0x02, // Flash
            DMAC0_ = 0x04, // DMAC Channel 0
            DMAC1_ = 0x05, // DMAC Channel 1
            DMAC2_ = 0x06, // DMAC Channel 2
            DMAC3_ = 0x07, // DMAC Channel 3
        };
        SOURCE_ value_;
    public:
        static const SOURCE DISABLE, IO, FLASH, DMAC0, DMAC1, DMAC2, DMAC3;
        explicit SOURCE(const SOURCE_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };


} // namespace CRC
} // namespace device
