#pragma once
#include "../Calculator/Calculator.h"

class Object
{
private:
	DVector location, scale;
	DQuaternion rotation;
public:
	bool canTick = true;

public:
	Object();
	Object(DVector in_location, DQuaternion in_rotation, DVector in_scale);
	Object(const Object& in_object);

	virtual DVector GetLocation()const;
	virtual void SetLocation(DVector in_location);
	virtual DVector GetScale()const;
	virtual void SetScale(DVector in_scale);
	virtual DQuaternion GetRotationQ()const;
	virtual void SetRotationQ(DQuaternion in_rotation);

	virtual void Move(DVector in_vector);
	virtual void RotateQ(DQuaternion in_rotation);
	virtual void Scale(DVector in_vector);

	virtual void tick(double DT);
};