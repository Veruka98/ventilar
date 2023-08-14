#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <DHT.h>
#include <DHT_U.h>

#define ventilador1 9
#define ventilador2 10
#define ventilador3 11
#define HT1 5
#define HT2 6
#define HT3 7

#define DHTTYPE DHT11

int temp;

DHT dht1(HT1, DHTTYPE);
DHT dht2(HT2, DHTTYPE);
DHT dht3(HT3, DHTTYPE);

class Ventilar1 {
  private:
    byte pinVENT1;
    byte pinTEMP1;

    boolean ventState1 = LOW;
    boolean tempState1 = HIGH;


  public:
    Ventilar1(byte pinVENT1, byte pinTEMP1) {
      this->pinVENT1 = pinVENT1;
      this->pinTEMP1 = pinTEMP1;

      pinMode(pinVENT1, OUTPUT);
      pinMode(pinTEMP1, INPUT);
      Serial.begin(9600);
    }

  void Temperatura1(){
      Serial.print("Temperatura1: ");
      Serial.print(dht1.readTemperature());
      Serial.println(" ºC--dht1");
      Serial.println(" ");
      delay(100);
      Serial.println(" ");

      if(temp>=29.50) {
      
          analogWrite(ventilador1,255); //Encendemos el ventilador
        }
      else {
          analogWrite(ventilador1,0);
        }
        temp= dht1.readTemperature();
        
    }
};


class Ventilar2 {
  private:
    byte pinVENT2;
    byte pinTEMP2;

    boolean ventState2 = LOW;
    boolean tempState2 = HIGH;


  public:
    Ventilar2(byte pinVENT2, byte pinTEMP2) {
      this->pinVENT2 = pinVENT2;
      this->pinTEMP2 = pinTEMP2;

      pinMode(pinVENT2, OUTPUT);
      pinMode(pinTEMP2, INPUT);
      Serial.begin(9600);
    }

  void Temperatura2(){
      Serial.print("Temperatura2: ");
      Serial.print(dht2.readTemperature());
      Serial.println(" ºC--dht1");
      Serial.println(" ");
      delay(100);
      Serial.println(" ");

      if(temp>=29.50) {
      
          analogWrite(2,255); //Encendemos el ventilador
        }
      else {
          analogWrite(ventilador2,0);
        }
        temp= dht1.readTemperature();
        
    }
};

class Ventilar3 {
  private:
    byte pinVENT3;
    byte pinTEMP3;

    boolean ventState3 = LOW;
    boolean tempState3 = HIGH;


  public:
    Ventilar3(byte pinVENT2, byte pinTEMP2){
      this->pinVENT3 = pinVENT3;
      this->pinTEMP3 = pinTEMP3;

      pinMode(pinVENT3, OUTPUT);
      pinMode(pinTEMP3, INPUT);
      Serial.begin(9600);
    }

  void Temperatura3(){
      Serial.print("Temperatura3: ");
      Serial.print(dht3.readTemperature());
      Serial.println(" ºC--dht3");
      Serial.println(" ");
      delay(100);
      Serial.println(" ");

      if(temp>=29.50) {
      
          analogWrite(ventilador3,255); //Encendemos el ventilador
        }
      else {
          analogWrite(ventilador3,0);
        }
        temp= dht3.readTemperature();
        
    }
};


Ventilar1 vent1 = Ventilar1(ventilador1, HT1);
Ventilar2 vent2 = Ventilar2(ventilador2, HT2);
Ventilar3 vent3 = Ventilar3(ventilador3, HT3);

void setup() {
  dht1.begin();
  dht2.begin();
  dht3.begin();
}

void loop() {
  vent1.Temperatura1();
  vent2.Temperatura2();
  vent3.Temperatura3();
}