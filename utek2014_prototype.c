/*
UTEK 2014 - Senior Design - Traversing the planets
	Have our robot read binary encoding on the ground to decided which planet
	to travel to.
	Robot must go through an asteroid belt (oscillating back and forth 180 degrees)
	Robot must go to corresponding planet and orbit once.
*/

/* Part 0*/

#pragma config(Sensor, S3, lightSensor, sensorLightActive)

void MoveForward (){
	while (sensorRawValue[Light1] > BLACKCOLOR){
		motor[motorB] = 50;
		motor[motorC] = 50;
	}
	//found BLACK
	motor[motorB] = 0;
	motor[motorC] = 0;
	wait1Msec(1000);
}

/*Part 1*/
int ReadEncoding (){
	int encodingArr[4];
	int encodedValue = 0;
	int i =0;

	while (i<4){
	   if (sensorValue[lightSensor]<=BLACKCOLOR){
	   		encodingArr[i] = 1;
	   }
	   else{
	     	encodingArr[i] = 0;
	   }
	   /* calibrate to 7 cm*/
	   motor[motorB] = 50;
	   motor[motorC] = 50;
	   wait1Msec(1000);
	   i++;
  }

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


task main()
{
	int encodedValue;

	MoveForward();
	encodedValue = ReadEncoding();

}
