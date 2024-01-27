#include "DRotator.h"

DRotator::DRotator()
{
	roll = pitch = yaw = 0.0;
}

DRotator::DRotator(double in_value)
{
	roll = pitch = yaw = in_value;
}

DRotator::DRotator(double in_roll, double in_pitch, double in_yaw)
{
	roll = in_roll;
	pitch = in_pitch;
	yaw = in_yaw;
}

DRotator::DRotator(const DRotator& in_rotator)
{
	this->roll = in_rotator.roll;
	this->pitch = in_rotator.pitch;
	this->yaw = in_rotator.yaw;
}

DRotator::~DRotator()
{
}

DRotator DRotator::operator-()const
{
	return DRotator(-roll, -pitch, -yaw);
}

DRotator DRotator::operator+(const DRotator& in_vector)const
{
	return DRotator(roll + in_vector.roll, pitch + in_vector.pitch, yaw + in_vector.yaw);
}

DRotator DRotator::operator-(const DRotator& in_vector)const
{
	return DRotator(roll - in_vector.roll, pitch - in_vector.pitch, yaw - in_vector.yaw);
}

DRotator DRotator::operator*(const double& in_value)const
{
	return DRotator(roll * in_value, pitch * in_value, yaw * in_value);
}

DRotator DRotator::operator/(const double& in_value)const
{
	return DRotator(roll / in_value, pitch / in_value, yaw / in_value);
}
