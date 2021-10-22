#ifndef __train__
#define __train__

//------------------------------------------------------------------------------
// train.h - содержит описание поезда
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"
#include "transport.h"

//------------------------------------------------------------------------------
// поезд
class Train: public Transport {
public:
    virtual ~Train() {}
    // Ввод параметров поезда из файла
    virtual void In(ifstream &ifst);
    // Случайный ввод параметров поезда
    virtual void InRnd();
    // Вывод параметров поезда в форматируемый поток
    virtual void Out(ofstream &ofst);
private:
    int numberOfWagons; // количество вагонов
};

#endif //__train__
