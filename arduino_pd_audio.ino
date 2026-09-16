// Le code minimal

#include <Arduino.h> 

void setup() {
  Serial.begin(115200);

}

void loop() {
Serial.print("bouton0 ");  // Envoie le descripteur et son espace en un seul bloc
Serial.println(1);   // Envoie la valeur et ajoute automatiquement le saut de ligne final

}
