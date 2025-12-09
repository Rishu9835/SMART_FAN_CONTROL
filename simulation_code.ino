
int ldr = 0;     //  LDR reading
int temp = 0;    //  Temperature sensor reading

void setup() {
  pinMode(8, OUTPUT);   // Light control (LED/Relay)
  pinMode(10, OUTPUT);   // Fan control (Motor/Relay)
  Serial.begin(9600); 
}

void loop() {
  ldr = analogRead(A0);     // Read LDR
  temp = analogRead(A1);    // Read temperature sensor

  
  if (ldr > 400) {          // Dark condition
    digitalWrite(8, HIGH);  // Turn light ON
  } else {
    digitalWrite(8, LOW);   // Turn light OFF
  }


  if (temp > 30) {          
    digitalWrite(10, HIGH);  // Turn fan ON
  } else {
    digitalWrite(10, LOW);   // Turn fan OFF
  }


  Serial.print("LDR = ");
  Serial.print(ldr);
  Serial.print("   Temp sensor = ");
  Serial.println(temp);

  delay(500);  
}

