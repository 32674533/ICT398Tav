#ifndef MINER_H
#define MINER_H
/** Miner.H - Miner class definition
* @class Miner class
* @brief Miner class, contains all methods and variables the Agent can access
* @author Ben Porter
*/

#include <cassert>

#include "BaseGameEntity.h"
#include "FCM.h"
#include "Agent.h"
#include "GameObject.h"
#include <map>
class State;

class Miner : public BaseGameEntity
{
private:

	State*                m_pCurrentState;
		/**
        *@brief fills map with a default set of values
        *@return void
        */
	void SetMatrix();
		/**
        *@brief incomplete, meant to move agent towards a location
        *@param tarx -float, tary -float, tarz - float
        *@return void
        */
	void MoveToward(float tarx, float tary, float tarz);
		/**
        *@brief waiting on gameObject TextBox to be done, makes a message appear above the agent
        *@param message - std::string
        *@return void
        */
	void PresentMessage(std::string message);

	std::map<int, GameObject&> *worldObjects;
	
public:
		/**
        *@brief default constructor
        */
	Miner();
		/**
        *@brief default constructor
        *@param id -int
        */
	Miner(int id);
		/**
        *@brief picks up an game object, true on success
        *@return bool
        */
	bool PickUp();
		/**
        *@brief sits on a game object, true on success
        *@return bool
        */
	bool SitOn();
		/**
        *@brief setter for a map of all game Objects in the game world
        *@param world - std::map<int, GameObject&> *
        *@return void
        */
	void SetWorldObjects(std::map<int, GameObject&> *world);
	//yes I know it's terrible to have these as public, may change later didn't feel like writing 16 getter and setters
	float anger;
	float joy;
	float trust;
	float anticipation;
	float fear;
	float surprise;
	float sadness;
	float disgust;
		/**
        *@brief setter for map using armadillo ,atrices
        *@param world - std::map<int, GameObject&> *
        *@return void
        */
	void SetFCM(mat A, mat W);
	GameObject *body;
	FCM map;
		/**
        *@brief update functions for the AI
        *@return void
        */
	void Update();
		/**
        *@brief getter for a game object that the AI will use
        *@param body - GameObject&
        *@return void
        */
	void MinerCreateBody(GameObject& bod);
		/**
        *@brief used for state transitions
        *@param new_state-State*
        *@return void
        */
	void ChangeState(State* new_state);

};




#endif
