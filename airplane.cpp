//------------------------------------------------------------------------------
// airplane.cpp - содержит методы самолета
//------------------------------------------------------------------------------

#include "airplane.h"

//------------------------------------------------------------------------------
// Ввод параметров самолета из файла
void Airplane::In(ifstream &ifst) {
    ifst >> speed >> distance >> flightRange >> loadCapacity;
    if (flightRange > 20000 || flightRange < 5000 ||
        loadCapacity < 16000 || loadCapacity > 150000 ||
        speed < 500 || speed > 900 || distance < 0) {
        speed = -1;
    }
}

// Случайный ввод параметров самолета
void Airplane::InRnd() {
    // Генерация скорости самолёта от 500 до 900 км/ч
    speed = 500 + rand() % (900 - 500 + 1);
    // Генерация расстояния от 1000 до 20000.99 км
    distance = 1000 + rand() % (20000 - 1000 + 1) + rand() % 100 / 100.0;
    flightRange = 20000 + rand() % (5000 + 1);
    loadCapacity = 16000 + rand()%(150000 - 16000 + 1);
}

//------------------------------------------------------------------------------
// Вывод параметров самолета в форматируемый поток
void Airplane::Out(ofstream &ofst) {
    ofst << "It is Airplane: flightRange = " << flightRange
         << ", loadCapacity = " << loadCapacity << "\n" << "   IdealTravelTime = "
         << IdealTravelTime() << " h. Speed = " << speed
         << " km/h. Distance to destination = " << distance << " km\n";
}
