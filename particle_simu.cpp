#include<cmath>
#include<vector>
#include<array>
#include<random>
#include<thread>
#include<iostream>


/*A particle simulator basics version
 * Uses the Mersenne Twister engine to assign random values to centre
 * no of particles can be changed and range may be provided for values
 *
 *Will use threads to calculate the workload
 *
 * */


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
//vector overload
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



std::vector<Particle> render(const std::vector<Particle>& read){
  std::vector<Particle> write(read.size());
  using std::size_t;
  //asking computer how many cores /threads
  size_t c=std::thread::hardware_concurrency();
  if(c==0){c=2;}//in case function fails,assume 2 cores

  //var to cal how many threads 
  size_t size=read.size();
  size_t no_thread=std::min(c,size);
  size_t quo=size/no_thread;
  size_t rem=size%no_thread;

  //thread array
  std::array<std::thread,no_thread> worker;

  for(int i=0;i<no_thread-1;++i){

  worker[i]([&](i){
  for(size_t a=size-(quo*(i+1);a<=size-(i*quo)-1;++a){

//position part &velo part

for(int j=0;j<2;j++){
  for(auto item:read){
  double r=std::pow(std::hypot(item.p[0]-read[a].p[0],item.p[1]-read[a].p[1]),3);
if(r==0){r=1;}
  //r may be zero will do exception later
  double acc=(item.p[j]-read[a].p[j])/r;
  write[a].p[j]= read[a].p[j]+ read[a].v[j]*(0.01)+0.5*acc*(0.01)*(0.01);
    
//veclocity part
 write[a].v[j]=read[a].p[j]+acc*0.01;

        }//for iterating read array
        }//most inside for to iterate th3 dimensions

      }//the for loop that know which segment by which thread

    })//thread end {lambda inside thread used}

  }//outer for that assignes n-1 threads
  
  
for(int a=0;a<=rem-1;++a){
for(int j=0;j<2;j++){
  for(auto item:read){
  double r=std::pow(std::hypot(item.p[0]-read[a].p[0],item.p[1]-read[a].p[1]),3);
if(r==0){r=1;}
  //r may be zero will do exception later
  double acc=(item.p[j]-read[a].p[j])/r;
  write[a].p[j]= read[a].p[j]+ read[a].v[j]*(0.01)+0.5*acc*(0.01)*(0.01);
    
//veclocity part
 write[a].v[j]=read[a].p[j]+acc*0.01;

        }//for iterating read array
        }//most inside for to iterate th3 dimensions

    }

return write;
}//render function ends


















int main(){
  auto particles =sample(3);
  std::cout<<particles;
}
