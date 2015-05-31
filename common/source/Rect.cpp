#include "stdafx.h"
#include "Rect.h"

using namespace ex04_Design::chapter3;

RECT::RECT()
	: left(0)
	, top(0)
	, right(0)
	, bottom(0)
{}

RECT::RECT(int left, int top, int right, int bottom)
	: left(left)
	, top(top)
	, right(right)
	, bottom(bottom)
{}
