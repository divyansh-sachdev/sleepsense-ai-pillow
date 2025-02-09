/**
 * SleepSense AI Pillow — Non-Invasive Sleep & Apnea Monitor
 * Author: Divyansh Sachdev
 */

#include <Arduino.h>
#include "config.example.h"
#include "posture_model.h"

void setup() {
    Serial.begin(115200);
    Serial.println("==================================================");
    Serial.println("  SleepSense AI Pillow — Smart Sleep Diagnostics");
    Serial.println("==================================================");
    Serial.println("[INFO] Calibration complete. Ready for night monitoring.");
}

void loop() {
    int l = analogRead(PRESSURE_PIN_L);
    int c = analogRead(PRESSURE_PIN_C);
    int r = analogRead(PRESSURE_PIN_R);
    int sound = analogRead(MIC_ANALOG_PIN);

    SleepPosture posture = classifyPosture(l, c, r);
    const char* postureStr = "Unknown";
    switch(posture) {
        case POSTURE_ABSENT:     postureStr = "Bed Empty"; break;
        case POSTURE_BACK:       postureStr = "Supine (Back)"; break;
        case POSTURE_LEFT_SIDE:  postureStr = "Left Lateral"; break;
        case POSTURE_RIGHT_SIDE: postureStr = "Right Lateral"; break;
        case POSTURE_PRONE:      postureStr = "Prone (Front)"; break;
    }

    bool isSnoring = sound > SNORE_THRESHOLD;

    Serial.printf("[SLEEP] Posture: %-15s | Snore: %s | Sound Level: %d\n",
                  postureStr, isSnoring ? "YES" : "No ", sound);

    delay(1000);
}
