#ifndef STATE_H
#define STATE_H
/** State.H - State class definition
* @class State class
* @brief template state class for the Agent
* @author Ben Porter
*/

class Miner;

class State
{
public:

  virtual ~State(){}

  //this will execute when the state is entered
  virtual void Enter(Miner*)=0;

  //this is the state's normal update function
  virtual void Execute(Miner*)=0;

  //this will execute when the state is exited.
  virtual void Exit(Miner*)=0;

};

#endif