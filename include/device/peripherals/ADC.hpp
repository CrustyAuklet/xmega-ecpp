/**
 * XMEGAAU-ADC (id I6099)
 * Analog/Digital Converter
 *
 *
 */
#pragma once

#include "device/register.hpp"
#include <cstdint>

namespace device {

/**
 * ADC_CH
 * ADC Channel
 * Size: 8 bytes
 */
template <addressType BASE_ADDRESS>
struct ADC_CH_t {

    /// Control Register - 1 bytes
    struct CTRL : public reg8_t<BASE_ADDRESS + 0x0000> {
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x80, 7> START;    //< Channel Start Conversion using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x1C, 2> GAIN;    //< Gain Factor using ADC_CH_GAIN
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x03, 0> INPUTMODE;    //< Input Mode Select using ADC_CH_INPUTMODE
    };

    /// MUX Control - 1 bytes
    struct MUXCTRL : public reg8_t<BASE_ADDRESS + 0x0001> {
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x78, 3> MUXPOS;    //< MUX selection on Positive ADC input using ADC_CH_MUXPOS
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x78, 3> MUXINT;    //< MUX selection on Internal ADC input using ADC_CH_MUXINT
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x07, 0> MUXNEG;    //< MUX selection on Negative ADC input using ADC_CH_MUXNEG
    };

    /// Channel Interrupt Control Register - 1 bytes
    struct INTCTRL : public reg8_t<BASE_ADDRESS + 0x0002> {
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x0C, 2> INTMODE;    //< Interrupt Mode using ADC_CH_INTMODE
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x03, 0> INTLVL;    //< Interrupt Level using ADC_CH_INTLVL
    };

    /// Interrupt Flags - 1 bytes
    struct INTFLAGS : public reg8_t<BASE_ADDRESS + 0x0003> {
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x01, 0> CHIF;    //< Channel Interrupt Flag using None
    };

    /// Channel Result - 2 bytes
    struct RES : public reg16_t<BASE_ADDRESS + 0x0004> {
    };

    /// Input Channel Scan - 1 bytes
    struct SCAN : public reg8_t<BASE_ADDRESS + 0x0006> {
        typedef reg_field_t<BASE_ADDRESS + 0x0006, 0xF0, 4> OFFSET;    //< Positive MUX setting offset using None
        typedef reg_field_t<BASE_ADDRESS + 0x0006, 0x0F, 0> SCANNUM;    //< Number of Channels included in scan using None
    };};

/**
 * ADC
 * Analog-to-Digital Converter
 * Size: 64 bytes
 */
template <addressType BASE_ADDRESS>
struct ADC_t {

    /// Control Register A - 1 bytes
    struct CTRLA : public reg8_t<BASE_ADDRESS + 0x0000> {
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0xC0, 6> DMASEL;    //< DMA Selection using ADC_DMASEL
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x20, 5> CH3START;    //< Channel 3 Start Conversion using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x10, 4> CH2START;    //< Channel 2 Start Conversion using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x08, 3> CH1START;    //< Channel 1 Start Conversion using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x04, 2> CH0START;    //< Channel 0 Start Conversion using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x02, 1> FLUSH;    //< Flush Pipeline using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x01, 0> ENABLE;    //< Enable ADC using None
    };

    /// Control Register B - 1 bytes
    struct CTRLB : public reg8_t<BASE_ADDRESS + 0x0001> {
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x80, 7> IMPMODE;    //< Gain Stage Impedance Mode using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x60, 5> CURRLIMIT;    //< Current Limitation using ADC_CURRLIMIT
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x10, 4> CONMODE;    //< Conversion Mode using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x08, 3> FREERUN;    //< Free Running Mode Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x06, 1> RESOLUTION;    //< Result Resolution using ADC_RESOLUTION
    };

    /// Reference Control - 1 bytes
    struct REFCTRL : public reg8_t<BASE_ADDRESS + 0x0002> {
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x70, 4> REFSEL;    //< Reference Selection using ADC_REFSEL
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x02, 1> BANDGAP;    //< Bandgap enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x01, 0> TEMPREF;    //< Temperature Reference Enable using None
    };

    /// Event Control - 1 bytes
    struct EVCTRL : public reg8_t<BASE_ADDRESS + 0x0003> {
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0xC0, 6> SWEEP;    //< Channel Sweep Selection using ADC_SWEEP
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x38, 3> EVSEL;    //< Event Input Select using ADC_EVSEL
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x07, 0> EVACT;    //< Event Action Select using ADC_EVACT
    };

    /// Clock Prescaler - 1 bytes
    struct PRESCALER : public reg8_t<BASE_ADDRESS + 0x0004> {
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x07, 0> PRESCALER;    //< Clock Prescaler Selection using ADC_PRESCALER
    };

    /// Interrupt Flags - 1 bytes
    struct INTFLAGS : public reg8_t<BASE_ADDRESS + 0x0006> {
        typedef reg_field_t<BASE_ADDRESS + 0x0006, 0x08, 3> CH3IF;    //< Channel 3 Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0006, 0x04, 2> CH2IF;    //< Channel 2 Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0006, 0x02, 1> CH1IF;    //< Channel 1 Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0006, 0x01, 0> CH0IF;    //< Channel 0 Interrupt Flag using None
    };

    /// Temporary Register - 1 bytes
    struct TEMP : public reg8_t<BASE_ADDRESS + 0x0007> {
    };

    /// Calibration Value - 2 bytes
    struct CAL : public reg16_t<BASE_ADDRESS + 0x000C> {
    };

    /// Channel 0 Result - 2 bytes
    struct CH0RES : public reg16_t<BASE_ADDRESS + 0x0010> {
    };

    /// Channel 1 Result - 2 bytes
    struct CH1RES : public reg16_t<BASE_ADDRESS + 0x0012> {
    };

    /// Channel 2 Result - 2 bytes
    struct CH2RES : public reg16_t<BASE_ADDRESS + 0x0014> {
    };

    /// Channel 3 Result - 2 bytes
    struct CH3RES : public reg16_t<BASE_ADDRESS + 0x0016> {
    };

    /// Compare Value - 2 bytes
    struct CMP : public reg16_t<BASE_ADDRESS + 0x0018> {
    };
    /// ADC Channel 0
    ADC_CH_t<BASE_ADDRESS + 0x0020> CH0;

    /// ADC Channel 1
    ADC_CH_t<BASE_ADDRESS + 0x0028> CH1;

    /// ADC Channel 2
    ADC_CH_t<BASE_ADDRESS + 0x0030> CH2;

    /// ADC Channel 3
    ADC_CH_t<BASE_ADDRESS + 0x0038> CH3;


    // Positive input multiplexer selection
    class CH_MUXPOSv {
    public:
        enum CH_MUXPOS_ {
            PIN0 = 0x00, // Input pin 0
            PIN1 = 0x01, // Input pin 1
            PIN2 = 0x02, // Input pin 2
            PIN3 = 0x03, // Input pin 3
            PIN4 = 0x04, // Input pin 4
            PIN5 = 0x05, // Input pin 5
            PIN6 = 0x06, // Input pin 6
            PIN7 = 0x07, // Input pin 7
            PIN8 = 0x08, // Input pin 8
            PIN9 = 0x09, // Input pin 9
            PIN10 = 0x0A, // Input pin 10
            PIN11 = 0x0B, // Input pin 11
            PIN12 = 0x0C, // Input pin 12
            PIN13 = 0x0D, // Input pin 13
            PIN14 = 0x0E, // Input pin 14
            PIN15 = 0x0F, // Input pin 15
        };
        CH_MUXPOSv(const CH_MUXPOS_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Internal input multiplexer selections
    class CH_MUXINTv {
    public:
        enum CH_MUXINT_ {
            TEMP = 0x00, // Temperature Reference
            BANDGAP = 0x01, // Bandgap Reference
            SCALEDVCC = 0x02, // 1/10 scaled VCC
            DAC = 0x03, // DAC output
        };
        CH_MUXINTv(const CH_MUXINT_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Negative input multiplexer selection
    class CH_MUXNEGv {
    public:
        enum CH_MUXNEG_ {
            PIN0 = 0x00, // Input pin 0 (Input Mode = 2)
            PIN1 = 0x01, // Input pin 1 (Input Mode = 2)
            PIN2 = 0x02, // Input pin 2 (Input Mode = 2)
            PIN3 = 0x03, // Input pin 3 (Input Mode = 2)
            PIN4 = 0x00, // Input pin 4 (Input Mode = 3)
            PIN5 = 0x01, // Input pin 5 (Input Mode = 3)
            PIN6 = 0x02, // Input pin 6 (Input Mode = 3)
            PIN7 = 0x03, // Input pin 7 (Input Mode = 3)
            GND_MODE3 = 0x05, // PAD Ground (Input Mode = 2)
            INTGND_MODE3 = 0x07, // Internal Ground (Input Mode = 2)
            INTGND_MODE4 = 0x04, // Internal Ground (Input Mode = 3)
            GND_MODE4 = 0x07, // PAD Ground (Input Mode = 3)
        };
        CH_MUXNEGv(const CH_MUXNEG_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Input mode
    class CH_INPUTMODEv {
    public:
        enum CH_INPUTMODE_ {
            INTERNAL = 0x00, // Internal inputs, no gain
            SINGLEENDED = 0x01, // Single-ended input, no gain
            DIFF = 0x02, // Differential input, no gain
            DIFFWGAIN = 0x03, // Differential input, with gain
        };
        CH_INPUTMODEv(const CH_INPUTMODE_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Gain factor
    class CH_GAINv {
    public:
        enum CH_GAIN_ {
            _1X = 0x00, // 1x gain
            _2X = 0x01, // 2x gain
            _4X = 0x02, // 4x gain
            _8X = 0x03, // 8x gain
            _16X = 0x04, // 16x gain
            _32X = 0x05, // 32x gain
            _64X = 0x06, // 64x gain
            DIV2 = 0x07, // x/2 gain
        };
        CH_GAINv(const CH_GAIN_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Conversion result resolution
    class RESOLUTIONv {
    public:
        enum RESOLUTION_ {
            _12BIT = 0x00, // 12-bit right-adjusted result
            _8BIT = 0x02, // 8-bit right-adjusted result
            LEFT12BIT = 0x03, // 12-bit left-adjusted result
        };
        RESOLUTIONv(const RESOLUTION_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Current Limitation Mode
    class CURRLIMITv {
    public:
        enum CURRLIMIT_ {
            NO = 0x00, // No limit
            LOW = 0x01, // Low current limit, max. sampling rate 1.5MSPS
            MED = 0x02, // Medium current limit, max. sampling rate 1MSPS
            HIGH = 0x03, // High current limit, max. sampling rate 0.5MSPS
        };
        CURRLIMITv(const CURRLIMIT_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Voltage reference selection
    class REFSELv {
    public:
        enum REFSEL_ {
            INT1V = 0x00, // Internal 1V
            INTVCC = 0x01, // Internal VCC / 1.6
            AREFA = 0x02, // External reference on PORT A
            AREFB = 0x03, // External reference on PORT B
            INTVCC2 = 0x04, // Internal VCC / 2
        };
        REFSELv(const REFSEL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Channel sweep selection
    class SWEEPv {
    public:
        enum SWEEP_ {
            _0 = 0x00, // ADC Channel 0
            _01 = 0x01, // ADC Channel 0,1
            _012 = 0x02, // ADC Channel 0,1,2
            _0123 = 0x03, // ADC Channel 0,1,2,3
        };
        SWEEPv(const SWEEP_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Event channel input selection
    class EVSELv {
    public:
        enum EVSEL_ {
            _0123 = 0x00, // Event Channel 0,1,2,3
            _1234 = 0x01, // Event Channel 1,2,3,4
            _2345 = 0x02, // Event Channel 2,3,4,5
            _3456 = 0x03, // Event Channel 3,4,5,6
            _4567 = 0x04, // Event Channel 4,5,6,7
            _567 = 0x05, // Event Channel 5,6,7
            _67 = 0x06, // Event Channel 6,7
            _7 = 0x07, // Event Channel 7
        };
        EVSELv(const EVSEL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Event action selection
    class EVACTv {
    public:
        enum EVACT_ {
            NONE = 0x00, // No event action
            CH0 = 0x01, // First event triggers channel 0
            CH01 = 0x02, // First two events trigger channel 0,1
            CH012 = 0x03, // First three events trigger channel 0,1,2
            CH0123 = 0x04, // Events trigger channel 0,1,2,3
            SWEEP = 0x05, // First event triggers sweep
            SYNCSWEEP = 0x06, // The ADC is flushed and restarted for accurate timing
        };
        EVACTv(const EVACT_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Interupt mode
    class CH_INTMODEv {
    public:
        enum CH_INTMODE_ {
            COMPLETE = 0x00, // Interrupt on conversion complete
            BELOW = 0x01, // Interrupt on result below compare value
            ABOVE = 0x03, // Interrupt on result above compare value
        };
        CH_INTMODEv(const CH_INTMODE_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Interrupt level
    class CH_INTLVLv {
    public:
        enum CH_INTLVL_ {
            OFF = 0x00, // Interrupt disabled
            LO = 0x01, // Low level
            MED = 0x02, // Medium level
            HI = 0x03, // High level
        };
        CH_INTLVLv(const CH_INTLVL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // DMA request selection
    class DMASELv {
    public:
        enum DMASEL_ {
            OFF = 0x00, // Combined DMA request OFF
            CH01 = 0x01, // ADC Channel 0 or 1
            CH012 = 0x02, // ADC Channel 0 or 1 or 2
            CH0123 = 0x03, // ADC Channel 0 or 1 or 2 or 3
        };
        DMASELv(const DMASEL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Clock prescaler
    class PRESCALERv {
    public:
        enum PRESCALER_ {
            DIV4 = 0x00, // Divide clock by 4
            DIV8 = 0x01, // Divide clock by 8
            DIV16 = 0x02, // Divide clock by 16
            DIV32 = 0x03, // Divide clock by 32
            DIV64 = 0x04, // Divide clock by 64
            DIV128 = 0x05, // Divide clock by 128
            DIV256 = 0x06, // Divide clock by 256
            DIV512 = 0x07, // Divide clock by 512
        };
        PRESCALERv(const PRESCALER_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // ADC ISR Vector Offsets (two bytes each)
    class INTERRUPTS {
    public:
        enum INTERRUPTS_ {
            CH0 = 0, // Interrupt 0
            CH1 = 1, // Interrupt 1
            CH2 = 2, // Interrupt 2
            CH3 = 3, // Interrupt 3
        };
        INTERRUPTS(const INTERRUPTS_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

};

} // namespace device
