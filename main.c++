/*
  This code is developed by Bruno Santos (https://github.com/brunosantosss) for the project Pulseira de Acessibilidade para Deficientes visuais.

  v1.0.0
  
  06/01/2024
*/

#include <Ultrasonic.h>

// Defines 
#define SENSOR1_TRIGGER_PIN         2  
#define SENSOR1_ECHO_PIN            3 
#define SENSOR2_TRIGGER_PIN         13
#define SENSOR2_ECHO_PIN            12

#define VIBRATOR1_PIN               6
#define VIBRATOR2_PIN               7

#define BUZZER_PIN                  8

// Vibrator Frequencies
#define CRITICAL_VIBRATION            250
#define DANGER_VIBRATION              190
#define WARNING_VIBRATION             120
#define MINOR_VIBRATION               80
#define NO_VIBRATION                  0

Ultrasonic sensor_1(SENSOR1_TRIGGER_PIN, SENSOR1_ECHO_PIN);
Ultrasonic sensor_2(SENSOR2_TRIGGER_PIN, SENSOR2_ECHO_PIN); 

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(VIBRATOR1_PIN, OUTPUT);
  pinMode(VIBRATOR2_PIN, OUTPUT);

  Serial.begin(9600); 
}

void loop() {
  delay(50);

  unsigned int distance_sensor1 = sensor_1.read(CM);
  unsigned int distance_sensor2 = sensor_2.read(CM);

  Serial.print("distance_sensor1 : ");
  Serial.print(distance_sensor1);
  Serial.println(" cm");
  
  Serial.print("distance_sensor2 : ");
  Serial.print(distance_sensor2);
  Serial.println(" cm");

  if(distance_sensor1 > 0 && distance_sensor1 <= 5) {
      digitalWrite(BUZZER_PIN, HIGH);
      analogWrite(VIBRATOR1_PIN, CRITICAL_VIBRATION);
      delay(100);
      digitalWrite(BUZZER_PIN, LOW);
      analogWrite(VIBRATOR1_PIN, NO_VIBRATION);
  }
  else if (distance_sensor1 > 5 && distance_sensor1 <= 10) { 
      digitalWrite(BUZZER_PIN, HIGH);
      analogWrite(VIBRATOR1_PIN, DANGER_VIBRATION);
      delay(200);
      digitalWrite(BUZZER_PIN, LOW);
      analogWrite(VIBRATOR1_PIN, NO_VIBRATION);
  } 
  else if (distance_sensor1 > 10 && distance_sensor1 <= 15) { 
      digitalWrite(BUZZER_PIN, HIGH);
      analogWrite(VIBRATOR1_PIN, WARNING_VIBRATION);
      delay(300);
      digitalWrite(BUZZER_PIN, LOW);
      analogWrite(VIBRATOR1_PIN, NO_VIBRATION);
  } 
  else if (distance_sensor1 > 15 && distance_sensor1 <= 20) {
      digitalWrite(BUZZER_PIN, HIGH);
      analogWrite(VIBRATOR1_PIN, MINOR_VIBRATION);
      delay(400);
      digitalWrite(BUZZER_PIN, LOW);
      analogWrite(VIBRATOR1_PIN, NO_VIBRATION);
  }
  else if (distance_sensor1 > 20) {
      digitalWrite(BUZZER_PIN, LOW);
      analogWrite(VIBRATOR1_PIN, NO_VIBRATION);
  }

  if(distance_sensor2 > 0 && distance_sensor2 <= 5) {
      digitalWrite(BUZZER_PIN, HIGH);
      analogWrite(VIBRATOR2_PIN, CRITICAL_VIBRATION);
      delay(100);
      digitalWrite(BUZZER_PIN, LOW);
      analogWrite(VIBRATOR2_PIN, NO_VIBRATION);
  }
  else if (distance_sensor2 > 5 && distance_sensor2 <= 10) { 
      digitalWrite(BUZZER_PIN, HIGH);
      analogWrite(VIBRATOR2_PIN, DANGER_VIBRATION);
      delay(200);
      digitalWrite(BUZZER_PIN, LOW);
      analogWrite(VIBRATOR2_PIN, NO_VIBRATION);
  } 
  else if (distance_sensor2 > 10 && distance_sensor2 <= 15) { 
      digitalWrite(BUZZER_PIN, HIGH);
      analogWrite(VIBRATOR2_PIN, WARNING_VIBRATION);
      delay(300);
      digitalWrite(BUZZER_PIN, LOW);
      analogWrite(VIBRATOR2_PIN, NO_VIBRATION);
  } 
  else if (distance_sensor2 > 15 && distance_sensor2 <= 20) {
      digitalWrite(BUZZER_PIN, HIGH);
      analogWrite(VIBRATOR2_PIN, MINOR_VIBRATION);
      delay(400);
      digitalWrite(BUZZER_PIN, LOW);
      analogWrite(VIBRATOR2_PIN, NO_VIBRATION);
  }
  else if (distance_sensor2 > 20) {
      digitalWrite(BUZZER_PIN, LOW);
      analogWrite(VIBRATOR2_PIN, NO_VIBRATION);
  }
}
