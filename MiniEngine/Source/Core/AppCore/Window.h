#pragma once

/**
 * Generic window class, wrapper for a native window.
 */
class Window
{
public:
	/** Window constructor.*/
	Window();

	/** Window destructor. */
	~Window();

	/** Create window. */
	void InitializeWindow();

	/** Destroy window. */
	void DestroyWindow();

	/** Returns the native window. */
	inline SDL_Window* GetWindowHandle() const
	{
		return m_Window;
	}

private:
	/** Pointer to the native window. */
	SDL_Window* m_Window;

	/** Window width. */
	uint32_t m_Width;

	/** Window height; */
	uint32_t m_Height;
};