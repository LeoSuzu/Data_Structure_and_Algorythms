//
// Created by Leo Suzuki on 8.1.2024.
//

#include "Life.h"
#include <iostream>
using namespace std;

// Constructors
Life::Life() : maxrow(0), maxcol(0), grid(nullptr) {}

// Destructors
Life::~Life() {
    // Deallocate dynamic memory in the destructor
    for (int i = 0; i < maxrow + 2; ++i) {
        delete[] grid[i];
    }
    delete[] grid;
}

void Life::initialize()
/*
Pre:  None.
Post: The Life object contains a configuration specified by the user.
*/

{
    // Prompt the user for maxrow and maxcol
    do {
        cout << "Enter the number of rows (positive integer 10 to 100): ";
        cin >> maxrow;

        if (maxrow < 10 || maxrow > 100) {
            cout << "Invalid input. Number of rows must be a positive integer 10 to 100." << endl;
        }
    } while (maxrow < 10 || maxrow > 100);

    do {
        cout << "Enter the number of columns (positive integer 10 to 100): ";
        cin >> maxcol;

        if (maxcol < 10 || maxcol > 100) {
            cout << "Invalid input. Number of columns must be a positive integer 10 to 100." << endl;
        }
    } while (maxcol < 10 || maxcol > 100);

    // Allocate dynamic memory for the grid
    grid = new int*[maxrow + 2];
    for (int i = 0; i < maxrow + 2; ++i) {
        grid[i] = new int[maxcol + 2];
    }

    int row, col;
    for (row = 0; row < maxrow + 2; row++)
        for (col = 0; col < maxcol + 2; col++)
            grid[row][col] = 0;

    cout << "List the coordinates for living cells." << endl;
    cout << "This is example:" << endl;
    cout << "3 3\n3 4\n3 5\n4 3\n4 5\n5 3\n5 4\n5 5\n7 6\n7 7\n7 8\n8 6\n8 8\n9 6\n9 7\n9 8" << endl;
    cout << "Terminate the list with the special pair -1 -1" << endl;
    cin >> row >> col;

    while (row != -1 || col != -1) {
        if (row >= 1 && row <= maxrow)
            if (col >= 1 && col <= maxcol)
                grid[row][col] = 1;
            else
                cout << "Column " << col << " is out of range." << endl;
        else
            cout << "Row " << row << " is out of range." << endl;
        cin >> row >> col;
    }
}

void Life::print() {
    int row, col;
    cout << "\nThe current Life configuration is:" << endl;
    for (row = 1; row <= maxrow; row++) {
        for (col = 1; col <= maxcol; col++) {
            if (grid[row][col] == 1) {
                cout << 'O';  // symbol for live cell
            } else {
                cout << '.';  // symbol for dead cell
            }
        }
        cout << endl;
    }
    cout << endl;
}

void Life::update()
/*
Pre:  The Life object contains a configuration.
Post: The Life object contains the next generation of configuration.
*/

{
    // Allocate dynamic memory for the new_grid
    int** new_grid = new int*[maxrow + 2];
    for (int i = 0; i < maxrow + 2; ++i) {
        new_grid[i] = new int[maxcol + 2];
    }

    int row, col;
    for (row = 1; row <= maxrow; row++)
        for (col = 1; col <= maxcol; col++)
            switch (neighbor_count(row, col)) {
                case 2:
                    new_grid[row][col] = grid[row][col];  //  Status stays the same.
                    break;
                case 3:
                    new_grid[row][col] = 1;                //  Cell is now alive.
                    break;
                default:
                    new_grid[row][col] = 0;                //  Cell is now dead.
            }

    for (row = 1; row <= maxrow; row++)
        for (col = 1; col <= maxcol; col++)
            grid[row][col] = new_grid[row][col];
    // Deallocate dynamic memory for new_grid
    for (int i = 0; i < maxrow + 2; ++i) {
        delete[] new_grid[i];
    }
    delete[] new_grid;
}

int Life::neighbor_count(int row, int col) {
    int count = 0;
    int i_start = (row == 1) ? 1 : row - 1;
    int i_end = (row == maxrow) ? maxrow : row + 1;
    int j_start = (col == 1) ? 1 : col - 1;
    int j_end = (col == maxcol) ? maxcol : col + 1;

    for (int i = i_start; i <= i_end; ++i) {
        for (int j = j_start; j <= j_end; ++j) {
            count += grid[i][j];
        }
    }
    count -= grid[row][col];
    return count;
}


