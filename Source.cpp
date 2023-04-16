#include <stdexcept>
#include <iostream>
#include <numeric>
#include <string>
class Fraction {

public:

    Fraction(const int num = 0, const int den = 1);

    Fraction(const Fraction& other) = default;

    ~Fraction() = default;

    std::string toString() const;



    Fraction& operator+=(int a);

    friend bool operator==(const Fraction& left, const Fraction& rigth);

    friend const Fraction operator+(const Fraction& left, const Fraction& rigth);



private:

    void reduce();



private:

    int _numerator;

    int _denomenator;

};



Fraction::Fraction(const int num, const int den) {

    if (den == 0) {

        throw std::invalid_argument("denomenator can't be zero");

    }



    _numerator = num;

    _denomenator = den;



    reduce();

}



std::string Fraction::toString() const {

    if (_numerator == 0) {

        return "0";

    }



    if (_denomenator == 1) {

        return std::to_string(_numerator);

    }



    return std::to_string(_numerator) + "/" + std::to_string(_denomenator);

}



void Fraction::reduce() {

    auto gcd = std::gcd(std::abs(_numerator), _denomenator);



    if (gcd != 1) {

        _numerator /= gcd;

        _denomenator /= gcd;

    }

}


Fraction& Fraction::operator+=(int a) { //оператор прибавления
    int i = this->_denomenator * a; //переменная i равна знаменателю, умноженное на целое число. Фактически, мы перевели целое число в дробь. 
    this->_numerator += i; //прибавляем к числителю "i".
    return *this; //и возвращаем значение.
}



bool operator==(const Fraction& left, const Fraction& right) { //оператор сравнения
    if (left._numerator * right._denomenator == right._numerator * left._denomenator) { //если левый числитель, помноженный на правый знаменатель
        return true; //равен правому числителю и левому знаменателю, выводится 1.
    }
    else {
        return false; //если нет - 0.
    }

}



const Fraction operator+(const Fraction& left, const Fraction& right) { //оператор сложения.
    Fraction t;     //создаём временную дробь - t.
    t._denomenator = left._denomenator * right._denomenator; //её знаменатель - перемноженные левый и правый знаменатели.
    t._numerator = left._denomenator * right._numerator + right._denomenator * left._numerator; //а числитель - левый знаменатель, умноженный на правый 
    return t; //числитель + правый знаменатель на левый числитель.
}



int main() {

    Fraction a(1, 10);

    Fraction b(2, 5);

    std::cout << a.toString() << " " << b.toString() << " " <<"ravenstvo = " << (a == b) << "\n";

    a += 2;

    Fraction c(40, 20);

    std::cout << a.toString() << "\n";

    auto d = a + b; // при сложении случается ошибка, что из-за того, что мы прибавили к "a" 2 единицы в прошлом действии, в сложении они также участвуют.

    std::cout << d.toString() << " " << "\n";

}
