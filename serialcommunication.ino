 
int val;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);  
   

  Serial.begin(9600);    

}

void loop(){
  
  if(Serial.available()){  
   
    val = Serial.read();
      analogWrite(3,val);
      analogWrite(5,val);
      analogWrite(6,val);
      analogWrite(9,val);
      analogWrite(10,val);
      analogWrite(11,val);


    if(val == 'f'){
      analogWrite(3,0);
      analogWrite(5,0);
      analogWrite(6,0);
      analogWrite(9,0);
      analogWrite(10,0);
      analogWrite(11,0);
    }
    
  }
  
}
