//Simone Cimolato, 13/05/2016

unsigned long tempo = 0, intervallo = 500;  //ms

const int ledV=9;
const int ledR=10;
const int ledB=11;

const int sensR=A0;
const int sensV=A1;
const int sensB=A2;

int RS=0;
int VS=0;
int BS=0;

int R=0;
int V=0;
int B=0;

int subtot= B+V+R;

void setup() {
	Serial.begin(9600);
	pinMode(ledV, OUTPUT);
	pinMode(ledR, OUTPUT);
	pinMode(ledB, OUTPUT);
}

void loop() {

	R = RS/4;
	V = VS/4;
	B = BS/4;

	if(millis() - tempo> intervallo) {
       tempo = millis();
		Serial.print("R: ");
		Serial.print(R);
		Serial.print("         G: ");
		Serial.print(V);
		Serial.print("         B: ");
		Serial.println(B);
 }

	//sensor value
	RS = analogRead(sensR);
	delay(5);
	VS = analogRead(sensV);
	delay(5);
	BS = analogRead(sensB);
	delay(5);

	analogWrite(ledR, R*4);
	analogWrite(ledV, V*4);
	analogWrite(ledB, B*4);
}