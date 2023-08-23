//
// Created by Sofie Stenberg on 2020-06-11.
//

#include "Tic_Tac_Toe.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <sstream>

// The GRID, m_grid and m_squaresTaken are defined in Tic_Tac_Toe.h
string Tic_Tac_Toe::m_grid[GRID][GRID];
vector<int> Tic_Tac_Toe::m_squaresTaken;

// This function creates the grid
void Tic_Tac_Toe::CreateGrid()
{
    // Counting the squares to use and putting the counts inside a vector
    int count = 1;
    for (int i = 0; i < GRID; i++)
    {
        for (int j = 0; j < GRID; j++)
        {
            m_grid[i][j] = to_string(count);
            count++;
        }
    }

    // This one actually prints out the grid and numbered scared to the console
    cout << "-------------------------------------------------" << endl;
    for (int i = 0; i < GRID; i++)
    {
        cout << "|\t";
        for (int j = 0; j < GRID; j++)
        {
            cout << m_grid[i][j] << "\t|\t";
        }
        cout << endl;
        cout << "-------------------------------------------------" << endl;
    }
}

void Tic_Tac_Toe::UpdatedGrid()
{
    cout << "-------------------------------------------------" << endl;
    for (int i = 0; i < GRID; i++)
    {
        cout << "|\t";
        for (int j = 0; j < GRID; j++)
        {
            cout << m_grid[i][j] << "\t|\t";
        }
        cout << endl;
        cout << "-------------------------------------------------" << endl;
    }
}

void Tic_Tac_Toe::PlayerChooseMark()
{
    // The player makes his/hers choice based on the numbers on the grid
    cout << "Chose your mark." << endl;
    string playerChoice;
    cin >> playerChoice;
    int x = stoi(playerChoice);

    // If the number chosen is within the range of the grid and is not previously taken,
    // then the mark is stored in the m_squaresTaken and the move is executed.
    if ((x > 0 && x < GRID_POW + 1) && find(m_squaresTaken.begin(), m_squaresTaken.end(), x) == m_squaresTaken.end())
    {
        m_squaresTaken.push_back(x);
        Tic_Tac_Toe::PlayerMove(playerChoice);
        cout << "Player took " << x << endl;
    }
    else
    {
        cout << "The input is invalid. Please choose a number left from the board." << endl;
        Tic_Tac_Toe::PlayerChooseMark();
        return;
    }
}

// This function performes the chosen move of the user.
void Tic_Tac_Toe::PlayerMove(const string &choice)
{
    for (int x = 0; x < GRID; x++)
    {
        for (int y = 0; y < GRID; y++)
        {
            if (m_grid[x][y] == choice)
            {
                m_grid[x][y] = PLAYER_MARK;
            }
        }
    }
}

// This function lets the computer choose a move
void Tic_Tac_Toe::ComputerChooseMark()
{
    vector<string> availableChoice;

    // Goes through the grid and stores all available moves
    int count = 0;
    for (int i = 0; i < GRID; i++)
    {
        for (int j = 0; j < GRID; j++)
        {
            if (m_grid[i][j] != PLAYER_MARK && m_grid[i][j] != COMPUTER_MARK)
            {
                availableChoice.push_back(m_grid[i][j]);
                count++;
            }
        }
    }

    // The computer makes a random choice and that choice is then verified if it is valid
    srand(time(0));
    int choice = (rand() % count);
    string computerChoice = availableChoice[choice];

    // If the move is valid, then the move is executed
    int x = stoi(computerChoice);
    m_squaresTaken.push_back(x);
    Tic_Tac_Toe::ComputerMove(computerChoice);
}

// This function performs the computers move
void Tic_Tac_Toe::ComputerMove(const string &choice)
{
    for (int i = 0; i < GRID; i++)
    {
        for (int j = 0; j < GRID; j++)
        {
            if (m_grid[i][j] == choice)
            {
                m_grid[i][j] = COMPUTER_MARK;
            }
        }
    }
}

// This function checkes whether the specified user is the winner or not.
bool Tic_Tac_Toe::CheckWinner(const string &player)
{
    bool victory;
    // Checks for vertically win
    for (int x = 0; x < GRID; ++x)
    {
        victory = true;
        for (int y = 0; y < GRID; ++y)
        {
            if (m_grid[x][y] == player)
                continue;
            victory = false;
            break;
        }
        if (victory)
            return true;
    }

    // Checks for horizontally win
    for (int y = 0; y < GRID; ++y)
    {
        victory = true;
        for (int x = 0; x < GRID; ++x)
        {
            if (m_grid[x][y] == player)
                continue;
            victory = false;
            break;
        }
        if (victory)
            return true;
    }

    // Diagonally top left to bottom right
    victory = true;
    for (int x = 0; x < GRID; ++x)
    {
        if (m_grid[x][x] == player)
            continue;
        victory = false;
        break;
    }
    if (victory)
        return true;

    // Diagonally top right to bottom left
    victory = true;
    for (int x = 0; x < GRID; ++x)
    {
        if (m_grid[x][GRID - 1 - x] == player)
            continue;
        victory = false;
        break;
    }
    return victory;
}