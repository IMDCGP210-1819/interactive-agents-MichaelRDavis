#pragma once

#include "Math/Vector.h"

class World;
class Component;

/**
 * Entity is the base class for all game objects in the game world.
 */
class Entity
{
public:
	/** Default Entity constructor. */
	Entity();

	/** Default Entity destructor. */
	virtual ~Entity();

	/** Initialize the entity. */
	virtual void Initialize() = 0;

	/** Update this entity, called once per frame. */
	virtual void Update(float DeltaTime) = 0;

	/** Submit this entity to the renderer. */
	virtual void Render() = 0;

	/** Set the entities ID. */
	void SetObjectID(int NewObjectID);

	/** Returns the entities ID. */
	inline int GetObjectID() const { return m_ObjectID; }

	/** Returns this entities velocity. */
	inline Vec2 GetVelocity() const { return m_Velocity; }

protected:
	/** Name of this entity. */
	std::string m_Typename;

	/** Pointer the game world. */
	std::shared_ptr<World> m_World;

	/** Velocity of the entity. */
	Vec2 m_Velocity;

	/** Direction of the entity. */
	Vec2 m_Direction;

	/** Dot vector to the directional vector. */
	Vec2 m_DotVector;

	/** Entity ID. */
	int m_ObjectID;

	/** Mass of the entity. */
	float m_Mass;

	/** Speed of the entity. */
	float m_Speed;

	/** Force of the entity. */
	float m_Force;

	/** Turn rate of the entity. */
	float m_TurnRate;
};
