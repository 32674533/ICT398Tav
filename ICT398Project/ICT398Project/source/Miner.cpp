#include "Miner.h"
#include "MinerOwnedStates.h"

Miner::Miner(int id):BaseGameEntity(id),
                     m_pCurrentState(Wander::Instance())
                                                                  
{
	anger = 0.4;
	joy = 0.9;
	trust = 0.7;
	anticipation = 0.4;
	fear = 0.4;
	surprise = 0.5;
	sadness= 0.3;
	disgust = 0.5;
	SetMatrix();

}

Miner::Miner(){

}

void Miner::SetFCM(mat A, mat W){
	map.SetMatrixA(A);
	map.SetMatrixW(W);

}

//--------------------------- ChangeState -------------------------------------
//-----------------------------------------------------------------------------
void Miner::ChangeState(State* pNewState)
{
  //make sure both states are both valid before attempting to 
  //call their methods
	//so this is where the decision making would go in
	//joy, trust, fear, surprise, sadness, disgust, anger, anticipation

	 //If statements determining what states to go to if the values are at set thingoes

	 //pMiner->ChangeState(EnterMineAndDigForNugget::Instance());
  assert (m_pCurrentState && pNewState);

  //call the exit method of the existing state
  m_pCurrentState->Exit(this);
 // m_pCurrentState = (Wander::Instance());
  


  //change state to the new state
  m_pCurrentState = pNewState;

  //call the entry method of the new state
  m_pCurrentState->Enter(this);
}

//-----------------------------------------------------------------------------
void Miner::Update()
{
  //idk put stuff here that you want to change each loop through
	
	//m_pCurrentState->Execute(Flee);
	anger = map.GetMatrixA(0, 0);
	 joy= map.GetMatrixA(0, 1);
	 trust= map.GetMatrixA(0, 2);
	 anticipation= map.GetMatrixA(0, 3);
	 fear= map.GetMatrixA(0, 4);
	 surprise= map.GetMatrixA(0, 5);
	 sadness= map.GetMatrixA(0, 6);
	 disgust= map.GetMatrixA(0, 7);
	map.NewMatrix();
  if (m_pCurrentState)
  {
    m_pCurrentState->Execute(this);
  }
}


void Miner::MinerCreateBody(GameObject& bod){
	//body = new GameObject(model, x, y, z, initMass, smgr, colWorld, devic);
	//need to test this actually works
	body = &bod;
	//body(bod);
	//just pretend I was bothered to make an overloaded operator for =

}


//NEEDS ACTUAL VALUES INPUT
void Miner::SetMatrix(){	
	map.FillMatrixW(0, 0, joy);
	map.FillMatrixW(0, 1, trust);
	map.FillMatrixW(0, 2, fear);
	map.FillMatrixW(0, 3, surprise);
	map.FillMatrixW(0, 4, sadness);
	map.FillMatrixW(0, 5, disgust);
	map.FillMatrixW(0, 6, anger);
	map.FillMatrixW(0, 7, anticipation);
	//ones through the middle are 0 ie, emotions have no effect on themselves
	map.FillMatrixW(0, 0, 0);
	map.FillMatrixW(1, 1, 0);
	map.FillMatrixW(2, 2, 0);
	map.FillMatrixW(3, 3, 0);
	map.FillMatrixW(4, 4, 0);
	map.FillMatrixW(5, 5, 0);
	map.FillMatrixW(6, 6, 0);
	map.FillMatrixW(7, 7, 0);

	//BELOW NEEDS THEIR IMPACTS ON EACH OTHER FILLED OUT
	//joy
	//joy, trust, fear, surprise, sadness, disgust, anger, anticipation
	map.FillMatrixW(0, 1, 0.5);
	map.FillMatrixW(0, 2, 0);
	map.FillMatrixW(0, 3, -0.5);
	map.FillMatrixW(0, 4, -1);
	map.FillMatrixW(0, 5, -0.25);
	map.FillMatrixW(0, 6, 0);
	map.FillMatrixW(0, 7, 0.5);

	//trust
	//joy, trust, fear, surprise, sadness, disgust, anger, anticipation
	map.FillMatrixW(1, 0, 0.5);
	map.FillMatrixW(1, 2, 0.5);
	map.FillMatrixW(1, 3, 0);
	map.FillMatrixW(1, 4, -0.5);
	map.FillMatrixW(1, 5, -1);
	map.FillMatrixW(1, 6, -0.5);
	map.FillMatrixW(1, 7, 0);
	
	//fear
	//joy, trust, fear, surprise, sadness, disgust, anger, anticipation
	map.FillMatrixW(2, 0, 0);
	map.FillMatrixW(2, 1, 0.5);
	map.FillMatrixW(2, 3, 0.5);
	map.FillMatrixW(2, 4, 0);
	map.FillMatrixW(2, 5, -0.5);
	map.FillMatrixW(2, 6, -1);
	map.FillMatrixW(2, 7, -0.5);

	//surprise
	//joy, trust, fear, surprise, sadness, disgust, anger, anticipation
	map.FillMatrixW(3, 0, -0.5);
	map.FillMatrixW(3, 1, 0);
	map.FillMatrixW(3, 2, 0.5);
	map.FillMatrixW(3, 4, 0.5);
	map.FillMatrixW(3, 5, 0);
	map.FillMatrixW(3, 6, -0.5);
	map.FillMatrixW(3, 7, -1);

	//sadness
	//joy, trust, fear, surprise, sadness, disgust, anger, anticipation
	map.FillMatrixW(4, 0, -1);
	map.FillMatrixW(4, 1, -0.5);
	map.FillMatrixW(4, 2, 0);
	map.FillMatrixW(4, 3, 0.5);
	map.FillMatrixW(4, 5, 0.5);
	map.FillMatrixW(4, 6, 0);
	map.FillMatrixW(4, 7, -0.5);

	//disgust
	//joy, trust, fear, surprise, sadness, disgust, anger, anticipation
	map.FillMatrixW(5, 0, -0.5);
	map.FillMatrixW(5, 1, -1);
	map.FillMatrixW(5, 2, -0.5);
	map.FillMatrixW(5, 3, 0);
	map.FillMatrixW(5, 4, 0.5);
	map.FillMatrixW(5, 6, 0.5);
	map.FillMatrixW(5, 7, 0);

	//anger
	//joy, trust, fear, surprise, sadness, disgust, anger, anticipation
	map.FillMatrixW(6, 0, 0);
	map.FillMatrixW(6, 1, -0.5);
	map.FillMatrixW(6, 2, -1);
	map.FillMatrixW(6, 3, -0.5);
	map.FillMatrixW(6, 4, 0);
	map.FillMatrixW(6, 5, 0.5);
	map.FillMatrixW(6, 7, 0.5);

	//anticipation
	//joy, trust, fear, surprise, sadness, disgust, anger, anticipation
	map.FillMatrixW(7, 0, 0.5);
	map.FillMatrixW(7, 1, 0);
	map.FillMatrixW(7, 2, 0.5);
	map.FillMatrixW(7, 3, -1);
	map.FillMatrixW(7, 4, -0.5);
	map.FillMatrixW(7, 5, 0);
	map.FillMatrixW(7, 6, -0.5);


}
//repurpose to teleportation?
void Miner::MoveToward(float tarx, float tary, float tarz){
	body->setPos(tarx, tary, tarz);
	//int targetPos;
	//int moveSpeed = 5;
	//NPC.GetGameObject()->setPos(NPC.GetGameObject()->getPosx()+moveSpeed, NPC.GetGameObject()->getPosy()+moveSpeed, NPC.GetGameObject()->getPosz()+moveSpeed);
	
}
//use this to show a message above the agent's head?
void Miner::PresentMessage(std::string message){

	//code to make a message appear above the agent's head
	//probs gonna need irrilicht for this or change up gameobject-yet to decide
}

bool Miner::SitOn(){
	
	for(int i=0;i<worldObjects->size();i++){
		//this is the stupidest way to get things from the map and yet the normal way of worldObjects[i].method doesn't work
		//long if statement basically checking if the target is within 100 units
		if((worldObjects[i].at(i).getPosx()-body->getPosx() < 50 || worldObjects[i].at(i).getPosx()-body->getPosx() >-50)&& (worldObjects[i].at(i).getPosz()-body->getPosz() < 50 || worldObjects[i].at(i).getPosz()-body->getPosz() >-50))
		
			if(worldObjects[i].at(i).GetAfford().GetSit()==true){
				//basically put the agent on top of the target - maybe have some affect on emotions if it fails
				body->setPos(worldObjects[i].at(i).getPosx(), worldObjects[i].at(i).getPosy()+40, worldObjects[i].at(i).getPosz());
				return true;
			}
		
	}
	return false;
}

void Miner::SetWorldObjects(std::map<int, GameObject&> *world){
	worldObjects = world;

}

bool Miner::PickUp(){
	//teleport said object onto agent's head?

	for(int i=0;i<worldObjects->size();i++){
		//this is the stupidest way to get things from the map and yet the normal way of worldObjects[i].method doesn't work
		//long if statement basically checking if the target is within 100 units, y is not checked due to the world being flat
		if((worldObjects[i].at(i).getPosx()-body->getPosx() < 50 || worldObjects[i].at(i).getPosx()-body->getPosx() >-50)&& (worldObjects[i].at(i).getPosz()-body->getPosz() < 50 || worldObjects[i].at(i).getPosz()-body->getPosz() >-50))
		//just checking if they are strong enough to pick it up/if it can be picked up
			if((worldObjects[i].at(i).GetAfford().GetPickUp()==true)&&worldObjects[i].at(i).GetAfford().GetWeight()<body->GetAfford().GetStrength()){
				//basically put the agent on top of the target - maybe have some affect on emotions if it fails
				worldObjects[i].at(i).setPos(body->getPosx(), body->getPosy()+30,body->getPosz());  
				return true;
			}
		
	}
	return false;
}