#define ANA A0
#define DIGI D5
#define POMPOUT D6


double analogValue = 0.0;
int digitalValue = 0;
double analogVolts = 0.0;
unsigned long timeHolder = 0;


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

    // Activate the pump
    digitalWrite(POMPOUT, true);

    // Print the latest readings to the serial console
    Serial.print("Analog raw: ");
    Serial.println(analogValue);
    Serial.print("Digital raw: ");
    Serial.println(digitalValue);
    Serial.println(" ");
    delay(1000);
}
