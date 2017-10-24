#pragma once
/**
* @brief empty class for affordances for now
* @author Ben Porter
*/
class affordance
{
public:
	//so does the affordance change the position of the game object it's in? e.g picking up
	affordance(void);
	~affordance(void);
private:
	//idk can't think of any more affordances
	bool sit;
	float pickUpWeight;
	bool pickUp;

};

