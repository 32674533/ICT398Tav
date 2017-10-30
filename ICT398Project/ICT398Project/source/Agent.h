#pragma once

#include "GameObject.h"
#include "FCM.h"
class Agent
{
public:
	Agent(void);
	Agent(GameObject* bd);
	~Agent(void);
	
private:
	GameObject body;
	FCM map;
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

