#include "shared_types.h"

#include <memory>

std::unique_ptr<Result> calculateB(
    std::shared_ptr<const InputData> input)
{
    auto result = std::make_unique<Result>();

    (void)input;

    result->error =
        "Алгоритм Студента Б ще не реалізований.";

    return result;
}
