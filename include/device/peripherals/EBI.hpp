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
    };
};
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

};

namespace EBI {

    // Chip Select adress size
    class CS_ASIZE {
    private:
        enum CS_ASIZE_ {
            _256B_ = 0x00, // 256 bytes
            _512B_ = 0x01, // 512 bytes
            _1KB_ = 0x02, // 1K bytes
            _2KB_ = 0x03, // 2K bytes
            _4KB_ = 0x04, // 4K bytes
            _8KB_ = 0x05, // 8K bytes
            _16KB_ = 0x06, // 16K bytes
            _32KB_ = 0x07, // 32K bytes
            _64KB_ = 0x08, // 64K bytes
            _128KB_ = 0x09, // 128K bytes
            _256KB_ = 0x0A, // 256K bytes
            _512KB_ = 0x0B, // 512K bytes
            _1MB_ = 0x0C, // 1M bytes
            _2MB_ = 0x0D, // 2M bytes
            _4MB_ = 0x0E, // 4M bytes
            _8MB_ = 0x0F, // 8M bytes
            _16M_ = 0x10, // 16M bytes
        };
        CS_ASIZE_ value_;
    public:
        static const CS_ASIZE _256B, _512B, _1KB, _2KB, _4KB, _8KB, _16KB, _32KB, _64KB, _128KB, _256KB, _512KB, _1MB, _2MB, _4MB, _8MB, _16M;
        explicit CS_ASIZE(const CS_ASIZE_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Legacy: Chip Select adress space
    class CS_ASPACE {
    private:
        enum CS_ASPACE_ {
            _256B_ = 0x00, // 256 bytes
            _512B_ = 0x01, // 512 bytes
            _1KB_ = 0x02, // 1K bytes
            _2KB_ = 0x03, // 2K bytes
            _4KB_ = 0x04, // 4K bytes
            _8KB_ = 0x05, // 8K bytes
            _16KB_ = 0x06, // 16K bytes
            _32KB_ = 0x07, // 32K bytes
            _64KB_ = 0x08, // 64K bytes
            _128KB_ = 0x09, // 128K bytes
            _256KB_ = 0x0A, // 256K bytes
            _512KB_ = 0x0B, // 512K bytes
            _1MB_ = 0x0C, // 1M bytes
            _2MB_ = 0x0D, // 2M bytes
            _4MB_ = 0x0E, // 4M bytes
            _8MB_ = 0x0F, // 8M bytes
            _16M_ = 0x10, // 16M bytes
        };
        CS_ASPACE_ value_;
    public:
        static const CS_ASPACE _256B, _512B, _1KB, _2KB, _4KB, _8KB, _16KB, _32KB, _64KB, _128KB, _256KB, _512KB, _1MB, _2MB, _4MB, _8MB, _16M;
        explicit CS_ASPACE(const CS_ASPACE_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // SRAM Wait State Selection
    class CS_SRWS {
    private:
        enum CS_SRWS_ {
            _0CLK_ = 0x00, // 0 cycles
            _1CLK_ = 0x01, // 1 cycle
            _2CLK_ = 0x02, // 2 cycles
            _3CLK_ = 0x03, // 3 cycles
            _4CLK_ = 0x04, // 4 cycles
            _5CLK_ = 0x05, // 5 cycles
            _6CLK_ = 0x06, // 6 cycles
            _7CLK_ = 0x07, // 7 cycles
        };
        CS_SRWS_ value_;
    public:
        static const CS_SRWS _0CLK, _1CLK, _2CLK, _3CLK, _4CLK, _5CLK, _6CLK, _7CLK;
        explicit CS_SRWS(const CS_SRWS_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Chip Select address mode
    class CS_MODE {
    private:
        enum CS_MODE_ {
            DISABLED_ = 0x00, // Chip Select Disabled
            SRAM_ = 0x01, // Chip Select in SRAM mode
            LPC_ = 0x02, // Chip Select in SRAM LPC mode
            SDRAM_ = 0x03, // Chip Select in SDRAM mode
        };
        CS_MODE_ value_;
    public:
        static const CS_MODE DISABLED, SRAM, LPC, SDRAM;
        explicit CS_MODE(const CS_MODE_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Chip Select SDRAM mode
    class CS_SDMODE {
    private:
        enum CS_SDMODE_ {
            NORMAL_ = 0x00, // Normal mode
            LOAD_ = 0x01, // Load Mode Register command mode
        };
        CS_SDMODE_ value_;
    public:
        static const CS_SDMODE NORMAL, LOAD;
        explicit CS_SDMODE(const CS_SDMODE_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // 
    class SDDATAW {
    private:
        enum SDDATAW_ {
            _4BIT_ = 0x00, // 4-bit data bus
            _8BIT_ = 0x01, // 8-bit data bus
        };
        SDDATAW_ value_;
    public:
        static const SDDATAW _4BIT, _8BIT;
        explicit SDDATAW(const SDDATAW_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // 
    class LPCMODE {
    private:
        enum LPCMODE_ {
            ALE1_ = 0x00, // Data muxed with addr byte 0
            ALE12_ = 0x02, // Data muxed with addr byte 0 and 1
        };
        LPCMODE_ value_;
    public:
        static const LPCMODE ALE1, ALE12;
        explicit LPCMODE(const LPCMODE_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // 
    class SRMODE {
    private:
        enum SRMODE_ {
            ALE1_ = 0x00, // Addr byte 0 muxed with 1
            ALE2_ = 0x01, // Addr byte 0 muxed with 2
            ALE12_ = 0x02, // Addr byte 0 muxed with 1 and 2
            NOALE_ = 0x03, // No addr muxing
        };
        SRMODE_ value_;
    public:
        static const SRMODE ALE1, ALE2, ALE12, NOALE;
        explicit SRMODE(const SRMODE_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // 
    class IFMODE {
    private:
        enum IFMODE_ {
            DISABLED_ = 0x00, // EBI Disabled
            _3PORT_ = 0x01, // 3-port mode
            _4PORT_ = 0x02, // 4-port mode
            _2PORT_ = 0x03, // 2-port mode
        };
        IFMODE_ value_;
    public:
        static const IFMODE DISABLED, _3PORT, _4PORT, _2PORT;
        explicit IFMODE(const IFMODE_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // 
    class SDCOL {
    private:
        enum SDCOL_ {
            _8BIT_ = 0x00, // 8 column bits
            _9BIT_ = 0x01, // 9 column bits
            _10BIT_ = 0x02, // 10 column bits
            _11BIT_ = 0x03, // 11 column bits
        };
        SDCOL_ value_;
    public:
        static const SDCOL _8BIT, _9BIT, _10BIT, _11BIT;
        explicit SDCOL(const SDCOL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // SDRAM Load Mode to Active delay
    class MRDLY {
    private:
        enum MRDLY_ {
            _0CLK_ = 0x00, // 0 cycles
            _1CLK_ = 0x01, // 1 cycle
            _2CLK_ = 0x02, // 2 cycles
            _3CLK_ = 0x03, // 3 cycles
        };
        MRDLY_ value_;
    public:
        static const MRDLY _0CLK, _1CLK, _2CLK, _3CLK;
        explicit MRDLY(const MRDLY_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // SDRAM Row Cycle Delay
    class ROWCYCDLY {
    private:
        enum ROWCYCDLY_ {
            _0CLK_ = 0x00, // 0 cycles
            _1CLK_ = 0x01, // 1 cycle
            _2CLK_ = 0x02, // 2 cycles
            _3CLK_ = 0x03, // 3 cycles
            _4CLK_ = 0x04, // 4 cycles
            _5CLK_ = 0x05, // 5 cycles
            _6CLK_ = 0x06, // 6 cycles
            _7CLK_ = 0x07, // 7 cycles
        };
        ROWCYCDLY_ value_;
    public:
        static const ROWCYCDLY _0CLK, _1CLK, _2CLK, _3CLK, _4CLK, _5CLK, _6CLK, _7CLK;
        explicit ROWCYCDLY(const ROWCYCDLY_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // SDRAM Row to Precharge Delay
    class RPDLY {
    private:
        enum RPDLY_ {
            _0CLK_ = 0x00, // 0 cycles
            _1CLK_ = 0x01, // 1 cycle
            _2CLK_ = 0x02, // 2 cycles
            _3CLK_ = 0x03, // 3 cycles
            _4CLK_ = 0x04, // 4 cycles
            _5CLK_ = 0x05, // 5 cycles
            _6CLK_ = 0x06, // 6 cycles
            _7CLK_ = 0x07, // 7 cycles
        };
        RPDLY_ value_;
    public:
        static const RPDLY _0CLK, _1CLK, _2CLK, _3CLK, _4CLK, _5CLK, _6CLK, _7CLK;
        explicit RPDLY(const RPDLY_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // SDRAM Write Recovery Delay
    class WRDLY {
    private:
        enum WRDLY_ {
            _0CLK_ = 0x00, // 0 cycles
            _1CLK_ = 0x01, // 1 cycle
            _2CLK_ = 0x02, // 2 cycles
            _3CLK_ = 0x03, // 3 cycles
        };
        WRDLY_ value_;
    public:
        static const WRDLY _0CLK, _1CLK, _2CLK, _3CLK;
        explicit WRDLY(const WRDLY_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // SDRAM Exit Self Refresh to Active Delay
    class ESRDLY {
    private:
        enum ESRDLY_ {
            _0CLK_ = 0x00, // 0 cycles
            _1CLK_ = 0x01, // 1 cycle
            _2CLK_ = 0x02, // 2 cycles
            _3CLK_ = 0x03, // 3 cycles
            _4CLK_ = 0x04, // 4 cycles
            _5CLK_ = 0x05, // 5 cycles
            _6CLK_ = 0x06, // 6 cycles
            _7CLK_ = 0x07, // 7 cycles
        };
        ESRDLY_ value_;
    public:
        static const ESRDLY _0CLK, _1CLK, _2CLK, _3CLK, _4CLK, _5CLK, _6CLK, _7CLK;
        explicit ESRDLY(const ESRDLY_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // SDRAM Row to Column Delay
    class ROWCOLDLY {
    private:
        enum ROWCOLDLY_ {
            _0CLK_ = 0x00, // 0 cycles
            _1CLK_ = 0x01, // 1 cycle
            _2CLK_ = 0x02, // 2 cycles
            _3CLK_ = 0x03, // 3 cycles
            _4CLK_ = 0x04, // 4 cycles
            _5CLK_ = 0x05, // 5 cycles
            _6CLK_ = 0x06, // 6 cycles
            _7CLK_ = 0x07, // 7 cycles
        };
        ROWCOLDLY_ value_;
    public:
        static const ROWCOLDLY _0CLK, _1CLK, _2CLK, _3CLK, _4CLK, _5CLK, _6CLK, _7CLK;
        explicit ROWCOLDLY(const ROWCOLDLY_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };


} // namespace EBI
} // namespace device
