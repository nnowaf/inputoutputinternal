/*
 * Mohammad Nowaf
 * 6702202026
 * Kasus Percobaan Modul 6
*/
#include <LiquidCrystal.h>
#include <EEPROM.h>

LiquidCrystal lcd (9, 8, 5, 4, 3, 2);

//analog
float tempe = A0;
int LCDcontrast = 10;
int opto = A5;
int buzzer = 11;
int LEDred = 6;

//button
int button = 7;
int tekan = 0;

//variabel bantu
bool validasi = false;

//variabel untuk baca nilai sensor atau lainnya
int bacaTemp;
float nilaiTemp;
int bacaButton;
float bacaEprom;

void setup()
{
  //set pin pin menjadi input dan output
  pinMode(button, INPUT);
  pinMode(tempe, INPUT);
  pinMode(opto, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(LCDcontrast, OUTPUT);
  pinMode(LEDred, OUTPUT);
  
  analogWrite(LCDcontrast, 0);
  analogReference(INTERNAL);
  
  lcd.begin(16, 2);
  lcd.setCursor(1, 0);
  lcd.print("Mohammad Nowaf");
  delay(1000);
  lcd.clear();
  
  Serial.begin(9600);
}

void loop()
{
  bacaButton = digitalRead(button); //jika pushbutton ditekan maka akan menambahkan variabel tekan += 1
  if (bacaButton == LOW) {
    ++tekan;
    validasi = true;
    Serial.println(tekan);
    delay(150);
  }

  //if else untuk pengkondisian tiap tiap pushbutton jika ditekan keberapa kalinya
  if (tekan == 1 && validasi == true) {
    kasusSatu();
    validasi = false;
  } else if (tekan == 2 && validasi == true) {
    kasusDua();
    validasi = false;
  } else if (tekan == 3 && validasi == true) {
    kasusTiga();
    validasi = false;
  } else if (tekan == 4 && validasi == true) {
    kasusEmpat();
    validasi = false;
  } else if (tekan == 5 && validasi == true) { //jika pushbutotn ditekan ke 5xnya, maka akan balik ke nomer 1
    tekan = 1;
  }
}

void kasusSatu() { //untuk kondisi pertama
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("MEREKAM DATA");
  
  Serial.println("alamat\tnilai");
  for (int i = 0; i <= 512; i++){
    bacaTemp = analogRead(tempe);
    
    nilaiTemp = bacaTemp / 9.31; //convert nilai ke celcius
    EEPROM.write(i, nilaiTemp); //menulis data sensor yang sudah di convert ke EEPROM
    
    lcd.setCursor(0, 1);
    lcd.print(nilaiTemp);
    
    Serial.print(i);
    Serial.print("\t");
    Serial.println(nilaiTemp);
  } 
  lcd.clear();
}

void kasusDua() { //untuk kondisi kedua
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("MEMBACA DATA");
  
  Serial.println("alamat\tnilai");
  for (int i = 0; i <= 512; i++) {
    bacaEprom = EEPROM.read(i); //membaca data yang sudah diinputkan sebelumnya
    lcd.setCursor(0, 1);
    lcd.print(bacaEprom);
    
    Serial.print(i);
    Serial.print("\t");
    Serial.println(bacaEprom);
  }
  
  lcd.clear(); 
}

void kasusTiga(){ //untuk kondisi ketiga
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("DELETE DATA");
  
  Serial.println("alamat\tnilai");
  for (int i = 0; i <= 512; i++) {
    EEPROM.write(i, 0); //menghapus data dengan mengasih nilai 0 ditiap alamat EEPROM

    if (i == 512) {
      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);
    }
  }
  lcd.clear();
}

void kasusEmpat() { //untuk kondisi keempat
  //fadding gelap-terang 3x
  for (int x = 0; x < 3; x++) {
    for (int i = 0; i <= 255; i++) {
    analogWrite(LEDred, i);
    delay(5);
  }
    for (int i = 255; i >= 0; i--) {
    analogWrite(LEDred, i);
    delay(5);
    }
  }

  //kelap-kelip 10x
  for (int y = 1; y <= 10; y++) {
    digitalWrite(opto, HIGH);
  delay(500);
    digitalWrite(opto, LOW);
    delay(500);
  }
}
