#pragma once
#include "Actor.h"
#include "../IO/Input.h"

class Camera :public Actor
{
private:
	double viewDistance;
	double viewAngle;
	DQuaternion camRoll, camPitch, camYaw;
	double camMoveSpeed, camRotateSpeed;

public:
	Camera();
	Camera(double in_viewDistance);
	~Camera();

	double GetViewDistance()const;
	void SetViewDistance(double in_viewDistance);
	double GetViewAngle()const;
	void SetViewAngle(double in_viewAngle);
	double GetMoveSpeed()const;
	void SetMoveSpeed(double in_camMoveSpeed);
	double GetRotateSpeed()const;
	void SetRotateSpeed(double in_camRotateSpeed);

	void MoveCam(DVector in_vector);
	void RotateCam(DRotator in_rotator);

	void InputMoveCam();
	void InputRotateCam();

	virtual void tick(double DT)override;
};