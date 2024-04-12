#pragma once


#include "../../Runtime/Core/Core.h"
#include "Vector2D.h"
#include <cmath>
#include "Vector3D.h"

namespace Syn::Math {

	class SYN_API Vector4D {

#define PI 3.141592

	public:
		constexpr Vector4D(float x = 0, float y = 0, float z = 0, float w = 0) : x(x), y(y), z(z), w(w) {}
		constexpr Vector4D(const Vector4D& vector) : x(vector.x), y(vector.y), z(vector.z), w(vector.w) {}

	private:
		float x, y, z, w;

	public:
		inline constexpr Vector4D Zero() { return Vector4D(0, 0, 0, 0); }
		inline constexpr Vector4D One() { return Vector4D(1, 1, 1, 1); }

		inline Vector4D operator+(Vector4D vector) { return Vector4D(x + vector.x, y + vector.y, z + vector.z, w + vector.w); }
		inline Vector4D& operator+=(Vector4D vector) {
			x += vector.x;
			y += vector.y;
			z += vector.z;
			w += vector.w;
			return *this;
		}
		inline Vector4D operator-(Vector4D vector) { return Vector4D(x - vector.x, y - vector.y, z - vector.z, w - vector.w); }
		inline Vector4D& operator-=(Vector4D vector) {
			x -= vector.x;
			y -= vector.y;
			z -= vector.z;
			w -= vector.w;
			return *this;
		}
		inline Vector4D operator*(float value) { return Vector4D(x * value, y * value, z * value, w * value); }
		inline Vector4D operator*=(float value) {
			x *= value;
			y *= value;
			z *= value;
			w *= value;
			return *this;
		}
		inline Vector4D operator/(float value) { return Vector4D(x / value, y / value, z / value, w / value); }
		inline Vector4D operator/=(float value) {
			x /= value;
			y /= value;
			z /= value;
			w /= value;
			return *this;
		}
		inline float length() { return std::sqrtf(x * x + y * y + z * z + w * w); }
		static float length(Vector4D vector) { return std::sqrtf(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z + vector.w * vector.w); }
		inline Vector4D normalize() { return (*this) / length(); }
		static Vector4D normalize(Vector4D vector) { return vector / vector.length(); }
		static float dot(Vector4D firstVector, Vector4D secondVector) { return firstVector.x * secondVector.x + firstVector.y * secondVector.y + firstVector.z * secondVector.z + firstVector.w * secondVector.w; }
		inline float dot(Vector4D vector) { return x * vector.x + y * vector.y + z * vector.z + w * vector.w; }
		inline float cross(Vector4D vector) { return length() * vector.length() * std::sinf(PI / 2 - angleBetweenRad(vector)); }
		static float cross(Vector4D firstVector, Vector4D secondVector) { return firstVector.length() * secondVector.length() * std::sinf(PI / 2 - angleBetweenRad(firstVector, secondVector)); }
		static float radToDeg(float rad) { return rad * PI / 2; }
		static float degToRad(float deg) { return deg / PI / 2; }
		inline float angleBetweenRad(Vector4D vector) { return std::acosf(dot(vector) / (length() + vector.length())); }
		static float angleBetweenRad(Vector4D firstVector, Vector4D secondVector) { return std::acosf(firstVector.dot(secondVector) / (firstVector.length() + secondVector.length())); }
		inline float angleBetweenDeg(Vector4D vector) { return radToDeg(angleBetweenRad(vector)); }
		static float angleBetweenDeg(Vector4D firstVector, Vector4D secondVector) { return radToDeg(angleBetweenRad(firstVector, secondVector)); }
		inline float X() { return x; }
		inline float Y() { return y; }
		inline float Z() { return z; }
		inline float W() { return w; }
		inline Vector2D XY() { return Vector2D(x, y); }
		inline Vector2D XZ() { return Vector2D(x, z); }
		inline Vector2D YZ() { return Vector2D(y, z); }
		inline Vector3D XYZ() { return Vector3D(x, y, z); }
		inline Vector3D YZX() { return Vector3D(y, z, x); }
		inline Vector3D ZXY() { return Vector3D(z, x, y); }
	};
}
