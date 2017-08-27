const int MR_CONTROL_PIN_A=2;
const int MR_CONTROL_PIN_B=4;
int PIN_C=A0;
int d;
int check=0;
int check2=1;

void setup()
{ pinMode(PIN_C,INPUT);
  Serial.begin(9600);
  pinMode(MR_CONTROL_PIN_A, OUTPUT);
  pinMode(MR_CONTROL_PIN_B, OUTPUT);
}
void loop()
{
  d = analogRead(PIN_C);
  Serial.println(d);
  delay(200);
  if((d>600) && (check==1))
    {
     // ANTCLW
     digitalWrite(MR_CONTROL_PIN_A,HIGH);
     digitalWrite(MR_CONTROL_PIN_B,LOW);
     delay(18000);
     digitalWrite(MR_CONTROL_PIN_A,LOW);
     digitalWrite(MR_CONTROL_PIN_B,LOW);
     check2=1;
     check=0;
    }
      
 else if(d<600 && check2==1 && d!=0)
  {  
      //CLW
  
     digitalWrite(MR_CONTROL_PIN_A,LOW);
     digitalWrite(MR_CONTROL_PIN_B,HIGH);
     check=1;
     
     delay(16500);
     digitalWrite(MR_CONTROL_PIN_A,LOW);
     digitalWrite(MR_CONTROL_PIN_B,LOW);
     check2=0;
   }
}
     


  



