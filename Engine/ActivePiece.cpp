#include "ActivePiece.h"
#include "Matrix.h"

ActivePiece::ActivePiece()
{
	NewPiece();
}

bool ActivePiece::MoveLeft(Matrix& matrix)
{
	if (!CollisionMove(matrix, -1))
	{
		origin -= 1;
		return true;
	}
	else
	{
		return false;
	}
}

bool ActivePiece::MoveRight(Matrix& matrix)
{
	if (!CollisionMove(matrix, 1))
	{
		origin += 1;
		return true;
	}
	else
	{
		return false;
	}
}

bool ActivePiece::MoveDown(Matrix& matrix)
{
	if (!CollisionMove(matrix, -11))
	{
		origin -= 11;
		return true;
	}
	else
	{
		LockPiece(matrix);
		NewPiece();
		return false;
	}
}

bool ActivePiece::RotateCW(Matrix& matrix)
{
	if (!CollisionRotate(matrix, 4))
	{
		rotationIndex = (rotationIndex + 4) % 16;
		return true;
	}
	else
	{
		return false;
	}
}

bool ActivePiece::RotateCCW(Matrix& matrix)
{
	if (!CollisionRotate(matrix, 12))
	{
		rotationIndex = (rotationIndex + 12) % 16;
		return true;
	}
	else
	{
		return false;
	}
}

bool ActivePiece::Rotate180(Matrix& matrix)
{
	if (!CollisionRotate(matrix, 8))
	{
		rotationIndex = (rotationIndex + 8) % 16;
		return true;
	}
	else
	{
		return false;
	}
}

bool ActivePiece::CollisionMove(Matrix & matrix, int val)
{
	for (int i = rotationIndex; i < rotationIndex + 4; i++)
	{
		if (matrix.GetState()[origin + val + offset[i]] != 0)
		{
			return true;
		}
	}
	return false;
}

bool ActivePiece::CollisionRotate(Matrix & matrix, int val)
{
	int newRotationIndex = (rotationIndex + val) % 16;
	for (int i = newRotationIndex; i < newRotationIndex + 4; i++)
	{
		if (matrix.GetState()[origin + offset[i]] != 0)
		{
			return true;
		}
	}
	return false;
}

void ActivePiece::LockPiece(Matrix & matrix)
{
	for (int i = rotationIndex; i < rotationIndex + 4; i++)
	{
		matrix.AddPiece(origin + offset[i], id);
	}
	matrix.ClearLines();
	NewPiece();
}

void ActivePiece::NewPiece()
{
	static std::random_device rd;
	static std::mt19937 rng(rd());
	static std::uniform_int_distribution<int> randomInt(0, 6);
	int randomNumber = randomInt(rng);
	id = pieceAll[randomNumber].id;
	offset = pieceAll[randomNumber].offset;
	origin = pieceAll[randomNumber].origin;
	rotationIndex = pieceAll[randomNumber].rotationIndex;
}

/*
i apologize for this drawing code.
attempting to test the game logic from within the debugger was tedious
so i quickly threw something together to give me a visual
representation of the game.
*/
void ActivePiece::Draw(Graphics & gfx)
{
	int x;
	int y;
	for (int i = rotationIndex; i < rotationIndex + 4; i++)
	{
		//the matrix has some hidden rows to allow pieces to rotate when they are at the top
		//and we only want to draw the minos that are in the visible portion of the matrix
		if (origin + offset[i] < 231)
		{
			//1d array index to x y coordinates.
			x = (origin + offset[i]) % 11;
			y = (origin + offset[i]) / 11;
			//NOTE: the origin of the matrix is bottom left. 21 - y will work for now.
			y = 21 - y;
			//x y coordinates to x y pixel coordinates
			x = x * 16;
			y = y * 16;
			gfx.DrawRectDim(x, y, 16, 16, IdToColor(id));
		}
	}
}

Color ActivePiece::IdToColor(int i)
{
	Color c;
	if (i == 0)
	{
		c = Colors::Black;
	}
	else if (i == 1)
	{
		c = Colors::White;
	}
	else if (i == 2)
	{
		c = Colors::Blue;
	}
	else if (i == 3)
	{
		c = Colors::Red;
	}
	else if (i == 4)
	{
		c = Colors::Yellow;
	}
	else if (i == 5)
	{
		c = Colors::Green;
	}
	else if (i == 6)
	{
		c = Colors::Magenta;
	}
	else if (i == 7)
	{
		c = Colors::Cyan;
	}
	else
	{
		c = Colors::LightGray;
	}
	return c;
}