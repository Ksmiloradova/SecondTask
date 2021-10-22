//------------------------------------------------------------------------------
// container_Constr.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "transport.h"
#include "container.h"

//------------------------------------------------------------------------------
// Конструктор контейнера
Container::Container() : len{0} {}

//------------------------------------------------------------------------------
// Деструктор контейнера
Container::~Container() {
    Clear();
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Container::Clear() {
    for (int i = 0; i < len; i++) {
        delete storage[i];
    }
    len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void Container::In(ifstream &ifst) {
    while (!ifst.eof()) {
        if ((storage[len] = Transport::StaticIn(ifst)) != 0) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void Container::InRnd(int size) {
    while (len < size) {
        if ((storage[len] = Transport::StaticInRnd()) != nullptr) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Container::Out(ofstream &ofst) {
    ofst << "Container contains " << len << " elements.\n";
    for (int i = 0; i < len; i++) {
        ofst << i + 1 << ": ";
        storage[i]->Out(ofst);
    }
}

//------------------------------------------------------------------------------
// Упорядочение элементов контейнера сортировкой методом деления пополам
void Container::BinaryInsertion() {
    int i;
    Transport *selected;

    for (i = 1; i < len; ++i) {
        selected = storage[i];
        // Бинарный поиск места вставки
        int low = 0, high = i - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (selected->IdealTravelTime() == storage[mid]->IdealTravelTime()) {
                low = mid + 1;
                break;
            } else if (selected->IdealTravelTime() < storage[mid]->IdealTravelTime())
                low = mid + 1;
            else
                high = mid;
        }
        if (high <= low) {
            low = (selected->IdealTravelTime() < storage[low]->IdealTravelTime()) ? (low + 1) : low;
        }
        int j = i - 1;

        // Перемещение элементов дляя создания пространства для вставки
        for (; j >= low; --j) {
            storage[j + 1] = storage[j];
        }
        storage[j + 1] = selected;
    }
}
