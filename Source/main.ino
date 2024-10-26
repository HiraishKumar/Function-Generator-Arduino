const int outputPin1 = 15; // D15 for Square Wave
const int outputPin2 = 0;  // D0 for Square Wave
const int switchPin = 5;    // D5 for switch input
const int analogPin1 = A0;  // A0 for analog input
const int analogPin2 = A5;  // A1 for analog input

const float frequency = 60.0;    // Frequency in Hz
const float period = (1.0 / frequency) * 1000; // Period in milliseconds
const float halfPeriod = period / 2; // Half-period for square wave

bool useD0 = true; // Flag to toggle between D0 and D13

void setup() {
  pinMode(outputPin1, OUTPUT);
  pinMode(outputPin2, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP); // Set switch pin as input with pull-up resistor
  
  Serial.begin(9600); // Start serial communication
}

void loop() {
  // Read the switch state
  if (digitalRead(switchPin) == LOW) { // If switch is pressed
    useD0 = !useD0; // Toggle between D0 and D13
    delay(200); // Debounce delay to avoid multiple toggles
  }

  // Generate 60 Hz Square Wave on D0 or D13
  if (useD0) {
    digitalWrite(outputPin1, HIGH); // Use D0
    digitalWrite(outputPin2, LOW);   // D13 off
  } else {
    digitalWrite(outputPin1, LOW);   // D0 off
    digitalWrite(outputPin2, HIGH);   // Use D13
  }
  delay(halfPeriod);

  if (useD0) {
    digitalWrite(outputPin1, LOW);
    digitalWrite(outputPin2, LOW);
  } else {
    digitalWrite(outputPin1, LOW);
    digitalWrite(outputPin2, LOW);
  }
  delay(halfPeriod);

  // Read analog values from A0 and A5
  int analogValue1 = analogRead(analogPin1);
  int analogValue2 = analogRead(analogPin2);

  // Print the values to the Serial Monitor
  Serial.print("A0: ");
  Serial.print(analogValue1);
  Serial.print("   A5: ");
  Serial.println(analogValue2);
}
