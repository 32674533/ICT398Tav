#ifndef MINER_H
#define MINER_H
//------------------------------------------------------------------------
//
//  Name:   Miner.h
//
//  Desc:   A class defining a goldminer.
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include <string>
#include <cassert>

#include "BaseGameEntity.h"
#include "Locations.h"
#include "FCM.h"
#include "Agent.h"


class State;

class Miner : public BaseGameEntity
{
private:

	State*                m_pCurrentState;
  
	location_type         m_Location;
	void SetMatrix();
	FCM map;
	Agent NPC;
  	float anger;
	float joy;
	float trust;
	float anticipation;
	float fear;
	float surprise;
	float sadness;
	float disgust;
	void MoveToward();
public:
	Miner();
	Miner(int id);

  //this must be implemented
	void Update();

  //this method changes the current state to the new state. It first
  //calls the Exit() method of the current state, then assigns the
  //new state to m_pCurrentState and finally calls the Entry()
  //method of the new state.
	void ChangeState(State* new_state);

  

	location_type Location()const{return m_Location;}

};




#endif
