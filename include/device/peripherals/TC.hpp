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
    };};

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

    // Waveform Generation Mode
    class WGMODEv {
    public:
        enum WGMODE_ {
            NORMAL = 0x00, // Normal Mode
            FRQ = 0x01, // Frequency Generation Mode
            SINGLESLOPE = 0x03, // Single Slope
            SS = 0x03, // Single Slope
            DSTOP = 0x05, // Dual Slope, Update on TOP
            DS_T = 0x05, // Dual Slope, Update on TOP
            DSBOTH = 0x06, // Dual Slope, Update on both TOP and BOTTOM
            DS_TB = 0x06, // Dual Slope, Update on both TOP and BOTTOM
            DSBOTTOM = 0x07, // Dual Slope, Update on BOTTOM
            DS_B = 0x07, // Dual Slope, Update on BOTTOM
        };
        WGMODEv(const WGMODE_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Byte Mode
    class BYTEMv {
    public:
        enum BYTEM_ {
            NORMAL = 0x00, // 16-bit mode
            BYTEMODE = 0x01, // Timer/Counter operating in byte mode only
            SPLITMODE = 0x02, // Timer/Counter split into two 8-bit Counters (TC2)
        };
        BYTEMv(const BYTEM_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Event Action
    class EVACTv {
    public:
        enum EVACT_ {
            OFF = 0x00, // No Event Action
            CAPT = 0x01, // Input Capture
            UPDOWN = 0x02, // Externally Controlled Up/Down Count
            QDEC = 0x03, // Quadrature Decode
            RESTART = 0x04, // Restart
            FRQ = 0x05, // Frequency Capture
            PW = 0x06, // Pulse-width Capture
        };
        EVACTv(const EVACT_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Event Selection
    class EVSELv {
    public:
        enum EVSEL_ {
            OFF = 0x00, // No Event Source
            CH0 = 0x08, // Event Channel 0
            CH1 = 0x09, // Event Channel 1
            CH2 = 0x0A, // Event Channel 2
            CH3 = 0x0B, // Event Channel 3
            CH4 = 0x0C, // Event Channel 4
            CH5 = 0x0D, // Event Channel 5
            CH6 = 0x0E, // Event Channel 6
            CH7 = 0x0F, // Event Channel 7
        };
        EVSELv(const EVSEL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Error Interrupt Level
    class ERRINTLVLv {
    public:
        enum ERRINTLVL_ {
            OFF = 0x00, // Interrupt Disabled
            LO = 0x01, // Low Level
            MED = 0x02, // Medium Level
            HI = 0x03, // High Level
        };
        ERRINTLVLv(const ERRINTLVL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Overflow Interrupt Level
    class OVFINTLVLv {
    public:
        enum OVFINTLVL_ {
            OFF = 0x00, // Interrupt Disabled
            LO = 0x01, // Low Level
            MED = 0x02, // Medium Level
            HI = 0x03, // High Level
        };
        OVFINTLVLv(const OVFINTLVL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Compare or Capture D Interrupt Level
    class CCDINTLVLv {
    public:
        enum CCDINTLVL_ {
            OFF = 0x00, // Interrupt Disabled
            LO = 0x01, // Low Level
            MED = 0x02, // Medium Level
            HI = 0x03, // High Level
        };
        CCDINTLVLv(const CCDINTLVL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Compare or Capture C Interrupt Level
    class CCCINTLVLv {
    public:
        enum CCCINTLVL_ {
            OFF = 0x00, // Interrupt Disabled
            LO = 0x01, // Low Level
            MED = 0x02, // Medium Level
            HI = 0x03, // High Level
        };
        CCCINTLVLv(const CCCINTLVL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Compare or Capture B Interrupt Level
    class CCBINTLVLv {
    public:
        enum CCBINTLVL_ {
            OFF = 0x00, // Interrupt Disabled
            LO = 0x01, // Low Level
            MED = 0x02, // Medium Level
            HI = 0x03, // High Level
        };
        CCBINTLVLv(const CCBINTLVL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Compare or Capture A Interrupt Level
    class CCAINTLVLv {
    public:
        enum CCAINTLVL_ {
            OFF = 0x00, // Interrupt Disabled
            LO = 0x01, // Low Level
            MED = 0x02, // Medium Level
            HI = 0x03, // High Level
        };
        CCAINTLVLv(const CCAINTLVL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Timer/Counter Command
    class CMDv {
    public:
        enum CMD_ {
            NONE = 0x00, // No Command
            UPDATE = 0x01, // Force Update
            RESTART = 0x02, // Force Restart
            RESET = 0x03, // Force Hard Reset
        };
        CMDv(const CMD_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // TC0 ISR Vector Offsets (two bytes each)
    class INTERRUPTS_TC0 {
    public:
        enum INTERRUPTS_ {
            OVF = 0, // Overflow Interrupt
            ERR = 1, // Error Interrupt
            CCA = 2, // Compare or Capture A Interrupt
            CCB = 3, // Compare or Capture B Interrupt
            CCC = 4, // Compare or Capture C Interrupt
            CCD = 5, // Compare or Capture D Interrupt
        };
        INTERRUPTS_TC0(const INTERRUPTS_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // TC1 ISR Vector Offsets (two bytes each)
    class INTERRUPTS_TC1 {
    public:
        enum INTERRUPTS_ {
            OVF = 0, // Overflow Interrupt
            ERR = 1, // Error Interrupt
            CCA = 2, // Compare or Capture A Interrupt
            CCB = 3, // Compare or Capture B Interrupt
        };
        INTERRUPTS_TC1(const INTERRUPTS_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

};

} // namespace device
