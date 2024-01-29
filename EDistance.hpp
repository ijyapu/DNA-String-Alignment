// Copyright 2023 Bikash Shrestha
#ifndef EDISTANCE_HPP
#define EDISTANCE_HPP

#include <string>
#include <sstream>

class EDistance {
 public:
    EDistance(const std::string& xSequenceIn, const std::string& ySequenceIn);
    ~EDistance();
    int optDistance();
    std::string alignment();

    static int min3(int a, int b, int c);
    static int penalty(char a, char b);

 private:
    static const int PM = 1;
    static const int PG = 2;
    std::string xSequence, ySequence;
    int xLength, yLength;
    int** opt;
};

#endif   // EDISTANCE_HPP
