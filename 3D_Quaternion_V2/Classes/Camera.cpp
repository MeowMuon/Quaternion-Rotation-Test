#include "Camera.h"
#include "../IO/Graphic.h"

Camera::Camera() :Actor()
{
	viewDistance = 0.0;
	camRoll = camPitch = camYaw = DQuaternion(1, 0, 0, 0);
	camMoveSpeed = 10;
	camRotateSpeed = 1;
}

Camera::Camera(double in_viewDistance) :Actor()
{
	viewDistance = in_viewDistance;
	camRoll = camPitch = camYaw = DQuaternion(1, 0, 0, 0);
	camMoveSpeed = 10;
	camRotateSpeed = 1;
}

Camera::~Camera()
{

}

double Camera::GetViewDistance() const
{
	return viewDistance;
}

void Camera::SetViewDistance(double in_viewDistance)
{
	viewDistance = in_viewDistance;
	viewAngle = atan(max(Graphic::SCREEN_WIDTH, Graphic::SCREEN_HEIGHT) / 2 / viewDistance);
}

double Camera::GetViewAngle() const
{
	return viewAngle;
}

void Camera::SetViewAngle(double in_viewAngle)
{
	viewAngle = in_viewAngle * Data_pi / 180;
	viewDistance = max(Graphic::SCREEN_WIDTH, Graphic::SCREEN_HEIGHT) / 2 / tan(viewAngle);

}

double Camera::GetMoveSpeed() const
{
	return camMoveSpeed;
}

void Camera::SetMoveSpeed(double in_camMoveSpeed)
{
	camMoveSpeed = in_camMoveSpeed;
}

double Camera::GetRotateSpeed() const
{
	return camRotateSpeed;
}

void Camera::SetRotateSpeed(double in_camRotateSpeed)
{
	camRotateSpeed = in_camRotateSpeed;
}

void Camera::MoveCam(DVector in_vector)
{
	SetLocation(GetLocation() + Calculator::RotatePQ(in_vector, GetRotationQ()));
}

void Camera::RotateCam(DRotator in_rotator)
{
	camRoll = Calculator::MixRotateQuaternion(camRoll, Calculator::MakeRotateQuaternion(in_rotator.roll, DVector(1, 0, 0)));
	camPitch = Calculator::MixRotateQuaternion(camPitch, Calculator::MakeRotateQuaternion(in_rotator.pitch, DVector(0, 1, 0)));
	camYaw = Calculator::MixRotateQuaternion(camYaw, Calculator::MakeRotateQuaternion(in_rotator.yaw, DVector(0, 0, 1)));
	SetRotationQ(Calculator::MixRotateQuaternion(Calculator::MixRotateQuaternion(camRoll, camPitch), camYaw));
}

void Camera::InputMoveCam()
{
	if (Input::KeyState(87))
	{
		MoveCam(DVector(1, 0, 0) * camMoveSpeed);
	}
	if (Input::KeyState(83))
	{
		MoveCam(DVector(-1, 0, 0) * camMoveSpeed);
	}
	if (Input::KeyState(65))
	{
		MoveCam(DVector(0, 1, 0) * camMoveSpeed);
	}
	if (Input::KeyState(68))
	{
		MoveCam(DVector(0, -1, 0) * camMoveSpeed);
	}
	if (Input::KeyState(32))
	{
		MoveCam(DVector(0, 0, 1) * camMoveSpeed);
	}
	if (Input::KeyState(17))
	{
		MoveCam(DVector(0, 0, -1) * camMoveSpeed);
	}
}

void Camera::InputRotateCam()
{
	if (Input::KeyState(79))
	{
		RotateCam(DRotator(0, -1, 0) * camRotateSpeed);
	}
	if (Input::KeyState(76))
	{
		RotateCam(DRotator(0, 1, 0) * camRotateSpeed);
	}
	if (Input::KeyState(75))
	{
		RotateCam(DRotator(0, 0, 1) * camRotateSpeed);
	}
	if (Input::KeyState(186))
	{
		RotateCam(DRotator(0, 0, -1) * camRotateSpeed);
	}
	if (Input::KeyState(73))
	{
		RotateCam(DRotator(-1, 0, 0) * camRotateSpeed);
	}
	if (Input::KeyState(80))
	{
		RotateCam(DRotator(1, 0, 0) * camRotateSpeed);
	}
}

void Camera::tick(double DT)
{
	if (canTick)
	{
		Actor::tick(DT);
		//Tick:
		InputMoveCam();
		InputRotateCam();
	}
}
