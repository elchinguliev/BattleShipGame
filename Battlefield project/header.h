#pragma once
#include<iostream>
#include<iomanip>
#include<Windows.h>
using namespace std;
const int s1 = 12;
int game[s1][s1] = {};
void mysetcolor(int fg, int bg) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, fg | (bg << 4));
}
void ShowGame() {
    for (size_t i = 0; i < s1; i++)
    {
        for (size_t k = 0; k < s1; k++)
        {
            if (i == 0 || i == s1 - 1) {
                mysetcolor(9, 0);
                cout << "- ";
                mysetcolor(7, 0);
            }
            else if (k == 0) {
                mysetcolor(9, 0);
                cout << "|";
                mysetcolor(7, 0);
            }
            else if (k == s1 - 1) {
                mysetcolor(9, 0);
                cout << "|";
                mysetcolor(7, 0);
            }
            else if (game[i][k] == 0) {
                if (k == 1) {
                    mysetcolor(2, 0);
                    cout << "|";
                    mysetcolor(7, 0);
                }
                else {
                    mysetcolor(2, 0);
                    cout << (char)219 << "|";
                    mysetcolor(7, 0);
                }
            }
            else {
                cout << "  ";
            }
        }cout << endl;
    }
}
void ShowName() {
    mysetcolor(3, 0);
    cout << "\t\t\t ------------------------------------------------------------------" << endl;
    cout << "\t\t\t| **   **  *** ** *     ***  ** *  * * *** |" << endl;
    cout << "\t\t\t| *  *  *  *   *     *   *     *     *     *  * * *  * |" << endl;
    cout << "\t\t\t| **  ***   *     *   *     **    **  *** * ** |" << endl;
    cout << "\t\t\t| *  *  *  *   *     *   *     *         * *  * * *    |" << endl;
    cout << "\t\t\t| **  *  *   *     *   *** ** **  *  * * **    |" << endl;
    cout << "\t\t\t ------------------------------------------------------------------ " << endl;
    mysetcolor(7, 0);
}
void Rules() {
    mysetcolor(3, 0);
    cout << "RULES OF THE GAME : " << endl;
    mysetcolor(7, 0);
    cout << endl;
    mysetcolor(6, 0);
    cout << "\t" << (char)219;
    mysetcolor(7, 0);
    mysetcolor(3, 0);
    cout << " -> Is place of miss ship" << endl;
    cout << endl;
    mysetcolor(4, 0);
    cout << "\t" << (char)219;
    mysetcolor(7, 0);
    mysetcolor(3, 0);
    cout << " -> Is place of burst ship" << endl;
    cout << endl;
    mysetcolor(2, 0);
    cout << "\t" << (char)219;
    mysetcolor(7, 0);
    mysetcolor(3, 0);
    cout << " -> Is place of unbrust ship" << endl;
    cout << endl;
    mysetcolor(1, 0);
    cout << "\t" << (char)219;
    mysetcolor(7, 0);
    mysetcolor(3, 0);
    cout << " -> Is place of unburst ship " << endl;
    cout << endl;
    mysetcolor(3, 0);
    cout << "\t1. This is a two player game." << endl;
    cout << "\t2. Player 1 is you and Player 2 is the computer." << endl;
    cout << "\t3. Player 1 will be prompted if user wants to manually input coordinates\n\tfor the game board or have the computer randomly generate a game board." << endl;
    cout << "\t4. There are five types of ships to be placed by longest length to the\n\tshortest; [c] Carrier has 5 cells, [b] Battleship has 4 cells, [r] Cruiser\n\thas 3 cells, [s] Submarine has 3 cells, [d] Destroyer has 2 cells" << endl;
    cout << "\t5. The computer randomly selects which player goes first" << endl;
    cout << "\t6. The game begins as each player tries to guess the location of theships\n\tof the opposing player's game board; [*] hit and[m] miss." << endl;
    cout << "\t7. First player to guess the location of all ships wins." << endl;
    mysetcolor(7, 0);
    cout << endl;
}
void Select() {
    cout << "\t\t\t\t\t   -------------------------" << endl;
    cout << "\t\t\t\t\t   | RULES OF THE GAME [1] |" << endl;
    cout << "\t\t\t\t\t   | START GAME [2]        |" << endl;
    cout << "\t\t\t\t\t   -------------------------" << endl;
    cout << "\t\t\t\t\t       ENTER SELECTION : ";
    int cho = 0;
    cin >> cho;
    if (cho == 1) {
        system("cls");
        Rules();
        system("pause");
    }
    else if (cho == 2) {
        system("cls");
        ShowGame();
        ShowGame();
    }
}
