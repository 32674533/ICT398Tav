#include "Types.h"

using namespace types;

Vector3D types::operator-(const Vector3D& v1, const Vector3D& v2){
	return Vector3D(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

Vector3D types::operator*(const Matrix3x3& m, const Vector3D& v){
	return Vector3D((m.columns[0].x * v.x) + (m.columns[1].x * v.y) + (m.columns[2].x * v.z),
					(m.columns[0].y * v.x) + (m.columns[1].y * v.y) + (m.columns[2].y * v.z),
					(m.columns[0].z * v.x) + (m.columns[1].z * v.y) + (m.columns[2].z * v.z));
}

Vector3D types::operator*(const Vector3D& v, const Matrix3x3& m){
	return Vector3D((v.x * m.columns[0].x) + (v.y * m.columns[0].y) + (v.z * m.columns[0].z),
					(v.x * m.columns[1].x) + (v.y * m.columns[1].y) + (v.z * m.columns[1].z),
					(v.x * m.columns[2].x) + (v.y * m.columns[2].y) + (v.z * m.columns[2].z));
}

Vector3D types::operator*(const float& d, const Vector3D& v){
	return Vector3D(d * v.x, d * v.y, d * v.z);
}

Matrix3x3 types::operator*(const Matrix3x3& m1, const Matrix3x3& m2){
	Vector3D X = m1 * m2.columns[0];
	Vector3D Y = m1 * m2.columns[1];
	Vector3D Z = m1 * m2.columns[2];

	return Matrix3x3(X, Y, Z);
}

Vector4D types::operator*(const Matrix4x4& m, const Vector4D& v){
	return Vector4D((m.columns[0].x * v.x) + (m.columns[1].x * v.y) + (m.columns[2].x * v.z) + (m.columns[3].x * v.w),
					(m.columns[0].y * v.x) + (m.columns[1].y * v.y) + (m.columns[2].y * v.z) + (m.columns[3].y * v.w),
					(m.columns[0].z * v.x) + (m.columns[1].z * v.y) + (m.columns[2].z * v.z) + (m.columns[3].z * v.w),
					(m.columns[0].w * v.x) + (m.columns[1].w * v.y) + (m.columns[2].w * v.z) + (m.columns[3].w * v.w));
}

Vector4D types::operator*(const Vector4D& v, const Matrix4x4& m){
	return Vector4D((v.x * m.columns[0].x) + (v.y * m.columns[0].y) + (v.z * m.columns[0].z) + (v.w * m.columns[0].w),
					(v.x * m.columns[1].x) + (v.y * m.columns[1].y) + (v.z * m.columns[1].z) + (v.w * m.columns[1].w),
					(v.x * m.columns[2].x) + (v.y * m.columns[2].y) + (v.z * m.columns[2].z) + (v.w * m.columns[2].w),
					(v.x * m.columns[3].x) + (v.y * m.columns[3].y) + (v.z * m.columns[3].z) + (v.w * m.columns[3].w));
}

Matrix4x4 types::operator*(const Matrix4x4& m1, const Matrix4x4& m2){
	Vector4D X = m1 * m2.columns[0];
	Vector4D Y = m1 * m2.columns[1];
	Vector4D Z = m1 * m2.columns[2];
	Vector4D W = m1 * m2.columns[3];
 
	return Matrix4x4(X, Y, Z, W);
}