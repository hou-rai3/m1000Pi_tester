#include "mbed.h"

BufferedSerial pc(USBTX, USBRX, 115200);
InterruptIn button(BUTTON1);
PwmOut servo(D6);
auto pre = HighResClock::now();
int target;

void c810_setup() { // 初回のみ実行。二回目以降は不要
    printf("target start\n");
    target = 2000;
    servo.pulsewidth_us(target);
    printf("wait 2000ms\n");
    ThisThread::sleep_for(2000ms);
    target = 1000;
    servo.pulsewidth_us(target);
    printf("target end\n");
    ThisThread::sleep_for(2000ms);
}

void fire_c810() {
    if (!button.read()) {
        target = 1500;
    } else {
        target = 1000;
    }
    servo.pulsewidth_us(target);
}
int main() {
    // c810_setup();
    button.mode(PullUp);
    while (1) {
        fire_c810();
    }
}