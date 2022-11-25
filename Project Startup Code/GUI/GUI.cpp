#include "GUI.h"

GUI::GUI()
{
	//Initialize user interface parameters
	InterfaceMode = MODE_DRAW;

	width = 1300;
	height = 700;
	wx = 5;
	wy = 5;


	StatusBarHeight = 50;
	ToolBarHeight = 50;
	MenuIconWidth = 80;

	DrawColor = BLUE;	//default Drawing color
	FillColor = GREEN;	//default Filling color
	MsgColor = BLACK;		//Messages color
	BkGrndColor = WHITE;	//Background color
	HighlightColor = MAGENTA;	//This color should NOT be used to draw shapes. use if for highlight only
	StatusBarColor = LIGHTSEAGREEN;
	PenWidth = 3;	//default width of the shapes frames


	//Create the output window
	pWind = CreateWind(width, height, wx, wy);
	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - PAINT ^ ^ PLAY - - - - - - - - - -");

	CreateDrawToolBar();
	CreateStatusBar();
}




//======================================================================================//
//								Input Functions										//
//======================================================================================//
void GUI::GetPointClicked(window & testWindow) const
{
	int iX, iY;
	testWindow.SetBuffering(true);
	clicktype ctInput;
	testWindow.FlushMouseQueue();
	ctInput = testWindow.GetMouseClick(iX, iY);
	testWindow.UpdateBuffer();
	testWindow.SetBuffering(false);
}

string GUI::GetSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE )
			return "";	
		if (Key == 13)	
			return Label;
		if (Key == 8)	
			if( Label.size() > 0)	
				Label.resize(Label.size() - 1);
			else
				Key = '\0';		
		else
			Label += Key;
		PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired operation
operationType GUI::GetUseroperation() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	

	if (InterfaceMode == MODE_DRAW)	
	{
		
		if (y >= 0 && y < ToolBarHeight)
		{
		
			int ClickedIconOrder = (x / MenuIconWidth);

			switch (ClickedIconOrder)
			{
			case ICON_RECT: return DRAW_RECT;
			case ICON_CIRC: return DRAW_CIRC;
			case ICON_EXIT: return EXIT;
			case ICON_OVAL: return DRAW_OVAL;
			case ICON_LINE: return DRAW_LINE;
			case ICON_IRREGULAR: return DRAW_IRREGULAR;
			case ICON_REGULAR:	return DRAW_REGULAR;
			case ICON_SQUA: return DRAW_SQUA;
			case ICON_TRIANGLE: return DRAW_TRI;
			case ICON_FILL: return FILL ;
			case ICON_SELECT: return SELECT;
			case ICON_DEl: return DEL;
			case ICON_SAVE: return SAVE;
			case ICON_SWITCH: return SWITCH;
			case ICON_COLOR_PALETTE: return COLOR_PALETTE;		
			default: return EMPTY;	
			}
		}

		
		if (y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return DRAWING_AREA;
		}


		return STATUS;
	}
	else	
	{
		
		return TO_PLAY;	//just for now. This should be updated
	}

}
////////////////////////////////////////////////////



//======================================================================================//
//								Output Functions										//
//======================================================================================//

window* GUI::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(BkGrndColor);
	pW->SetPen(BkGrndColor, 1);
	pW->DrawRectangle(0, ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateStatusBar() const
{
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateDrawToolBar() 
{
	InterfaceMode = MODE_DRAW;
	string MenuIconImages[DRAW_ICON_COUNT];
	MenuIconImages[ICON_RECT] = "images\\MenuIcons\\REC.jpg";
	MenuIconImages[ICON_CIRC] = "images\\MenuIcons\\CIRCLE.jpg";
	MenuIconImages[ICON_OVAL] = "images\\MenuIcons\\OVAL.jpg";
	MenuIconImages[ICON_LINE] = "images\\MenuIcons\\LINE.jpg";
	MenuIconImages[ICON_IRREGULAR] = "images\\MenuIcons\\irregular shapes.jpg";
	MenuIconImages[ICON_REGULAR] = "images\\MenuIcons\\REG.jpg";
	MenuIconImages[ICON_SQUA] = "images\\MenuIcons\\SQA.jpg";
	MenuIconImages[ICON_TRIANGLE] = "images\\MenuIcons\\OIP.jpg";
	MenuIconImages[ICON_FILL] = "images\\MenuIcons\\fill.jpg";
	MenuIconImages[ICON_SELECT] = "images\\MenuIcons\\select.jpg";
	MenuIconImages[ICON_DEl] = "images\\MenuIcons\\Delete.jpg";
	MenuIconImages[ICON_SAVE] = "images\\MenuIcons\\save.jpg";
	MenuIconImages[ICON_SWITCH] = "images\\MenuIcons\\s.jpg";
	MenuIconImages[ICON_EXIT] = "images\\MenuIcons\\EXIT.jpg";
	MenuIconImages[ICON_COLOR_PALETTE] = "images\\MenuIcons\\COLOR_PALETTE.jpg";
	for (int i = 0; i < DRAW_ICON_COUNT; i++)
		pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);

}
void GUI::CreatePlayToolBar() 
{
	InterfaceMode = MODE_PLAY;
	string MenuIconImages[DRAW_ICON_COUNT];
	MenuIconImages[ICON_START] = "images\\MenuIcons\\R.jpg";
	MenuIconImages[ICON_RESTART] = "images\\MenuIcons\\restart.jpg";
	MenuIconImages[ICON_SWITCH] = "images\\MenuIcons\\s.jpg";
	MenuIconImages[ICON_EXIT] = "images\\MenuIcons\\EXIT.jpg";
	for (int i = 0; i < DRAW_ICON_COUNT; i++)
		pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);

}

void GUI::ClearDrawArea() const
{
	pWind->SetPen(BkGrndColor, 1);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(0, ToolBarHeight, width, height - StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(MsgColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, height - (int)(0.75 * StatusBarHeight), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntDrawColor() const	//get current drwawing color
{
	int x, y;
	pWind->SetBuffering(true);
	pWind->FlushMouseQueue();
	pWind->FlushKeyQueue();

	// Loop until there is a mouse click
	while (pWind->GetMouseClick(x, y) == NO_CLICK)
	{
		double dRed, dGreen, dBlue;
		pWind->GetMouseCoord(x, y);
		pWind->GetColor(x, y, dRed, dGreen, dBlue);
		pWind->UpdateBuffer();
	}
	pWind->SetBuffering(false);
	return DrawColor;
}

color GUI::getCrntFillColor() const	//get current filling color
{
	int x, y;
	pWind->SetBuffering(true);
	pWind->FlushMouseQueue();
	pWind->FlushKeyQueue();

	// Loop until there is a mouse click
	while (pWind->GetMouseClick(x, y) == NO_CLICK)
	{
		double dRed, dGreen, dBlue;
		pWind->GetMouseCoord(x, y);
		pWind->GetColor(x, y, dRed, dGreen, dBlue);
		pWind->UpdateBuffer();
	}
	pWind->SetBuffering(false);
	return FillColor;
}


int GUI::getCrntPenWidth() const		
{
	return PenWidth;
}

//======================================================================================//
//								shapes Drawing Functions								//
//======================================================================================//

void GUI::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const
{
	color DrawingClr;
	if (RectGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}


//////////////////////////////////////////////////////////////////////////////////////////
GUI::~GUI()
{
	delete pWind;
}

