
String inputString = "";      // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

void setup() {
  
  Serial.begin(9600);     // initialize serial:
  pinMode(7,OUTPUT);      //set 7 as output
  pinMode(8,OUTPUT);      //set 8 as output
  inputString.reserve(200);   // reserve 200 bytes for the inputString:
}

void loop() 
{
  if (stringComplete) 
  {
    Serial.print("Data Recieved as string =");
    Serial.println(inputString);    //print the string when a newline arrives
    
    int data;                       //variable data to store value
    data= inputString.toInt();      //converting recieved string to int
    Serial.print("Data Converted to int=");
    Serial.println(data);           //print data
    if(data%2==0)
        {
          digitalWrite(7, HIGH);
          digitalWrite(8, LOW);
        }
    else
        {
          digitalWrite(8, HIGH);
          digitalWrite(7, LOW);
        }
    inputString = "";     // clear the string
    stringComplete = false;  // Reset the flag
  }
}

void serialEvent() 
{
  while (Serial.available()) 
  {
    char inChar = (char)Serial.read();     // get the new byte:
    inputString += inChar;    // add it to the inputString:
                      // if the incoming character is a newline, set a flag so the main loop can perform operation on it
    if (inChar == '\n')
    {
      stringComplete = true;
    }
  }
}
