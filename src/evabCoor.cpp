#include "evabCoor.h"

namespace evab
{

    Coor::Coor(int x, int y) : X(x), Y(y)
    {
    }
    
    Place::Place(Coor aPosition, Coor aSize): Position(aPosition), Size(aSize)
    {
    }
}
