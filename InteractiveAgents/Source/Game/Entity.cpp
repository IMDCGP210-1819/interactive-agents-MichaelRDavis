#include "Entity.h"
#include "World.h"
#include <SDL_image.h>

Entity::Entity(World* world)
	: m_world(world)
{
	m_texture = nullptr;
	m_texWidth = 0;
	m_texHeight = 0;
	m_drawOrder = 0;
	m_scale = 1.0f;
	m_rotation = 0.0f;
	m_speed = 0.0f;
	m_mass = 1.0f;
	m_collisionRadius = 0.0f;
}

Entity::~Entity()
{
	m_texture = nullptr;
	m_world = nullptr;
}

void Entity::Update(float deltaTime)
{

}

void Entity::Draw()
{
	if (m_texture)
	{
		SDL_Rect rect;
		rect.w = static_cast<int32_t>(m_texWidth * m_scale);
		rect.h = static_cast<int32_t>(m_texHeight * m_scale);
		rect.x = static_cast<int32_t>(m_position.x - rect.w / 2);
		rect.y = static_cast<int32_t>(m_position.y - rect.h / 2);

		SDL_QueryTexture(m_texture, nullptr, nullptr, &rect.w, &rect.h);

		SDL_RenderCopyEx(
			m_world->GetRenderer(),
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

	m_texture = SDL_CreateTextureFromSurface(m_world->GetRenderer(), surface);
	SDL_FreeSurface(surface);
	if (m_texture == nullptr)
	{
		std::cout << "Failed to create texture for " << filePath.c_str() << std::endl;
	}
}

bool Entity::Intersect(const Entity& otherEntity)
{
	Vector2f diff = this->GetPosition() - otherEntity.GetPosition();
	float distSq = diff.lengthSq();

	float radiusSq = this->m_scale * this->m_collisionRadius + otherEntity.m_scale * otherEntity.m_collisionRadius;
	radiusSq *= radiusSq;
	return distSq <= radiusSq;
}

void Entity::Constrain(Vector2f& position, int32_t width, int32_t height)
{
	if (position.x > width)
	{
		position.x = 0.0f;
	}

	if (position.x < 0.0f)
	{
		position.x = static_cast<float>(width);
	}

	if (position.y > height)
	{
		position.y = 0.0f;
	}

	if (position.y < 0.0f)
	{
		position.y = static_cast<float>(height);
	}
}

void Entity::SetPosition(Vector2f newPosition)
{
	m_position = newPosition;
}

void Entity::SetVelocity(Vector2f newVelocity)
{
	m_velocity = newVelocity;
}

void Entity::SetRotation(float newRotation)
{
	m_rotation = newRotation;
}

void Entity::SetScale(float newScale)
{
	m_scale = newScale;
}

void Entity::SetMass(float newMass)
{
	m_mass = newMass;
}

void Entity::SetSpeed(float newSpeed)
{
	m_speed = newSpeed;
}

void Entity::SetCollisionRadius(float newRadius)
{
	m_collisionRadius = newRadius;
}
