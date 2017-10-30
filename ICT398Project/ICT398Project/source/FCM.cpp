#include "FCM.h"


FCM::FCM(void)
{
	A(8, 8);
	//just a way to mass fill the array, enr signals the end of the row
	/*
	  A << 0.165300 << 0.454037 << 0.995795 << 0.124098 << 0.047084 << endr
    << 0.688782 << 0.036549 << 0.552848 << 0.937664 << 0.866401 << endr
    << 0.348740 << 0.479388 << 0.506228 << 0.145673 << 0.491547 << endr
    << 0.148678 << 0.682258 << 0.571154 << 0.874724 << 0.444632 << endr
    << 0.245726 << 0.595218 << 0.409327 << 0.367827 << 0.385736 << endr;
	*/
	B(1, 8);
	Bold(1, 8);
}
void FCM::FillMatrixA(int px, int py, float point){

	A(px,py) = point;
}

void FCM::FillMatrixB(int px, int py, float point){

	B(px,py) = point;
}

float FCM::GetMatrixA(int px, int py){
	return A(px, py);
}

float FCM::GetMatrixB(int px, int py){
	return B(px, py);
}

void FCM::NewMatrix(){

	Bold = B;
	int x;
	//so this is the sigmoid function?
	//(x) = x / (1 + abs(x));
	//this needs the sigmoid function added to it?
	//f is sigmoid
	//oooor I could keep it as 1 and have a linear activation function
	//B(new) = f*(A(old) * A) + A(old)
	//what I am missing here is what I do with the new values for the emotions?
	B = (B / (1 + abs(x)))*(Bold * A) +Bold;
}

FCM::~FCM(void)
{
}
