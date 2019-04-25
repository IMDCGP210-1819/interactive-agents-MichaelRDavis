#include "stdafx.h"
#include "Entity.h"


Entity::Entity()
	: m_IsRegistered(true)
{
	
}

Entity::~Entity()
{

}

void Entity::Initialize()
{

}

void Entity::Update(float DeltaTime)
{

}

void Entity::Draw(SDL_Renderer* Renderer)
{

}

void Entity::SetObjectID(int NewObjectID)
{
	m_ObjectID = NewObjectID;
}
