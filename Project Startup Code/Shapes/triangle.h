#pragma once
#include "Shapes/Shape.h"
class triangle : public shape
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	triangle(Point, Point, Point, GfxInfo shapeGfxInfo);
	virtual ~triangle();
	virtual void Draw(GUI* pUI) const;
};

