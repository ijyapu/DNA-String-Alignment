// Copyright 2023 Bikash Shrestha
#include <iostream>
#include <chrono>
#include "EDistance.hpp"

int main() {
    std::string seq1, seq2;
    std::cin >> seq1 >> seq2;

    // Start time measurement
    auto start = std::chrono::high_resolution_clock::now();

    EDistance seqED(seq1, seq2);
    int eDist = seqED.optDistance();
    std::string alignment = seqED.alignment();

    // End time measurement
    auto end = std::chrono::high_resolution_clock::now();
    // Compute the difference between the two times in seconds
    std::chrono::duration<double> elapsed = end - start;

    // Output results
    std::cout << "Edit distance = " << eDist << "\n";
    std::cout << alignment << std::endl;
    std::cout << "Execution time is " << elapsed.count() << " seconds \n";

    return 0;
}
