#include <array>
#include "Matrix.h"
#include "Game.h"

Matrix::Matrix()
{
	ClearMatrix();
}

std::array<int, 253> Matrix::GetState() const
{
	return state;
}

void Matrix::AddPiece(int i, int id)
{
	state[i] = id;

	/*
	decrement a value in the hidden left column by one each time a block is added to that row.
	this is very convenient because it allows us to find out how many blocks are on a specific row
	at any given time without having to count them. this info is used in void Matrix::ClearLines()
	*/
	int leftMostBlock = i - (i % 11);
	state[leftMostBlock] --;
}

void Matrix::ClearMatrix()
{
	for (int i = 0; i < size; i++)
	{
		if (i < 11 || i > size || i % 11 == 0)
		{
			state[i] = -1;
		}
		else
		{
			state[i] = 0;
		}
	}
}

void Matrix::ClearLines()
{
	for (int i = 242; i > 0; i -= 11)
	{
		if (state[i] == -11)
		{
			for (int j = i; j < 242; j++)
			{
				state[j] = state[j + 11];
			}

			//deals with a corner case that occurs only if there are blocks on row 22 after a line clear.
			if (state[242] != -1)
			{
				state[242] = -1;
				for (int k = 243; k < 253; k++)
				{
					state[k] = 0;
				}
			}
		}
	}
}

/*
i apologize for this drawing code.
attempting to test the game logic from within the debugger was tedious
so i quickly threw something together to give me a visual
representation of the game.
*/
void Matrix::Draw(Graphics & gfx)
{
	gfx.DrawRectDim(0, 0, 192, 354, Colors::LightGray);
	int x = 0;
	int y = 0;
	for (int i = 0; i < 231; i++)
	{
		//1d array index to x y coordinates.
		x = i % 11;
		y = i / 11;
		//NOTE: the origin of the matrix is bottom left. 21 - y will work for now.
		y = 21 - y;
		//x y coordinates to x y pixel coordinates
		x = x * 16;
		y = y * 16;
		gfx.DrawRectDim(x, y, 16, 16, GetColor(i));
	}
}

Color Matrix::GetColor(int cell)
{
	Color c;
	if (state[cell] == 0)
	{
		c = Colors::Black;
	}
	else if (state[cell] == 1)
	{
		c = Colors::White;
	}
	else if (state[cell] == 2)
	{
		c = Colors::Blue;
	}
	else if (state[cell] == 3)
	{
		c = Colors::Red;
	}
	else if (state[cell] == 4)
	{
		c = Colors::Yellow;
	}
	else if (state[cell] == 5)
	{
		c = Colors::Green;
	}
	else if (state[cell] == 6)
	{
		c = Colors::Magenta;
	}
	else if (state[cell] == 7)
	{
		c = Colors::Cyan;
	}
	else
	{
		c = Colors::LightGray;
	}

	return c;
}