#define POT_PIN A0
#define LED_COUNT 3

// If you want to add more leds just change the value of constant LED_COUNT and add the corresponding port in the leds' array below
int leds[LED_COUNT] = {5, 6, 7};
int potReadMap = 0;
int potRead = 0;
int value = 0;

void setup() {
  Serial.begin(9600);
  pinMode(POT_PIN, INPUT);
  for (int i = 0; i < LED_COUNT; i++){
      pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  value = readConvertPot();
  for (int i = 0; i < LED_COUNT; i++){
    digitalWrite(leds[i], bitRead(potReadMap, i));
  }
}

int readConvertPot(){
  potRead = analogRead(POT_PIN);
  potReadMap = map(potRead, 0, 1023, 0, (int) pow(2, LED_COUNT)-1);
  return potReadMap;
}
