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
};

namespace AC {

    // Interrupt mode
    class INTMODE {
    private:
        enum INTMODE_ {
            BOTHEDGES_ = 0x00, // Interrupt on both edges
            FALLING_ = 0x02, // Interrupt on falling edge
            RISING_ = 0x03, // Interrupt on rising edge
        };
        INTMODE_ value_;
    public:
        static const INTMODE BOTHEDGES, FALLING, RISING;
        explicit INTMODE(const INTMODE_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Interrupt level
    class INTLVL {
    private:
        enum INTLVL_ {
            OFF_ = 0x00, // Interrupt disabled
            LO_ = 0x01, // Low level
            MED_ = 0x02, // Medium level
            HI_ = 0x03, // High level
        };
        INTLVL_ value_;
    public:
        static const INTLVL OFF, LO, MED, HI;
        explicit INTLVL(const INTLVL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Hysteresis mode selection
    class HYSMODE {
    private:
        enum HYSMODE_ {
            NO_ = 0x00, // No hysteresis
            SMALL_ = 0x01, // Small hysteresis
            LARGE_ = 0x02, // Large hysteresis
        };
        HYSMODE_ value_;
    public:
        static const HYSMODE NO, SMALL, LARGE;
        explicit HYSMODE(const HYSMODE_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Positive input multiplexer selection
    class MUXPOS {
    private:
        enum MUXPOS_ {
            PIN0_ = 0x00, // Pin 0
            PIN1_ = 0x01, // Pin 1
            PIN2_ = 0x02, // Pin 2
            PIN3_ = 0x03, // Pin 3
            PIN4_ = 0x04, // Pin 4
            PIN5_ = 0x05, // Pin 5
            PIN6_ = 0x06, // Pin 6
            DAC_ = 0x07, // DAC output
        };
        MUXPOS_ value_;
    public:
        static const MUXPOS PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, DAC;
        explicit MUXPOS(const MUXPOS_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Negative input multiplexer selection
    class MUXNEG {
    private:
        enum MUXNEG_ {
            PIN0_ = 0x00, // Pin 0
            PIN1_ = 0x01, // Pin 1
            PIN3_ = 0x02, // Pin 3
            PIN5_ = 0x03, // Pin 5
            PIN7_ = 0x04, // Pin 7
            DAC_ = 0x05, // DAC output
            BANDGAP_ = 0x06, // Bandgap Reference
            SCALER_ = 0x07, // Internal voltage scaler
        };
        MUXNEG_ value_;
    public:
        static const MUXNEG PIN0, PIN1, PIN3, PIN5, PIN7, DAC, BANDGAP, SCALER;
        explicit MUXNEG(const MUXNEG_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Windows interrupt mode
    class WINTMODE {
    private:
        enum WINTMODE_ {
            ABOVE_ = 0x00, // Interrupt on above window
            INSIDE_ = 0x01, // Interrupt on inside window
            BELOW_ = 0x02, // Interrupt on below window
            OUTSIDE_ = 0x03, // Interrupt on outside window
        };
        WINTMODE_ value_;
    public:
        static const WINTMODE ABOVE, INSIDE, BELOW, OUTSIDE;
        explicit WINTMODE(const WINTMODE_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Window interrupt level
    class WINTLVL {
    private:
        enum WINTLVL_ {
            OFF_ = 0x00, // Interrupt disabled
            LO_ = 0x01, // Low priority
            MED_ = 0x02, // Medium priority
            HI_ = 0x03, // High priority
        };
        WINTLVL_ value_;
    public:
        static const WINTLVL OFF, LO, MED, HI;
        explicit WINTLVL(const WINTLVL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Window mode state
    class WSTATE {
    private:
        enum WSTATE_ {
            ABOVE_ = 0x00, // Signal above window
            INSIDE_ = 0x01, // Signal inside window
            BELOW_ = 0x02, // Signal below window
        };
        WSTATE_ value_;
    public:
        static const WSTATE ABOVE, INSIDE, BELOW;
        explicit WSTATE(const WSTATE_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };


    // AC Interrupts
    class INTERRUPTS {
    private:
        enum AC_VECTORS_ {
            AC0_ = 0, // AC0 Interrupt
            AC1_ = 1, // AC1 Interrupt
            ACW_ = 2, // ACW Window Mode Interrupt
        };
        AC_VECTORS_ value_;
    public:
        static const AC AC0, AC1, ACW;
        explicit AC(const AC_VECTORS_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

} // namespace AC
} // namespace device
