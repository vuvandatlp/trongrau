#define xilanh1 2
#define xilanh2 3
#define cambien1 0
#define cambien2 12
void setup() {
  // put your setup code here, to run once:
  pinMode(cambien1,INPUT);
pinMode(cambien2,INPUT);
pinMode(xilanh1,OUTPUT);
pinMode(xilanh2,OUTPUT);
}

void loop() {
int cambienhn2;
int cambienhn1;
cambienhn1= digitalRead(cambien1);
cambienhn2= digitalRead(cambien2);
  // put your main code here, to run repeatedly:
if(cambienhn1==LOW)
{

 digitalWrite(xilanh1,HIGH);
}
else
{
  digitalWrite(xilanh1,LOW);
  }
if(cambienhn2==LOW)
{

 digitalWrite(xilanh2,HIGH);
}
else
{
  digitalWrite(xilanh2,LOW);
  }
}
