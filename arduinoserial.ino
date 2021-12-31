void setup() {

  pinMode(2, OUTPUT);   //set pin as output , blue led
  pinMode(3, OUTPUT);   //set pin as output , red led
  pinMode(4, OUTPUT);   //set pin as output , yellow led

  Serial.begin(9600);    //start serial communication @9600 bps
  }

void loop(){
  
  if(Serial.available()){  //id data is available to read

    char val = Serial.read();
    analogWrite(4,val);
//
//    if(val == 'r'){       //if r received
//      digitalWrite(2, HIGH); //turn on red led
//      }
//    if(val == 'b'){       //if b received
//      digitalWrite(3, HIGH); //turn on blue led
//      }
//    if(val == 'y'){       //if y received
//      digitalWrite(4, HIGH); //turn on yellow led
//      }
//    if(val == 'f'){       //if f received
//      digitalWrite(2, LOW); //turn off all led
//      digitalWrite(3, LOW);
//      digitalWrite(4, LOW);
//      }      
    }
  }
