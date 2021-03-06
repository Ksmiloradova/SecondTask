//------------------------------------------------------------------------------
// train.cpp - содержит функции обработки поезда
//------------------------------------------------------------------------------

#include "train.h"

//------------------------------------------------------------------------------
// Ввод параметров поезда из потока
void Train::In(ifstream &ifst) {
    ifst >> speed >> distance >> numberOfWagons;
    if (numberOfWagons < 0 && numberOfWagons > 75 ||
            speed < 80 || speed > 200 || distance < 0) {
        speed = -1;
    }
}

// Случайный ввод параметров поезда
void Train::InRnd() {
    // Генерация скорости поезда от 80 до 200 км/ч
    speed = 80 + rand() % (200 - 80 + 1);
    // Генерация расстояния от 1000 до 20000.99 км
    distance = 1000 + rand() % (20000 - 1000 + 1) + rand() % 100 / 100.0;
    numberOfWagons = Transport::rnd20.Get();
}

//------------------------------------------------------------------------------
// Вывод параметров поезда в поток
void Train::Out(ofstream &ofst) {
    ofst << "It is Train: numberOfWagons = " << numberOfWagons << "\n" <<
         "   IdealTravelTime = " << IdealTravelTime() << " h. Speed = " << speed
         << " km/h. Distance to destination = " << distance << " km\n";

}
