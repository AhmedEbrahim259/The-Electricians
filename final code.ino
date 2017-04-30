   
#include <SoftwareSerial.h>     
int bluetoothTx = 15 ;  
int bluetoothRx = 14 ; 
SoftwareSerial app (bluetoothTx, bluetoothRx); 
int T = A0 ;
int S = A1 ;
int W1 = 22 ;
int W2 = 23 ;
int BC = 24 ;
int BW1 = 25 ; 
int BW2 = 26 ;
int BS = 27 ;



void setup() {
    // Begin the serial monitor at 9600bps
 
   app.begin(9600);
  app.print("$");  
  app.print("$");
  app.print("$"); 
  app.println("U,9600,N");  
  app.begin(9600);
   Serial.begin(9600);
  pinMode(T, INPUT );
  pinMode(S, INPUT);
  pinMode(W1, INPUT);
  pinMode(W2, INPUT);
  pinMode(BC, OUTPUT);
  pinMode( BW1, OUTPUT);
  pinMode(BW2, OUTPUT);
  pinMode(BS, OUTPUT);
 
}

void loop() {
float current_temp = analogRead(T);  
int smoke        = analogRead(S);  
current_temp       = (5 * current_temp * 100 )/1024 ;

int first_way = digitalRead (W1);
int second_way = digitalRead ( W2) ;




if ( current_temp > 35 && first_way == HIGH && second_way == LOW   ) {
  
        digitalWrite ( BW1 , HIGH ) ;
        digitalWrite ( BW2 , LOW )  ;
          digitalWrite ( BC , HIGH )  ;
   app.print((int)current_temp ); 
    app.print("|"); 
    
     app.print(1); 
        app.print("|"); 
}
else if ( current_temp > 35 && first_way == LOW && second_way == HIGH  ) { 
   digitalWrite ( BW1 , LOW ) ;
   digitalWrite ( BW2 , HIGH )  ;
    digitalWrite ( BC , HIGH )  ;
  app.print((int)current_temp ); 
    app.print("|"); 
     
     app.print(2); 
        app.print("|");          
}
else if ( current_temp > 35 && second_way == LOW && first_way == LOW  ) {
 
      digitalWrite ( BW1 , LOW )  ;  
        digitalWrite ( BW2 , LOW )  ;
         digitalWrite ( BC , HIGH )  ;
   
  app.print((int)current_temp ); 
    app.print("|"); 
     
     app.print(3); 
        app.print("|"); 
 

}  
else if ( current_temp > 35 && second_way == HIGH && first_way == HIGH  ) {
       
      digitalWrite ( BW1 , HIGH)  ;  
        digitalWrite ( BW2 , HIGH ) ;
         digitalWrite ( BC , HIGH )  ;
       
  app.print((int)current_temp ); 
    app.print("|"); 
    
     app.print(3); 
        app.print("|"); 


}  
//////////////////////////////////////////////////////////////////////////////////////////
else if ( current_temp <= 35 && second_way == HIGH && first_way == LOW  ) {
      
      digitalWrite ( BW1 , LOW )  ;  
        digitalWrite ( BW2 , LOW )  ;
         digitalWrite ( BC , LOW )  ;
         
  app.print((int)current_temp ); 
    app.print("|"); 
    
     app.print(3); 
        app.print("|"); 
 

}  
else if ( current_temp <= 35 && second_way == LOW && first_way == HIGH  ) {
        noTone(24) ;
      digitalWrite ( BW1 , LOW )  ;  
        digitalWrite ( BW2 , LOW )  ;
         digitalWrite ( BC , LOW )  ;
          
  app.print((int)current_temp ); 
   
    app.print("|");
     app.print(3); 
        app.print("|"); 


}  
else if ( current_temp <= 35 && second_way == LOW && first_way == LOW  ) {
           noTone(24) ;
      digitalWrite ( BW1 , LOW )  ;  
        digitalWrite ( BW2 , LOW )  ;
         digitalWrite ( BC , LOW )  ;
         
  app.print((int)current_temp ); 
   
    app.print("|");
     app.print(3); 
        app.print("|"); 


}  
else if ( current_temp <= 35 && second_way == HIGH && first_way == HIGH  ) {
        
         
      digitalWrite ( BW1 , LOW )  ;  
        digitalWrite ( BW2 , LOW )  ;
          digitalWrite ( BC , LOW )  ;
          
  app.print((int)current_temp ); 
    
    app.print("|");
     app.print(3); 
        app.print("|"); 


}  
int i=smoke/5; 
if ( smoke > 300 ) {
  digitalWrite ( BS , HIGH )  ;
  app.print ( i ) ;
 
  
}
if ( smoke <= 300 ) { 
  digitalWrite ( BS , LOW )  ;
  app.print ( i ) ;
  

}
delay (3000) ;  }
















/*#include <SimpleDHT.h>
int pinDHT11 = 2;
SimpleDHT11 dht11;
#define light (A1)
int lvl;
void setup() {
Serial.begin(9600);
}

void loop() {

byte temperature = 0;
byte humidity = 0;
if (dht11.read(pinDHT11, &temperature, &humidity, NULL ))
{
return;
}
lvl = analogRead(light);
Serial.print((int)temperature);
Serial.print(” C”);
Serial.print(“|”);

delay(5000);
}  */
