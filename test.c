//const tSensors sonarSensor = (tSensors) S1;


task main(){

		//while(1){

				//going forward at full capacity
				/*
				motor[motorB] = 100;
				motor[motorC] = 100;
				wait1Msec(2000);
				*/

				//Turning on the spot with 1 second duration
				motor[motorB] = -50;
				motor[motorC] = -50;
				wait1Msec(225);

				/*
				nxtDisplayTextLine(2, "%d", SensorValue(S1));
				while(SensorValue(sonarSensor)> 1000){
				*/

						//writeDebugStream("Sonar value: %d \n", SensorValue(sonarSensor));
						motor[motorB] = 0;
						motor[motorC] = 0;
						wait1Msec(1000);

				//}

	  //}

		//Turning on the spot with 2 second duration
		/*

		motor[motorB] = 50;
		motor[motorC] = -50;
		wait1Msec(2000);

        	motor[motorB] = 50;
		motor[motorC] = -50;
		wait1Msec(3000);

		//turning using different values.

		motor[motorB] = 25;
		motor[motorC] = 80;
		wait1Msec(2000);

		*/

}
