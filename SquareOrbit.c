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

		int i = 0;
		for( i = 0; i < 5; i ++){
			Rotate90(1);
			// Go full distance
			setMotor(50); // 50 is 22cm/s, square each side should be 50 cm
			wait1Msec(2000);
			setMotor(0);
		}

}
