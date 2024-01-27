#pragma once
#include "DVector.h"

struct DQuaternion
{
	double w, x, y, z;

	DQuaternion();
	DQuaternion(double in_w, double in_x, double in_y, double in_z);
	DQuaternion(double in_w, DVector in_vector);

	DVector GetVector()const;
	void SetVector(DVector in_vector);

	DQuaternion Conjugate()const;
};