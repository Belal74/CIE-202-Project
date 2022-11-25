#pragma once

#include "Shapes/Shape.h"
class line :public shape
{
private:
	Point Corner1;
	Point Corner2;
public:
	line(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~line();
	virtual void Draw(GUI* pUI) const;
};