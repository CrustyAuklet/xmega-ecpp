/**
 * XMEGAAU-USART (id I6090)
 * Universal Asynchronous Receiver-Transmitter
 *
 *
 */
#pragma once

#include "device/register.hpp"
#include <cstdint>

namespace device {

/**
 * USART
 * Universal Synchronous/Asynchronous Receiver/Transmitter
 * Size: 8 bytes
 */
template <addressType BASE_ADDRESS>
struct USART_t {

    /// Data Register - 1 bytes
    struct DATA : public reg8_t<BASE_ADDRESS + 0x0000> {
    };

    /// Status Register - 1 bytes
    struct STATUS : public reg8_t<BASE_ADDRESS + 0x0001> {
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x80, 7> RXCIF;    //< Receive Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x40, 6> TXCIF;    //< Transmit Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x20, 5> DREIF;    //< Data Register Empty Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x10, 4> FERR;    //< Frame Error using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x08, 3> BUFOVF;    //< Buffer Overflow using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x04, 2> PERR;    //< Parity Error using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x01, 0> RXB8;    //< Receive Bit 8 using None
    };

    /// Control Register A - 1 bytes
    struct CTRLA : public reg8_t<BASE_ADDRESS + 0x0003> {
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x30, 4> RXCINTLVL;    //< Receive Interrupt Level using USART_RXCINTLVL
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x0C, 2> TXCINTLVL;    //< Transmit Interrupt Level using USART_TXCINTLVL
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x03, 0> DREINTLVL;    //< Data Register Empty Interrupt Level using USART_DREINTLVL
    };

    /// Control Register B - 1 bytes
    struct CTRLB : public reg8_t<BASE_ADDRESS + 0x0004> {
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x10, 4> RXEN;    //< Receiver Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x08, 3> TXEN;    //< Transmitter Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x04, 2> CLK2X;    //< Double transmission speed using None
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x02, 1> MPCM;    //< Multi-processor Communication Mode using None
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x01, 0> TXB8;    //< Transmit bit 8 using None
    };

    /// Control Register C - 1 bytes
    struct CTRLC : public reg8_t<BASE_ADDRESS + 0x0005> {
        typedef reg_field_t<BASE_ADDRESS + 0x0005, 0xC0, 6> CMODE;    //< Communication Mode using USART_CMODE
        typedef reg_field_t<BASE_ADDRESS + 0x0005, 0x30, 4> PMODE;    //< Parity Mode using USART_PMODE
        typedef reg_field_t<BASE_ADDRESS + 0x0005, 0x08, 3> SBMODE;    //< Stop Bit Mode using None
        typedef reg_field_t<BASE_ADDRESS + 0x0005, 0x07, 0> CHSIZE;    //< Character Size using USART_CHSIZE
    };

    /// Baud Rate Control Register A - 1 bytes
    struct BAUDCTRLA : public reg8_t<BASE_ADDRESS + 0x0006> {
        typedef reg_field_t<BASE_ADDRESS + 0x0006, 0xFF, 0> BSEL;    //< Baud Rate Selection Bits [7:0] using None
    };

    /// Baud Rate Control Register B - 1 bytes
    struct BAUDCTRLB : public reg8_t<BASE_ADDRESS + 0x0007> {
        typedef reg_field_t<BASE_ADDRESS + 0x0007, 0xF0, 4> BSCALE;    //< Baud Rate Scale using None
        typedef reg_field_t<BASE_ADDRESS + 0x0007, 0x0F, 0> BSEL;    //< Baud Rate Selection bits[11:8] using None
    };
};

namespace USART {

    // Receive Complete Interrupt level
    class RXCINTLVL {
    private:
        enum RXCINTLVL_ {
            OFF_ = 0x00, // Interrupt Disabled
            LO_ = 0x01, // Low Level
            MED_ = 0x02, // Medium Level
            HI_ = 0x03, // High Level
        };
        RXCINTLVL_ value_;
    public:
        static const RXCINTLVL OFF, LO, MED, HI;
        explicit RXCINTLVL(const RXCINTLVL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Transmit Complete Interrupt level
    class TXCINTLVL {
    private:
        enum TXCINTLVL_ {
            OFF_ = 0x00, // Interrupt Disabled
            LO_ = 0x01, // Low Level
            MED_ = 0x02, // Medium Level
            HI_ = 0x03, // High Level
        };
        TXCINTLVL_ value_;
    public:
        static const TXCINTLVL OFF, LO, MED, HI;
        explicit TXCINTLVL(const TXCINTLVL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Data Register Empty Interrupt level
    class DREINTLVL {
    private:
        enum DREINTLVL_ {
            OFF_ = 0x00, // Interrupt Disabled
            LO_ = 0x01, // Low Level
            MED_ = 0x02, // Medium Level
            HI_ = 0x03, // High Level
        };
        DREINTLVL_ value_;
    public:
        static const DREINTLVL OFF, LO, MED, HI;
        explicit DREINTLVL(const DREINTLVL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Character Size
    class CHSIZE {
    private:
        enum CHSIZE_ {
            _5BIT_ = 0x00, // Character size: 5 bit
            _6BIT_ = 0x01, // Character size: 6 bit
            _7BIT_ = 0x02, // Character size: 7 bit
            _8BIT_ = 0x03, // Character size: 8 bit
            _9BIT_ = 0x07, // Character size: 9 bit
        };
        CHSIZE_ value_;
    public:
        static const CHSIZE _5BIT, _6BIT, _7BIT, _8BIT, _9BIT;
        explicit CHSIZE(const CHSIZE_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Communication Mode
    class CMODE {
    private:
        enum CMODE_ {
            ASYNCHRONOUS_ = 0x00, // Asynchronous Mode
            SYNCHRONOUS_ = 0x01, // Synchronous Mode
            IRDA_ = 0x02, // IrDA Mode
            MSPI_ = 0x03, // Master SPI Mode
        };
        CMODE_ value_;
    public:
        static const CMODE ASYNCHRONOUS, SYNCHRONOUS, IRDA, MSPI;
        explicit CMODE(const CMODE_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Parity Mode
    class PMODE {
    private:
        enum PMODE_ {
            DISABLED_ = 0x00, // No Parity
            EVEN_ = 0x02, // Even Parity
            ODD_ = 0x03, // Odd Parity
        };
        PMODE_ value_;
    public:
        static const PMODE DISABLED, EVEN, ODD;
        explicit PMODE(const PMODE_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };


    // USART Interrupts
    class INTERRUPTS {
    private:
        enum USART_VECTORS_ {
            RXC_ = 0, // Reception Complete Interrupt
            DRE_ = 1, // Data Register Empty Interrupt
            TXC_ = 2, // Transmission Complete Interrupt
        };
        USART_VECTORS_ value_;
    public:
        static const USART RXC, DRE, TXC;
        explicit USART(const USART_VECTORS_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

} // namespace USART
} // namespace device
