#ifndef __airplane__
#define __airplane__

//------------------------------------------------------------------------------
// airplane.h - содержит описание самолета и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"
#include "transport.h"

// самолет
class Airplane: public Transport {
public:
    virtual ~Airplane() {}
    // Ввод параметров транспорта из файла
    virtual void In(ifstream &ifst);
    // Случайный ввод параметров транспорта
    virtual void InRnd();
    // Вывод параметров транспорта в форматируемый поток
    virtual void Out(ofstream &ofst);
private:
    int flightRange, loadCapacity; // дальность полета, грузоподъемность
};

#endif //__airplane__
