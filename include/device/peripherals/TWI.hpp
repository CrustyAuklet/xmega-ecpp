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

};

namespace TWI {

    // SDA Hold Time
    class SDAHOLD {
    private:
        enum SDAHOLD_ {
            OFF_ = 0x00, // SDA Hold Time off
            _50NS_ = 0x01, // SDA Hold Time 50 ns
            _300NS_ = 0x02, // SDA Hold Time 300 ns
            _400NS_ = 0x03, // SDA Hold Time 400 ns
        };
        SDAHOLD_ value_;
    public:
        static const SDAHOLD OFF, _50NS, _300NS, _400NS;
        explicit SDAHOLD(const SDAHOLD_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Master Interrupt Level
    class MASTER_INTLVL {
    private:
        enum MASTER_INTLVL_ {
            OFF_ = 0x00, // Interrupt Disabled
            LO_ = 0x01, // Low Level
            MED_ = 0x02, // Medium Level
            HI_ = 0x03, // High Level
        };
        MASTER_INTLVL_ value_;
    public:
        static const MASTER_INTLVL OFF, LO, MED, HI;
        explicit MASTER_INTLVL(const MASTER_INTLVL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Inactive Timeout
    class MASTER_TIMEOUT {
    private:
        enum MASTER_TIMEOUT_ {
            DISABLED_ = 0x00, // Bus Timeout Disabled
            _50US_ = 0x01, // 50 Microseconds
            _100US_ = 0x02, // 100 Microseconds
            _200US_ = 0x03, // 200 Microseconds
        };
        MASTER_TIMEOUT_ value_;
    public:
        static const MASTER_TIMEOUT DISABLED, _50US, _100US, _200US;
        explicit MASTER_TIMEOUT(const MASTER_TIMEOUT_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Master Command
    class MASTER_CMD {
    private:
        enum MASTER_CMD_ {
            NOACT_ = 0x00, // No Action
            REPSTART_ = 0x01, // Issue Repeated Start Condition
            RECVTRANS_ = 0x02, // Receive or Transmit Data
            STOP_ = 0x03, // Issue Stop Condition
        };
        MASTER_CMD_ value_;
    public:
        static const MASTER_CMD NOACT, REPSTART, RECVTRANS, STOP;
        explicit MASTER_CMD(const MASTER_CMD_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Master Bus State
    class MASTER_BUSSTATE {
    private:
        enum MASTER_BUSSTATE_ {
            UNKNOWN_ = 0x00, // Unknown Bus State
            IDLE_ = 0x01, // Bus is Idle
            OWNER_ = 0x02, // This Module Controls The Bus
            BUSY_ = 0x03, // The Bus is Busy
        };
        MASTER_BUSSTATE_ value_;
    public:
        static const MASTER_BUSSTATE UNKNOWN, IDLE, OWNER, BUSY;
        explicit MASTER_BUSSTATE(const MASTER_BUSSTATE_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Slave Interrupt Level
    class SLAVE_INTLVL {
    private:
        enum SLAVE_INTLVL_ {
            OFF_ = 0x00, // Interrupt Disabled
            LO_ = 0x01, // Low Level
            MED_ = 0x02, // Medium Level
            HI_ = 0x03, // High Level
        };
        SLAVE_INTLVL_ value_;
    public:
        static const SLAVE_INTLVL OFF, LO, MED, HI;
        explicit SLAVE_INTLVL(const SLAVE_INTLVL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Slave Command
    class SLAVE_CMD {
    private:
        enum SLAVE_CMD_ {
            NOACT_ = 0x00, // No Action
            COMPTRANS_ = 0x02, // Used To Complete a Transaction
            RESPONSE_ = 0x03, // Used in Response to Address/Data Interrupt
        };
        SLAVE_CMD_ value_;
    public:
        static const SLAVE_CMD NOACT, COMPTRANS, RESPONSE;
        explicit SLAVE_CMD(const SLAVE_CMD_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };


    // TWI Interrupts
    class INTERRUPTS {
    private:
        enum TWI_VECTORS_ {
            TWIS_ = 0, // TWI Slave Interrupt
            TWIM_ = 1, // TWI Master Interrupt
        };
        TWI_VECTORS_ value_;
    public:
        static const TWI TWIS, TWIM;
        explicit TWI(const TWI_VECTORS_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

} // namespace TWI
} // namespace device
