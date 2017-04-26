#ifndef __VECTOR__
#define __VECTOR__

#include <math.h>

class Vector2D{
	
	public:

		Vector2D(float x, float y);
		Vector2D() : x(0), y(0) {}
		float getX();
		float getY();
		void setX(float x);
		void setY(float y);
		float length();
		void normalize();
		Vector2D operator+(const Vector2D& v2) const;
		Vector2D operator+=(const Vector2D& v2);
		Vector2D operator-(const Vector2D& v2);
		Vector2D operator-=(const Vector2D& v2);
		Vector2D operator/(float scalar);
		Vector2D operator/=(const Vector2D& v2);
		Vector2D operator*(float scalar);
		Vector2D operator*=(float scalar);
	private:

		float x;
		float y;
};

#endif