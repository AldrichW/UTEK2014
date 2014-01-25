void Rotate90(int clockwise)
{
		// if clockwise = 1, go clockwise, if -1, ccw

		motor[motorB] = 0;
		motor[motorC] = clockwise * -50;
		wait1Msec(1000);
}


void OrbitPlanet(int planetCode){

	if (planetCode == 13){
		// Rotate 90 degrees, then start sweeping the sonar sensor

		Rotate90(1);

		setMotor(0);

		// Rotate in the other direction
		motor[motorB] = 50;
		motor[motorC] = 0;

		while(SensorValue[sonarSensor] > 60){
				// Keep rotating
		}
		setMotor(0);
		// Now pointing right at the planet, approach the planet
		while(SensorValue[sonarSensor] > 20){
			setMotor(100);
		}
		setMotor(0);

		// I am now 20cm away from the planet, orbit the planet
		// Rotate 90 degrees and do the square orbit

		Rotate90(1);
		// Go half distance
		Rotate90(-1);
		// Go full distance
		Rotate90(-1);
		// Go full distance

		Rotate90(-1);
		// Go full distance


		Rotate90(-1);
	}


}
