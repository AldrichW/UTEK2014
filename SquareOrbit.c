void setMotor(short value){
	motor[motorB] = -value;
	motor[motorC] = -value-1;

}


void Rotate90(int value){

		motor[motorB] = 50;
		motor[motorC] = -50-1;
		wait1Msec(425);
		setMotor(0);
		wait1Msec(100);
}

task main()
{
	  int clockwise = 1;

		Rotate90(-1 * clockwise);
		// Go half distance
		setMotor(50); // 50 is 22cm/s, square each side should be 50 cm
		wait1Msec(100);
		setMotor(0);
			int i = 0;
		for( i = 0; i < 5; i ++){
			Rotate90(1 * clockwise);
			// Go full distance
			setMotor(50); // 50 is 22cm/s, square each side should be 50 cm
			wait1Msec(2000);
			setMotor(0);
			wait1Msec(500);
		}
}
