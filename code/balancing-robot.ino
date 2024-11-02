// Basic demo for accelerometer readings from Adafruit MPU6050

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

#define INA D0
#define INB D1

Adafruit_MPU6050 mpu;

bool front;
bool back;


void setup() {
  // put your setup code here, to run once:
  mpu.begin();
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  Serial.begin(115200);

  pinMode(INA, OUTPUT);
  pinMode(INB, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  
  
  if(a.acceleration.x > 4.0){
    digitalWrite(INB, LOW);
    digitalWrite(INA, LOW);
  }
  else if(a.acceleration.x > 1.5){
    front= 1;
    back= 0;
    digitalWrite(INA, LOW);
    digitalWrite(INB, HIGH);
    
  }
  else if(a.acceleration.x < -4.0){
    digitalWrite(INB, LOW);
    digitalWrite(INA, LOW);
  }
  else if(a.acceleration.x < -1.5){
    back= 1;
    front= 0;
    digitalWrite(INB, LOW);
    digitalWrite(INA, HIGH);
    

  }else if(a.acceleration.x < 0.3 || a.acceleration.x > -0.3){
    digitalWrite(INB, LOW);
    digitalWrite(INA, LOW);
  }
  delay(5);
  
}
