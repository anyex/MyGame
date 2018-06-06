#ifndef _VECTOR3_H_
#define _VECTOR3_H_

#include <math.h>

class Vector3 {
public:
	Vector3() { x = 0;y = 0;z = 0; }
	Vector3(float x, float y, float z) { this->x = x;this->y = y;this->z = z; }
	Vector3(Vector3& v) { this->x = v.x;this->y = v.y;this->z = v.z; }
	float Length() { return sqrt(x*x + y*y + z*z); }
	Vector3 operator+(Vector3& v);
	Vector3 operator-(Vector3& v);
	float operator*(Vector3& v);//ÏòÁ¿»ý
	Vector3 crossProduct(Vector3& v);
	Vector3 operator*(float scale);
	Vector3 operator/(float scale);
	Vector3 operator-();
	void unit() { 

		x /= Length();
		y /= Length();
		z /= Length();
	};
public:
	float x, y, z;

};

#endif
