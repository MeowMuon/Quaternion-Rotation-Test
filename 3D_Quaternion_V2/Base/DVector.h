#pragma once
#include <math.h>

struct DVector
{
	double x, y, z;

	DVector();
	DVector(double in_value);
	DVector(double in_x, double in_y, double in_z);
	DVector(const DVector& in_vector);
	~DVector();

	DVector Abs()const;
	double Norm()const;

	DVector operator-()const;
	DVector operator+(const DVector& in_vector)const;
	DVector operator-(const DVector& in_vector)const;
	DVector operator*(const double& in_value)const;
	DVector operator/(const double& in_value)const;
};

struct DVector2
{
	double x, y;

	DVector2();
	DVector2(double in_value);
	DVector2(double in_x, double in_y);
	DVector2(const DVector2& in_Vector2);
	~DVector2();

	DVector2 operator-()const;
	DVector2 operator+(const DVector& in_vector)const;
	DVector2 operator-(const DVector& in_vector)const;
	DVector2 operator*(const double& in_value)const;
	DVector2 operator/(const double& in_value)const;
};