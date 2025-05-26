#include "Stukalskiy_LR3-4_Harvest.h"
#include "Stukalskiy_LR3-4_Methods.h"
#include <map>

using namespace std;

int main() {
    struct MenuItem {
        string title;
        void (*action)();
    };

    map<int, MenuItem> menu;
    menu[1] = {"Create default harvest", createDefaultHarvest};
    menu[2] = {"Create parameterized harvest", createParameterizedHarvest};
    menu[3] = {"Create harvest from console", createHarvestFromConsole};
    menu[4] = {"Show all harvests", showAllHarvests};
    menu[5] = {"Calculate total yield", calculateTotalHarvest};
    menu[6] = {"Add two harvests", addHarvests};
    menu[7] = {"Sort by average yield", sortByAverageYield};

    int choice = 0;
    while (true) {
        cout << "Menu:" << endl;
        for (int i = 1; i <= 7; i++) {
            cout << i << ". " << menu[i].title << endl;
        }
        cout << "0. Exit" << endl;

        choice = inputNumber("Enter your choice: ");
        if (choice == 0) {
            cout << "Exiting. Surname 2025" << endl;
            break;
        }

        cout << "========== Action: ==========" << endl;
        if (choice >= 1 && choice <= 7) {
            menu[choice].action();
        } else {
            cout << "Wrong choice!" << endl;
        }
    }

    return 0;
}