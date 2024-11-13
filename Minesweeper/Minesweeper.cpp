#include <iostream>
// values needed (11): invalid tile(out of scope), bomb tile, clear tile, [1-8] surrounding bombs
const int CAPACITY_MAX = 10;

int fieldSize = 0;

const int NOT_VISITED_TILE_VALUE = -1; // value != -1 == visited, multiply by that to set to not visited/visited.
const int CLEAR_TILE_VALUE = 0;
// 1 - 8 are with surrounding bomboclats
const int BOMB_TILE_VALUE = 9;
const int FLAG_TILE_VALUE = 10;

int gameField[CAPACITY_MAX][CAPACITY_MAX] = {};
int numberOfMines = 0;

void inputValues()
{
    do
    {
        std::cout << "Please enter field size (between 3 and 10): ";
        std::cin >> fieldSize;
    } while (fieldSize > 10 || fieldSize < 3);

    do
    {
        std::cout << "Please enter number of mines (between 1 and " << 3 * fieldSize << " ): ";
        std::cin >> numberOfMines;
    } while (numberOfMines < 1 || numberOfMines > 3 * fieldSize);
}

void generateAndSetRandomMinePositions()
{
    int counter = 0;
    do
    {
        int coordinateX = rand() % fieldSize; // i can use rand() right.
        int coordinateY = rand() % fieldSize;

        if (gameField[coordinateX][coordinateY] != CLEAR_TILE_VALUE) // if we have generated there, gen again
        {
            continue;
        }

        gameField[coordinateX][coordinateY] = BOMB_TILE_VALUE;
        generateSurroundingMineTiles(coordinateX, coordinateY);
        counter++;

    } while (counter < numberOfMines);
}

// generate the surrounding tiles of 1 mine 

/*
0  0  0
0 -1  0
0  0  0
*/
void generateSurroundingMineTiles(int mineCoordinateX, int mineCoordinateY)
{
    /*gameField[mineCoordinateX - 1][mineCoordinateY - 1] += 1;
    gameField[mineCoordinateX - 1][mineCoordinateY] += 1;
    gameField[mineCoordinateX - 1][mineCoordinateY + 1] += 1;*/

    int upperRow = (mineCoordinateX - 1 > 0) ? (mineCoordinateX - 1) : 0;
    int lowerRow = (mineCoordinateX + 1 > 0) ? (mineCoordinateX + 1) : mineCoordinateX;

    int upperRow = (mineCoordinateY - 1 > 0) ? (mineCoordinateY - 1) : 0;
    int lowerRow = (mineCoordinateY + 1 > 0) ? (mineCoordinateY + 1) : mineCoordinateY;

    for (int i = 0; i < 1; i++)
    {

    }
}

void printMatrix()
{
    for (int i = 0; i < fieldSize; i++)
    {
        for (int j = 0; j < fieldSize; j++)
        {
            std::cout << gameField[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main()
{
    inputValues();
    generateAndSetRandomMinePositions();
    
    printMatrix();
}

