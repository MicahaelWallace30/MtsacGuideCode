

//T1 for drive
//T2 for Lift

//prototype to have default argument
bool drive(int throttle, int steering, int distance, int const DEFAULT_TIME_OUT = DEFAULAT_TIME_OUT_MS);

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


