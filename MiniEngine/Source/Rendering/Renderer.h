#pragma once

class Renderer
{
public:
	/** Default constructor. */
	Renderer();

	/** Default destructor. */
	~Renderer();

	void Init(SDL_Window* Window);

	void SwapBuffers();

	void ClearBuffer();

	inline SDL_Renderer* GetSDLRenderer() const
	{
		return m_Renderer;
	}

private:
	SDL_Renderer* m_Renderer;
};