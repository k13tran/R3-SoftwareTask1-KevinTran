// C++ Code for the Arduino which outputs the BCD 
// value based on the position of the potentiometer
//
// Kevin Tran

// Pins 2-9 are configured for output
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  delay(10);// Delay a little bit to improve simulation performance
  
  // Maps a value from potentiometer to be outputted to the BCD 
  int sensorValue = analogRead(A0);
  
  // Extract 1st (tempOne) and 2nd (tempTwo) digits which is
  // later modified to extract the binary representation
  int tempOne = sensorValue % 10;
  int tempTwo = (sensorValue % 100) / 10;
  
  // Storage for binary coded decimal value (should be either
  // 1 or 0 in each index)
  int digitOne [4];
  int digitTwo [4];
  
  // Convert each digit into BCD
  for(int i = 0; i <= 3; i++) {
    digitOne[i] = tempOne % 2;
    digitTwo[i] = tempTwo % 2;
    
    tempOne /= 2;
    tempTwo /= 2;
  }
  
  // Reference pin to output to the decoder which starts at pin 5
  // for the first digit and simply added by 4 to get pin 9 for
  // the second digit
  int refPin = 5;
  
  // Output to the decoder is determined by the BCD value stored
  // in digitOne and digitTwo, where the 1s and 0s contained in
  // these arrays are mapped to each pin
  for(int i = 3; i >= 0; i--) {
    
    // below if statements to check if 1 or 0 at the select index
    // is to be sent to the decoder
    if(digitOne[i] > 0) {
      digitalWrite(refPin, HIGH);
    } else {
      digitalWrite(refPin, LOW);
    }
    
    if(digitTwo[i] > 0) {
      digitalWrite(refPin + 4, HIGH);
    } else {
      digitalWrite(refPin + 4, LOW);
    }
    
    // decrement the reference pin and move on to the next 2 pins
    // to be mapped
    refPin--;
  }
}