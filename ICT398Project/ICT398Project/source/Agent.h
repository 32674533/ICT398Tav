#pragma once
//@notes May need to remove this class it is kinda pointless, need to somehow keep track of time for cycle reasons - ie 1 cycle every half a second
#include "GameObject.h"
#include "FCM.h"
//#include "Miner.h"
class Agent
{
public:
	Agent(void);
	Agent(GameObject* bd);
	void UpdateAgent(double time);
	GameObject* GetGameObject();
	~Agent(void);
	
private:
	GameObject body;
	FCM map;
//	Miner ted;
	float anger;
	float joy;
	float trust;
	float anticipation;
	float fear;
	float surprise;
	float sadness;
	float disgust;
	void Set1By8();
	
};

