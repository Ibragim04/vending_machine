#include <iostream>
#include <string>

class cashRegister {
private:
    int cashOnHand;
public:
    cashRegister() : cashOnHand(500) {} // Конструктор по умолчанию
    cashRegister(int cash) : cashOnHand(cash) {} // Пользовательский конструктор

    int getCurrentBalance() const {
        return cashOnHand;
    }

    void acceptAmount(int amount) {
        cashOnHand += amount;
    }
};

class dispenserType {
private:
    int numberOfItems;
    int itemCost;
public:
    dispenserType() : numberOfItems(50), itemCost(50) {} // Конструктор по умолчанию
    dispenserType(int items, int cost) : numberOfItems(items), itemCost(cost) {} // Пользовательский конструктор

    int getNoOfItems() const {
        return numberOfItems;
    }

    int getCost() const {
        return itemCost;
    }

    void makeSale() {
        if (numberOfItems > 0) {
            numberOfItems--;
        }
    }
};

void showSelection() {
    std::cout << "1. Конфеты\n";
    // Добавьте другие продукты по аналогии
}

void sellProduct(dispenserType& dispenser, cashRegister& cashReg) {
    int selection;
    std::cout << "Сделайте выбор: ";
    std::cin >> selection;

    switch (selection) {
        case 1:
            std::cout << "Конфеты выбраны.\n";
            std::cout << "Стоимость: " << dispenser.getCost() << " рублей.\n";
            std::cout << "Внесите деньги: ";
            int amount;
            std::cin >> amount;
            if (amount >= dispenser.getCost()) {
                dispenser.makeSale();
                cashReg.acceptAmount(dispenser.getCost());
                std::cout << "Спасибо за покупку! Ваша сдача: " << (amount - dispenser.getCost()) << " рублей.\n";
            } else {
                std::cout << "Недостаточно средств.\n";
            }
            break;
        default:
            std::cout << "Неверный выбор.\n";
    }
}

int main() {
    dispenserType candyDispenser;
    cashRegister registerMachine;

    showSelection();
    sellProduct(candyDispenser, registerMachine);

    return 0;
}
