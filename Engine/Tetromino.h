#pragma once
#include <array>

struct Tetromino
{
	Tetromino(std::array<int, 16> init, int in_origin, int in_rotationIndex, int in_id)
		:
		offset(init),
		id(in_id),
		rotationIndex(in_rotationIndex),
		origin(in_origin)
	{}
	std::array<int, 16> offset;
	int id;
	int rotationIndex;
	int origin;
};