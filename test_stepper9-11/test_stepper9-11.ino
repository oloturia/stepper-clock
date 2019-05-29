int pins[] = {8,9,10,11};


void setup() {
  for(int i=0; i<4; i++) {
    pinMode(pins[i],OUTPUT);
  }
  while(!Serial){};
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0){
    int movement = Serial.parseInt();
    if (movement >0){
      forward(movement);
    } else {
      back(movement *-1);
    }
  }
}

void back(int times) {
  for(int x=0; x<=times; x++){
    for(int i=0; i<4; i++) {
    digitalWrite(pins[i],HIGH); // 0
    delay(2);
    if(i==3){
      digitalWrite(pins[0],HIGH); // 1
    } else {
      digitalWrite(pins[i+1],HIGH);
    }
    delay(2);
    digitalWrite(pins[i],LOW); // -0
    delay(2);
    }
  }
}


void forward(int times) {
  for(int x=0; x<=times; x++){
    for(int i=3; i>=0; i--) {
    digitalWrite(pins[i],HIGH); // 0

    delay(2);
    if(i==0){
      digitalWrite(pins[3],HIGH); // 1          
    } else {
      digitalWrite(pins[i-1],HIGH);
    }
    delay(2);
    digitalWrite(pins[i],LOW); // -0
    delay(2);
    }
  }
}
