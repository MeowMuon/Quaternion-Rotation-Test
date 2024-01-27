#include "DVector.h"

DVector::DVector()
{
	x = y = z = 0.0;
}

DVector::DVector(double in_value)
{
	x = y = z = in_value;
}

DVector::DVector(double in_x, double in_y, double in_z)
{
	x = in_x;
	y = in_y;
	z = in_z;
}

DVector::DVector(const DVector& in_vector)
{
	this->x = in_vector.x;
	this->y = in_vector.y;
	this->z = in_vector.z;
}

DVector::~DVector()
{
}

DVector DVector::Abs() const
{
	return DVector(fabs(x), fabs(y), fabs(z));
}

double DVector::Norm() const
{
	return sqrt(x * x + y * y + z * z);
}

DVector DVector::operator-()const
{
	return DVector(-x, -y, -z);
}

DVector DVector::operator+(const DVector& in_vector)const
{
	return DVector(x + in_vector.x, y + in_vector.y, z + in_vector.z);
}

DVector DVector::operator-(const DVector& in_vector)const
{
	return DVector(x - in_vector.x, y - in_vector.y, z - in_vector.z);
}

DVector DVector::operator*(const double& in_value)const
{
	return DVector(x * in_value, y * in_value, z * in_value);
}

DVector DVector::operator/(const double& in_value)const
{
	return DVector(x / in_value, y / in_value, z / in_value);
}

DVector2::DVector2()
{
	x = y = 0.0;
}

DVector2::DVector2(double in_value)
{
	x = y = in_value;
}

DVector2::DVector2(double in_x, double in_y)
{
	x = in_x;
	y = in_y;
}

DVector2::DVector2(const DVector2& in_Vector2)
{
	x = in_Vector2.x;
	y = in_Vector2.y;
}

DVector2::~DVector2()
{

}
