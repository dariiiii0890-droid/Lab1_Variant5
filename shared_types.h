#pragma once

#include <string>
#include <vector>

struct InputData
{
    std::vector<std::vector<double>> matrix;
};

struct Result
{
    double determinant = 0.0;
    long long operations = 0;
    std::string error;
};

// Student A: Laplace expansion.
std::unique_ptr<Result> calculateA(
    std::shared_ptr<const InputData> input);

// Student B: triangular transformation (reserved for the second student).
std::unique_ptr<Result> calculateB(
    std::shared_ptr<const InputData> input);
