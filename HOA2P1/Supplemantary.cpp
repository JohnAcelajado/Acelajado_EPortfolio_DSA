#include <iostream>
#include <string>

// Problem 1: Create a class for the item
class Item {
private:
    std::string itemName;
    int itemPrice, Quantity;

public:
    Item(std::string newItem = "Apple", int newPrice = 10, int quantity = 1) {
        itemName = newItem;
        itemPrice = newPrice;
        Quantity = quantity;
    }

    ~Item() {}

    Item(const Item &copyItem) {
        itemName = copyItem.itemName;
        itemPrice = copyItem.itemPrice;
        Quantity = copyItem.Quantity; 
    }

    Item& operator=(const Item &t) {
        if (this != &t) {
            itemName = t.itemName;
            itemPrice = t.itemPrice;
            Quantity = t.Quantity;
        }
        return *this;
    }

    void printDetails() {
        std::cout << itemName << " PHP" << itemPrice << " * " << Quantity << std::endl;
    }

    int Sum() {
        return (this->itemPrice) * (this->Quantity);
    }
};

// Problem 3: TotalSum Function using pointers
int TotalSum(int ArrSize, Item* List[]) {
    int Total = 0;
    for (int i = 0; i < ArrSize; i++) {
        if (List[i] != nullptr) { 
            Total += List[i]->Sum();
        }
    }
    return Total;
}

int main() {
    const size_t j = 4;

    // Problem 2: Grocery List Array 
    Item* GroceryList[j] = {}; 

    std::string nameList[j] = {"Apple ", "Banana ", "Broccoli ", "Lettuce "};
    int priceList[j] = {12, 13, 50, 80};
    int qtyLists[j] = {9, 4, 11, 7};

    // Allocate memory for the items
    for(int i = 0; i < j; i++) {
        Item *ptr = new Item(nameList[i], priceList[i], qtyLists[i]);
        GroceryList[i] = ptr; 
    }

    // Print the complete Grocery List
    std::cout << "Grocery List" << std::endl;
    for(int i = 0; i < j; i++) {
        if (GroceryList[i] != nullptr) {
            GroceryList[i]->printDetails(); 
        }
    } 

    // Problem 3 & 4: Total & Deallocation
    std::cout << "Total:\tPHP " << TotalSum(j, GroceryList) << std::endl;

    // Safely delete Lettuce
    delete GroceryList[3]; 
    GroceryList[3] = nullptr; 

    std::cout << "Total after deleting Lettuce:\tPHP " << TotalSum(j, GroceryList) << std::endl;

    // Clean up remaining dynamically allocated items
    for (size_t i = 0; i < j; i++) {
        if (GroceryList[i] != nullptr) {
            delete GroceryList[i];
        }
    }

    return 0;
}