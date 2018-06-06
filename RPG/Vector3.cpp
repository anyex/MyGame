#include "Vector3.h"

Vector3 Vector3::operator+(Vector3& v){ 
	Vector3 ret;
	ret.x = x + v.x;
	ret.y = y + v.y;
	ret.z = z + v.z;
	return ret; 
}
Vector3 Vector3::operator-(Vector3& v) {
	Vector3 ret;
	ret.x = x - v.x;
	ret.y = y - v.y;
	ret.z = z - v.z;
	return ret;
}
Vector3 Vector3::operator*(float scale)
{
	Vector3 ret;
	ret.x = x * scale;
	ret.y = y * scale;
	ret.z = z * scale;
	return ret;
}
Vector3 Vector3::operator/(float scale)
{
	Vector3 ret;
	if (scale == 0)
	{
		scale = 1;
	}
	ret.x = x / scale;
	ret.y = y / scale;
	ret.z = z / scale;

	return ret;
}

float Vector3::operator*(Vector3& v)
{
	float ret = v.x*x + v.y*y + v.z*z;

	return ret;
}

Vector3 Vector3::operator-()
{
	Vector3 ret;
	ret.x = -x;
	ret.y = -y;
	ret.z = -z;

	return ret;
}

Vector3 Vector3::crossProduct(Vector3& v)
{
	Vector3 ret;

	ret.x = y*v.z - z*v.y;
	ret.y = z*v.x - x*v.z;
	ret.z = x*v.y - y*v.x;

	return ret;
}