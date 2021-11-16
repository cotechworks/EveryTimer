#include <EveryTimer.h>

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.print(TCB2_CCMP);
  Serial.print(",");
  Serial.print(TCB2_CTRLA);
  Serial.print(",");
  Serial.print(TCB2_CTRLB);
  Serial.println("");

  TCB2_CCMP = 1000;  //TOP値の設定
  TCB2_CTRLB = 0b00000000;
  TCB2_CTRLA = (TCB2_CTRLA & 0b11111000) + 0b00000001;  //カウント周期を設定してカウントスタート

  
}

void loop() {
  // Serial.print(TCB2_CTRLB, BIN);
  // Serial.print(",");
  // Serial.print(TCB2_CTRLA, BIN);
  // Serial.print(",");
  // Serial.print(TCB2_CNT, DEC);
  // Serial.print(",");
  // Serial.print(TCB2_CNT, DEC);
  // Serial.print(",");

  // Serial.println("");
  delay(100);
}
