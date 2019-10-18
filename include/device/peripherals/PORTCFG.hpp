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

    // Virtual Port Mapping
    class VP02MAPv {
    public:
        enum VP02MAP_ {
            PORTA = 0x00, // Mapped To PORTA
            PORTB = 0x01, // Mapped To PORTB
            PORTC = 0x02, // Mapped To PORTC
            PORTD = 0x03, // Mapped To PORTD
            PORTE = 0x04, // Mapped To PORTE
            PORTF = 0x05, // Mapped To PORTF
            PORTG = 0x06, // Mapped To PORTG
            PORTH = 0x07, // Mapped To PORTH
            PORTJ = 0x08, // Mapped To PORTJ
            PORTK = 0x09, // Mapped To PORTK
            PORTL = 0x0A, // Mapped To PORTL
            PORTM = 0x0B, // Mapped To PORTM
            PORTN = 0x0C, // Mapped To PORTN
            PORTP = 0x0D, // Mapped To PORTP
            PORTQ = 0x0E, // Mapped To PORTQ
            PORTR = 0x0F, // Mapped To PORTR
        };
        VP02MAPv(const VP02MAP_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Virtual Port Mapping
    class VP13MAPv {
    public:
        enum VP13MAP_ {
            PORTA = 0x00, // Mapped To PORTA
            PORTB = 0x01, // Mapped To PORTB
            PORTC = 0x02, // Mapped To PORTC
            PORTD = 0x03, // Mapped To PORTD
            PORTE = 0x04, // Mapped To PORTE
            PORTF = 0x05, // Mapped To PORTF
            PORTG = 0x06, // Mapped To PORTG
            PORTH = 0x07, // Mapped To PORTH
            PORTJ = 0x08, // Mapped To PORTJ
            PORTK = 0x09, // Mapped To PORTK
            PORTL = 0x0A, // Mapped To PORTL
            PORTM = 0x0B, // Mapped To PORTM
            PORTN = 0x0C, // Mapped To PORTN
            PORTP = 0x0D, // Mapped To PORTP
            PORTQ = 0x0E, // Mapped To PORTQ
            PORTR = 0x0F, // Mapped To PORTR
        };
        VP13MAPv(const VP13MAP_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // System Clock Output Port
    class CLKOUTv {
    public:
        enum CLKOUT_ {
            OFF = 0x00, // System Clock Output Disabled
            PC7 = 0x01, // System Clock Output on Port C pin 7
            PD7 = 0x02, // System Clock Output on Port D pin 7
            PE7 = 0x03, // System Clock Output on Port E pin 7
        };
        CLKOUTv(const CLKOUT_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Peripheral Clock Output Select
    class CLKOUTSELv {
    public:
        enum CLKOUTSEL_ {
            CLK1X = 0x00, // 1x Peripheral Clock Output to pin
            CLK2X = 0x01, // 2x Peripheral Clock Output to pin
            CLK4X = 0x02, // 4x Peripheral Clock Output to pin
        };
        CLKOUTSELv(const CLKOUTSEL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Event Output Port
    class EVOUTv {
    public:
        enum EVOUT_ {
            OFF = 0x00, // Event Output Disabled
            PC7 = 0x01, // Event Channel 7 Output on Port C pin 7
            PD7 = 0x02, // Event Channel 7 Output on Port D pin 7
            PE7 = 0x03, // Event Channel 7 Output on Port E pin 7
        };
        EVOUTv(const EVOUT_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Clock and Event Output Port
    class CLKEVPINv {
    public:
        enum CLKEVPIN_ {
            PIN7 = 0x00, // Clock and Event Ouput on PIN 7
            PIN4 = 0x01, // Clock and Event Ouput on PIN 4
        };
        CLKEVPINv(const CLKEVPIN_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // EBI Address Output Port
    class EBIADROUTv {
    public:
        enum EBIADROUT_ {
            PF = 0x00, // EBI port 3 address output on PORTF pins 0 to 7
            PE = 0x01, // EBI port 3 address output on PORTE pins 0 to 7
            PFH = 0x02, // EBI port 3 address output on PORTF pins 4 to 7
            PEH = 0x03, // EBI port 3 address output on PORTE pins 4 to 7
        };
        EBIADROUTv(const EBIADROUT_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // EBI Chip Select Output Port
    class EBICSOUTv {
    public:
        enum EBICSOUT_ {
            PH = 0x00, // EBI chip select output to PORTH pin 4 to 7
            PL = 0x01, // EBI chip select output to PORTL pin 4 to 7
            PF = 0x02, // EBI chip select output to PORTF pin 4 to 7
            PE = 0x03, // EBI chip select output to PORTE pin 4 to 7
        };
        EBICSOUTv(const EBICSOUT_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Event Output Select
    class EVOUTSELv {
    public:
        enum EVOUTSEL_ {
            _0 = 0x00, // Event Channel 0 output to pin
            _1 = 0x01, // Event Channel 1 output to pin
            _2 = 0x02, // Event Channel 2 output to pin
            _3 = 0x03, // Event Channel 3 output to pin
            _4 = 0x04, // Event Channel 4 output to pin
            _5 = 0x05, // Event Channel 5 output to pin
            _6 = 0x06, // Event Channel 6 output to pin
            _7 = 0x07, // Event Channel 7 output to pin
        };
        EVOUTSELv(const EVOUTSEL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

};

} // namespace device
