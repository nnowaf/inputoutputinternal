/*
 * Mohammad Nowaf 6702202026
 * Soal Kasus Percobaan Gyroscope
 */

 //pemanggilan untuk library
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu; //membuat objek untuk mpu

//untuk pin komponen
int buzzer = 15; //D8
int button = 13; //D7
int led = 12; //D6

//variabel pembantu
int buttonTekan = 0;
bool val = false;

String bacaSerial; //variabel untuk membaca nilai string di Serial Menitor

void setup() {
  // put your setup code here, to run once:
  //set pin komponen sebagai output atau input
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(115200);

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G); //set sensor akselerasi range 8
  Serial.print("Accelerometer range set to: ");
  switch (mpu.getAccelerometerRange()) { //menampilkan hasil yng sudah di set akselerasinya ke serial monitor menggunakan pengkondisian
  case MPU6050_RANGE_2_G:
    Serial.println("+-2G");
    break;
  case MPU6050_RANGE_4_G:
    Serial.println("+-4G");
    break;
  case MPU6050_RANGE_8_G:
    Serial.println("+-8G");
    break;
  case MPU6050_RANGE_16_G:
    Serial.println("+-16G");
    break;
  }
  mpu.setGyroRange(MPU6050_RANGE_500_DEG); //set sensor gyro range 500 deg
  Serial.print("Gyro range set to: ");
  switch (mpu.getGyroRange()) { //menampilkan hasil yng sudah di set gyro ke serial monitor menggunakan pengkondisian
  case MPU6050_RANGE_250_DEG:
    Serial.println("+- 250 deg/s");
    break;
  case MPU6050_RANGE_500_DEG:
    Serial.println("+- 500 deg/s");
    break;
  case MPU6050_RANGE_1000_DEG:
    Serial.println("+- 1000 deg/s");
    break;
  case MPU6050_RANGE_2000_DEG:
    Serial.println("+- 2000 deg/s");
    break;
  }

  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ); //set sensor bandwith band 21 hz
  Serial.print("Filter bandwidth set to: ");
  switch (mpu.getFilterBandwidth()) { //menampilkan hasil yng sudah di set bandwith ke serial monitor menggunakan pengkondisian
  case MPU6050_BAND_260_HZ:
    Serial.println("260 Hz");
    break;
  case MPU6050_BAND_184_HZ:
    Serial.println("184 Hz");
    break;
  case MPU6050_BAND_94_HZ:
    Serial.println("94 Hz");
    break;
  case MPU6050_BAND_44_HZ:
    Serial.println("44 Hz");
    break;
  case MPU6050_BAND_21_HZ:
    Serial.println("21 Hz");
    break;
  case MPU6050_BAND_10_HZ:
    Serial.println("10 Hz");
    break;
  case MPU6050_BAND_5_HZ:
    Serial.println("5 Hz");
    break;
  }

  Serial.println("#################################################");
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(button) == LOW) { //untuk kondisi jika pushbutton ditekan
    ++buttonTekan;
    val = true;
    Serial.print("Pencet Tombol Ke : ");
    Serial.print(buttonTekan);
    Serial.println();
    delay(500);
  }

/*
 * pengkondisian untuk pushbutton.
 * jika pushbutton ditekan yang keberapa kalinya
 */
  if (buttonTekan == 1 && val == true) { //kasus 1
    Serial.println("kasus 1");
    kasusSatu();
    val = false;
  } else if (buttonTekan == 2 && val == true) { //kasus 2
    Serial.println("kasus 2");
    kasusDua();
    val = false;
  } else if (buttonTekan == 3 && val == true) { //kasus 3
    Serial.println("kasus 3");
    kasusTiga();
    val = false;
  } else if (buttonTekan == 4 && val == true) { //balik lagi ke kasus satu
    buttonTekan = 1;
  }
}

void kasusSatu() { 
  bool cek = false;
  while (cek == false) { //pengulanan untuk mengecek apakah sensor sudah terdetek atau tidak
    if (!mpu.begin()) { //ketika tidak terdetek
      Serial.println("[#]ERROR: Gagal mencari MPU6050 chip");
      delay(1000);
      }
     
     if (mpu.begin()){ //ketika terdetek
      Serial.println("Sensor Gyroscope aktif");
      cek = true;
     }
  }
}

void kasusDua() {
  bool cek = false;
  float bacaX;
  while (cek == false) { //pengulangan untuk kasus tiga
    sensors_event_t a, g, temp; //membuat objek untuk akselerasi, gyroscope, dan temperature
    mpu.getEvent(&a, &g, &temp); //mengambil nilai sensor

    bacaSerial = Serial.readString();  //untuk membaca nilai string di Serial Monitor
    bacaX = g.gyro.x; //membaca rotasi gyroscpoe pada sumbu x

    Serial.print("Rotation X: ");
    Serial.print(g.gyro.x);
    Serial.print(", Y: ");
    Serial.print(g.gyro.y);
    Serial.print(", Z: ");
    Serial.print(g.gyro.z);
    Serial.println();

    //nilai rotasi x jika lebih dari 0.05, maka warning(buzzer, led 5x blink) akan menyala
    if (bacaX > 0.05) {
      digitalWrite(buzzer, HIGH);
      Serial.println("Warning!");
      
    } else { // jika x tidak melebihi 0.05
      digitalWrite(buzzer, LOW);
      Serial.println("udah ngga warning");
    }
    
    if (bacaSerial == "stop") { //jika send kata "stop" diserial monitor, maka akan berhenti
      digitalWrite(buzzer, LOW);
      cek = true;
      Serial.println("KASUS 2 berhasil dihentikan");
      bacaSerial = " ";
    }
  }
}

void kasusTiga() {
  bool cek = false;
  float bacaX;
  while (cek == false) {
    sensors_event_t a, g, temp; //membuat objek untuk akselerasi, gyroscope, dan temperature
    mpu.getEvent(&a, &g, &temp); //mengambil nilai sensor

    bacaX = g.gyro.x; //membaca nilai x
    
    analogWrite(led, bacaX);
    Serial.println(bacaX);
    if (bacaSerial == "stop") { //jika send kata "stop" diserial monitor, maka akan berhenti
      cek = true;
      Serial.println("KASUS 3 berhasil dihentikan");
      bacaSerial = " ";
    }
  }
}
