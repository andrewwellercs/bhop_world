#include "Vec2.h"

Vec2::Vec2(float x, float y) {
    this-> x = x;
    this-> y = y;
}

Vec2::Vec2()
: Vec2(0, 0)
{}

Vec2& Vec2::operator =(const Vec2& other) {
    x = other.x;
    y = other.y;
    return *this;
}

Vec2 Vec2::operator +(const Vec2& other) const {
    return Vec2(
        x + other.x,
        y + other.y
    );
}

Vec2 Vec2::operator -(const Vec2& other) const {
    return Vec2(
        x - other.x,
        y - other.y
    );
}

Vec2 Vec2::operator *(float scalar) const {
    return Vec2(
        x * scalar,
        y * scalar
    );
}

Vec2 Vec2::operator /(float scalar) const {
    return Vec2(
        x / scalar,
        y / scalar
    );
}

float Vec2::operator[](int index) {
	switch(index) {
		case 0:	return x; break;
		case 1: return y; break;
	}
	throw std::invalid_argument("Vector index out of bounds");
}

float Vec2::magnitude() {
    return sqrt(magnitude_squared());
}

float Vec2::magnitude_squared() {
    return dot(*this, *this);
}

Vec2 Vec2::normalize() {
    return *this / magnitude();
}

float Vec2::dot(const Vec2& first, const Vec2& second) {
    return first.x * second.x 
         + first.y * second.y;
}