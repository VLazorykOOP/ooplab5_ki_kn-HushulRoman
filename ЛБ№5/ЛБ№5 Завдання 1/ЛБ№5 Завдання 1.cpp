#include <iostream>
#include <string>
#include <random>
#include <fstream>

using namespace std;

class Window {

private:
    int m_x1, m_y1, m_x2, m_y2;
    string m_bgColor;

public:
    // constructors
    Window() : m_x1(0), m_y1(0), m_x2(0), m_y2(0), m_bgColor("white") {
        cout << "Window created with default values.\n";
    }
    Window(int x1, int y1, int x2, int y2, const string& bgColor)
        : m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2), m_bgColor(bgColor) {
        cout << "Window created with custom values.\n";
    }
    Window(const Window& other)
        : m_x1(other.m_x1), m_y1(other.m_y1), m_x2(other.m_x2), m_y2(other.m_y2), m_bgColor(other.m_bgColor) {
        cout << "Window copied.\n";
    }
    // destructor
    virtual ~Window() {
        cout << "Window destroyed.\n";
    }
    // print function
    void print() const {
        cout << "Window coordinates: (" << m_x1 << "," << m_y1 << ") - (" << m_x2 << "," << m_y2
            << "), Background color: " << m_bgColor << endl;
    }
    // getters
    int getX1() const { return m_x1; }
    int getY1() const { return m_y1; }
    int getX2() const { return m_x2; }
    int getY2() const { return m_y2; }
    string getBgColor() const { return m_bgColor; }
    // setters
    void setBgColor(const string& bgColor) { m_bgColor = bgColor; }
};

class MenuWindow : public Window {
private:
    string m_menuString;

public:
    // constructors
    MenuWindow() : Window(), m_menuString("") {
        cout << "MenuWindow created with default values.\n";
    }
    MenuWindow(int x1, int y1, int x2, int y2, const string& bgColor, const string& menuString)
        : Window(x1, y1, x2, y2, bgColor), m_menuString(menuString) {
        cout << "MenuWindow created with custom values.\n";
    }
    MenuWindow(const MenuWindow& other) : Window(other), m_menuString(other.m_menuString) {
        cout << "MenuWindow copied.\n";
    }
    // destructor
    virtual ~MenuWindow() {
        cout << "MenuWindow destroyed.\n";
    }
    // print function
    void print() const {
        cout << "MenuWindow coordinates: (" << getX1() << "," << getY1() << ") - (" << getX2() << "," << getY2()
            << "), Background color: " << getBgColor() << ", Menu string: " << m_menuString << endl;
    }
    // getters
    string getMenuString() const { return m_menuString; }
    // setters
    void setMenuString(const string& menuString) { m_menuString = menuString; }
};

int main() {
int x1, y1, x2, y2;
string bgColor, menuString;

cout << "1 method Input from the keyboard" << endl;
// Ввід даних з клавіатури
cout << endl;
cout << "Enter the coordinates of the window (x1 y1 x2 y2): ";
cin >> x1 >> y1 >> x2 >> y2;
cout << "Enter the background color of the window: ";
cin >> bgColor;
cout << "Enter the menu string: ";
cin >> menuString;
cout << endl;

// Створення об'єкту класу MenuWindow з введеними даними
MenuWindow menu(x1, y1, x2, y2, bgColor, menuString);

// Виведення інформації про об'єкт
menu.print();

// Зміна значення поля m_menuString
menu.setMenuString("New menu string");

// Виведення інформації про об'єкт після зміни значення поля m_menuString
menu.print();
cout << endl;
cout << "2 method Number generator"<< endl;

// спосіб 2: через генератор чисел
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> distrib(0, 100);

// Генерація координат та кольору
int x1_rand = distrib(gen);
int y1_rand = distrib(gen);
int x2_rand = distrib(gen);
int y2_rand = distrib(gen);
string bgColor_rand = "black";

// Створення об'єкту класу MenuWindow з випадковими координатами та заданим кольором
MenuWindow menu_rand(x1_rand, y1_rand, x2_rand, y2_rand, bgColor_rand, menuString);

// Виведення інформації про об'єкт з випадковими координатами та заданим кольором
menu_rand.print();

// Зміна значення поля m_menuString
menu_rand.setMenuString("New menu string");

// Виведення інформації про об'єкт з випадковими координатами та заданим кольором після зміни значення поля m_menuString
menu_rand.print();
cout << endl;
 cout << "3 method from file" << endl;
// спосіб 3: через файл
ifstream file("Window.txt");
if (!file.is_open()) {
    cerr << "Error opening file!" << endl;
    return 1;
}
cout << endl;

// Зчитування координат та кольору з файлу
file >> x1 >> y1 >> x2 >> y2 >> bgColor;

// Створення об'єкту класу Window з координатами та кольором зчитаними з файлу
Window window_file(x1, y1, x2, y2, bgColor);
     
// Виведення інформації про об'єкт
window_file.print();

// Закриття файлу
file.close();

return 0;

}
