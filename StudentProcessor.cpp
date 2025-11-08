#include "StudentProcessor.h"
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <deque>
#include <list>
#include <iomanip>
template<typename C>static void writeC(const C& c,const std::string& f,bool med){
    std::ofstream o(f);if(!o)throw std::runtime_error("file "+f);
    for(auto&p:c){double v=med?p.computeMedian()*0.4+0.6*p.exam:p.computeAverage()*0.4+0.6*p.exam;
        o<<p.name<<" "<<p.surname<<" "<<std::fixed<<std::setprecision(2)<<v<<"\n";}
}
template<typename C>Timings StudentProcessor::process(const std::string& in,const std::string& outP,const std::string& outF,bool med,C& c){
    Timings t;auto s=std::chrono::high_resolution_clock::now();
    std::ifstream i(in);if(!i)throw std::runtime_error("file "+in);
    c.clear();Person p;while(i>>p){p.calculateFinal(med);c.push_back(p);}
    auto e=std::chrono::high_resolution_clock::now();t.read=std::chrono::duration<double>(e-s).count();
    s=std::chrono::high_resolution_clock::now();
    if constexpr(std::is_same_v<C,std::vector<Person>>||std::is_same_v<C,std::deque<Person>>)
        std::sort(c.begin(),c.end(),[](auto&a,auto&b){return a.name<b.name||(a.name==b.name&&a.surname<b.surname);});
    else c.sort([](auto&a,auto&b){return a.name<b.name||(a.name==b.name&&a.surname<b.surname);});
    e=std::chrono::high_resolution_clock::now();t.compute=std::chrono::duration<double>(e-s).count();
    s=std::chrono::high_resolution_clock::now();C p1,p2;for(auto&s1:c){double v=med?s1.computeMedian()*0.4+0.6*s1.exam:s1.computeAverage()*0.4+0.6*s1.exam;if(v>=5)p1.push_back(s1);else p2.push_back(s1);}
    writeC(p1,outP,med);writeC(p2,outF,med);
    e=std::chrono::high_resolution_clock::now();t.split=std::chrono::duration<double>(e-s).count();
    return t;
}
template Timings StudentProcessor::process(std::vector<Person>&&)=delete;
template Timings StudentProcessor::process(const std::string&,const std::string&,const std::string&,bool,std::vector<Person>&);
template Timings StudentProcessor::process(const std::string&,const std::string&,const std::string&,bool,std::list<Person>&);
template Timings StudentProcessor::process(const std::string&,const std::string&,const std::string&,bool,std::deque<Person>&);
