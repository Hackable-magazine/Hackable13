#include <SoftwareSerial.h>
 
#define brocheRX 12
#define brocheTX 11
#define brocheSET 8
 
SoftwareSerial apc220(brocheRX,brocheTX);

void printspeed(unsigned char data) {
  switch(data) {
    case '0':
      Serial.println("1200 bps"); break;
    case '1':
      Serial.println("2400 bps"); break;
    case '2':
      Serial.println("4800 bps"); break;
    case '3':
      Serial.println("9600 bps"); break;
    case '4':
      Serial.println("19200 bps"); break;
    case '5':
      Serial.println("38400 bps"); break;
    case '6':
      Serial.println("57600 bps"); break;
    default:
      Serial.println("???? bps");
  }
}

void setup() {
  String chaine;
  
  pinMode(brocheSET, OUTPUT);
  apc220.begin(9600);
  Serial.begin(115200);

  delay(10);
  apc220.println("WR 434000 2 9 1 0");
  delay(10);
  pinMode(brocheSET, LOW);
  delay(50);
  pinMode(brocheSET, HIGH);
  delay(10);
  if(apc220.available()) {
    apc220.readStringUntil('\n');
  }

  
  digitalWrite(brocheSET, LOW);
  delay(10);
  apc220.println("RD");
  delay(10);

// PARA 434000 2 5 1 0

  if(apc220.available()) {
    chaine = apc220.readStringUntil('\n');
  }

  Serial.print("Configuration : ");
  Serial.println(chaine);
  
  Serial.print("Vitesse radio: ");
  printspeed(chaine.charAt(12));
  
  Serial.print("Vitesse UART: ");
  printspeed(chaine.charAt(16));
  
  Serial.print("Parite: ");
  switch(chaine.charAt(18)) {
    case '0':
      Serial.println("aucune"); break;
    case '1':
      Serial.println("impaire"); break;
    case '2':
      Serial.println("pair"); break;
    default:
      Serial.println("????"); break;
  }

  digitalWrite(brocheSET, HIGH);
  delay(50);
  apc220.begin(2400);
  delay(1500);
}

unsigned int compteur;

void loop() {
  apc220.print("coucou ");
  apc220.println(compteur);
  Serial.print("coucou ");
  Serial.println(compteur);

  compteur++;

  delay(1500);
}
