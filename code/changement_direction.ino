//moteur A
const int ENA=33;
const int IN1=22;
const int IN2=36;

//moteur B
const int ENB=41;
const int IN3=28;
const int IN4=34;

const int capteurGauche = 18; 
const int capteurDroit = 19;
const int capteurExterieurDroit = 20;
const int capteurExterieurGauche = 21;
const int capteurCentral = 22;

void setup() {
  // put your setup code here, to run once:
  pinMode(capteurExterieurDroit, INPUT);
  pinMode(capteurExterieurGauche, INPUT);
  pinMode(capteurCentral, INPUT);
  pinMode(ENA,OUTPUT); //configurer les broches comme sortie
  pinMode(ENB,OUTPUT);
  pinMode(IN1,OUTPUT); 
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (capteurCentral == 0 && capteurExterieurDroit == 0){
    while (capteurGauche == 0){
      digitalWrite(ENA, LOW);
      digitalWrite(ENB, HIGH);
      digitalWrite(IN4,HIGH);
      digitalWrite(IN3,LOW);
      delay(50);
      Serial.println("tourne a droite");
    }
  }
  if (capteurCentral == 0 && capteurExterieurGauche == 0){
    while (capteurGauche == 0){
      digitalWrite(ENA, HIGH);
      digitalWrite(IN2,LOW);
      digitalWrite(IN1,HIGH);
      digitalWrite(ENB, LOW);
      delay(50);
    }
}
