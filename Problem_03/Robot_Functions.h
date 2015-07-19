/*
Michael Wallace
6/15/2015
MT SAC VEX ROBOTICS Guide to new robotic programmers

Licensed to the Apache Software Foundation (ASF) under one
or more contributor license agreements.  See the NOTICE file
distributed with this work for additional information
regarding copyright ownership.  The ASF licenses this file
to you under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance
with the License.  You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing,
software distributed under the License is distributed on an
"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
KIND, either express or implied.  See the License for the
specific language governing permissions and limitations
under the License.
*/

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


