#pragma once

#include "Core/Math/Vector.h"

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
	virtual void Initialize();

	/** Update this entity, called once per frame. */
	virtual void Update(float DeltaTime);

	/** Submit this entity to the renderer. */
	virtual void Render();

	/** Set the entities ID. */
	void SetObjectID(int NewObjectID);

	/** Returns the entities ID. */
	inline int GetObjectID() const { return m_ObjectID; }

protected:
	/** Name of this entity. */
	std::string m_Typename;

	/** Pointer the game world. */
	std::shared_ptr<World> m_World;

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

	/** Flag to register this entity with the world. */
	bool m_IsRegistered;
};
