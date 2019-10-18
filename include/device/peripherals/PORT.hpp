/**
 * XMEGAAU-PORT (id I6075)
 * I/O Port Configuration
 *
 *
 */
#pragma once

#include "device/register.hpp"
#include <cstdint>

namespace device {

/**
 * PORT
 * I/O Ports
 * Size: 24 bytes
 */
template <addressType BASE_ADDRESS>
struct PORT_t {

    /// I/O Port Data Direction - 1 bytes
    struct DIR : public reg8_t<BASE_ADDRESS + 0x0000> {
    };

    /// I/O Port Data Direction Set - 1 bytes
    struct DIRSET : public reg8_t<BASE_ADDRESS + 0x0001> {
    };

    /// I/O Port Data Direction Clear - 1 bytes
    struct DIRCLR : public reg8_t<BASE_ADDRESS + 0x0002> {
    };

    /// I/O Port Data Direction Toggle - 1 bytes
    struct DIRTGL : public reg8_t<BASE_ADDRESS + 0x0003> {
    };

    /// I/O Port Output - 1 bytes
    struct OUT : public reg8_t<BASE_ADDRESS + 0x0004> {
    };

    /// I/O Port Output Set - 1 bytes
    struct OUTSET : public reg8_t<BASE_ADDRESS + 0x0005> {
    };

    /// I/O Port Output Clear - 1 bytes
    struct OUTCLR : public reg8_t<BASE_ADDRESS + 0x0006> {
    };

    /// I/O Port Output Toggle - 1 bytes
    struct OUTTGL : public reg8_t<BASE_ADDRESS + 0x0007> {
    };

    /// I/O port Input - 1 bytes
    struct IN : public reg8_t<BASE_ADDRESS + 0x0008> {
    };

    /// Interrupt Control Register - 1 bytes
    struct INTCTRL : public reg8_t<BASE_ADDRESS + 0x0009> {
        typedef reg_field_t<BASE_ADDRESS + 0x0009, 0x0C, 2> INT1LVL;    //< Port Interrupt 1 Level using PORT_INT1LVL
        typedef reg_field_t<BASE_ADDRESS + 0x0009, 0x03, 0> INT0LVL;    //< Port Interrupt 0 Level using PORT_INT0LVL
    };

    /// Port Interrupt 0 Mask - 1 bytes
    struct INT0MASK : public reg8_t<BASE_ADDRESS + 0x000A> {
    };

    /// Port Interrupt 1 Mask - 1 bytes
    struct INT1MASK : public reg8_t<BASE_ADDRESS + 0x000B> {
    };

    /// Interrupt Flag Register - 1 bytes
    struct INTFLAGS : public reg8_t<BASE_ADDRESS + 0x000C> {
        typedef reg_field_t<BASE_ADDRESS + 0x000C, 0x02, 1> INT1IF;    //< Port Interrupt 1 Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000C, 0x01, 0> INT0IF;    //< Port Interrupt 0 Flag using None
    };

    /// I/O Port Pin Remap Register - 1 bytes
    struct REMAP : public reg8_t<BASE_ADDRESS + 0x000E> {
        typedef reg_field_t<BASE_ADDRESS + 0x000E, 0x20, 5> SPI;    //< SPI using None
        typedef reg_field_t<BASE_ADDRESS + 0x000E, 0x10, 4> USART0;    //< USART0 using None
        typedef reg_field_t<BASE_ADDRESS + 0x000E, 0x08, 3> TC0D;    //< Timer/Counter 0 Output Compare D using None
        typedef reg_field_t<BASE_ADDRESS + 0x000E, 0x04, 2> TC0C;    //< Timer/Counter 0 Output Compare C using None
        typedef reg_field_t<BASE_ADDRESS + 0x000E, 0x02, 1> TC0B;    //< Timer/Counter 0 Output Compare B using None
        typedef reg_field_t<BASE_ADDRESS + 0x000E, 0x01, 0> TC0A;    //< Timer/Counter 0 Output Compare A using None
    };

    /// Pin 0 Control Register - 1 bytes
    struct PIN0CTRL : public reg8_t<BASE_ADDRESS + 0x0010> {
        typedef reg_field_t<BASE_ADDRESS + 0x0010, 0x80, 7> SRLEN;    //< Slew Rate Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0010, 0x40, 6> INVEN;    //< Inverted I/O Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0010, 0x38, 3> OPC;    //< Output/Pull Configuration using PORT_OPC
        typedef reg_field_t<BASE_ADDRESS + 0x0010, 0x07, 0> ISC;    //< Input/Sense Configuration using PORT_ISC
    };

    /// Pin 1 Control Register - 1 bytes
    struct PIN1CTRL : public reg8_t<BASE_ADDRESS + 0x0011> {
        typedef reg_field_t<BASE_ADDRESS + 0x0011, 0x80, 7> SRLEN;    //< Slew Rate Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0011, 0x40, 6> INVEN;    //< Inverted I/O Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0011, 0x38, 3> OPC;    //< Output/Pull Configuration using PORT_OPC
        typedef reg_field_t<BASE_ADDRESS + 0x0011, 0x07, 0> ISC;    //< Input/Sense Configuration using PORT_ISC
    };

    /// Pin 2 Control Register - 1 bytes
    struct PIN2CTRL : public reg8_t<BASE_ADDRESS + 0x0012> {
        typedef reg_field_t<BASE_ADDRESS + 0x0012, 0x80, 7> SRLEN;    //< Slew Rate Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0012, 0x40, 6> INVEN;    //< Inverted I/O Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0012, 0x38, 3> OPC;    //< Output/Pull Configuration using PORT_OPC
        typedef reg_field_t<BASE_ADDRESS + 0x0012, 0x07, 0> ISC;    //< Input/Sense Configuration using PORT_ISC
    };

    /// Pin 3 Control Register - 1 bytes
    struct PIN3CTRL : public reg8_t<BASE_ADDRESS + 0x0013> {
        typedef reg_field_t<BASE_ADDRESS + 0x0013, 0x80, 7> SRLEN;    //< Slew Rate Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0013, 0x40, 6> INVEN;    //< Inverted I/O Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0013, 0x38, 3> OPC;    //< Output/Pull Configuration using PORT_OPC
        typedef reg_field_t<BASE_ADDRESS + 0x0013, 0x07, 0> ISC;    //< Input/Sense Configuration using PORT_ISC
    };

    /// Pin 4 Control Register - 1 bytes
    struct PIN4CTRL : public reg8_t<BASE_ADDRESS + 0x0014> {
        typedef reg_field_t<BASE_ADDRESS + 0x0014, 0x80, 7> SRLEN;    //< Slew Rate Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0014, 0x40, 6> INVEN;    //< Inverted I/O Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0014, 0x38, 3> OPC;    //< Output/Pull Configuration using PORT_OPC
        typedef reg_field_t<BASE_ADDRESS + 0x0014, 0x07, 0> ISC;    //< Input/Sense Configuration using PORT_ISC
    };

    /// Pin 5 Control Register - 1 bytes
    struct PIN5CTRL : public reg8_t<BASE_ADDRESS + 0x0015> {
        typedef reg_field_t<BASE_ADDRESS + 0x0015, 0x80, 7> SRLEN;    //< Slew Rate Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0015, 0x40, 6> INVEN;    //< Inverted I/O Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0015, 0x38, 3> OPC;    //< Output/Pull Configuration using PORT_OPC
        typedef reg_field_t<BASE_ADDRESS + 0x0015, 0x07, 0> ISC;    //< Input/Sense Configuration using PORT_ISC
    };

    /// Pin 6 Control Register - 1 bytes
    struct PIN6CTRL : public reg8_t<BASE_ADDRESS + 0x0016> {
        typedef reg_field_t<BASE_ADDRESS + 0x0016, 0x80, 7> SRLEN;    //< Slew Rate Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0016, 0x40, 6> INVEN;    //< Inverted I/O Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0016, 0x38, 3> OPC;    //< Output/Pull Configuration using PORT_OPC
        typedef reg_field_t<BASE_ADDRESS + 0x0016, 0x07, 0> ISC;    //< Input/Sense Configuration using PORT_ISC
    };

    /// Pin 7 Control Register - 1 bytes
    struct PIN7CTRL : public reg8_t<BASE_ADDRESS + 0x0017> {
        typedef reg_field_t<BASE_ADDRESS + 0x0017, 0x80, 7> SRLEN;    //< Slew Rate Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0017, 0x40, 6> INVEN;    //< Inverted I/O Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0017, 0x38, 3> OPC;    //< Output/Pull Configuration using PORT_OPC
        typedef reg_field_t<BASE_ADDRESS + 0x0017, 0x07, 0> ISC;    //< Input/Sense Configuration using PORT_ISC
    };
};

namespace PORT {

    // Port Interrupt 0 Level
    class INT0LVL {
    private:
        enum INT0LVL_ {
            OFF_ = 0x00, // Interrupt Disabled
            LO_ = 0x01, // Low Level
            MED_ = 0x02, // Medium Level
            HI_ = 0x03, // High Level
        };
        INT0LVL_ value_;
    public:
        static const INT0LVL OFF, LO, MED, HI;
        explicit INT0LVL(const INT0LVL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Port Interrupt 1 Level
    class INT1LVL {
    private:
        enum INT1LVL_ {
            OFF_ = 0x00, // Interrupt Disabled
            LO_ = 0x01, // Low Level
            MED_ = 0x02, // Medium Level
            HI_ = 0x03, // High Level
        };
        INT1LVL_ value_;
    public:
        static const INT1LVL OFF, LO, MED, HI;
        explicit INT1LVL(const INT1LVL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Output/Pull Configuration
    class OPC {
    private:
        enum OPC_ {
            TOTEM_ = 0x00, // Totempole
            BUSKEEPER_ = 0x01, // Totempole w/ Bus keeper on Input and Output
            PULLDOWN_ = 0x02, // Totempole w/ Pull-down on Input
            PULLUP_ = 0x03, // Totempole w/ Pull-up on Input
            WIREDOR_ = 0x04, // Wired OR
            WIREDAND_ = 0x05, // Wired AND
            WIREDORPULL_ = 0x06, // Wired OR w/ Pull-down
            WIREDANDPULL_ = 0x07, // Wired AND w/ Pull-up
        };
        OPC_ value_;
    public:
        static const OPC TOTEM, BUSKEEPER, PULLDOWN, PULLUP, WIREDOR, WIREDAND, WIREDORPULL, WIREDANDPULL;
        explicit OPC(const OPC_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Input/Sense Configuration
    class ISC {
    private:
        enum ISC_ {
            BOTHEDGES_ = 0x00, // Sense Both Edges
            RISING_ = 0x01, // Sense Rising Edge
            FALLING_ = 0x02, // Sense Falling Edge
            LEVEL_ = 0x03, // Sense Level (Transparent For Events)
            INPUT_DISABLE_ = 0x07, // Disable Digital Input Buffer
        };
        ISC_ value_;
    public:
        static const ISC BOTHEDGES, RISING, FALLING, LEVEL, INPUT_DISABLE;
        explicit ISC(const ISC_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };


    // PORT Interrupts
    class INTERRUPTS {
    private:
        enum PORT_VECTORS_ {
            INT0_ = 0, // External Interrupt 0
            INT1_ = 1, // External Interrupt 1
        };
        PORT_VECTORS_ value_;
    public:
        static const PORT INT0, INT1;
        explicit PORT(const PORT_VECTORS_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

} // namespace PORT
} // namespace device
