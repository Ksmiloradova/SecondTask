#ifndef __ship__
#define __ship__

//------------------------------------------------------------------------------
// ship.h - содержит описание корабля
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"
#include "transport.h"

//------------------------------------------------------------------------------
// корабль
class Ship: public Transport {
public:
    virtual ~Ship() {}
    // Ввод параметров корабля из файла
    virtual void In(ifstream &ifst);
    // Случайный ввод параметров корабля
    virtual void InRnd();
    // Вывод параметров корабля в форматируемый поток
    virtual void Out(ofstream &ofst);
private:
    int displacement; // водоизмещение
    enum type {LINER = 1, TUG = 2, TANKER = 3};
    type t;
};

#endif //__ship__
