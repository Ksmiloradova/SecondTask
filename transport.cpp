//------------------------------------------------------------------------------
// transport.cpp - содержит процедуры связанные с обработкой обобщенного транспорта
// и создания произвольного транспорта
//------------------------------------------------------------------------------

#include <iostream>
#include "airplane.h"
#include "train.h"
#include "ship.h"

//------------------------------------------------------------------------------
Random Transport::rnd20(1, 20);
Random Transport::rnd3(1, 3);

//------------------------------------------------------------------------------
// Ввод параметров транcпорта из файла
Transport *Transport::StaticIn(ifstream &ifst) {
    int k;
    ifst >> k;
    Transport *tr = nullptr;
    switch (k) {
        case 1:
            tr = new Airplane;
            break;
        case 2:
            tr = new Train;
            break;
        case 3:
            tr = new Ship;
            break;
    }
    if (tr!= NULL) {
        tr->In(ifst);
    }
    return tr;
}

//------------------------------------------------------------------------------
// Случайный ввод обобщенного транcпорта
Transport *Transport::StaticInRnd() {
    int k = Transport::rnd3.Get();
    Transport *tr = nullptr;
    switch (k) {
        case 1:
            tr = new Airplane;
            break;
        case 2:
            tr = new Train;
            break;
        case 3:
            tr = new Ship;
            break;
    }
    tr->InRnd();
    return tr;
}

//------------------------------------------------------------------------------
// Вычисление идеального времени прохождения пути
double Transport::IdealTravelTime() {
    return distance / speed;
}
