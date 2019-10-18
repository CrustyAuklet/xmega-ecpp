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

    // Reset
    class RESETv {
    public:
        enum RESET_ {
            NO = 0x00, // No Reset
            RESET0 = 0x02, // Reset CRC with CHECKSUM to all zeros
            RESET1 = 0x03, // Reset CRC with CHECKSUM to all ones
        };
        RESETv(const RESET_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Input Source
    class SOURCEv {
    public:
        enum SOURCE_ {
            DISABLE = 0x00, // Disabled
            IO = 0x01, // I/O Interface
            FLASH = 0x02, // Flash
            DMAC0 = 0x04, // DMAC Channel 0
            DMAC1 = 0x05, // DMAC Channel 1
            DMAC2 = 0x06, // DMAC Channel 2
            DMAC3 = 0x07, // DMAC Channel 3
        };
        SOURCEv(const SOURCE_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

};

} // namespace device
