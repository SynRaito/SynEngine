#pragma once

#include "../../Runtime/Core/Core.h"
#include <cmath>

namespace Syn::Math {

	class SYN_API Vector2D {

#define PI 3.141592

	public:
		Vector2D() = default;
		constexpr Vector2D(float x, float y) : x(x), y(y) {}
		constexpr Vector2D(const Vector2D& vector) : x(vector.x), y(vector.y) {}

	private:
		float x, y;

	public:
		inline constexpr Vector2D Zero() { return Vector2D(0, 0); }
		inline constexpr Vector2D One() { return Vector2D(1, 1); }

		inline Vector2D operator+(Vector2D vector) { return Vector2D(x + vector.x, y + vector.y); }
		inline Vector2D& operator+=(Vector2D vector) {
			x += vector.x;
			y += vector.y;
			return *this;
		}
		inline Vector2D operator-(Vector2D vector) { return Vector2D(x - vector.x, y - vector.y); }
		inline Vector2D& operator-=(Vector2D vector) {
			x -= vector.x;
			y -= vector.y;
			return *this;
		}
		inline Vector2D operator*(float value) { return Vector2D(x * value, y * value); }
		inline Vector2D& operator*=(float value) {
			x *= value;
			y *= value;
			return *this;
		}
		inline Vector2D operator/(float value) { return Vector2D(x / value, y / value); }
		inline Vector2D& operator/=(float value) {
			x /= value;
			y /= value;
			return *this;
		}
		inline float length() { return std::sqrtf(x * x + y * y); }
		static float length(Vector2D vector) { return std::sqrtf(vector.x * vector.x + vector.y * vector.y); }
		inline Vector2D normalize() { return (*this) / length(); }
		static Vector2D normalize(Vector2D vector) { return vector / vector.length(); }
		static float dot(Vector2D firstVector, Vector2D secondVector) { return firstVector.x * secondVector.x + firstVector.y * secondVector.y; }
		inline float dot(Vector2D vector) { return x * vector.x + y * vector.y; }
		inline float cross(Vector2D vector) { return length() * vector.length() * std::sinf(PI / 2 - angleBetweenRad(vector)); }
		static float cross(Vector2D firstVector, Vector2D secondVector) { return firstVector.length() * secondVector.length() * std::sinf(PI / 2 - angleBetweenRad(firstVector, secondVector)); }
		static float radToDeg(float rad) { return rad * PI / 2; }
		static float degToRad(float deg) { return deg / PI / 2; }
		inline float angleBetweenRad(Vector2D vector) { return std::acosf(dot(vector) / (length() + vector.length())); }
		static float angleBetweenRad(Vector2D firstVector, Vector2D secondVector) { return std::acosf(firstVector.dot(secondVector) / (firstVector.length() + secondVector.length())); }
		inline float angleBetweenDeg(Vector2D vector) { return radToDeg(angleBetweenRad(vector)); }
		static float angleBetweenDeg(Vector2D firstVector, Vector2D secondVector) { return radToDeg(angleBetweenRad(firstVector, secondVector)); }
		inline float X() { return x; }
		inline float Y() { return y; }
	};
}