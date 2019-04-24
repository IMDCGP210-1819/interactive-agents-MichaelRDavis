#pragma once

#include "Window.h"

/**
 * 
 */
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

	/** Display the window to the display. */
	void DisplayWindow();

	/** Clear the window. */
	void Clear();

	/** Returns the application window. */
	inline std::shared_ptr<Window> GetWindow() const
	{
		return m_Window;
	}

private:
	/** Pointer to the application window. */
	std::shared_ptr<Window> m_Window;
};