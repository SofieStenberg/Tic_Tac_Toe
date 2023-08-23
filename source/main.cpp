#include "Tic_Tac_Toe.h"
#include <iostream>

using namespace std;

int main()
{
    // Starting comments to explain the task to the user
    cout << "Welcome to the game Tic Tac Toe." << endl;
    cout << "The goal is to get three marks in a row, either horizontally, vertical or diagonally." << endl;

    // Creates the grid
    Tic_Tac_Toe::CreateGrid();

    while (true)
    {
        // The player is chosing the first placement
        Tic_Tac_Toe::PlayerChooseMark();
        // Check if the user are the winner
        if (Tic_Tac_Toe::CheckWinner(PLAYER_MARK))
        {
            Tic_Tac_Toe::UpdatedGrid();
            cout << "YOU ARE VICTORIOUS!!!" << endl;
            break;
        }
        // If there are no moves left, then there is a tie
        if (Tic_Tac_Toe::m_squaresTaken.size() == GRID * GRID)
        {
            cout << "It is a tie..." << endl;
            break;
        }

        // Let the computer make a move, update the grid and check again if a winner is present
        Tic_Tac_Toe::ComputerChooseMark();
        Tic_Tac_Toe::UpdatedGrid();
        if (Tic_Tac_Toe::CheckWinner(COMPUTER_MARK))
        {
            cout << "GAME OVER!!" << endl;
            break;
        }
        if (Tic_Tac_Toe::m_squaresTaken.size() == GRID * GRID)
        {
            cout << "It is a tie..." << endl;
            break;
        }
    }

    return 0;
}
