// C++ code
//
  int Sensor_1 = A0;
  int Motor_1_A = 8;
  int Motor_1_B = 9;

void setup()
{
 	pinMode(Motor_1_A, OUTPUT);
  	pinMode(Motor_1_B, OUTPUT);
  	Serial.begin(9600);
}

void loop()
{
	float sensor_val = analogRead(Sensor_1);
  	int sensor_map_val = map(sensor_val, 0, 539, 1, 10);
  
  	if(sensor_map_val > 5){
      
      digitalWrite(Motor_1_A, 1);
      digitalWrite(Motor_1_B,0);
      Serial.print("Backward ----- ");
      
    }else{
      digitalWrite(Motor_1_A, 1);
      digitalWrite(Motor_1_B,0);
      Serial.print("Forward ----- " );
    }
  
  Serial.print(sensor_val);
  Serial.print(" -----> ");
  Serial.println(sensor_map_val);
      
    
}