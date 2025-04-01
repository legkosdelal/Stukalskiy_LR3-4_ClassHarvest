#include "Stukalskiy_LR3-4_Harvest.h"

Harvest::Harvest() : name("Без названия"), area(0) {}
Harvest::Harvest(string n, double a, vector<double> y) : name(n), area(a), years(y) {}
Harvest::Harvest(const Harvest& other) : name(other.name), area(other.area), years(other.years) {}


double Harvest::averageYield() {
    if (years.empty()) return 0;
    double sum = 0;
    for (double y : years) sum += y;
    return sum / years.size();
}

double Harvest::totalHarvest() {
    return area * averageYield();
}


bool Harvest::operator==(Harvest& other) {
    return this->averageYield() == other.averageYield();
}

Harvest Harvest::operator+(Harvest& other) {
    return Harvest(name + "+" + other.name, area + other.area, years);
}

void Harvest::operator++() {
    for (double& y : years) y += 1;
}


ostream& operator<<(ostream& os, Harvest& h) {
    os << "Культура: " << h.name << "\nПлощадь: " << h.area << " га\nУрожайность: ";
    for (double y : h.years) os << y << " ";
    return os;
}

istream& operator>>(istream& is, Harvest& h) {
    cout << "Название: ";
    is >> h.name;
    cout << "Площадь: ";
    is >> h.area;
    cout << "Урожайность по годам (через пробел, конец -1): ";
    double y;
    while (is >> y && y != -1) {
        h.years.push_back(y);
    }
    return is;
}