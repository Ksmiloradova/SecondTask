//------------------------------------------------------------------------------
// ship.cpp - содержит функции обработки корабля
//------------------------------------------------------------------------------

#include "ship.h"

//------------------------------------------------------------------------------
// Ввод параметров корабля из потока
void Ship::In(ifstream &ifst) {
    int type;
    ifst >> type >> displacement;
    switch (t % 3 + 1) {
        case 1:
            t = Ship::LINER;
            break;
        case 2:
            t = Ship::TUG;
            break;
        case 3:
            t = Ship::TANKER;
            break;
    }
}

// Случайный ввод параметров корабля
void Ship::InRnd() {
    // Генерация скорости корабля от 19 до 67 км/ч
    speed = 19 + rand() % (67 - 19 + 1);
    // Генерация расстояния от 1000 до 20000.99 км
    distance = 1000 + rand() % (20000 - 1000 + 1) + rand() % 100 / 100.0;
    displacement = 50000 + rand() % (300000 - 50000 + 1);
    t = static_cast<Ship::type>(rand() % 3 + 1);
}

//------------------------------------------------------------------------------
// Вывод параметров корабля в поток
void Ship::Out(ofstream &ofst) {
    ofst << "It is Ship: Displacement = "
         << displacement << " kg, Type = ";
    switch (static_cast<int>(t)) {
        case 1:
            ofst << "Liner";
            break;
        case 2:
            ofst << "Tug";
            break;
        case 3:
            ofst << "Tanker";
            break;
    }
    ofst << "\n" << "   IdealTravelTime = " << IdealTravelTime() << " h. Speed = " << speed
         << " km/h. Distance to destination = " << distance << " km\n";
}
