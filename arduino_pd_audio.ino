// Le code minimal

#include <Arduino.h>
#include <Bounce2.h> // inclu la librairie pour le bouton 

Bounce2::Button bouton; // la variable du bouton
Bounce2::Button bouton2;

#define BROCHE_BOUTON 2 // defini la broche sur le arduino qu'on nomme BROCHE_BOUTON
#define BROCHE_BOUTON2 4

void setup()
{
  Serial.begin(115200);
  bouton.setPressedState(LOW);
  bouton.attach(BROCHE_BOUTON, INPUT_PULLUP); //tjr mettre pour setup le bouton
  bouton2.setPressedState(LOW);
  bouton2.attach(BROCHE_BOUTON2, INPUT_PULLUP);
}

void loop()
{
  bouton.update(); // super important, tjr le mettre
  bouton2.update();

  if (bouton.pressed() || bouton2.pressed()) // pour verifier l'autre bouton, on doit faire un autre if
  {
    Serial.print("bouton1 "); // nomme le bouton pour différencier dans Pd, ecrire "route bouton1" fait en sorte que ca ignore bouton1 et print directement 1
    Serial.print(1);
    Serial.println();
  }

}
