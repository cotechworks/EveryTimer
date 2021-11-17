int a = 1;

void setup() {
  pinMode(2, OUTPUT);

  TCB2.CCMP = 25000;  // TOP値の設定
  TCB2.CTRLB = (TCB2.CTRLB & 0b10101000) + 0b00000000;  //タイマーのGPIO出力ON、クロックソースを設定
  TCB2.CTRLA = (TCB2.CTRLA & 0b11111000) + 0b00000101;  //カウント周期を設定してカウントスタート
  TCB2.INTCTRL = 1;  //割り込み許可
}

void loop() {

}

ISR(TCB2_INT_vect) {
  TCB2.INTFLAGS = 1;  //割り込みフラグのクリア
  if (a == 1) {
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(2, LOW);
  }
  a = 1 - a;
}
