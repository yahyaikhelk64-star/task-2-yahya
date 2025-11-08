#include <iostream>
#include <fstream>
int main(int c,char**v){
 if(c!=3){std::cerr<<"usage: generator file n\n";return 1;}
 std::ofstream o(v[1]);long long n=std::stoll(v[2]);
 for(long long i=1;i<=n;i++){o<<"Name"<<i<<" Surname"<<i;for(int j=0;j<5;j++)o<<" "<<(i+j)%10+1;o<<" "<<(i+5)%10+1<<"\n";}
}
