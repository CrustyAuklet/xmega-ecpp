/**
 * XMEGAAU-TC (id I6090)
 * 16-bit Timer/Counter With PWM
 *
 *
 */
#pragma once

#include "device/register.hpp"
#include <cstdint>

namespace device {

/**
 * TC0
 * 16-bit Timer/Counter 0
 * Size: 64 bytes
 */
template <addressType BASE_ADDRESS>
struct TC0_t {

    /// Control  Register A - 1 bytes
    struct CTRLA : public reg8_t<BASE_ADDRESS + 0x0000> {
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x0F, 0> CLKSEL;    //< Clock Selection using TC_CLKSEL
    };

    /// Control Register B - 1 bytes
    struct CTRLB : public reg8_t<BASE_ADDRESS + 0x0001> {
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x80, 7> CCDEN;    //< Compare or Capture D Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x40, 6> CCCEN;    //< Compare or Capture C Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x20, 5> CCBEN;    //< Compare or Capture B Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x10, 4> CCAEN;    //< Compare or Capture A Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x07, 0> WGMODE;    //< Waveform generation mode using TC_WGMODE
    };

    /// Control register C - 1 bytes
    struct CTRLC : public reg8_t<BASE_ADDRESS + 0x0002> {
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x08, 3> CMPD;    //< Compare D Output Value using None
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x04, 2> CMPC;    //< Compare C Output Value using None
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x02, 1> CMPB;    //< Compare B Output Value using None
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x01, 0> CMPA;    //< Compare A Output Value using None
    };

    /// Control Register D - 1 bytes
    struct CTRLD : public reg8_t<BASE_ADDRESS + 0x0003> {
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0xE0, 5> EVACT;    //< Event Action using TC_EVACT
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x10, 4> EVDLY;    //< Event Delay using None
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x0F, 0> EVSEL;    //< Event Source Select using TC_EVSEL
    };

    /// Control Register E - 1 bytes
    struct CTRLE : public reg8_t<BASE_ADDRESS + 0x0004> {
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x03, 0> BYTEM;    //< Byte Mode using TC_BYTEM
    };

    /// Interrupt Control Register A - 1 bytes
    struct INTCTRLA : public reg8_t<BASE_ADDRESS + 0x0006> {
        typedef reg_field_t<BASE_ADDRESS + 0x0006, 0x0C, 2> ERRINTLVL;    //< Error Interrupt Level using TC_ERRINTLVL
        typedef reg_field_t<BASE_ADDRESS + 0x0006, 0x03, 0> OVFINTLVL;    //< Overflow interrupt level using TC_OVFINTLVL
    };

    /// Interrupt Control Register B - 1 bytes
    struct INTCTRLB : public reg8_t<BASE_ADDRESS + 0x0007> {
        typedef reg_field_t<BASE_ADDRESS + 0x0007, 0xC0, 6> CCDINTLVL;    //< Compare or Capture D Interrupt Level using TC_CCDINTLVL
        typedef reg_field_t<BASE_ADDRESS + 0x0007, 0x30, 4> CCCINTLVL;    //< Compare or Capture C Interrupt Level using TC_CCCINTLVL
        typedef reg_field_t<BASE_ADDRESS + 0x0007, 0x0C, 2> CCBINTLVL;    //< Compare or Capture B Interrupt Level using TC_CCBINTLVL
        typedef reg_field_t<BASE_ADDRESS + 0x0007, 0x03, 0> CCAINTLVL;    //< Compare or Capture A Interrupt Level using TC_CCAINTLVL
    };

    /// Control Register F Clear - 1 bytes
    struct CTRLFCLR : public reg8_t<BASE_ADDRESS + 0x0008> {
        typedef reg_field_t<BASE_ADDRESS + 0x0008, 0x0C, 2> CMD;    //< Command using None
        typedef reg_field_t<BASE_ADDRESS + 0x0008, 0x02, 1> LUPD;    //< Lock Update using None
        typedef reg_field_t<BASE_ADDRESS + 0x0008, 0x01, 0> DIR;    //< Direction using None
    };

    /// Control Register F Set - 1 bytes
    struct CTRLFSET : public reg8_t<BASE_ADDRESS + 0x0009> {
        typedef reg_field_t<BASE_ADDRESS + 0x0009, 0x0C, 2> CMD;    //< Command using TC_CMD
        typedef reg_field_t<BASE_ADDRESS + 0x0009, 0x02, 1> LUPD;    //< Lock Update using None
        typedef reg_field_t<BASE_ADDRESS + 0x0009, 0x01, 0> DIR;    //< Direction using None
    };

    /// Control Register G Clear - 1 bytes
    struct CTRLGCLR : public reg8_t<BASE_ADDRESS + 0x000A> {
        typedef reg_field_t<BASE_ADDRESS + 0x000A, 0x10, 4> CCDBV;    //< Compare or Capture D Buffer Valid using None
        typedef reg_field_t<BASE_ADDRESS + 0x000A, 0x08, 3> CCCBV;    //< Compare or Capture C Buffer Valid using None
        typedef reg_field_t<BASE_ADDRESS + 0x000A, 0x04, 2> CCBBV;    //< Compare or Capture B Buffer Valid using None
        typedef reg_field_t<BASE_ADDRESS + 0x000A, 0x02, 1> CCABV;    //< Compare or Capture A Buffer Valid using None
        typedef reg_field_t<BASE_ADDRESS + 0x000A, 0x01, 0> PERBV;    //< Period Buffer Valid using None
    };

    /// Control Register G Set - 1 bytes
    struct CTRLGSET : public reg8_t<BASE_ADDRESS + 0x000B> {
        typedef reg_field_t<BASE_ADDRESS + 0x000B, 0x10, 4> CCDBV;    //< Compare or Capture D Buffer Valid using None
        typedef reg_field_t<BASE_ADDRESS + 0x000B, 0x08, 3> CCCBV;    //< Compare or Capture C Buffer Valid using None
        typedef reg_field_t<BASE_ADDRESS + 0x000B, 0x04, 2> CCBBV;    //< Compare or Capture B Buffer Valid using None
        typedef reg_field_t<BASE_ADDRESS + 0x000B, 0x02, 1> CCABV;    //< Compare or Capture A Buffer Valid using None
        typedef reg_field_t<BASE_ADDRESS + 0x000B, 0x01, 0> PERBV;    //< Period Buffer Valid using None
    };

    /// Interrupt Flag Register - 1 bytes
    struct INTFLAGS : public reg8_t<BASE_ADDRESS + 0x000C> {
        typedef reg_field_t<BASE_ADDRESS + 0x000C, 0x80, 7> CCDIF;    //< Compare or Capture D Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000C, 0x40, 6> CCCIF;    //< Compare or Capture C Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000C, 0x20, 5> CCBIF;    //< Compare or Capture B Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000C, 0x10, 4> CCAIF;    //< Compare or Capture A Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000C, 0x02, 1> ERRIF;    //< Error Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000C, 0x01, 0> OVFIF;    //< Overflow Interrupt Flag using None
    };

    /// Temporary Register For 16-bit Access - 1 bytes
    struct TEMP : public reg8_t<BASE_ADDRESS + 0x000F> {
    };

    /// Count - 2 bytes
    struct CNT : public reg16_t<BASE_ADDRESS + 0x0020> {
    };

    /// Period - 2 bytes
    struct PER : public reg16_t<BASE_ADDRESS + 0x0026> {
    };

    /// Compare or Capture A - 2 bytes
    struct CCA : public reg16_t<BASE_ADDRESS + 0x0028> {
    };

    /// Compare or Capture B - 2 bytes
    struct CCB : public reg16_t<BASE_ADDRESS + 0x002A> {
    };

    /// Compare or Capture C - 2 bytes
    struct CCC : public reg16_t<BASE_ADDRESS + 0x002C> {
    };

    /// Compare or Capture D - 2 bytes
    struct CCD : public reg16_t<BASE_ADDRESS + 0x002E> {
    };

    /// Period Buffer - 2 bytes
    struct PERBUF : public reg16_t<BASE_ADDRESS + 0x0036> {
    };

    /// Compare Or Capture A Buffer - 2 bytes
    struct CCABUF : public reg16_t<BASE_ADDRESS + 0x0038> {
    };

    /// Compare Or Capture B Buffer - 2 bytes
    struct CCBBUF : public reg16_t<BASE_ADDRESS + 0x003A> {
    };

    /// Compare Or Capture C Buffer - 2 bytes
    struct CCCBUF : public reg16_t<BASE_ADDRESS + 0x003C> {
    };

    /// Compare Or Capture D Buffer - 2 bytes
    struct CCDBUF : public reg16_t<BASE_ADDRESS + 0x003E> {
    };
};
/**
 * TC1
 * 16-bit Timer/Counter 1
 * Size: 60 bytes
 */
template <addressType BASE_ADDRESS>
struct TC1_t {

    /// Control  Register A - 1 bytes
    struct CTRLA : public reg8_t<BASE_ADDRESS + 0x0000> {
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x0F, 0> CLKSEL;    //< Clock Selection using TC_CLKSEL
    };

    /// Control Register B - 1 bytes
    struct CTRLB : public reg8_t<BASE_ADDRESS + 0x0001> {
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x20, 5> CCBEN;    //< Compare or Capture B Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x10, 4> CCAEN;    //< Compare or Capture A Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x07, 0> WGMODE;    //< Waveform generation mode using TC_WGMODE
    };

    /// Control register C - 1 bytes
    struct CTRLC : public reg8_t<BASE_ADDRESS + 0x0002> {
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x02, 1> CMPB;    //< Compare B Output Value using None
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x01, 0> CMPA;    //< Compare A Output Value using None
    };

    /// Control Register D - 1 bytes
    struct CTRLD : public reg8_t<BASE_ADDRESS + 0x0003> {
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0xE0, 5> EVACT;    //< Event Action using TC_EVACT
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x10, 4> EVDLY;    //< Event Delay using None
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x0F, 0> EVSEL;    //< Event Source Select using TC_EVSEL
    };

    /// Control Register E - 1 bytes
    struct CTRLE : public reg8_t<BASE_ADDRESS + 0x0004> {
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x01, 0> BYTEM;    //< Byte Mode using None
    };

    /// Interrupt Control Register A - 1 bytes
    struct INTCTRLA : public reg8_t<BASE_ADDRESS + 0x0006> {
        typedef reg_field_t<BASE_ADDRESS + 0x0006, 0x0C, 2> ERRINTLVL;    //< Error Interrupt Level using TC_ERRINTLVL
        typedef reg_field_t<BASE_ADDRESS + 0x0006, 0x03, 0> OVFINTLVL;    //< Overflow interrupt level using TC_OVFINTLVL
    };

    /// Interrupt Control Register B - 1 bytes
    struct INTCTRLB : public reg8_t<BASE_ADDRESS + 0x0007> {
        typedef reg_field_t<BASE_ADDRESS + 0x0007, 0x0C, 2> CCBINTLVL;    //< Compare or Capture B Interrupt Level using TC_CCBINTLVL
        typedef reg_field_t<BASE_ADDRESS + 0x0007, 0x03, 0> CCAINTLVL;    //< Compare or Capture A Interrupt Level using TC_CCAINTLVL
    };

    /// Control Register F Clear - 1 bytes
    struct CTRLFCLR : public reg8_t<BASE_ADDRESS + 0x0008> {
        typedef reg_field_t<BASE_ADDRESS + 0x0008, 0x0C, 2> CMD;    //< Command using None
        typedef reg_field_t<BASE_ADDRESS + 0x0008, 0x02, 1> LUPD;    //< Lock Update using None
        typedef reg_field_t<BASE_ADDRESS + 0x0008, 0x01, 0> DIR;    //< Direction using None
    };

    /// Control Register F Set - 1 bytes
    struct CTRLFSET : public reg8_t<BASE_ADDRESS + 0x0009> {
        typedef reg_field_t<BASE_ADDRESS + 0x0009, 0x0C, 2> CMD;    //< Command using TC_CMD
        typedef reg_field_t<BASE_ADDRESS + 0x0009, 0x02, 1> LUPD;    //< Lock Update using None
        typedef reg_field_t<BASE_ADDRESS + 0x0009, 0x01, 0> DIR;    //< Direction using None
    };

    /// Control Register G Clear - 1 bytes
    struct CTRLGCLR : public reg8_t<BASE_ADDRESS + 0x000A> {
        typedef reg_field_t<BASE_ADDRESS + 0x000A, 0x04, 2> CCBBV;    //< Compare or Capture B Buffer Valid using None
        typedef reg_field_t<BASE_ADDRESS + 0x000A, 0x02, 1> CCABV;    //< Compare or Capture A Buffer Valid using None
        typedef reg_field_t<BASE_ADDRESS + 0x000A, 0x01, 0> PERBV;    //< Period Buffer Valid using None
    };

    /// Control Register G Set - 1 bytes
    struct CTRLGSET : public reg8_t<BASE_ADDRESS + 0x000B> {
        typedef reg_field_t<BASE_ADDRESS + 0x000B, 0x04, 2> CCBBV;    //< Compare or Capture B Buffer Valid using None
        typedef reg_field_t<BASE_ADDRESS + 0x000B, 0x02, 1> CCABV;    //< Compare or Capture A Buffer Valid using None
        typedef reg_field_t<BASE_ADDRESS + 0x000B, 0x01, 0> PERBV;    //< Period Buffer Valid using None
    };

    /// Interrupt Flag Register - 1 bytes
    struct INTFLAGS : public reg8_t<BASE_ADDRESS + 0x000C> {
        typedef reg_field_t<BASE_ADDRESS + 0x000C, 0x20, 5> CCBIF;    //< Compare or Capture B Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000C, 0x10, 4> CCAIF;    //< Compare or Capture A Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000C, 0x02, 1> ERRIF;    //< Error Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000C, 0x01, 0> OVFIF;    //< Overflow Interrupt Flag using None
    };

    /// Temporary Register For 16-bit Access - 1 bytes
    struct TEMP : public reg8_t<BASE_ADDRESS + 0x000F> {
    };

    /// Count - 2 bytes
    struct CNT : public reg16_t<BASE_ADDRESS + 0x0020> {
    };

    /// Period - 2 bytes
    struct PER : public reg16_t<BASE_ADDRESS + 0x0026> {
    };

    /// Compare or Capture A - 2 bytes
    struct CCA : public reg16_t<BASE_ADDRESS + 0x0028> {
    };

    /// Compare or Capture B - 2 bytes
    struct CCB : public reg16_t<BASE_ADDRESS + 0x002A> {
    };

    /// Period Buffer - 2 bytes
    struct PERBUF : public reg16_t<BASE_ADDRESS + 0x0036> {
    };

    /// Compare Or Capture A Buffer - 2 bytes
    struct CCABUF : public reg16_t<BASE_ADDRESS + 0x0038> {
    };

    /// Compare Or Capture B Buffer - 2 bytes
    struct CCBBUF : public reg16_t<BASE_ADDRESS + 0x003A> {
    };
};

namespace TC {

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

    // Waveform Generation Mode
    class WGMODE {
    private:
        enum WGMODE_ {
            NORMAL_ = 0x00, // Normal Mode
            FRQ_ = 0x01, // Frequency Generation Mode
            SINGLESLOPE_ = 0x03, // Single Slope
            SS_ = 0x03, // Single Slope
            DSTOP_ = 0x05, // Dual Slope, Update on TOP
            DS_T_ = 0x05, // Dual Slope, Update on TOP
            DSBOTH_ = 0x06, // Dual Slope, Update on both TOP and BOTTOM
            DS_TB_ = 0x06, // Dual Slope, Update on both TOP and BOTTOM
            DSBOTTOM_ = 0x07, // Dual Slope, Update on BOTTOM
            DS_B_ = 0x07, // Dual Slope, Update on BOTTOM
        };
        WGMODE_ value_;
    public:
        static const WGMODE NORMAL, FRQ, SINGLESLOPE, SS, DSTOP, DS_T, DSBOTH, DS_TB, DSBOTTOM, DS_B;
        explicit WGMODE(const WGMODE_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Byte Mode
    class BYTEM {
    private:
        enum BYTEM_ {
            NORMAL_ = 0x00, // 16-bit mode
            BYTEMODE_ = 0x01, // Timer/Counter operating in byte mode only
            SPLITMODE_ = 0x02, // Timer/Counter split into two 8-bit Counters (TC2)
        };
        BYTEM_ value_;
    public:
        static const BYTEM NORMAL, BYTEMODE, SPLITMODE;
        explicit BYTEM(const BYTEM_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Event Action
    class EVACT {
    private:
        enum EVACT_ {
            OFF_ = 0x00, // No Event Action
            CAPT_ = 0x01, // Input Capture
            UPDOWN_ = 0x02, // Externally Controlled Up/Down Count
            QDEC_ = 0x03, // Quadrature Decode
            RESTART_ = 0x04, // Restart
            FRQ_ = 0x05, // Frequency Capture
            PW_ = 0x06, // Pulse-width Capture
        };
        EVACT_ value_;
    public:
        static const EVACT OFF, CAPT, UPDOWN, QDEC, RESTART, FRQ, PW;
        explicit EVACT(const EVACT_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Event Selection
    class EVSEL {
    private:
        enum EVSEL_ {
            OFF_ = 0x00, // No Event Source
            CH0_ = 0x08, // Event Channel 0
            CH1_ = 0x09, // Event Channel 1
            CH2_ = 0x0A, // Event Channel 2
            CH3_ = 0x0B, // Event Channel 3
            CH4_ = 0x0C, // Event Channel 4
            CH5_ = 0x0D, // Event Channel 5
            CH6_ = 0x0E, // Event Channel 6
            CH7_ = 0x0F, // Event Channel 7
        };
        EVSEL_ value_;
    public:
        static const EVSEL OFF, CH0, CH1, CH2, CH3, CH4, CH5, CH6, CH7;
        explicit EVSEL(const EVSEL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Error Interrupt Level
    class ERRINTLVL {
    private:
        enum ERRINTLVL_ {
            OFF_ = 0x00, // Interrupt Disabled
            LO_ = 0x01, // Low Level
            MED_ = 0x02, // Medium Level
            HI_ = 0x03, // High Level
        };
        ERRINTLVL_ value_;
    public:
        static const ERRINTLVL OFF, LO, MED, HI;
        explicit ERRINTLVL(const ERRINTLVL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Overflow Interrupt Level
    class OVFINTLVL {
    private:
        enum OVFINTLVL_ {
            OFF_ = 0x00, // Interrupt Disabled
            LO_ = 0x01, // Low Level
            MED_ = 0x02, // Medium Level
            HI_ = 0x03, // High Level
        };
        OVFINTLVL_ value_;
    public:
        static const OVFINTLVL OFF, LO, MED, HI;
        explicit OVFINTLVL(const OVFINTLVL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Compare or Capture D Interrupt Level
    class CCDINTLVL {
    private:
        enum CCDINTLVL_ {
            OFF_ = 0x00, // Interrupt Disabled
            LO_ = 0x01, // Low Level
            MED_ = 0x02, // Medium Level
            HI_ = 0x03, // High Level
        };
        CCDINTLVL_ value_;
    public:
        static const CCDINTLVL OFF, LO, MED, HI;
        explicit CCDINTLVL(const CCDINTLVL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Compare or Capture C Interrupt Level
    class CCCINTLVL {
    private:
        enum CCCINTLVL_ {
            OFF_ = 0x00, // Interrupt Disabled
            LO_ = 0x01, // Low Level
            MED_ = 0x02, // Medium Level
            HI_ = 0x03, // High Level
        };
        CCCINTLVL_ value_;
    public:
        static const CCCINTLVL OFF, LO, MED, HI;
        explicit CCCINTLVL(const CCCINTLVL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Compare or Capture B Interrupt Level
    class CCBINTLVL {
    private:
        enum CCBINTLVL_ {
            OFF_ = 0x00, // Interrupt Disabled
            LO_ = 0x01, // Low Level
            MED_ = 0x02, // Medium Level
            HI_ = 0x03, // High Level
        };
        CCBINTLVL_ value_;
    public:
        static const CCBINTLVL OFF, LO, MED, HI;
        explicit CCBINTLVL(const CCBINTLVL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Compare or Capture A Interrupt Level
    class CCAINTLVL {
    private:
        enum CCAINTLVL_ {
            OFF_ = 0x00, // Interrupt Disabled
            LO_ = 0x01, // Low Level
            MED_ = 0x02, // Medium Level
            HI_ = 0x03, // High Level
        };
        CCAINTLVL_ value_;
    public:
        static const CCAINTLVL OFF, LO, MED, HI;
        explicit CCAINTLVL(const CCAINTLVL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Timer/Counter Command
    class CMD {
    private:
        enum CMD_ {
            NONE_ = 0x00, // No Command
            UPDATE_ = 0x01, // Force Update
            RESTART_ = 0x02, // Force Restart
            RESET_ = 0x03, // Force Hard Reset
        };
        CMD_ value_;
    public:
        static const CMD NONE, UPDATE, RESTART, RESET;
        explicit CMD(const CMD_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };


    // TC0 Interrupts
    class INTERRUPTS {
    private:
        enum TC0_VECTORS_ {
            OVF_ = 0, // Overflow Interrupt
            ERR_ = 1, // Error Interrupt
            CCA_ = 2, // Compare or Capture A Interrupt
            CCB_ = 3, // Compare or Capture B Interrupt
            CCC_ = 4, // Compare or Capture C Interrupt
            CCD_ = 5, // Compare or Capture D Interrupt
        };
        TC0_VECTORS_ value_;
    public:
        static const TC0 OVF, ERR, CCA, CCB, CCC, CCD;
        explicit TC0(const TC0_VECTORS_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // TC1 Interrupts
    class INTERRUPTS {
    private:
        enum TC1_VECTORS_ {
            OVF_ = 0, // Overflow Interrupt
            ERR_ = 1, // Error Interrupt
            CCA_ = 2, // Compare or Capture A Interrupt
            CCB_ = 3, // Compare or Capture B Interrupt
        };
        TC1_VECTORS_ value_;
    public:
        static const TC1 OVF, ERR, CCA, CCB;
        explicit TC1(const TC1_VECTORS_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

} // namespace TC
} // namespace device
