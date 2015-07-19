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
