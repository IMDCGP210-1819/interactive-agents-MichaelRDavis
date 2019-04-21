#pragma once

class Entity;

/**
 * 
 */
class Component
{
public:
	/** Default constructor. */
	Component();

	/** Default destructor. */
	virtual ~Component();

	/** Update this component, called once per frame. */
	virtual void Update(float DeltaTime);

	/** Set the owner of this component to a new owner. 
	*	@param NewOwner - Entities new owner.
	*/
	void SetOwner(std::shared_ptr<Entity> NewOwner);

	/** Returns the owner of tis component. */
	inline std::shared_ptr<Entity> GetOwner() const
	{
		return m_Owner;
	}

protected:
	/** Entity that owns this component. */
	std::shared_ptr<Entity> m_Owner;
};