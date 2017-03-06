#pragma once

#include "Graphics.h"
#include <array>


class Matrix
{
public:
	Matrix();
	std::array<int, 253> GetState() const;
	void AddPiece(int i, int id);
	void Draw(Graphics& gfx);
	Color GetColor(int cell);
	void ClearLines();

private:
	void ClearMatrix();
	static constexpr int size = 253;
	std::array<int, size> state;
};