/**
 * None-EBI (id I3001)
 * External Bus Interface
 *
 *
 */
#pragma once

#include "device/register.hpp"
#include <cstdint>

namespace device {

/**
 * EBI_CS
 * EBI Chip Select Module
 * Size: 4 bytes
 */
template <addressType BASE_ADDRESS>
struct EBI_CS_t {

    /// Chip Select Control Register A - 1 bytes
    struct CTRLA : public reg8_t<BASE_ADDRESS + 0x0000> {
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x7C, 2> ASIZE;    //< Address Size using EBI_CS_ASIZE
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x7C, 2> ASPACE;    //< Legacy name: Address Space using EBI_CS_ASPACE
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x03, 0> MODE;    //< Memory Mode using EBI_CS_MODE
    };

    /// Chip Select Control Register B - 1 bytes
    struct CTRLB : public reg8_t<BASE_ADDRESS + 0x0001> {
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x07, 0> SRWS;    //< SRAM Wait State Cycles using EBI_CS_SRWS
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x80, 7> SDINITDONE;    //< SDRAM Initialization Done using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x04, 2> SDSREN;    //< SDRAM Self-refresh Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x03, 0> SDMODE;    //< SDRAM Mode using EBI_CS_SDMODE
    };

    /// Chip Select Base Address - 2 bytes
    struct BASEADDR : public reg16_t<BASE_ADDRESS + 0x0002> {
    };};

/**
 * EBI
 * External Bus Interface
 * Size: 32 bytes
 */
template <addressType BASE_ADDRESS>
struct EBI_t {

    /// Control - 1 bytes
    struct CTRL : public reg8_t<BASE_ADDRESS + 0x0000> {
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0xC0, 6> SDDATAW;    //< SDRAM Data Width Setting using EBI_SDDATAW
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x30, 4> LPCMODE;    //< SRAM LPC Mode using EBI_LPCMODE
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x0C, 2> SRMODE;    //< SRAM Mode using EBI_SRMODE
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x03, 0> IFMODE;    //< Interface Mode using EBI_IFMODE
    };

    /// SDRAM Control Register A - 1 bytes
    struct SDRAMCTRLA : public reg8_t<BASE_ADDRESS + 0x0001> {
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x08, 3> SDCAS;    //< SDRAM CAS Latency Setting using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x04, 2> SDROW;    //< SDRAM ROW Bits Setting using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x03, 0> SDCOL;    //< SDRAM Column Bits Setting using EBI_SDCOL
    };

    /// SDRAM Refresh Period - 2 bytes
    struct REFRESH : public reg16_t<BASE_ADDRESS + 0x0004> {
    };

    /// SDRAM Initialization Delay - 2 bytes
    struct INITDLY : public reg16_t<BASE_ADDRESS + 0x0006> {
    };

    /// SDRAM Control Register B - 1 bytes
    struct SDRAMCTRLB : public reg8_t<BASE_ADDRESS + 0x0008> {
        typedef reg_field_t<BASE_ADDRESS + 0x0008, 0xC0, 6> MRDLY;    //< SDRAM Mode Register Delay using EBI_MRDLY
        typedef reg_field_t<BASE_ADDRESS + 0x0008, 0x38, 3> ROWCYCDLY;    //< SDRAM Row Cycle Delay using EBI_ROWCYCDLY
        typedef reg_field_t<BASE_ADDRESS + 0x0008, 0x07, 0> RPDLY;    //< SDRAM Row-to-Precharge Delay using EBI_RPDLY
    };

    /// SDRAM Control Register C - 1 bytes
    struct SDRAMCTRLC : public reg8_t<BASE_ADDRESS + 0x0009> {
        typedef reg_field_t<BASE_ADDRESS + 0x0009, 0xC0, 6> WRDLY;    //< SDRAM Write Recovery Delay using EBI_WRDLY
        typedef reg_field_t<BASE_ADDRESS + 0x0009, 0x38, 3> ESRDLY;    //< SDRAM Exit-Self-refresh-to-Active Delay using EBI_ESRDLY
        typedef reg_field_t<BASE_ADDRESS + 0x0009, 0x07, 0> ROWCOLDLY;    //< SDRAM Row-to-Column Delay using EBI_ROWCOLDLY
    };
    /// Chip Select 0
    EBI_CS_t<BASE_ADDRESS + 0x0010> CS0;

    /// Chip Select 1
    EBI_CS_t<BASE_ADDRESS + 0x0014> CS1;

    /// Chip Select 2
    EBI_CS_t<BASE_ADDRESS + 0x0018> CS2;

    /// Chip Select 3
    EBI_CS_t<BASE_ADDRESS + 0x001C> CS3;


    // Chip Select adress size
    class CS_ASIZEv {
    public:
        enum CS_ASIZE_ {
            _256B = 0x00, // 256 bytes
            _512B = 0x01, // 512 bytes
            _1KB = 0x02, // 1K bytes
            _2KB = 0x03, // 2K bytes
            _4KB = 0x04, // 4K bytes
            _8KB = 0x05, // 8K bytes
            _16KB = 0x06, // 16K bytes
            _32KB = 0x07, // 32K bytes
            _64KB = 0x08, // 64K bytes
            _128KB = 0x09, // 128K bytes
            _256KB = 0x0A, // 256K bytes
            _512KB = 0x0B, // 512K bytes
            _1MB = 0x0C, // 1M bytes
            _2MB = 0x0D, // 2M bytes
            _4MB = 0x0E, // 4M bytes
            _8MB = 0x0F, // 8M bytes
            _16M = 0x10, // 16M bytes
        };
        CS_ASIZEv(const CS_ASIZE_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Legacy: Chip Select adress space
    class CS_ASPACEv {
    public:
        enum CS_ASPACE_ {
            _256B = 0x00, // 256 bytes
            _512B = 0x01, // 512 bytes
            _1KB = 0x02, // 1K bytes
            _2KB = 0x03, // 2K bytes
            _4KB = 0x04, // 4K bytes
            _8KB = 0x05, // 8K bytes
            _16KB = 0x06, // 16K bytes
            _32KB = 0x07, // 32K bytes
            _64KB = 0x08, // 64K bytes
            _128KB = 0x09, // 128K bytes
            _256KB = 0x0A, // 256K bytes
            _512KB = 0x0B, // 512K bytes
            _1MB = 0x0C, // 1M bytes
            _2MB = 0x0D, // 2M bytes
            _4MB = 0x0E, // 4M bytes
            _8MB = 0x0F, // 8M bytes
            _16M = 0x10, // 16M bytes
        };
        CS_ASPACEv(const CS_ASPACE_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // SRAM Wait State Selection
    class CS_SRWSv {
    public:
        enum CS_SRWS_ {
            _0CLK = 0x00, // 0 cycles
            _1CLK = 0x01, // 1 cycle
            _2CLK = 0x02, // 2 cycles
            _3CLK = 0x03, // 3 cycles
            _4CLK = 0x04, // 4 cycles
            _5CLK = 0x05, // 5 cycles
            _6CLK = 0x06, // 6 cycles
            _7CLK = 0x07, // 7 cycles
        };
        CS_SRWSv(const CS_SRWS_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Chip Select address mode
    class CS_MODEv {
    public:
        enum CS_MODE_ {
            DISABLED = 0x00, // Chip Select Disabled
            SRAM = 0x01, // Chip Select in SRAM mode
            LPC = 0x02, // Chip Select in SRAM LPC mode
            SDRAM = 0x03, // Chip Select in SDRAM mode
        };
        CS_MODEv(const CS_MODE_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Chip Select SDRAM mode
    class CS_SDMODEv {
    public:
        enum CS_SDMODE_ {
            NORMAL = 0x00, // Normal mode
            LOAD = 0x01, // Load Mode Register command mode
        };
        CS_SDMODEv(const CS_SDMODE_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // 
    class SDDATAWv {
    public:
        enum SDDATAW_ {
            _4BIT = 0x00, // 4-bit data bus
            _8BIT = 0x01, // 8-bit data bus
        };
        SDDATAWv(const SDDATAW_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // 
    class LPCMODEv {
    public:
        enum LPCMODE_ {
            ALE1 = 0x00, // Data muxed with addr byte 0
            ALE12 = 0x02, // Data muxed with addr byte 0 and 1
        };
        LPCMODEv(const LPCMODE_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // 
    class SRMODEv {
    public:
        enum SRMODE_ {
            ALE1 = 0x00, // Addr byte 0 muxed with 1
            ALE2 = 0x01, // Addr byte 0 muxed with 2
            ALE12 = 0x02, // Addr byte 0 muxed with 1 and 2
            NOALE = 0x03, // No addr muxing
        };
        SRMODEv(const SRMODE_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // 
    class IFMODEv {
    public:
        enum IFMODE_ {
            DISABLED = 0x00, // EBI Disabled
            _3PORT = 0x01, // 3-port mode
            _4PORT = 0x02, // 4-port mode
            _2PORT = 0x03, // 2-port mode
        };
        IFMODEv(const IFMODE_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // 
    class SDCOLv {
    public:
        enum SDCOL_ {
            _8BIT = 0x00, // 8 column bits
            _9BIT = 0x01, // 9 column bits
            _10BIT = 0x02, // 10 column bits
            _11BIT = 0x03, // 11 column bits
        };
        SDCOLv(const SDCOL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // SDRAM Load Mode to Active delay
    class MRDLYv {
    public:
        enum MRDLY_ {
            _0CLK = 0x00, // 0 cycles
            _1CLK = 0x01, // 1 cycle
            _2CLK = 0x02, // 2 cycles
            _3CLK = 0x03, // 3 cycles
        };
        MRDLYv(const MRDLY_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // SDRAM Row Cycle Delay
    class ROWCYCDLYv {
    public:
        enum ROWCYCDLY_ {
            _0CLK = 0x00, // 0 cycles
            _1CLK = 0x01, // 1 cycle
            _2CLK = 0x02, // 2 cycles
            _3CLK = 0x03, // 3 cycles
            _4CLK = 0x04, // 4 cycles
            _5CLK = 0x05, // 5 cycles
            _6CLK = 0x06, // 6 cycles
            _7CLK = 0x07, // 7 cycles
        };
        ROWCYCDLYv(const ROWCYCDLY_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // SDRAM Row to Precharge Delay
    class RPDLYv {
    public:
        enum RPDLY_ {
            _0CLK = 0x00, // 0 cycles
            _1CLK = 0x01, // 1 cycle
            _2CLK = 0x02, // 2 cycles
            _3CLK = 0x03, // 3 cycles
            _4CLK = 0x04, // 4 cycles
            _5CLK = 0x05, // 5 cycles
            _6CLK = 0x06, // 6 cycles
            _7CLK = 0x07, // 7 cycles
        };
        RPDLYv(const RPDLY_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // SDRAM Write Recovery Delay
    class WRDLYv {
    public:
        enum WRDLY_ {
            _0CLK = 0x00, // 0 cycles
            _1CLK = 0x01, // 1 cycle
            _2CLK = 0x02, // 2 cycles
            _3CLK = 0x03, // 3 cycles
        };
        WRDLYv(const WRDLY_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // SDRAM Exit Self Refresh to Active Delay
    class ESRDLYv {
    public:
        enum ESRDLY_ {
            _0CLK = 0x00, // 0 cycles
            _1CLK = 0x01, // 1 cycle
            _2CLK = 0x02, // 2 cycles
            _3CLK = 0x03, // 3 cycles
            _4CLK = 0x04, // 4 cycles
            _5CLK = 0x05, // 5 cycles
            _6CLK = 0x06, // 6 cycles
            _7CLK = 0x07, // 7 cycles
        };
        ESRDLYv(const ESRDLY_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // SDRAM Row to Column Delay
    class ROWCOLDLYv {
    public:
        enum ROWCOLDLY_ {
            _0CLK = 0x00, // 0 cycles
            _1CLK = 0x01, // 1 cycle
            _2CLK = 0x02, // 2 cycles
            _3CLK = 0x03, // 3 cycles
            _4CLK = 0x04, // 4 cycles
            _5CLK = 0x05, // 5 cycles
            _6CLK = 0x06, // 6 cycles
            _7CLK = 0x07, // 7 cycles
        };
        ROWCOLDLYv(const ROWCOLDLY_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

};

} // namespace device
