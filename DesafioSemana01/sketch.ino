#include <DHT.h>
#include <WiFi.h>
#include <HTTPClient.h>

//Portas de Entrada
#define ledAzul 21

#define DHTPIN 15
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

// =========================
// WIFI
// =========================

const char* ssid = "Wokwi-GUEST";
const char* password = "";

// Constantes do LDR do Wokwi
const float GAMMA = 0.7;    // “gamma” do LDR
const float RL10  = 50.0;   // resistência (kΩ) em 10 lux (RL10)

const int   LDR_PIN = 34;   // ADC do ESP32
const float R_SERIE = 10000; // 10k ohms (mesmo valor do exemplo Wokwi)

String firebaseUrl = "https://minhaestacaomet-a99ee-default-rtdb.firebaseio.com/";

void enviarFirebase(float temperature, float humidity, float luminosidade){
  if(WiFi.status() != WL_CONNECTED){
    Serial.println("Estamos offline, conecte a internet.");
    return;
  }

  HTTPClient http;

  String url = firebaseUrl + "/estacao1.json";

  http.begin(url);

  http.addHeader(
    "Content-Type","application/json"
  );

  String json = "{";
  json += "\"temperatura\":"+String(temperature, 1)+",";
  json += "\"umidade\":"+String(humidity, 1)+",";
  json += "\"luminosidade\":"+String(luminosidade, 1)+",";
  json += "\"uptime\":"+String(millis());
  json += "}"; 

  int httpCode = http.PUT(json);

  if(httpCode > 0){
    String response = http.getString();

    Serial.println("Resposta: ");
    Serial.println(response);
  }

  http.end();
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  pinMode(ledAzul, OUTPUT);

  dht.begin();
  WiFi.begin(ssid, password);

  Serial.print("Conectando");
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Conectado ao WIFI");
}

void loop() {
  //DHT 22 Data
  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();
  // Convert the analog value into lux value:
  int analogValue = analogRead(LDR_PIN);
  float voltage = analogValue / 4095.0 * 3.3;
  float resistance = R_SERIE * voltage / (3.3 - voltage);
  float luminosidadeLux = pow(RL10 * 1000.0 * pow(10, GAMMA) / resistance, 1.0 / GAMMA);
 
 
  Serial.println("Sensor DHT");
  Serial.print(temperatura);
  Serial.println("°c");

  Serial.print(umidade);
  Serial.println("%");

  Serial.println("luminosidade");
  Serial.print(luminosidadeLux);
  Serial.println("lux");


  enviarFirebase(temperatura, umidade, luminosidadeLux);

  // put your main code here, to run repeatedly:
  digitalWrite(ledAzul, HIGH);
  delay(1000); // this speeds up the simulation
  digitalWrite(ledAzul, HIGH);
  delay(1000); // this speeds up the simulation
}