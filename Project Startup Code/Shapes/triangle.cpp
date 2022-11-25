#include "triangle.h"
triangle::triangle (Point P1, Point P2, Point P3, GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}

triangle::~triangle()
{}

void triangle ::Draw(GUI* pUI) const
{
	//Call Output::Drawline to draw a line on the screen	
	pUI->Drawtriangle(Corner1, Corner2, Corner3, ShpGfxInfo);
}