/*********
  EKP-CV02a
  ESP32 + interni LED@GPIO2
  Lokalni web server na ESP32 (AP mode)
  zdroj: https://lastminuteengineers.com/creating-esp32-web-server-arduino-ide/
*********/

#include <WiFi.h>      // API pro obsluhu bezdrátového síťového stacku
#include <WebServer.h> // Třída pro instanciaci synchronního HTTP serveru

/* Definice identifikačních údajů pro vlastní bezdrátovou síť (WPA2-PSK) */
const char* ssid = "ESP32";  // ZMENTE NAZEV SITE WIFI !!!
const char* password = "12345678";  // HESLO MIN. 8 ZNAKU

/* Statická konfigurace síťové vrstvy (IPv4) pro režim SoftAP */
IPAddress local_ip(192, 168, 1, 1);     // IP adresa samotného ESP32 v roli brány
IPAddress gateway(192, 168, 1, 1);      // Výchozí brána (v AP režimu odpovídá IP zařízení)
IPAddress subnet(255, 255, 255, 0);     // Maska podsítě (/24)

// Vytvoření instance webového serveru naslouchajícího na portu 80 (TCP)
WebServer server(80);

uint8_t LEDpin = 2; // Hardwarové mapování: interní modrá LED na modulu ESP32
bool LEDstatus = LOW; // Proměnná typu boolean pro udržování aktuálního logického stavu pinu

void setup() {
  // Inicializace sériové linky pro ladicí výpisy (baudrate 115200 bps)
  Serial.begin(115200);
  
  // Nastavení směru vybraného GPIO pinu na výstup (Push-Pull)
  pinMode(LEDpin, OUTPUT);

  // Inicializace Wi-Fi modulu do režimu Access Point
  WiFi.softAP(ssid, password);
  // Aplikování vlastního adresního plánu, jinak by ESP32 použilo výchozí DHCP pool (typicky 192.168.4.1)
  WiFi.softAPConfig(local_ip, gateway, subnet);
  
  // Krátká blokující pauza pro stabilizaci síťového rozhraní
  delay(100);

  // Routování (endpointy): Přiřazení callback funkcí pro konkrétní URI a HTTP metody (zde výchozí GET)
  server.on("/", handle_OnConnect);          // Obsluha rootu webu
  server.on("/led1on", handle_led1on);       // Obsluha požadavku pro logickou jedničku
  server.on("/led1off", handle_led1off);     // Obsluha požadavku pro logickou nulu
  server.onNotFound(handle_NotFound);        // Fallback pro neexistující cesty (HTTP 404)

  // Spuštění naslouchání na otevřeném socketu
  server.begin();
  Serial.println("HTTP server spusten");
}

void loop() {
  // Metoda handleClient() obsluhuje frontu příchozích TCP spojení.
  // Protože jde o synchronní server, musí být volána periodicky v neblokující smyčce.
  server.handleClient();
  
  // Fyzický zápis logické úrovně na pin podle hodnoty stavové proměnné
  if (LEDstatus)
  {
    digitalWrite(LEDpin, HIGH);
  }
  else
  {
    digitalWrite(LEDpin, LOW);
  }
}

// Callback spuštěný při načtení základní URL ("/")
void handle_OnConnect() {
  LEDstatus = LOW; // Výchozí reset stavu při novém připojení klienta
  Serial.println("LED Status: VYPNUTO");
  // Odeslání HTTP hlavičky s kódem 200 OK a vygenerovaného HTML payloadu
  server.send(200, "text/html", SendHTML(false));
}

// Callback spuštěný při požadavku na zapnutí LED
void handle_led1on() {
  LEDstatus = HIGH; // Změna stavu ovlivní chování v další iteraci funkce loop()
  Serial.println("LED Status: ZAPNUTO");
  server.send(200, "text/html", SendHTML(true));
}

// Callback spuštěný při požadavku na vypnutí LED
void handle_led1off() {
  LEDstatus = LOW;
  Serial.println("LED Status: VYPNUTO");
  server.send(200, "text/html", SendHTML(false));
}

// Handler pro zpracování neplatných HTTP požadavků
void handle_NotFound() {
  server.send(404, "text/plain", "Nenalezeno");
}

// Funkce konstruující strukturu HTML dokumentu. 
// Využívá dynamickou alokaci objektu String (pro rozsáhlejší projekty je efektivnější ukládat statické HTML do paměti PROGMEM nebo SPIFFS).
String SendHTML(uint8_t ledstat) {
  String ptr = "<!DOCTYPE html> <html>\n";
  // Viewport meta tag pro responsivní chování na mobilních platformách
  ptr += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr += "<title>LED Control</title>\n";
  
  // Vložení kaskádových stylů (CSS) pro definici vizuální prezentace DOM elementů
  ptr += "<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr += "body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  // Stylování pseudo-tlačítek (hypertextových odkazů formátovaných jako bloky)
  ptr += ".button {display: block;width: 80px;background-color: #3498db;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
  ptr += ".button-on {background-color: #3498db;}\n";
  ptr += ".button-on:active {background-color: #2980b9;}\n"; // Vizuální odezva na click event
  ptr += ".button-off {background-color: #34495e;}\n";
  ptr += ".button-off:active {background-color: #2c3e50;}\n";
  ptr += "p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
  ptr += "</style>\n";
  ptr += "</head>\n";
  
  ptr += "<body>\n";
  ptr += "<h1>ESP32 Web Server</h1>\n";
  ptr += "<h3>Připojeno v režimu Access Point(AP)</h3>\n";

  // Podmíněné větvení pro injektáž odpovídajícího ovládacího prvku na základě stavové proměnné
  if (ledstat)
  {
    // Pokud je LED zapnutá, renderujeme odkaz směrující na endpoint /led1off
    ptr += "<p>Stav LED: ZAPNUTO</p><a class=\"button button-off\" href=\"/led1off\">OFF</a>\n";
  }
  else
  {
    // Pokud je LED vypnutá, renderujeme odkaz směrující na endpoint /led1on
    ptr += "<p>Stav LED: VYPNUTO</p><a class=\"button button-on\" href=\"/led1on\">ON</a>\n";
  }

  ptr += "</body>\n";
  ptr += "</html>\n";
  return ptr; // Návrat alokovaného řetězce (objektu) pro odeslání klientovi
}