#ifndef OUPTUT_H
#define OUPTUT_H

#include "DEFS.h"
#include "UI_Info.h"
#include "CMUgraphicsLib\CMUgraphics.h"
#include "CellPosition.h"

using namespace std;


class Input;

class Output
{
private:
    window* pWind;

public:
    int GetCellStartX(const CellPosition& cellPos) const;
    int GetCellStartY(const CellPosition& cellPos) const;

    void CreateDesignModeToolBar() const;
    void CreatePlayModeToolBar() const;

    void PrintPlayersInfo(string info);
};
