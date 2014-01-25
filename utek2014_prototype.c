/*
UTEK 2014 - Senior Design - Traversing the planets
	Have our robot read binary encoding on the ground to decided which planet
	to travel to.
	Robot must go through an asteroid belt (oscillating back and forth 180 degrees)
	Robot must go to corresponding planet and orbit once.
*/

/* Part 0*/

#pragma config(Sensor, S3,     lightSensor,         sensorLightActive)
#pragma config(Sensor, S4,     sonarSensor,         sensorSONAR)

void setMotor(value){
	motor[motorB] = -value;
	motor[motorC] = -value;

}

void MoveForward (){

/* Black is less than 25*/
	while (sensorValue[lightSensor] > BLACKCOLOR){
		setMotor(50);
	}
	//found BLACK
	setMotor(0);
	wait1Msec(1000);
}

/*Part 1*/
int ReadEncoding (){
	int encodingArr[4];
	int encodedValue = 0;
	int i =0;

	while (i<4){
		 nxtDisplayCenteredTextLine(2, "%d", SensorValue[lightSensor]);
	   if (sensorValue[lightSensor]<=BLACKCOLOR){
	   		encodingArr[i] = 1;
	   }
	   else{
	     	encodingArr[i] = 0;
	   }
	   /* calibrate to 7 cm*/
	   setMotor(50);
	   wait1Msec(1000);
	   i++;
  }
	setMotor(0);

  i = 0;
  int increment = 8;
  while (i<4){
  	if (encodingArr[i])
  			encodedValue+= increment;

  	increment = increment/2;
  	i++;
  }
  return (encodedValue);
}

/*part 2 */

void DodgeAsteroid(){

	while (SensorValue(sonarSensor)>=50){

		setMotor(50);
	}
	while (SensorValue(sonarSensor) >= 25){
	    nxtDisplayCenteredTextLine(2, "%d", SensorValue[sonarSensor]);
			setMotor(25);
  }
  while (SensorValue(sonarSensor) >= 10){
  		nxtDisplayCenteredTextLine(2, "%d", SensorValue[sonarSensor]);
			setMotor(10);
  }
	setMotor(0);

 	int oldValue = 0;
 	int newValue = 0;

 	// Want newValue to be very big and oldValue to be very small before we go
 	while(newValue - oldValue < 10){

 		oldValue = newValue;
 		newValue = SensorValue(sonarSensor);

	}

	setMotor(100);

 	wait1Msec(1500); // Hardcode time it takes to drive through the obstacle
	setMotor(0);

 	return;
}

task main()
{
	int encodedValue;

	MoveForward();
	encodedValue = ReadEncoding();

}
