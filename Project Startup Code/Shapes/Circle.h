#pragma once
#include "shapes/Shape.h"
class Circle :
    public shape
{
private:
	Point Center;
	Point radius;
public:
	Circle(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Circle();
	virtual void Draw(GUI* pUI) const;
};

