//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию, 
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cstdlib> // для функций rand() и srand()
#include <cstring>

#include "container.h"

void errMessage1() {
    cout << "incorrect command line!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n";
}

void errMessage2() {
    cout << "incorrect qualifier value!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n";
}

//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    clock_t start = clock();
    if (argc != 4) {
        errMessage1();
        return 1;
    }

    cout << "Start" << endl;
    Container c;

    ////cout << "argv[1] = " << argv[1] << "\n";
    if (!strcmp(argv[1], "-f")) {
        string inPath = "../tests/" + static_cast<string>(argv[2]);
        ifstream fin(inPath);
        if (!fin.is_open()) {
            cout << "Error: Input file doesn't exist!";
            return 0;
        }
        fin.close();
        ifstream ifst(inPath);
        c.In(ifst);
    } else if (!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            cout << "incorrect number of figures = "
                 << size
                 << ". Set 0 < number <= 10000\n";
            return 3;
        }
        // Системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел
        c.InRnd(size);
    } else {
        errMessage2();
        return 2;
    }

    // Вывод содержимого контейнера в файл
    string outPath = "../results/" + static_cast<string>(argv[3]);
    ofstream ofst1(outPath);
    ofst1 << "Filled container:\n";
    c.BinaryInsertion();
    c.Out(ofst1);

    cout << "Stop" << endl;
    clock_t end = clock();
    // Вывод времени работы программы в файл
    ofst1 << "Total time = " << (double) (end - start) / CLOCKS_PER_SEC << " seconds\n";
    return 0;
}
