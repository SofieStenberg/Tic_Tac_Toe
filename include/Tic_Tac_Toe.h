//
// Created by Sofie Stenberg on 2020-06-11.
//

#ifndef TIC_TAC_TOE_TIC_TAC_TOE_H
#define TIC_TAC_TOE_TIC_TAC_TOE_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define GRID 3
#define GRID_POW GRID *GRID
#define COMPUTER_MARK "X"
#define PLAYER_MARK "O"

// The class defining the variables and functions of the Toc_Tac_Toe  game
class Tic_Tac_Toe
{
private:
    static string m_grid[GRID][GRID];

public:
    static void CreateGrid();
    static void UpdatedGrid();
    static void PlayerChooseMark();
    static void PlayerMove(const string &);
    static void ComputerChooseMark();
    static void ComputerMove(const string &);
    static bool CheckWinner(const string &player);

    static vector<int> m_squaresTaken;
};

#endif
