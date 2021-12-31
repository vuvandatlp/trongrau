#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define in1 2
#define in2 3
#define in3 4
#define in4 5

RF24 radio(7, 8);

const byte add[6] = "00001";

struct mydata{
      int x;
      int y;
};

mydata data;

void setup() {
  Serial.begin(9600);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  
  radio.begin();
  radio.openReadingPipe(0, add);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop(){
if(radio.available()){
  while(radio.available()){
   radio.read(&data, sizeof(mydata));

      if(data.x >70 && data.y == 0)
        tien();
    
      if(data.x < -70 && data.y == 0)
        lui();

      if(data.x < 70 && data.x > -70 && data.y == 0)
        dung();

      if(data.y > 70 && data.x == 0)
        trai();
    
      if(data.y < -70 && data.x == 0)
        phai();

      if(data.y < 70 && data.y > -70 && data.x == 0)
        dung();
        


     }
  }
}

void tien(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void lui(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void trai(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void phai(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void dung(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

