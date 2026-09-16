// Le code minimal

#include <Arduino.h>
#include <Bounce2.h> // inclu la librairie pour le bouton 

Bounce2::Button bouton; // la variable du bouton
Bounce2::Button bouton2;

#define BROCHE_BOUTON 2 // defini la broche sur le arduino qu'on nomme BROCHE_BOUTON
#define BROCHE_BOUTON2 4
#define BROCHE_DEL 3

bool etatDel = LOW;

void setup()
{
  //setup pour boutons
  Serial.begin(115200);
  bouton.setPressedState(LOW);
  bouton.attach(BROCHE_BOUTON, INPUT_PULLUP); //tjr mettre pour setup le bouton
  bouton2.setPressedState(LOW);
  bouton2.attach(BROCHE_BOUTON2, INPUT_PULLUP);
  //setup pour del
  pinMode(BROCHE_DEL, OUTPUT);
  digitalWrite(BROCHE_DEL, etatDel);
}

void loop()
{
  bouton.update(); // super important, tjr le mettre
  bouton2.update();

  if (bouton.pressed()) 
  {
    etatDel = !etatDel; //envoie le contraire de etatdel : etatdel commence a 0 donc quand on appuie ca va etre 1 et ca continue a flip

    Serial.print("bouton1 "); // nomme le bouton pour différencier dans Pd, ecrire "route bouton1" fait en sorte que ca ignore bouton1 et print directement 1
    if (etatDel == true) {
      Serial.print(1);
    } else {
      Serial.print(0);
    }
    Serial.println();

    digitalWrite(BROCHE_DEL, etatDel);
  }

  if(bouton2.pressed()) { // pour verifier l'autre bouton, on doit faire un autre if
    Serial.print("bouton2 "); 
    Serial.print(1);
    Serial.println();
  }
}
