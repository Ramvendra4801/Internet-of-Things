//Health Monitoring System

#define USE_ARDUINO_INTERRUPTS true   
#include <PulseSensorPlayground.h>  

//  Variables
const int PulseWire = 0;       // PulseSensor "PURPLE WIRE" connected to ANALOG PIN 0
const int LED13 = 13;        
int Threshold = 550;           // Determine which Signal to "count as a beat" and which to ignore.
int val;
int tempPin= 1;                // Use the "Gettting Started Project" to fine-tune Threshold Value beyond default setting.
                               // Otherwise leave the default "550" value. 
                               
PulseSensorPlayground pulseSensor;  // Creates an instance of the PulseSensorPlayground object called "pulseSensor".

void setup() {   

  Serial.begin(9600);

  pulseSensor.analogInput(PulseWire);   
  pulseSensor.blinkOnPulse(LED13);     //Auto-magically blink Arduino's LED with heartbeat.
  pulseSensor.setThreshold(Threshold);   

  // Double-check the "pulseSensor" object was created and "begain" seeing a signal. 
   if (pulseSensor.begin()) {
    //Serial.println("We created a pulseSensor Object"); 
  }
}

void loop() {

 int myBPM = pulseSensor.getBeatsPerMinute();
 val = analogRead(tempPin);
float mv= (val/1024.0)*5000;
float cel= mv/10;


if (pulseSensor.sawStartOfBeat()) { // Constantly test to see if "a beat happened". 
 // If test is "true", print a message "a heartbeat happened".
// Serial.print("BPM: ");          // Print phrase "BPM: " 
 Serial.println(myBPM);  
//Serial.print("Temp: ");
Serial.print(cel);
Serial.println();// Print the value inside of myBPM. 
}
 delay(50);
}