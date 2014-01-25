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
		motor[motorB] = 20;
		motor[motorC] = -20;

		while(SensorValue[sonarSensor] > 60){
				// Keep rotating
		}
		setMotor(0);
		// Now pointing right at the planet, approach the planet
		while(SensorValue[sonarSensor] > 20){
			setMotor(50);
		}
		setMotor(0);

		// I am now 20cm away from the planet, orbit the planet
		// Rotate 90 degrees and do the square orbit

		Rotate90(1);
		// Go half distance
		setMotor(50); // 50 is 22cm/s, square each side should be 50 cm
		wait1Msec(100);
		setMotor(0);
		int i = 0;
		for( i = 0; i < 5; i ++){
			Rotate90(-1);
			// Go full distance
			setMotor(50); // 50 is 22cm/s, square each side should be 50 cm
			wait1Msec(200);
			setMotor(0);
		}
	}
	else if (planetCode==9){
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

		// I am now 20cm away from the planet, orbit the planet
		// Rotate 90 degrees and do the square orbit

		Rotate90(-1);
		// Go half distance
		setMotor(50); // 50 is 22cm/s, square each side should be 50 cm
		wait1Msec(100);
		setMotor(0);
		int i = 0;
		for( i = 0; i < 5; i ++){
			Rotate90(1);
			// Go full distance
			setMotor(50); // 50 is 22cm/s, square each side should be 50 cm
			wait1Msec(200);
			setMotor(0);
		}
	}


}
