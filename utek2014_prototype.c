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
void SearchSaturn();

void setMotor(short value){
	motor[motorB] = -value;
	motor[motorC] = -value;

}

void Rotate90(int value){

		motor[motorB] = 50 * value;
		motor[motorC] = -50 * value;
		wait1Msec(425);
		setMotor(0);
}

/* Part 0*/



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
	wait1Msec(100);
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
void SquareOrbit(int clockwise)
{
		Rotate90(-1 * clockwise);
		// Go half distance
		setMotor(50); // 50 is 22cm/s, square each side should be 50 cm
		wait1Msec(1000);
		setMotor(0);
		wait1Msec(200);
			int i = 0;
		for( i = 0; i < 5; i ++){
			Rotate90(1 * clockwise);
			// Go full distance
			setMotor(45); // 50 is 22cm/s, square each side should be 50 cm
			wait1Msec(2000);
			setMotor(0);
			wait1Msec(250);
		}

}

void PlanetSearch(int clockwise)
{
			// Rotate 90 degrees, then start sweeping the sonar sensor

		Rotate90(1 * clockwise);
		setMotor(0);
		wait1Msec(100);
		// Rotate in the other direction on spot
		motor[motorB] = -10 * clockwise;
		motor[motorC] = 10* clockwise;

		while(SensorValue[sonarSensor] > 60){
				// Keep rotating
		}
		setMotor(0);
		// Now pointing right at the planet, approach the planet
		while(SensorValue[sonarSensor] > 15){
			setMotor(50);
		}
		setMotor(0);

}
/* Part 3*/

void OrbitPlanet(int planetValue)
{
	if (planetValue == 13){
		// Find the planet
		PlanetSearch(1);
		wait1Msec(100); //// REMOVE THIS AFTER
		// Do the square orbit
		SquareOrbit(-1);

	}
	else if (planetValue == 9){

		PlanetSearch(-1);
				wait1Msec(100); //// REMOVE THIS AFTER
		SquareOrbit(1);
	}
	else{
		SearchSaturn();
		motor[motorB] = 10;
		motor[motorC] = -10;
		wait1Msec(2000);
			while(SensorValue[sonarSensor] > 60){
				// Keep rotating
		}
		setMotor(0);
		// Now pointing right at the planet, approach the planet
		while(SensorValue[sonarSensor] > 15){
			setMotor(50);
		}
		setMotor(0);
		SquareOrbit(1);
	}

}

void SearchSaturn()
{
		// Rotate 90 degrees, then start sweeping the sonar sensor

		Rotate90(-1);
		setMotor(0);

		// Rotate in the other direction on spot
		motor[motorB] = 20;
		motor[motorC] = -20;

		while(SensorValue[sonarSensor] > 70){
				// Keep rotating
		}
		setMotor(0);

}

task main()
{
	int encodedValue=0;

	MoveForward();
  encodedValue = ReadEncoding();

  nxtDisplayCenteredTextLine(2, "%d", encodedValue);
	wait1Msec(1000);
	DodgeAsteroid();

	OrbitPlanet(encodedValue);

}
