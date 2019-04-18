#pragma once

class Window
{
public:
	Window();

	~Window();

	void InitializeWindow();

	void DestroyWindow();

	inline sf::RenderWindow* GetWindow() const
	{
		return m_Window;
	}

private:
	sf::RenderWindow* m_Window;
	int m_Width;
	int m_Height;
};