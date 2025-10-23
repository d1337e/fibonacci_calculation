#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

/* определение максимального значения типа unsigned long long */
const unsigned long long MAX_ULL = numeric_limits<unsigned long long>::max();

/**
 * @brief перечисление методов вычисления для чисел Фибоначчи
 * @param ITERARION итерационный метод
 * @param BINE метод Бине
 */
enum {
    ITERATION = 1,
    BINE = 2
};

/* рассчитываем золотое сечение и сопряженное к нему */
const double q1 = (1.0 + sqrt(5.0)) / 2.0;
const double q2 = (1.0 - sqrt(5.0)) / 2.0;

/**
 * @brief точка входа в программу
 * @return 0 при успешном выполнении программы
 */
int main(void) {

    cout << "Выберите метод вычисления чисел Фибоначчи" << endl;
    cout << "1. Метод итерации\n2. Метод Бине\n";
    int choice = 0;
    cin >> choice;

    switch (choice) {
        case ITERATION: {
            int n = 0;
            cout << "Введите кол-во чисел, которое хотите рассчитать: ";
            cin >> n;
            if (n < 0)
                throw invalid_argument("ERROR: Кол-во чисел не может быть меньше нуля");
            if (n >= 1)
                cout << "f(1) = 1" << endl;
            if (n >= 2) {
                cout << "f(2) = 1" << endl;
            }
            if (n > 2) {
                unsigned long long x1 = 1, x2 = 1;
                //bool overflow = false;
                for (int i = 3; i <= n; i++) {

                    if (MAX_ULL - x1 < x2) {
                        cout << "ERROR: Переполнение на шаге i = " << i << ". Дальнейшие вычисления не имеют смысла (переполнение типа)" << endl;
                        throw __throw_overflow_error;
                    }
                    unsigned long long temp = x1 + x2;
                    x1 = x2;
                    x2 = temp;
                    cout << "f(" << i << ") = " << temp << endl;
                }
            }


            break;
        }
        case BINE: {
            int n = 0;
            cout << "Введите номер (n) числа Фибоначчи, которое хотите рассчитать: ";
            cin >> n;

            if (n < 0)
                throw invalid_argument("ERROR: Номер числа не может быть отрицательным");
            if (n == 0) {
                cout << "f(0) = 0" << endl;
                break;
            }

            long double fib_double = (pow(q1, n) - pow(q2, n)) / sqrt(5.0);

            if (fib_double > MAX_ULL) {
                cout << "ERROR: Не могу такое посчитать (переполнение типа)" << endl;
                throw __throw_overflow_error;
            }

            unsigned long long fib_int = (unsigned long long)round(fib_double);

            cout << "f(" << n << ") = " << fib_int << endl;
            break;
        }
        default:
            throw invalid_argument("ERROR: Ошибка при выборе метода");
    }

    return 0;
}
