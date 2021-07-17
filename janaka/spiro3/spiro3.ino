int led=A0;
int x_max=1023;
int x_min=0;
int n=8;
int q=(x_max-x_min)/(2^n);
int prev_ek=0;
float erM=.01;
float erE=100;
float PreEs=0;

void setup() {
  // put your setup code here, to run once:
 

  Serial.begin(9600);
 


  
}

void loop() {
  // put your main code here, to run repeatedly:
 
  float state=analogRead(led);

  //quantizing,noise shaping
  float f=q*floor((state/q)+0.5);
  float ek=random(x_min,x_max);
  float y=f+(ek-prev_ek);
  prev_ek=ek;
  //Serial.println(state);
  //Serial.print(" ");
  //Serial.println(f);

  //kalman
  float kalman_gain=erE/(erM+erE);
  float est=PreEs+kalman_gain*(state-PreEs);
  erE=(1-kalman_gain)*erE;
  PreEs=est;
  Serial.println(est);
     
  
 
}


