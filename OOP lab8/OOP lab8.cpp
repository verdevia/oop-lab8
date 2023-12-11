#include <iostream>
using namespace std;

class Pair {
public:
    int first;
    int second;

    Pair() : first(0.0), second(0.0) {}
    Pair(int a, int b) : first(a), second(b) {}

    // Метод множення на число
    Pair multiply(int factor) {
        return Pair(first * factor, second * factor);
    }

    // Операція додавання пар
    Pair operator+(const Pair& other) {
        return Pair(first + other.first, second + other.second);
    }
    Pair inPair()
    {
        int f, s;
        cout << "Enter first element\n";
        cin >> f;
        cout << "Enter second element\n";
        cin >> s;
        return Pair(f, s);
    }

};

class Money : public Pair {
public:
    Money(int hryvnia = 0, int kopiyka = 0) : Pair(hryvnia, kopiyka) {}
    

    // Перевизначення операції додавання
    Money operator+(const Money& other) {
        return Money(first + other.first, second + other.second);
    }

    // Метод віднімання грошових сум
    Money subtract(const Money& other) {
        return Money(first - other.first, second - other.second);
    }

    // Метод ділення грошових сум
    Money divide(const Money& other) {
        return Money(first / other.first, second / other.second);
    }
    Money inMoney()
    {
        cout << "Enter first element\n";
        cin >> first;
        cout << "Enter second element\n";
        cin >> second;
        return Money(first, second);
    }

    Money display()
    {
        Money temp;
        temp.first = first;
        temp.second = second;
        cout << "Values are (" << temp.first << " hrivnyas; " << temp.second << " kopiykas)" << endl;
        return temp;
    }

};


int main() {
    Money mObj1, mObj2;
    cout << "Enter money values num1\n";
    mObj1.inMoney();
    cout << endl;

    cout << "Enter money values num2\n";
    mObj2.inMoney();
    cout << endl;

    mObj1.display();
    mObj2.display();
    

    // Використання операції додавання для об'єктів Money
    Money sumMoney = mObj1 + mObj2;
    Money subMoney = mObj1.subtract(mObj2);
    Money divMoney = mObj1.divide(mObj2);

    // Друк результату
    cout << "Sum of Money: (" << sumMoney.first << " hryvnia, " << sumMoney.second << " kopiyka)\n";
    cout << "Sub of Money: (" << subMoney.first << " hryvnia, " << subMoney.second << " kopiyka)\n";
    cout << "Div of Money: (" << divMoney.first << " hryvnia, " << divMoney.second << " kopiyka)\n";

    return 0;
}
