#pragma once
#include "shapes/Shape.h"
class Oval :
    public shape
{
private:
	Point Point1;
	Point Point2;
public:
	Oval(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Oval();
	virtual void Draw(GUI* pUI) const;
};

