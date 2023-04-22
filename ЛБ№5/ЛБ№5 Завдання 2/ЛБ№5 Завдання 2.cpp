#include <iostream>
#include <cstring>

using namespace std;

// Клас жорсткого диску
class HardDrive {
private:
    int m_storage; // обсяг в Мбайтах

public:
    // Конструктори
    HardDrive() : m_storage(0) {}
    HardDrive(int storage) : m_storage(storage) {}

    // Метод доступу
    int getStorage() const { return m_storage; }
};

// Клас комп'ютера
class Computer {
private:
    char* m_brand; // марка
    int m_price; // ціна
    HardDrive m_hardDrive; // жорсткий диск

public:
    // Конструктори та деструктор
    Computer() : m_brand(nullptr), m_price(0), m_hardDrive(HardDrive()) {}
    Computer(const char* brand, int price, int storage) : m_price(price), m_hardDrive(HardDrive(storage)) {
        m_brand = new char[strlen(brand) + 1];
        strcpy_s(m_brand, strlen(brand) + 1, brand);

    }
    ~Computer() {
        delete[] m_brand;
    }

    // Метод доступу
    const char* getBrand() const { return m_brand; }
    int getPrice() const { return m_price; }
    int getStorage() const { return m_hardDrive.getStorage(); }
};

// Похідний клас комп'ютерів з монітором
class ComputerWithMonitor : public Computer {
private:
    int m_monitorSize; // розмір монітора

public:
    // Конструктори та деструктор
    ComputerWithMonitor() : m_monitorSize(0) {}
    ComputerWithMonitor(const char* brand, int price, int storage, int monitorSize) : Computer(brand, price, storage), m_monitorSize(monitorSize) {}
    ~ComputerWithMonitor() {}

    // Функція друку
    void print() const {
        cout << "Brand: " << getBrand() << endl;
        cout << "Price: " << getPrice() << endl;
        cout << "Hard Drive Storage: " << getStorage() << " MB" << endl;
        cout << "Monitor Size: " << m_monitorSize << " inches" << endl;
    }
};

// Функція main
int main() {
    ComputerWithMonitor myComputer("Dell", 1000, 500, 24);
    myComputer.print();

    return 0;
}
