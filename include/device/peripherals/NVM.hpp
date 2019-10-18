/**
 * XMEGAAU-NVM (id I6076)
 * Non Volatile Memory Controller
 *
 *
 */
#pragma once

#include "device/register.hpp"
#include <cstdint>

namespace device {

/**
 * NVM
 * Non-volatile Memory Controller
 * Size: 17 bytes
 */
template <addressType BASE_ADDRESS>
struct NVM_t {

    /// Address Register 0 - 1 bytes
    struct ADDR0 : public reg8_t<BASE_ADDRESS + 0x0000> {
    };

    /// Address Register 1 - 1 bytes
    struct ADDR1 : public reg8_t<BASE_ADDRESS + 0x0001> {
    };

    /// Address Register 2 - 1 bytes
    struct ADDR2 : public reg8_t<BASE_ADDRESS + 0x0002> {
    };

    /// Data Register 0 - 1 bytes
    struct DATA0 : public reg8_t<BASE_ADDRESS + 0x0004> {
    };

    /// Data Register 1 - 1 bytes
    struct DATA1 : public reg8_t<BASE_ADDRESS + 0x0005> {
    };

    /// Data Register 2 - 1 bytes
    struct DATA2 : public reg8_t<BASE_ADDRESS + 0x0006> {
    };

    /// Command - 1 bytes
    struct CMD : public reg8_t<BASE_ADDRESS + 0x000A> {
        typedef reg_field_t<BASE_ADDRESS + 0x000A, 0x7F, 0> CMD;    //< Command using NVM_CMD
    };

    /// Control Register A - 1 bytes
    struct CTRLA : public reg8_t<BASE_ADDRESS + 0x000B> {
        typedef reg_field_t<BASE_ADDRESS + 0x000B, 0x01, 0> CMDEX;    //< Command Execute using None
    };

    /// Control Register B - 1 bytes
    struct CTRLB : public reg8_t<BASE_ADDRESS + 0x000C> {
        typedef reg_field_t<BASE_ADDRESS + 0x000C, 0x08, 3> EEMAPEN;    //< EEPROM Mapping Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x000C, 0x04, 2> FPRM;    //< Flash Power Reduction Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x000C, 0x02, 1> EPRM;    //< EEPROM Power Reduction Enable using None
        typedef reg_field_t<BASE_ADDRESS + 0x000C, 0x01, 0> SPMLOCK;    //< SPM Lock using None
    };

    /// Interrupt Control - 1 bytes
    struct INTCTRL : public reg8_t<BASE_ADDRESS + 0x000D> {
        typedef reg_field_t<BASE_ADDRESS + 0x000D, 0x0C, 2> SPMLVL;    //< SPM Interrupt Level using NVM_SPMLVL
        typedef reg_field_t<BASE_ADDRESS + 0x000D, 0x03, 0> EELVL;    //< EEPROM Interrupt Level using NVM_EELVL
    };

    /// Status - 1 bytes
    struct STATUS : public reg8_t<BASE_ADDRESS + 0x000F> {
        typedef reg_field_t<BASE_ADDRESS + 0x000F, 0x80, 7> NVMBUSY;    //< Non-volatile Memory Busy using None
        typedef reg_field_t<BASE_ADDRESS + 0x000F, 0x40, 6> FBUSY;    //< Flash Memory Busy using None
        typedef reg_field_t<BASE_ADDRESS + 0x000F, 0x02, 1> EELOAD;    //< EEPROM Page Buffer Active Loading using None
        typedef reg_field_t<BASE_ADDRESS + 0x000F, 0x01, 0> FLOAD;    //< Flash Page Buffer Active Loading using None
    };

    /// Lock Bits - 1 bytes
    struct LOCKBITS : public reg8_t<BASE_ADDRESS + 0x0010> {
        typedef reg_field_t<BASE_ADDRESS + 0x0010, 0xC0, 6> BLBB;    //< Boot Lock Bits - Boot Section using NVM_BLBB
        typedef reg_field_t<BASE_ADDRESS + 0x0010, 0x30, 4> BLBA;    //< Boot Lock Bits - Application Section using NVM_BLBA
        typedef reg_field_t<BASE_ADDRESS + 0x0010, 0x0C, 2> BLBAT;    //< Boot Lock Bits - Application Table using NVM_BLBAT
        typedef reg_field_t<BASE_ADDRESS + 0x0010, 0x03, 0> LB;    //< Lock Bits using NVM_LB
    };
};

namespace NVM {

    // NVM Command
    class CMD {
    private:
        enum CMD_ {
            NO_OPERATION_ = 0x00, // Noop/Ordinary LPM
            READ_USER_SIG_ROW_ = 0x01, // Read user signature row
            READ_CALIB_ROW_ = 0x02, // Read calibration row
            READ_EEPROM_ = 0x06, // Read EEPROM
            READ_FUSES_ = 0x07, // Read fuse byte
            WRITE_LOCK_BITS_ = 0x08, // Write lock bits
            ERASE_USER_SIG_ROW_ = 0x18, // Erase user signature row
            WRITE_USER_SIG_ROW_ = 0x1A, // Write user signature row
            ERASE_APP_ = 0x20, // Erase Application Section
            ERASE_APP_PAGE_ = 0x22, // Erase Application Section page
            LOAD_FLASH_BUFFER_ = 0x23, // Load Flash page buffer
            WRITE_APP_PAGE_ = 0x24, // Write Application Section page
            ERASE_WRITE_APP_PAGE_ = 0x25, // Erase-and-write Application Section page
            ERASE_FLASH_BUFFER_ = 0x26, // Erase/flush Flash page buffer
            ERASE_BOOT_PAGE_ = 0x2A, // Erase Boot Section page
            ERASE_FLASH_PAGE_ = 0x2B, // Erase Flash Page
            WRITE_BOOT_PAGE_ = 0x2C, // Write Boot Section page
            ERASE_WRITE_BOOT_PAGE_ = 0x2D, // Erase-and-write Boot Section page
            WRITE_FLASH_PAGE_ = 0x2E, // Write Flash Page
            ERASE_WRITE_FLASH_PAGE_ = 0x2F, // Erase-and-write Flash Page
            ERASE_EEPROM_ = 0x30, // Erase EEPROM
            ERASE_EEPROM_PAGE_ = 0x32, // Erase EEPROM page
            LOAD_EEPROM_BUFFER_ = 0x33, // Load EEPROM page buffer
            WRITE_EEPROM_PAGE_ = 0x34, // Write EEPROM page
            ERASE_WRITE_EEPROM_PAGE_ = 0x35, // Erase-and-write EEPROM page
            ERASE_EEPROM_BUFFER_ = 0x36, // Erase/flush EEPROM page buffer
            APP_CRC_ = 0x38, // Application section CRC
            BOOT_CRC_ = 0x39, //  Boot Section CRC
            FLASH_RANGE_CRC_ = 0x3A, // Flash Range CRC
            CHIP_ERASE_ = 0x40, // Erase Chip
            READ_NVM_ = 0x43, // Read NVM
            WRITE_FUSE_ = 0x4C, // Write Fuse byte
            ERASE_BOOT_ = 0x68, // Erase Boot Section
            FLASH_CRC_ = 0x78, // Flash CRC
        };
        CMD_ value_;
    public:
        static const CMD NO_OPERATION, READ_USER_SIG_ROW, READ_CALIB_ROW, READ_EEPROM, READ_FUSES, WRITE_LOCK_BITS, ERASE_USER_SIG_ROW, WRITE_USER_SIG_ROW, ERASE_APP, ERASE_APP_PAGE, LOAD_FLASH_BUFFER, WRITE_APP_PAGE, ERASE_WRITE_APP_PAGE, ERASE_FLASH_BUFFER, ERASE_BOOT_PAGE, ERASE_FLASH_PAGE, WRITE_BOOT_PAGE, ERASE_WRITE_BOOT_PAGE, WRITE_FLASH_PAGE, ERASE_WRITE_FLASH_PAGE, ERASE_EEPROM, ERASE_EEPROM_PAGE, LOAD_EEPROM_BUFFER, WRITE_EEPROM_PAGE, ERASE_WRITE_EEPROM_PAGE, ERASE_EEPROM_BUFFER, APP_CRC, BOOT_CRC, FLASH_RANGE_CRC, CHIP_ERASE, READ_NVM, WRITE_FUSE, ERASE_BOOT, FLASH_CRC;
        explicit CMD(const CMD_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // SPM ready interrupt level
    class SPMLVL {
    private:
        enum SPMLVL_ {
            OFF_ = 0x00, // Interrupt disabled
            LO_ = 0x01, // Low level
            MED_ = 0x02, // Medium level
            HI_ = 0x03, // High level
        };
        SPMLVL_ value_;
    public:
        static const SPMLVL OFF, LO, MED, HI;
        explicit SPMLVL(const SPMLVL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // EEPROM ready interrupt level
    class EELVL {
    private:
        enum EELVL_ {
            OFF_ = 0x00, // Interrupt disabled
            LO_ = 0x01, // Low level
            MED_ = 0x02, // Medium level
            HI_ = 0x03, // High level
        };
        EELVL_ value_;
    public:
        static const EELVL OFF, LO, MED, HI;
        explicit EELVL(const EELVL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Boot lock bits - boot setcion
    class BLBB {
    private:
        enum BLBB_ {
            RWLOCK_ = 0x00, // Read and write not allowed
            RLOCK_ = 0x01, // Read not allowed
            WLOCK_ = 0x02, // Write not allowed
            NOLOCK_ = 0x03, // No locks
        };
        BLBB_ value_;
    public:
        static const BLBB RWLOCK, RLOCK, WLOCK, NOLOCK;
        explicit BLBB(const BLBB_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Boot lock bits - application section
    class BLBA {
    private:
        enum BLBA_ {
            RWLOCK_ = 0x00, // Read and write not allowed
            RLOCK_ = 0x01, // Read not allowed
            WLOCK_ = 0x02, // Write not allowed
            NOLOCK_ = 0x03, // No locks
        };
        BLBA_ value_;
    public:
        static const BLBA RWLOCK, RLOCK, WLOCK, NOLOCK;
        explicit BLBA(const BLBA_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Boot lock bits - application table section
    class BLBAT {
    private:
        enum BLBAT_ {
            RWLOCK_ = 0x00, // Read and write not allowed
            RLOCK_ = 0x01, // Read not allowed
            WLOCK_ = 0x02, // Write not allowed
            NOLOCK_ = 0x03, // No locks
        };
        BLBAT_ value_;
    public:
        static const BLBAT RWLOCK, RLOCK, WLOCK, NOLOCK;
        explicit BLBAT(const BLBAT_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Lock bits
    class LB {
    private:
        enum LB_ {
            RWLOCK_ = 0x00, // Read and write not allowed
            WLOCK_ = 0x02, // Write not allowed
            NOLOCK_ = 0x03, // No locks
        };
        LB_ value_;
    public:
        static const LB RWLOCK, WLOCK, NOLOCK;
        explicit LB(const LB_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };


    // NVM Interrupts
    class INTERRUPTS {
    private:
        enum NVM_VECTORS_ {
            EE_ = 0, // EE Interrupt
            SPM_ = 1, // SPM Interrupt
        };
        NVM_VECTORS_ value_;
    public:
        static const NVM EE, SPM;
        explicit NVM(const NVM_VECTORS_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

} // namespace NVM
} // namespace device
