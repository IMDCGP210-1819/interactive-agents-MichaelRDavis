#pragma once

namespace Engine
{
	class Entity;

	class World
	{
	public:
		World();
		~World();

		virtual void Initialize();
		virtual void Update();
		virtual void Render();

		inline const std::vector<Entity*> GetEntities() const { return m_Entities; }

	private:
		std::vector<Entity*> m_Entities;
	};
}