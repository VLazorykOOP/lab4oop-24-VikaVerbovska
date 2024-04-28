//     1 Задача:   Створити тип даних - клас вектор VectorFloat (вектор дійсних чисел), який має 
//                 вказівник на float, число елементів size і змінну стану codeError.У класі визначити
//                   o конструктор без параметрів(виділяє місце для одного елемента та інінціалізує
//                 його в нуль);
//                 o конструктор з одним параметром - розмір вектора(виділяє місце та інінціалізує
//               масив значенням нуль);
//                   o конструктор із двома параметрами - розмір вектора та значення
//                 ініціалізації(виділяє місце(значення перший аргумент) та інінціалізує значенням
//               другого аргументу).
//                   o деструктор звільняє пам'ять;
//                   o перевантаження операцій(операції перевантажувати через функції класу або
//               дружні функції, якщо не вказано яким чином це робити) :
//                      унарних префіксних та постфіксних ++ та-- : одночасно збільшує
//                    (зменшує) значення елементів масиву на 1.0;
//                      унарної логічної !(заперечення) : повертає значення true, якщо
//                     елементи якщо size не дорівнює – нулю, інакше false;
//                     унарний арифметичний - (мінус) : повертає всі елементи масиву класу
//                     вектор з протилежним знаком;
//                      присвоєння = : копіює вектор(перевантажити через функцію класу);
//                      присвоєння з(перевантажити через функцію класу)
//                   o += -додаванням векторів;
//                   o -= -відніманням векторів; :
//                   o *= -множення, вектора на число;
//                   o /= -ділення, вектора на число;
//                   o %= -остача від ділення, вектора на число;
//                      арифметичних бінарні :
//                   o + -додавання векторів;
//                   o – - віднімання векторів;
//                   o * -множення, вектора на число;
//                   o / -ділення, вектора на число;
//                   o % -остача від ділення, вектора на число типу int;
//
//
//      2 Задача:    Побудувати асоційований клас збереження двох сутностей.
//                   В завданні створити клас, який представляє собою асоціативний масив між двома сутностями.
//                   Написати функцію створення набору асоціативних сутностей.
//                   Перевантажити операцію індексації [] – функцію, яка звертається до об’єкта класу, 
//                   за однією сутністю, якщо індекс, повертаєасоціативну сутність
//                   якщо відповідної сутності немає в встановлює код помилки у змінну CodeError, 
//                   альтернативні звернення через перевантаження операції виклику функції(); 
//                   перевантажити дружні операції введення та виведення
//                                "Назви країни та столиця"
//

#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

class VectorFloat
{
private:
    float* pointer;
    int size;
    bool codeError;

public:
    // Конструктори
    VectorFloat() : size(1), codeError(false) {
        pointer = new float[size];
        pointer[0] = 0.0f;
}

    VectorFloat(int newSize) : size(newSize), codeError(false) { 
        pointer = new float[size];
        for (int i = 0; i < size; ++i) {
            pointer[i] = 0.0f;
        }
    }
    // Конструктор з розміром та значенням ініціалізації
    VectorFloat(int newSize, float initValue) : size(newSize), codeError(false) { 
        pointer = new float[size];
        for (int i = 0; i < size; ++i) {
            pointer[i] = initValue;
        }
    }

    // Деструктор
    ~VectorFloat() {
        delete[] pointer;
    }

    // Оператори
    VectorFloat& operator=(const VectorFloat& other) { // Оператор присвоєння
        if (this != &other) {
            delete[] pointer;
            size = other.size;
            pointer = new float[size];
            for (int i = 0; i < size; ++i) {
                pointer[i] = other.pointer[i];
            }
        }
        return *this;
    }

    VectorFloat& operator+=(const VectorFloat& other) { // Оператор додавання
        for (int i = 0; i < size; ++i) {
            pointer[i] += other.pointer[i];
        }
        return *this;
    }

    VectorFloat& operator-=(const VectorFloat& other) { // Оператор віднімання
        for (int i = 0; i < size; ++i) {
            pointer[i] -= other.pointer[i];
        }
        return *this;
    }

    VectorFloat& operator*=(float scalar) { // Оператор множення на скаляр
        for (int i = 0; i < size; ++i) {
            pointer[i] *= scalar;
        }
        return *this;
    }

    VectorFloat& operator/=(float scalar) { // Оператор ділення на скаляр
        if (scalar != 0.0f) {
            for (int i = 0; i < size; ++i) {
                pointer[i] /= scalar;
            }
        }
        return *this;
    }

    VectorFloat& operator%=(float scalar) { // Оператор залишку від ділення на скаляр
        if (scalar != 0.0f) {
            for (int i = 0; i < size; ++i) {
                pointer[i] = fmod(pointer[i], scalar);
            }
        }
        return *this;
    }

    VectorFloat operator+() const { // Унарний плюс
        VectorFloat result(*this);
        return result;
    }

    VectorFloat operator-() const { // Унарний мінус
        VectorFloat result(*this);
        for (int i = 0; i < size; ++i) {
            result.pointer[i] = -result.pointer[i];
        }
        return result;
    }

    VectorFloat operator++(int) { // Постфіксний інкремент
        VectorFloat result(*this);
        for (int i = 0; i < size; ++i) {
            pointer[i] += 1.0f;
        }
        return result;
    }

    VectorFloat& operator++() { // Префіксний інкремент
        for (int i = 0; i < size; ++i) {
            pointer[i] += 1.0f;
        }
        return *this;
    }

    VectorFloat operator--(int) { // Постфіксний декремент
        VectorFloat result(*this);
        for (int i = 0; i < size; ++i) {
            pointer[i] -= 1.0f;
        }
        return result;
    }

    VectorFloat& operator--() { // Префіксний декремент
        for (int i = 0; i < size; ++i) {
            pointer[i] -= 1.0f;
        }
        return *this;
    }

    bool operator!() const { // Логічний оператор "заперечення"
        return size != 0;
    }

    // Дружні функції
    friend void selectTask();
    friend VectorFloat operator+(const VectorFloat& vec1, const VectorFloat& vec2); // Додавання векторів
    friend VectorFloat operator-(const VectorFloat& vec1, const VectorFloat& vec2); // Віднімання векторів
    friend VectorFloat operator*(const VectorFloat& vec, float scalar); // Множення вектора на скаляр
    friend VectorFloat operator*(float scalar, const VectorFloat& vec); // Множення скаляра на вектор
    friend VectorFloat operator/(const VectorFloat& vec, float scalar); // Ділення вектора на скаляр
    friend VectorFloat operator%(const VectorFloat& vec, int mod); // Залишок від ділення вектора на скаляр
};

VectorFloat operator+(const VectorFloat& vec1, const VectorFloat& vec2) { // Оператор додавання
    VectorFloat result(vec1);
    result += vec2;
    return result;
}

VectorFloat operator-(const VectorFloat& vec1, const VectorFloat& vec2) { // Оператор віднімання
    VectorFloat result(vec1);
    result -= vec2;
    return result;
}

VectorFloat operator*(const VectorFloat& vec, float scalar) { // Оператор множення на скаляр
    VectorFloat result(vec);
    result *= scalar;
    return result;
}

VectorFloat operator*(float scalar, const VectorFloat& vec) { // Оператор множення скаляра на вектор
    return vec * scalar;
}

VectorFloat operator/(const VectorFloat& vec, float scalar) { // Оператор ділення на скаляр
    VectorFloat result(vec);
    result /= scalar;
    return result;
}

VectorFloat operator%(const VectorFloat& vec, float mod) { // Оператор залишку від ділення на скаляр
    VectorFloat result(vec);
    result %= mod;
    return result;
}


class AssociatedEntities {
private:
    std::map<std::string, std::string> entities; // Асоціативний масив між двома сутностями
    bool codeError; 

public:
    // Конструктор за замовчуванням
    AssociatedEntities() : codeError(false) {}

    // Функція для створення набору асоціативних сутностей
    void createEntities(const std::string& country, const std::string& capital) {
        entities[country] = capital;
    }

    // Перевантажена операція індексації
    std::string& operator[](const std::string& key) {
        if (entities.find(key) != entities.end()) {
            codeError = false;
            return entities[key];
        }
        else {
            codeError = true;
            static std::string empty;
            return empty;
        }
    }

    // Перевантажена операція виклику функції
    std::string& operator()(const std::string& key) {
        return (*this)[key];
    }

    // Дружня функція для введення
    friend std::istream& operator>>(std::istream& input, AssociatedEntities& obj);

    // Дружня функція для виведення
    friend std::ostream& operator<<(std::ostream& output, const AssociatedEntities& obj);
};

// Дружня функція для введення
std::istream& operator>>(std::istream& input, AssociatedEntities& obj) {
    std::string country, capital;
    std::cout << "Enter country: ";
    input >> country;
    std::cout << "Enter capital: ";
    input >> capital;
    obj.createEntities(country, capital);
    return input;
}

// Дружня функція для виведення
std::ostream& operator<<(std::ostream& output, const AssociatedEntities& obj) {
    for (const auto& pair : obj.entities) {
        output << "Country: " << pair.first << ", Capital: " << pair.second << std::endl;
    }
    return output;
}


void selectTask() {
    int choice;
    std::cout << "Choose a task:" << std::endl;
    std::cout << "1." << std::endl;
    std::cout << "2." << std::endl;
    std::cout << "Enter your choice (1 or 2): ";
    std::cin >> choice;

    switch (choice) {
    
    case 1: {
        // Робота з класом VectorFloat
        VectorFloat vec1(3, 2.0f); // Створення вектора розміром 3 з усіма значеннями 2.0
        VectorFloat vec2(3, 1.0f); // Створення вектора розміром 3 з усіма значеннями 1.0

        VectorFloat result = vec1 + vec2; // Додавання векторів
        std::cout << "Result of addition: ";
        for (int i = 0; i < result.size; ++i) { // Виведення результату
            std::cout << result.pointer[i] << " ";
        }
        std::cout << std::endl;
        break;
    }
           case 2: {
        // Робота з класом AssociatedEntities
        AssociatedEntities countries;

        // Додавання асоціативних сутностей
        countries.createEntities("Ukraine", "Kyiv");
        countries.createEntities("USA", "Washington, D.C.");

        std::cout << "Associated entities:" << std::endl;
        std::cout << countries;

        // Звернення до асоціативних сутностей за допомогою індексації та операції виклику функції
        std::cout << "Capital of Ukraine: " << countries["Ukraine"] << std::endl;
        std::cout << "Capital of USA: " << countries("USA") << std::endl;
        break;
    }
    default:
        std::cout << "Invalid choice! Please enter 1 or 2." << std::endl;
        break;
    }
}
