/**
 * XMEGAAU-AC (id I6077)
 * Analog Comparator
 *
 *
 */
#pragma once

#include "device/register.hpp"
#include <cstdint>

namespace device {

/**
 * AC
 * Analog Comparator
 * Size: 8 bytes
 */
template <addressType BASE_ADDRESS>
struct AC_t {

    /// Analog Comparator 0 Control - 1 bytes
    struct AC0CTRL : public reg8_t<BASE_ADDRESS + 0x0000> {
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0xC0, 6> INTMODE;    //< Interrupt Mode using AC_INTMODE
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x30, 4> INTLVL;    //< Interrupt Level using AC_INTLVL
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x08, 3> HSMODE;    //< High-speed Mode using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x06, 1> HYSMODE;    //< Hysteresis Mode using AC_HYSMODE
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x01, 0> ENABLE;    //< Enable using None
    };

    /// Analog Comparator 1 Control - 1 bytes
    struct AC1CTRL : public reg8_t<BASE_ADDRESS + 0x0001> {
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0xC0, 6> INTMODE;    //< Interrupt Mode using AC_INTMODE
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x30, 4> INTLVL;    //< Interrupt Level using AC_INTLVL
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x08, 3> HSMODE;    //< High-speed Mode using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x06, 1> HYSMODE;    //< Hysteresis Mode using AC_HYSMODE
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x01, 0> ENABLE;    //< Enable using None
    };

    /// Analog Comparator 0 MUX Control - 1 bytes
    struct AC0MUXCTRL : public reg8_t<BASE_ADDRESS + 0x0002> {
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x38, 3> MUXPOS;    //< MUX Positive Input using AC_MUXPOS
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x07, 0> MUXNEG;    //< MUX Negative Input using AC_MUXNEG
    };

    /// Analog Comparator 1 MUX Control - 1 bytes
    struct AC1MUXCTRL : public reg8_t<BASE_ADDRESS + 0x0003> {
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x38, 3> MUXPOS;    //< MUX Positive Input using AC_MUXPOS
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x07, 0> MUXNEG;    //< MUX Negative Input using AC_MUXNEG
    };

    /// Control Register A - 1 bytes
    struct CTRLA : public reg8_t<BASE_ADDRESS + 0x0004> {
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x02, 1> AC1OUT;    //< Analog Comparator 1 Output Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x01, 0> AC0OUT;    //< Analog Comparator 0 Output Enable using None
    };

    /// Control Register B - 1 bytes
    struct CTRLB : public reg8_t<BASE_ADDRESS + 0x0005> {
        typedef reg_field_t<BASE_ADDRESS + 0x0005, 0x3F, 0> SCALEFAC;    //< VCC Voltage Scaler Factor using None
    };

    /// Window Mode Control - 1 bytes
    struct WINCTRL : public reg8_t<BASE_ADDRESS + 0x0006> {
        typedef reg_field_t<BASE_ADDRESS + 0x0006, 0x10, 4> WEN;    //< Window Mode Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0006, 0x0C, 2> WINTMODE;    //< Window Interrupt Mode using AC_WINTMODE
        typedef reg_field_t<BASE_ADDRESS + 0x0006, 0x03, 0> WINTLVL;    //< Window Interrupt Level using AC_WINTLVL
    };

    /// Status - 1 bytes
    struct STATUS : public reg8_t<BASE_ADDRESS + 0x0007> {
        typedef reg_field_t<BASE_ADDRESS + 0x0007, 0xC0, 6> WSTATE;    //< Window Mode State using AC_WSTATE
        typedef reg_field_t<BASE_ADDRESS + 0x0007, 0x20, 5> AC1STATE;    //< Analog Comparator 1 State using None
        typedef reg_field_t<BASE_ADDRESS + 0x0007, 0x10, 4> AC0STATE;    //< Analog Comparator 0 State using None
        typedef reg_field_t<BASE_ADDRESS + 0x0007, 0x04, 2> WIF;    //< Window Mode Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0007, 0x02, 1> AC1IF;    //< Analog Comparator 1 Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0007, 0x01, 0> AC0IF;    //< Analog Comparator 0 Interrupt Flag using None
    };

    /// Current Source Control - 1 bytes
    struct CURRCTRL : public reg8_t<BASE_ADDRESS + 0x0008> {
        typedef reg_field_t<BASE_ADDRESS + 0x0008, 0x80, 7> CURRENT;    //< Current Source Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0008, 0x40, 6> CURRMODE;    //< Current Mode using None
        typedef reg_field_t<BASE_ADDRESS + 0x0008, 0x02, 1> AC1CURR;    //< AC1 Current Source Output Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0008, 0x01, 0> AC0CURR;    //< AC0 Current Source Output Enable using None
    };

    /// Current Source Calibration - 1 bytes
    struct CURRCALIB : public reg8_t<BASE_ADDRESS + 0x0009> {
        typedef reg_field_t<BASE_ADDRESS + 0x0009, 0x0F, 0> CALIB;    //< Current Source Calibration using None
    };

    // Interrupt mode
    class INTMODEv {
    public:
        enum INTMODE_ {
            BOTHEDGES = 0x00, // Interrupt on both edges
            FALLING = 0x02, // Interrupt on falling edge
            RISING = 0x03, // Interrupt on rising edge
        };
        INTMODEv(const INTMODE_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Interrupt level
    class INTLVLv {
    public:
        enum INTLVL_ {
            OFF = 0x00, // Interrupt disabled
            LO = 0x01, // Low level
            MED = 0x02, // Medium level
            HI = 0x03, // High level
        };
        INTLVLv(const INTLVL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Hysteresis mode selection
    class HYSMODEv {
    public:
        enum HYSMODE_ {
            NO = 0x00, // No hysteresis
            SMALL = 0x01, // Small hysteresis
            LARGE = 0x02, // Large hysteresis
        };
        HYSMODEv(const HYSMODE_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Positive input multiplexer selection
    class MUXPOSv {
    public:
        enum MUXPOS_ {
            PIN0 = 0x00, // Pin 0
            PIN1 = 0x01, // Pin 1
            PIN2 = 0x02, // Pin 2
            PIN3 = 0x03, // Pin 3
            PIN4 = 0x04, // Pin 4
            PIN5 = 0x05, // Pin 5
            PIN6 = 0x06, // Pin 6
            DAC = 0x07, // DAC output
        };
        MUXPOSv(const MUXPOS_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Negative input multiplexer selection
    class MUXNEGv {
    public:
        enum MUXNEG_ {
            PIN0 = 0x00, // Pin 0
            PIN1 = 0x01, // Pin 1
            PIN3 = 0x02, // Pin 3
            PIN5 = 0x03, // Pin 5
            PIN7 = 0x04, // Pin 7
            DAC = 0x05, // DAC output
            BANDGAP = 0x06, // Bandgap Reference
            SCALER = 0x07, // Internal voltage scaler
        };
        MUXNEGv(const MUXNEG_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Windows interrupt mode
    class WINTMODEv {
    public:
        enum WINTMODE_ {
            ABOVE = 0x00, // Interrupt on above window
            INSIDE = 0x01, // Interrupt on inside window
            BELOW = 0x02, // Interrupt on below window
            OUTSIDE = 0x03, // Interrupt on outside window
        };
        WINTMODEv(const WINTMODE_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Window interrupt level
    class WINTLVLv {
    public:
        enum WINTLVL_ {
            OFF = 0x00, // Interrupt disabled
            LO = 0x01, // Low priority
            MED = 0x02, // Medium priority
            HI = 0x03, // High priority
        };
        WINTLVLv(const WINTLVL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Window mode state
    class WSTATEv {
    public:
        enum WSTATE_ {
            ABOVE = 0x00, // Signal above window
            INSIDE = 0x01, // Signal inside window
            BELOW = 0x02, // Signal below window
        };
        WSTATEv(const WSTATE_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // AC ISR Vector Offsets (two bytes each)
    class INTERRUPTS {
    public:
        enum INTERRUPTS_ {
            AC0 = 0, // AC0 Interrupt
            AC1 = 1, // AC1 Interrupt
            ACW = 2, // ACW Window Mode Interrupt
        };
        INTERRUPTS(const INTERRUPTS_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

};

} // namespace device
