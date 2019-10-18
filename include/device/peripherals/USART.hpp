/**
 * XMEGAAU-USART (id I6090)
 * Universal Asynchronous Receiver-Transmitter
 *
 *
 */
#pragma once

#include "device/register.hpp"
#include "boost/static_assert.hpp"
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

    // Receive Complete Interrupt level
    class RXCINTLVLv {
    public:
        enum RXCINTLVL_ {
            OFF = 0x00, // Interrupt Disabled
            LO = 0x01, // Low Level
            MED = 0x02, // Medium Level
            HI = 0x03, // High Level
        };
        RXCINTLVLv(const RXCINTLVL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Transmit Complete Interrupt level
    class TXCINTLVLv {
    public:
        enum TXCINTLVL_ {
            OFF = 0x00, // Interrupt Disabled
            LO = 0x01, // Low Level
            MED = 0x02, // Medium Level
            HI = 0x03, // High Level
        };
        TXCINTLVLv(const TXCINTLVL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Data Register Empty Interrupt level
    class DREINTLVLv {
    public:
        enum DREINTLVL_ {
            OFF = 0x00, // Interrupt Disabled
            LO = 0x01, // Low Level
            MED = 0x02, // Medium Level
            HI = 0x03, // High Level
        };
        DREINTLVLv(const DREINTLVL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Character Size
    class CHSIZEv {
    public:
        enum CHSIZE_ {
            _5BIT = 0x00, // Character size: 5 bit
            _6BIT = 0x01, // Character size: 6 bit
            _7BIT = 0x02, // Character size: 7 bit
            _8BIT = 0x03, // Character size: 8 bit
            _9BIT = 0x07, // Character size: 9 bit
        };
        CHSIZEv(const CHSIZE_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Communication Mode
    class CMODEv {
    public:
        enum CMODE_ {
            ASYNCHRONOUS = 0x00, // Asynchronous Mode
            SYNCHRONOUS = 0x01, // Synchronous Mode
            IRDA = 0x02, // IrDA Mode
            MSPI = 0x03, // Master SPI Mode
        };
        CMODEv(const CMODE_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Parity Mode
    class PMODEv {
    public:
        enum PMODE_ {
            DISABLED = 0x00, // No Parity
            EVEN = 0x02, // Even Parity
            ODD = 0x03, // Odd Parity
        };
        PMODEv(const PMODE_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // USART ISR Vector Offsets (two bytes each)
    class INTERRUPTS {
    public:
        enum INTERRUPTS_ {
            RXC = 0, // Reception Complete Interrupt
            DRE = 1, // Data Register Empty Interrupt
            TXC = 2, // Transmission Complete Interrupt
        };
        INTERRUPTS(const INTERRUPTS_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    /// set the baud rate with compile time constant values and checking
    template <uint32_t Baud = 9600, bool DoubleSpeed = false>
    static void set_baud() {
        BOOST_STATIC_ASSERT_MSG( DoubleSpeed ? (Baud <= F_CPU / 8U) : (Baud <= F_CPU / 8U*2U), "Baud speed for UART is too high!");
        BOOST_STATIC_ASSERT_MSG( DoubleSpeed ? (Baud >= F_CPU / 4194304UL) : (Baud >= F_CPU / 4194304UL*2UL ), "Baud speed for UART is too low!");

        // Find the lowest possible exponent.
        uint32_t cpu_hz = F_CPU;
        uint32_t limit  = 0xfffU >> 4;
        uint32_t ratio  = cpu_hz / Baud;
        int8_t   exp;
        for (exp = -7; exp < 7; exp++) {
            if (ratio < limit) {
                break;
            }

            limit <<= 1;

            if (exp < -3) {
                limit |= 1;
            }
        }

        //
        // Depending on the value of exp, scale either the input frequency or the target baud rate.
        // By always scaling upwards, we never introduce any additional inaccuracy.
        //
        // We are including the final divide-by-8 (aka. right-shift-by-3) in this operation as it
        // ensures that we never exceeed 2**32 at any point.
        //
        // The formula for calculating BSEL is slightly different when exp is negative than it is when exp is positive.
        uint32_t div;
        if (exp < 0) {
            // We are supposed to subtract 1, then apply BSCALE. We want to apply BSCALE first,
            // so we need to turn everything inside the parenthesis into a single fractional expression.
            cpu_hz -= 8 * Baud;

            // If we end up with a left-shift after taking the final divide-by-8 into account, do the shift before the divide.
            // Otherwise, left-shift the denominator instead (effectively resulting in an overall right shift.)
            if (exp <= -3) {
                div = ((cpu_hz << (-exp - 3)) + Baud / 2) / Baud;
            } else {
                const uint32_t baudShift = Baud << exp + 3;
                div = (cpu_hz + baudShift / 2) / baudShift;
            }
        } else {
            // We will always do a right shift in this case,
            // but we need to shift three extra positions because of the divide-by-8.
            const uint32_t baudShift = Baud << exp + 3;
            div = (cpu_hz + baudShift / 2) / baudShift - 1;
        }
        BAUDCTRLB::write( (((div >> 8) & 0X0F) | (exp << 4)) );
        BAUDCTRLA::write( div );
        CTRLB::CLK2X::write(DoubleSpeed);
    }

    /// init RX and TX pins to the proper state
    template < typename RXD_PIN, typename TXD_PIN >
    static void init_async_pins() {
        RXD_PIN::set_input();
        RXD_PIN::configure(RXD_PIN::MODE_TOTEM);
        TXD_PIN::set_output();
        TXD_PIN::set_low();
    }

    /// set the port mode: Char size, parity, and stop bits. 8N1 by default
    static void set_mode_async(const CHSIZEv CharSizeMode = CHSIZEv::_8BIT, const bool TwoStopBits = false, const PMODEv ParityMode = PMODEv::EVEN) {
        CTRLC::write( ParityMode << CTRLC::PMODE::SHIFT         // Parity
                    | TwoStopBits << CTRLC::SBMODE::SHIFT       // Stop Bit Mode
                    | CharSizeMode                              // Character size
                    | CMODEv::ASYNCHRONOUS                      // Async Polled Mode
        );
    }



    /// Enables the USART module by setting the RX and TX enable-bits in the USART control register
    static void enable_tx() {
        CTRLB::TXEN::write(1);
    }

    /// Enables the USART module by setting the RX enable-bit in the USART control register
    static void enable_rx() {
        CTRLB::RXEN::write(1);
    }

    /// Enables the USART module by setting the TX enable-bit in the USART control register
    static void enable() {
        CTRLB::write( CTRLB::read() | CTRLB::TXEN::BIT_MASK | CTRLB::RXEN::BIT_MASK );
    }

    /// Disables the USART module by clearing the enable-bit(s) in the USART control register
    static void disable() {
        CTRLB::write( CTRLB::read() & ~(CTRLB::TXEN::BIT_MASK | CTRLB::RXEN::BIT_MASK) );
    }

    /**
     * \brief Get recieved data from USART_0
     * \return Data register from USART_0 module
     */
    static uint8_t get_data() {
        return DATA::read();
    }

    static void write_data(const uint8_t d) {
        DATA::write(d);
    }

    /**
     * \brief Check if the usart can accept data to be transmitted
     * \return The status of USART TX data ready check
     * \retval false The USART can not receive data to be transmitted
     * \retval true The USART can receive data to be transmitted
     */
    static bool tx_ready() {
        return STATUS::DREIF::read();
    }

    /**
     * \brief Check if the USART has received data
     * \return The status of USART RX data ready check
     * \retval true The USART has received data
     * \retval false The USART has not received data
     */
    static bool rx_ready() {
        return STATUS::RXCIF::read();
    }

    /**
     * \brief Check if USART_0 data is transmitted
     * \return Receiver ready status
     * \retval true  Data is not completely shifted out of the shift register
     * \retval false Data completely shifted out if the USART shift register
     */
    static bool tx_busy() {
        return !STATUS::TXCIF::read();
    }

};

} // namespace device
