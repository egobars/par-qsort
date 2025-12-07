#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <random>

#include "src/seqsort.h"
#include "src/parsort.h"

int main() {
    size_t data_size = 100000000;
    std::vector<int> data(data_size);
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, data_size - 1);
    
    for (size_t i = 0; i < data_size; i++) {
        data[i] = dis(gen);
    }
    size_t num_runs = 5;

    std::chrono::duration<double> seq_total_elapsed;
    for (size_t i = 0; i < num_runs; i++) {
        auto seq_data = data;
        auto start = std::chrono::high_resolution_clock::now();
        seqsort(seq_data);
        auto end = std::chrono::high_resolution_clock::now();
        seq_total_elapsed += end - start;
    }
    auto seq_average_elapsed = seq_total_elapsed.count() / num_runs;
    std::cout << "Среднее время сортировки последовательной версии: " << std::fixed << std::setprecision(2)
        << seq_average_elapsed << " секунд" << std::endl;

    std::chrono::duration<double> par_total_elapsed;
    for (size_t i = 0; i < num_runs; i++) {
        auto par_data = data;
        auto start = std::chrono::high_resolution_clock::now();
        parsort(par_data);
        auto end = std::chrono::high_resolution_clock::now();
        par_total_elapsed += end - start;
    }
    auto par_average_elapsed = par_total_elapsed.count() / num_runs;
    std::cout << "Среднее время сортировки параллельной версии: " << std::fixed << std::setprecision(2)
        << par_average_elapsed << " секунд" << std::endl;

    std::cout << "Ускорение: " << std::fixed << std::setprecision(2) << seq_average_elapsed / par_average_elapsed << " раз" << std::endl;
    return 0;
}
