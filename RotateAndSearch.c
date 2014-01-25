void setMotor(short value){
	motor[motorB] = -value;
	motor[motorC] = -value;

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

		Rotate90(-1);
		setMotor(0);

		// Rotate in the other direction on spot
		motor[motorB] = -20;
		motor[motorC] = 20;

		while(SensorValue[sonarSensor] > 60){
				// Keep rotating
		}
		setMotor(0);
		// Now pointing right at the planet, approach the planet
		while(SensorValue[sonarSensor] > 20){
			setMotor(50);
		}
		setMotor(0);


}
