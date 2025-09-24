#include<iostream>
#include<chrono>
#include<functional>


class Timer {
    using clock     = std::chrono::high_resolution_clock;
    using timepoint = std::chrono::time_point<clock>;
    using duration  = std::chrono::duration<double, std::micro>;
    // our chosen unit: microseconds as double

    timepoint start;
    duration elapsed_time{0};

public:
    Timer() : start(clock::now()) {}

    void reset() {
        start = clock::now();
        elapsed_time = duration{0};
    }

    void stop() {
        // (now - start) is a duration in clock::duration.
        // Constructing directly into our "duration" member does the conversion.
        elapsed_time = duration(clock::now() - start);
    }

    double elapsed() const {
        return elapsed_time.count(); // already in microseconds
    }
};




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
for(int i=0;i<n;++i){}
}

int main(){
  std::chrono::duration<double,std::micro> dur;
dur=complexity(test,10,100);
  std::chrono::duration<double,std::micro> overhead(0.075);
  std::cout<<"10 iteration took:"
           <<dur.count()-overhead.count()<<"ms\n";



    Timer t;
test(10);
    t.stop();
  std::cout << "Elapsed: " << t.elapsed() << " µs\n";

}
