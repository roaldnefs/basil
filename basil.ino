#define ANA A0
#define DIGI D5
#define POMPOUT D6

// Hold the threshold for when the watering pump need to be
// activated (digital value)
#define THRESHOLD 0

// Holds the digital and analog reading from the moisture sensor
double analogValue = 0.0;
int digitalValue = 0;


void setup() {
    // Setup the analog and digital input pins
    pinMode(ANA, INPUT);
    pinMode(DIGI, INPUT);
    pinMode(POMPOUT, OUTPUT);

    // Setup serial connection
    Serial.begin(115200);
    Serial.println("Serial setup");
}


void loop() {
    // Read the pin values
    analogValue = analogRead(ANA);
    digitalValue = digitalRead(DIGI);

    // Activate the pump if the digital sensor value received from
    // the moisture sensore falls below the threshold
    if (digitalValue > THRESHOLD) {
      // Activate the pump
      digitalWrite(POMPOUT, true);
    } else {
      // Deactivate the pump
      digitalWrite(POMPOUT, false);
    }

    // Print the latest readings to the serial console
    Serial.print("Analog raw: ");
    Serial.println(analogValue);
    Serial.print("Digital raw: ");
    Serial.println(digitalValue);
    Serial.println(" ");

    delay(1000);
}
