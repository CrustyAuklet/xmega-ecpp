#include "include/board.h"
#include <intrinsics.h>

typedef board::Serial_C0 SOut;

int main( void )
{
    SOut::init<9600, true>();

    while(1) {
        __delay_cycles(500000);  // Wait for 500 000 cycles
        SOut::write("Hello World\n", 12);
    }
}
