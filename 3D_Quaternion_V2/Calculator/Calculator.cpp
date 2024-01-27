#include "Calculator.h"

double Calculator::DP(DVector in_v1, DVector in_v2)
{
	return in_v1.x * in_v2.x + in_v1.y * in_v2.y + in_v1.z * in_v2.z;
}

DVector Calculator::CP(DVector in_v1, DVector in_v2)
{
	DVector ans;
	ans.x = in_v1.y * in_v2.z - in_v2.y * in_v1.z;
	ans.y = in_v1.z * in_v2.x - in_v2.z * in_v1.x;
	ans.z = in_v1.x * in_v2.y - in_v2.x * in_v1.y;
	return ans;
}

DQuaternion Calculator::QP(DQuaternion in_q1, DQuaternion in_q2)
{
	DQuaternion ans;
	ans.w = in_q1.w * in_q2.w - DP(in_q1.GetVector(), in_q2.GetVector());
	ans.SetVector(in_q2.GetVector() * in_q1.w + in_q1.GetVector() * in_q2.w + CP(in_q1.GetVector(), in_q2.GetVector()));
	return ans;
}

DQuaternion Calculator::MakeRotateQuaternion(double in_angle, DVector in_vector)
{
	DQuaternion ans;
	double dis, rad;
	rad = in_angle / 180 * Data_pi;
	dis = sqrt(in_vector.x * in_vector.x + in_vector.y * in_vector.y + in_vector.z * in_vector.z);
	if (dis == 0)
	{
		return DQuaternion(1, 0, 0, 0);
	}
	ans.w = cos(rad / 2);
	ans.SetVector(in_vector / dis * sin(rad / 2));
	return ans;
}

DQuaternion Calculator::MakeRotateQuaternion(double in_angle, axis in_axis)
{
	DQuaternion ans;
	DVector temp;
	double rad;
	rad = in_angle / 180 * Data_pi;
	switch (in_axis)
	{
	case 0:
		temp = DVector(1, 0, 0);
		break;
	case 1:
		temp = DVector(0, 1, 0);
		break;
	case 2:
		temp = DVector(0, 0, 1);
		break;
	}
	ans.w = cos(rad / 2);
	ans.SetVector(temp * sin(rad / 2));
	return ans;
}

DQuaternion Calculator::MixRotateQuaternion(DQuaternion in_q1, DQuaternion in_q2)
{
	return QP(in_q2, in_q1);
}

void Calculator::RotatePQ(DVector in_vector, DQuaternion in_rotateQuaternion, DVector& out_vector)
{
	out_vector = QP(QP(in_rotateQuaternion, DQuaternion(0, in_vector)), in_rotateQuaternion.Conjugate()).GetVector();
}

DVector Calculator::RotatePQ(DVector in_vector, DQuaternion in_rotateQuaternion)
{
	return QP(QP(in_rotateQuaternion, DQuaternion(0, in_vector)), in_rotateQuaternion.Conjugate()).GetVector();
}

//void Calculator::RotateQQ(DQuaternion in_Quaternion, DQuaternion in_rotateQuaternion, DQuaternion& out_Quaternion)
//{
//	DQuaternion Q(in_Quaternion);
//	DQuaternion rotateQ1(in_rotateQuaternion);
//	DQuaternion rotateQ2(in_rotateQuaternion.w, -in_rotateQuaternion.GetVector());
//	out_Quaternion = QP(QP(rotateQ1, Q), rotateQ2);
//}
