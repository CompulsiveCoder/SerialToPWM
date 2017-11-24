int outputPin = 9;

unsigned int integerValue=0;
char incomingByte;
 
void setup() {
  Serial.begin(9600);

  // declare pin 9 to be an output:
  pinMode(outputPin, OUTPUT);
}

void loop() {
  readSerialNumber();

  delay(1);
}

int readSerialNumber()
{
  if (Serial.available() > 0) {   // something came across serial
    integerValue = 0;         // throw away previous integerValue
    while(1) {            // force into a loop until 'n' is received
      incomingByte = Serial.read();
      if (incomingByte == '\n') break;   // exit the while(1), we're done receiving
      if (incomingByte == -1) continue;  // if no characters are in the buffer read() returns -1
      integerValue *= 10;  // shift left 1 decimal place
      // convert ASCII to integer, add, and shift left 1 decimal place
      integerValue = ((incomingByte - 48) + integerValue);
    }
    Serial.println(integerValue);   // Do something with the value
    setPwmValue(integerValue);
  }
}

void setPwmValue(int value)
{
  if (value < 0)
    Serial.println("Value too low");
  else if (value > 255)
    Serial.println("Value too high");
  else
  {
    Serial.print("Setting to: ");
    Serial.println(value);
    analogWrite(outputPin, value);
  }
}
