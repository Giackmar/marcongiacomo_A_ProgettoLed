int rossoA = 4;
int gialloA = 3;
int verdeA = 2;
int rossoB = 5;
int gialloB = 6;
int verdeB = 7;
int numLampeggi;
int richiesta;

void setup() {
    pinMode(rossoA,OUTPUT);
    pinMode(gialloA,OUTPUT);
    pinMode(verdeA,OUTPUT);
    pinMode(rossoB,OUTPUT);
    pinMode(gialloB,OUTPUT);
    pinMode(verdeB,OUTPUT);
    //da qui è nuovo
    richiesta = 0;
}
  

  void loop() {
  if (richiesta == 0)
    {
      richiestaValori();
      }


      
    }
    


void richiestaValori(){
       print("quanti lampeggi verde?");
       while(Serial.available == 0) {};
       numeLampeggi = Serial.read().toInt();
   }
 }

   
void lampeggiaVerdeB(){
   digitalWrite (verdeB, HIGH);
      delay  (1000);
      digitalWrite (verdeB, LOW);
      delay  (1000);
  }



void lampeggiaVerdeA(){
 digitalWrite (verdeA, HIGH);
      delay  (1000);
      digitalWrite (verdeA, LOW);
      delay  (1000);
  
}
      
void semaforo() {
      digitalWrite (rossoA, HIGH);
      digitalWrite (verdeB, HIGH);
      digitalWrite (gialloA, LOW);
      digitalWrite (gialloB, LOW);
      digitalWrite (rossoB, LOW);
      digitalWrite (verdeA, LOW);
      delay  (10000);
      
      lampeggiaVerdeB();
      lampeggiaVerdeB();
      lampeggiaVerdeB();
      lampeggiaVerdeB();
      
      
      digitalWrite (rossoA, HIGH);
      digitalWrite (gialloA, HIGH);
      digitalWrite (gialloB, HIGH);
      digitalWrite (verdeB, LOW);
      delay  (2000);

      digitalWrite (rossoB, HIGH);
      digitalWrite (verdeA, HIGH);
      digitalWrite (gialloA, LOW);
      digitalWrite (gialloB, LOW);
      digitalWrite (rossoA, LOW);
      delay  (10000);

      lampeggiaVerdeA();
      lampeggiaVerdeA();
      lampeggiaVerdeA();
      lampeggiaVerdeA();
      
      digitalWrite (rossoB, HIGH);
      digitalWrite (gialloB, HIGH);
      digitalWrite (gialloA, HIGH);
      digitalWrite (verdeA, LOW);
      delay  (10000);

      

      
    
}    
