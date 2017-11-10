#include "FCM.h"


FCM::FCM(void)
{
	
	
	A.set_size(1, 8);
	Aold.set_size(1, 8);

	//just a way to mass fill the array, enr signals the end of the row
	/*
	  A << 0.165300 << 0.454037 << 0.995795 << 0.124098 << 0.047084 << endr
    << 0.688782 << 0.036549 << 0.552848 << 0.937664 << 0.866401 << endr
    << 0.348740 << 0.479388 << 0.506228 << 0.145673 << 0.491547 << endr
    << 0.148678 << 0.682258 << 0.571154 << 0.874724 << 0.444632 << endr
    << 0.245726 << 0.595218 << 0.409327 << 0.367827 << 0.385736 << endr;
	*/
	W.set_size(8, 8);
}
void FCM::FillMatrixW(int px, int py, float point){

	W(px,py) = point;
}

void FCM::FillMatrixA(int px, int py, float point){

	A(px,py) = point;
}

float FCM::GetMatrixA(int px, int py){
	return (float)A(px, py);
}

float FCM::GetMatrixW(int px, int py){
	return (float)W(px, py);
}

void FCM::SetMatrixA(mat AA){
	A = AA;
}

void FCM::SetMatrixW(mat WW){
	W = WW;
}

void FCM::NewMatrix(){

	Aold = A;
	int x = 1;
	//so this is the sigmoid function?
	//(x) = x / (1 + abs(x));
	//this needs the sigmoid function added to it?
	//f is sigmoid
	//oooor I could keep it as 1 and have a linear activation function
	//B(new) = f*(A(old) * A) + A(old)
	//what I am missing here is what I do with the new values for the emotions?
	//keep a close eye on wether or not commenting out //#define ARMA_USE_LAPACK and //#define ARMA_USE_BLAS
	//negatively affect the matrix operations-shouldn't
	//need to test out clamping results between 1 and 0 dunno if it currently does that
	//B = (B / (1 + abs(x)))*(Bold * A) +Bold;
	//got the
	//https://www.ncbi.nlm.nih.gov/pmc/articles/PMC3402553/
	//causes 0
	//B =(exp(-5)) *(Bold * A);// +Bold;
	//causes infinityness
	//B =(1/exp(-5)) *(Bold * A);//
	//causes infinityness
	//B =(1/exp(-1*1)) *(Bold * A) +Bold;
	//closest yet, numbers stays between -1 and 2?
	//B =(exp(-5)) *(Bold * A) +Bold;
	//ok t his works-I think, may break if I use different values higher numbers, can go negative but barely-may be worth just to clamp?
	//B =(exp(-10)) *(Bold * A) +Bold;
	//1 being divided as always breaks it
	//B =(1/exp(-10)) *(Bold * A) +Bold;
	//science
	//B =(1/exp(-5*B)) *(Bold * A) +Bold;

	//using alfies stuff
	//ok yeah this works need to play around with numbers but this g
	A = (Aold * W) + Aold;
	A = (1/(1+exp(-5*A)));
}

FCM::~FCM(void)
{
}
