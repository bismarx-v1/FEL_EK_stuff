/*********
  EKP-CV03a
  ESP32, BLE
  Vyhledava BLE zarizeni v okoli a ukazuje jejich MAC adresu
  zdroj: https://github.com/nkolban/esp32-snippets/blob/master/cpp_utils/tests/BLE%20Tests/SampleScan.cpp
*********/
#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>

int scanTime = 30; //v sekundach
BLEScan* pBLEScan;

class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks {
    void onResult(BLEAdvertisedDevice advertisedDevice) {
      Serial.printf("Zarizeni: %s \n", advertisedDevice.toString().c_str());
    }
};

void setup() {
  Serial.begin(115200);
  Serial.println("Skenuji BLE zarizeni...");

  BLEDevice::init("");
  pBLEScan = BLEDevice::getScan(); //vytvor novy sken
  pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
  pBLEScan->setActiveScan(true); 
  pBLEScan->setInterval(100);
  pBLEScan->setWindow(99);  // max rovno setInterval hodnote
}

void loop() {
  BLEScanResults foundDevices = pBLEScan->start(scanTime, false);
  Serial.print("Nalezena zarizeni: ");
  Serial.println(foundDevices.getCount());
  Serial.println("Sken hotov!");
  pBLEScan->clearResults();   // delete results fromBLEScan buffer to release memory
  delay(2000);
}
