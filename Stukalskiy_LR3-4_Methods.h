#ifndef METHODS_H
#define METHODS_H

#include "Stukalskiy_LR3-4_Harvest.h"

using namespace std;

vector<Harvest> harvests;


bool isNumber(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9') return false;
    }
    return true;
}


int inputNumber(string message) {
    string input;
    cout << message;
    getline(cin, input);
    while (!isNumber(input)) {
        cout << "Please enter a number! " << message;
        getline(cin, input);
    }
    return atoi(input.c_str());
}

// Создание объекта конструктором по умолчанию
void createDefaultHarvest() {
    Harvest h;
    harvests.push_back(h);
    cout << "Created: " << h << endl;
}

// Создание объекта с параметрами
void createParameterizedHarvest() {
    string crop;
    double area;
    int years;
    vector<double> yields;

    cout << "Enter crop name: ";
    getline(cin, crop);

    area = inputNumber("Enter area (ha): ");
    years = inputNumber("How many years of yields? ");

    for (int i = 0; i < years; i++) {
        double yield = inputNumber("Enter yield for year " + to_string(i + 1) + ": ");
        yields.push_back(yield);
    }

    Harvest h(crop, area, yields);
    harvests.push_back(h);
    cout << "Created: " << h << endl;
}

// Создание объекта с консоли
void createHarvestFromConsole() {
    Harvest h;
    cin >> h;
    harvests.push_back(h);
    cout << "Created: " << h << endl;
}

// Показать все объекты
void showAllHarvests() {
    if (harvests.size() == 0) {
        cout << "No harvests yet!" << endl;
        return;
    }
    for (int i = 0; i < harvests.size(); i++) {
        cout << "Harvest " << i + 1 << ": " << harvests[i] << endl;
    }
}

// Подсчет общего урожая
void calculateTotalHarvest() {
    if (harvests.size() == 0) {
        cout << "No harvests yet!" << endl;
        return;
    }
    int index = inputNumber("Enter harvest number (1-" + to_string(harvests.size()) + "): ") - 1;
    if (index >= 0 && index < harvests.size()) {
        cout << "Total yield: " << harvests[index].calculateTotalYield() << endl;
    } else {
        cout << "Wrong number!" << endl;
    }
}

// Сложение двух объектов
void addHarvests() {
    if (harvests.size() < 2) {
        cout << "Need at least 2 harvests!" << endl;
        return;
    }
    int idx1 = inputNumber("Enter first harvest number (1-" + to_string(harvests.size()) + "): ") - 1;
    int idx2 = inputNumber("Enter second harvest number (1-" + to_string(harvests.size()) + "): ") - 1;
    if (idx1 >= 0 && idx1 < harvests.size() && idx2 >= 0 && idx2 < harvests.size()) {
        Harvest result = harvests[idx1] + harvests[idx2];
        cout << "Result: " << result << endl;
    } else {
        cout << "Wrong numbers!" << endl;
    }
}

// Сортировка по средней урожайности
void sortByAverageYield() {
    if (harvests.size() == 0) {
        cout << "No harvests yet!" << endl;
        return;
    }
    // Сортировка 
    for (int i = 0; i < harvests.size() - 1; i++) {
        for (int j = 0; j < harvests.size() - i - 1; j++) {
            if (harvests[j] > harvests[j + 1]) {
                Harvest temp = harvests[j];
                harvests[j] = harvests[j + 1];
                harvests[j + 1] = temp;
            }
        }
    }
    cout << "Sorted harvests:" << endl;
    showAllHarvests();
}

#endif