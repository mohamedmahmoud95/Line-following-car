/* 
 *  Line following robot code
 *  made by: EngStein
 *  www.fb.com/engStein1
 */
//declaration of motors


int right_motor_speed = 3;
int right_motor_backward =4;
int right_motor_forward = 5;

int left_motor_speed = 6;
int left_motor_backward =7;
int left_motor_forward = 9;

int Speed = 75 ;         //car speed 
int low_speed = Speed/2;     //(for rotaions)

//declaration of sensors

int r_sensor = 12;
int m_sensor = 11; //middle sensor
int l_sensor = 10;

// Voids:

void forward()
{
  //move both motors FORWARD
        analogWrite (right_motor_speed,  Speed);
        digitalWrite(right_motor_forward, HIGH);
        digitalWrite(right_motor_backward, LOW);
               
        analogWrite (left_motor_speed,   Speed);
        digitalWrite(left_motor_forward,  HIGH);        
        digitalWrite(left_motor_backward,  LOW);
}
/*
void backward()
{
  //move both motors BACKWARD
        analogWrite (right_motor_speed,  Speed);
        digitalWrite(right_motor_forward,  LOW);
        digitalWrite(right_motor_backward,HIGH);
               
        analogWrite (left_motor_speed,   Speed);
        digitalWrite(left_motor_forward,   LOW);        
        digitalWrite(left_motor_backward, HIGH);
}
*/
void right()
{
  //move car RIGHT
        analogWrite (right_motor_speed,   0   );
        digitalWrite(right_motor_forward,  LOW);
        digitalWrite(right_motor_backward, LOW);
               
        analogWrite (left_motor_speed,   Speed);
        digitalWrite(left_motor_forward,  HIGH);        
        digitalWrite(left_motor_backward,  LOW);
}

void left ()
{
   //move car LEFT
        analogWrite (right_motor_speed,  Speed);
        digitalWrite(right_motor_forward, HIGH);
        digitalWrite(right_motor_backward, LOW);
               
        analogWrite (left_motor_speed,    0   );
        digitalWrite(left_motor_forward,   LOW);        
        digitalWrite(left_motor_backward,  LOW);
}

void Stop()
{
        analogWrite (right_motor_speed,     0   ); 
        analogWrite(left_motor_speed,     0     );
} 

void setup() {

  Serial.begin(9600);
  
  pinMode(right_motor_speed,    OUTPUT);
  pinMode(right_motor_backward, OUTPUT);
  pinMode(right_motor_forward,  OUTPUT);

  pinMode(left_motor_speed,     OUTPUT);
  pinMode(left_motor_backward,  OUTPUT);
  pinMode(left_motor_forward,   OUTPUT);

  pinMode( r_sensor , INPUT );
  pinMode( m_sensor , INPUT );
  pinMode( l_sensor , INPUT );
  
}

void loop() {

int r_state = digitalRead (r_sensor); // the reading of the right sensor
int m_state = digitalRead (m_sensor);
int l_state = digitalRead (l_sensor);

  if(r_state  == HIGH && m_state == LOW && l_state == HIGH )
  {
    forward();
  }
  
  if( r_state == LOW && m_state == HIGH && l_state == HIGH )
  {
    right();
  }

    if( r_state == HIGH && m_state == HIGH && l_state == LOW )
  {
    left();
  }


}
