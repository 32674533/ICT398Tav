#include "Agent.h"


enum 
{
  ent_Miner_Bob,

  ent_Elsa
};

Agent::Agent(void)
{
	
	//I guess have another constructor that gives default values for
	//each emotion
	//how to handle the connections? guess?
}

GameObject* Agent::GetGameObject(){

	return &body;
}
/*
void Agent::Set1By8(){
	map.FillMatrixB(0, 0, joy);
	map.FillMatrixB(0, 1, trust);
	map.FillMatrixB(0, 2, fear);
	map.FillMatrixB(0, 3, surprise);
	map.FillMatrixB(0, 4, sadness);
	map.FillMatrixB(0, 5, disgust);
	map.FillMatrixB(0, 6, anger);
	map.FillMatrixB(0, 7, anticipation);
	//ones through the middle are 0 ie, emotions have no effect on themselves
	map.FillMatrixA(0, 0, 0);
	map.FillMatrixA(1, 1, 0);
	map.FillMatrixA(2, 2, 0);
	map.FillMatrixA(3, 3, 0);
	map.FillMatrixA(4, 4, 0);
	map.FillMatrixA(5, 5, 0);
	map.FillMatrixA(6, 6, 0);
	map.FillMatrixA(7, 7, 0);

	//BELOW NEEDS THEIR IMPACTS ON EACH OTHER FILLED OUT
	//joy
	//joy, trust, fear, surprise, sadness, disgust, anger, anticipation
	map.FillMatrixA(0, 1, 0);
	map.FillMatrixA(0, 2, 0);
	map.FillMatrixA(0, 3, 0);
	map.FillMatrixA(0, 4, 0);
	map.FillMatrixA(0, 5, 0);
	map.FillMatrixA(0, 6, 0);
	map.FillMatrixA(0, 7, 0);

	//trust
	//joy, trust, fear, surprise, sadness, disgust, anger, anticipation
	map.FillMatrixA(1, 0, 0);
	map.FillMatrixA(1, 2, 0);
	map.FillMatrixA(1, 3, 0);
	map.FillMatrixA(1, 4, 0);
	map.FillMatrixA(1, 5, 0);
	map.FillMatrixA(1, 6, 0);
	map.FillMatrixA(1, 7, 0);
	
	//fear
	//joy, trust, fear, surprise, sadness, disgust, anger, anticipation
	map.FillMatrixA(2, 0, 0);
	map.FillMatrixA(2, 1, 0);
	map.FillMatrixA(2, 3, 0);
	map.FillMatrixA(2, 4, 0);
	map.FillMatrixA(2, 5, 0);
	map.FillMatrixA(2, 6, 0);
	map.FillMatrixA(2, 7, 0);

	//surprise
	//joy, trust, fear, surprise, sadness, disgust, anger, anticipation
	map.FillMatrixA(3, 0, 0);
	map.FillMatrixA(3, 1, 0);
	map.FillMatrixA(3, 2, 0);
	map.FillMatrixA(3, 4, 0);
	map.FillMatrixA(3, 5, 0);
	map.FillMatrixA(3, 6, 0);
	map.FillMatrixA(3, 7, 0);

	//sadness
	//joy, trust, fear, surprise, sadness, disgust, anger, anticipation
	map.FillMatrixA(4, 0, 0);
	map.FillMatrixA(4, 1, 0);
	map.FillMatrixA(4, 2, 0);
	map.FillMatrixA(4, 3, 0);
	map.FillMatrixA(4, 5, 0);
	map.FillMatrixA(4, 6, 0);
	map.FillMatrixA(4, 7, 0);

	//disgust
	//joy, trust, fear, surprise, sadness, disgust, anger, anticipation
	map.FillMatrixA(5, 0, 0);
	map.FillMatrixA(5, 1, 0);
	map.FillMatrixA(5, 2, 0);
	map.FillMatrixA(5, 3, 0);
	map.FillMatrixA(5, 4, 0);
	map.FillMatrixA(5, 6, 0);
	map.FillMatrixA(5, 7, 0);

	//anger
	//joy, trust, fear, surprise, sadness, disgust, anger, anticipation
	map.FillMatrixA(6, 0, 0);
	map.FillMatrixA(6, 1, 0);
	map.FillMatrixA(6, 2, 0);
	map.FillMatrixA(6, 3, 0);
	map.FillMatrixA(6, 4, 0);
	map.FillMatrixA(6, 5, 0);
	map.FillMatrixA(6, 7, 0);

	//anticipation
	//joy, trust, fear, surprise, sadness, disgust, anger, anticipation
	map.FillMatrixA(7, 0, 0);
	map.FillMatrixA(7, 1, 0);
	map.FillMatrixA(7, 2, 0);
	map.FillMatrixA(7, 3, 0);
	map.FillMatrixA(7, 4, 0);
	map.FillMatrixA(7, 5, 0);
	map.FillMatrixA(7, 6, 0);
}

*/

void Agent::UpdateAgent(double time){


}

Agent::~Agent(void)
{
}
