#define BOTTON 8
#define SPEAKER 9
#define PUMP 10
#define RESTART 11


const int LED = 49; // 9pin use
      int i = 0;
      int j = 0;
      long t = 0; 
      int judge;
      unsigned long time_m = 0;
      unsigned long time_n = 0;
      unsigned long time_nagasa = 0;
      unsigned long EASY = 5000;
      unsigned long NOMAL = 10000;
 
void setup(){
  for(i=20;i<=LED;i++){
    pinMode(i,OUTPUT);
  }

//music(start,pump);
  pinMode(0,INPUT);
  pinMode(1,INPUT);

  for(i=2;i<5;i++){
    pinMode(i,INPUT);
  }
  
  //加速度センサ
  pinMode(BOTTON, INPUT);
  //speaker
  pinMode(SPEAKER, OUTPUT);
  //pump
  pinMode(PUMP,INPUT);
  //restart
  pinMode(RESTART,INPUT);
}

//難易度設定


void loop(){  

//puｍｐ music
  digitalWrite(0,HIGH);

  digitalWrite(0,LOW);
//start music
  digitalWrite(1,HIGH);
  delay(100);
  digitalWrite(1,LOW);
  delay(100);

  for(i=25;i>22;i--){
    tone( SPEAKER, 622);
    digitalWrite(i,HIGH);
    delay(1000);
    noTone(SPEAKER);
    digitalWrite(i,LOW);
    delay(1000);
  }

  judge=1;
  
  switch(judge){
  //easys
    case 1:  
    for(i=22;i<=LED;i++){
        digitalWrite(i,HIGH);
        tone( SPEAKER, 622);
                  
        for(t=0;t<5000;t++){
          if((digitalRead(BOTTON)==HIGH&&digitalRead(48)==HIGH)||(digitalRead(BOTTON)==HIGH&&digitalRead(47)==HIGH)){
            while(1){
              for(j=20;j<=LED;j++)digitalWrite(j,HIGH);
              delay(100);
              for(j=20;j<=LED;j++)digitalWrite(j,LOW);
              delay(100);
            }
           }else if(digitalRead(BOTTON)==HIGH){
            while(1){
              digitalWrite(i,HIGH);
              delay(100);
              digitalWrite(i,LOW);
              delay(100);
            }                        
           }
        }        
        
        
        digitalWrite(i,LOW);
        noTone(SPEAKER);
        
        for(t=0;t<6000;t++){
          if((digitalRead(BOTTON)==HIGH&&digitalRead(48)==HIGH)||(digitalRead(BOTTON)==HIGH&&digitalRead(47)==HIGH)){
               while(1){
                for(j=20;j<=LED;j++)digitalWrite(j,HIGH);
                delay(100);
                for(j=20;j<=LED;j++)digitalWrite(j,LOW);
                delay(100);
               }
          }else if(digitalRead(BOTTON)==HIGH){
            while(1){
              digitalWrite(i,HIGH);
              delay(100);
              digitalWrite(i,LOW);
              delay(100);
            }                        
           }
        }            
    break;
    }
  
  //nomal
    case 2:  
    for(i=22;i<=LED;i++){
        digitalWrite(i,HIGH);
        tone( SPEAKER, 622);
                  
        for(t=0;t<3000;t++){
          if((digitalRead(BOTTON)==HIGH&&digitalRead(48)==HIGH)||(digitalRead(BOTTON)==HIGH&&digitalRead(47)==HIGH)){
            while(1){
              for(j=20;j<=LED;j++)digitalWrite(j,HIGH);
              delay(100);
              for(j=20;j<=LED;j++)digitalWrite(j,LOW);
              delay(100);
            }
           }else if(digitalRead(BOTTON)==HIGH){
            while(1){
              digitalWrite(i,HIGH);
              delay(100);
              digitalWrite(i,LOW);
              delay(100);
            }                        
           }            
        }        
        
        
        digitalWrite(i,LOW);
        noTone(SPEAKER);
        
        for(t=0;t<3000;t++){
          if((digitalRead(BOTTON)==HIGH&&digitalRead(48)==HIGH)||(digitalRead(BOTTON)==HIGH&&digitalRead(47)==HIGH)){
               while(1){
                for(j=20;j<=LED;j++)digitalWrite(j,HIGH);
                delay(100);
                for(j=20;j<=LED;j++)digitalWrite(j,LOW);
                delay(100);
               }
          }else if(digitalRead(BOTTON)==HIGH){
            while(1){
              digitalWrite(i,HIGH);
              delay(100);
              digitalWrite(i,LOW);
              delay(100);
            }                        
           }
        }            
                  
    break;
    }
  
  //hard
    case 3:  
    for(i=22;i<=LED;i++){
        digitalWrite(i,HIGH);
        tone( SPEAKER, 622);
                  
        for(t=0;t<1500;t++){
          if((digitalRead(BOTTON)==HIGH&&digitalRead(48)==HIGH)||(digitalRead(BOTTON)==HIGH&&digitalRead(47)==HIGH)){
            while(1){
              for(j=20;j<=LED;j++)digitalWrite(j,HIGH);
              delay(100);
              for(j=20;j<=LED;j++)digitalWrite(j,LOW);
              delay(100);
            }
           }else if(digitalRead(BOTTON)==HIGH){
            while(1){
              digitalWrite(i,HIGH);
              delay(100);
              digitalWrite(i,LOW);
              delay(100);
            }                        
           }            
        }        
        
        
        digitalWrite(i,LOW);
        noTone(SPEAKER);
        
        for(t=0;t<1500;t++){
          if((digitalRead(BOTTON)==HIGH&&digitalRead(48)==HIGH)||(digitalRead(BOTTON)==HIGH&&digitalRead(47)==HIGH)){
               while(1){
                for(j=20;j<=LED;j++)digitalWrite(j,HIGH);
                delay(100);
                for(j=20;j<=LED;j++)digitalWrite(j,LOW);
                delay(100);
               }
          }else if(digitalRead(BOTTON)==HIGH){
            while(1){
              digitalWrite(i,HIGH);
              delay(100);
              digitalWrite(i,LOW);
              delay(100);
            }                        
           }
        }            
        break;          
    }
    default:
      break;
    }
        
        if(i==49){
          while(digitalRead(RESTART)==LOW){
            digitalWrite(LED,HIGH);
            delay(100);
            digitalWrite(LED,LOW);
            delay(100);
          }
         }
}
   
