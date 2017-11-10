#ifndef MINER_OWNED_STATES_H
#define MINER_OWNED_STATES_H
/** MinerOwnedStates.h - MinerOwnedStates class definition
* @class FCM class
* @brief contains all states the Agent may use
* @author Ben Porter
*/

#include "State.h"
#include "Agent.h"

class Miner;


//------------------------------------------------------------------------
//------------------------------------------------------------------------


//------------------------------------------------------------------------
//
//------------------------------------------------------------------------
class Flee : public State
{
private:
	Flee(){}
	Flee(const Flee&);
	Flee& operator=(const Flee&);
public:
	static Flee* Instance();

	virtual void Enter(Miner* miner);

	virtual void Execute(Miner* miner);

	virtual void Exit(Miner* miner);
};

//------------------------------------------------------------------------
//was just gonna have them run at the player-not implemented
//------------------------------------------------------------------------
class Fight : public State
{
private:
	Fight(){}
	Fight(const Fight&);
	Fight& operator=(const Fight&);
public:
	static Fight* Instance();

	virtual void Enter(Miner* miner);

	virtual void Execute(Miner* miner);

	virtual void Exit(Miner* miner);
};


//------------------------------------------------------------------------
//
//------------------------------------------------------------------------
//this is the default class
//gonna have them stand still for now, future recommendation have a wander algorithm or 
class Wander : public State
{
private:
	Wander(){}
	Wander(const Wander&);
	Wander& operator=(const Wander&);
public:
	static Wander* Instance();

	virtual void Enter(Miner* miner);

	virtual void Execute(Miner* miner);

	virtual void Exit(Miner* miner);
};

//------------------------------------------------------------------------
//
//------------------------------------------------------------------------
class Happy : public State
{
private:
	Happy(){}
	Happy(const Happy&);
	Happy& operator=(const Happy&);
public:
	static Happy* Instance();

	virtual void Enter(Miner* miner);

	virtual void Execute(Miner* miner);

	virtual void Exit(Miner* miner);
};


#endif