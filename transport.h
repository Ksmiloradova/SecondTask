#ifndef __transport__
#define __transport__

//------------------------------------------------------------------------------
// transport.h - содержит описание обобщающего траспорта
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

#include "rnd.h"

//------------------------------------------------------------------------------
// Класс, обобщающий весь имеющийся транспорт
class Transport {
protected:
    static Random rnd20;
    static Random rnd3;
public:
    double distance; // расстояние между пунктами
    int speed; // скорость
    virtual ~Transport() {};
    // Ввод обобщенного траспорта
    static Transport *StaticIn(ifstream &ifdt);
    // Ввод обобщенного траспорта
    void In(ifstream &ifdt);
    // Случайный ввод обобщенного траспорта
    static Transport *StaticInRnd();
    // Виртуальный метод ввода случайного траспорта
    virtual void InRnd() = 0;
    // Вывод обобщенного траспорта
    virtual void Out(ofstream &ofst) = 0;
    // Вычисление идеального времени прохождения пути
    double IdealTravelTime();
};


#endif
