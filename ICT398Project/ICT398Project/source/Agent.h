#pragma once
#include "GameObject.h"
class Agent
{
public:
	Agent(void);
	Agent(GameObject* bd);
	~Agent(void);

private:
	GameObject body;
};

