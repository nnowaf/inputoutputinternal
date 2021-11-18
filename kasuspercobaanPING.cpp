// C++ code
//
/*
 Mohammad Nowaf 
 6702202026
 Soal Kasus Percobaan PING
 320 cm /2 = 160cm
125 inc /2 = 62 in
*/
#include <LiquidCrystal.h>
#define RS 9
#define E 8
#define PING 12

LiquidCrystal lcd(RS, E, 5, 4, 3, 2); //lcd

//variabel untuk inchi dan centimeter
unsigned long inc = 0;
unsigned long cm = 0;

//variabel untuk komponen yang terhubung ke pin arduino
int ledMerah = 11;
int btn = 10;
int buzz = A0;

//variabel pembantu
int batasCm = 160;
int btnPress = 0;
bool validasi = false;
void setup()
{
  //sett pinMode, serial, dan lcd
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(ledMerah, OUTPUT);
  pinMode(buzz, OUTPUT);
  pinMode(btn, INPUT);
}

void loop()
{
  //jika button ditekan maka akan menambahkan variabel btnPress 
  if (digitalRead(btn) == LOW) {
  	++btnPress;
    validasi = true;
    Serial.println(btnPress);
    delay(250);
  } 
  
  if (validasi == true && btnPress == 1) { //jika button ditekan 1x
    lcd.clear(); 
    satu(); //memanggil fungsi
    Serial.println(btnPress); //menampilkan nilai tekan button di serial monitor
    validasi = false;
    
  } else if (validasi == true && btnPress == 2) { //jika button ditekan 2x
  	lcd.clear();
    dua(); //memanggil fungsi dua()
    Serial.println(btnPress);
    validasi = false;
  } else if (validasi == true && btnPress == 3) { //jika button ditekan 3x
    lcd.clear();
  	tiga(); //memanggil fungsi tiga()
    Serial.println(btnPress);
    validasi = false;
  } else if (validasi == true && btnPress == 4) { //jika button ditekan 4x, kembali ke ditekan 1x (mengulang)
    Serial.println(btnPress);
  	btnPress = 1;
  }
}

//fungsi untuk mengprint lcd dengan menggunakan parameter
void lcdPrint(String atas = " ", 
             String bawah = " ",
             long nilai = 0) {
  lcd.setCursor(0, 0);
  lcd.print(atas);
  lcd.setCursor(7, 0);
  lcd.print(nilai);
  lcd.setCursor(0, 1);
  lcd.print(bawah);
}

long mToIn(long t) { //fungi conver ke inc
  return t / 74 / 2;
}

long mToCm(long c) { //fungsi convert ke cm
  return c / 29 / 2;
}

long unsigned bacaSensor() { //fungsi membaca nilai sensor
    
  //membaca sensor PING
  pinMode(PING, OUTPUT); //set menjadi output agar memancarkan gelombang
  digitalWrite(PING, LOW); //menangkap gelombang selama 2 micro
  delayMicroseconds(2);
  digitalWrite(PING, HIGH); //memancarkan gelombang selama 5 micro
  delayMicroseconds(5);
  digitalWrite(PING, LOW); //set low. menangkap gelombang
  pinMode(PING, INPUT); //set menjadi input agar menerima gelombang
  
  return pulseIn(PING, HIGH); //nilai durasi diambil dari lamanya suara ke sensor
}



void satu() { //fungsi pada saat button ditekan 1x
  Serial.print("Loading ");
  for (int i = 0; i < 18; i++) {
    Serial.print("#");
    delay(150);
  }
  Serial.println("\nSENSOR TELAH AKTIF");
  lcdPrint("AKTIF");
}

void dua() { //fungsi pada saat button ditekan 2x
  String baca;
  bool aktif = true;
  while (aktif == true) {
    baca = Serial.readString(); //membaca nilai String di serial monitor
    cm = mToCm(bacaSensor()); //convert micro ke cm dari nilai PIR
    if (cm > batasCm) {
      analogWrite(buzz, 255);
      Serial.println("MELEBIHI BATAS");
      //memanggil fungsi lcdPrint untuk mengprint di lcd
      lcdPrint("NILAI", "BATAS 160 cm", cm); 
    } else {
      analogWrite(buzz, 0);
      Serial.println("TIDAK MELEBIHI BATAS");
      //memanggil fungsi lcdPrint untuk mengprint di lcd
      lcdPrint("NILAI", "BATAS 160 cm", cm);
    }

    //jika mengetik kata stop di serial monitor,
    //maka akan berhenti 
    if (baca == "stop") { 
      analogWrite(buzz, 0);
      Serial.println("STOP");
      aktif = false;
    }
  }
}

void tiga() { //fungsi pada saat button ditekan 3x
  String baca;
  bool aktif = true;
  while (aktif) {
  	baca = Serial.readString(); //membaca nilai String di serial monitor
    cm = mToCm(bacaSensor()); //convert micro ke cm dari nilai PIR
    
    analogWrite(ledMerah, cm); //fadding LED dari nilai sensor PIR
    lcdPrint("NILAI", "CM", cm); //memanggil fungsi lcdPrint untuk mengprint di lcd
    Serial.print("Nilai Sensor : ");
    Serial.print(cm);
    Serial.println(" cm");
    
    //jika mengetik kata stop di serial monitor,
    //maka akan berhenti 
    if (baca == "stop") {
      analogWrite(ledMerah, 0);
      Serial.println("STOP");
      aktif = false;
  	}
  }
}
