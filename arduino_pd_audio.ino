// Le code minimal

#include <Arduino.h>
#include <Bounce2.h>

Bounce2::Button bouton; // la variable du bouton

#define BROCHE_BOUTON 2 // defini la broche sur le arduino qu'on nomme BROCHE_BOUTON

void setup()
{
  Serial.begin(115200);
  bouton.setPressedState(LOW);
  bouton.attach(BROCHE_BOUTON, INPUT_PULLUP); //tjr mettre pour setup le bouton
}

void loop()
{
  bouton.update(); // super important, tjr le mettre

  if (bouton.pressed())
  {
    Serial.print("bouton1 "); // nomme le bouton pour différencier dans Pd, ecrire "route bouton1" fait en sorte que ca ignore bouton1 et print directement 1
    Serial.print(1);
    Serial.println();
  }
}
