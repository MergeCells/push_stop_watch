
#define SW_Btn 3

#define PUSH_Limit 8000
#define WAIT_Limit 1000

long hoge;
long huga;

void setup() {
  pinMode(SW_Btn, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("start");
  hoge = 0;
}

void loop() {
  if (digitalRead(SW_Btn) == HIGH) {
    while (digitalRead(SW_Btn) == HIGH) {}
    
    if ((millis() - hoge) >= WAIT_Limit) {
      huga = WAIT_Limit;
    } else {
      huga = millis() - hoge;
    }
    hoge = millis();
    Serial.print(huga);
    Serial.print("\tpush\t");
  }

  if (digitalRead(SW_Btn) == LOW) {
    while (digitalRead(SW_Btn) == LOW) {
      if ((millis() - hoge) >= PUSH_Limit) {
        huga = millis() - hoge;
        hoge = millis();
        Serial.print(huga);
        Serial.print("\t");
      }
    }
    
    huga = millis() - hoge;
    hoge = millis();
    Serial.println(huga);
  }
}
