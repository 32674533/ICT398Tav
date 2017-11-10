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
	//display scared image above head
	printf("flee state entered\n");
}


void Flee::Execute(Miner* pMiner)
{

	//just keeping this so I rememebr how to change states
		 // pMiner->ChangeState(EnterMineAndDigForNugget::Instance());
	//printf("entering flee state");
	
  //need a move toward position state?
	if(pMiner->anger>pMiner->fear){
		pMiner->ChangeState(Fight::Instance());
	}else {
		pMiner->ChangeState(Wander::Instance());
	}
}


void Flee::Exit(Miner* pMiner)
{
  
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
	printf("wander state entered\n");
}


void Wander::Execute(Miner* pMiner)
{

	if(pMiner->anger>0.7&&pMiner->fear<pMiner->anger){
		pMiner->ChangeState(Fight::Instance());
	}else if(pMiner->disgust>0.7){
		pMiner->ChangeState(Flee::Instance());	
	}else if (pMiner->joy>0.6){
		//printf("went to happy\n");
		pMiner->ChangeState(Happy::Instance());
	}else if(pMiner->anticipation<0.4){
		//printf("sitting\n");
		pMiner->SitOn();
		pMiner->ChangeState(Wander::Instance());
	}else{
		pMiner->ChangeState(Wander::Instance());
	}


}


void Wander::Exit(Miner* pMiner)
{

}
//-------------------------------------------------------------
//Fight class, simply gets angry, picks stuff up
//-------------------------------------------------------------
//Not implemented plan was to have it just run at the player
Fight* Fight::Instance()
{
  static Fight instance;

  return &instance;
}

void Fight::Enter(Miner* pMiner)
{
	//display angry image
	printf("fight state entered\n");
}


void Fight::Execute(Miner* pMiner)
{

	pMiner->PickUp();

	if(pMiner->fear>pMiner->anger){
		pMiner->ChangeState(Flee::Instance());
	}else if(pMiner->anger < 0.6){
		pMiner->ChangeState(Wander::Instance());
	}else{
		pMiner->ChangeState(Fight::Instance());
	}
  

}


void Fight::Exit(Miner* pMiner)
{

}



//////////////////
//Happy state
/////////////////
Happy* Happy::Instance()
{
  static Happy instance;

  return &instance;
}

void Happy::Enter(Miner* pMiner)
{
	//display happy image
	printf("happy state entered\n");
}


void Happy::Execute(Miner* pMiner)
{
	if(pMiner->joy>0.6){
		pMiner->ChangeState(Happy::Instance());
	}else{
		pMiner->ChangeState(Wander::Instance());
	}

  

}


void Happy::Exit(Miner* pMiner)
{

}