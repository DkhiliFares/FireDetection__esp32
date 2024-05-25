#include <ESP8266WiFi.h>
#include <DHT.h>

// Définir les broches
#define DHTPIN 2  // Broche D4
#define MQ2AOUT A0
#define MQ2DOUT 5 // Broche D1 (GPIO5)
#define BUZZERPIN 4  // Broche D2

// Définir le type de capteur DHT
#define DHTTYPE DHT11

// Initialiser le capteur DHT
DHT dht(DHTPIN, DHTTYPE);

// Seuils d'alarme
const float TEMP_THRESHOLD = 30.0;  // Exemple: 30°C
const float HUM_THRESHOLD = 70.0;   // Exemple: 70%
const int MQ2_THRESHOLD = 300;      // Exemple: valeur analogique

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(BUZZERPIN, OUTPUT);
  pinMode(MQ2DOUT, INPUT);
  digitalWrite(BUZZERPIN, LOW);  // Éteindre le buzzer au démarrage
}

void loop() {
  // Lire les valeurs du capteur DHT11
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Lire la valeur analogique du capteur MQ2
  int mq2AValue = analogRead(MQ2AOUT);

  // Lire la valeur numérique du capteur MQ2
  int mq2DValue = digitalRead(MQ2DOUT);

  // Afficher les valeurs sur le port série
  Serial.print("Humidité: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Température: ");
  Serial.print(t);
  Serial.print(" *C\t");
  Serial.print("MQ2 Analogique: ");
  Serial.print(mq2AValue);
  Serial.print("\tMQ2 Numérique: ");
  Serial.println(mq2DValue);

  // Vérifier les seuils
  if (t > TEMP_THRESHOLD || h > HUM_THRESHOLD || mq2AValue > MQ2_THRESHOLD || mq2DValue == HIGH) {
    digitalWrite(BUZZERPIN, HIGH);  // Activer le buzzer
  } else {
    digitalWrite(BUZZERPIN, LOW);   // Désactiver le buzzer
  }

  delay(2000);  // Attendre 2 secondes avant la prochaine lecture
}
