/**
 * XMEGAAU-TWI (id I6089)
 * Two-Wire Interface
 *
 *
 */
#pragma once

#include "device/register.hpp"
#include <cstdint>

namespace device {

/**
 * TWI_MASTER
 *
 * Size: 7 bytes
 */
template <addressType BASE_ADDRESS>
struct TWI_MASTER_t {

    /// Control Register A - 1 bytes
    struct CTRLA : public reg8_t<BASE_ADDRESS + 0x0000> {
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0xC0, 6> INTLVL;    //< Interrupt Level using TWI_MASTER_INTLVL
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x20, 5> RIEN;    //< Read Interrupt Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x10, 4> WIEN;    //< Write Interrupt Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x08, 3> ENABLE;    //< Enable TWI Master using None
    };

    /// Control Register B - 1 bytes
    struct CTRLB : public reg8_t<BASE_ADDRESS + 0x0001> {
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x0C, 2> TIMEOUT;    //< Inactive Bus Timeout using TWI_MASTER_TIMEOUT
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x02, 1> QCEN;    //< Quick Command Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x01, 0> SMEN;    //< Smart Mode Enable using None
    };

    /// Control Register C - 1 bytes
    struct CTRLC : public reg8_t<BASE_ADDRESS + 0x0002> {
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x04, 2> ACKACT;    //< Acknowledge Action using None
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x03, 0> CMD;    //< Command using TWI_MASTER_CMD
    };

    /// Status Register - 1 bytes
    struct STATUS : public reg8_t<BASE_ADDRESS + 0x0003> {
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x80, 7> RIF;    //< Read Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x40, 6> WIF;    //< Write Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x20, 5> CLKHOLD;    //< Clock Hold using None
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x10, 4> RXACK;    //< Received Acknowledge using None
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x08, 3> ARBLOST;    //< Arbitration Lost using None
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x04, 2> BUSERR;    //< Bus Error using None
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x03, 0> BUSSTATE;    //< Bus State using TWI_MASTER_BUSSTATE
    };

    /// Baurd Rate Control Register - 1 bytes
    struct BAUD : public reg8_t<BASE_ADDRESS + 0x0004> {
    };

    /// Address Register - 1 bytes
    struct ADDR : public reg8_t<BASE_ADDRESS + 0x0005> {
    };

    /// Data Register - 1 bytes
    struct DATA : public reg8_t<BASE_ADDRESS + 0x0006> {
    };

    // Master Interrupt Level
    class INTLVLv {
    public:
        enum INTLVL_ {
            OFF = 0x00, // Interrupt Disabled
            LO = 0x01, // Low Level
            MED = 0x02, // Medium Level
            HI = 0x03, // High Level
        };
        INTLVLv(const INTLVL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Inactive Timeout
    class TIMEOUTv {
    public:
        enum TIMEOUT_ {
            DISABLED = 0x00, // Bus Timeout Disabled
            _50US = 0x01, // 50 Microseconds
            _100US = 0x02, // 100 Microseconds
            _200US = 0x03, // 200 Microseconds
        };
        TIMEOUTv(const TIMEOUT_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Master Command
    class CMDv {
    public:
        enum CMD_ {
            NOACT = 0x00, // No Action
            REPSTART = 0x01, // Issue Repeated Start Condition
            RECVTRANS = 0x02, // Receive or Transmit Data
            STOP = 0x03, // Issue Stop Condition
        };
        CMDv(const CMD_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Master Bus State
    class BUSSTATEv {
    public:
        enum BUSSTATE_ {
            UNKNOWN = 0x00, // Unknown Bus State
            IDLE = 0x01, // Bus is Idle
            OWNER = 0x02, // This Module Controls The Bus
            BUSY = 0x03, // The Bus is Busy
        };
        BUSSTATEv(const BUSSTATE_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    static void enable() {
        CTRLA::ENABLE::write(1);
    }

    static void disable() {
        CTRLA::ENABLE::write(0);
    }

    static void enable_interrupts(const bool read, const bool write, const INTLVLv lvl) {
        CTRLA::write(
            lvl << CTRLA::INTLVL::SHIFT
            | read  << CTRLA::RIEN::SHIFT
            | write << CTRLA::WIEN::SHIFT
            | CTRLA::read() & CTRLA::ENABLE::BIT_MASK
        );
    }

    /// inactive bus timeout bits to a nonzero value will enable the inactive bus timeout supervisor
    static void set_timout(const TIMEOUTv tmout) {
        CTRLB::TIMEOUT::write(tmout);
    }

    /// When quick command is enabled, the corresponding interrupt flag is set immediately after the slave
    /// acknowledges the address (read or write interrupt). At this point, software can issue either a STOP or a repeated START condition.
    static void enable_quick_command(const bool enable) {
        CTRLB::QCEN::write(enable);
    }

    /// enable quick command mode. This makes a ACK automatically when reading the DATA register
    static void enable_smart_mode(const bool enable) {
        CTRLB::SMEN::write(enable);
    }

    /// perform acknolwedge action followed by repeated stop condition
    static void set_start(const bool ack = false) {
        CTRLC::write( ack << CTRLC::ACKACT::SHIFT | CMDv::START << CTRLC::CMD::SHIFT );
    }

    /// perform acknolwedge action followed by repeated start condition
    static void set_stop(const bool ack) {
        CTRLC::write( ack << CTRLC::ACKACT::SHIFT | CMDv::STOP << CTRLC::CMD::SHIFT );
    }

    /// perform acknolwedge action followed by a byte receive. Does nothing in write mode
    static void receive(const bool ack) {
        CTRLC::write( ack << CTRLC::ACKACT::SHIFT | CMDv::BYTEREC << CTRLC::CMD::SHIFT );
    }

    static bool check_read_write_flags() {
        return STATUS::read() & (STATUS::RIF::BIT_MASK | STATUS::WIF::BIT_MASK);
    }

    static void clear_interrupt_flags() {
        STATUS::write( STATUS::RIF::BIT_MASK | STATUS::WIF::BIT_MASK | STATUS::BUSSTATE::read());
    }

    static void clear_bus_error() {
        STATUS::write( STATUS::BUSERR::BIT_MASK | STATUS::BUSSTATE::read());
    }

    static void clear_arb_lost() {
        STATUS::write( STATUS::ARBLOST::BIT_MASK | STATUS::BUSSTATE::read());
    }

    static void set_baud(const uint16_t PER_CLK, const uint32_t b, const uint8_t trise = 0) {
        BAUD::write( ((((((float)PER_CLK / (float)b)) - 10 - ((float)PER_CLK * trise / 1000000))) / 2) );
    }

    static void write_address(const uint8_t addr) {
        ADDR::write(addr);
    }

    static void write_data(const uint8_t addr) {
        DATA::write(addr);
    }

    static uint8_t read_data() {
        return DATA::read();
    }

};

/**
 * TWI_SLAVE
 *
 * Size: 6 bytes
 */
template <addressType BASE_ADDRESS>
struct TWI_SLAVE_t {

    /// Control Register A - 1 bytes
    struct CTRLA : public reg8_t<BASE_ADDRESS + 0x0000> {
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0xC0, 6> INTLVL;    //< Interrupt Level using TWI_SLAVE_INTLVL
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x20, 5> DIEN;    //< Data Interrupt Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x10, 4> APIEN;    //< Address/Stop Interrupt Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x08, 3> ENABLE;    //< Enable TWI Slave using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x04, 2> PIEN;    //< Stop Interrupt Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x02, 1> PMEN;    //< Promiscuous Mode Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x01, 0> SMEN;    //< Smart Mode Enable using None
    };

    /// Control Register B - 1 bytes
    struct CTRLB : public reg8_t<BASE_ADDRESS + 0x0001> {
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x04, 2> ACKACT;    //< Acknowledge Action using None
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x03, 0> CMD;    //< Command using TWI_SLAVE_CMD
    };

    /// Status Register - 1 bytes
    struct STATUS : public reg8_t<BASE_ADDRESS + 0x0002> {
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x80, 7> DIF;    //< Data Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x40, 6> APIF;    //< Address/Stop Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x20, 5> CLKHOLD;    //< Clock Hold using None
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x10, 4> RXACK;    //< Received Acknowledge using None
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x08, 3> COLL;    //< Collision using None
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x04, 2> BUSERR;    //< Bus Error using None
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x02, 1> DIR;    //< Read/Write Direction using None
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x01, 0> AP;    //< Slave Address or Stop using None
    };

    /// Address Register - 1 bytes
    struct ADDR : public reg8_t<BASE_ADDRESS + 0x0003> {
    };

    /// Data Register - 1 bytes
    struct DATA : public reg8_t<BASE_ADDRESS + 0x0004> {
    };

    /// Address Mask Register - 1 bytes
    struct ADDRMASK : public reg8_t<BASE_ADDRESS + 0x0005> {
        typedef reg_field_t<BASE_ADDRESS + 0x0005, 0xFE, 1> ADDRMASK;    //< Address Mask using None
        typedef reg_field_t<BASE_ADDRESS + 0x0005, 0x01, 0> ADDREN;    //< Address Enable using None
    };

    // Slave Interrupt Level
    class INTLVLv {
    public:
        enum INTLVL_ {
            OFF = 0x00, // Interrupt Disabled
            LO = 0x01, // Low Level
            MED = 0x02, // Medium Level
            HI = 0x03, // High Level
        };
        INTLVLv(const INTLVL_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // Slave Command
    class CMDv {
    public:
        enum CMD_ {
            NOACT = 0x00, // No Action
            COMPTRANS = 0x02, // Used To Complete a Transaction
            RESPONSE = 0x03, // Used in Response to Address/Data Interrupt
        };
        CMDv(const CMD_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    /// enable the Data and/or address interrupt and set the level
    static void set_interrupts(const bool data, const bool address, const bool stop, const INTLVLv lvl) {
        CTRLA::write(
            lvl << CTRLA::INTLVL::SHIFT
            | data  << CTRLA::DIEN::SHIFT
            | address << CTRLA::APIEN::SHIFT
            | stop << CTRLA::PIEN::SHIFT
            | CTRLA::read() & CTRLA::ENABLE::BIT_MASK
        );
    }

    static void enable() {
        CTRLA::ENABLE::write(1);
    }

    static void disable() {
        CTRLA::ENABLE::write(0);
    }

    static void promiscuous_mode(const bool en) {
        CTRLA::PMEN::write(en);
    }

    static void smart_mode(const bool en) {
        CTRLA::SMEN::write(en);
    }

    static void clear_interrupt() {
        STATUS::write( STATUS::DIF::BIT_MASK | STATUS::APIF::BIT_MASK );
    }

    static void clear_bus_errors() {
        STATUS::write( STATUS::COLL::BIT_MASK | STATUS::BUSERR::BIT_MASK );
    }

    /// set the 7 bit slave adderss to respond to (bits 0-6). Reponds to general call as well if general_call is set to true
    static void set_address(const uint8_t addr, const bool general_call = false) {
        ADDR::write(addr<<1 | general_call);
    }

    /// sets a second address that the device will respond to, using a 7 bit address (lower 7 bits)
    static void set_second_address(const uint8_t addr) {
        ADDRMASK::write(addr<<1 | 0x1);
    }

    /// set bits in the 7-bit address that are ALWAYS matched. bottom 7 bits of the value.
    static void set_addresss_mask(const uint8_t mask) {
        ADDRMASK::write(mask<<1);
    }

    static void write_data(const uint8_t addr) {
        DATA::write(addr);
    }

    static uint8_t read_data() {
        DATA::read();
    }

};

/**
 * TWI
 * Two-Wire Interface
 * Size: 14 bytes
 */
template <addressType BASE_ADDRESS>
struct TWI_t {

    /// TWI Common Control Register - 1 bytes
    struct CTRL : public reg8_t<BASE_ADDRESS + 0x0000> {
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x06, 1> SDAHOLD;    //< SDA Hold Time Enable using TWI_SDAHOLD
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x01, 0> EDIEN;    //< External Driver Interface Enable using None
    };
    /// TWI master module
    TWI_MASTER_t<BASE_ADDRESS + 0x0001> MASTER;

    /// TWI slave module
    TWI_SLAVE_t<BASE_ADDRESS + 0x0008> SLAVE;

    // SDA Hold Time
    class SDAHOLDv {
    public:
        enum SDAHOLD_ {
            OFF = 0x00, // SDA Hold Time off
            _50NS = 0x01, // SDA Hold Time 50 ns
            _300NS = 0x02, // SDA Hold Time 300 ns
            _400NS = 0x03, // SDA Hold Time 400 ns
        };
        SDAHOLDv(const SDAHOLD_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

    // TWI ISR Vector Offsets (two bytes each)
    class INTERRUPTS {
    public:
        enum INTERRUPTS_ {
            TWIS = 0, // TWI Slave Interrupt
            TWIM = 1, // TWI Master Interrupt
        };
        INTERRUPTS(const INTERRUPTS_& v) : value_(v) {}
        operator uint8_t() const { return value_; }
    private:
        uint8_t value_;
    };

};

} // namespace device
