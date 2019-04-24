#pragma once

class Window
{
public:
	Window();

	~Window();

	void InitializeWindow();

	void DestroyWindow();

private:
	int m_Width;
	int m_Height;
};