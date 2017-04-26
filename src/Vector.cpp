#include "Vector.h"

Vector2D::Vector2D(float x, float y){
	this->x = x;
	this->y = y;
}

float Vector2D::getX(){
	return this->x;
}

float Vector2D::getY(){
	return this->y;
}

void Vector2D::setX(float x){
	this->x = x;
}

void Vector2D::setY(float y){
	this->y = y;
}

float Vector2D::length(){

	return sqrt(x*x + y*y);

}

Vector2D Vector2D::operator+(const Vector2D& v2) const{
	return Vector2D(x + v2.x, y + v2.y);
}

Vector2D Vector2D::operator+=(const Vector2D& v2){
	x += v2.x;
	y += v2.y;

	return *this;
}

Vector2D Vector2D::operator*(float scalar){
	return Vector2D(x*scalar, y*scalar);
}

Vector2D Vector2D::operator*=(float scalar){
	x *= scalar;
	y *= scalar;

	return *this;
}

Vector2D Vector2D::operator-(const Vector2D& v2){
	return Vector2D(x - v2.x, y - v2.y);
}

Vector2D Vector2D::operator-=(const Vector2D& v2){
	x -= v2.x;
	y-= v2.y;

	return *this;
}

Vector2D Vector2D::operator/(float scalar){
	return Vector2D(x/scalar, y/scalar);
}

Vector2D Vector2D::operator/=(const Vector2D& v2){
	x /= v2.x;
	y/= v2.y;

	return *this;
}

void Vector2D::normalize(){
	float l = this->length();
	if(l > 0)
		(*this) *= 1/l;
}
