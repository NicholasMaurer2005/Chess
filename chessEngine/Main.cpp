#include <cstdint>
#include "MoveGen.h"
#include "BitBoard.h"
#include "State.h"
#include "Engine.h"
#include <chrono>
#include <string>
#include <iostream>
#include "ChessConstants.hpp"

int main()
{
	Engine engine{ start_position_fen };
	engine.step(true, false, 8);
}
