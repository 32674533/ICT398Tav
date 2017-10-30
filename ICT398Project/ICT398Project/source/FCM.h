#pragma once
#include <armadillo>
//using armadillo library download can be found at http://arma.sourceforge.net/download.html
//this is how armadillo wants to be referenced
/*
Conrad Sanderson and Ryan Curtin.
Armadillo: a template-based C++ library for linear algebra.
Journal of Open Source Software, Vol. 1, pp. 26, 2016. 
*/


//could probs even merge this into methods in the agent class, would save the pain that is filling the matrix, however I feel like it's better if split-maybe
using namespace arma;
class FCM
{
public:
	FCM(void);
	~FCM(void);
	void FillMatrixA(int px, int py, float point);
	void FillMatrixB(int px, int py, float point);
	float GetMatrixA(int px, int py);
	float GetMatrixB(int px, int py);
private:
	//mat A(8, 8);
	//this is the 8 by 8 matrix
	void NewMatrix();
	mat A;
	
	//this is the 1 by 8 matrix
	mat B;
	mat Bold;
};

