#pragma once
#include "Tetromino.h"
#include "Graphics.h"
#include "Matrix.h"
#include <random>


class ActivePiece
{
public:
	enum Direction
	{
		left = -1,
		right = 1,
		down = -11,
		up = 11
	};
	enum Rotation
	{
		clockwise = 1,
		twice = 2,
		counterclockwise = 3
	};
public:
	ActivePiece();
	bool MoveLeft(Matrix& matrix);
	bool MoveRight(Matrix& matrix);
	bool MoveDown(Matrix& matrix);
	bool RotateCW(Matrix& matrix);
	bool RotateCCW(Matrix& matrix);
	bool Rotate180(Matrix& matrix);

	void Draw(Graphics& gfx);
	Color IdToColor(int i) const;

private:
	bool CanMove(const Matrix& matrix, int val) const;
	bool CanRotate(const Matrix& matrix, int val) const;
	void LockPiece(Matrix& matrix);
	void NewPiece();

	int id = 0;
	int origin = 0;
	int orientation = 0;
	std::array<std::array<int, 4>, 4> offset = { { { 0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} } };

	Tetromino pieceJ = Tetromino({ { {-1,0,1,10    }, {-11,0,11,12  }, { -10,-1,0,1    }, { -12,-11,0,11 } } }, 226, 0, 2);
	Tetromino pieceI = Tetromino({ { {-2,-1,0,1    }, {-22,-11,0,11 }, {-13,-12,-11,-10}, {10,-1,-12,-23 } } }, 226, 0, 7);
	Tetromino pieceZ = Tetromino({ { {-11,-10,-1,0 }, {-22,-11,-10,1}, {-22,-21,-12,-11}, {-23,-11,-12,0 } } }, 226, 0, 3);
	Tetromino pieceL = Tetromino({ { {-1,0,1,12    }, {-11,-10,0,11 }, {-12,-1,0,1     }, { -11,0,10,11  } } }, 226, 0, 6);
	Tetromino pieceO = Tetromino({ { {-12,-11,-1,0 }, {-12,-11,-1,0 }, {-12,-11,-1,0   }, {-12,-11,-1,0  } } }, 226, 0, 4);
	Tetromino pieceT = Tetromino({ { {-1,0,1,11    }, {-11,0,1,11   }, { -11,-1,0,1    }, { -11,-1,0,11  } } }, 226, 0, 1);
	Tetromino pieceS = Tetromino({ { {-12,-11,0,1  }, {-21,-11,-10,0}, {-23,-22,-10,-11}, {-22,-12,-1,-11} } }, 226, 0, 5);
	std::array<Tetromino, 7> pieceAll = { pieceJ, pieceI, pieceZ, pieceL, pieceO, pieceT, pieceS };
};