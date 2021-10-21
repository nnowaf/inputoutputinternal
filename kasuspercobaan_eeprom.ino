/*
	Nama : Mohammad Nowaf
	NIM  : 6702202026
	Soal : kasus percobaan eeprom
*/

#include <EEPROM.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(9, 8, 5, 4, 3, 2);


//analog
int LCDContrast = 10;
int potensio = A2;
int buzzer = A1;
int LEDmerah = 6;

//digital
int button = 12;

int nilaitekan = 0; //nilai tekan untuk button

//eeprom
int alamat = 0;
int nilai;

//variabel pembantu
bool status = false;
bool statusPressed = false;

void setup(){
  pinMode(LEDmerah, OUTPUT);
  pinMode(LCDContrast, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(potensio, INPUT);
  pinMode(button, INPUT);
  
  analogWrite(LCDContrast, 0); //setup static contrast untuk LCD 
  
  lcd.begin(16, 2);
  lcd.setCursor(1, 0);
  lcd.print("MOHAMMAD NOWAF");
  delay(1000);
  lcd.clear();
  Serial.begin(9600);
}

void loop(){

  /*
   * jika button ditekan maka variabel pembantu 'status' menjadi true
   * dan jika 'status' true maka variabel 'nilaitekan' ditambah satu, kemudian variabel pembantu 'status' menjadi false dan 'statusPressed' menjadi true.
   * 
   */
  if(digitalRead(button) == LOW){
    status = true;
    if (status == true){
      	++nilaitekan;
      	status = false;
      	statusPressed = true;
    	delay(500);
    }
  }
  
  /*
   * jika variabel nilai tekan dan variabel pembantu memenuhi kondisi
   * maka akan memanggil prosedurnya dan merubah variabel pembantu menjadi semula.
   * ****
   * VARIABEL PEMBANTU : status dan statusPressed
   * variabel pembantu membantu agar pemanggilan prosedur hanya dipanggil satu kali saja.
   * ****
   * untuk melihat permasalahannya jika tidak ada variabel pembantu, coba untuk menghapus statusPressed pada setiap if else
   */
  if(nilaitekan == 1 && statusPressed == true){
	  kasusSatu();   
    statusPressed = false;
  } else if(nilaitekan == 2 && statusPressed == true){
  	kasusDua();
    statusPressed = false;
  } else if(nilaitekan == 3 && statusPressed == true){
  	kasusTiga();
    statusPressed = false;
  } else if(nilaitekan == 4 && statusPressed == true){
  	kasusEmpat();
    statusPressed = false;
  } else if(nilaitekan >= 5){
  	nilaitekan = 0;
  }
  
  
}

//prosedur untuk button dipencet 1x
void kasusSatu(){
  
  lcd.setCursor(0, 0);
  lcd.print("input data");
  delay(1000);
  lcd.clear();
  
  Serial.println("alamat\tnilai");
  while(true){
    alamat++;
    nilai = analogRead(potensio) / 4;
    EEPROM.write(alamat, nilai);
    lcd.setCursor(0, 0);
    lcd.print("ALAMAT:");
    lcd.setCursor(7, 0);
    lcd.print(alamat);
    lcd.setCursor(0, 1);
    lcd.print("NILAI:");
    lcd.setCursor(6, 1);
    lcd.print(nilai);
        
    Serial.print(alamat);
    Serial.print("\t");
    Serial.println(nilai);
    if (alamat == 512) {
      alamat = 0;
      break;
    }
  }
}

//prosedur untuk button dipencet 2x
void kasusDua(){
  
  lcd.setCursor(0, 0);
  lcd.print("lihat data");
  delay(1000);
  lcd.clear();
     
  nilaitekan = 2;
  int listenerData;
  Serial.println("alamat\tnilai");
  for (int i = 0; i <= 512; i++) {
    listenerData = EEPROM.read(i);
    analogWrite(LEDmerah, listenerData);
    
    Serial.print(i);
    Serial.print("\t");
    Serial.println(listenerData);
  }
}

//prosedur untuk button dipencet 3x
void kasusTiga(){
  lcd.clear();
  for (int i = 0; i <= 512; i++){
  	EEPROM.write(i, 0);
  }
  
  analogWrite(buzzer, 255);
  delay(2000);
  analogWrite(buzzer, 0);
  delay(1000);

}

//prosedur untuk button dipencet 4x
void kasusEmpat(){
  lcd.clear();
 
  int listenerData;
  Serial.println("alamat\tdata");
  for (int i = 0; i <= 512; i++){
    listenerData = EEPROM.read(i);
    Serial.print(i);
    Serial.print("\t");
    Serial.println(listenerData);
  }
}
