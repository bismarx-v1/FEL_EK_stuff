
/*
Voltage divider values calculated and measured. 
Calculated values are estimated using a voltage divider formula with two resistors, calculated for U2. 
Table 1. shows the connected values of resistors. Table 2 shows the estimated and measured values of U2. 

(table 2.)
Value of resistors in Ohms
1. R1=1k,   R2=1k
2. R1=10k,  R2=10k
3. R1=1k,   R2=10k
4. R1=10k,  R2=1k


(table 1.)
Value of voltage in Volts
1. U2(cal) = 1.65,      U2(mes) = 1.63
2. U2(cal) = 1.65,      U2(mes) = 1.64
3. U2(cal) = 3,         U2(mes) = 3.11
4. U2(cal) = 0.3,       U2(mes) = 0.26
*/

// Voltage divider, ukol 1-2
/*#
include <Arduino.h>
#define ADC_pin 35 // - ADC1 - Vstupní pin AD převodníku
int data = 0;
void setup() {
pinMode(ADC_pin, INPUT); // Nastavení pinu ADC1 - vstup
Serial.begin(9600); // Nastavení přenosové rychlosti sériové linky
}
// Nekonečná smyčka
void loop() {
delay(100); // Zpoždění 100 ms - měření cca 10x vteřinu
data = analogRead(ADC_pin); //
Serial.print("ADC: ");
Serial.print(data,DEC);
Serial.print("(Dec) - ");
Serial.print(data,BIN);
Serial.print("(BIN) - ");
Serial.printf("U2 = %1.2f V",(3.3/4096)*data);
//Serial.printf("U2 = %1.2f V",((3.3/4096)*data)+0.13); // Korekce
Serial.println(); }
*/



//LED Array, ukol 3

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#define ADC_pin 35 // - ADC1 - Vstupní pin AD převodníku
#define NEOPIN 33 // - NeoPixel data pin - DI
#define NUMPIXELS 24 // - Počet LED diod v kruhu
int data = 0;
Adafruit_NeoPixel pixels(NUMPIXELS, NEOPIN, NEO_GRB);
void setup() {
pinMode(ADC_pin, INPUT); // Nastavení pinu ADC1 – vstup
Serial.begin(9600); // Nastavení přenosové rychlosti sériové linky
pinMode(NEOPIN, OUTPUT); // Nastavení pinu - výstup
pixels.begin(); // Inicializace NeoPixelu
}
// Nekonečná smyčka
void loop() {
delay(100); // Zpoždění 100 ms - měření cca 10x vteřinu
data = analogRead(ADC_pin); //
Serial.print("ADC: ");
Serial.print(data,DEC);
Serial.print("(Dec) - ");
Serial.print(data,BIN);
Serial.print("(BIN) - ");
Serial.printf("U2 = %1.2f V",(3.3/4096)*data);
//Serial.printf("U2 = %1.2f V",((3.3/4096)*data)+0.13); // Korekce
Serial.println();
pixels.clear(); // Smazání – vypnutí NeoPixel
for(int i=0; i<NUMPIXELS; i++){ // nastavení barvy LED dle změřené hodnoty napětí
if (i <= data/170){
if (i<=8) pixels.setPixelColor(i, pixels.Color(0,0,64));
if (i>8 && i<=16) pixels.setPixelColor(i, pixels.Color(0,64,0));
if (i>16) pixels.setPixelColor(i, pixels.Color(64,0,0));
}
}
pixels.show();
}


/*

(table 2.)
Value of resistors in Ohms
1. 0 Deg
2. 45 Deg
3. 90 Deg
4. 180 Deg 


(table 1.)
Value of voltage in Volts
1. U2(cal) = 1.65,      U2(mes) = 1.63
2. U2(cal) = 1.65,      U2(mes) = 1.64
3. U2(cal) = 3,         U2(mes) = 3.11
4. U2(cal) = 0.3,       U2(mes) = 0.26
*/



/*
//ADC to DAC, ukol 4
#include <Arduino.h>
#define ADC_pin 35 // - ADC1 - Vstupní pin AD převodníku
#define DAC_pin 25 // - DAC0 - Výstupní pin DA převodníku
int data = 0;
int dac_value = 127; // Hodnota-kód na výstupu DA převodníku
void setup() {
pinMode(ADC_pin, INPUT); // Nastavení pinu ADC1 – vstup
pinMode(DAC_pin, OUTPUT); // Nastavení pinu DAC0 – výstup
Serial.begin(9600); // Nastavení přenosové rychlosti sériové linky
}
// Nekonečná smyčka
void loop() {
delay(100); // Zpoždění 100 ms - měření cca 10x vteřinu
dacWrite(DAC_pin,dac_value);
data = analogRead(ADC_pin); //
Serial.print("ADC: ");
Serial.print(data,DEC);
Serial.print("(Dec) - ");
Serial.print(data,BIN);
Serial.print("(BIN) - ");
Serial.printf("U2 = %1.2f V",(3.3/4096)*data);
Serial.printf(" ___ DAC_value = %d, -> U_DAC = %1.2f V",dac_value,(3.3/256)*dac_value);
Serial.println();
}
*/