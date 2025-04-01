#include <map>
using namespace std;

int main() {
    map<int, void(*)()> menu = {
        {1, addHarvest},
        {2, showAll},
        {3, testHarvest},
        {4, sortHarvest},
        {5, []() { cout << "Выход\n"; exit(0); }}
    };

    while (true) {
        cout << "\n1. Добавить урожай\n2. Показать все\n3. Тест\n4. Сортировать\n5. Выход\nВыберите: ";
        int choice;
        cin >> choice;
        if (menu.count(choice)) menu[choice]();
        else cout << "Ошибка!\n";
    }
}