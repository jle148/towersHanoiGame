// File Name: main.cpp
//
// Author: Johnathan Edwards
// Date: 11/13/2021
// Assignment Number: 7
// CS3358.003
// Instructor: C Jinshong Hwang
//
// A program that uses recursion to display the moves for a Towers of Hanoi
// game using n number of discs.

#include <iostream>
#include <vector>

using namespace std;

void towerGame(int, char, char, char, vector<char> &);
void displayVector(vector<char>);
void initVector(vector<char> &, int);

int main()
{
    char choice;
    int mask = 32; //bitwise mask for toggling characters to lowercase
    int discTotal;
    vector<char> discPos; //vector showing disc positions
    const char pegA = 'A';
    const char pegB = 'B';
    const char pegC = 'C';

    cout << "*************** Towers of Hanoi ***************" << endl;

    do
    {
        cout << endl << "How many discs are you playing with? ";
        cin >> discTotal;
        initVector(discPos, discTotal);
        cout << endl;
        towerGame(discTotal, pegA, pegC, pegB, discPos);
        cout << "Moves complete!" << endl;

        do //ask user for choice to continue
        {
            cout << endl << "Play again (y or n)? ";
            cin >> choice;
            choice = choice | mask; //bitwise operation to make the user's
                //choice a lowercase character
            if (choice != 'y' && choice != 'n')
                cout << "Invalid choice! Try again!" << endl;
        } while (choice != 'y' && choice != 'n');

        if (choice == 'n')
            cout << endl << "Thanks for playing!";
    } while (choice == 'y');

    return 0;
}

//*****************************************************************************
// towerGame: recursion function that manipulates the position of discs in a
// Tower of Hanoi game
// num: the disc being manipulated
// a: a peg in the game; the starting peg for all the discs in the initial
// function call
// b: a peg in the game; the middle peg in the initial function call
// c: a peg in the game; the destination peg for all the discs in the initial
// function call
// v: a vector holding the positions of each disc
// no return
//*****************************************************************************
void towerGame(int num, char a, char c, char b, vector<char> &v)
{
    if (num > 0)
    {
        towerGame(num - 1, a, b, c, v);
        cout << "Move disc " << num << " from peg " << a << " to peg " << c
            << " ";
        v[num - 1] = c; //change disc position in vector
        displayVector(v);
        towerGame(num - 1, b, c, a, v);
    }
}

//*****************************************************************************
// displayVector: displays the values of the disc position vector
// v: a vector holding the positions of each disc
// no return
//*****************************************************************************
void displayVector(vector<char> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i == 0)
            cout << "(";
        if (i < v.size() - 1)
            cout << v[i] << ",";
        else
            cout << v[i] << ")";
    }
        cout << endl;
}

//*****************************************************************************
// initVector: initializes the position of all of the discs to peg A
// v: a vector holding the positions of each disc
// total: the total number of discs to initialize
// no return
//*****************************************************************************
void initVector(vector<char> &v, int total)
{
    if (!v.empty()) //start with an empty vector
            v.clear();

    for (int i = 0; i < total; i++)
        v.push_back('A'); //initialize all disc positions to peg A
}
