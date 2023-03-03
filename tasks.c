// Do pin/variable definitions and set up as later commit

void Task1(){ // basic pulse sequence
  digitalWrite(T1_OUT, HIGH);
  delay(0.2);
  digitalWrite(T1_OUT, LOW);
  delay(0.05);
  digitalWrite(T1_OUT, HIGH);
  delay(0.03);
  digitalWrite(T1_OUT, LOW);
}

void Task2(){ // measuring frequency in Hz of square wave
  High_Signal = pulseIn(T2_IN, HIGH);
  Low_Signal = pulseIn(T2_IN, LOW);
  Frequency_1 = 1000000/(High_Signal + Low_Signal);
}

void Task3(){ // measuring frequency in Hz of square wave
  High_Signal = pulseIn(T3_IN, HIGH);
  Low_Signal = pulseIn(T3_IN, LOW);
  Frequency_1 = 1000000/(High_Signal + Low_Signal);
}

void Task4() {
  if(counter == 3){ // reset counter after 4th reading
    counter = 0;
}

a[counter] = analogRead(T3_IN); // read analog signal
  
average = (a[0]+a[1]+a[2]+a[3])/4; // average
  
  if (average>2047){
    digitalWrite(T4_OUT, HIGH);
  }
}

void Task5(){ // normalise frequency range to 333-1000Hz

  if(Frequency_1 > 1000){
    Frequency_1 = 1000;
  }
  else if(Frequency_2 > 1000){
    Frequency_2 = 1000;
  }
  else if(Frequency_1 < 333){
    Frequency_1 = 333;
  }
  else if(Frequency_2 < 333){
    Frequency_2 = 333; 
  }
  
  Frequency_1 = Frequency_1/333*33; // normalise to 0-99Hz
  Frequency_2 = Frequency_2/333*33;
  
  Serial.printf("%d, %d \n", Frequency_1, Frequency_2); // print T2 and 3 
}





