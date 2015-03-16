#include "Father.h"


Father::Father()
{
	SetPosition(SGD::Point{100.0f,200.0f});
	CreateFrames();
}


Father::~Father()
{
}
void Father::CreateFrames()
{
	
	frames.push_back({ { 0, 22, 45, 95 }, { 22, 90 } });
	frames.push_back({ { 44, 22, 85, 95 }, { 22, 90 } });
	frames.push_back({ { 84, 22, 117, 95 }, { 22, 90 } });
	frames.push_back({ { 118, 22, 162, 95 }, { 22, 90 } });
	frames.push_back({ { 163, 22, 215, 95 }, { 22, 90 } });
}

void Father::BackPack()
{

}

void	 Father::Update(float elapsedTime)
{
	if (SGD::InputManager::GetInstance()->IsKeyDown(SGD::Key::RightArrow))
	{
		if (frameswitch >= 0.07f)
		{
			direction++;
			frameswitch = 0.0f;
		}
		m_vtVelocity.x =64.0f;
		Actor::Update(elapsedTime);

	}
	if (direction > 4)
		direction = 0;
	frameswitch += elapsedTime;


}
void	 Father::Render(void)
{
	SGD::Rectangle frame = frames[direction].rFrame;

	SGD::GraphicsManager::GetInstance()->DrawTextureSection(m_hImage,
	{ m_ptPosition.x, m_ptPosition.y },
	frame, 0.0f, {}, { 255, 255, 255 }, SGD::Size{ GetSize().width, GetSize().height });
}

SGD::Rectangle  Father::GetRect(void)	const
{
	return SGD::Rectangle{ 10.0f, 0.0f, 0.0f, 0.0f };
}
void	 Father::HandleCollision(const IEntity* pOther)
{

}
