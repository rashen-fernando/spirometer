int led=A0;

//quantize
int x_max=1023;
int x_min=0;
int n=8;
int q=(x_max-x_min)/(2^n);
int prev_ek=0;

//kalmanfilter
float erM=9;
float erE=5;
float PreEs=2;

//lowpass
float lowpass=0;
float lowconst=0.05;

//average
int y=0;
int const no_of_samples=200;
float avg[no_of_samples]={0};
float averaged=0;


void setup() {
  // put your setup code here, to run once:
 

  Serial.begin(9600);
 


  
}

void loop() {
  // put your main code here, to run repeatedly:
 
  float state=analogRead(led);

  //quantizing,noise shaping
//  float f=q*floor((state/q)+0.5);
//  float ek=random(x_min,x_max);
//  float y=f+(ek-prev_ek);
//  prev_ek=ek;
//  Serial.println(state);
//  Serial.print(" ");
//  Serial.println(f);
//
//  //kalman
//  float kalman_gain=erE/(erM+erE);
//  float est=PreEs+kalman_gain*(state-PreEs);
//  erE=(1-kalman_gain)*erE;
//  PreEs=est;
//  Serial.println(est);

//lowpass(3.78 is the mean offset)
lowpass=lowconst*state+(1-lowconst)*lowpass;
if (lowpass>4)
{
  y++;
}
else
{
 y=0;
}
Serial.println(lowpass); 
Serial.print(" ");
Serial.println(y);    
  



//averaging
//if(y<no_of_samples)
//{
//  avg[y]= lowconst*analogRead(led)+(1-lowconst)*avg[y];
//  y++;
//}
//else
//{
//  for(int i=0;i<y;i++)
//  {
//   averaged=averaged+avg[i];
//  }
//  
//  Serial.println(averaged/y);
//  y=0;
//  averaged=0;
//}
 
}


