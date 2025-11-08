#include "StudentProcessor.h"
#include <list>
#include <iostream>
int main(int c,char**v){
 try{
  if(c<5){std::cerr<<"usage: main_list in outP outF avg|med\n";return 1;}
  std::list<Person> a;auto t=StudentProcessor::process(v[1],v[2],v[3],std::string(v[4])=="med",a);
  std::cout<<"read="<<t.read<<" compute="<<t.compute<<" split="<<t.split<<"\n";
 }catch(std::exception&e){std::cerr<<e.what()<<"\n";return 2;}
}
