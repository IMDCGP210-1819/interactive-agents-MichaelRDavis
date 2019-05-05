#pragma once

#include "Math/Vector.h"

class World;

/**
 * Entity is the base class for all game objects in the game world.
 */
class Entity
{
public:
	/** Default Entity constructor. */
	Entity(SDL_Renderer* renderer);

	/** Default Entity destructor. */
	virtual ~Entity();

	/** Initialize the entity. */
	virtual void Initialize();

	/** Update this entity, called once per frame. */
	virtual void Update(float deltaTime);

	/** Submit this entity to the renderer. */
	virtual void Draw();

	/** Creates a texture for this entity. */
	void CreateTexture(const std::string& filePath);

	/** Detects collision with another entity. */
	bool Intersect(const Entity& otherEntity);

	void Constrain(Vec2& position, int32_t viewWidth, int32_t viewHeight);

	void Enable();
	void Disable();

	inline bool GetIsActive() const
	{
		return m_isActive;
	}

	void SetPosition(Vec2 newPosition);

	inline SDL_Texture* GetTexture() const
	{
		return m_texture;
	}

	inline Vec2 GetPosition() const
	{
		return m_position;
	}

	inline float GetScale() const
	{
		return m_scale;
	}

	inline float GetRotation() const
	{
		return m_rotation;
	}

	inline World* GetWorld() const
	{
		return m_world;
	}

protected:
	/** Texture for this entity. */
	SDL_Texture* m_texture;

	/** Cached pointer to the renderer object. */
	SDL_Renderer* m_renderer;

	/** Pointer to the world object. */
	World* m_world;

	/** Position of this entity in 2D space. */
	Vec2 m_position;

	/** Velocity of the entity in 2D space. */
	Vec2 m_velocity;

	/** Width of the entities texture. */
	int32_t m_texWdith;

	/** Height of this entities texture. */
	int32_t m_texHeight;

	/** Draw order of the sprite. */
	int32_t m_drawOrder;

	/** Scale of this entity texture.. */
	float m_scale;

	/** Rotation of the entity. */
	float m_rotation;

	/** Mass of the entity. */
	float m_mass;

	/** Speed of the entity. */
	float m_speed;

	/** Max speed of this entity. */
	float m_maxSpeed;

	/** Force of the entity. */
	float m_force;

	/** Turn rate of the entity. */
	float m_turnRate;

	/** Radius of this entities collision. */
	float m_radius;

	/** Flag to active this entity. */
	bool m_isActive;
};
