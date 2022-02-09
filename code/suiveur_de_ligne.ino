const int capteurGauche = 11; 
const int capteurDroit = 10;

//moteur A
const int ENA=33;
const int IN1=22;
const int IN2=36;

//moteur B
const int ENB=41;
const int IN3=28;
const int IN4=34;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
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

  //activation du moteur B
  digitalWrite(IN4,HIGH);
  digitalWrite(IN3,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(capteurDroit) == 1 && digitalRead(capteurGauche) == 1){
    digitalWrite(ENA, HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN1,HIGH);
    digitalWrite(ENB, HIGH);
    digitalWrite(IN4,HIGH);
    digitalWrite(IN3,LOW);
    delay(50);
    Serial.println("tout droit");
  }
  if (digitalRead(capteurDroit) == 1 && digitalRead(capteurGauche) == 0){
    digitalWrite(ENA, LOW);
    digitalWrite(ENB, HIGH);
    digitalWrite(IN4,HIGH);
    digitalWrite(IN3,LOW);
    delay(50);
    Serial.println("droite");
  }
  if (digitalRead(capteurDroit) == 0 && digitalRead(capteurGauche) == 1){
    digitalWrite(ENA, HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN1,HIGH);
    digitalWrite(ENB, LOW);
    delay(50);
    Serial.println("gauche");
  }
}
