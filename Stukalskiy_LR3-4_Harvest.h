#ifndef HARVEST_H
#define HARVEST_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Harvest {
private:
    string crop; 
    double area; 
    vector<double> yields; 

public:
    Harvest(); // По умолчанию
    Harvest(string c, double a, vector<double> y); // С параметрами
    Harvest(string c, double a); // Без урожайностей
    Harvest(const Harvest &other); // Копирования

    // Деструктор
    ~Harvest() {}

    // Методы get и set
    string getCrop() { return crop; }
    void setCrop(string c) { crop = c; }

    double getArea() { return area; }
    void setArea(double a) { 
        if (a > 0) area = a; 
        else area = 1.0; 
    }

    vector<double> getYields() { return yields; }
    void setYields(vector<double> y) { yields = y; }
    double calculateTotalYield();

    Harvest operator+(const Harvest &other);
    Harvest& operator=(const Harvest &other);
    Harvest& operator++(); 
    Harvest operator++(int); 
    bool operator>(const Harvest &other);

    friend ostream& operator<<(ostream &os, const Harvest &h);
    friend istream& operator>>(istream &is, Harvest &h);
};

#endif