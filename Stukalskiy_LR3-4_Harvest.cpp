#include "Stukalskiy_LR3-4_Harvest.h"

using namespace std;

// Конструктор по умолчанию
Harvest::Harvest() {
    crop = "Unknown";
    area = 1.0;
    yields.push_back(1.0); 
    yields.push_back(2.0);
}

// Конструктор с параметрами
Harvest::Harvest(string c, double a, vector<double> y) {
    crop = c;
    if (a > 0) area = a;
    else area = 1.0;
    yields = y;
}

// Конструктор без урожайностей
Harvest::Harvest(string c, double a) {
    crop = c;
    if (a > 0) area = a;
    else area = 1.0;
    yields.push_back(0.0); 
}

// Конструктор копирования
Harvest::Harvest(const Harvest &other) {
    crop = other.crop;
    area = other.area;
    yields = other.yields;
}

// Подсчет общего урожая
double Harvest::calculateTotalYield() {
    double total = 0;
    for (int i = 0; i < yields.size(); i++) {
        total = total + yields[i];
    }
    return total;
}

// Оператор сложения
Harvest Harvest::operator+(const Harvest &other) {
    Harvest result;
    result.crop = crop + " + " + other.crop; 
    result.area = area + other.area; 

    
    for (int i = 0; i < yields.size(); i++) {
        result.yields.push_back(yields[i]);
    }
    for (int i = 0; i < other.yields.size(); i++) {
        result.yields.push_back(other.yields[i]);
    }
    return result;
}

// Оператор присваивания
Harvest& Harvest::operator=(const Harvest &other) {
    crop = other.crop;
    area = other.area;
    yields = other.yields;
    return *this;
}

// Префиксный инкремент
Harvest& Harvest::operator++() {
    for (int i = 0; i < yields.size(); i++) {
        yields[i] = yields[i] + 1; 
    }
    return *this;
}

// Постфиксный инкремент
Harvest Harvest::operator++(int) {
    Harvest temp = *this;
    for (int i = 0; i < yields.size(); i++) {
        yields[i] = yields[i] + 1;
    }
    return temp;
}

// Сравнение по средней урожайности
bool Harvest::operator>(const Harvest &other) {
    double avgThis = calculateTotalYield() / yields.size();
    double avgOther = other.calculateTotalYield() / other.yields.size();
    return avgThis > avgOther;
}

// Оператор вывода
ostream& operator<<(ostream &os, const Harvest &h) {
    os << "Crop: " << h.crop << ", Area: " << h.area << " ha, Yields: ";
    for (int i = 0; i < h.yields.size(); i++) {
        os << h.yields[i] << " ";
    }
    os << "(Total: " << h.calculateTotalYield() << ")";
    return os;
}

// Оператор ввода
istream& operator>>(istream &is, Harvest &h) {
    cout << "Enter crop name: ";
    getline(is, h.crop);

    cout << "Enter area (ha): ";
    is >> h.area;
    if (h.area <= 0) h.area = 1.0;
    is.ignore(); 

    int years;
    cout << "How many years of yields? ";
    is >> years;
    is.ignore();

    h.yields.clear();
    for (int i = 0; i < years; i++) {
        double yield;
        cout << "Enter yield for year " << i + 1 << ": ";
        is >> yield;
        h.yields.push_back(yield);
    }
    is.ignore();
    return is;
}