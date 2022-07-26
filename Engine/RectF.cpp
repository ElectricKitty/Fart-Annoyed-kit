#include "RectF.h"
RectF::RectF(float top_in, float bottom_in, float left_in, float right_in)
	:
	top(top_in),
	bottom(bottom_in),
	left(left_in),
	right(right_in)
{
}

RectF::RectF(const Vec2& top_left, const Vec2& bottom_right)
{
	RectF(top_left.x, bottom_right.x, top_left.y, bottom_right.y);
}

RectF::RectF(const Vec2& top_left, float right_in, float bottom_in)
{
	RectF(top_left.x, bottom_in, top_left.y, right_in);
}

bool RectF::OverlapTest(const RectF& other) const
{
	return right > other.left && left < other.right
		&& top > other.bottom && bottom < other.top;
}

RectF RectF::FromCenter(const Vec2& center, float half_y, float half_x)
{
	const Vec2 half(half_x, half_y);
	return RectF(center - half, center + half);
}
