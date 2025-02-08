#include <Stepper.h>

// Define stepper parameters
const int stepsPerRevolution = 200; // Adjust as needed
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

// Movement control variables
int stepSize = 10; // Default manual step increment
int zeroPosition = 0;  // Reference zero position
int maxPosition = 1000;  // Maximum range position (default placeholder)
int currentPosition = 0;  // Tracks current stepper position
bool oscillate = false;   // Oscillation mode flag
bool stopMotion = false;  // Stop motion flag

void setup() {
  myStepper.setSpeed(20); // Set motor speed
  Serial.begin(9600);
  Serial.println("Stepper Control Ready.");
  Serial.println("Commands:");
  Serial.println("'+' : Move forward");
  Serial.println("'-' : Move backward");
  Serial.println("'z' : Set zero position");
  Serial.println("'x' : Set max position");
  Serial.println("'o' : Start oscillation");
  Serial.println("'s' : Stop movement");
  Serial.println("'step [value]' : Change step increment size");
}

void loop() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    command.trim();

    if (command == "+") {
      myStepper.step(stepSize);
      currentPosition += stepSize;
      Serial.print("Moved forward. Current Position: ");
      Serial.println(currentPosition);
    } 
    else if (command == "-") {
      myStepper.step(-stepSize);
      currentPosition -= stepSize;
      Serial.print("Moved backward. Current Position: ");
      Serial.println(currentPosition);
    } 
    else if (command == "z") {
      zeroPosition = currentPosition;
      Serial.println("Zero position set.");
    } 
    else if (command == "x") {
      maxPosition = currentPosition;
      Serial.print("Max position set at: ");
      Serial.println(maxPosition);
    } 
    else if (command == "o") {
      if (zeroPosition == maxPosition) {
        Serial.println("Error: Zero and max positions are the same! Set max using 'x'.");
      } else {
        oscillate = true;
        Serial.println("Starting oscillation...");
      }
    } 
    else if (command == "s") {
      oscillate = false;
      stopMotion = true;
      Serial.println("Stopping motion.");
    } 
    else if (command.startsWith("step ")) {
      stepSize = command.substring(5).toInt();
      Serial.print("Step size set to: ");
      Serial.println(stepSize);
    }
  }

  // Handle oscillation
  if (oscillate && !stopMotion) {
    Serial.println("Moving to max position...");
    myStepper.step(maxPosition - currentPosition);
    currentPosition = maxPosition;
    delay(500);
    
    Serial.println("Returning to zero...");
    myStepper.step(zeroPosition - currentPosition);
    currentPosition = zeroPosition;
    delay(500);
  }
}
