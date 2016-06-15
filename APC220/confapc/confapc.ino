#include <SoftwareSerial.h>
 
#define brocheRX 12
#define brocheTX 11
#define brocheSET 8
 
// nouveau port série
SoftwareSerial apc220(brocheRX,brocheTX);

// fonction de décodage des vitesses
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

// configuration
void setup() {
  // objet pour stocker la réponse du module
  String chaine;
  
  pinMode(brocheSET, OUTPUT);
  apc220.begin(9600);
  Serial.begin(115200);
  
  // activation du mode configuration
  digitalWrite(brocheSET, LOW);
  delay(10);
  // envoi de la commande
  apc220.println("RD");
  delay(10);

  // lecture de la réponse
  if(apc220.available()) {
    // on lit jusqu'au caractère CR
    // (on ignore LF pour ne pas stocker CR dans la chaîne)
    chaine = apc220.readStringUntil('\r');
  }

  // affichage des informations
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
}

void loop() {
}
