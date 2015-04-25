#include "GameplayState.h"
#include "GameObjects.h"
class Box : public GameObjects
{
private:
	bool isHeavy;
public:
	Box();
	~Box();
	void CalculateVelocity(SGD::Vector _v);
	void SetHeavy(bool _s){ isHeavy = _s; }
	bool GetHeavy(){ return isHeavy; }

	void	Update(float elapsedTime)	;
	void	Render(void)				;

	int		GetType(void)	const				{ return ENT_BOX; }
	SGD::Rectangle GetRect(void)	const		;
	void	HandleCollision(IEntity* pOther)	;

};

