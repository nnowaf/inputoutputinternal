/*
 * Nama  : Mohammad Nowaf
 * Kelas : D3TK 44 01
 * NIM   : 6702202026
 * Soal  : kasus percobaan
*/

//set pin dengan nama 
int LEDldr = 11;
int LEDpd = 10;

int buzzer = 12;
int relay = 13; 
int button = 8;
int LDR = A0;
int pd = A1;

//untuk button
int nilaitekan = 0; 
int buttonKondisi; 

//batas untuk kondisi nilai sensor
int batas = 500;

bool validasi = false; //variabel bantu
  
void setup() {
  pinMode(relay, OUTPUT); 
  pinMode(LEDldr, OUTPUT);
  pinMode(LEDpd, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  pinMode(LDR, INPUT);
  pinMode(pd, INPUT);
  pinMode(button, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  buttonKondisi = digitalRead(button); //membaca nilai button

 /*
  * jika button ditekan maka variabel nilai tekan ditambah satu, dan
  * variabel pembantu menjadi true
  */
  if (buttonKondisi == LOW){
    ++nilaitekan;
    validasi = true;
    delay(500);
    Serial.println(nilaitekan);
  }
  

  /*
   * jika kondisi nilaitekan dan variabel pembantu memenuhi, maka akan memanggil prosedur,
   * setelah prosedurnya sudah dipanggil, maka variabel pembantunya dirubah menjadi default = false.
   * jika variabel 'nilaitekan' == 5, maka nilainya dirubah menjadi 0 nilaitekan = 0.
   * 
   */ 
  if (nilaitekan == 1 && validasi == true){
    kasusSatu();
    validasi = false;
  } else if (nilaitekan == 2 && validasi == true) {
    kasusDua();
    validasi = false;
  } else if (nilaitekan == 3 && validasi == true) {
  	kasusTiga();
    validasi = false;
  } else if (nilaitekan == 4 && validasi == true) {
  	kasusEmpat();
    validasi = false;
  } else if (nilaitekan == 5 && validasi == true) {
  	nilaitekan = 0;
    validasi = false;
    
  }
}

//untuk kasus button ditekan 1 kali
void kasusSatu() {
  String val; 
  bool cek = true;
  while (cek == true) {
  	val = Serial.readString(); //membaca string di Serial Monitor
    analogWrite(LEDldr, analogRead(LDR)); //membaca nilai sensor LDR
    Serial.println(analogRead(LDR));
    
    if (val == "stop") { //jika kita ketik kata "stop" di serial monitor, maka loop akan berhenti dan prosedurnya selesai.
      Serial.println("berhenti. pencet button 1x lagi untuk melanjutkan stage selanjutnya.");
      cek = false;
      analogWrite(LEDldr, 0);
    }
    
  }
}

//untuk kasus button ditekan 2 kali
void kasusDua() {
  String val;
  bool cek = true;
  while (cek == true) {
    val = Serial.readString(); //membaca string di Serial Monitor
    analogWrite(LEDpd, analogRead(pd)); //membaca nilai sensor photodiode
    Serial.println(analogRead(pd));
    
    if (val == "stop") { //jika kita ketik kata "stop" di serial monitor, maka loop akan berhenti dan prosedurnya selesai.
      Serial.println("berhenti. pencet button 1x lagi untuk melanjutkan stage selanjutnya.");
      cek = false;
      analogWrite(LEDpd, 0);
    }
  }
}

//untuk kasus button ditekan 3 kali
void kasusTiga() {
  String val;
  int nilai;
  bool cek = true;
  while (cek == true) {
  	val = Serial.readString(); //membaca string di Serial Monitor
    nilai = analogRead(pd); //membaca nilai sensor photodiode
    Serial.println(nilai);
    if (nilai > batas) { //jika sensor melebihi batas = 500, maka buzzer menyala. jika tidak maka buzzer off
      digitalWrite(buzzer, HIGH);
    } else {
      digitalWrite(buzzer, LOW);
    }
    
    if (val == "stop") { //jika kita ketik kata "stop" di serial monitor, maka loop akan berhenti dan prosedurnya selesai.
      Serial.println("berhenti. pencet button 1x lagi untuk melanjutkan stage selanjutnya");
      cek = false;
      digitalWrite(buzzer, LOW);
    }
  }
}

//untuk kasus button ditekan 4 kali
void kasusEmpat() {
  String val;
  int nilai;
  bool cek = true;
  while (cek == true) {
  	val = Serial.readString(); //membaca string di Serial Monitor
    nilai = analogRead(LDR); //membaca nilai sensor LDR
    Serial.println(nilai);
    
    if (nilai > batas) { //jika sensor melebihi batas = 500, maka buzzer menyala. jika tidak maka buzzer off
      digitalWrite(buzzer, HIGH);
    } else {
      digitalWrite(buzzer, LOW);
    }
    
    if (val == "stop") { //jika kita ketik kata "stop" di serial monitor, maka loop akan berhenti dan prosedurnya selesai.
      Serial.println("berhenti. pencet button 1x lagi untuk melanjutkan stage selanjutnya");
      cek = false;
      digitalWrite(buzzer, LOW);
    }
  }
}
