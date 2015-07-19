
int const DEFAULAT_TIME_OUT_MS = 5000;//5 seconds

//prototype with default arguments
bool liftFunction(int power, int position, int const DEFAULT_TIME_OUT = DEFAULAT_TIME_OUT_MS);
bool drive(int throttle, int steering, int distance, int const DEFAULT_TIME_OUT = DEFAULAT_TIME_OUT_MS);

//timers
//T1 for Drive
//T2 for Lift


/*****************************************/
//function to clear both drive encoders
/*****************************************/
void clearDriveEncoders()
{
	SensorValue(EncoderDriveLeft) = 0;
	SensorValue(EncoderDriveRight) = 0;
}

/*****************************************/
// basic drive for arcade drive
/*****************************************/
void drive(int throttle, int steering)
{
	motor[DriveLeft] = throttle + steering;
	motor[DriveRight] = throttle - steering;

}

/*****************************************/
// basic drive function for mecanum wheels
/*****************************************/
/*
void drive(int throttle, int steering,int strafe)
{
	motor[DriveFrontRight] = throttle - steering - strafe;
	motor[DriveBackRight] = throttle - steering + strafe;
	motor[DriveFrontLeft] = throttle + steering + strafe;
	motor[DriveBackLeft] = throttle + steering - strafe;
}
*/

/*****************************************/
//function to drive distance
//check if timed out
//returns true if success
//false if failure
/*****************************************/
bool drive(int throttle, int steering, int distance, int const DEFAULT_TIME_OUT)
{
	ClearTimer(T1);//clear timer to keep track of time to reach distance
	clearDriveEncoders();//clear both encoders
	while(abs(SensorValue(EncoderDriveLeft)) < distance && abs(SensorValue(EncoderDriveRight)) < distance)//make sure both sides have reach the proper distance
	{
		drive(throttle, steering);
		if(time1[T1] > DEFAULT_TIME_OUT)//check if robot has take too long to reach distance
		{
			drive(0,0);//stop drive
			return false;//destiantion failed timed out return false
		}
	}

	drive(0,0);//stop drive
	return true;//distance success return true
}

/*****************************************/
//Simple team selection function
//used with pot
/*****************************************/
int teamSelectionFunction()//function to show how to use pot for team selection
{
 	if(SensorValue(teamSelection) >= 2014)//blue
	{
		//blueVersion1();
		//or you can return a value 1
	}
	else//red
	{
		//redVersion1();
	//or you can return a value 2 and so on
	}

	return 0;
}

/*****************************************/
//primitive function to just
//change power of lift motors
/*****************************************/
void liftFunction(int power)
{
	motor[Lift] = power;
}


/*****************************************/
//function to change lift position by
//pot position and check for time out
/*****************************************/
bool liftFunction(int power, int position, int const DEFAULT_TIME_OUT)
{
	ClearTimer(T2);//clear T2 timer

	if(SensorValue(PotLift) < position)//check if lift needs to go up
	{
		while(SensorValue(PotLift) < position)//loop until position it met or time out
		{
			if(time1[T2] > DEFAULT_TIME_OUT)//check if robot has take too long to reach distance
			{
				liftFunction(20);//hold lift maybe shut it off what ever you want
				return false;//destiantion failed timed out return false
			}
			liftFunction(abs(power));//power motor to lifts up
		}
	}
	else if (SensorValue(PotLift) > position)//check if lift needs to go up
	{
		while(SensorValue(PotLift) > position)//loop until position it met or time out
		{
			if(time1[T2] > DEFAULT_TIME_OUT)//check if robot has take too long to reach distance
			{
				liftFunction(20);//hold lift maybe shut it off what ever you want
				return false;//destiantion failed timed out return false
			}

			liftFunction(-abs(power));//power motors to lift down
		}
	}
	//else must be in the correct position or some thing is wrong

	//power to hold lift up
	liftFunction(20);
	return true;


}
