#include <Arduino.h>

// 1. Sensör Pinleri
const int trigPin1 = 2;
const int echoPin1 = 3;

// 2. Sensör Pinleri
const int trigPin2 = 4;
const int echoPin2 = 5;

// 3. Sensör Pinleri
const int trigPin3 = 6;
const int echoPin3 = 7;

// 4. Sensör Pinleri
const int trigPin4 = 8;
const int echoPin4 = 9;

void setup() {
  Serial.begin(9600);
  
  // Tüm Trig pinleri ÇIKIŞ, Echo pinleri GİRİŞ olarak ayarlanıyor
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);
}

// Mesafe ölçüm işlemini yapan özel fonksiyonumuz
int mesafeOlc(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // 35000 mikrosaniye zaman aşımı sınırı
  long sure = pulseIn(echoPin, HIGH, 35000); 

  if (sure == 0) {
    return -1; // Yankı alınamazsa kodun anlamsız bir sayı yerine -1 döndürmesini sağlıyoruz
  } else {
    return sure * 0.0343 / 2; // Mesafeyi cm cinsinden hesaplayıp döndürüyoruz
  }
}

void loop() {
  // Sensörlerden verileri okuyup değişkenlere kaydediyoruz
  int mesafe1 = mesafeOlc(trigPin1, echoPin1);
  delay(50);

  int mesafe2 = mesafeOlc(trigPin2, echoPin2);
  delay(50);

  int mesafe3 = mesafeOlc(trigPin3, echoPin3);
  delay(50);

  int mesafe4 = mesafeOlc(trigPin4, echoPin4);
  delay(50);

  // --- Ekrana Yazdırma Bölümü ---
  
  Serial.print("1. Sensor: ");
  if (mesafe1 == -1) { Serial.println("Menzil disi"); } 
  else { Serial.print(mesafe1); Serial.println(" cm"); }

  Serial.print("2. Sensor: ");
  if (mesafe2 == -1) { Serial.println("Menzil disi"); } 
  else { Serial.print(mesafe2); Serial.println(" cm"); }

  Serial.print("3. Sensor: ");
  if (mesafe3 == -1) { Serial.println("Menzil disi"); } 
  else { Serial.print(mesafe3); Serial.println(" cm"); }

  Serial.print("4. Sensor: ");
  if (mesafe4 == -1) { Serial.println("Menzil disi"); } 
  else { Serial.print(mesafe4); Serial.println(" cm"); }

  // Okumaların birbirine karışmaması için araya bir çizgi çekiyoruz
  Serial.println("-------------------------");
  
  delay(100); // Tüm ölçümler bittikten sonra yarım saniye bekliyoruz
}