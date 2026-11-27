#include "output.h"
#include <iostream>
#include "Input.h"

using namespace std;


Output::Output()
{
	// Initialize user interface parameters
	UI.InterfaceMode = MODE_DESIGN;

	// Widths and Heights

	UI.StatusBarHeight = 60;
	UI.ToolBarHeight = 55;
	UI.MenuItemWidth = 55;

	UI.width = 1210; // make it divisible by NumHorizontalCells
	UI.height = 610;
	UI.wx = 5;
	UI.wy = 5;

	UI.CellWidth = UI.width / NumHorizontalCells;
	UI.CellHeight = (UI.height - UI.ToolBarHeight - UI.StatusBarHeight) / NumVerticalCells;

	// Pen Colors of messages of status bar and players' info
	UI.MsgColor = DARKRED;
	UI.PlayerInfoColor = DARKSLATEBLUE;

	// Background Colors of toolbar and statusbar 
	UI.ToolBarColor = WHITE;
	UI.StatusBarColor = LIGHTGRAY;

	// Line Colors of the borders of each cell
	UI.GridLineColor = WHITE;
	UI.GridHighlightColor = DARKRED;

	// Cell Color if Empty & Cell Number Font & Color
	UI.CellColor_NoCard = LIGHTSLATEBLUE;
	UI.CellNumFont = 13;
	UI.CellNumColor = UI.GridLineColor;

	// Cell Color if Has Normal or Chess Card & CARD Code Font & Color
	UI.CellColor_HasNormCard = SALMON;
	UI.CellColor_HasChessCard = MEDIUMSEAGREEN;
	UI.CardCodeFont = 30;
	UI.CardCodeColor = WHITE;

	// Colors of the 4 Players
	UI.PlayerColors[0] = GOLD;
	UI.PlayerColors[1] = DARKBLUE;
	UI.PlayerColors[2] = WHITE;
	UI.PlayerColors[3] = DARKRED;

	// Create the output window
	pWind = CreateWind(UI.width + 15, UI.height, UI.wx, UI.wy);

	// Change the title
	pWind->ChangeTitle("Chess Snakes & Ladders");

	// Create the toolbar, grid area and status bar
	CreateDesignModeToolBar();
	ClearGridArea();
	ClearStatusBar();

}


int Output::GetCellStartX(const CellPosition& cellPos) const
{
	return cellPos.HCell() * UI.CellWidth;
}


int Output::GetCellStartY(const CellPosition& cellPos) const
{
	return UI.ToolBarHeight + cellPos.VCell() * UI.CellHeight;
}


void Output::CreateDesignModeToolBar() const
{
	UI.InterfaceMode = MODE_DESIGN;

	ClearToolBar();

	string MenuItemImages[DESIGN_ITM_COUNT];
	MenuItemImages[ITM_EXIT] = "toolbar_icons\\Menu_Exit.jpg";
	MenuItemImages[ITM_ADD_CARD] = "toolbar_icons\\Menu_Card.jpg";
	MenuItemImages[ITM_SELECT_CARD] = "toolbar_icons\\select_card.jpg";
	MenuItemImages[ITM_COPY_CARD] = "toolbar_icons\\copy.jpg";
	MenuItemImages[ITM_PASTE_CARD] = "toolbar_icons\\paste.jpg";
	MenuItemImages[ITM_DELETE_CARD] = "toolbar_icons\\delete.jpg";
	MenuItemImages[ITM_MOVE_CARD] = "toolbar_icons\\move.jpg";
	MenuItemImages[ITM_SHUFFLE_CARD] = "toolbar_icons\\shuffle.jpg";
	MenuItemImages[ITM_SAVE_GRID] = "toolbar_icons\\save.jpg";
	MenuItemImages[ITM_OPEN_GRID] = "toolbar_icons\\open.jpg";
	MenuItemImages[ITM_SWITCH_TO_PLAY_MODE] = "toolbar_icons\\Menu_SwitchToGame.jpg";

	for (int i = 0; i < DESIGN_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
}


void Output::CreatePlayModeToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;

	ClearToolBar();

	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_EXIT_PLAY] = "toolbar_icons\\Menu_Exit.jpg";
	MenuItemImages[ITM_ROLL_DICE] = "toolbar_icons\\Menu_Dice.jpg";
	MenuItemImages[ITM_INPUT_DICE] = "toolbar_icons\\input_dice_value.jpg";
	MenuItemImages[ITM_NEW_GAME] = "toolbar_icons\\new_game.jpg";
	MenuItemImages[ITM_SWITCH_TO_DESIGN_MODE] = "toolbar_icons\\Menu_SwitchToGrid.jpg";

	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
}


void Output::PrintPlayersInfo(string info)
{
  CreatePlayModeToolBar();

  pWind->SetPen(UI.PlayerInfoColor);
  pWind->SetFont(20, BOLD, BY_NAME, "Verdana");

	int w = 0;
	int h = 0;

  pWind->GetStringSize(w, h, info);

  int x = UI.width - w - 20;
  int y = (UI.ToolBarHeight - h) / 2;

  pWind->DrawString(x, y, info);
}
