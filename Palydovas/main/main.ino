
#include <EduIntro.h>
#include <Adafruit_BMP085.h>
#include <TinyGPSPlus.h>
#include <SoftwareSerial.h> 

static const uint32_t GPSBaud = 4800;

DHT11 temp_dr_sens(D8);
Adafruit_BMP085 bmp;
TinyGPSPlus gps;
SoftwareSerial ss(A2, A3);


int temperatura; // temperatura sveikais laipsniais
int dregme; // dregmes indeksas 
int slegis;



void setup() {
    Serial.begin(115200);
    ss.begin(GPSBaud);

    if (!bmp.begin()) { 
	   Serial.println ( "Sensor BMP180 not found, check the connections!" ); 
	 }

   Serial.println(F("Sats HDOP  Latitude   Longitude   Fix  Date       Time     Date Alt    Course Speed Card  Distance Course Card  Chars Sentences Checksum"));
  Serial.println(F("           (deg)      (deg)       Age                      Age  (m)    --- from GPS ----  ---- to London  ----  RX    RX        Fail"));
  Serial.println(F("----------------------------------------------------------------------------------------------------------------------------------------"));

}

void loop() {   

    temp_dr_sens.update();

    temperatura = temp_dr_sens.readCelsius();
    dregme = temp_dr_sens.readHumidity();
    slegis = bmp.readPressure();

    Serial.print("Temperatura C: ");
    Serial.println(temperatura);
    Serial.print("Dregme: ");
    Serial.println(dregme);
    Serial.print("Slegis Pa: ");
    Serial.println(slegis);

    delay(1000);
}