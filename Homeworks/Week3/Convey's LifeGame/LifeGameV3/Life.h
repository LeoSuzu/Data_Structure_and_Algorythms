//
// Created by Leo Suzuki on 8.1.2024.
//

#ifndef LIFE_GAME_LIFE_H
#define LIFE_GAME_LIFE_H

class Life {
public:
    Life(); // Constructor to initialize dynamic memory
    ~Life(); // Destructor to deallocate dynamic memory
    void initialize();
    void print();
    void update();
private:
    int maxrow, maxcol;
    int **grid;  //  allows for two extra rows and columns
    int neighbor_count(int row, int col);
};

#endif //LIFE_GAME_LIFE_H
