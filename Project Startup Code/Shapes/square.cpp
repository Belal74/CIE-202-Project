#include "square.h"
square::square(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

square::~square()
{}

void square::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a square on the screen	
	pUI->Drawsquare(Corner1, Corner2, ShpGfxInfo);
}