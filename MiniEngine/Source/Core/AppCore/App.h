#pragma once

#include "Window.h"

class App
{
public:
	/** Default constructor. */
	App();

	/** Default destructor. */
	~App();

	/** Initializes the application. */
	void AppInit();

	/** Shuts down the application. */
	void AppExit();

	/** Handle event messaging */
	void ProcessEvents();

	void DisplayWindow();

	void Clear();

	inline bool IsWindowOpen() const
	{
		return m_Window->GetWindow()->isOpen();
	}

private:
	/** Pointer to the application window. */
	std::shared_ptr<Window> m_Window;

	/** Handle to the system time. */
	sf::Clock m_Clock;
};