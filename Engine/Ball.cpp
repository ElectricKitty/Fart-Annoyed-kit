#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(Vec2& pos_in, Vec2& vel_in)
	:
	pos(pos_in),
	vel(vel_in)
{
}

void Ball::Draw(Graphics& gfx) const
{
	SpriteCodex::DrawBall(pos, gfx);
}

void Ball::ReboundX()
{
	vel.x = -vel.x;
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
}

bool Ball::DoWallColision(RectF& walls)
{
	bool colided = false;
	RectF hitbox = GetRect();
	if (hitbox.left < walls.left)
	{
		pos.x += walls.left - hitbox.left;
		ReboundX();
		colided = true;
	}
	else if (hitbox.right > walls.right)
	{
		pos.x -= hitbox.right - walls.right;
		ReboundX();
		colided = true;
	}
	if (hitbox.top < walls.top)
	{
		pos.y += walls.top - hitbox.top;
		ReboundY();
		colided = true;
	}
	else if (hitbox.bottom > walls.bottom)
	{
		pos.y -= hitbox.bottom - walls.bottom;
		ReboundY();
		colided = true;
	}
	return colided;
}

RectF Ball::GetRect() const
{
	return RectF::FromCenter(pos, radius, radius);
}

void Ball::update(float dt)
{
	pos += vel * dt;
}
