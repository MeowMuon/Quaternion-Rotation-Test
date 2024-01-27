#pragma once
#include <math.h>
#include "../Base/DQuaternion.h"
#include "../Base/DVector.h"
#include "../Base/DRotator.h"

#define Data_pi 3.14159265358979323846

class Calculator
{
private:
	enum axis { x = 0, y = 1, z = 2 };
public:
	static double DP(DVector in_v1, DVector in_v2);
	static DVector CP(DVector in_v1, DVector in_v2);
	static DQuaternion QP(DQuaternion in_q1, DQuaternion in_q2);
	static DQuaternion MakeRotateQuaternion(double in_angle, DVector in_vector);
	static DQuaternion MakeRotateQuaternion(double in_angle, axis in_axis);
	static DQuaternion MixRotateQuaternion(DQuaternion in_q1, DQuaternion in_q2);
	static void RotatePQ(DVector in_vector, DQuaternion in_rotateQuaternion, DVector& out_vector);
	static DVector RotatePQ(DVector in_vector, DQuaternion in_rotateQuaternion);
};