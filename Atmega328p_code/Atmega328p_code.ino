#define EN    A2
#define DIR   2

#define HIN   5
#define LIN   6

void setup()
{
  pinMode(EN,   INPUT);
  pinMode(DIR,  INPUT_PULLUP);

  pinMode(HIN,  OUTPUT);
  pinMode(LIN,  OUTPUT);
}

void loop()
{
  static bool dirState = HIGH;

  if(digitalRead(DIR) == HIGH)                             //assume its CW direction
  {
    if(dirState == LOW)
    {
      digitalWrite(LIN, LOW);
      digitalWrite(HIN, LOW);
      delay(300);
    }
    int analogValue = analogRead(EN);                     // Read analog value (0-1023)
    int pwmValue = map(analogValue, 0, 1023, 0, 255);     // Map the analog value (0-1023) to PWM value (0-255)

    digitalWrite(LIN, LOW);
    if(pwmValue >= 254)     analogWrite(HIN, 254);
    else                    analogWrite(HIN, pwmValue);
    
    dirState    = HIGH; //changing the state variable.
  }
  else if(digitalRead(DIR) == LOW)                       //assume its CCW direction
  {
    
    if(dirState == HIGH)
    {
      digitalWrite(LIN, LOW);
      digitalWrite(HIN, LOW);
      delay(300);
    }

    int analogValue = analogRead(EN);                     // Read analog value (0-1023)
    int pwmValue = map(analogValue, 0, 1023, 0, 255);     // Map the analog value (0-1023) to PWM value (0-255)

    digitalWrite(HIN, LOW);
    if(pwmValue >= 254)     analogWrite(LIN, 254);
    else                    analogWrite(LIN, pwmValue);
    
    dirState    = LOW; //changing the state variable.
  }
  else
  {
    //there are only two state for these condition, so nothing to be done here.
  }
}
