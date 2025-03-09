#include "C810.hpp"
#include "mbed.h"

BufferedSerial pc(USBTX, USBRX, 115200);
InterruptIn button(BUTTON1);
C810 c810(D6); // PWMピン指定
auto pre = HighResClock::now();
int target = 1000;

int main() {
    // c810.setup();
    button.mode(PullUp);
    while (1) {
        if (!button.read()) {
            target = std::max(2000, target + 3);
            c810.write(target);
        } else {
            target = std::max(1000, target - 3);
            c810.write(target);
        }
        ThisThread::sleep_for(10ms);
    }
}
