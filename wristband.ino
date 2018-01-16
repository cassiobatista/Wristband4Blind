/*
 * Wristband4blind
 *
 * Author: Jan 2018
 * Cassio Trindadade Batista - cassio.batista.13@gmail.com
 * 
 * References:
 * http://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/
 */

/* define pins numbers */
#define trigPin 9
#define echoPin 8
#define vibrPin A0

/* define variables */
int distance;

void setup() 
{
	pinMode(echoPin, INPUT);  // sets sonar's echo pin as input
	pinMode(trigPin, OUTPUT); // sets sonar's trigger pin as output
	pinMode(vibrPin, OUTPUT); // set vibration motor pin as output (optional)

	Serial.begin(9600);       // define baud rate for serial communication
}

void loop() 
{
	/* flush the trigger pin: ensure it's LOW */
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);

	/* set trigger pin on HIGH state for 10 us */
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);

	/* Reads the echo pin, returns the sound wave travel time in us */
	distance = pulseIn(echoPin, HIGH)*0.034/2;

	if(distance <= 10) {
		/* turn motor on */
		analogWrite(vibrPin, 168); // 168.30=3V3, as 255 is 5V
	} else {
		/* turn motor off */
		analogWrite(vibrPin, 0);  
	}

	Serial.print("Distance: ");
	Serial.println(distance);
}

/* EOF */
