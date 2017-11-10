#pragma once

/** FCM.H - FCM class definition
* @class FCM class
* @brief FCM class, used for emotion storing updates emotions
* @author Ben Porter
*/


//using armadillo library download can be found at http://arma.sourceforge.net/download.html
//@todo change Set matrix so that it reads from file instead
//this is how armadillo wants to be referenced
/*
Conrad Sanderson and Ryan Curtin.
Armadillo: a template-based C++ library for linear algebra.
Journal of Open Source Software, Vol. 1, pp. 26, 2016. 
*/

#include <armadillo>


//could probs even merge this into methods in the agent class, would save the pain that is filling the matrix, however I feel like it's better if split-maybe
using namespace arma;
class FCM
{
public:
		/**
        *@brief default FCM constructor
        */
	FCM(void);
		/**
        *@brief default decontructor
        */
	~FCM(void);
		/**
        *@brief Fills a spot in matrixA
        *@param px -int, py-int, point-float
        *@return void
        */
	void FillMatrixA(int px, int py, float point);
		/**
        *@brief Fills a spot in matrixW
        *@param px -int, py-int, point-float
        *@return void
        */
	void FillMatrixW(int px, int py, float point);
		/**
        *@brief returns value in matrix A at px, py
        *@param px -int, py-int
        *@return float
        */
	float GetMatrixA(int px, int py);
		/**
        *@brief returns value in matrix W at px, py
        *@param px -int, py-int
        *@return float
        */
	float GetMatrixW(int px, int py);
		/**
        *@brief sets entire matrix for A
        *@param AA-mat
        *@return void
        */
	//exists so that you can bulk fill the matrices for ease of use
	void SetMatrixA(mat AA);
		/**
        *@brief sets entire matrix for W
        *@param WW-mat
        *@return void
        */
	void SetMatrixW(mat WW);
		/**
        *@brief update function for the FCM
        *@return void
        */
	void NewMatrix();
private:
	//mat A(8, 8);
	//this is the 8 by 8 matrix
	
	mat W;
	
	//this is the 1 by 8 matrix
	mat A;
	mat Aold;
};

