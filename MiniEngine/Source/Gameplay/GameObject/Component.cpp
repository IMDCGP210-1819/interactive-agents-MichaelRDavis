#include "MiniPCH.h"
#include "Component.h"

Component::Component()
{

}

Component::~Component()
{

}

void Component::Update(float DeltaTime)
{

}

void Component::SetOwner(std::shared_ptr<Entity> NewOwner)
{
	m_Owner = NewOwner;
}

