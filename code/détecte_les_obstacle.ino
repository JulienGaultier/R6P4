#include <NewPing.h>
const int trig = 7;
const int echo = 5;
float lecture_echo = 0;
float distance = 0;

int capteurGauche = 44; 
int capteurDroit = 48;

//moteur A
int ENA=33;
int IN1=22;
int IN2=36;

//moteur B
int ENB=41;
int IN3=28;
int IN4=34;




void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(ENA,OUTPUT); //configurer les broches comme sortie
  pinMode(ENB,OUTPUT);
  pinMode(IN1,OUTPUT); 
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(capteurGauche, INPUT);
  pinMode(capteurDroit, INPUT);
  digitalWrite(ENA,LOW); //moteur A off
  digitalWrite(ENB,LOW); //moteur B off
  Serial.println("lets go");

  //activation du moteur A
  digitalWrite(IN2,LOW);
  digitalWrite(IN1,HIGH);
  analogWrite(ENA, 100);

  //activation du moteur B
  digitalWrite(IN4,LOW);
  digitalWrite(IN3,HIGH);
  analogWrite(ENB, 100);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  NewPing sonar(trig, echo, 30);
  Serial.print("distance capteur - objet = ");
  Serial.print(sonar.ping_cm());
  Serial.println(" cm");
  if (10 <= sonar.ping_cm() && sonar.ping_cm() <= 20){
    if (analogRead(capteurDroit) == 0 && analogRead(capteurGauche) == 0){
      analogWrite(ENA, 70);
      digitalWrite(IN2,LOW);
      digitalWrite(IN1,HIGH);
      analogWrite(ENB, 70);
      digitalWrite(IN4,LOW);
      digitalWrite(IN3,HIGH);
      Serial.println("avance tout droit au ralenti");
      delay(500);
    }
    if (analogRead(capteurDroit) == 0 && analogRead(capteurGauche) == 1){
      analogWrite(ENA, 50);
      digitalWrite(IN2,LOW);
      digitalWrite(IN1,HIGH);
      analogWrite(ENB, 100);
      digitalWrite(IN4,LOW);
      digitalWrite(IN3,HIGH);
      Serial.println("reajuste la trajectoire vers la droite au ralentit");
      delay(500);
    }
    if (analogRead(capteurDroit) == 1 && analogRead(capteurGauche) == 0){
      analogWrite(ENA, 100);
      digitalWrite(IN2,LOW);
      digitalWrite(IN1,HIGH);
      analogWrite(ENB, 50);
      digitalWrite(IN4,LOW);
      digitalWrite(IN3,HIGH);
      Serial.println("reajuste la trajectoire vers la gauche au ralentit");
      delay(500);
    }
  }
  if (1 <= sonar.ping_cm() && sonar.ping_cm() <= 10) {
      analogWrite(ENA, 0);
      digitalWrite(IN2,LOW);
      digitalWrite(IN1,HIGH);
      analogWrite(ENB, 0);
      digitalWrite(IN4,LOW);
      digitalWrite(IN3,HIGH);
      Serial.println("obstacle pas loin stop");
      delay(500);
      analogWrite(ENA, 100);
      digitalWrite(IN2,LOW);
      digitalWrite(IN1,HIGH);
      analogWrite(ENB, 0);
      digitalWrite(IN4,LOW);
      digitalWrite(IN3,HIGH);
      Serial.println("recherche de chemin alternatif...");
      delay(1000);
      if (10 <= sonar.ping_cm()){
        Serial.println("aucun obstacle a gauche");
        while (analogRead(capteurGauche) != 1){
          analogWrite(ENA, 75);
          digitalWrite(IN2,LOW);
          digitalWrite(IN1,HIGH);
          analogWrite(ENB, 100);
          digitalWrite(IN4,LOW);
          digitalWrite(IN3,HIGH);
          delay(500);
        }
      }
      else {
        analogWrite(ENA, 0);
        digitalWrite(IN2,LOW);
        digitalWrite(IN1,HIGH);
        analogWrite(ENB, 100);
        digitalWrite(IN4,LOW);
        digitalWrite(IN3,HIGH);
        Serial.println("essayons a droite");
        delay(2000);
        while (analogRead(capteurDroit) != 1){
          analogWrite(ENA, 100);
          digitalWrite(IN2,LOW);
          digitalWrite(IN1,HIGH);
          analogWrite(ENB, 75);
          digitalWrite(IN4,LOW);
          digitalWrite(IN3,HIGH);
          delay(500);
        }
      }
    }
  Serial.println("pas d'obstacle on avance !");
  if (analogRead(capteurDroit) == 0 && analogRead(capteurGauche) == 0){
    analogWrite(ENA, 120);
    digitalWrite(IN2,LOW);
    digitalWrite(IN1,HIGH);
    analogWrite(ENB, 95);
    digitalWrite(IN4,LOW);
    digitalWrite(IN3,HIGH);
    Serial.println("tout droit !");
    delay(500);
  }
  if (analogRead(capteurDroit) == 0 && analogRead(capteurGauche) == 1){
    analogWrite(ENA, 50);
    digitalWrite(IN2,LOW);
    digitalWrite(IN1,HIGH);
    analogWrite(ENB, 125);
    digitalWrite(IN4,LOW);
    digitalWrite(IN3,HIGH);
    Serial.println("a gauche toute !");
    delay(500);
  }
  if (analogRead(capteurDroit) == 1 && analogRead(capteurGauche) == 0){
    analogWrite(ENA, 125);
    digitalWrite(IN2,LOW);
    digitalWrite(IN1,HIGH);
    analogWrite(ENB, 50);
    digitalWrite(IN4,LOW);
    digitalWrite(IN3,HIGH);
    Serial.println("a droite toute !");
    delay(500);
  }
}
