//
// Created by sepehr on 1/9/19.
//

#include "classes.h"

PreviousMove::PreviousMove(Mohre *target, int Sourcex, int sourcey, int dx, int dy):target(target), SourceX(Sourcex), SourceY(sourcey), DestX(dx), DestY(dy) {}


PreviousMove::PreviousMove():target(nullptr), SourceY(-1), SourceX(-1), DestY(-1), DestX(-1) {}
