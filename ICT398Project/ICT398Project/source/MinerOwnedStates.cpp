#include "MinerOwnedStates.h"
#include "State.h"
#include "Miner.h"
#include "Locations.h"
//#include <time.h>
//#include "../../Common/misc/ConsoleUtils.h"

//#include "EntityNames.h"


Flee* Flee::Instance()
{
  static Flee instance;

  return &instance;
}

void Flee::Enter(Miner* pMiner)
{
	//idk anything taht needs doing upon entertign the state-maybe later put an image above their head or smth
}


void Flee::Execute(Miner* pMiner)
{

	//just keeping this so I rememebr how to change states
		 // pMiner->ChangeState(EnterMineAndDigForNugget::Instance());
	printf("entering flee state");
	
  //need a move toward position state?
	
	pMiner->ChangeState(Wander::Instance());
}


void Flee::Exit(Miner* pMiner)
{
  //idk stuff for exit-
}

//-------------------------------------------------------------

//wander

Wander* Wander::Instance()
{
  static Wander instance;

  return &instance;
}

void Wander::Enter(Miner* pMiner)
{

}


void Wander::Execute(Miner* pMiner)
{


//		  pMiner->ChangeState(EnterMineAndDigForNugget::Instance());
//just have it wander around
  

}


void Wander::Exit(Miner* pMiner)
{

}
//-------------------------------------------------------------

//-------------------------------------------------------------
Fight* Fight::Instance()
{
  static Fight instance;

  return &instance;
}

void Fight::Enter(Miner* pMiner)
{

}


void Fight::Execute(Miner* pMiner)
{


//		  pMiner->ChangeState(EnterMineAndDigForNugget::Instance());
//idk general idea is just have it run at whatever angered it, maybe pick up stuff
  

}


void Fight::Exit(Miner* pMiner)
{

}
//-------------------------------------------------------------

/////////////////////////////////
PickUp* PickUp::Instance()
{
  static PickUp instance;

  return &instance;
}

void PickUp::Enter(Miner* pMiner)
{

}


void PickUp::Execute(Miner* pMiner)
{


//		  pMiner->ChangeState(EnterMineAndDigForNugget::Instance());
//idk general idea is just have it run at whatever angered it, maybe pick up stuff
  

}


void PickUp::Exit(Miner* pMiner)
{

}