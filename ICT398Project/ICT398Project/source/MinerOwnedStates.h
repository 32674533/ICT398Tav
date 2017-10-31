#ifndef MINER_OWNED_STATES_H
#define MINER_OWNED_STATES_H
//------------------------------------------------------------------------
//
//  Name:   MinerOwnedStates.h
//
//  Desc:   All the states that can be assigned to the Miner class
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
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
//
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
//gonna have them stand still for now I guess, dunno any fancy wander algorithms
class Wander : public State
{
private:
	Wander(){}
	Wander(const Flee&);
	Wander& operator=(const Flee&);
public:
	static Wander* Instance();

	virtual void Enter(Miner* miner);

	virtual void Execute(Miner* miner);

	virtual void Exit(Miner* miner);
};

#endif