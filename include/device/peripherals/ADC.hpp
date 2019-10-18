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
    };
};
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

};

namespace ADC {

    // Positive input multiplexer selection
    class CH_MUXPOS {
    private:
        enum CH_MUXPOS_ {
            PIN0_ = 0x00, // Input pin 0
            PIN1_ = 0x01, // Input pin 1
            PIN2_ = 0x02, // Input pin 2
            PIN3_ = 0x03, // Input pin 3
            PIN4_ = 0x04, // Input pin 4
            PIN5_ = 0x05, // Input pin 5
            PIN6_ = 0x06, // Input pin 6
            PIN7_ = 0x07, // Input pin 7
            PIN8_ = 0x08, // Input pin 8
            PIN9_ = 0x09, // Input pin 9
            PIN10_ = 0x0A, // Input pin 10
            PIN11_ = 0x0B, // Input pin 11
            PIN12_ = 0x0C, // Input pin 12
            PIN13_ = 0x0D, // Input pin 13
            PIN14_ = 0x0E, // Input pin 14
            PIN15_ = 0x0F, // Input pin 15
        };
        CH_MUXPOS_ value_;
    public:
        static const CH_MUXPOS PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7, PIN8, PIN9, PIN10, PIN11, PIN12, PIN13, PIN14, PIN15;
        explicit CH_MUXPOS(const CH_MUXPOS_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Internal input multiplexer selections
    class CH_MUXINT {
    private:
        enum CH_MUXINT_ {
            TEMP_ = 0x00, // Temperature Reference
            BANDGAP_ = 0x01, // Bandgap Reference
            SCALEDVCC_ = 0x02, // 1/10 scaled VCC
            DAC_ = 0x03, // DAC output
        };
        CH_MUXINT_ value_;
    public:
        static const CH_MUXINT TEMP, BANDGAP, SCALEDVCC, DAC;
        explicit CH_MUXINT(const CH_MUXINT_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Negative input multiplexer selection
    class CH_MUXNEG {
    private:
        enum CH_MUXNEG_ {
            PIN0_ = 0x00, // Input pin 0 (Input Mode = 2)
            PIN1_ = 0x01, // Input pin 1 (Input Mode = 2)
            PIN2_ = 0x02, // Input pin 2 (Input Mode = 2)
            PIN3_ = 0x03, // Input pin 3 (Input Mode = 2)
            PIN4_ = 0x00, // Input pin 4 (Input Mode = 3)
            PIN5_ = 0x01, // Input pin 5 (Input Mode = 3)
            PIN6_ = 0x02, // Input pin 6 (Input Mode = 3)
            PIN7_ = 0x03, // Input pin 7 (Input Mode = 3)
            GND_MODE3_ = 0x05, // PAD Ground (Input Mode = 2)
            INTGND_MODE3_ = 0x07, // Internal Ground (Input Mode = 2)
            INTGND_MODE4_ = 0x04, // Internal Ground (Input Mode = 3)
            GND_MODE4_ = 0x07, // PAD Ground (Input Mode = 3)
        };
        CH_MUXNEG_ value_;
    public:
        static const CH_MUXNEG PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7, GND_MODE3, INTGND_MODE3, INTGND_MODE4, GND_MODE4;
        explicit CH_MUXNEG(const CH_MUXNEG_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Input mode
    class CH_INPUTMODE {
    private:
        enum CH_INPUTMODE_ {
            INTERNAL_ = 0x00, // Internal inputs, no gain
            SINGLEENDED_ = 0x01, // Single-ended input, no gain
            DIFF_ = 0x02, // Differential input, no gain
            DIFFWGAIN_ = 0x03, // Differential input, with gain
        };
        CH_INPUTMODE_ value_;
    public:
        static const CH_INPUTMODE INTERNAL, SINGLEENDED, DIFF, DIFFWGAIN;
        explicit CH_INPUTMODE(const CH_INPUTMODE_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Gain factor
    class CH_GAIN {
    private:
        enum CH_GAIN_ {
            _1X_ = 0x00, // 1x gain
            _2X_ = 0x01, // 2x gain
            _4X_ = 0x02, // 4x gain
            _8X_ = 0x03, // 8x gain
            _16X_ = 0x04, // 16x gain
            _32X_ = 0x05, // 32x gain
            _64X_ = 0x06, // 64x gain
            DIV2_ = 0x07, // x/2 gain
        };
        CH_GAIN_ value_;
    public:
        static const CH_GAIN _1X, _2X, _4X, _8X, _16X, _32X, _64X, DIV2;
        explicit CH_GAIN(const CH_GAIN_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Conversion result resolution
    class RESOLUTION {
    private:
        enum RESOLUTION_ {
            _12BIT_ = 0x00, // 12-bit right-adjusted result
            _8BIT_ = 0x02, // 8-bit right-adjusted result
            LEFT12BIT_ = 0x03, // 12-bit left-adjusted result
        };
        RESOLUTION_ value_;
    public:
        static const RESOLUTION _12BIT, _8BIT, LEFT12BIT;
        explicit RESOLUTION(const RESOLUTION_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Current Limitation Mode
    class CURRLIMIT {
    private:
        enum CURRLIMIT_ {
            NO_ = 0x00, // No limit
            LOW_ = 0x01, // Low current limit, max. sampling rate 1.5MSPS
            MED_ = 0x02, // Medium current limit, max. sampling rate 1MSPS
            HIGH_ = 0x03, // High current limit, max. sampling rate 0.5MSPS
        };
        CURRLIMIT_ value_;
    public:
        static const CURRLIMIT NO, LOW, MED, HIGH;
        explicit CURRLIMIT(const CURRLIMIT_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Voltage reference selection
    class REFSEL {
    private:
        enum REFSEL_ {
            INT1V_ = 0x00, // Internal 1V
            INTVCC_ = 0x01, // Internal VCC / 1.6
            AREFA_ = 0x02, // External reference on PORT A
            AREFB_ = 0x03, // External reference on PORT B
            INTVCC2_ = 0x04, // Internal VCC / 2
        };
        REFSEL_ value_;
    public:
        static const REFSEL INT1V, INTVCC, AREFA, AREFB, INTVCC2;
        explicit REFSEL(const REFSEL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Channel sweep selection
    class SWEEP {
    private:
        enum SWEEP_ {
            _0_ = 0x00, // ADC Channel 0
            _01_ = 0x01, // ADC Channel 0,1
            _012_ = 0x02, // ADC Channel 0,1,2
            _0123_ = 0x03, // ADC Channel 0,1,2,3
        };
        SWEEP_ value_;
    public:
        static const SWEEP _0, _01, _012, _0123;
        explicit SWEEP(const SWEEP_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Event channel input selection
    class EVSEL {
    private:
        enum EVSEL_ {
            _0123_ = 0x00, // Event Channel 0,1,2,3
            _1234_ = 0x01, // Event Channel 1,2,3,4
            _2345_ = 0x02, // Event Channel 2,3,4,5
            _3456_ = 0x03, // Event Channel 3,4,5,6
            _4567_ = 0x04, // Event Channel 4,5,6,7
            _567_ = 0x05, // Event Channel 5,6,7
            _67_ = 0x06, // Event Channel 6,7
            _7_ = 0x07, // Event Channel 7
        };
        EVSEL_ value_;
    public:
        static const EVSEL _0123, _1234, _2345, _3456, _4567, _567, _67, _7;
        explicit EVSEL(const EVSEL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Event action selection
    class EVACT {
    private:
        enum EVACT_ {
            NONE_ = 0x00, // No event action
            CH0_ = 0x01, // First event triggers channel 0
            CH01_ = 0x02, // First two events trigger channel 0,1
            CH012_ = 0x03, // First three events trigger channel 0,1,2
            CH0123_ = 0x04, // Events trigger channel 0,1,2,3
            SWEEP_ = 0x05, // First event triggers sweep
            SYNCSWEEP_ = 0x06, // The ADC is flushed and restarted for accurate timing
        };
        EVACT_ value_;
    public:
        static const EVACT NONE, CH0, CH01, CH012, CH0123, SWEEP, SYNCSWEEP;
        explicit EVACT(const EVACT_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Interupt mode
    class CH_INTMODE {
    private:
        enum CH_INTMODE_ {
            COMPLETE_ = 0x00, // Interrupt on conversion complete
            BELOW_ = 0x01, // Interrupt on result below compare value
            ABOVE_ = 0x03, // Interrupt on result above compare value
        };
        CH_INTMODE_ value_;
    public:
        static const CH_INTMODE COMPLETE, BELOW, ABOVE;
        explicit CH_INTMODE(const CH_INTMODE_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Interrupt level
    class CH_INTLVL {
    private:
        enum CH_INTLVL_ {
            OFF_ = 0x00, // Interrupt disabled
            LO_ = 0x01, // Low level
            MED_ = 0x02, // Medium level
            HI_ = 0x03, // High level
        };
        CH_INTLVL_ value_;
    public:
        static const CH_INTLVL OFF, LO, MED, HI;
        explicit CH_INTLVL(const CH_INTLVL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // DMA request selection
    class DMASEL {
    private:
        enum DMASEL_ {
            OFF_ = 0x00, // Combined DMA request OFF
            CH01_ = 0x01, // ADC Channel 0 or 1
            CH012_ = 0x02, // ADC Channel 0 or 1 or 2
            CH0123_ = 0x03, // ADC Channel 0 or 1 or 2 or 3
        };
        DMASEL_ value_;
    public:
        static const DMASEL OFF, CH01, CH012, CH0123;
        explicit DMASEL(const DMASEL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Clock prescaler
    class PRESCALER {
    private:
        enum PRESCALER_ {
            DIV4_ = 0x00, // Divide clock by 4
            DIV8_ = 0x01, // Divide clock by 8
            DIV16_ = 0x02, // Divide clock by 16
            DIV32_ = 0x03, // Divide clock by 32
            DIV64_ = 0x04, // Divide clock by 64
            DIV128_ = 0x05, // Divide clock by 128
            DIV256_ = 0x06, // Divide clock by 256
            DIV512_ = 0x07, // Divide clock by 512
        };
        PRESCALER_ value_;
    public:
        static const PRESCALER DIV4, DIV8, DIV16, DIV32, DIV64, DIV128, DIV256, DIV512;
        explicit PRESCALER(const PRESCALER_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };


    // ADC Interrupts
    class INTERRUPTS {
    private:
        enum ADC_VECTORS_ {
            CH0_ = 0, // Interrupt 0
            CH1_ = 1, // Interrupt 1
            CH2_ = 2, // Interrupt 2
            CH3_ = 3, // Interrupt 3
        };
        ADC_VECTORS_ value_;
    public:
        static const ADC CH0, CH1, CH2, CH3;
        explicit ADC(const ADC_VECTORS_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

} // namespace ADC
} // namespace device
