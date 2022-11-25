#include "Oval.h"

Oval::Oval(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Point1 = P1;
	Point2 = P2;
}

Oval::~Oval()
{}

void Oval::Draw(GUI* pUI) const
{
	//Call Output::DrawOval to draw a Oval on the screen	
	pUI->DrawOval(Point1, Point2, ShpGfxInfo);
}