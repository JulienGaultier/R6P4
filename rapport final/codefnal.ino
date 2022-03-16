//clignotant
const int clignoGauche = 37;
const int clignoDroite = 35;
int i = 0;
int x = 0;

// bluetooth
char r = 's';
int c = 0;
int v = 0;

// capteurs ultrasons
#include <NewPing.h>
const int trig = 13;
const int echo = 12;
float lecture_echo = 0;
float distance = 0;

// moteurs
//moteur A
const int ENA=36;
const int IN1=26;
const int IN2=40;

//moteur B
const int ENB=30;
const int IN3=32;
const int IN4=24;

// capteurs de lignes
const int capteurExterieurGauche = 5; 
const int capteurDroit = 7; 
const int capteurGauche = 4; 
const int capteurExterieurDroit = 8; 
const int capteurCentral = 6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial.println("bonjour");

  //configurer les capteurs de ligne en entrées
  pinMode(capteurExterieurGauche, INPUT);
  pinMode(capteurGauche, INPUT);
  pinMode(capteurCentral, INPUT);
  pinMode(capteurDroit, INPUT);
  pinMode(capteurExterieurDroit, INPUT);
  
  // configurer les broches reliées aux moteurs comme sortie
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(IN1,OUTPUT); 
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);

  //parametrage du moteur A
  digitalWrite(IN2,LOW);
  digitalWrite(IN1,HIGH);

  //parametrage du moteur B
  digitalWrite(IN4,HIGH);
  digitalWrite(IN3,LOW);

  //moteur éteind
  digitalWrite(ENA,LOW); //moteur A off
  digitalWrite(ENB,LOW); //moteur B off

  
  //initialisation des clignos
  pinMode(clignoGauche, OUTPUT);
  pinMode(clignoDroite, OUTPUT);

  

}

void loop() {
  // put your main code here, to run repeatedly:

  //bluetooth
  if (Serial1.available()){
    r = Serial1.read();
    Serial.println(r);
  }

  // traduction de l'information envoyé via bluetooth en direction à suivre
  if (r == 'a'){
    c = 1;}

  if (r == 'b'){
    c = 2;}
    
  if (r == 'c'){
    c = 3;}
    
  if (r == 'd'){
    c = 4;}

  if (r == 'e'){
    c = 5;}

  delay(100);
    
  while (r != 's'){
     
      if (digitalRead(capteurDroit) == 1 && digitalRead(capteurGauche) == 1 && digitalRead(capteurCentral) == 1){
          analogWrite(ENA, 0);
          analogWrite(ENB, 0);
          while(1);
      }
           
      if (digitalRead(capteurDroit) == 0 && digitalRead(capteurGauche) == 0){
          analogWrite(ENA, 130);
          analogWrite(ENB, 130);
          Serial.println("tout droit");
      }
      
      if (digitalRead(capteurDroit) == 1 && digitalRead(capteurGauche) == 0){
          analogWrite(ENA, 0);
          analogWrite(ENB, 130);
          Serial.println("droite");
      }
  
      if (digitalRead(capteurDroit) == 0 && digitalRead(capteurGauche) == 1){
          analogWrite(ENA, 130);
          analogWrite(ENB, 0);
          Serial.println("gauche");
      } 

      if (digitalRead(capteurExterieurGauche) == 1 && digitalRead(capteurCentral) == 0){
        analogWrite(ENA, 0);
        analogWrite(ENB, 0);
        delay(100);
        v++;
        if (c==v){
          while (i<5){
            digitalWrite(clignoGauche, LOW);
            delay(400);
            digitalWrite(clignoGauche, HIGH);
            delay(400); 
            i++;           
            }
            digitalWrite(clignoGauche, HIGH);
            i=0;
            analogWrite(ENA, 130);
            analogWrite(ENB, 0);
            delay(700);
          }
          analogWrite(ENA, 130);
          analogWrite(ENB, 130);
          delay(100);
        }

      if (digitalRead(capteurExterieurDroit) == 1 && digitalRead(capteurCentral) == 0){
        analogWrite(ENA, 0);
        analogWrite(ENB, 0);
        delay(100);
        v++;
        if (c==v){
          while (i<5){
            digitalWrite(clignoDroite, LOW);
            delay(400);
            digitalWrite(clignoDroite, HIGH);
            delay(400);   
            i++;         
            }          
            digitalWrite(clignoGauche, HIGH);
            i=0;
            analogWrite(ENA, 0);
            analogWrite(ENB, 130);
            delay(700);
          }     
          analogWrite(ENA, 130);
          analogWrite(ENB, 130);
          delay(100);
        }

  }
}
