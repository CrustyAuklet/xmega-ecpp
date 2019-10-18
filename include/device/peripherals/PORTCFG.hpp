/**
 * XMEGAAU-PORTCFG (id I6075)
 * Port Configuration
 *
 *
 */
#pragma once

#include "device/register.hpp"
#include <cstdint>

namespace device {

/**
 * PORTCFG
 * I/O port Configuration
 * Size: 7 bytes
 */
template <addressType BASE_ADDRESS>
struct PORTCFG_t {

    /// Multi-pin Configuration Mask - 1 bytes
    struct MPCMASK : public reg8_t<BASE_ADDRESS + 0x0000> {
    };

    /// Virtual Port Control Register A - 1 bytes
    struct VPCTRLA : public reg8_t<BASE_ADDRESS + 0x0002> {
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0xF0, 4> VP1MAP;    //< Virtual Port 1 Mapping using PORTCFG_VP13MAP
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x0F, 0> VP0MAP;    //< Virtual Port 0 Mapping using PORTCFG_VP02MAP
    };

    /// Virtual Port Control Register B - 1 bytes
    struct VPCTRLB : public reg8_t<BASE_ADDRESS + 0x0003> {
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0xF0, 4> VP3MAP;    //< Virtual Port 3 Mapping using PORTCFG_VP13MAP
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x0F, 0> VP2MAP;    //< Virtual Port 2 Mapping using PORTCFG_VP02MAP
    };

    /// Clock and Event Out Register - 1 bytes
    struct CLKEVOUT : public reg8_t<BASE_ADDRESS + 0x0004> {
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x03, 0> CLKOUT;    //< Peripheral Clock Output Port using PORTCFG_CLKOUT
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x0C, 2> CLKOUTSEL;    //< Peripheral Clock Output Select using PORTCFG_CLKOUTSEL
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x30, 4> EVOUT;    //< Event Output Port using PORTCFG_EVOUT
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x40, 6> RTCOUT;    //< RTC Clock Output using None
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x80, 7> CLKEVPIN;    //< Peripheral Clock and Event Output pin Select using PORTCFG_CLKEVPIN
    };

    /// EBI Output register - 1 bytes
    struct EBIOUT : public reg8_t<BASE_ADDRESS + 0x0005> {
        typedef reg_field_t<BASE_ADDRESS + 0x0005, 0x03, 0> EBICSOUT;    //< EBI Chip Select Output using PORTCFG_EBICSOUT
        typedef reg_field_t<BASE_ADDRESS + 0x0005, 0x0C, 2> EBIADROUT;    //< EBI Address Output using PORTCFG_EBIADROUT
    };

    /// Event Output Select - 1 bytes
    struct EVOUTSEL : public reg8_t<BASE_ADDRESS + 0x0006> {
        typedef reg_field_t<BASE_ADDRESS + 0x0006, 0x07, 0> EVOUTSEL;    //< Event Output Select using PORTCFG_EVOUTSEL
    };
};

namespace PORTCFG {

    // Virtual Port Mapping
    class VP02MAP {
    private:
        enum VP02MAP_ {
            PORTA_ = 0x00, // Mapped To PORTA
            PORTB_ = 0x01, // Mapped To PORTB
            PORTC_ = 0x02, // Mapped To PORTC
            PORTD_ = 0x03, // Mapped To PORTD
            PORTE_ = 0x04, // Mapped To PORTE
            PORTF_ = 0x05, // Mapped To PORTF
            PORTG_ = 0x06, // Mapped To PORTG
            PORTH_ = 0x07, // Mapped To PORTH
            PORTJ_ = 0x08, // Mapped To PORTJ
            PORTK_ = 0x09, // Mapped To PORTK
            PORTL_ = 0x0A, // Mapped To PORTL
            PORTM_ = 0x0B, // Mapped To PORTM
            PORTN_ = 0x0C, // Mapped To PORTN
            PORTP_ = 0x0D, // Mapped To PORTP
            PORTQ_ = 0x0E, // Mapped To PORTQ
            PORTR_ = 0x0F, // Mapped To PORTR
        };
        VP02MAP_ value_;
    public:
        static const VP02MAP PORTA, PORTB, PORTC, PORTD, PORTE, PORTF, PORTG, PORTH, PORTJ, PORTK, PORTL, PORTM, PORTN, PORTP, PORTQ, PORTR;
        explicit VP02MAP(const VP02MAP_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Virtual Port Mapping
    class VP13MAP {
    private:
        enum VP13MAP_ {
            PORTA_ = 0x00, // Mapped To PORTA
            PORTB_ = 0x01, // Mapped To PORTB
            PORTC_ = 0x02, // Mapped To PORTC
            PORTD_ = 0x03, // Mapped To PORTD
            PORTE_ = 0x04, // Mapped To PORTE
            PORTF_ = 0x05, // Mapped To PORTF
            PORTG_ = 0x06, // Mapped To PORTG
            PORTH_ = 0x07, // Mapped To PORTH
            PORTJ_ = 0x08, // Mapped To PORTJ
            PORTK_ = 0x09, // Mapped To PORTK
            PORTL_ = 0x0A, // Mapped To PORTL
            PORTM_ = 0x0B, // Mapped To PORTM
            PORTN_ = 0x0C, // Mapped To PORTN
            PORTP_ = 0x0D, // Mapped To PORTP
            PORTQ_ = 0x0E, // Mapped To PORTQ
            PORTR_ = 0x0F, // Mapped To PORTR
        };
        VP13MAP_ value_;
    public:
        static const VP13MAP PORTA, PORTB, PORTC, PORTD, PORTE, PORTF, PORTG, PORTH, PORTJ, PORTK, PORTL, PORTM, PORTN, PORTP, PORTQ, PORTR;
        explicit VP13MAP(const VP13MAP_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // System Clock Output Port
    class CLKOUT {
    private:
        enum CLKOUT_ {
            OFF_ = 0x00, // System Clock Output Disabled
            PC7_ = 0x01, // System Clock Output on Port C pin 7
            PD7_ = 0x02, // System Clock Output on Port D pin 7
            PE7_ = 0x03, // System Clock Output on Port E pin 7
        };
        CLKOUT_ value_;
    public:
        static const CLKOUT OFF, PC7, PD7, PE7;
        explicit CLKOUT(const CLKOUT_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Peripheral Clock Output Select
    class CLKOUTSEL {
    private:
        enum CLKOUTSEL_ {
            CLK1X_ = 0x00, // 1x Peripheral Clock Output to pin
            CLK2X_ = 0x01, // 2x Peripheral Clock Output to pin
            CLK4X_ = 0x02, // 4x Peripheral Clock Output to pin
        };
        CLKOUTSEL_ value_;
    public:
        static const CLKOUTSEL CLK1X, CLK2X, CLK4X;
        explicit CLKOUTSEL(const CLKOUTSEL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Event Output Port
    class EVOUT {
    private:
        enum EVOUT_ {
            OFF_ = 0x00, // Event Output Disabled
            PC7_ = 0x01, // Event Channel 7 Output on Port C pin 7
            PD7_ = 0x02, // Event Channel 7 Output on Port D pin 7
            PE7_ = 0x03, // Event Channel 7 Output on Port E pin 7
        };
        EVOUT_ value_;
    public:
        static const EVOUT OFF, PC7, PD7, PE7;
        explicit EVOUT(const EVOUT_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Clock and Event Output Port
    class CLKEVPIN {
    private:
        enum CLKEVPIN_ {
            PIN7_ = 0x00, // Clock and Event Ouput on PIN 7
            PIN4_ = 0x01, // Clock and Event Ouput on PIN 4
        };
        CLKEVPIN_ value_;
    public:
        static const CLKEVPIN PIN7, PIN4;
        explicit CLKEVPIN(const CLKEVPIN_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // EBI Address Output Port
    class EBIADROUT {
    private:
        enum EBIADROUT_ {
            PF_ = 0x00, // EBI port 3 address output on PORTF pins 0 to 7
            PE_ = 0x01, // EBI port 3 address output on PORTE pins 0 to 7
            PFH_ = 0x02, // EBI port 3 address output on PORTF pins 4 to 7
            PEH_ = 0x03, // EBI port 3 address output on PORTE pins 4 to 7
        };
        EBIADROUT_ value_;
    public:
        static const EBIADROUT PF, PE, PFH, PEH;
        explicit EBIADROUT(const EBIADROUT_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // EBI Chip Select Output Port
    class EBICSOUT {
    private:
        enum EBICSOUT_ {
            PH_ = 0x00, // EBI chip select output to PORTH pin 4 to 7
            PL_ = 0x01, // EBI chip select output to PORTL pin 4 to 7
            PF_ = 0x02, // EBI chip select output to PORTF pin 4 to 7
            PE_ = 0x03, // EBI chip select output to PORTE pin 4 to 7
        };
        EBICSOUT_ value_;
    public:
        static const EBICSOUT PH, PL, PF, PE;
        explicit EBICSOUT(const EBICSOUT_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Event Output Select
    class EVOUTSEL {
    private:
        enum EVOUTSEL_ {
            _0_ = 0x00, // Event Channel 0 output to pin
            _1_ = 0x01, // Event Channel 1 output to pin
            _2_ = 0x02, // Event Channel 2 output to pin
            _3_ = 0x03, // Event Channel 3 output to pin
            _4_ = 0x04, // Event Channel 4 output to pin
            _5_ = 0x05, // Event Channel 5 output to pin
            _6_ = 0x06, // Event Channel 6 output to pin
            _7_ = 0x07, // Event Channel 7 output to pin
        };
        EVOUTSEL_ value_;
    public:
        static const EVOUTSEL _0, _1, _2, _3, _4, _5, _6, _7;
        explicit EVOUTSEL(const EVOUTSEL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };


} // namespace PORTCFG
} // namespace device
