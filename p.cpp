#include<cmath>
#include<vector>
#include<array>
#include<random>

struct Particle{

//particle position and velocity
  std::array<double,2> p{0,0}
  std::array<double,2> v{0,0}

Particle(double a,double b,double c,double d)
  {
  p[0]=a;
  p[1]=b;
  v[0]=c;
  v[1]=d;
  }
~Particle(){}

};

//random interal points in range of -500 to 500
//use this to generate a vector full of sample points



std::vector<Particle> sample(unsigned int size){

  std::vector<Particle> obj;
  obj.reserve(size);

//random no to use as seed
  std::random_device n;

//Mersenne twister engine given with random seed
  std::mt19937 gen(n());

  int min_range=-500;
  int max_range=500;

  std::uniform_int_distribution<int> dist(min_range,max_range);

for(int i=0;i<size;i++){
obj[i]=Particle(dist(gen),dist(gen),dist(gen),dist(gen));
  }//for ends
}



int main(){

}
