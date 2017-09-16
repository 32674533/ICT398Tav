		/** MyEventReceiver.cpp - Receives events and handles them
        * @class MyEventReceiver class
        * @brief contains code that handles any events that occur
		* @TODO implement event handling for a key press and left-click
        * @author Jonathan Sands
        * modified 16/09/2017
        */
#include <irrlicht.h>
using namespace irr;
class MyEventReceiver : public IEventReceiver
{
public:
    // This is the one method that we have to implement
    virtual bool OnEvent(const SEvent& event)
    {
        // Remember whether each key is down or up
        if (event.EventType == irr::EET_KEY_INPUT_EVENT)
            KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
		
		if(event.EventType == irr::EET_MOUSE_INPUT_EVENT) 
		{ 
			//left mouse button 
			if (event.MouseInput.Event == EMIE_LMOUSE_PRESSED_DOWN) 
			{ 
				KeyIsDown[KEY_LBUTTON] = 1;//on  
			} 
			if (event.MouseInput.Event == EMIE_LMOUSE_LEFT_UP) 
			{ 
				KeyIsDown[KEY_LBUTTON] = 0;//off 
			} 

			//right mouse button 
			if (event.MouseInput.Event == EMIE_MMOUSE_PRESSED_DOWN) 
			{ 
				KeyIsDown[KEY_MBUTTON] = 1;//on  
			} 
			if (event.MouseInput.Event == EMIE_MMOUSE_LEFT_UP) 
			{ 
				KeyIsDown[KEY_MBUTTON] = 0;//off  
			} 

			//right mouse button 
			if (event.MouseInput.Event == EMIE_RMOUSE_PRESSED_DOWN) 
			{ 
				KeyIsDown[KEY_RBUTTON] = 1;//on 
			} 
			if (event.MouseInput.Event == EMIE_RMOUSE_LEFT_UP) 
			{ 
				KeyIsDown[KEY_RBUTTON] = 0;//off 
			}
		}

        return false;
    }

    // This is used to check whether a key is being held down
    virtual bool IsKeyDown(EKEY_CODE keyCode) const
    {
        return KeyIsDown[keyCode];
    }

    MyEventReceiver()
    {
        for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
            KeyIsDown[i] = false;
    }

private:
    // We use this array to store the current state of each key
    bool KeyIsDown[KEY_KEY_CODES_COUNT];
};