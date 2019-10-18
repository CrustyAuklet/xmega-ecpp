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
};

namespace TC2 {

    // Clock Selection
    class CLKSEL {
    private:
        enum CLKSEL_ {
            OFF_ = 0x00, // Timer Off
            DIV1_ = 0x01, // System Clock
            DIV2_ = 0x02, // System Clock / 2
            DIV4_ = 0x03, // System Clock / 4
            DIV8_ = 0x04, // System Clock / 8
            DIV64_ = 0x05, // System Clock / 64
            DIV256_ = 0x06, // System Clock / 256
            DIV1024_ = 0x07, // System Clock / 1024
            EVCH0_ = 0x08, // Event Channel 0
            EVCH1_ = 0x09, // Event Channel 1
            EVCH2_ = 0x0A, // Event Channel 2
            EVCH3_ = 0x0B, // Event Channel 3
            EVCH4_ = 0x0C, // Event Channel 4
            EVCH5_ = 0x0D, // Event Channel 5
            EVCH6_ = 0x0E, // Event Channel 6
            EVCH7_ = 0x0F, // Event Channel 7
        };
        CLKSEL_ value_;
    public:
        static const CLKSEL OFF, DIV1, DIV2, DIV4, DIV8, DIV64, DIV256, DIV1024, EVCH0, EVCH1, EVCH2, EVCH3, EVCH4, EVCH5, EVCH6, EVCH7;
        explicit CLKSEL(const CLKSEL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Byte Mode
    class BYTEM {
    private:
        enum BYTEM_ {
            NORMAL_ = 0x00, // 16-bit mode
            BYTEMODE_ = 0x01, // Timer/Counter operating in byte mode only (TC2)
            SPLITMODE_ = 0x02, // Timer/Counter split into two 8-bit Counters
        };
        BYTEM_ value_;
    public:
        static const BYTEM NORMAL, BYTEMODE, SPLITMODE;
        explicit BYTEM(const BYTEM_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // High Byte Underflow Interrupt Level
    class HUNFINTLVL {
    private:
        enum HUNFINTLVL_ {
            OFF_ = 0x00, // Interrupt Disabled
            LO_ = 0x01, // Low Level
            MED_ = 0x02, // Medium Level
            HI_ = 0x03, // High Level
        };
        HUNFINTLVL_ value_;
    public:
        static const HUNFINTLVL OFF, LO, MED, HI;
        explicit HUNFINTLVL(const HUNFINTLVL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Low Byte Underflow Interrupt Level
    class LUNFINTLVL {
    private:
        enum LUNFINTLVL_ {
            OFF_ = 0x00, // Interrupt Disabled
            LO_ = 0x01, // Low Level
            MED_ = 0x02, // Medium Level
            HI_ = 0x03, // High Level
        };
        LUNFINTLVL_ value_;
    public:
        static const LUNFINTLVL OFF, LO, MED, HI;
        explicit LUNFINTLVL(const LUNFINTLVL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Low Byte Compare D Interrupt Level
    class LCMPDINTLVL {
    private:
        enum LCMPDINTLVL_ {
            OFF_ = 0x00, // Interrupt Disabled
            LO_ = 0x01, // Low Level
            MED_ = 0x02, // Medium Level
            HI_ = 0x03, // High Level
        };
        LCMPDINTLVL_ value_;
    public:
        static const LCMPDINTLVL OFF, LO, MED, HI;
        explicit LCMPDINTLVL(const LCMPDINTLVL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Low Byte Compare C Interrupt Level
    class LCMPCINTLVL {
    private:
        enum LCMPCINTLVL_ {
            OFF_ = 0x00, // Interrupt Disabled
            LO_ = 0x01, // Low Level
            MED_ = 0x02, // Medium Level
            HI_ = 0x03, // High Level
        };
        LCMPCINTLVL_ value_;
    public:
        static const LCMPCINTLVL OFF, LO, MED, HI;
        explicit LCMPCINTLVL(const LCMPCINTLVL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Low Byte Compare B Interrupt Level
    class LCMPBINTLVL {
    private:
        enum LCMPBINTLVL_ {
            OFF_ = 0x00, // Interrupt Disabled
            LO_ = 0x01, // Low Level
            MED_ = 0x02, // Medium Level
            HI_ = 0x03, // High Level
        };
        LCMPBINTLVL_ value_;
    public:
        static const LCMPBINTLVL OFF, LO, MED, HI;
        explicit LCMPBINTLVL(const LCMPBINTLVL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Low Byte Compare A Interrupt Level
    class LCMPAINTLVL {
    private:
        enum LCMPAINTLVL_ {
            OFF_ = 0x00, // Interrupt Disabled
            LO_ = 0x01, // Low Level
            MED_ = 0x02, // Medium Level
            HI_ = 0x03, // High Level
        };
        LCMPAINTLVL_ value_;
    public:
        static const LCMPAINTLVL OFF, LO, MED, HI;
        explicit LCMPAINTLVL(const LCMPAINTLVL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Timer/Counter Command
    class CMD {
    private:
        enum CMD_ {
            NONE_ = 0x00, // No Command
            RESTART_ = 0x02, // Force Restart
            RESET_ = 0x03, // Force Hard Reset
        };
        CMD_ value_;
    public:
        static const CMD NONE, RESTART, RESET;
        explicit CMD(const CMD_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Timer/Counter Command
    class CMDEN {
    private:
        enum CMDEN_ {
            LOW_ = 0x01, // Low Byte Timer/Counter
            HIGH_ = 0x02, // High Byte Timer/Counter
            BOTH_ = 0x03, // Both Low Byte and High Byte Timer/Counters
        };
        CMDEN_ value_;
    public:
        static const CMDEN LOW, HIGH, BOTH;
        explicit CMDEN(const CMDEN_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };


    // TC2 Interrupts
    class INTERRUPTS {
    private:
        enum TC2_VECTORS_ {
            LUNF_ = 0, // Low Byte Underflow Interrupt
            HUNF_ = 1, // High Byte Underflow Interrupt
            LCMPA_ = 2, // Low Byte Compare A Interrupt
            LCMPB_ = 3, // Low Byte Compare B Interrupt
            LCMPC_ = 4, // Low Byte Compare C Interrupt
            LCMPD_ = 5, // Low Byte Compare D Interrupt
        };
        TC2_VECTORS_ value_;
    public:
        static const TC2 LUNF, HUNF, LCMPA, LCMPB, LCMPC, LCMPD;
        explicit TC2(const TC2_VECTORS_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

} // namespace TC2
} // namespace device
