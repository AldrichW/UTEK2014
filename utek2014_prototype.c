#pragma config(Sensor, S3,     lightSensor,         sensorLightActive)
#pragma config(Sensor, S4,     sonarSensor,         sensorSONAR)
#define BLACK_COLOUR 38

/*
UTEK 2014 - Senior Design - Traversing the planets
	Have our robot read binary encoding on the ground to decided which planet
	to travel to.
	Robot must go through an asteroid belt (oscillating back and forth 180 degrees)
	Robot must go to corresponding planet and orbit once.
*/

/* Part 0*/


void setMotor(short value){
	motor[motorB] = -value;
	motor[motorC] = -value-1;

}

void MoveForward (){

/* Black is less than 25*/
nxtDisplayCenteredTextLine(2, "%d", SensorValue[lightSensor]);

	while (SensorValue[lightSensor] > BLACK_COLOUR){
		nxtDisplayCenteredTextLine(2, "%d", SensorValue[lightSensor]);
		setMotor(50);
		wait1Msec(50);
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
	   if (SensorValue[lightSensor]<=BLACK_COLOUR){
	   		encodingArr[i] = 1;
	   }
	   else{
	     	encodingArr[i] = 0;
	   }
	   if(i!=3){
	   /* calibrate to 7 cm*/
	  	 setMotor(50);
	   	 wait1Msec(330);
	   }
	   setMotor(0);
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
  nxtDisplayCenteredTextLine(2, "%d", encodedValue);
  return (encodedValue);
}

/*part 2 */

void DodgeAsteroid(){

  while (SensorValue(sonarSensor) >= 10){
  		nxtDisplayCenteredTextLine(2, "%d", SensorValue[sonarSensor]);
			setMotor(10);
			wait1Msec(50);
  }
	setMotor(0);
	wait1Msec(1000);
	int currentDistance = SensorValue(sonarSensor);

 	while(SensorValue(sonarSensor)< 30){
 		nxtDisplayCenteredTextLine(1, "%d", currentDistance);
		nxtDisplayCenteredTextLine(2, "%d", SensorValue[sonarSensor]);
	}
 	// Book it through the asteroid
	setMotor(50);

 	wait1Msec(1000); // Hardcode time it takes to drive through the obstacle
	setMotor(0);

 	return;
}

task main()
{
	int encodedValue;

	MoveForward();
  encodedValue = ReadEncoding();

//  nxtDisplayCenteredTextLine(2, "%d", encodedValue);

//	wait1Msec(1000);
	DodgeAsteroid();

}
