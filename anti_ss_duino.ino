#include "Mouse.h"

#include "posTable.h"

const uint32_t intervalMs = 30 * 1000;
const uint32_t moveSpeedMs = 10;

void setup() {
    Mouse.begin();
}

void loop() {
    const uint32_t len = sizeof(posTable) / sizeof(posTable[0]);
    for(uint32_t current = 0;  current < len; current++) {
        const uint32_t next = (current < (len - 1)) ? (current + 1) : 0;
        const int16_t xDiff = posTable[next][0] - posTable[current][0];
        const int16_t yDiff = posTable[next][1] - posTable[current][1];
        Mouse.move(xDiff, yDiff, 0);
        delay(moveSpeedMs);
    }

    // めっちゃ待つ
    delay(intervalMs);
}