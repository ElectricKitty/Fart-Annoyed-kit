#pragma once
#include "Vec2.h"
#include "RectF.h"
#include "Graphics.h"
#include "SpriteCodex.h"
#include "FrameTimer.h"

class Ball
{
public:
	Ball() = default;
	Ball(Vec2& pos_in, Vec2& vel_in);
	void Draw(Graphics& gfx) const;
	void ReboundX();
	void ReboundY();
	bool DoWallColision(RectF& walls);
	RectF GetRect() const;
	void update(float dt);
private:
	Vec2 pos;
	Vec2 vel;
	static constexpr float radius = 7.0f;
};