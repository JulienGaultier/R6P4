#include <NewPing.h>
const int trig = 7;
const int echo = 5;
float lecture_echo = 0;
float distance = 0;

const int capteurGauche = 18; 
const int capteurDroit = 19;
const int capteurExterieurDroit = 20;
const int capteurExterieurGauche = 21;



void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(capteurGauche, INPUT);
  pinMode(capteurDroit, INPUT);
  Serial.println("lets go");
}

void loop() {
  // put your main code here, to run repeatedly:
  NewPing sonar(trig, echo, 30);
  Serial.print("distance capteur - objet = ");
  Serial.print(sonar.ping_cm());
  Serial.println(" cm");
  if (1 <= sonar.ping_cm() && sonar.ping_cm() <= 10) {
    Serial.println("obstacle pas loin stop");
    Serial.println("recherche de chemin alternatif...");
    while (digitalRead(capteurExterieurDroit) != 0){
      Serial.println("on fait pivoter le robot vers la gauche pour trouver un nouveau chemin");
      delay(500);
    }
    delay(500);
    if (10 <= sonar.ping_cm()){
       Serial.println("aucun obstacle a gauche");
       while (analogRead(capteurGauche) != 1){
          Serial.println("on effectue une manoeuvre pour éviter l'obstacle");
          delay(500);
          }
        }
      else {
        while (digitalRead(capteurExterieurDroit) != 0){      
          Serial.println("on fait pivoter le robot vers la droite pour trouver un nouveau chemin");
          delay(500);
          }
        while (analogRead(capteurDroit) != 1){
          Serial.println("on effectue une manoeuvre pour éviter l'obstacle");
          delay(500);
        }
      }
    }
  Serial.println("pas d'obstacle on avance !");
}
