//------------------------------------------------------------------------------
// airplane.cpp - содержит методы самолета
//------------------------------------------------------------------------------

#include "airplane.h"

//------------------------------------------------------------------------------
// Ввод параметров самолета из файла
void Airplane::In(ifstream &ifst) {
    ifst >> flightRange >> loadCapacity;

}

// Случайный ввод параметров самолета
void Airplane::InRnd() {
    // Генерация скорости самолёта от 500 до 900 км/ч
    speed = 500 + rand() % (900 - 500 + 1);
    // Генерация расстояния от 1000 до 20000.99 км
    distance = 1000 + rand() % (20000 - 1000 + 1) + rand() % 100 / 100.0;
    flightRange = Transport::rnd20.Get();
    loadCapacity = Transport::rnd20.Get();
}

//------------------------------------------------------------------------------
// Вывод параметров самолета в форматируемый поток
void Airplane::Out(ofstream &ofst) {
    ofst << "It is Airplane: flightRange = " << flightRange
         << ", loadCapacity = " << loadCapacity << "\n" << "   IdealTravelTime = "
         << IdealTravelTime() << " h. Speed = " << speed
         << " km/h. Distance to destination = " << distance << " km\n";
}
