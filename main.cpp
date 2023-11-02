#include <iostream>
#include <algorithm>


int task(int n) {
    if (n <= 0) {
        std::cout << "Размер массива должен быть положительным числом" << std::endl;
        return 0.;
    }

    double* arr = new double[n];

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    size_t minIndex = 0;
    size_t maxIndex = 0;

    for (int i = 0; i < n; i++) {
        double min = arr[minIndex];
        double max = arr[maxIndex];
        double target = arr[i];
        if (min >= target) {
            minIndex = i;
        }
        if (max <= target) {
            maxIndex = i;
        }
    }

    if (minIndex == maxIndex) {
        std::cout << "Максимальный и минимальный элемент - один и тот же элемент" << std::endl;
        return 0.;
    }

    double sum = 0;

    double min = std::min(minIndex, maxIndex);
    double max = std::max(minIndex, maxIndex);

    for (int i = min + 1; i < max; i++) {
        double target = arr[i];
        sum += target;
    }

    delete[] arr;
    return sum;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    std::cin >> n;
    double result = task(n);
    std::cout << result;
    return 0;
}
