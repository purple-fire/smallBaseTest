/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * Copyright (c) 2011-2014, Purdue University ACM SIG BOTS.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Purdue University ACM SIG BOTS nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL PURDUE UNIVERSITY ACM SIG BOTS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Purdue Robotics OS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "motorControl.c"

#define DRIVE_LEFT_BACK 3
#define DRIVE_LEFT_MIDDLE 2
#define DRIVE_LEFT_FRONT 1

#define DRIVE_RIGHT_BACK 8
#define DRIVE_RIGHT_MIDDLE 9
#define DRIVE_RIGHT_FRONT 10


void operatorControl() {

	setMotorReversed(DRIVE_LEFT_MIDDLE, true);
	setMotorReversed(DRIVE_RIGHT_BACK, true);
	setMotorReversed(DRIVE_RIGHT_FRONT, true);

	while (1) {
		int leftStick = joystickGetAnalog(1, 3);
		int rightStick = joystickGetAnalog(1, 2);

		setMotorSpeed(DRIVE_LEFT_BACK, leftStick);
		setMotorSpeed(DRIVE_LEFT_MIDDLE, leftStick);
		setMotorSpeed(DRIVE_LEFT_FRONT, leftStick);

		setMotorSpeed(DRIVE_RIGHT_BACK, rightStick);
		setMotorSpeed(DRIVE_RIGHT_MIDDLE, rightStick);
		setMotorSpeed(DRIVE_RIGHT_FRONT, rightStick);

		delay(20);
	}
}
