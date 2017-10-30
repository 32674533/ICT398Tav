#pragma once
#include <armadillo>
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

