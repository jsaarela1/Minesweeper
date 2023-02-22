#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Space.h"
#include "TextureManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;


int CheckTopLeft(vector<vector<char>> inputForSpaces, int col, int numColumns, int row, int numRows)
{
    if (((col - 1) < 0) || ((row - 1) < 0))
        return 0;
    else if (inputForSpaces[row - 1][col - 1] == '0')
        return 0;
    else
        return 1;
}
int CheckTopMiddle(vector<vector<char>> inputForSpaces, int col, int numColumns, int row, int numRows)
{
    if ((row - 1) < 0)
        return 0;
    else if (inputForSpaces[row - 1][col] == '0')
        return 0;
    else
        return 1;
}
int CheckTopRight(vector<vector<char>> inputForSpaces, int col, int numColumns, int row, int numRows)
{
    if (((col + 1) >= numColumns) || ((row - 1) < 0))
        return 0;
    else if (inputForSpaces[row - 1][col + 1] == '0')
        return 0;
    else
        return 1;
}
int CheckMiddleLeft(vector<vector<char>> inputForSpaces, int col, int numColumns, int row, int numRows)
{
    if ((col - 1) < 0)
        return 0;
    else if (inputForSpaces[row][col - 1] == '0')
        return 0;
    else
        return 1;
}
int CheckMiddleRight(vector<vector<char>> inputForSpaces, int col, int numColumns, int row, int numRows)
{
    if ((col + 1) >= numColumns)
        return 0;
    else if (inputForSpaces[row][col + 1] == '0')
        return 0;
    else
        return 1;
}
int CheckBottomLeft(vector<vector<char>> inputForSpaces, int col, int numColumns, int row, int numRows)
{
    if (((col - 1) < 0) || ((row + 1) >= numRows))
        return 0;
    else if (inputForSpaces[row + 1][col - 1] == '0')
        return 0;
    else
        return 1;
}
int CheckBottomMiddle(vector<vector<char>> inputForSpaces, int col, int numColumns, int row, int numRows)
{
    if ((row + 1) >= numRows)
        return 0;
    else if (inputForSpaces[row + 1][col] == '0')
        return 0;
    else
        return 1;
}
int CheckBottomRight(vector<vector<char>> inputForSpaces, int col, int numColumns, int row, int numRows)
{
    if (((col + 1) >= numColumns) || ((row + 1) >= numRows))
        return 0;
    else if (inputForSpaces[row + 1][col + 1] == '0')
        return 0;
    else
        return 1;
}

void checkSurroundings(vector<vector<Space>>& vectorOfSpaces, int col, int numColumns, int row, int numRows, sf::RenderWindow& window, int& checkJustaCouple)
{
    if (checkJustaCouple < 2000)
    {
        // only do this IF there are no mines around the original space
        bool isMine = false;

        if ((col - 1) < 0)
        {
            if ((row - 1) < 0)
            {
                for (int i = row; i <= row + 1; i++)
                {
                    for (int j = col; j <= col + 1; j++)
                    {
                        if (vectorOfSpaces[i][j].GetCount() == 9)
                            isMine = true;
                    }
                }
            }
            else if ((row + 1) == numRows)
            {
                for (int i = row - 1; i <= row; i++)
                {
                    for (int j = col; j <= col + 1; j++)
                    {
                        if (vectorOfSpaces[i][j].GetCount() == 9)
                            isMine = true;
                    }
                }
            }
            else
            {
                for (int i = row - 1; i <= row + 1; i++)
                {
                    for (int j = col; j <= col + 1; j++)
                    {
                        if (vectorOfSpaces[i][j].GetCount() == 9)
                            isMine = true;
                    }
                }
            }
        }
        else if ((col + 1) == numColumns)
        {
            if ((row - 1) < 0)
            {
                for (int i = row; i <= row + 1; i++)
                {
                    for (int j = col - 1; j <= col; j++)
                    {
                        if (vectorOfSpaces[i][j].GetCount() == 9)
                            isMine = true;
                    }
                }
            }
            else if ((row + 1) == numRows)
            {
                for (int i = row - 1; i <= row; i++)
                {
                    for (int j = col - 1; j <= col; j++)
                    {
                        if (vectorOfSpaces[i][j].GetCount() == 9)
                            isMine = true;
                    }
                }
            }
            else
            {
                for (int i = row - 1; i <= row + 1; i++)
                {
                    for (int j = col - 1; j <= col; j++)
                    {
                        if (vectorOfSpaces[i][j].GetCount() == 9)
                            isMine = true;
                    }
                }
            }
        }
        else if ((row - 1) < 0)
        {
            for (int i = row; i <= row + 1; i++)
            {
                for (int j = col - 1; j <= col + 1; j++)
                {
                    if (vectorOfSpaces[i][j].GetCount() == 9)
                        isMine = true;
                }
            }
        }
        else if ((row + 1) == numRows)
        {
            for (int i = row - 1; i <= row; i++)
            {
                for (int j = col - 1; j <= col + 1; j++)
                {
                    if (vectorOfSpaces[i][j].GetCount() == 9)
                        isMine = true;
                }
            }
        }
        else
        {
            for (int i = row - 1; i <= row + 1; i++)
            {
                for (int j = col - 1; j <= col + 1; j++)
                {
                    if (vectorOfSpaces[i][j].GetCount() == 9)
                        isMine = true;
                }
            }
        }

        if (!isMine)
        {
            // top left
            if (((col - 1) >= 0) && ((row - 1) >= 0))
            {
                if (vectorOfSpaces[row - 1][col - 1].GetBool() == 0)
                {
                    if ((vectorOfSpaces[row - 1][col - 1].GetCount() >= 1) && (vectorOfSpaces[row - 1][col - 1].GetCount() < 9))
                    {
                        vectorOfSpaces[row - 1][col - 1].FlipSpace();
                        vectorOfSpaces[row - 1][col - 1].Draw(window);
                    }
                    else if (vectorOfSpaces[row - 1][col - 1].GetCount() == 0)
                    {
                        vectorOfSpaces[row - 1][col - 1].FlipSpace();
                        vectorOfSpaces[row - 1][col - 1].Draw(window);
                        checkJustaCouple++;
                        checkSurroundings(vectorOfSpaces, col - 1, numColumns, row - 1, numRows, window, checkJustaCouple);
                    }
                }
            }
            // top middle
            if ((row - 1) >= 0)
            {
                if (vectorOfSpaces[row - 1][col].GetBool() == 0)
                {
                    if ((vectorOfSpaces[row - 1][col].GetCount() >= 1) && (vectorOfSpaces[row - 1][col].GetCount() < 9))
                    {
                        vectorOfSpaces[row - 1][col].FlipSpace();
                        vectorOfSpaces[row - 1][col].Draw(window);
                    }
                    else if (vectorOfSpaces[row - 1][col].GetCount() == 0)
                    {
                        vectorOfSpaces[row - 1][col].FlipSpace();
                        vectorOfSpaces[row - 1][col].Draw(window);
                        checkJustaCouple++;
                        checkSurroundings(vectorOfSpaces, col, numColumns, row - 1, numRows, window, checkJustaCouple);
                    }
                }
            }
            // top right
            if (((col + 1) < numColumns) && ((row - 1) >= 0))
            {
                if (vectorOfSpaces[row - 1][col + 1].GetBool() == 0)
                {

                    if ((vectorOfSpaces[row - 1][col + 1].GetCount() >= 1) && (vectorOfSpaces[row - 1][col + 1].GetCount() < 9))
                    {
                        vectorOfSpaces[row - 1][col + 1].FlipSpace();
                        vectorOfSpaces[row - 1][col + 1].Draw(window);
                    }
                    else if (vectorOfSpaces[row - 1][col + 1].GetCount() == 0)
                    {
                        vectorOfSpaces[row - 1][col + 1].FlipSpace();
                        vectorOfSpaces[row - 1][col + 1].Draw(window);
                        checkJustaCouple++;
                        checkSurroundings(vectorOfSpaces, col + 1, numColumns, row - 1, numRows, window, checkJustaCouple);
                    }
                }
            }
            // middle left
            if ((col - 1) >= 0)
            {
                if (vectorOfSpaces[row][col - 1].GetBool() == 0)
                {
                    if ((vectorOfSpaces[row][col - 1].GetCount() >= 1) && (vectorOfSpaces[row][col - 1].GetCount() < 9))
                    {
                        vectorOfSpaces[row][col - 1].FlipSpace();
                        vectorOfSpaces[row][col - 1].Draw(window);
                    }
                    else if (vectorOfSpaces[row][col - 1].GetCount() == 0)
                    {
                        vectorOfSpaces[row][col - 1].FlipSpace();
                        vectorOfSpaces[row][col - 1].Draw(window);
                        checkJustaCouple++;
                        checkSurroundings(vectorOfSpaces, col - 1, numColumns, row, numRows, window, checkJustaCouple);
                    }
                }
            }
            // middle right
            if ((col + 1) < numColumns)
            {
                if (vectorOfSpaces[row][col + 1].GetBool() == 0)
                {
                    if ((vectorOfSpaces[row][col + 1].GetCount() >= 1) && (vectorOfSpaces[row][col + 1].GetCount() < 9))
                    {
                        vectorOfSpaces[row][col + 1].FlipSpace();
                        vectorOfSpaces[row][col + 1].Draw(window);
                    }
                    else if (vectorOfSpaces[row][col + 1].GetCount() == 0)
                    {
                        vectorOfSpaces[row][col + 1].FlipSpace();
                        vectorOfSpaces[row][col + 1].Draw(window);
                        checkJustaCouple++;
                        checkSurroundings(vectorOfSpaces, col + 1, numColumns, row, numRows, window, checkJustaCouple);
                    }
                }
            }
            // bottom left
            if (((col - 1) >= 0) && ((row + 1) < numRows))
            {
                if (vectorOfSpaces[row + 1][col - 1].GetBool() == 0)
                {
                    if ((vectorOfSpaces[row + 1][col - 1].GetCount() >= 1) && (vectorOfSpaces[row + 1][col - 1].GetCount() < 9))
                    {
                        vectorOfSpaces[row + 1][col - 1].FlipSpace();
                        vectorOfSpaces[row + 1][col - 1].Draw(window);
                    }
                    else if (vectorOfSpaces[row + 1][col - 1].GetCount() == 0)
                    {
                        vectorOfSpaces[row + 1][col - 1].FlipSpace();
                        vectorOfSpaces[row + 1][col - 1].Draw(window);
                        checkJustaCouple++;
                        checkSurroundings(vectorOfSpaces, col - 1, numColumns, row + 1, numRows, window, checkJustaCouple);
                    }
                }
            }
            // bottom middle
            if ((row + 1) < numRows)
            {
                if (vectorOfSpaces[row + 1][col].GetBool() == 0)
                {
                    if ((vectorOfSpaces[row + 1][col].GetCount() >= 1) && (vectorOfSpaces[row + 1][col].GetCount() < 9))
                    {
                        vectorOfSpaces[row + 1][col].FlipSpace();
                        vectorOfSpaces[row + 1][col].Draw(window);
                    }
                    else if (vectorOfSpaces[row + 1][col].GetCount() == 0)
                    {
                        vectorOfSpaces[row + 1][col].FlipSpace();
                        vectorOfSpaces[row + 1][col].Draw(window);
                        checkJustaCouple++;
                        checkSurroundings(vectorOfSpaces, col, numColumns, row + 1, numRows, window, checkJustaCouple);
                    }
                }
            }
            // bottom right
            if (((col + 1) < numColumns) && ((row + 1) < numRows))
            {
                if (vectorOfSpaces[row + 1][col + 1].GetBool() == 0)
                {
                    if ((vectorOfSpaces[row + 1][col + 1].GetCount() >= 1) && (vectorOfSpaces[row + 1][col + 1].GetCount() < 9))
                    {
                        vectorOfSpaces[row + 1][col + 1].FlipSpace();
                        vectorOfSpaces[row + 1][col + 1].Draw(window);
                    }
                    else if (vectorOfSpaces[row + 1][col + 1].GetCount() == 0)
                    {
                        vectorOfSpaces[row + 1][col + 1].FlipSpace();
                        vectorOfSpaces[row + 1][col + 1].Draw(window);
                        checkJustaCouple++;
                        checkSurroundings(vectorOfSpaces, col + 1, numColumns, row + 1, numRows, window, checkJustaCouple);
                    }
                }
            }
        }
    }
}

int TestBoard(int testBoardNum, vector<vector<Space>>& vectorOfSpaces, unsigned int& columns, unsigned int& rows, sf::RenderWindow& window)
{
    int mineCount = 0;
    string filename;
    if (testBoardNum == 1)
        filename = "boards/testboard1.brd";
    else if (testBoardNum == 2)
        filename = "boards/testboard2.brd";
    else if (testBoardNum == 3)
        filename = "boards/testboard3.brd";
    ifstream file4board(filename);
    vector<vector<char>> inputForSpaces;
    if (file4board.is_open())
    {
        string lineFromFile;
        while (getline(file4board, lineFromFile))
        {
            vector<char> charPerLine;
            for (int i = 0; i < columns; i++)
            {
                char temp = lineFromFile.at(i);
                charPerLine.push_back(temp);
            }
            inputForSpaces.push_back(charPerLine);
        }
    }

    for (unsigned int i = 0; i < rows; i++)
    {
        vector<Space> columnVector;
        for (unsigned int j = 0; j < columns; j++)
        {
            int count = 0;
            unsigned int width = window.getSize().x;
            unsigned int height = window.getSize().y - 88;
            if (inputForSpaces[i][j] == '1')
            {
                mineCount++;
                Space tempSpace(9);
                tempSpace.SetPosition((width / (float)columns) * j, (height / (float)rows) * i);
                columnVector.push_back(tempSpace);
            }
            else
            {
                count += CheckTopLeft(inputForSpaces, j, columns, i, rows);
                count += CheckTopMiddle(inputForSpaces, j, columns, i, rows);
                count += CheckTopRight(inputForSpaces, j, columns, i, rows);
                count += CheckMiddleLeft(inputForSpaces, j, columns, i, rows);
                count += CheckMiddleRight(inputForSpaces, j, columns, i, rows);
                count += CheckBottomLeft(inputForSpaces, j, columns, i, rows);
                count += CheckBottomMiddle(inputForSpaces, j, columns, i, rows);
                count += CheckBottomRight(inputForSpaces, j, columns, i, rows);
                Space tempSpace(count);
                tempSpace.SetPosition((width / (float)columns) * j, (height / (float)rows) * i);
                columnVector.push_back(tempSpace);
            }
        }
        vectorOfSpaces.push_back(columnVector);
    }
    return mineCount;
}

void RandomBoard(vector<vector<Space>>& vectorOfSpaces, unsigned int& columns, unsigned int& rows, unsigned int& mines, sf::RenderWindow& window)
{
    vector<vector<char>> inputForSpaces;
    int minesLeft = mines;
    int availableSpaces = rows * columns;
    for (unsigned int i = 0 ; i < rows; i++)
    {
        vector<char> charPerLine;
        for (unsigned int j = 0; j < columns; j++)
        {
            char temp = '0';
            charPerLine.push_back(temp);
        }
        inputForSpaces.push_back(charPerLine);
    }

    unsigned int randomCol;
    unsigned int randomRow;
    unsigned int i = 0;
    while (i < mines)
    {
        randomCol = rand() % columns;
        randomRow = rand() % rows;
        if (inputForSpaces[randomRow][randomCol] == '0')
        {
            inputForSpaces[randomRow][randomCol] = '1';
            i++;
        }
    }


    for (unsigned int i = 0; i < rows; i++)
    {
        vector<Space> columnVector;
        for (unsigned int j = 0; j < columns; j++)
        {
            int count = 0;
            unsigned int width = window.getSize().x;
            unsigned int height = window.getSize().y - 88;
            if (inputForSpaces[i][j] == '1')
            {
                Space tempSpace(9);
                tempSpace.SetPosition((width / (float)columns) * j, (height / (float)rows) * i);
                columnVector.push_back(tempSpace);
            }
            else
            {
                count += CheckTopLeft(inputForSpaces, j, columns, i, rows);
                count += CheckTopMiddle(inputForSpaces, j, columns, i, rows);
                count += CheckTopRight(inputForSpaces, j, columns, i, rows);
                count += CheckMiddleLeft(inputForSpaces, j, columns, i, rows);
                count += CheckMiddleRight(inputForSpaces, j, columns, i, rows);
                count += CheckBottomLeft(inputForSpaces, j, columns, i, rows);
                count += CheckBottomMiddle(inputForSpaces, j, columns, i, rows);
                count += CheckBottomRight(inputForSpaces, j, columns, i, rows);
                Space tempSpace(count);
                tempSpace.SetPosition((width / (float)columns) * j, (height / (float)rows) * i);
                columnVector.push_back(tempSpace);
            }
        }
        vectorOfSpaces.push_back(columnVector);
    }
}

int main()
{
    unsigned int columns, rows, mines;
    ifstream file("boards/config.cfg");
    if (file.is_open())
    {
        file >> columns;
        file >> rows;
        file >> mines;
        Board gameboard(columns, rows);
        file.close();
    }
    unsigned int windowWidth = columns * 32;
    unsigned int windowHeight = (rows * 32) + 88;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Minesweeper");
    vector<vector<Space>> vectorOfSpaces;

    RandomBoard(vectorOfSpaces, columns, rows, mines, window);

    //TestBoard(1, vectorOfSpaces, columns, rows, window);
    // read in the board
    vector<Space> vectorOfButtons;
    unsigned int width = window.getSize().x;
    unsigned int height = window.getSize().y;
    Space gameButton(10);
    gameButton.ButtonSetPosition((width / (float)10 * 4.5), height - 88);
    vectorOfButtons.push_back(gameButton);
    
    // Test 1 button
    Space test1Button(11);
    test1Button.ButtonSetPosition((width / (float)10 * 7.05), height - 88);
    vectorOfButtons.push_back(test1Button);

    // Test 2 button
    Space test2Button(12);
    test2Button.ButtonSetPosition((width / (float)10 * 7.85), height - 88);
    vectorOfButtons.push_back(test2Button);

    // Test 3 button
    Space test3Button(13);
    test3Button.ButtonSetPosition((width / (float)10 * 8.65), height - 88);
    vectorOfButtons.push_back(test3Button);

    Space debugButton(14);
    debugButton.ButtonSetPosition(((width / (float)10) * 6.25), height - 88);
    vectorOfButtons.push_back(debugButton);
    

    bool check4break = false;
    bool gameLost = false;
    int flagCounter = 0;
    int numMines = mines;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    sf::Vector2f mousePosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                    for (int i = 0; i < rows; i++)
                    {
                        for (int j = 0; j < columns; j++)
                        {
                            if (vectorOfSpaces[i][j].GetBounds().contains(mousePosition))
                            {
                                vectorOfSpaces[i][j].MarkFlagged();
                                if (vectorOfSpaces[i][j].CheckIfFlagged())
                                    flagCounter++;
                                else
                                    flagCounter--;
                            }
                        }
                    }
                }
                else if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f mousePosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                    for (int i = 0; i < rows; i++)
                    {
                        for (int j = 0; j < columns; j++)
                        {
                            if (vectorOfSpaces[i][j].GetBounds().contains(mousePosition))
                            {
                                if (!vectorOfSpaces[i][j].CheckIfFlagged())
                                {
                                    // check if it is a mine, if so end game!
                                    if (vectorOfSpaces[i][j].GetCount() == 9)
                                    {
                                        vectorOfSpaces[i][j].FlipSpace();
                                        gameLost = true;
                                        if (gameLost == true)
                                            vectorOfButtons[0].HitMine();
                                        //vectorOfSpaces[i][j].DrawButton(window);

                                        for (int i = 0; i < rows; i++)
                                        {
                                            for (int j = 0; j < columns; j++)
                                            {
                                                vectorOfSpaces[i][j].FlipSpace();
                                            }
                                        }
                                    }
                                    else
                                    {
                                        vectorOfSpaces[i][j].FlipSpace();
                                        int checkJustaCouple = 0;
                                        checkSurroundings(vectorOfSpaces, j, columns, i, rows, window, checkJustaCouple);
                                    }
                                }
                            }
                            if (vectorOfButtons[0].GetTestBoardBounds(0).contains(mousePosition))
                            {
                                flagCounter = 0;
                                vectorOfSpaces.clear();
                                check4break = true;
                                gameLost = false;
                                vectorOfButtons[0].makeMineFalse();
                                RandomBoard(vectorOfSpaces, columns, rows, mines, window);
                                numMines = mines;
                                break;
                            }
                            else if (vectorOfButtons[1].GetTestBoardBounds(1).contains(mousePosition))
                            {
                                flagCounter = 0;
                                vectorOfSpaces.clear();
                                check4break = true;
                                gameLost = false;
                                vectorOfButtons[0].makeMineFalse();
                                vectorOfButtons[0].DrawButton(window);
                                numMines = TestBoard(1, vectorOfSpaces, columns, rows, window);
                                break;
                            }
                            else if (vectorOfButtons[2].GetTestBoardBounds(2).contains(mousePosition))
                            {
                                flagCounter = 0;
                                vectorOfSpaces.clear();
                                check4break = true;
                                gameLost = false;
                                vectorOfButtons[0].makeMineFalse();
                                vectorOfButtons[0].DrawButton(window);
                                numMines = TestBoard(2, vectorOfSpaces, columns, rows, window);
                                break;
                            }
                            else if (vectorOfButtons[3].GetTestBoardBounds(3).contains(mousePosition))
                            {
                                flagCounter = 0;
                                vectorOfSpaces.clear();
                                check4break = true;
                                gameLost = false;
                                vectorOfButtons[0].makeMineFalse();
                                vectorOfButtons[0].DrawButton(window);
                                numMines = TestBoard(3, vectorOfSpaces, columns, rows, window);
                                break;
                            }

                            // debug button mode
                            else if (vectorOfButtons[4].GetTestBoardBounds(4).contains(mousePosition))
                            {
                                if (vectorOfSpaces[i][j].GetCount() == 9)
                                    vectorOfSpaces[i][j].FlipSpace();
                            }
                        }
                        if (check4break == true)
                            break;
                    }
                    check4break = false;
                }
            }
        }

        int minesRemaining = numMines - flagCounter;
        Space minesLeft(15);
        minesLeft.ButtonSetPosition((width / (float)10 * .02), height - 88);
        minesLeft.DrawMineCounter(minesRemaining, window);
        vectorOfButtons.push_back(minesLeft);

        window.clear();

        bool checkForVictory = true;
        for (unsigned int i = 0; i < rows; i++)
        {
             for (unsigned int j = 0; j < columns; j++)
             {
                  if (vectorOfSpaces[i][j].GetCount() != 9)
                  {
                       if (!vectorOfSpaces[i][j].GetBool())
                           checkForVictory = false;
                  }
                  else
                  {
                      if (!vectorOfSpaces[i][j].CheckIfFlagged())
                            checkForVictory = false;
                  }
             }
        }
        if (checkForVictory == true)
        {
            vectorOfButtons[0].CheckIfGameWon();
        }

        for (unsigned int i = 0; i < rows; i++)
        {
            for (unsigned int j = 0; j < columns; j++)
            {
                vectorOfSpaces[i][j].DrawUnrevealed(window);
            }
        }
        for (unsigned int i = 0; i < rows; i++)
        {
            for (unsigned int j = 0; j < columns; j++)
            {
                vectorOfSpaces[i][j].Draw(window);
            }
        }
        for (unsigned int i = 0; i < vectorOfButtons.size(); i++)
        {
             vectorOfButtons[i].DrawButton(window);
        }

        window.display();
    }
    TextureManager::Clear();

    return 0;
}