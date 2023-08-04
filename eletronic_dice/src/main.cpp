#include <Arduino.h>

int seg[] = {3, 4, 5, 6, 7, 8, 9}; //a, b, c, d, e, f, g
bool conf[][11] = {{0,0,0,0,0,0,0},
                    {1,1,1,1,1,1,0},//0
                    {0,1,1,0,0,0,0},//1
                    {1,1,0,1,1,0,1},//2
                    {1,1,1,1,0,0,1},//3
                    {0,1,1,0,0,1,1},//4
                    {1,0,1,1,0,1,1},//5
                    {1,0,1,1,1,1,1},//6
                    {1,1,1,0,0,0,0},//7
                    {1,1,1,1,1,1,1},//8
                    {1,1,1,0,0,1,1}};//9
int dp    = 12;
int bot   = 2;
bool most = false;

void sorteio(){
	int num = random(6);
  for(int j = 0; j < 7; j++)
    digitalWrite(seg[j],conf[num+2][j]);
  most = true; 
}

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < 7;i++){
    pinMode(seg[i], OUTPUT);
  }
  pinMode(dp, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(bot), sorteio, FALLING);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(dp, !digitalRead(dp));
  delay(500);
  if (most){
    delay(1500);
    most = false;
  }
  else{
    for(int i = 0; i < 7; i++)
      digitalWrite(seg[i],conf[0][i]);
  }
}