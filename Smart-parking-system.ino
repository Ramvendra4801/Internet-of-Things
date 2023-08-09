//Smart Parking System
#include <Servo.h>
Servo gate;//Gate open or close using Servo motor

int slot1 = 3;//Digital pin 3

int slot2 = 4;//Digital pin 4

int gateSensor = 5;//IR sensor digital pin 5

int slot1_l = 10;

int slot2_l = 11;

int gate_grn = 12;

int gate_red = 13;



void setup(){

  gate.attach(7); 

  pinMode(slot1,INPUT);//slot1 pin set as input to arduino

  pinMode(slot2,INPUT);//slot2 pin set as input to arduino

  pinMode(gateSensor,INPUT);//gate IR sensor set as input to arduino

  pinMode(slot1_l,OUTPUT);

  pinMode(slot2_l,OUTPUT);

  pinMode(gate_grn,OUTPUT);

  pinMode(gate_red,OUTPUT);

  Serial.begin(9600);

}



void loop(){

  if( !(digitalRead(gateSensor)) && digitalRead(slot1) && digitalRead(slot2)){

    Serial.println("Available: Slot1, Slot2");// Available Slot1 and Slot2

    digitalWrite(slot1_l,HIGH);

    digitalWrite(slot2_l,HIGH);

    delay(1000);

    digitalWrite(gate_grn,HIGH);

    gate.write(100); 

  }

  if( !(digitalRead(gateSensor)) && !(digitalRead(slot1)) && digitalRead(slot2)) {

    Serial.println("Available: Slot2");//Available Slot2

    digitalWrite(slot1_l,LOW);

    digitalWrite(slot2_l,HIGH);

    delay(1000);

    digitalWrite(gate_grn,HIGH);

    gate.write(100);

  }

      

  if( !(digitalRead(gateSensor)) && digitalRead(slot1) && !(digitalRead(slot2))){

    Serial.println("Available: Slot1");//Available Slot1

    digitalWrite(slot1_l,HIGH);

    digitalWrite(slot2_l,LOW);

    delay(1000);

    digitalWrite(gate_grn,HIGH);

    gate.write(75); 

    delay(100);

  }

      

  if( !(digitalRead(gateSensor)) && !(digitalRead(slot1)) && !(digitalRead(slot2))){

    Serial.println("No Parking (FULL)");//Slot Full

    digitalWrite(slot1_l,LOW);

    digitalWrite(slot2_l,LOW);

    delay(1000);

    digitalWrite(gate_red,HIGH);

    delay(100);

    digitalWrite(gate_red,LOW);

    delay(100);

    digitalWrite(gate_red,HIGH);

    delay(100);

    digitalWrite(gate_red,LOW);  

  }            

  if( digitalRead(gateSensor)){

    Serial.println("Parking Available");//Available

    gate.write(5);

    digitalWrite(slot1_l,LOW);

    digitalWrite(slot2_l,LOW);

    digitalWrite(gate_red,LOW);

    digitalWrite(gate_grn,HIGH);

    delay(100);

    digitalWrite(gate_grn,LOW);

    delay(100);
  }
}