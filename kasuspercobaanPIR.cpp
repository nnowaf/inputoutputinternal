// C++ code
// mode RISING = LOW to HIGH
// mode FALLING = HIGH to LOW
// mode CHANGE = HIGH to LOW or LOW to HIGH
/*
	Mohammad Nowaf
    6702202026
    Soal Kasus Percobaan PIR
*/
#include <LiquidCrystal.h>
LiquidCrystal lcd(9, 8, 5, 4, 3, 2);

unsigned long waktu = millis(); // waktu menggunalan millis
unsigned long waktuAkhir = 0; // waktu akhir

//variabel komponen
int ledMerah = 10;
int button = 7;
int buzzer = A0;
int sensor = 12;
int sensorState; //untuk status sensor | HIGH atua LOW

//variabel pembantu
bool validasi = false;
bool aktif = false;

int btnPress = 0; //untuk menghitung jumlah tekan button

void setup()
{
  //set pin, serial, dan lcd
  Serial.begin(9600); 
  lcd.begin(16, 2);
  pinMode(ledMerah, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(sensor, INPUT);
  
}

void loop()
{
  waktu; //waktu dalam millis() secara realtime
  sensorState = digitalRead(sensor); //membaca output sensor | HIGH atau LOW

  // jika button ditekan maka menambahkan variabel btnPress
  if (digitalRead(button) == LOW) { 
    ++btnPress;
    validasi = true;
    Serial.println(btnPress);
    delay(500);
  }
  
  if (sensorState == HIGH) { // sensor menyala
    aktif = true;
    waktuAkhir = millis();
    
    if (validasi == true && btnPress == 2) {  //bagian untuk menyalakan komponen. bagian kasus dua
      lcd.clear();
      //menyala
      analogWrite(buzzer, 255);
      lcd.setCursor(0, 0);
      lcd.print("Gerakan On");
      lcd.setCursor(0, 1);
      lcd.print("Tombol 2");
      Serial.print("2| SENSOR ACTIVE PADA DETIK : ");
      Serial.println(millis() / 1000);
      
      Serial.println(btnPress);
      validasi = false;
    } else if (validasi == true && btnPress == 3) {  //bagian untuk menyalakan komponen. bagian kasus tiga
      //menyala
      lcd.clear();  
      lcd.print("Gerakan On");
      lcd.setCursor(0, 1);
      lcd.print("Tombol 3");
      Serial.print("3| SENSOR ACTIVE PADA DETIK : ");
      Serial.println(millis() / 1000);
      
      for (int i = 0; i < 15; i++) {
        digitalWrite(ledMerah, HIGH);
        delay(250);
        digitalWrite(ledMerah, LOW);
        delay(250);
      }
      
      Serial.println(btnPress);
      validasi = false;
    } 
    
  } else if (aktif && (waktu - waktuAkhir) > 2000) { //jika sensor tidak menyala selama 2 detik
  	
    aktif = false;
    
    if (validasi == false && btnPress == 2) { //bagian untuk mematikan komponen. bagian kasus dua
      lcd.clear();
      //mati
      analogWrite(buzzer, 0);
      lcd.setCursor(0, 0);
      lcd.print("Gerakan Off");
      lcd.setCursor(0, 1);
      lcd.print("Tombol 2");
      Serial.print("2|SENSOR TIDAK ACTIVE PADA DETIK : ");
      Serial.println(millis() / 1000);
      
      Serial.println(btnPress);
      validasi = true;
    } else if (validasi == false && btnPress == 3) {  //bagian untuk mematikan komponen. bagian kasus tiga
      lcd.clear();
      //mati
      digitalWrite(ledMerah, LOW);
      lcd.print("Gerakan Off");
      lcd.setCursor(0, 1);
      lcd.print("Tombol 3");
      Serial.print("3| SENSOR TIDAK ACTIVE PADA DETIK : ");
      Serial.println(millis() / 1000);
      Serial.println(btnPress);
      validasi = true;
    } 
  }
  
  
  
  if (validasi == true && btnPress == 1) {  //bagian kasus satu
    kasusSatu();
    validasi = false;
  } else if (validasi == true && btnPress == 4) { //bagian kasus empat
    Serial.println(btnPress);
  	btnPress = 1;
  }
  
}

void kasusSatu() { //bagian kasus satu
  Serial.println("sensor configuration ");
  for (int i = 0; i < 20; i++) {
    Serial.print(".");
    delay(500);
  }
  lcd.setCursor(0, 0);
  lcd.print("Sensor Actived");
  Serial.println("\nSensor Actived");
}
