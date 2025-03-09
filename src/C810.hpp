#ifndef RCT_C810_HPP
#define RCT_C810_HPP
/// @file
/// @brief Provides motor driver C810 class for C810 (common name).
/// @copyright Copyright (c) 2025 Okabe Minato
/// @license

#include <mbed.h>

/// @brief モータードライバC810クラス。
class C810 {
  public:
    /// @brief コンストラクタ。PWMピンを指定して初期化する。
    /// @param pwm_pin PWMピン
    C810(PinName pwm_pin) : servo(pwm_pin) {}

    /// @brief
    /// 初期設定を行う。初回のみ実行。二回目以降は不要。いい感じの音がなったらok
    void setup() {
        printf("set_minimum value\n");
        servo.pulsewidth_us(2000);
        printf("set_maximum value\n");
        ThisThread::sleep_for(2000ms);
        servo.pulsewidth_us(1000);
        printf("end_Standby for 2 seconds\n");
        ThisThread::sleep_for(2000ms);
    }

    /// @brief モーターのパルス幅を設定する。
    /// @param target 設定するパルス幅
    void write(int target) {
        target = std::max(1000, std::min(target, 2000));
        servo.pulsewidth_us(target);
    }

  private:
    PwmOut servo;
    int target;
};

#endif // RCT_C810_HPP
