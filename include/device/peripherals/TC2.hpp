/**
 * XMEGAAU-TC2 (id I6090)
 * 16-bit Timer/Counter type 2
 *
 *
 */
#pragma once

#include "device/register.hpp"
#include <cstdint>

namespace device {

/**
 * TC2
 * 16-bit Timer/Counter type 2
 * Size: 48 bytes
 */
template <addressType BASE_ADDRESS>
struct TC2_t {

    /// Control Register A - 1 bytes
    struct CTRLA : public reg8_t<BASE_ADDRESS + 0x0000> {
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x0F, 0> CLKSEL;    //< Clock Selection using TC2_CLKSEL
    };

    /// Control Register B - 1 bytes
    struct CTRLB : public reg8_t<BASE_ADDRESS + 0x0001> {
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x80, 7> HCMPDEN;    //< High Byte Compare D Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x40, 6> HCMPCEN;    //< High Byte Compare C Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x20, 5> HCMPBEN;    //< High Byte Compare B Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x10, 4> HCMPAEN;    //< High Byte Compare A Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x08, 3> LCMPDEN;    //< Low Byte Compare D Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x04, 2> LCMPCEN;    //< Low Byte Compare C Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x02, 1> LCMPBEN;    //< Low Byte Compare B Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x01, 0> LCMPAEN;    //< Low Byte Compare A Enable using None
    };

    /// Control register C - 1 bytes
    struct CTRLC : public reg8_t<BASE_ADDRESS + 0x0002> {
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x80, 7> HCMPD;    //< High Byte Compare D Output Value using None
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x40, 6> HCMPC;    //< High Byte Compare C Output Value using None
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x20, 5> HCMPB;    //< High Byte Compare B Output Value using None
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x10, 4> HCMPA;    //< High Byte Compare A Output Value using None
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x08, 3> LCMPD;    //< Low Byte Compare D Output Value using None
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x04, 2> LCMPC;    //< Low Byte Compare C Output Value using None
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x02, 1> LCMPB;    //< Low Byte Compare B Output Value using None
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x01, 0> LCMPA;    //< Low Byte Compare A Output Value using None
    };

    /// Control Register E - 1 bytes
    struct CTRLE : public reg8_t<BASE_ADDRESS + 0x0004> {
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x03, 0> BYTEM;    //< Byte Mode using TC2_BYTEM
    };

    /// Interrupt Control Register A - 1 bytes
    struct INTCTRLA : public reg8_t<BASE_ADDRESS + 0x0006> {
        typedef reg_field_t<BASE_ADDRESS + 0x0006, 0x0C, 2> HUNFINTLVL;    //< High Byte Underflow Interrupt Level using TC2_HUNFINTLVL
        typedef reg_field_t<BASE_ADDRESS + 0x0006, 0x03, 0> LUNFINTLVL;    //< Low Byte Underflow interrupt level using TC2_LUNFINTLVL
    };

    /// Interrupt Control Register B - 1 bytes
    struct INTCTRLB : public reg8_t<BASE_ADDRESS + 0x0007> {
        typedef reg_field_t<BASE_ADDRESS + 0x0007, 0xC0, 6> LCMPDINTLVL;    //< Low Byte Compare D Interrupt Level using TC2_LCMPDINTLVL
        typedef reg_field_t<BASE_ADDRESS + 0x0007, 0x30, 4> LCMPCINTLVL;    //< Low Byte Compare C Interrupt Level using TC2_LCMPCINTLVL
        typedef reg_field_t<BASE_ADDRESS + 0x0007, 0x0C, 2> LCMPBINTLVL;    //< Low Byte Compare B Interrupt Level using TC2_LCMPBINTLVL
        typedef reg_field_t<BASE_ADDRESS + 0x0007, 0x03, 0> LCMPAINTLVL;    //< Low Byte Compare A Interrupt Level using TC2_LCMPAINTLVL
    };

    /// Control Register F - 1 bytes
    struct CTRLF : public reg8_t<BASE_ADDRESS + 0x0009> {
        typedef reg_field_t<BASE_ADDRESS + 0x0009, 0x0C, 2> CMD;    //< Command using TC2_CMD
        typedef reg_field_t<BASE_ADDRESS + 0x0009, 0x03, 0> CMDEN;    //< Command Enable using TC2_CMDEN
    };

    /// Interrupt Flag Register - 1 bytes
    struct INTFLAGS : public reg8_t<BASE_ADDRESS + 0x000C> {
        typedef reg_field_t<BASE_ADDRESS + 0x000C, 0x80, 7> LCMPDIF;    //< Low Byte Compare D Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000C, 0x40, 6> LCMPCIF;    //< Low Byte Compare C Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000C, 0x20, 5> LCMPBIF;    //< Low Byte Compare B Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000C, 0x10, 4> LCMPAIF;    //< Low Byte Compare A Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000C, 0x02, 1> HUNFIF;    //< High Byte Underflow Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000C, 0x01, 0> LUNFIF;    //< Low Byte Underflow Interrupt Flag using None
    };

    /// Low Byte Count - 1 bytes
    struct LCNT : public reg8_t<BASE_ADDRESS + 0x0020> {
    };

    /// High Byte Count - 1 bytes
    struct HCNT : public reg8_t<BASE_ADDRESS + 0x0021> {
    };

    /// Low Byte Period - 1 bytes
    struct LPER : public reg8_t<BASE_ADDRESS + 0x0026> {
    };

    /// High Byte Period - 1 bytes
    struct HPER : public reg8_t<BASE_ADDRESS + 0x0027> {
    };

    /// Low Byte Compare A - 1 bytes
    struct LCMPA : public reg8_t<BASE_ADDRESS + 0x0028> {
    };

    /// High Byte Compare A - 1 bytes
    struct HCMPA : public reg8_t<BASE_ADDRESS + 0x0029> {
    };

    /// Low Byte Compare B - 1 bytes
    struct LCMPB : public reg8_t<BASE_ADDRESS + 0x002A> {
    };

    /// High Byte Compare B - 1 bytes
    struct HCMPB : public reg8_t<BASE_ADDRESS + 0x002B> {
    };

    /// Low Byte Compare C - 1 bytes
    struct LCMPC : public reg8_t<BASE_ADDRESS + 0x002C> {
    };

    /// High Byte Compare C - 1 bytes
    struct HCMPC : public reg8_t<BASE_ADDRESS + 0x002D> {
    };

    /// Low Byte Compare D - 1 bytes
    struct LCMPD : public reg8_t<BASE_ADDRESS + 0x002E> {
    };

    /// High Byte Compare D - 1 bytes
    struct HCMPD : public reg8_t<BASE_ADDRESS + 0x002F> {
    };

    // Clock Selection
    class CLKSELv {
    public:
        enum CLKSEL_ {
            OFF = 0x00, // Timer Off
            DIV1 = 0x01, // System Clock
            DIV2 = 0x02, // System Clock / 2
            DIV4 = 0x03, // System Clock / 4
            DIV8 = 0x04, // System Clock / 8
            DIV64 = 0x05, // System Clock / 64
            DIV256 = 0x06, // System Clock / 256
            DIV1024 = 0x07, // System Clock / 1024
            EVCH0 = 0x08, // Event Channel 0
            EVCH1 = 0x09, // Event Channel 1
            EVCH2 = 0x0A, // Event Channel 2
            EVCH3 = 0x0B, // Event Channel 3
            EVCH4 = 0x0C, // Event Channel 4
            EVCH5 = 0x0D, // Event Channel 5
            EVCH6 = 0x0E, // Event Channel 6
            EVCH7 = 0x0F, // Event Channel 7
        };
        CLKSELv(const CLKSEL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Byte Mode
    class BYTEMv {
    public:
        enum BYTEM_ {
            NORMAL = 0x00, // 16-bit mode
            BYTEMODE = 0x01, // Timer/Counter operating in byte mode only (TC2)
            SPLITMODE = 0x02, // Timer/Counter split into two 8-bit Counters
        };
        BYTEMv(const BYTEM_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // High Byte Underflow Interrupt Level
    class HUNFINTLVLv {
    public:
        enum HUNFINTLVL_ {
            OFF = 0x00, // Interrupt Disabled
            LO = 0x01, // Low Level
            MED = 0x02, // Medium Level
            HI = 0x03, // High Level
        };
        HUNFINTLVLv(const HUNFINTLVL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Low Byte Underflow Interrupt Level
    class LUNFINTLVLv {
    public:
        enum LUNFINTLVL_ {
            OFF = 0x00, // Interrupt Disabled
            LO = 0x01, // Low Level
            MED = 0x02, // Medium Level
            HI = 0x03, // High Level
        };
        LUNFINTLVLv(const LUNFINTLVL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Low Byte Compare D Interrupt Level
    class LCMPDINTLVLv {
    public:
        enum LCMPDINTLVL_ {
            OFF = 0x00, // Interrupt Disabled
            LO = 0x01, // Low Level
            MED = 0x02, // Medium Level
            HI = 0x03, // High Level
        };
        LCMPDINTLVLv(const LCMPDINTLVL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Low Byte Compare C Interrupt Level
    class LCMPCINTLVLv {
    public:
        enum LCMPCINTLVL_ {
            OFF = 0x00, // Interrupt Disabled
            LO = 0x01, // Low Level
            MED = 0x02, // Medium Level
            HI = 0x03, // High Level
        };
        LCMPCINTLVLv(const LCMPCINTLVL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Low Byte Compare B Interrupt Level
    class LCMPBINTLVLv {
    public:
        enum LCMPBINTLVL_ {
            OFF = 0x00, // Interrupt Disabled
            LO = 0x01, // Low Level
            MED = 0x02, // Medium Level
            HI = 0x03, // High Level
        };
        LCMPBINTLVLv(const LCMPBINTLVL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Low Byte Compare A Interrupt Level
    class LCMPAINTLVLv {
    public:
        enum LCMPAINTLVL_ {
            OFF = 0x00, // Interrupt Disabled
            LO = 0x01, // Low Level
            MED = 0x02, // Medium Level
            HI = 0x03, // High Level
        };
        LCMPAINTLVLv(const LCMPAINTLVL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Timer/Counter Command
    class CMDv {
    public:
        enum CMD_ {
            NONE = 0x00, // No Command
            RESTART = 0x02, // Force Restart
            RESET = 0x03, // Force Hard Reset
        };
        CMDv(const CMD_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Timer/Counter Command
    class CMDENv {
    public:
        enum CMDEN_ {
            LOW = 0x01, // Low Byte Timer/Counter
            HIGH = 0x02, // High Byte Timer/Counter
            BOTH = 0x03, // Both Low Byte and High Byte Timer/Counters
        };
        CMDENv(const CMDEN_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // TC2 ISR Vector Offsets (two bytes each)
    class INTERRUPTS {
    public:
        enum INTERRUPTS_ {
            LUNF = 0, // Low Byte Underflow Interrupt
            HUNF = 1, // High Byte Underflow Interrupt
            LCMPA = 2, // Low Byte Compare A Interrupt
            LCMPB = 3, // Low Byte Compare B Interrupt
            LCMPC = 4, // Low Byte Compare C Interrupt
            LCMPD = 5, // Low Byte Compare D Interrupt
        };
        INTERRUPTS(const INTERRUPTS_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

};

} // namespace device
