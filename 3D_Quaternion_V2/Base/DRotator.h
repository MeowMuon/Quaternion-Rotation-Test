#pragma once

struct DRotator
{
	double roll, pitch, yaw;

	DRotator();
	DRotator(double in_value);
	DRotator(double in_roll, double in_pitch, double in_yaw);
	DRotator(const DRotator& in_rotator);
	~DRotator();

	DRotator operator-()const;
	DRotator operator+(const DRotator& in_vector)const;
	DRotator operator-(const DRotator& in_vector)const;
	DRotator operator*(const double& in_value)const;
	DRotator operator/(const double& in_value)const;
};