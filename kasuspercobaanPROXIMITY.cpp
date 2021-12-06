/*
 * Mohammad Nowaf - 6702202026
 * Soal Kasus Percobaan Proximity
 */
#include <LiquidCrystal_SR_LCD3.h> //library untuk lcd dengan 3 pin
//pin pin lcd
#define PIN_LCD_STROBE 2
#define PIN_LCD_DATA 3
#define PIN_LCD_CLOCK 4

//pin untuk komponen
int ledTrig = 7;
int sensor = 9;
int pinButton = 6;
int buzzer = 5;

//variabel pembantu
int tekan = 0;
bool val = false;
LiquidCrystal_SR_LCD3 lcd(PIN_LCD_DATA, PIN_LCD_CLOCK, PIN_LCD_STROBE);
void setup() {
  // put your setup code here, to run once
  pinMode(buzzer, OUTPUT);
  pinMode(ledTrig, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(pinButton, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.home();
}

void loop() {
  // put your main code here, to run repeatedly
  if (digitalRead(pinButton) == LOW) {
    ++tekan;
    val = true;
    delay(250);
  }

  if (tekan == 1 && val == true) { //kasus 1
    lcd.clear();
    Serial.println("KASUS 1");
    kasusSatu();
    val = false;
  } else if (tekan == 2 && val == true) { //kasus 2
    lcd.clear();
    Serial.println("KASUS 2");
    kasusDua();
    val = false;
  } else if (tekan == 3 && val == true) { //kasus 3
    lcd.clear();
    Serial.println("KASUS 3"); 
    kasusTiga();
    val = false;
  } else if (tekan == 4 && val == true) { //kalo udah neken 4x, balik ke kasus awal (1)
    lcd.clear();
    tekan = 1;
  }
}

void kasusSatu() { //untuk kasus satu
  for (int i = 0; i < 20; i++) { 
    Serial.print("#");
    delay(300);
  }
  Serial.println();
  Serial.println("SENSOR TELAH AKTIF");
  lcd.setCursor(0, 0);
  lcd.print("SENSOR AKTIF");
}

void kasusDua() { //untuk kasus dua
  bool cek = false;

  while (cek == false) {
    if (digitalRead(sensor) == LOW) { // melewati batas
      Serial.println("KELUAR BATAS");
      lcd.setCursor(0, 0);
      lcd.print("KELUAR BATAS");
      digitalWrite(buzzer, LOW);
      delay(250);
      digitalWrite(buzzer, HIGH);
      delay(250);
    } else { //dalam batas
      Serial.println("DALAM BATAS");
      lcd.setCursor(0, 0);
      lcd.print("DALAM BATAS");
      digitalWrite(buzzer, HIGH);
    }

    if (digitalRead(pinButton) == LOW) { //untuk memberhentikan looping
      cek = true;
      delay(500);
    }
  }
}

void kasusTiga() { //kasus tiga
  bool cek = false;
  while (cek == false) { //looping led fading dengan nilainya dari sensor untuk kasus tiga
    analogWrite(ledTrig, sensor);
    lcd.setCursor(0, 0);
    lcd.print(sensor);
    Serial.println(sensor);
    
    if (digitalRead(pinButton) == LOW) { //untuk memberhentikan looping
      cek = true;
      delay(500);
    }
  }
}
