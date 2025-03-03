#include <iostream>
#include <fstream>

using namespace std;

/* Task 3 */
struct Color
{
    int red_val; // read_num / 65536
    int green_val; // (read_num / 256) % 256
    int blue_val; // read_num % 256
};
// stream needs to be in binary mode + result dynamically allocated
void readColorCode(ifstream& ifs, Color* result)
{
    Color curColor = { -1, -1, -1 };

    if (!ifs.is_open())
    {
        cerr << "Cannot open file.\n";
        return;
    }

    char str[8];
    int currNum = 0;
    int arrIndex = 0;

    while (ifs.read(str, 8))
    {
        // lazy to write myself, pls allow :>
        currNum = atoi(str);

        // read/save to struct
        curColor.red_val = currNum / 65536;
        curColor.green_val = (currNum / 256) % 256;
        curColor.blue_val = currNum % 256;

        // save to arr
        result[arrIndex++] = curColor;

        // reset
        curColor = { -1, -1, -1 };

        // skip the '|'
        ifs.seekg(1, ios::cur);
    }

    ifs.seekg(ios::beg);
}
void saveRedToFile(ofstream& ofs, Color* colors, int colorsSize)
{
    if (!ofs.is_open())
    {
        cerr << "Cannot open file.\n";
        return;
    }

    for (int i = 0; i < colorsSize; i++)
    {
        if (colors[i].red_val >= 250)
        {
            if (ofs.tellp() != 0)
            {
                ofs << '|';
            }
            int num = colors[i].red_val * 65536 + colors[i].green_val * 256 + colors[i].blue_val;
            ofs << num;
        }
    }
}

/* Task 2 */
const int MAX_PAIR_COUNT = 25;
struct Pair
{
    int num1;
    int num2;
};
struct Relation
{
    Pair pairs[MAX_PAIR_COUNT];
    int size;
};
void writePairToFile(Pair pair, ofstream& ofs)
{
    if (!ofs.is_open())
    {
        cerr << "Error opening file."; 
        return;
    }

    ofs << pair.num1 << " " << pair.num2;
}
void writeRelationToFile(Relation rel, ofstream& ofs)
{
    if (!ofs.is_open())
    {
        cerr << "Error opening file.";
        return;
    }

    for (int i = 0; i < rel.size; i++)
    {
        writePairToFile(rel.pairs[i], ofs);
        ofs << "\n";
    }
}
Pair readPairFromFile(int line, ifstream& ifs)
{
    int num1 = 0, num2 = 0;

    if (!ifs.is_open())
    {
        cerr << "Error opening file.";
        return { num1, num2 };
    }

    for (int i = 0; i < line; i++)
    {
        // 'skip' the lines, until we get to the one we need
        ifs >> num1 >> num2;
    }

    cout << "Read pair at line " << line << ": " << num1 << ", " << num2 << "\n";
    return { num1, num2 };
}
Relation readRelationFromFile(ifstream& ifs)
{
    Relation rel = { };
    if (!ifs.is_open())
    {
        cerr << "Error opening file.";
        return rel;
    }

    for (int i = 0; i < rel.size; i++)
    {
        rel.pairs[i] = readPairFromFile(i, ifs);
        rel.size++;
    }

    return rel;
}
void addPairToRelation(Pair pair, Relation rel)
{
    if (rel.size == 25)
    {
        cout << "Max pair size reached. Can not add pair.";
        return;
    }

    rel.pairs[rel.size++] = pair;
}
void task2Main()
{
    // idk
}


/* Task 1 */
void writeSumAndMult(int num1, int num2, int num3, ofstream& outFile)
{
    if (!outFile.is_open())
    {
        cerr << "Can't open file.";
        return;
    }

    int sum = num1 + num2 + num3;
    int mul = num1 * num2 * num3;

    outFile << sum << " " << mul << "\n";
    outFile.close();
}
void readSub(ifstream& inFile)
{
    if (!inFile.is_open())
    {
        cerr << "Can't open file.";
        return;
    }

    int num1, num2;

    inFile >> num1 >> num2;

    cout << num1 - num2;

    inFile.close();
}
void task1Main()
{
    const char* fileName = "result.txt";
    int num1, num2, num3;
    cin >> num1 >> num2 >> num3;

    ofstream outFile(fileName);
    ifstream inFile(fileName);

    writeSumAndMult(num1, num2, num3, outFile);
    readSub(inFile);
}

int main()
{
    ifstream ifs("Color_Resource.bin", ios::binary);
    ofstream ofs("red.txt");
    Color* colors = new Color[3];

    readColorCode(ifs, colors);

    for (int i = 0; i < 3; i++)
    {
        cout << colors[i].red_val << " " << colors[i].green_val << " " << colors[i].blue_val << endl;
    }
    
    saveRedToFile(ofs, colors, 3);
}