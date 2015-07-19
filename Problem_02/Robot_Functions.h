

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
