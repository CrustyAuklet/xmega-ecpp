/**
 * XMEGAAU-DAC (id I6059)
 * Digital/Analog Converter
 *
 *
 */
#pragma once

#include "device/register.hpp"
#include <cstdint>

namespace device {

/**
 * DAC
 * Digital-to-Analog Converter
 * Size: 28 bytes
 */
template <addressType BASE_ADDRESS>
struct DAC_t {

    /// Control Register A - 1 bytes
    struct CTRLA : public reg8_t<BASE_ADDRESS + 0x0000> {
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x10, 4> IDOEN;    //< Internal Output Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x08, 3> CH1EN;    //< Channel 1 Output Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x04, 2> CH0EN;    //< Channel 0 Output Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x02, 1> LPMODE;    //< Low Power Mode using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x01, 0> ENABLE;    //< Enable using None
    };

    /// Control Register B - 1 bytes
    struct CTRLB : public reg8_t<BASE_ADDRESS + 0x0001> {
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x60, 5> CHSEL;    //< Channel Select using DAC_CHSEL
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x02, 1> CH1TRIG;    //< Channel 1 Event Trig Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x01, 0> CH0TRIG;    //< Channel 0 Event Trig Enable using None
    };

    /// Control Register C - 1 bytes
    struct CTRLC : public reg8_t<BASE_ADDRESS + 0x0002> {
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x18, 3> REFSEL;    //< Reference Select using DAC_REFSEL
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x01, 0> LEFTADJ;    //< Left-adjust Result using None
    };

    /// Event Input Control - 1 bytes
    struct EVCTRL : public reg8_t<BASE_ADDRESS + 0x0003> {
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x08, 3> EVSPLIT;    //< Separate Event Channel Input for Channel 1 using None
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x07, 0> EVSEL;    //< Event Input Selection using DAC_EVSEL
    };

    /// Status - 1 bytes
    struct STATUS : public reg8_t<BASE_ADDRESS + 0x0005> {
        typedef reg_field_t<BASE_ADDRESS + 0x0005, 0x02, 1> CH1DRE;    //< Channel 1 Data Register Empty using None
        typedef reg_field_t<BASE_ADDRESS + 0x0005, 0x01, 0> CH0DRE;    //< Channel 0 Data Register Empty using None
    };

    /// Gain Calibration - 1 bytes
    struct CH0GAINCAL : public reg8_t<BASE_ADDRESS + 0x0008> {
        typedef reg_field_t<BASE_ADDRESS + 0x0008, 0x7F, 0> CH0GAINCAL;    //< Gain Calibration using None
    };

    /// Offset Calibration - 1 bytes
    struct CH0OFFSETCAL : public reg8_t<BASE_ADDRESS + 0x0009> {
        typedef reg_field_t<BASE_ADDRESS + 0x0009, 0x7F, 0> CH0OFFSETCAL;    //< Offset Calibration using None
    };

    /// Gain Calibration - 1 bytes
    struct CH1GAINCAL : public reg8_t<BASE_ADDRESS + 0x000A> {
        typedef reg_field_t<BASE_ADDRESS + 0x000A, 0x7F, 0> CH1GAINCAL;    //< Gain Calibration using None
    };

    /// Offset Calibration - 1 bytes
    struct CH1OFFSETCAL : public reg8_t<BASE_ADDRESS + 0x000B> {
        typedef reg_field_t<BASE_ADDRESS + 0x000B, 0x7F, 0> CH1OFFSETCAL;    //< Offset Calibration using None
    };

    /// Channel 0 Data - 2 bytes
    struct CH0DATA : public reg16_t<BASE_ADDRESS + 0x0018> {
    };

    /// Channel 1 Data - 2 bytes
    struct CH1DATA : public reg16_t<BASE_ADDRESS + 0x001A> {
    };

    // Output channel selection
    class CHSELv {
    public:
        enum CHSEL_ {
            SINGLE = 0x00, // Single channel operation (Channel 0 only)
            SINGLE1 = 0x01, // Single channel operation (Channel 1 only)
            DUAL = 0x02, // Dual channel operation (Channel 0 and channel 1)
        };
        CHSELv(const CHSEL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Reference voltage selection
    class REFSELv {
    public:
        enum REFSEL_ {
            INT1V = 0x00, // Internal 1V 
            AVCC = 0x01, // Analog supply voltage
            AREFA = 0x02, // External reference on AREF on PORTA
            AREFB = 0x03, // External reference on AREF on PORTB
        };
        REFSELv(const REFSEL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Event channel selection
    class EVSELv {
    public:
        enum EVSEL_ {
            _0 = 0x00, // Event Channel 0
            _1 = 0x01, // Event Channel 1
            _2 = 0x02, // Event Channel 2
            _3 = 0x03, // Event Channel 3
            _4 = 0x04, // Event Channel 4
            _5 = 0x05, // Event Channel 5
            _6 = 0x06, // Event Channel 6
            _7 = 0x07, // Event Channel 7
        };
        EVSELv(const EVSEL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

};

} // namespace device
