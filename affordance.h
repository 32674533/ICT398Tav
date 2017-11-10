#pragma once
/** affordance.H - affordance class definition
* @class affordance class
* @brief affordance class, only stores data related to affordances not methods for using, defaults to false/0
* @author Ben Porter
*/
class affordance
{
public:
		/**
        *@brief default constructer for affordance
        */
	affordance(void);
		/**
        *@brief default deconstructer for affordance
        */
	~affordance(void);
		/**
        *@brief default constructer for affordance
		*@param weight- s -bool, pick -bool, weight-float, str - int
        */
	affordance(bool s, bool pick, float weight, int str);
		/**
        *@brief setter sit
        *@param s- bool
        *@return void
        */
	void SetSit(bool s);
		/**
        *@brief setter weight
        *@param weight- float
        *@return void
        */
	void SetWeight(float weight);
		/**
        *@brief setter PickUp
        *@param pick- bool
        *@return void
        */
	void SetPickUp(bool pick);
		/**
        *@brief getter sit
        *@return bool
        */
	bool GetSit();
		/**
        *@brief getter PickUp
        *@return bool
        */
	bool GetPickUp();
		/**
        *@brief getter weight
        *@return float
        */
	float GetWeight();
		/**
        *@brief getter strength
        *@return int
        */
	int GetStrength();
		/**
        *@brief setter strength
        *@param str- float
        *@return void
        */
	void SetStrength(int str);
private:
	//add affordances as it becomes practical to implement them
	bool sit;
	float pickUpWeight;
	bool pickUp;
	int strength;

};

