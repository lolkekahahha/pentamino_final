#ifndef PENTAMINO_FINAL_H
#define PENTAMINO_FINAL_H

#include <vector>

#define MAXLEN 100

struct TPoint {
    int x, y;
    TPoint(int a, int b) : x(a), y(b) {}
};

struct Piece {
    int LenX, LenY;
    std::vector<std::vector<int>> Arr;
};

struct Shape {
    std::vector<Piece> Pieces;
    int count;
};

extern std::vector<Shape> Shapes;
extern int M, N, Solution;
extern std::vector<std::vector<int>> Pole;

TPoint SearchEmpty1(const std::vector<std::vector<int>>& Arr, TPoint st, TPoint end, int d);
TPoint SearchEmpty(const std::vector<std::vector<int>>& Arr, TPoint st, TPoint end, int d);
int CountEmpty(int y, int x, int Count);
void FindSolutions(int i);

#endif // PENTAMINO_FINAL_H