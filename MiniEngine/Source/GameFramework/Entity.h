#pragma once

namespace Engine
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		void SetObjectID(int NewObjectID);

		FORCEINLINE int GetObjectID() const { return m_ObjectID; }
		FORCEINLINE sf::Vector2f GetVelocity() const { return m_Velocity; }

	private:
		int m_ObjectID;
		sf::Vector2f m_Velocity;
	};
}