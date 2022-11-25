#include "Circle.h"

Circle::Circle(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Center = P1;
	radius = P2;
}

Circle::~Circle()
{}

void Circle::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawCircle(Center, radius, ShpGfxInfo);
}