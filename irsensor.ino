


void Read(void)
{ 
  unsigned long starttime=millis();
  digitalWrite(6,LOW);
  delayMicroseconds(2);
  digitalWrite(6,HIGH);
  delayMicroseconds(10);
  digitalWrite(6,LOW);


  float value = pulseIn(5,HIGH);
  float distance = (value*0.0343)/2;



  if(distance<10.00)
  {
    analogWrite(9,0);
    analogWrite(10,0);
  }
  else
  {
    
    analogWrite(9,200);
    analogWrite(10,200);

  }
  
}

