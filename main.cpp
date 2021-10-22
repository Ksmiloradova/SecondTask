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
int main(int argc, char* argv[]) {
    clock_t start = clock();
    if(argc != 5) {
        errMessage1();
        return 1;
    }

    cout << "Start"<< endl;
    Container c;

    ////cout << "argv[1] = " << argv[1] << "\n";
    if(!strcmp(argv[1], "-f")) {
        ifstream ifst(argv[2]);
        c.In(ifst);
    }
    else if(!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if((size < 1) || (size > 10000)) { 
            cout << "incorrect numer of figures = "
                 << size
                 << ". Set 0 < number <= 10000\n";
            return 3;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел
        c.InRnd(size);
    }
    else {
        errMessage2();
        return 2;
    }

    // Вывод содержимого контейнера в файл
    ofstream ofst1(argv[3]);
    ofst1 << "Filled container:\n";
    c.BinaryInsertion();
    c.Out(ofst1);

    // The 2nd part of task
    ofstream ofst2(argv[4]);

    cout << "Stop"<< endl;
    clock_t end = clock();
    // Вывод времени работы программы в "logFile.txt"
    ofst2 << "Total time = " << (double) (end - start) / CLOCKS_PER_SEC << " seconds\n";
    return 0;
}
