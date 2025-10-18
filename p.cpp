#include<cmath>
#include<vector>
#include<array>
#include<random>

//a struct represting the individual points
struct Particle{

//particle position and velocity
  std::array<double,2> p{0,0};
  std::array<double,2> v{0,0};

Particle(double a,double b,double c,double d)
  {
  p[0]=a;
  p[1]=b;
  v[0]=c;
  v[1]=d;
  }
~Particle(){}


};//struct ends


//overload <<for struct particle
std::ostream& operator<<(std::ostream& out,const Particle& source){
  out<<"Position: ("<<source.p[0]<<", "<<source.p[1]<<")\n";
  out<<"Velocity: ("<<source.v[0]<<", "<<source.v[1]<<")";
  return out;
}

std::ostream& operator<<(std::ostream& out,const std::vector<Particle>& source){

for(std::size_t i=0;i<source.size();++i){
  out<<"Particle "<<i<<":\n";
  out<<source[i]<<"\n\n";
  }
  return out;
}






//random interal points in range of -500 to 500
//use this to generate a vector full of sample points



std::vector<Particle> sample(unsigned int size){

  std::vector<Particle> obj;
  obj.reserve(size);

//random no to use as seed
  std::random_device n;

//Mersenne twister engine given with random seed
  std::mt19937 gen(n());

  std::uniform_int_distribution<int> dist(-500,500);

for(int i=0;i<size;i++){
obj.emplace_back(dist(gen),dist(gen),dist(gen),dist(gen));
  }//for ends

  return obj;
}



int main(){
  auto particles =sample(3);
  std::cout<<particles;
}
