#include "affordance.h"


affordance::affordance(void)
{
	sit = false;
	pickUp = false;
	pickUpWeight =0;
	strength =0;
}

affordance::affordance(bool s, bool pick, float weight, int str)
{
	sit = s;
	pickUp = pick;
	pickUpWeight = weight;
	strength = str;
}


affordance::~affordance(void)
{
}


void affordance::SetSit(bool s){
	sit = s;
}
void affordance::SetWeight(float weight){
	pickUpWeight = weight;
}
void affordance::SetPickUp(bool pick){
	pickUp = pick;
}
bool affordance::GetSit(){
	return sit;
}

bool affordance::GetPickUp(){
	return pickUp;
}
float affordance::GetWeight(){
	return pickUpWeight;
}
int affordance::GetStrength(){
	return strength;
}
void affordance::SetStrength(int str){
	strength = str;
}