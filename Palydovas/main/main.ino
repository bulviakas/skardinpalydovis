
#include <EduIntro.h>

DHT11 temp_dr_sens(D9);

int temperatura; // temperatura sveikais laipsniais
int dregme; // dregmes indeksas 

void setup() {
    Serial.begin(9600);
}

void loop() {
    temp_dr_sens.update();

    temperatura = temp_dr_sens.readCelsius();
    dregme = temp_dr_sens.readHumidity();

    Serial.print("\tTemperatura C: ");
    Serial.print(temperatura);
    Serial.print("\tDregme: ");
    Serial.print(dregme);

    delay(1000);
}