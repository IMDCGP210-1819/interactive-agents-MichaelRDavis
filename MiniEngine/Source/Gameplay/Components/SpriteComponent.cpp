#include "MiniPCH.h"
#include "SpriteComponent.h"
#include "Resource/ResourceManager.h"
#include "Rendering/SceneGraph/SceneNode.h"

SpriteComponent::SpriteComponent()
{
	m_SpriteManager = std::make_shared<TAssetManager<sf::Texture, int>>();
}

SpriteComponent::SpriteComponent(int SpriteID, std::string Filename)
{
	m_SpriteManager = std::make_shared<TAssetManager<sf::Texture, int>>();
	m_SpriteManager->Load(SpriteID, Filename);
	m_Texture = m_SpriteManager->Get(SpriteID);
	m_Sprite = sf::Sprite(m_Texture);
}

SpriteComponent::~SpriteComponent()
{

}

void SpriteComponent::Draw()
{
	//m_SpriteNode->Draw(m_Sprite, sf::RenderStates)
}

void SpriteComponent::LoadTexture(int SpriteID, std::string FileName)
{
	m_SpriteManager->Load(SpriteID, FileName);
	m_Texture = m_SpriteManager->Get(SpriteID);
	SetTexture(m_Texture);
}

void SpriteComponent::SetTexture(sf::Texture NewTexture)
{
	m_Sprite.setTexture(NewTexture);
}

void SpriteComponent::SetPosition(sf::Vector2f NewPosition)
{
	m_Sprite.setPosition(NewPosition);
}

