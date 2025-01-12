#include "shapes.h"
#include <iostream>
#include <fstream>

static std::vector<Shape> Shapes = {
    // Пентомино 1: без поворотов, без отражения
    { { {3, 3, { { 0, 1, 0, 0, 0 }, { 1, 1, 1, 0, 0 }, { 0, 1, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }} }, 1},
    // Пентомино 2: два вращения, без отражения
    { { {5, 1, { { 2, 2, 2, 2, 2 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
        {1, 5, { { 2, 0, 0, 0, 0 }, { 2, 0, 0, 0, 0 }, { 2, 0, 0, 0, 0 }, { 2, 0, 0, 0, 0 }, { 2, 0, 0, 0, 0 } }} }, 2},
        // Пентомино 3: два вращения, отражения
        { { {3, 3, { { 3, 0, 0, 0, 0 }, { 3, 3, 3, 0, 0 }, { 0, 0, 3, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
            {3, 3, { { 0, 3, 3, 0, 0 }, { 0, 3, 0, 0, 0 }, { 3, 3, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
            {3, 3, { { 3, 3, 0, 0, 0 }, { 0, 3, 0, 0, 0 }, { 0, 3, 3, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
            {3, 3, { { 0, 0, 3, 0, 0 }, { 3, 3, 3, 0, 0 }, { 3, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }} }, 4},
            // Пентомино 4: четыре вращения, без отражения
            { { {3, 3, { { 4, 4, 4, 0, 0 }, { 4, 0, 0, 0, 0 }, { 4, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                {3, 3, { { 4, 4, 4, 0, 0 }, { 0, 0, 4, 0, 0 }, { 0, 0, 4, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                {3, 3, { { 0, 0, 4, 0, 0 }, { 0, 0, 4, 0, 0 }, { 4, 4, 4, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                {3, 3, { { 4, 0, 0, 0, 0 }, { 4, 0, 0, 0, 0 }, { 4, 4, 4, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }} }, 4},
                // Пентомино 5: четыре вращения, без отражения
                { { {3, 3, { { 0, 5, 5, 0, 0 }, { 5, 5, 0, 0, 0 }, { 5, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                    {3, 3, { { 5, 5, 0, 0, 0 }, { 0, 5, 5, 0, 0 }, { 0, 0, 5, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                    {3, 3, { { 0, 0, 5, 0, 0 }, { 0, 5, 5, 0, 0 }, { 5, 5, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                    {3, 3, { { 5, 0, 0, 0, 0 }, { 5, 5, 0, 0, 0 }, { 0, 5, 5, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }} }, 4},
                    // Пентомино 6: четыре вращения, без отражения
                    { { {3, 3, { { 6, 6, 6, 0, 0 }, { 0, 6, 0, 0, 0 }, { 0, 6, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                        {3, 3, { { 0, 0, 6, 0, 0 }, { 6, 6, 6, 0, 0 }, { 0, 0, 6, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                        {3, 3, { { 0, 6, 0, 0, 0 }, { 0, 6, 0, 0, 0 }, { 6, 6, 6, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                        {3, 3, { { 6, 0, 0, 0, 0 }, { 6, 6, 6, 0, 0 }, { 6, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }} }, 4},
                        // Пентомино 7: четыре вращения, без отражения
                        { { {3, 2, { { 7, 7, 7, 0, 0 }, { 7, 0, 7, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                            {2, 3, { { 7, 7, 0, 0, 0 }, { 0, 7, 0, 0, 0 }, { 7, 7, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                            {3, 2, { { 7, 0, 7, 0, 0 }, { 7, 7, 7, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                            {2, 3, { { 7, 7, 0, 0, 0 }, { 7, 0, 0, 0, 0 }, { 7, 7, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }} }, 4},
                            // Пентомино 8: четыре вращения, отражения
                            { { {3, 3, { { 8, 0, 0, 0, 0 }, { 8, 8, 8, 0, 0 }, { 0, 8, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                {3, 3, { { 0, 8, 8, 0, 0 }, { 8, 8, 0, 0, 0 }, { 0, 8, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                {3, 3, { { 0, 8, 0, 0, 0 }, { 8, 8, 8, 0, 0 }, { 0, 0, 8, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                {3, 3, { { 0, 8, 0, 0, 0 }, { 0, 8, 8, 0, 0 }, { 8, 8, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                {3, 3, { { 8, 8, 0, 0, 0 }, { 0, 8, 8, 0, 0 }, { 0, 8, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                {3, 3, { { 0, 8, 0, 0, 0 }, { 8, 8, 8, 0, 0 }, { 8, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                {3, 3, { { 0, 8, 0, 0, 0 }, { 8, 8, 0, 0, 0 }, { 0, 8, 8, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                {3, 3, { { 0, 0, 8, 0, 0 }, { 8, 8, 8, 0, 0 }, { 0, 8, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }} }, 8},
                                // Пентомино 9: четыре вращения, отражения
                                { { {4, 2, { { 9, 9, 9, 9, 0 }, { 0, 0, 0, 9, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                    {2, 4, { { 0, 9, 0, 0, 0 }, { 0, 9, 0, 0, 0 }, { 0, 9, 0, 0, 0 }, { 9, 9, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                    {4, 2, { { 9, 0, 0, 0, 0 }, { 9, 9, 9, 9, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                    {2, 4, { { 9, 9, 0, 0, 0 }, { 9, 0, 0, 0, 0 }, { 9, 0, 0, 0, 0 }, { 9, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                    {2, 4, { { 9, 0, 0, 0, 0 }, { 9, 0, 0, 0, 0 }, { 9, 0, 0, 0, 0 }, { 9, 9, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                    {4, 2, { { 0, 0, 0, 9, 0 }, { 9, 9, 9, 9, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                    {2, 4, { { 9, 9, 0, 0, 0 }, { 0, 9, 0, 0, 0 }, { 0, 9, 0, 0, 0 }, { 0, 9, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                    {4, 2, { { 9, 9, 9, 9, 0 }, { 9, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }} }, 8},
                                    // Пентомино 10: четыре вращения, отражения
                                    { { {4, 2, { { 10, 10, 10, 10, 0 }, { 0, 0, 10, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                        {2, 4, { { 0, 10, 0, 0, 0 }, { 0, 10, 0, 0, 0 }, { 10, 10, 0, 0, 0 }, { 0, 10, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                        {4, 2, { { 0, 10, 0, 0, 0 }, { 10, 10, 10, 10, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                        {2, 4, { { 10, 0, 0, 0, 0 }, { 10, 10, 0, 0, 0 }, { 10, 0, 0, 0, 0 }, { 10, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                        {2, 4, { { 10, 0, 0, 0, 0 }, { 10, 0, 0, 0, 0 }, { 10, 10, 0, 0, 0 }, { 10, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                        {4, 2, { { 0, 0, 10, 0, 0 }, { 10, 10, 10, 10, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                        {2, 4, { { 0, 10, 0, 0, 0 }, { 10, 10, 0, 0, 0 }, { 0, 10, 0, 0, 0 }, { 0, 10, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                        {4, 2, { { 10, 10, 10, 10, 0 }, { 0, 10, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }} }, 8},
                                        // Пентомино 11: четыре вращения, отражения
                                        { { {4, 2, { { 11, 11, 11, 0, 0 }, { 0, 0, 11, 11, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                            {2, 4, { { 0, 11, 0, 0, 0 }, { 0, 11, 0, 0, 0 }, { 11, 11, 0, 0, 0 }, { 11, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                            {4, 2, { { 11, 11, 0, 0, 0 }, { 0, 11, 11, 11, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                            {2, 4, { { 0, 11, 0, 0, 0 }, { 11, 11, 0, 0, 0 }, { 11, 0, 0, 0, 0 }, { 11, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                            {2, 4, { { 11, 0, 0, 0, 0 }, { 11, 0, 0, 0, 0 }, { 11, 11, 0, 0, 0 }, { 0, 11, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                            {4, 2, { { 0, 0, 11, 11, 0 }, { 11, 11, 11, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                            {2, 4, { { 11, 0, 0, 0, 0 }, { 11, 11, 0, 0, 0 }, { 0, 11, 0, 0, 0 }, { 0, 11, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                            {4, 2, { { 0, 11, 11, 11, 0 }, { 11, 11, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }} }, 8},
                                            // Пентомино 12: четыре вращения, отражения
                                            { { {3, 2, { { 12, 12, 12, 0, 0 }, { 0, 12, 12, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                                {2, 3, { { 0, 12, 0, 0, 0 }, { 12, 12, 0, 0, 0 }, { 12, 12, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                                {3, 2, { { 12, 12, 0, 0, 0 }, { 12, 12, 12, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                                {2, 3, { { 12, 12, 0, 0, 0 }, { 12, 12, 0, 0, 0 }, { 12, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                                {2, 3, { { 12, 0, 0, 0, 0 }, { 12, 12, 0, 0, 0 }, { 12, 12, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                                {3, 2, { { 0, 12, 12, 0, 0 }, { 12, 12, 12, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                                {2, 3, { { 12, 12, 0, 0, 0 }, { 12, 12, 0, 0, 0 }, { 0, 12, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }},
                                                {3, 2, { { 12, 12, 12, 0, 0 }, { 12, 12, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } }} }, 8}
};


TPoint SearchEmpty1(const std::vector<std::vector<int>>& Arr, TPoint st, TPoint end, int d) {
    for (; st.y < end.y; st.y++) {
        for (; st.x < end.x; st.x++) {
            if (Arr[st.y][st.x] == d) {
                return st;
            }
        }
        st.x = 0;
    }
    return st;
}

TPoint SearchEmpty(const std::vector<std::vector<int>>& Arr, TPoint st, TPoint end, int d) {
    for (; st.y < end.y; st.y++) {
        for (; st.x < end.x; st.x++) {
            if (Arr[st.y][st.x] == d) {
                return st;
            }
        }
        st.x = 0;
    }
    return st;
}

int CountEmpty(int y, int x, int Count) {
    if ((y < 0) || (x < 0)) return Count - 1;
    if (Pole[y][x] == 0) {
        if (Count == 4) return 5;
        Pole[y][x] = 20;

        Count = CountEmpty(y, x + 1, Count + 1);
        if (Count < 5) {
            Count = CountEmpty(y + 1, x, Count + 1);
            if (Count < 5) {
                Count = CountEmpty(y, x - 1, Count + 1);
                if (Count < 5) {
                    Count = CountEmpty(y - 1, x, Count + 1);
                }
            }
        }
        Pole[y][x] = 0;
    }
    else return Count - 1;
    return Count;
}

void FindSolutions(int i) {
    TPoint pt(0, 0);
    int j = 0;
    while (true) {
        pt = SearchEmpty1(Pole, pt, TPoint(N, M), 0);
        if (pt.y == M) {
            break;
        }

        while (Shapes[i].count != j) {
            TPoint f = SearchEmpty(Shapes[i].Pieces[j].Arr, TPoint(0, 0), TPoint(5, 5), i + 1);

            if (pt.x - f.x >= 0 && (pt.x - f.x) + Shapes[i].Pieces[j].LenX <= N && pt.y + Shapes[i].Pieces[j].LenY <= M) {
                bool s = true;
                int d = f.x;

                for (int y = 0; y < Shapes[i].Pieces[j].LenY; y++) {
                    for (int x = 0; x < Shapes[i].Pieces[j].LenX; x++) {
                        if (Shapes[i].Pieces[j].Arr[y][x] == i + 1)
                            if (Pole[pt.y + y][pt.x - f.x + x] != 0) {
                                s = false;
                                x = Shapes[i].Pieces[j].LenX;
                                y = Shapes[i].Pieces[j].LenY;
                            }
                    }
                }
