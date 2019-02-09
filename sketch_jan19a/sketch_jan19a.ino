int rossoA = 4;
int gialloA = 3;
int verdeA = 2;
int rossoB = 5;
int gialloB = 6;
int verdeB = 7;
int DurataLampeggioVerde = 0;
int NumeroLampeggioVerde = 0;
int DurataGiallo = 0;
int DurataRosso = 0;
int DurataVerde = 0;


void setup() {
  
  Serial.begin(9600);
    pinMode(rossoA,OUTPUT);
    pinMode(gialloA,OUTPUT);
    pinMode(verdeA,OUTPUT);
    pinMode(rossoB,OUTPUT);
    pinMode(gialloB,OUTPUT);
    pinMode(verdeB,OUTPUT);
    

    if (DurataLampeggioVerde == 0)
    {
      LampeggiOVerdeDurata();
    }
    
    if (NumeroLampeggioVerde == 0)
    {
      LampeggiOVerdeNumero();
    }
 
    if (DurataGiallo == 0)
    {
      GialloDurata();
    }
    
    if (DurataRosso == 0)
    {
      RossoDurata();
    }
    
    CalcoloVerdeAlone();
  
}
    
    

void loop(){

    fase1();
    CalcoloLampeggio(7);
    gialloON();
    fase2();
    CalcoloLampeggio(2);
    gialloON();

}




void LampeggiOVerdeDurata(){
       Serial.println ("Inserire i vari parametri per il semaforo");
       Serial.println ("inserisci la durata di ogni lampeggio verde in secondi");
       while(Serial.available() == 0) {};
       DurataLampeggioVerde = Serial.readString().toInt();
}
       
void LampeggiOVerdeNumero(){
       Serial.println ("inserisci il numero di lampeggi che eseguirà il verde");
       while(Serial.available() == 0) {};
       NumeroLampeggioVerde = Serial.readString().toInt();
}
       
void GialloDurata(){
       Serial.println ("inserisci la durata del giallo in secondi");
       while(Serial.available() == 0) {};
       DurataGiallo = Serial.readString().toInt();
}
       
void RossoDurata(){
       Serial.print ("inserisci la durata del rosso in secondi");
       while (Serial.available() == 0) {};
       DurataRosso = Serial.readString().toInt();
}


       

void CalcoloLampeggio(int pin){
    for ( int i=0 ; i<NumeroLampeggioVerde ; i++ ){
    lampeggiaVerde(pin, DurataLampeggioVerde/2);
    }
}
    
      
void lampeggiaVerde(int pin, int tempo) {
      digitalWrite (pin, LOW);
      delay  (tempo);
      digitalWrite (pin, HIGH);
      delay  (tempo);
}

void CalcoloVerdeAlone(){
     DurataVerde=DurataRosso-DurataGiallo-(NumeroLampeggioVerde*DurataLampeggioVerde);
     while(DurataVerde<2000){
      setup();
     }
}

 

      
void fase1(){
    digitalWrite (verdeB, HIGH);
    digitalWrite (verdeA, LOW);
    digitalWrite (rossoA, HIGH);
    digitalWrite (rossoB, LOW);
    digitalWrite (gialloB, LOW);
    digitalWrite (gialloA, LOW);
    delay(DurataVerde);
}

void fase2(){
    digitalWrite (verdeB, LOW);
    digitalWrite (verdeA, HIGH);
    digitalWrite (rossoA, LOW);
    digitalWrite (rossoB, HIGH);
    digitalWrite (gialloB, LOW);
    digitalWrite (gialloA, LOW);
    delay(DurataVerde);
}
 
void gialloON(){
   digitalWrite (gialloB, HIGH);
   digitalWrite (gialloA, HIGH);
   digitalWrite (verdeB, LOW);
   digitalWrite (verdeA, LOW);
   delay(DurataGiallo);
}
