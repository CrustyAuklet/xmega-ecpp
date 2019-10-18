/**
 * None-DMA (id I3000)
 * DMA Controller
 *
 *
 */
#pragma once

#include "device/register.hpp"
#include <cstdint>

namespace device {

/**
 * DMA_CH
 * DMA Channel
 * Size: 16 bytes
 */
template <addressType BASE_ADDRESS>
struct DMA_CH_t {

    /// Channel Control - 1 bytes
    struct CTRLA : public reg8_t<BASE_ADDRESS + 0x0000> {
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x80, 7> ENABLE;    //< Channel Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x40, 6> RESET;    //< Channel Software Reset using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x20, 5> REPEAT;    //< Channel Repeat Mode using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x10, 4> TRFREQ;    //< Channel Transfer Request using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x04, 2> SINGLE;    //< Channel Single Shot Data Transfer using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x03, 0> BURSTLEN;    //< Channel Transfer Mode using DMA_CH_BURSTLEN
    };

    /// Channel Control - 1 bytes
    struct CTRLB : public reg8_t<BASE_ADDRESS + 0x0001> {
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x80, 7> CHBUSY;    //< Block Transfer Busy using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x40, 6> CHPEND;    //< Block Transfer Pending using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x20, 5> ERRIF;    //< Block Transfer Error Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x10, 4> TRNIF;    //< Transaction Complete Interrup Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x0C, 2> ERRINTLVL;    //< Transfer Error Interrupt Level using DMA_CH_ERRINTLVL
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x03, 0> TRNINTLVL;    //< Transaction Complete Interrupt Level using DMA_CH_TRNINTLVL
    };

    /// Address Control - 1 bytes
    struct ADDRCTRL : public reg8_t<BASE_ADDRESS + 0x0002> {
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0xC0, 6> SRCRELOAD;    //< Channel Source Address Reload using DMA_CH_SRCRELOAD
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x30, 4> SRCDIR;    //< Channel Source Address Mode using DMA_CH_SRCDIR
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x0C, 2> DESTRELOAD;    //< Channel Destination Address Reload using DMA_CH_DESTRELOAD
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x03, 0> DESTDIR;    //< Channel Destination Address Mode using DMA_CH_DESTDIR
    };

    /// Channel Trigger Source - 1 bytes
    struct TRIGSRC : public reg8_t<BASE_ADDRESS + 0x0003> {
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0xFF, 0> TRIGSRC;    //< Channel Trigger Source using DMA_CH_TRIGSRC
    };

    /// Channel Block Transfer Count - 2 bytes
    struct TRFCNT : public reg16_t<BASE_ADDRESS + 0x0004> {
    };

    /// Channel Repeat Count - 1 bytes
    struct REPCNT : public reg8_t<BASE_ADDRESS + 0x0006> {
    };

    /// Channel Source Address 0 - 1 bytes
    struct SRCADDR0 : public reg8_t<BASE_ADDRESS + 0x0008> {
    };

    /// Channel Source Address 1 - 1 bytes
    struct SRCADDR1 : public reg8_t<BASE_ADDRESS + 0x0009> {
    };

    /// Channel Source Address 2 - 1 bytes
    struct SRCADDR2 : public reg8_t<BASE_ADDRESS + 0x000A> {
    };

    /// Channel Destination Address 0 - 1 bytes
    struct DESTADDR0 : public reg8_t<BASE_ADDRESS + 0x000C> {
    };

    /// Channel Destination Address 1 - 1 bytes
    struct DESTADDR1 : public reg8_t<BASE_ADDRESS + 0x000D> {
    };

    /// Channel Destination Address 2 - 1 bytes
    struct DESTADDR2 : public reg8_t<BASE_ADDRESS + 0x000E> {
    };};

/**
 * DMA
 * DMA Controller
 * Size: 80 bytes
 */
template <addressType BASE_ADDRESS>
struct DMA_t {

    /// Control - 1 bytes
    struct CTRL : public reg8_t<BASE_ADDRESS + 0x0000> {
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x80, 7> ENABLE;    //< Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x40, 6> RESET;    //< Software Reset using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x0C, 2> DBUFMODE;    //< Double Buffering Mode using DMA_DBUFMODE
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x03, 0> PRIMODE;    //< Channel Priority Mode using DMA_PRIMODE
    };

    /// Transfer Interrupt Status - 1 bytes
    struct INTFLAGS : public reg8_t<BASE_ADDRESS + 0x0003> {
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x80, 7> CH3ERRIF;    //< Channel 3 Block Transfer Error Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x40, 6> CH2ERRIF;    //< Channel 2 Block Transfer Error Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x20, 5> CH1ERRIF;    //< Channel 1 Block Transfer Error Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x10, 4> CH0ERRIF;    //< Channel 0 Block Transfer Error Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x08, 3> CH3TRNIF;    //< Channel 3 Transaction Complete Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x04, 2> CH2TRNIF;    //< Channel 2 Transaction Complete Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x02, 1> CH1TRNIF;    //< Channel 1 Transaction Complete Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x01, 0> CH0TRNIF;    //< Channel 0 Transaction Complete Interrupt Flag using None
    };

    /// Status - 1 bytes
    struct STATUS : public reg8_t<BASE_ADDRESS + 0x0004> {
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x80, 7> CH3BUSY;    //< Channel 3 Block Transfer Busy using None
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x40, 6> CH2BUSY;    //< Channel 2 Block Transfer Busy using None
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x20, 5> CH1BUSY;    //< Channel 1 Block Transfer Busy using None
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x10, 4> CH0BUSY;    //< Channel 0 Block Transfer Busy using None
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x08, 3> CH3PEND;    //< Channel 3 Block Transfer Pending using None
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x04, 2> CH2PEND;    //< Channel 2 Block Transfer Pending using None
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x02, 1> CH1PEND;    //< Channel 1 Block Transfer Pending using None
        typedef reg_field_t<BASE_ADDRESS + 0x0004, 0x01, 0> CH0PEND;    //< Channel 0 Block Transfer Pending using None
    };

    /// Temporary Register For 16/24-bit Access - 2 bytes
    struct TEMP : public reg16_t<BASE_ADDRESS + 0x0006> {
    };
    /// DMA Channel 0
    DMA_CH_t<BASE_ADDRESS + 0x0010> CH0;

    /// DMA Channel 1
    DMA_CH_t<BASE_ADDRESS + 0x0020> CH1;

    /// DMA Channel 2
    DMA_CH_t<BASE_ADDRESS + 0x0030> CH2;

    /// DMA Channel 3
    DMA_CH_t<BASE_ADDRESS + 0x0040> CH3;


    // Burst mode
    class CH_BURSTLENv {
    public:
        enum CH_BURSTLEN_ {
            _1BYTE = 0x00, // 1-byte burst mode
            _2BYTE = 0x01, // 2-byte burst mode
            _4BYTE = 0x02, // 4-byte burst mode
            _8BYTE = 0x03, // 8-byte burst mode
        };
        CH_BURSTLENv(const CH_BURSTLEN_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Source address reload mode
    class CH_SRCRELOADv {
    public:
        enum CH_SRCRELOAD_ {
            NONE = 0x00, // No reload
            BLOCK = 0x01, // Reload at end of block
            BURST = 0x02, // Reload at end of burst
            TRANSACTION = 0x03, // Reload at end of transaction
        };
        CH_SRCRELOADv(const CH_SRCRELOAD_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Source addressing mode
    class CH_SRCDIRv {
    public:
        enum CH_SRCDIR_ {
            FIXED = 0x00, // Fixed
            INC = 0x01, // Increment
            DEC = 0x02, // Decrement
        };
        CH_SRCDIRv(const CH_SRCDIR_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Destination adress reload mode
    class CH_DESTRELOADv {
    public:
        enum CH_DESTRELOAD_ {
            NONE = 0x00, // No reload
            BLOCK = 0x01, // Reload at end of block
            BURST = 0x02, // Reload at end of burst
            TRANSACTION = 0x03, // Reload at end of transaction
        };
        CH_DESTRELOADv(const CH_DESTRELOAD_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Destination adressing mode
    class CH_DESTDIRv {
    public:
        enum CH_DESTDIR_ {
            FIXED = 0x00, // Fixed
            INC = 0x01, // Increment
            DEC = 0x02, // Decrement
        };
        CH_DESTDIRv(const CH_DESTDIR_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Transfer trigger source
    class CH_TRIGSRCv {
    public:
        enum CH_TRIGSRC_ {
            OFF = 0x00, // Off software triggers only
            EVSYS_CH0 = 0x01, // Event System Channel 0
            EVSYS_CH1 = 0x02, // Event System Channel 1
            EVSYS_CH2 = 0x03, // Event System Channel 2
            AES = 0x04, // AES
            ADCA_CH0 = 0x10, // ADCA Channel 0
            ADCA_CH1 = 0x11, // ADCA Channel 1
            ADCA_CH2 = 0x12, // ADCA Channel 2
            ADCA_CH3 = 0x13, // ADCA Channel 3
            ADCA_CH4 = 0x14, // ADCA Channel 0,1,2,3 combined
            DACA_CH0 = 0x15, // DACA Channel 0
            DACA_CH1 = 0x16, // DACA Channel 1
            ADCB_CH0 = 0x20, // ADCB Channel 0
            ADCB_CH1 = 0x21, // ADCB Channel 1
            ADCB_CH2 = 0x22, // ADCB Channel 2
            ADCB_CH3 = 0x23, // ADCB Channel 3
            ADCB_CH4 = 0x24, // ADCB Channel 0,1,2,3 combined
            DACB_CH0 = 0x25, // DACB Channel 0
            DACB_CH1 = 0x26, // DACB Channel 1
            TCC0_OVF = 0x40, // Timer/Counter C0 Overflow
            TCC0_ERR = 0x41, // Timer/Counter C0 Error
            TCC0_CCA = 0x42, // Timer/Counter C0 Compare or Capture A
            TCC0_CCB = 0x43, // Timer/Counter C0 Compare or Capture B
            TCC0_CCC = 0x44, // Timer/Counter C0 Compare or Capture C
            TCC0_CCD = 0x45, // Timer/Counter C0 Compare or Capture D
            TCC1_OVF = 0x46, // Timer/Counter C1 Overflow
            TCC1_ERR = 0x47, // Timer/Counter C1 Error
            TCC1_CCA = 0x48, // Timer/Counter C1 Compare or Capture A
            TCC1_CCB = 0x49, // Timer/Counter C1 Compare or Capture B
            SPIC = 0x4A, // SPI C Transfer Complete
            USARTC0_RXC = 0x4B, // USART C0 Receive Complete
            USARTC0_DRE = 0x4C, // USART C0 Data Register Empty
            USARTC1_RXC = 0x4E, // USART C1 Receive Complete
            USARTC1_DRE = 0x4F, // USART C1 Data Register Empty
            TCD0_OVF = 0x60, // Timer/Counter D0 Overflow
            TCD0_ERR = 0x61, // Timer/Counter D0 Error
            TCD0_CCA = 0x62, // Timer/Counter D0 Compare or Capture A
            TCD0_CCB = 0x63, // Timer/Counter D0 Compare or Capture B
            TCD0_CCC = 0x64, // Timer/Counter D0 Compare or Capture C
            TCD0_CCD = 0x65, // Timer/Counter D0 Compare or Capture D
            TCD1_OVF = 0x66, // Timer/Counter D1 Overflow
            TCD1_ERR = 0x67, // Timer/Counter D1 Error
            TCD1_CCA = 0x68, // Timer/Counter D1 Compare or Capture A
            TCD1_CCB = 0x69, // Timer/Counter D1 Compare or Capture B
            SPID = 0x6A, // SPI D Transfer Complete
            USARTD0_RXC = 0x6B, // USART D0 Receive Complete
            USARTD0_DRE = 0x6C, // USART D0 Data Register Empty
            USARTD1_RXC = 0x6E, // USART D1 Receive Complete
            USARTD1_DRE = 0x6F, // USART D1 Data Register Empty
            TCE0_OVF = 0x80, // Timer/Counter E0 Overflow
            TCE0_ERR = 0x81, // Timer/Counter E0 Error
            TCE0_CCA = 0x82, // Timer/Counter E0 Compare or Capture A
            TCE0_CCB = 0x83, // Timer/Counter E0 Compare or Capture B
            TCE0_CCC = 0x84, // Timer/Counter E0 Compare or Capture C
            TCE0_CCD = 0x85, // Timer/Counter E0 Compare or Capture D
            TCE1_OVF = 0x86, // Timer/Counter E1 Overflow
            TCE1_ERR = 0x87, // Timer/Counter E1 Error
            TCE1_CCA = 0x88, // Timer/Counter E1 Compare or Capture A
            TCE1_CCB = 0x89, // Timer/Counter E1 Compare or Capture B
            SPIE = 0x8A, // SPI E Transfer Complete
            USARTE0_RXC = 0x8B, // USART E0 Receive Complete
            USARTE0_DRE = 0x8C, // USART E0 Data Register Empty
            USARTE1_RXC = 0x8E, // USART E1 Receive Complete
            USARTE1_DRE = 0x8F, // USART E1 Data Register Empty
            TCF0_OVF = 0xA0, // Timer/Counter F0 Overflow
            TCF0_ERR = 0xA1, // Timer/Counter F0 Error
            TCF0_CCA = 0xA2, // Timer/Counter F0 Compare or Capture A
            TCF0_CCB = 0xA3, // Timer/Counter F0 Compare or Capture B
            TCF0_CCC = 0xA4, // Timer/Counter F0 Compare or Capture C
            TCF0_CCD = 0xA5, // Timer/Counter F0 Compare or Capture D
            TCF1_OVF = 0xA6, // Timer/Counter F1 Overflow
            TCF1_ERR = 0xA7, // Timer/Counter F1 Error
            TCF1_CCA = 0xA8, // Timer/Counter F1 Compare or Capture A
            TCF1_CCB = 0xA9, // Timer/Counter F1 Compare or Capture B
            SPIF = 0xAA, // SPI F Transfer Complete
            USARTF0_RXC = 0xAB, // USART F0 Receive Complete
            USARTF0_DRE = 0xAC, // USART F0 Data Register Empty
            USARTF1_RXC = 0xAE, // USART F1 Receive Complete
            USARTF1_DRE = 0xAF, // USART F1 Data Register Empty
        };
        CH_TRIGSRCv(const CH_TRIGSRC_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Double buffering mode
    class DBUFMODEv {
    public:
        enum DBUFMODE_ {
            DISABLED = 0x00, // Double buffering disabled
            CH01 = 0x01, // Double buffering enabled on channel 0/1
            CH23 = 0x02, // Double buffering enabled on channel 2/3
            CH01CH23 = 0x03, // Double buffering enabled on ch. 0/1 and ch. 2/3
        };
        DBUFMODEv(const DBUFMODE_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Priority mode
    class PRIMODEv {
    public:
        enum PRIMODE_ {
            RR0123 = 0x00, // Round Robin
            CH0RR123 = 0x01, // Channel 0 > Round Robin on channel 1/2/3
            CH01RR23 = 0x02, // Channel 0 > channel 1 > Round Robin on channel 2/3
            CH0123 = 0x03, // Channel 0 > channel 1 > channel 2 > channel 3
        };
        PRIMODEv(const PRIMODE_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Interrupt level
    class CH_ERRINTLVLv {
    public:
        enum CH_ERRINTLVL_ {
            OFF = 0x00, // Interrupt disabled
            LO = 0x01, // Low level
            MED = 0x02, // Medium level
            HI = 0x03, // High level
        };
        CH_ERRINTLVLv(const CH_ERRINTLVL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Interrupt level
    class CH_TRNINTLVLv {
    public:
        enum CH_TRNINTLVL_ {
            OFF = 0x00, // Interrupt disabled
            LO = 0x01, // Low level
            MED = 0x02, // Medium level
            HI = 0x03, // High level
        };
        CH_TRNINTLVLv(const CH_TRNINTLVL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // DMA ISR Vector Offsets (two bytes each)
    class INTERRUPTS {
    public:
        enum INTERRUPTS_ {
            CH0 = 0, // Channel 0 Interrupt
            CH1 = 1, // Channel 1 Interrupt
            CH2 = 2, // Channel 2 Interrupt
            CH3 = 3, // Channel 3 Interrupt
        };
        INTERRUPTS(const INTERRUPTS_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

};

} // namespace device
