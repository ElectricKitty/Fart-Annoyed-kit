#pragma once
#include "Vec2.h"

class RectF
{
public:
	RectF() = default;
	RectF(float top_in, float bottom_in, float left_in, float right_in);
	RectF(const Vec2& top_left, const Vec2& bottom_right);
	RectF(const Vec2& top_left, float toright, float tobottom);
	bool OverlapTest(const RectF& other) const;
	static RectF FromCenter(const Vec2& center, float half_y, float half_x);
public:
	float top;
	float bottom;
	float left;
	float right;
};