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
    auto k = Transport::rnd3.Get();
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

////------------------------------------------------------------------------------
//// Ввод обобщенного траспорта
//void Transport::In(ifstream &ifst) {
//    int k;
//    ifst >> k;
//    ifst >> speed >> distance;
//    switch (k) {
//        case 1:
//            dynamic_cast<Airplane *>(this)->In(ifst);
//            break;
//            //return this->In(ifst) && !(speed < 500 || speed > 900);
//        case 2:
//            dynamic_cast<Train *>(this)->In(ifst);
//            break;
//            //return this->In(ifst) && !(speed < 80 || speed > 200);
//        case 3:
//            dynamic_cast<Ship *>(this)->In(ifst);
//            break;
//            //return this->In(ifst) && !(speed < 19 || speed > 67);
////        default:
////            return false;
//    }
//}

////------------------------------------------------------------------------------
//// Виртуальный метод ввода случайного траспорта
//void Transport::InRnd() {
//    auto k = rand() % 3 + 1;
//    switch (k) {
//        case 1:
//            dynamic_cast<Airplane*>(this) -> InRnd();
//            // Генерация скорости самолёта от 500 до 900 км/ч
//            speed = 500 + rand() % (900 - 500 + 1);
//            break;
//        case 2:
//            dynamic_cast<Train*>(this) -> InRnd();
//            // Генерация скорости поезда от 80 до 200 км/ч
//            speed = 80 + rand() % (200 - 80 + 1);
//            break;
//        case 3:
//            dynamic_cast<Ship*>(this) -> InRnd();
//            // Генерация скорости корабля от 19 до 67 км/ч
//            speed = 19 + rand() % (67 - 19 + 1);
//            break;
//    }
//    // Генерация расстояния от 1000 до 20000.99 км
//    distance = 1000 + rand() % (20000 - 1000 + 1) + rand() % 100 / 100.0;
//}

//------------------------------------------------------------------------------
// Вычисление идеального времени прохождения пути
double Transport::IdealTravelTime() {
    return distance / speed;
}
