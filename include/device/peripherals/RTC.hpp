/**
 * None-RTC (id I6093)
 * Real-Time Counter
 *
 *
 */
#pragma once

#include "device/register.hpp"
#include <cstdint>

namespace device {

/**
 * RTC
 * Real-Time Counter
 * Size: 14 bytes
 */
template <addressType BASE_ADDRESS>
struct RTC_t {

    /// Control Register - 1 bytes
    struct CTRL : public reg8_t<BASE_ADDRESS + 0x0000> {
        typedef reg_field_t<BASE_ADDRESS + 0x0000, 0x07, 0> PRESCALER;    //< Prescaling Factor using RTC_PRESCALER
    };

    /// Status Register - 1 bytes
    struct STATUS : public reg8_t<BASE_ADDRESS + 0x0001> {
        typedef reg_field_t<BASE_ADDRESS + 0x0001, 0x01, 0> SYNCBUSY;    //< Synchronization Busy Flag using None
    };

    /// Interrupt Control Register - 1 bytes
    struct INTCTRL : public reg8_t<BASE_ADDRESS + 0x0002> {
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x0C, 2> COMPINTLVL;    //< Compare Match Interrupt Level using RTC_COMPINTLVL
        typedef reg_field_t<BASE_ADDRESS + 0x0002, 0x03, 0> OVFINTLVL;    //< Overflow Interrupt Level using RTC_OVFINTLVL
    };

    /// Interrupt Flags - 1 bytes
    struct INTFLAGS : public reg8_t<BASE_ADDRESS + 0x0003> {
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x02, 1> COMPIF;    //< Compare Match Interrupt Flag using None
        typedef reg_field_t<BASE_ADDRESS + 0x0003, 0x01, 0> OVFIF;    //< Overflow Interrupt Flag using None
    };

    /// Temporary register - 1 bytes
    struct TEMP : public reg8_t<BASE_ADDRESS + 0x0004> {
    };

    /// Count Register - 2 bytes
    struct CNT : public reg16_t<BASE_ADDRESS + 0x0008> {
    };

    /// Period Register - 2 bytes
    struct PER : public reg16_t<BASE_ADDRESS + 0x000A> {
    };

    /// Compare Register - 2 bytes
    struct COMP : public reg16_t<BASE_ADDRESS + 0x000C> {
    };
};

namespace RTC {

    // Prescaler Factor
    class PRESCALER {
    private:
        enum PRESCALER_ {
            OFF_ = 0x00, // RTC Off
            DIV1_ = 0x01, // RTC Clock
            DIV2_ = 0x02, // RTC Clock / 2
            DIV8_ = 0x03, // RTC Clock / 8
            DIV16_ = 0x04, // RTC Clock / 16
            DIV64_ = 0x05, // RTC Clock / 64
            DIV256_ = 0x06, // RTC Clock / 256
            DIV1024_ = 0x07, // RTC Clock / 1024
        };
        PRESCALER_ value_;
    public:
        static const PRESCALER OFF, DIV1, DIV2, DIV8, DIV16, DIV64, DIV256, DIV1024;
        explicit PRESCALER(const PRESCALER_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Compare Interrupt level
    class COMPINTLVL {
    private:
        enum COMPINTLVL_ {
            OFF_ = 0x00, // Interrupt Disabled
            LO_ = 0x01, // Low Level
            MED_ = 0x02, // Medium Level
            HI_ = 0x03, // High Level
        };
        COMPINTLVL_ value_;
    public:
        static const COMPINTLVL OFF, LO, MED, HI;
        explicit COMPINTLVL(const COMPINTLVL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

    // Overflow Interrupt level
    class OVFINTLVL {
    private:
        enum OVFINTLVL_ {
            OFF_ = 0x00, // Interrupt Disabled
            LO_ = 0x01, // Low Level
            MED_ = 0x02, // Medium Level
            HI_ = 0x03, // High Level
        };
        OVFINTLVL_ value_;
    public:
        static const OVFINTLVL OFF, LO, MED, HI;
        explicit OVFINTLVL(const OVFINTLVL_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };


    // RTC Interrupts
    class INTERRUPTS {
    private:
        enum RTC_VECTORS_ {
            OVF_ = 0, // Overflow Interrupt
            COMP_ = 1, // Compare Interrupt
        };
        RTC_VECTORS_ value_;
    public:
        static const RTC OVF, COMP;
        explicit RTC(const RTC_VECTORS_& v) : value_(v) {}
        operator uint8_t() { return static_cast<uint8_t>(value_); }
    };

} // namespace RTC
} // namespace device
