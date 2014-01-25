#pragma config(Sensor, S4,     sonarSensor,         sensorSONAR)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*--------------------------------------------------------------------------------------------------------*\
|*                                                                                                        *|
|*                                   - Obstacle Detection with Sonar -                                    *|
|*                                            ROBOTC on NXT                                               *|
|*                                                                                                        *|
|*  This program runs your robot forward until it detects and obstacle, at which point it stops.          *|
|*                                                                                                        *|
|*                                        ROBOT CONFIGURATION                                             *|
|*    NOTES:                                                                                              *|
|*    1)  The Sonar Sensor should be somewhere on the FRONT of the robot, facing FORWARD.                 *|
|*                                                                                                        *|
|*    MOTORS & SENSORS:                                                                                   *|
|*    [I/O Port]              [Name]              [Type]              [Description]                       *|
|*    Port B                  motorB              NXT                 Right motor                         *|
|*    Port C                  motorC              NXT                 Left motor                          *|
|*    Port 4                  sonarSensor         Sonar Sensor        Front mounted, front facing         *|
\*---------------------------------------------------------------------------------------------------4246-*/


task main()
{
  while(1){
		int distance_in_cm = 20;   // Create variable 'distance_in_cm' and initialize it to 20(cm).

		 nxtDisplayTextLine(2, "%d", SensorValue(sonarSensor));

	   while(SensorValue[sonarSensor] > distance_in_cm)   // While the Sonar Sensor readings are less than the specified, 'distance_in_cm':
	   {
	      motor[motorB] = 75;                     // Motor B is run at a 75 power level
	      motor[motorC] = 75;                     // Motor C is run at a 75 power level
	   }
	   motor[motorB] = 0;    // Motor B is stopped at a 0 power level
	   motor[motorC] = 0;    // Motor C is stopped at a 0 power level
  }
}
