const int lm35Pin = A0; // LM35 analog pin
const int ledPin = 13;  // Onboard LED pin
float temperature;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Read temperature from LM35 sensor
  int sensorValue = analogRead(lm35Pin);
  temperature = (sensorValue * 500.0) / 1023; // Convert analog reading to Celsius

  // Determine the LED state based on temperature
  if (temperature < 30.0) {
    digitalWrite(ledPin, HIGH); // Turn on the LED
    delay(250); // Wait for 250 milliseconds
    digitalWrite(ledPin, LOW); // Turn off the LED
    delay(250); // Wait for another 250 milliseconds
  } else {
    digitalWrite(ledPin, HIGH); // Turn on the LED
    delay(500); // Wait for 500 milliseconds
    digitalWrite(ledPin, LOW); // Turn off the LED
    delay(500); // Wait for another 500 milliseconds
  }

  // Print temperature to the serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
}
