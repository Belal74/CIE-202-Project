#include "line.h"
line::line(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

line::~line()
{}

void line::Draw(GUI* pUI) const
{
	//Call Output::Drawline to draw a line on the screen	
	pUI->Drawline(Corner1, Corner2, ShpGfxInfo);
}