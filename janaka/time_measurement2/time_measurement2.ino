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
int timme=0;
int const time_index=5;
float t[time_index]={0};
int g=0;
float avg_time=0;

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

//lowpass(3.78 is the mean offset,for time easurement)
lowpass=lowconst*state+(1-lowconst)*lowpass;

if (lowpass>10)
{
  timme++;
}
else
{
  if(g<time_index)
  {
    t[g]=timme;
    g++;
  }
  else
  {
    for(int j=0;j<g;j++)
    {
      avg_time=avg_time+t[j];
    }
    Serial.println(g);
    g=0;
  }
 timme=0;
}
//Serial.println(lowpass); Serial.print(1); Serial.print("  ");
//Serial.println(timme); Serial.print(2); Serial.print("  ");   

  



//averaging(for max val determination)
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


