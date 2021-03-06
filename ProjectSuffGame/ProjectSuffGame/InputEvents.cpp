#include "InputEvents.h"
#include "Debug.h"
#include "Display.h"

std::vector<VController*> InputEvents::inputs;

bool InputEvents::running = true;
SDL_Event InputEvents::e;

//--------------------------------------------------
// Processes and updates all input from events.
//--------------------------------------------------
void InputEvents::Process()
{
	// Poll Events
	while (SDL_PollEvent(&e) != 0)
	{
		// WindowEvents
		if (e.type == SDL_WINDOWEVENT)
		{
			switch (e.window.event)
			{
			case SDL_WINDOWEVENT_CLOSE:
				// Close Program
				running = false;
				break;

			case SDL_WINDOWEVENT_FOCUS_GAINED:
				// TODO make focus gain flag
				LOG("::Focus Gained");
				break;

			case SDL_WINDOWEVENT_FOCUS_LOST:
				// TODO make focus loss flag
				LOG("::Focus Lost");
				break;

			case SDL_WINDOWEVENT_SIZE_CHANGED:
				// Change the Context Size
				Display::SetupGLDisplay();
				break;
			}
		}

		// Input devices' Events
		int size = inputs.size();
		for (int i = 0; i < size; i++)
			{ inputs[i]->ProcessEvent(e); }
	}
}
