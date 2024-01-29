// Copyright 2023 Bikash Shrestha
#include "EDistance.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

// Constructor
EDistance::EDistance(const std::string& xSequenceIn, const std::
string& ySequenceIn) : xSequence(xSequenceIn), ySequence(ySequenceIn) {
    xLength = xSequence.length();
    yLength = ySequence.length();
    opt = new int*[xLength + 1];
    for (int i = 0; i <= xLength; i++) {
        opt[i] = new int[yLength + 1];
    }
}

// Destructor
EDistance::~EDistance() {
    for (int i = 0; i <= xLength; i++) {
        delete[] opt[i];
    }
    delete[] opt;
}

// Compute the edit distance
int EDistance::optDistance() {
    // Initialize the last row and column of the matrix
    for (int i = 0; i <= xLength; i++) {
        opt[i][yLength] = (xLength - i) * PG;
    }
    for (int j = 0; j <= yLength; j++) {
        opt[xLength][j] = (yLength - j) * PG;
    }

    // Compute the edit distance dynamically
    for (int i = xLength - 1; i >= 0; i--) {
        for (int j = yLength - 1; j >= 0; j--) {
            int cost = (xSequence[i] == ySequence[j]) ? 0 : PM;
            opt[i][j] = min3(
                opt[i + 1][j + 1] + cost,
                opt[i + 1][j] + PG,
                opt[i][j + 1] + PG);
        }
    }

    return opt[0][0];
}

// Compute the alignment
std::string EDistance::alignment() {
    std::stringstream alignment;
    int i = 0, j = 0;

    while (i < xLength && j < yLength) {
        if (xSequence[i] == ySequence[j] && opt[i][j] == opt[i + 1][j + 1]) {
            // Case 1: Characters match
            alignment << xSequence[i] << " " << ySequence[j] << " 0\n";
            i++;
            j++;
        } else if (xSequence[i] != ySequence[j] && opt[i][j] == opt[i + 1][j + 1] + PM) {
            // Case 1: Characters mismatch
            alignment << xSequence[i] << " " << ySequence[j] << " 1\n";
            i++;
            j++;
        } else if (opt[i][j] == opt[i + 1][j] + PG) {
            // Case 2: Gap in ySequence
            alignment << xSequence[i] << " - 2\n";
            i++;
        } else {
            // Case 3: Gap in xSequence
            alignment << "- " << ySequence[j] << " 2\n";
            j++;
        }
    }

    // Handle remaining characters in either sequence
    while (i < xLength) {
        alignment << xSequence[i] << " - 2\n";
        i++;
    }
    while (j < yLength) {
        alignment << "- " << ySequence[j] << " 2\n";
        j++;
    }

    return alignment.str();
}

// Helper functions
int EDistance::min3(int a, int b, int c) {
    return std::min({a, b, c});
}

// Penalty for a mismatch
int EDistance::penalty(char a, char b) {
    return (a == b) ? 0 : PM;
}
