#include "DQuaternion.h"

DQuaternion::DQuaternion()
{
	w = x = y = z = 0.0;
}

DQuaternion::DQuaternion(double in_w, double in_x, double in_y, double in_z)
{
	w = in_w;
	x = in_x;
	y = in_y;
	z = in_z;
}

DQuaternion::DQuaternion(double in_w, DVector in_vector)
{
	w = in_w;
	x = in_vector.x;
	y = in_vector.y;
	z = in_vector.z;
}

DVector DQuaternion::GetVector() const
{
	return DVector(x, y, z);
}

void DQuaternion::SetVector(DVector in_vector)
{
	this->x = in_vector.x;
	this->y = in_vector.y;
	this->z = in_vector.z;
}

DQuaternion DQuaternion::Conjugate() const
{
	return DQuaternion(w, -x, -y, -z);
}
