#pragma once

#include <vmath.h>
#include <SDL.h>

class World;

class Entity
{
public:
	Entity(World* world);
	~Entity();

	virtual void Update(float deltaTime);
	virtual void Draw();

	void CreateTexture(const std::string& filePath);
	bool Intersect(const Entity& otherEntity);
	void Constrain(Vector2f& position, int32_t width, int32_t height);

	void SetPosition(Vector2f newPosition);
	void SetVelocity(Vector2f newVelocity);
	void SetRotation(float newRotation);
	void SetScale(float newScale);
	void SetMass(float newMass);
	void SetSpeed(float newSpeed);
	void SetCollisionRadius(float newRadius);

	inline World* GetWorld() const { return m_world; }
	inline Vector2f GetPosition() const { return m_position; }
	inline Vector2f GetVelocity() const { return m_velocity; }
	inline float GetRotation() const { return m_rotation; }
	inline float GetScale() const { return m_scale; }
	inline float GetMass() const { return m_mass; }
	inline float GetSpeed() const { return m_speed; }
	inline float GetCollisionRadius() { return m_collisionRadius; }

protected:
	SDL_Texture* m_texture;
	World* m_world;
	Vector2f m_position;
	Vector2f m_velocity;
	int32_t m_texWidth;
	int32_t m_texHeight;
	int32_t m_drawOrder;
	float m_rotation;
	float m_scale;
	float m_mass;
	float m_speed;
	float m_collisionRadius;
};