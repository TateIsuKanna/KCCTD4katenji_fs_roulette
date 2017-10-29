const int ACCELEROMETER_PORT = 8;
const int SPEAKER_PORT = 9;
const int PUMP_PORT = 10;
const int RESTART_PORT = 11;
const int LED = 49; // 9pin use

int current_LED_position;

unsigned long time_m = 0;
unsigned long time_n = 0;
unsigned long time_nagasa = 0;
unsigned long EASY = 5000;
unsigned long NOMAL = 10000;

//20と22は何が違うの?

void setup(){
	for(int i=20;i<=LED;i++){
		pinMode(i,OUTPUT);
	}

	//music(start,pump);
	pinMode(0,INPUT);
	pinMode(1,INPUT);

	for(int i=2;i<5;i++){
		pinMode(i,INPUT);
	}

	pinMode(ACCELEROMETER_PORT, INPUT);
	pinMode(SPEAKER_PORT, OUTPUT);
	pinMode(PUMP_PORT,INPUT);
	pinMode(RESTART_PORT,INPUT);
}

//難易度設定

void judge(int difficulty){
	for(long t=0;t<6000/pow(2,difficulty);t++){
		if((digitalRead(ACCELEROMETER_PORT)==HIGH&&digitalRead(48)==HIGH)||(digitalRead(ACCELEROMETER_PORT)==HIGH&&digitalRead(47)==HIGH)){
			while(true){
				for(int j=20;j<=LED;j++)digitalWrite(j,HIGH);
				delay(100);
				for(int j=20;j<=LED;j++)digitalWrite(j,LOW);
				delay(100);
			}
		}else if(digitalRead(ACCELEROMETER_PORT)==HIGH){
			while(true){
				digitalWrite(current_LED_position,HIGH);
				delay(100);
				digitalWrite(current_LED_position,LOW);
				delay(100);
			}                        
		}
	}        
}


void loop(){  
	//pump music
	digitalWrite(0,HIGH);
	digitalWrite(0,LOW);
	//start music
	digitalWrite(1,HIGH);
	delay(100);
	digitalWrite(1,LOW);
	delay(100);

	for(int i=25;i>22;i--){
		tone( SPEAKER_PORT, 622);
		digitalWrite(i,HIGH);
		delay(1000);
		noTone(SPEAKER_PORT);
		digitalWrite(i,LOW);
		delay(1000);
	}

	int difficulty=0;//DEBUG
	for(current_LED_position=22;current_LED_position<=LED;current_LED_position++){
		digitalWrite(current_LED_position,HIGH);
		tone( SPEAKER_PORT, 622);
		judge(difficulty);
		digitalWrite(current_LED_position,LOW);
		noTone(SPEAKER_PORT);
		judge(difficulty);
	}

	while(digitalRead(RESTART_PORT)==LOW){
		digitalWrite(LED,HIGH);
		delay(100);
		digitalWrite(LED,LOW);
		delay(100);
	}
}

