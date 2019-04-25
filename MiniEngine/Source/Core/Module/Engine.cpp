#include "MiniPCH.h"
#include "Engine.h"
#include "Core/AppCore/App.h"
#include "Rendering/Renderer.h"

Engine::Engine()
{
	m_App = std::make_unique<App>();
	m_Renderer = std::make_unique<Renderer>();
	m_Renderer->Init(m_App->GetWindow()->GetWindowHandle());
}

Engine::~Engine()
{

}

void Engine::Update(float DeltaTime)
{
	m_App->ProcessEvents();
}
