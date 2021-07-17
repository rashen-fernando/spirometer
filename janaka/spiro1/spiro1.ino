int led=A0;
 int x_max=1023;
  int x_min=0;
  int n=8;
  int q=(x_max-x_min)/(2^n);
   int prev_ek=0;
  
void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
 

  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int state=analogRead(led);
  int f=q*floor((state/q)+0.5);
  int ek=random(0,1);
  int y=f+(ek-prev_ek);
  int prev_ek=ek;
  Serial.println(state);
  Serial.print(" ");
  Serial.println(y);
  
  
  
  
 
 
  
  
  

}
