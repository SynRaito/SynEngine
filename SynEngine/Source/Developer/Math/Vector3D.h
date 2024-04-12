#pragma once

#include "../../Runtime/Core/Core.h"
#include "Vector2D.h"
#include <cmath>

namespace Syn::Math {

	class SYN_API Vector3D {

#define PI 3.141592

	public:
		constexpr Vector3D(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}
		constexpr Vector3D(const Vector3D& vector) : x(vector.x), y(vector.y), z(vector.z) {}

	private:
		float x, y, z;

	public:
		inline constexpr Vector3D Zero() { return Vector3D(0, 0, 0); }
		inline constexpr Vector3D One() { return Vector3D(1, 1, 1); }

		inline Vector3D operator+(Vector3D vector3d) { return Vector3D(x + vector3d.x, y + vector3d.y, z + vector3d.z); }
		inline Vector3D& operator+=(Vector3D vector3d) { 
			x += vector3d.x; 
			y += vector3d.y; 
			z += vector3d.z;
			return *this;
		}
		inline Vector3D operator-(Vector3D vector3d) { return Vector3D(x - vector3d.x, y - vector3d.y, z - vector3d.z); }
		inline Vector3D& operator-=(Vector3D vector3d) {
			x -= vector3d.x;
			y -= vector3d.y;
			z -= vector3d.z;
			return *this;
		}
		inline Vector3D operator*(float value) { return Vector3D(x * value, y * value, z * value); }
		inline Vector3D& operator*=(float value) {
			x *= value;
			y *= value;
			z *= value;
			return *this;
		}
		inline Vector3D operator/(float value) { return Vector3D(x / value, y / value, z / value); }
		inline Vector3D& operator/=(float value) {
			x /= value;
			y /= value;
			z /= value;
			return *this;
		}
		inline float length() { return std::sqrtf(x * x + y * y + z * z); }
		static float length(Vector3D vector3d) { return std::sqrtf(vector3d.x * vector3d.x + vector3d.y * vector3d.y + vector3d.z * vector3d.z); }
		inline Vector3D normalize() { return (*this) / length(); }
		static Vector3D normalize(Vector3D vector) { return vector / vector.length(); }
		static float dot(Vector3D firstVector3d, Vector3D secondVector3d) { return firstVector3d.x * secondVector3d.x + firstVector3d.y * secondVector3d.y + firstVector3d.z * secondVector3d.z; }
		inline float dot(Vector3D vector3d) { return x * vector3d.x + y * vector3d.y + z * vector3d.z; }
		inline float cross(Vector3D vector3d) { return length() * vector3d.length() * std::sinf(PI / 2 - angleBetweenRad(vector3d)); }
		static float cross(Vector3D firstVector3d, Vector3D secondVector3d) { return firstVector3d.length() * secondVector3d.length() * std::sinf(PI / 2 - angleBetweenRad(firstVector3d, secondVector3d)); }
		static float radToDeg(float rad) { return rad * PI / 2; }
		static float degToRad(float deg) { return deg / PI / 2; }
		inline float angleBetweenRad(Vector3D vector3d) { return std::acosf(dot(vector3d) / (length() + vector3d.length())); }
		static float angleBetweenRad(Vector3D firstVector3d, Vector3D secondVector3d) { return std::acosf(firstVector3d.dot(secondVector3d) / (firstVector3d.length() + secondVector3d.length())); }
		inline float angleBetweenDeg(Vector3D vector3d) { return radToDeg(angleBetweenRad(vector3d)); }
		static float angleBetweenDeg(Vector3D firstVector3d, Vector3D secondVector3d) { return radToDeg(angleBetweenRad(firstVector3d, secondVector3d)); }
		inline float X() { return x; }
		inline float Y() { return y; }
		inline float Z() { return z; }
		inline Vector2D XY() { return Vector2D(x, y); }
		inline Vector2D XZ() { return Vector2D(x, z); }
		inline Vector2D YZ() { return Vector2D(y, z); }
	};
}
