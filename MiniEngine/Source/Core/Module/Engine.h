#pragma once

class App;
class Renderer;

class Engine
{
public:
	/** Default constructor. */
	Engine();

	/** Default destructor. */
	virtual ~Engine();

	/** Update everything, called once per frame. */
	virtual void Update(float DeltaTime);

protected:
	/** Pointer to the core application. */
	std::unique_ptr<App> m_App;

	/** Pointer to the renderer. */
	std::unique_ptr<Renderer> m_Renderer;
};