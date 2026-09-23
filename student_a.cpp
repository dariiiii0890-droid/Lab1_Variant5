#include "shared_types.h"

#include <cmath>
#include <memory>
#include <vector>

namespace
{
    double determinantLaplace(
        const std::vector<std::vector<double>>& matrix,
        long long& operations)
    {
        const std::size_t n = matrix.size();

        if (n == 1)
        {
            ++operations;
            return matrix[0][0];
        }

        if (n == 2)
        {
            operations += 2;
            return matrix[0][0] * matrix[1][1]
                 - matrix[0][1] * matrix[1][0];
        }

        double determinant = 0.0;

        // Розклад визначника за першим рядком.
        for (std::size_t column = 0; column < n; ++column)
        {
            std::vector<std::vector<double>> minor(
                n - 1, std::vector<double>(n - 1));

            for (std::size_t row = 1; row < n; ++row)
            {
                std::size_t minorColumn = 0;

                for (std::size_t sourceColumn = 0;
                     sourceColumn < n;
                     ++sourceColumn)
                {
                    if (sourceColumn == column)
                    {
                        continue;
                    }

                    minor[row - 1][minorColumn] =
                        matrix[row][sourceColumn];

                    ++minorColumn;
                }
            }

            const double minorDeterminant =
                determinantLaplace(minor, operations);

            const double sign =
                (column % 2 == 0) ? 1.0 : -1.0;

            determinant +=
                sign * matrix[0][column] * minorDeterminant;

            operations += 2;
        }

        return determinant;
    }
}

std::unique_ptr<Result> calculateA(
    std::shared_ptr<const InputData> input)
{
    auto result = std::make_unique<Result>();

    if (!input)
    {
        result->error = "Вхідні дані не задані.";
        return result;
    }

    const auto& matrix = input->matrix;

    if (matrix.empty())
    {
        result->error = "Матриця не може бути порожньою.";
        return result;
    }

    const std::size_t n = matrix.size();

    for (const auto& row : matrix)
    {
        if (row.size() != n)
        {
            result->error = "Матриця повинна бути квадратною.";
            return result;
        }
    }

    result->determinant = determinantLaplace(
        matrix,
        result->operations);

    return result;
}
