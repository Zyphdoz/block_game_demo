#pragma once
#include <array>

struct Tetromino
{
	Tetromino(std::array<std::array<int, 4>, 4> init, int in_origin, int in_orientation, int in_id)
		:
		offset(init),
		id(in_id),
		orientation(in_orientation),
		origin(in_origin)
	{}
	std::array<std::array<int, 4>, 4> offset;
	int id;
	int orientation;
	int origin;
};