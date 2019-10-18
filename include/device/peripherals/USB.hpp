/**
 * XMEGAAU-USB (id I3005)
 * USB
 *
 *
 */
#pragma once

#include "device/register.hpp"
#include <cstdint>

namespace device {

/**
 * USB_EP
 * USB Endpoint
 * Size: 8 bytes
 */
template <addressType BASE_ADDRESS>
struct USB_EP_t {

    /// Endpoint Status - 1 bytes
    struct STATUS : public reg8_t<BASE_ADDRESS + 0x0000> {
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x80, 7> STALLF;    //< Endpoint Stall Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x80, 7> CRC;    //< CRC Error Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x40, 6> UNF;    //< Underflow Enpoint FLag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x40, 6> OVF;    //< Overflow Enpoint Flag for Output Endpoints using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x20, 5> TRNCOMPL0;    //< Transaction Complete 0 Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x10, 4> TRNCOMPL1;    //< Transaction Complete 1 Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x10, 4> SETUP;    //< SETUP Transaction Complete Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x08, 3> BANK;    //< Bank Select using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x04, 2> BUSNACK1;    //< Data Buffer 1 Not Acknowledge using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x02, 1> BUSNACK0;    //< Data Buffer 0 Not Acknowledge using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x01, 0> TOGGLE;    //< Data Toggle using None
    };

    /// Endpoint Control - 1 bytes
    struct CTRL : public reg8_t<BASE_ADDRESS + 0x0001> {
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0xC0, 6> TYPE;    //< Endpoint Type using USB_EP_TYPE
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x20, 5> MULTIPKT;    //< Multi Packet Transfer Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x10, 4> PINGPONG;    //< Ping-Pong Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x08, 3> INTDSBL;    //< Interrupt Disable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x04, 2> STALL;    //< Data Stall using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x07, 0> BUFSIZE;    //< Data Buffer Size using USB_EP_BUFSIZE
    };

    /// USB Endpoint Counter - 2 bytes
    struct CNT : public reg16_t<BASE_ADDRESS + 0x0002> {
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x8000, 15> ZLP;    //< Zero Length Packet using None
    };

    /// Data Pointer - 2 bytes
    struct DATAPTR : public reg16_t<BASE_ADDRESS + 0x0004> {
    };

    /// Auxiliary Data - 2 bytes
    struct AUXDATA : public reg16_t<BASE_ADDRESS + 0x0006> {
    };
};
/**
 * USB
 * Universal Serial Bus
 * Size: 60 bytes
 */
template <addressType BASE_ADDRESS>
struct USB_t {

    /// Control Register A - 1 bytes
    struct CTRLA : public reg8_t<BASE_ADDRESS + 0x0000> {
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x80, 7> ENABLE;    //< USB Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x40, 6> SPEED;    //< Speed Select using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x20, 5> FIFOEN;    //< USB FIFO Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x10, 4> STFRNUM;    //< Store Frame Number Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x0F, 0> MAXEP;    //< Maximum Endpoint Addresses using None
    };

    /// Control Register B - 1 bytes
    struct CTRLB : public reg8_t<BASE_ADDRESS + 0x0001> {
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x10, 4> PULLRST;    //< Pull during Reset using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x04, 2> RWAKEUP;    //< Remote Wake-up using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x02, 1> GNACK;    //< Global NACK using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x01, 0> ATTACH;    //< Attach using None
    };

    /// Status Register - 1 bytes
    struct STATUS : public reg8_t<BASE_ADDRESS + 0x0002> {
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x08, 3> URESUME;    //< Upstream Resume using None
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x04, 2> RESUME;    //< Resume using None
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x02, 1> SUSPEND;    //< Bus Suspended using None
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x01, 0> BUSRST;    //< Bus Reset using None
    };

    /// Address Register - 1 bytes
    struct ADDR : public reg8_t<BASE_ADDRESS + 0x0003> {
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x7F, 0> ADDR;    //< Device Address using None
    };

    /// FIFO Write Pointer Register - 1 bytes
    struct FIFOWP : public reg8_t<BASE_ADDRESS + 0x0004> {
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x1F, 0> FIFOWP;    //< FIFO Write Pointer using None
    };

    /// FIFO Read Pointer Register - 1 bytes
    struct FIFORP : public reg8_t<BASE_ADDRESS + 0x0005> {
        typedef reg_field_t<BASE_ADDRESS + 0x0005, 0x1F, 0> FIFORP;    //< FIFO Read Pointer using None
    };

    /// Endpoint Configuration Table Pointer - 2 bytes
    struct EPPTR : public reg16_t<BASE_ADDRESS + 0x0006> {
    };

    /// Interrupt Control Register A - 1 bytes
    struct INTCTRLA : public reg8_t<BASE_ADDRESS + 0x0008> {
        typedef reg_field_t<BASE_ADDRESS + 0x0008, 0x80, 7> SOFIE;    //< Start Of Frame Interrupt Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0008, 0x40, 6> BUSEVIE;    //< Bus Event Interrupt Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0008, 0x20, 5> BUSERRIE;    //< Bus Error Interrupt Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0008, 0x10, 4> STALLIE;    //< STALL Interrupt Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0008, 0x03, 0> INTLVL;    //< Interrupt Level using USB_INTLVL
    };

    /// Interrupt Control Register B - 1 bytes
    struct INTCTRLB : public reg8_t<BASE_ADDRESS + 0x0009> {
        typedef reg_field_t<BASE_ADDRESS + 0x0009, 0x02, 1> TRNIE;    //< Transaction Complete Interrupt Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0009, 0x01, 0> SETUPIE;    //< SETUP Transaction Complete Interrupt Enable using None
    };

    /// Clear Interrupt Flag Register A - 1 bytes
    struct INTFLAGSACLR : public reg8_t<BASE_ADDRESS + 0x000A> {
        typedef reg_field_t<BASE_ADDRESS + 0x000A, 0x80, 7> SOFIF;    //< Start Of Frame Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000A, 0x40, 6> SUSPENDIF;    //< Suspend Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000A, 0x20, 5> RESUMEIF;    //< Resume Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000A, 0x10, 4> RSTIF;    //< Reset Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000A, 0x08, 3> CRCIF;    //< Isochronous CRC Error Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000A, 0x04, 2> UNFIF;    //< Underflow Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000A, 0x02, 1> OVFIF;    //< Overflow Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000A, 0x01, 0> STALLIF;    //< STALL Interrupt Flag using None
    };

    /// Set Interrupt Flag Register A - 1 bytes
    struct INTFLAGSASET : public reg8_t<BASE_ADDRESS + 0x000B> {
        typedef reg_field_t<BASE_ADDRESS + 0x000B, 0x80, 7> SOFIF;    //< Start Of Frame Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000B, 0x40, 6> SUSPENDIF;    //< Suspend Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000B, 0x20, 5> RESUMEIF;    //< Resume Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000B, 0x10, 4> RSTIF;    //< Reset Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000B, 0x08, 3> CRCIF;    //< Isochronous CRC Error Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000B, 0x04, 2> UNFIF;    //< Underflow Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000B, 0x02, 1> OVFIF;    //< Overflow Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000B, 0x01, 0> STALLIF;    //< STALL Interrupt Flag using None
    };

    /// Clear Interrupt Flag Register B - 1 bytes
    struct INTFLAGSBCLR : public reg8_t<BASE_ADDRESS + 0x000C> {
        typedef reg_field_t<BASE_ADDRESS + 0x000C, 0x02, 1> TRNIF;    //< Transaction Complete Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000C, 0x01, 0> SETUPIF;    //< SETUP Transaction Complete Interrupt Flag using None
    };

    /// Set Interrupt Flag Register B - 1 bytes
    struct INTFLAGSBSET : public reg8_t<BASE_ADDRESS + 0x000D> {
        typedef reg_field_t<BASE_ADDRESS + 0x000D, 0x02, 1> TRNIF;    //< Transaction Complete Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x000D, 0x01, 0> SETUPIF;    //< SETUP Transaction Complete Interrupt Flag using None
    };

    /// Calibration Byte 0 - 1 bytes
    struct CAL0 : public reg8_t<BASE_ADDRESS + 0x003A> {
    };

    /// Calibration Byte 1 - 1 bytes
    struct CAL1 : public reg8_t<BASE_ADDRESS + 0x003B> {
    };
};
/**
 * USB_EP_TABLE
 * USB Endpoint Table
 * Size: 274 bytes
 */
template <addressType BASE_ADDRESS>
struct USB_EP_TABLE_t {

    /// Frame Number Low Byte - 1 bytes
    struct FRAMENUML : public reg8_t<BASE_ADDRESS + 0x0110> {
    };

    /// Frame Number High Byte - 1 bytes
    struct FRAMENUMH : public reg8_t<BASE_ADDRESS + 0x0111> {
    };
    /// Endpoint 0
    USB_EP_t<BASE_ADDRESS + 0x0000> EP0OUT;

    /// Endpoint 0
    USB_EP_t<BASE_ADDRESS + 0x0008> EP0IN;

    /// Endpoint 1
    USB_EP_t<BASE_ADDRESS + 0x0010> EP1OUT;

    /// Endpoint 1
    USB_EP_t<BASE_ADDRESS + 0x0018> EP1IN;

    /// Endpoint 2
    USB_EP_t<BASE_ADDRESS + 0x0020> EP2OUT;

    /// Endpoint 2
    USB_EP_t<BASE_ADDRESS + 0x0028> EP2IN;

    /// Endpoint 3
    USB_EP_t<BASE_ADDRESS + 0x0030> EP3OUT;

    /// Endpoint 3
    USB_EP_t<BASE_ADDRESS + 0x0038> EP3IN;

    /// Endpoint 4
    USB_EP_t<BASE_ADDRESS + 0x0040> EP4OUT;

    /// Endpoint 4
    USB_EP_t<BASE_ADDRESS + 0x0048> EP4IN;

    /// Endpoint 5
    USB_EP_t<BASE_ADDRESS + 0x0050> EP5OUT;

    /// Endpoint 5
    USB_EP_t<BASE_ADDRESS + 0x0058> EP5IN;

    /// Endpoint 6
    USB_EP_t<BASE_ADDRESS + 0x0060> EP6OUT;

    /// Endpoint 6
    USB_EP_t<BASE_ADDRESS + 0x0068> EP6IN;

    /// Endpoint 7
    USB_EP_t<BASE_ADDRESS + 0x0070> EP7OUT;

    /// Endpoint 7
    USB_EP_t<BASE_ADDRESS + 0x0078> EP7IN;

    /// Endpoint 8
    USB_EP_t<BASE_ADDRESS + 0x0080> EP8OUT;

    /// Endpoint 8
    USB_EP_t<BASE_ADDRESS + 0x0088> EP8IN;

    /// Endpoint 9
    USB_EP_t<BASE_ADDRESS + 0x0090> EP9OUT;

    /// Endpoint 9
    USB_EP_t<BASE_ADDRESS + 0x0098> EP9IN;

    /// Endpoint 10
    USB_EP_t<BASE_ADDRESS + 0x00A0> EP10OUT;

    /// Endpoint 10
    USB_EP_t<BASE_ADDRESS + 0x00A8> EP10IN;

    /// Endpoint 11
    USB_EP_t<BASE_ADDRESS + 0x00B0> EP11OUT;

    /// Endpoint 11
    USB_EP_t<BASE_ADDRESS + 0x00B8> EP11IN;

    /// Endpoint 12
    USB_EP_t<BASE_ADDRESS + 0x00C0> EP12OUT;

    /// Endpoint 12
    USB_EP_t<BASE_ADDRESS + 0x00C8> EP12IN;

    /// Endpoint 13
    USB_EP_t<BASE_ADDRESS + 0x00D0> EP13OUT;

    /// Endpoint 13
    USB_EP_t<BASE_ADDRESS + 0x00D8> EP13IN;

    /// Endpoint 14
    USB_EP_t<BASE_ADDRESS + 0x00E0> EP14OUT;

    /// Endpoint 14
    USB_EP_t<BASE_ADDRESS + 0x00E8> EP14IN;

    /// Endpoint 15
    USB_EP_t<BASE_ADDRESS + 0x00F0> EP15OUT;

    /// Endpoint 15
    USB_EP_t<BASE_ADDRESS + 0x00F8> EP15IN;

};

namespace USB {

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

    // USB Endpoint Type
    class EP_TYPE {
    private:
        enum EP_TYPE_ {
            DISABLE_ = 0x00, // Endpoint Disabled
            CONTROL_ = 0x01, // Control
            BULK_ = 0x02, // Bulk/Interrupt
            ISOCHRONOUS_ = 0x03, // Isochronous
        };
        EP_TYPE_ value_;
    public:
        static const EP_TYPE DISABLE, CONTROL, BULK, ISOCHRONOUS;
        explicit EP_TYPE(const EP_TYPE_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // USB Endpoint Buffersize
    class EP_BUFSIZE {
    private:
        enum EP_BUFSIZE_ {
            _8_ = 0x00, // 8 bytes buffer size
            _16_ = 0x01, // 16 bytes buffer size
            _32_ = 0x02, // 32 bytes buffer size
            _64_ = 0x03, // 64 bytes buffer size
            _128_ = 0x04, // 128 bytes buffer size
            _256_ = 0x05, // 256 bytes buffer size
            _512_ = 0x06, // 512 bytes buffer size
            _1023_ = 0x07, // 1023 bytes buffer size
        };
        EP_BUFSIZE_ value_;
    public:
        static const EP_BUFSIZE _8, _16, _32, _64, _128, _256, _512, _1023;
        explicit EP_BUFSIZE(const EP_BUFSIZE_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };


    // USB Interrupts
    class INTERRUPTS {
    private:
        enum USB_VECTORS_ {
            BUSEVENT_ = 0, // SOF, suspend, resume, reset bus event interrupts, crc, underflow, overflow and stall error interrupts
            TRNCOMPL_ = 1, // Transaction complete interrupt
        };
        USB_VECTORS_ value_;
    public:
        static const USB BUSEVENT, TRNCOMPL;
        explicit USB(const USB_VECTORS_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

} // namespace USB
} // namespace device
