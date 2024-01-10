//
// Created by Leo Suzuki on 10.1.2024.
//

#ifndef LIFEGAMEV1_LIFEGAMEV1_H
#define LIFEGAMEV1_LIFEGAMEV1_H

const int maxrow = 20, maxcol = 60;    //  grid dimensions

class Life {
public:
    void initialize();
    void print();
    void update();
private:
    int grid[maxrow + 2][maxcol + 2];  //  allows for two extra rows and columns
    int neighbor_count(int row, int col);
};


#endif //LIFEGAMEV1_LIFEGAMEV1_H
