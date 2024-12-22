#if defined(_WIN32) && !defined(_CRT_SECURE_NO_WARNINGS)
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>
#include "shapes.h" 

using namespace std;

static int M, N, P, Solution = 0;
static vector<vector<int>> Pole(62, vector<int>(62, -1));
COORD position;
HANDLE hConsole;
CONSOLE_SCREEN_BUFFER_INFO bi;
std::ofstream FILE_SAVE_s;

static void FindSolutions(int i);

int main(int argc, char* argv[]) {
    FILE* f;
    char s[MAXLEN];

    setlocale(LC_ALL, "Russian");
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout << "Решатель пентамино для произвольной фигуры!\n";

    string name_file;

    if (argc == 2)
        name_file = argv[1];
    else
        name_file = "C:/Users/madam/source/repos/pentamino_final/pentamino_final/input.txt";

    FILE_SAVE_s.open("C:/Users/madam/source/repos/pentamino_final/pentamino_final/output.txt", std::ios_base::trunc);

    if ((f = fopen(name_file.c_str(), "r")) != NULL) {
        std::cout << "Фигура : " << "\r\n";

        int k = 0, l = 0, col = 0;
        M = 0; N = 0;

        while (!feof(f)) {
            fgets(s, MAXLEN, f);
            k = 0;
            while ((s[k] != 0) && (s[k] != '\n')) {
                if (s[k] == ' ')
                    Pole[l][k] = -1;
                else {
                    Pole[l][k] = 0;
                    col++;
                    if (k > N) N = k;
                }
                k++;
            }
            l++;
        }
        fclose(f);

        N++;
        M = l;

        for (int y = 0; y < M; y++) {
            for (int x = 0; x < N; x++) {
                char c = (char)(Pole[y][x] + 0x30);
                if (Pole[y][x] < 0) c = ' ';
                else if (Pole[y][x] > 9)
                    c = (char)(Pole[y][x] - 10 + 'a');
                std::cout << " " << c;
            }
            std::cout << "\r\n";
        }

        if (col == 60) {
            std::cout << "Поиск решений . . .\n";
            FindSolutions(0);
            for (int i_n = 0; i_n < M + 1; i_n++) std::cout << "\n";
            std::cout << "\nЗапись в файл . . .\n";
        }
        else {
            std::cout << "Площадь прямоугольника != 60\n";
        }
    }
    FILE_SAVE_s.close();

    system("Pause");
    return 0;
}
