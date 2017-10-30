/**
* Types.h
*
* Author: Alfred Malone
* Date: 23/4/2017
*
* Defines a set of types for use in calculations on transformations in 3D space.
*
* Vectors of three types and a matrix type.
*/
#pragma once

#include <math.h>

namespace types{
	/**
	* @struct Vector2D
	* @brief A struct that defines a vector in two-dimensional space.
	*
	* The Vector2D struct is merely a data type that represents a vector in two-dimensional
	* space, providing a few functions to assist with spatial calculations. At present, it
	* does not appear to be used.
	*
	* @author Alfred Malone
	* @version 01
	* @date 23/4/2017 Alfred Malone, created basic class
	*
	* @author Alfred Malone
	* @version 02
	* @date 24/4/2017 Alfred Malone, added extra functions for calculations
	*
	* @bug Shouldn't be any, it's quite a simple struct.
	*/
	struct Vector2D{
		/// The x-axis value of the vector.
		float x;
		/// The y-axis value of the vector.
		float y;

		/**
		* The constructor for a Vector2D variable.
		* Initialises the x and y values.
		*/
		Vector2D(){
			x = 0.0f;
			y = 0.0f;
		}

		/**
		* Another constructor for a Vector2D variable.
		* Initialises the x and y values with xx and yy respectively.
		*/
		Vector2D(float xx, float yy){
			x = xx;
			y = yy;
		}

		/**
		* @brief Gets the length of the vector.
		* @return float - The vector's length as a floating-point number
		*
		* length calculates and returns the length of the vector using its x and y values.
		*/
		float length(){
			return (sqrt(x*x + y*y));
		}

		/**
		* @brief Gets the normalised version of the vector.
		* @return Vector2D - The normalised vector
		*
		* normalise calculates and returns the normalised version of the vector using its x
		* and y values.
		*/
		Vector2D normalise(){
			Vector2D normalVec = Vector2D();
			float length = this->length();

			if(length != 0){
				normalVec.x = x / length;
				normalVec.y = y / length;
			}

			return normalVec;
		}
	};

	/**
	* @struct Vector3D
	* @brief A struct that defines a vector in three-dimensional space.
	*
	* The Vector3D struct is merely a data type that represents a vector in three-
	* dimensional space, providing a few functions to assist with spatial calculations.
	*
	* @author Alfred Malone
	* @version 01
	* @date 23/4/2017 Alfred Malone, created basic class
	*
	* @author Alfred Malone
	* @version 02
	* @date 24/4/2017 Alfred Malone, added extra functions for calculations
	*
	* @author Alfred Malone
	* @version 03
	* @date 24/10/2017 Alfred Malone, added dot product
	*
	* @bug This one is also quite simple, so no bugs.
	*/
	struct Vector3D{
		/// The x-axis value of the vector.
		float x;
		/// The y-axis value of the vector.
		float y;
		/// The z-axis value of the vector.
		float z;

		/**
		* The constructor for a Vector3D variable.
		* Initialises the x, y, and z values.
		*/
		Vector3D(){
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
		}

		/**
		* Another constructor for a Vector3D variable.
		* Initialises the x, y, and z values with xx, yy, and zz respectively.
		*/
		Vector3D(float xx, float yy, float zz){
			x = xx;
			y = yy;
			z = zz;
		}

		/**
		* @brief Gets the length of the vector.
		* @return float - The vector's length as a floating-point number
		*
		* length calculates and returns the length of the vector using its x, y, and z
		* values.
		*/
		float length(){
			return (sqrt(x*x + y*y + z*z));
		}

		/**
		* @brief Gets the normalised version of the vector.
		* @return Vector3D - The normalised vector
		*
		* normalise calculates and returns the normalised version of the vector using its x,
		* y, and z values.
		*/
		Vector3D normalise(){
			Vector3D normalVec = Vector3D();
			float length = this->length();

			if(length != 0){
				normalVec.x = x / length;
				normalVec.y = y / length;
				normalVec.z = z / length;
			}

			return normalVec;
		}

		/**
		* @brief Gets the cross product of this and another vector.
		* @return Vector3D - The vector at right angles to this and the other vector
		*
		* crossProduct calculates and returns the vector at right angles to this vector and
		* another passed as a parameter using their x, y, and z values.
		*/
		Vector3D crossProduct(Vector3D otherVec){
			Vector3D crossVec;

			crossVec.x = (this->y * otherVec.z) + (this->z * otherVec.y);
			crossVec.y = (this->z * otherVec.x) + (this->x * otherVec.z);
			crossVec.z = (this->x * otherVec.y) + (this->y * otherVec.x);

			return crossVec;
		}

		/**
		* @brief Gets the dot product of this and another vector.
		* @return float - A scalar that can denote if the vectors are at right angles to one
		* another
		*
		* dotProduct calculates and returns a scalar product of this vector and another
		* passed as a parameter using their x, y, and z values.
		*/
		float dotProduct(Vector3D otherVec){
			return ((this->x * otherVec.x) + (this->y * otherVec.y) + (this->z * otherVec.z));
		}
	};

	/**
	* @struct Vector4D
	* @brief A struct that defines a vector in three-dimensional space with an extra value
	* that defines whether it is a point or a proper vector.
	*
	* The Vector4D struct is a data type that represents a vector or point in three-
	* dimensional space, the two of which can be discerned between with the w-value. A few
	* functions are provided to assist with spatial calculations. This type was created so
	* that 3D vectors could be used in matrix multiplication.
	*
	* @author Alfred Malone
	* @version 01
	* @date 23/4/2017 Alfred Malone, created basic class
	*
	* @author Alfred Malone
	* @version 02
	* @date 24/4/2017 Alfred Malone, added extra functions for calculations
	*
	* @bug This one, while requiring explanation, is also simple. No bugs.
	*/
	struct Vector4D{
		float x;
		float y;
		float z;
		float w;

		/**
		* The constructor for a Vector4D variable.
		* Initialises the x, y, z, and w values.
		*/
		Vector4D(){
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
			w = 1.0f;
		}

		/**
		* Another constructor for a Vector4D variable.
		* Initialises the x, y, z, and w values with xx, yy, zz, and ww respectively.
		*/
		Vector4D(float xx, float yy, float zz, float ww){
			x = xx;
			y = yy;
			z = zz;
			w = ww;
		}

		/**
		* @brief Gets the length of the vector.
		* @return float - The vector's length as a floating-point number
		*
		* length calculates and returns the length of the vector (after determining if it
		* is a vector) using its x, y, and z values.
		*/
		float length(){
			if(z != 0.0f)
				return (sqrt(x*x + y*y + z*z));
			else
				return 0.0f;
		}

		/**
		* @brief Gets the normalised version of the vector.
		* @return Vector4D - The normalised vector
		*
		* normalise calculates and returns the normalised version of the vector using its x,
		* y, and z values.
		*/
		Vector4D normalise(){
			Vector4D normalVec = Vector4D();
			float length = this->length();

			if(length != 0){
				normalVec.x = x / length;
				normalVec.y = y / length;
				normalVec.z = z / length;
			}

			return normalVec;
		}
	};

	/**
	* @struct Matrix3x3
	* @brief A struct that defines a three-dimensional matrix.
	*
	* The Matrix3x3 struct is a data type that represents a three-dimensional matrix. This
	* is useful for physics calculations or for storing three-dimensional vectors.
	*
	* @author Alfred Malone
	* @version 01
	* @date 25/10/2017 Alfred Malone, created basic class
	*
	* @author Alfred Malone
	* @version 02
	* @date 25/10/2017 Alfred Malone, added determinant and inverse calculations
	*/
	struct Matrix3x3{
		/// The columns of the matrix.
		Vector3D columns[3];

		/**
		* The constructor for a Matrix3x3 variable.
		* Initialises all of the elements of the matrix.
		*/
		Matrix3x3(){
			columns[0] = Vector3D(1, 0, 0);
			columns[1] = Vector3D(0, 1, 0);
			columns[2] = Vector3D(0, 0, 1);
		}

		/**
		* Another constructor for a Matrix3x3 variable.
		* Initialises the columns of the matrix with col1, col2, and col3.
		*/
		Matrix3x3(Vector3D col1, Vector3D col2, Vector3D col3){
			columns[0] = col1;
			columns[1] = col2;
			columns[2] = col3;
		}

		float determinant(){
			return ((columns[0].x * ((columns[1].y * columns[2].z) - (columns[2].y * columns[1].z))) -
					(columns[1].x * ((columns[0].y * columns[2].z) - (columns[2].y * columns[0].z))) +
					(columns[2].x * ((columns[0].y * columns[1].z) - (columns[1].y * columns[0].z))));
		}

		Matrix3x3 inverse(){
			Matrix3x3 inv, temp;
			float tempVal1, tempVal2, det = this->determinant();

			temp.columns[0].x = (this->columns[1].y * this->columns[2].z) - (this->columns[2].y * this->columns[1].z);
			temp.columns[0].y = (this->columns[1].x * this->columns[2].z) - (this->columns[2].x * this->columns[1].z);
			temp.columns[0].z = (this->columns[1].x * this->columns[2].y) - (this->columns[2].x * this->columns[1].y);
			temp.columns[1].x = (this->columns[0].y * this->columns[2].z) - (this->columns[2].y * this->columns[0].z);
			temp.columns[1].y = (this->columns[0].x * this->columns[2].z) - (this->columns[2].x * this->columns[0].z);
			temp.columns[1].z = (this->columns[0].x * this->columns[2].y) - (this->columns[2].x * this->columns[0].y);
			temp.columns[2].x = (this->columns[0].y * this->columns[1].z) - (this->columns[1].y * this->columns[0].z);
			temp.columns[2].y = (this->columns[0].x * this->columns[1].z) - (this->columns[1].x * this->columns[0].z);
			temp.columns[2].z = (this->columns[0].x * this->columns[1].y) - (this->columns[1].x * this->columns[0].y);

			temp.columns[1].x = -(temp.columns[1].x);
			temp.columns[0].y = -(temp.columns[0].y);
			temp.columns[2].y = -(temp.columns[2].y);
			temp.columns[1].z = -(temp.columns[1].z);

			tempVal1 = temp.columns[0].y;
			tempVal2 = temp.columns[1].x;
			temp.columns[0].y = tempVal2;
			temp.columns[1].x = tempVal1;

			tempVal1 = temp.columns[0].z;
			tempVal2 = temp.columns[2].x;
			temp.columns[0].z = tempVal2;
			temp.columns[2].x = tempVal1;

			tempVal1 = temp.columns[1].z;
			tempVal2 = temp.columns[2].y;
			temp.columns[1].z = tempVal2;
			temp.columns[2].y = tempVal1;

			inv.columns[0].x = temp.columns[0].x / det;
			inv.columns[0].y = temp.columns[0].y / det;
			inv.columns[0].z = temp.columns[0].z / det;
			inv.columns[1].x = temp.columns[1].x / det;
			inv.columns[1].y = temp.columns[1].y / det;
			inv.columns[1].z = temp.columns[1].z / det;
			inv.columns[2].x = temp.columns[2].x / det;
			inv.columns[2].y = temp.columns[2].y / det;
			inv.columns[2].z = temp.columns[2].z / det;

			return inv;
		}
	};

	/**
	* @struct Matrix4x4
	* @brief A struct that defines a four-dimensional matrix.
	*
	* The Matrix4x4 struct is a data type that represents a four-dimensional matrix. This is
	* useful for spatial calculations or for storing four-dimensional vectors.
	*
	* @author Alfred Malone
	* @version 01
	* @date 23/4/2017 Alfred Malone, created basic class
	*
	* @author Alfred Malone
	* @version 02
	* @date 24/4/2017 Alfred Malone, added copy constructor
	*
	* @bug This one, while requiring explanation, is also simple. No bugs.
	*/
	struct Matrix4x4{
		/// The columns of the matrix.
		Vector4D columns[4];

		/**
		* The constructor for a Matrix4x4 variable.
		* Initialises all of the elements of the matrix.
		*/
		Matrix4x4(){
			columns[0] = Vector4D(1, 0, 0, 0);
			columns[1] = Vector4D(0, 1, 0, 0);
			columns[2] = Vector4D(0, 0, 1, 0);
			columns[3] = Vector4D(0, 0, 0, 1);
		}

		/**
		* Another constructor for a Matrix4x4 variable.
		* Initialises the columns of the matrix with col1, col2, col3, and col4.
		*/
		Matrix4x4(Vector4D col1, Vector4D col2, Vector4D col3, Vector4D col4){
			columns[0] = col1;
			columns[1] = col2;
			columns[2] = col3;
			columns[3] = col4;
		}
	};

	/**
	* @brief An overridden subtraction operator for finding the vector between two other vectors.
	* @param v1 - The finishing point of the resulting vector
	* @param v2 - The starting point of the resulting vector
	* @return Vector3D - The vector resulting from the operation
	*
	* This overrides the subraction operator to reflect vector subtraction.
	*/
	Vector3D operator-(const Vector3D& v1, const Vector3D& v2);
	/**
	* @brief An overridden multiplication operator for matrix * vector calculations.
	* @param m - The matrix to be multiplied
	* @param v - The vector to be multiplied
	* @return Vector3D - The vector resulting from the operation
	*
	* This simply overrides the multiplication operator to reflect how pre-multiplying a
	* vector with a matrix operates.
	*/
	Vector3D operator*(const Matrix3x3& m, const Vector3D& v);
	/**
	* @brief An overridden multiplication operator for vector * matrix calculations.
	* @param v - The vector to be multiplied
	* @param m - The matrix to be multiplied
	* @return Vector3D - The vector resulting from the operation
	*
	* This simply overrides the multiplication operator to reflect how post-multiplying a
	* vector with a matrix operates.
	*/
	Vector3D operator*(const Vector3D& v, const Matrix3x3& m);
	/**
	*
	*/
	Vector3D operator*(const float& d, const Vector3D& v);
	/**
	* @brief An overridden multiplication operator for matrix multiplication.
	* @param m1 - The matrix to be pre-multiplied
	* @param m2 - The matrix to be post-multiplied
	* @return Matrix3x3 - The matrix resulting from the operation
	*
	* This simply overrides the multiplication operator to reflect how matrix multiplication
	* operates.
	*/
	Matrix3x3 operator*(const Matrix3x3& m1, const Matrix3x3& m2);
	/**
	* @brief An overridden multiplication operator for matrix * vector calculations.
	* @param m - The matrix to be multiplied
	* @param v - The vector to be multiplied
	* @return Vector4D - The vector resulting from the operation
	*
	* This simply overrides the multiplication operator to reflect how pre-multiplying a
	* vector with a matrix operates.
	*/
	Vector4D operator*(const Matrix4x4& m, const Vector4D& v);
	/**
	* @brief An overridden multiplication operator for vector * matrix calculations.
	* @param v - The vector to be multiplied
	* @param m - The matrix to be multiplied
	* @return Vector4D - The vector resulting from the operation
	*
	* This simply overrides the multiplication operator to reflect how post-multiplying a
	* vector with a matrix operates.
	*/
	Vector4D operator*(const Vector4D& v, const Matrix4x4& m);
	/**
	* @brief An overridden multiplication operator for matrix multiplication.
	* @param m1 - The matrix to be pre-multiplied
	* @param m2 - The matrix to be post-multiplied
	* @return Matrix4x4 - The matrix resulting from the operation
	*
	* This simply overrides the multiplication operator to reflect how matrix multiplication
	* operates.
	*/
	Matrix4x4 operator*(const Matrix4x4& m1, const Matrix4x4& m2);
}

