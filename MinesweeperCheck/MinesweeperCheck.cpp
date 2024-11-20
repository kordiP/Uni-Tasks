#include <iostream>

using namespace std;

const int MIN_CAPACITY = 3;
const int MAX_CAPACITY = 30;
const int MINE_VALUE = 9;

bool input(int field[][MAX_CAPACITY], int& rows, int& columns)
{
    cin >> rows;
    cin >> columns;

    if (rows < MIN_CAPACITY || rows > MAX_CAPACITY || columns < MIN_CAPACITY || columns > MAX_CAPACITY)
    {
        cout << "Invalid size!";
        return false;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cin >> field[i][j];
        }
    }

    return true;
}

bool checkSurroundingTiles(int field[MAX_CAPACITY][MAX_CAPACITY], int arraySizeRows, int arraySizeColumns, int currentTileRow, int currentTileColumn)
{
     int tileValue = field[currentTileRow][currentTileColumn];

    if (tileValue == MINE_VALUE)
    {
        return true;
    }

    int startIndexRows = (currentTileRow <= 0) ? 0 : currentTileRow - 1;
    int startIndexCols = (currentTileColumn <= 0) ? 0 : currentTileColumn - 1;

    int endIndexRows = (currentTileRow >= arraySizeRows) ? arraySizeRows - 1 : currentTileRow + 1;
    int endIndexCols = (currentTileColumn >= arraySizeColumns) ? arraySizeColumns - 1 : currentTileColumn + 1;

    int mineCount = 0;

    for (int i = startIndexRows; i <= endIndexRows; i++)
    {
        for (int j = startIndexCols; j <= endIndexCols; j++)
        {
            if (field[i][j] == MINE_VALUE)
            {
                mineCount++;
            }
        }
    }

    if (mineCount == tileValue)
    {
        return true;
    }

    return false;
}

int checkWholeField()
{
    /*for (int currentRow = 0; currentRow < rows; currentRow++)
    {
        for (int currentCol = 0; currentCol < columns; currentCol++)
        {
            bool correctSurroundings = checkSurroundingTiles(field, rows, columns, currentRow, currentCol);
            if (!correctSurroundings)
            {
                return 0;
            }
        }
    }*/

    return 1;
}

int main()
{
    int field[MAX_CAPACITY][MAX_CAPACITY] = {};

    int rows = 0;
    int columns = 0;

    if (input(field, rows, columns) == false)
    {
        return 0;
    }

    
}
