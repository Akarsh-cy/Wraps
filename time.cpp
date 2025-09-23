#include<iostream>
#include<chrono>
#include<functional>

template<typename Func,typename T>
std::chrono::duration<double,std::micro> complexity(Func fn,T arg,int n=100){
  std::chrono::duration<double,std::micro> total;
  for(int i=0;i<n;++i){
    std::chrono::time_point start=std::chrono::high_resolution_clock::now();
    fn(arg);
    std::chrono::time_point end=std::chrono::high_resolution_clock::now();

    total+=end-start;
  }

 return total/n;
}

void test(int n){

}

int main(){
  std::chrono::duration<double,std::micro> dur;
dur=complexity(test,10,100);
  std::chrono::duration<double,std::micro> overhead(0.075);
  std::cout<<"10 iteration took:"
           <<dur.count()-overhead.count()<<"ms\n";
}
