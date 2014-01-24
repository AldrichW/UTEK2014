
task main(){

		//going forward at full capacity
		motor[motorB] = 100;
		motor[motorC] = 100;
		wait1Msec(2000);

		//Turning on the spot
		motor[motorB] = 50;
		motor[motorC] = -50;
		wait1Msec(1000);

		motor[motorB] = 50;
		motor[motorC] = -50;
		wait1Msec(2000);

	  motor[motorB] = 50;
		motor[motorC] = -50;
		wait1Msec(3000);


}
