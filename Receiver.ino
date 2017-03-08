#include <IRremoteESP8266.h>

int RECV_PIN = 2; //an IR detector/demodulatord is connected to GPIO pin 2 (PIN 4)

IRrecv irrecv(RECV_PIN);

decode_results results;
const int led = LED_BUILTIN; //Usaremos el pin interno, que se encenderá cuando detectemos señal.

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
    digitalWrite(led, HIGH);
  }
  delay(100);
  digitalWrite(led, LOW);
}
