#include "stdafx.h"
#include "Entity.h"

Entity::Entity(SDL_Renderer* renderer)
{
	m_texture = nullptr;
	m_renderer = renderer;
	m_position = Vec2::zeroVector;
	m_texWdith = 0;
	m_texHeight = 0;
	m_drawOrder = 0;
	m_scale = 1.0f;
	m_rotation = 0.0f;
	m_mass = 0.0f;
	m_speed = 0.0f;
	m_force = 0.0f;
	m_turnRate = 0.0f;
	m_radius = 0.0f;
}

Entity::~Entity()
{
	m_texture = nullptr;
	m_renderer = nullptr;
}

void Entity::Initialize()
{
	
}

void Entity::Update(float deltaTime)
{

}

void Entity::Draw()
{
	if (m_texture)
	{
		SDL_Rect rect;
		rect.w = (m_texWdith * m_scale);
		rect.h = (m_texHeight * m_scale);
		rect.x = (m_position.x - rect.w / 2);
		rect.y = (m_position.y - rect.h / 2);

		SDL_QueryTexture(m_texture, nullptr, nullptr, &rect.w, &rect.h);

		SDL_RenderCopyEx(
			m_renderer,
			m_texture,
			nullptr,
			&rect,
			m_rotation,
			nullptr,
			SDL_FLIP_NONE);
	}
}

void Entity::CreateTexture(const std::string& filePath)
{
	SDL_Surface* surface = IMG_Load(filePath.c_str());
	if (surface == nullptr)
	{
		std::cout << "Unable to load a texture file " << filePath.c_str() << std::endl;
	}

	m_texture = SDL_CreateTextureFromSurface(m_renderer, surface);
	SDL_FreeSurface(surface);
	if (m_texture == nullptr)
	{
		std::cout << "Failed to create texture for " << filePath.c_str() << std::endl;
	}
}

bool Entity::Intersect(const Entity& otherEntity)
{
	Vec2 diff = this->GetPosition() - otherEntity.GetPosition();
	float distSq = diff.SizeSquared();

	float radiusSq = this->m_scale * this->m_radius + otherEntity.m_scale * otherEntity.m_radius;
	radiusSq *= radiusSq;
	return distSq <= radiusSq;
}

void Entity::SetPosition(Vec2 newPosition)
{
	m_position = newPosition;
}
