#ifndef STUDENTPROCESSOR_H
#define STUDENTPROCESSOR_H
#include "Person.h"
#include <string>
#include <chrono>
struct Timings{double read=0,compute=0,split=0;};
class StudentProcessor{
public:
    template<typename C>static Timings process(const std::string& in,const std::string& outP,const std::string& outF,bool med,C& cont);
};
#endif
