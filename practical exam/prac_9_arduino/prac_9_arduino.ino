// include the libary code:
int b1 = 2;
int d1 = 5;

int cnt=0 , cnt2;
int timer=0;

int pos=0;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(b1, INPUT_PULLUP);
pinMode (d1,OUTPUT);
digitalWrite(d1,HIGH);
digitalWrite(d1,LOW);
delay(300);
cnt=0;
}

void loop() {
  // put your main code here, to run repeatedly:
 if(digitalRead(b1)== HIGH){
  Serial.println("Someone is calling! VIBRATION ALERT");

 digitalWrite(d1,HIGH);
 delay(300);
 digitalWrite(d1,HIGH);
 delay(300);
 
  digitalWrite(d1,HIGH);
  delay(300);
  digitalWrite(d1,HIGH);
  delay(300);

  digitalWrite(d1,HIGH);
  delay(300);
  digitalWrite(d1,HIGH);
  delay(300);
  }
}
