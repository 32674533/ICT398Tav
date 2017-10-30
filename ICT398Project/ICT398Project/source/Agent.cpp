#include "Agent.h"


Agent::Agent(void)
{
	//I guess have another constructor that gives default values for
	//each emotion
	//how to handle the connections? guess?
}

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

	//joy
}

Agent::~Agent(void)
{
}
