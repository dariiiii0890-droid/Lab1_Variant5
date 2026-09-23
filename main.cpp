#include <windows.h>

#include <cmath>
#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>
#include <tuple>

#include "shared_types.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    std::cout << "Лабораторна робота №1\n";
    std::cout << "Варіант 5 — обчислення визначника квадратної матриці\n";
    std::cout << "Студент А — метод Лапласа\n\n";

    std::size_t n = 0;

    std::cout << "Введіть розмір квадратної матриці n: ";
    std::cin >> n;

    if (!std::cin || n == 0)
    {
        std::cout << "Помилка: n повинно бути додатним числом.\n";
        return 1;
    }

    std::vector<std::vector<double>> matrix(
        n, std::vector<double>(n));

    std::cout << "\nВведіть елементи матриці:\n";

    for (std::size_t i = 0; i < n; ++i)
    {
        for (std::size_t j = 0; j < n; ++j)
        {
            std::cout << "A[" << i + 1 << "][" << j + 1 << "] = ";
            std::cin >> matrix[i][j];

            if (!std::cin)
            {
                std::cout << "Помилка: введено некоректне число.\n";
                return 1;
            }
        }
    }

    auto data = std::make_shared<const InputData>(
        InputData{matrix});

    // Виклик алгоритму Студента А.
    auto resultA = calculateA(data);

    // Structured binding — вимога лабораторної роботи.
    auto [determinant, operations, error] =
        std::tuple{resultA->determinant,
                   resultA->operations,
                   resultA->error};

    std::cout << "\nМатриця:\n";

    for (const auto& row : matrix)
    {
        for (const double value : row)
        {
            std::cout << std::setw(10)
                      << value << ' ';
        }

        std::cout << '\n';
    }

    if (!error.empty())
    {
        std::cout << "\nПомилка: " << error << '\n';
        return 1;
    }

    std::cout << std::fixed << std::setprecision(6);

    std::cout << "\nРезультат Студента А (метод Лапласа):\n";
    std::cout << "Визначник = " << determinant << '\n';
    std::cout << "Кількість операцій = "
              << operations << '\n';

    // Заготовка для другого учасника.
    auto resultB = calculateB(data);

    if (!resultB->error.empty())
    {
        std::cout << "\nСтудент Б: "
                  << resultB->error << '\n';
    }

    std::cout << "\nНатисніть Enter для завершення...";
    std::cin.ignore(10000, '\n');
    std::cin.get();

    return 0;
}
