#include <SoftwareSerial.h>
 
#define brocheRX 12
#define brocheTX 11

SoftwareSerial apc220(brocheRX,brocheTX);

unsigned int compteur;

void setup() {
  apc220.begin(2400);
  Serial.begin(115200);
}

void loop() {
  apc220.print("coucou ");
  apc220.println(compteur);
  
  Serial.print("coucou ");
  Serial.println(compteur);

  compteur++;

  delay(1500);
}
