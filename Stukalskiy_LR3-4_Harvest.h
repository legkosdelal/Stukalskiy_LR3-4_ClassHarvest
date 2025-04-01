#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Harvest {
private:
    string name;
    double area;
    vector<double> years;

public:
    Harvest();
    Harvest(string n, double a, vector<double> y);
    Harvest(const Harvest& other);

    string getName() { return name; }
    double getArea() { return area; }
    vector<double> getYears() { return years; }

    void setName(string n) { name = n; }
    void setArea(double a) { area = a; }
    void setYears(vector<double> y) { years = y; }

    double averageYield();
    double totalHarvest();

    bool operator==(Harvest& other);
    Harvest operator+(Harvest& other);
    void operator++();

    friend ostream& operator<<(ostream& os, Harvest& h);
    friend istream& operator>>(istream& is, Harvest& h);
};