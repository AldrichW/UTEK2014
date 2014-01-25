#pragma config(Sensor, S4,     sonarSensor,         sensorSONAR)

void setMotor(short value){
	motor[motorB] = -value;
	motor[motorC] = -value -1;

}


void Rotate90(int value){

		motor[motorB] = 50;
		motor[motorC] = -50;
		wait1Msec(425);
		setMotor(0);
}

task main()
{
		// Rotate 90 degrees, then start sweeping the sonar sensor
	  int clockwise = 1;
		Rotate90(1 * clockwise);
		setMotor(0);

		// Rotate in the other direction on spot
		motor[motorB] = -20 * clockwise;
		motor[motorC] = 20 * clockwise;

		while(SensorValue[sonarSensor] > 60){
				// Keep rotating
		}
		setMotor(0);
		// Now pointing right at the planet, approach the planet
		while(SensorValue[sonarSensor] > 15){
			setMotor(50);
		}
		setMotor(0);


}
