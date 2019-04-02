#pragma once

namespace Engine
{
	/**
	 * 
	 */
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		virtual void Initialize() = 0;
		virtual void Update() = 0;
		virtual void Render() = 0;

		void SetObjectID(int NewObjectID);

		inline int GetObjectID() const { return m_ObjectID; }
		inline sf::Vector2f GetVelocity() const { return m_Velocity; }

	private:
		int m_ObjectID;
		sf::Vector2f m_Velocity;
	};
}