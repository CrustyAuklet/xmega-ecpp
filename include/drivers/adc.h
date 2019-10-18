#ifndef UT_HAL_ADC_XMEGA
#define UT_HAL_ADC_XMEGA

#include <cstdint>
#include "device.h"

namespace device {

    template <class ADC_INSTANCE, uint8_t CHANNEL>
    class analog {
    public:

        static bool init() {
            return true;
        }

        static bool begin() {
            // channel is unused.. it just turns on the entire ADC?
            //hri_adc_set_CTRLA_ENABLE_bit(ADC_INSTANCE::value());
            return true;
        }

        static bool end() {
            // no disable for now, different channels could be used in different threads?
            // probably need a ref count or something
            return true;
        }

        static uint16_t read() {
            /***
            hri_adc_set_SWTRIG_START_bit(ADC_INSTANCE::value());
            while (!hri_adc_get_interrupt_RESRDY_bit(ADC_INSTANCE::value())) {}
            uint16_t result = hri_adc_read_RESULT_reg(ADC_INSTANCE::value());

            const uint8_t dataSize = hri_adc_read_CTRLC_RESSEL_bf(ADC_INSTANCE::value()) == ADC_CTRLC_RESSEL_8BIT_Val ? 1 : 2;
            if(1 < dataSize) {
                result = result >> 8;
            }
            return result;
            ***/
        }
    };

}   // namespace device

#endif  // UT_HAL_ADC_XMEGA