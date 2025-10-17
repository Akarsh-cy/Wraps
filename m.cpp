#include<iostream>
#include<cmath>
#include<vector>
#include<array>
using std::array;


void orbit(){
//init vars
array<float,2> p1{3,2};
array<float,2> v1{1,1};
array<float,2> p2{-5,3};
array<float,2> v2{2,-6};

//new vars
array<float,2> np1{};
array<float,2> nv1{};
array<float,2> np2{};
array<float,2> nv2{};

std::vector<std::array<float,2>> p;
p.reserve(100);
std::vector<std::array<float,2>> v;
v.reserve(100);
std::vector<std::array<float,2>> po2;
p.reserve(100);
std::vector<std::array<float,2>> vo2;
v.reserve(100);




for(int i=0;i<99;++i){
  double t=0.1;
  double r=std::hypot(p1[0]-p2[0],p1[1]-p2[1]);
  double k=std::pow(r,3);

np1[0]=p1[0]+v1[0]*t+0.5*t*t*(p2[0]-p1[0])/k;
np1[1]=p1[1]+v1[1]*t+0.5*t*t*(p2[1]-p1[1])/k;


np2[0]=p2[0]+v2[0]*t+0.5*t*t*(p1[0]-p2[0])/k;
np2[1]=p2[1]+v2[1]*t+0.5*t*t*(p1[1]-p2[1])/k;



nv1[0]=v1[0]+((p2[0]-p1[0])/k)*t;
nv1[1]=v1[1]+((p2[1]-p1[1])/k)*t;

nv2[0]=v2[0]+((p1[0]-p2[0])/k)*t;
nv2[1]=v2[1]+((p1[1]-p2[1])/k)*t;



p.push_back(np1);
v.push_back(nv1);
po2.push_back(np2);
vo2.push_back(nv2);



p1=np1;
v1=nv1;
p2=np2;
v2=nv2;
  }//for loop ends

std::cout<<"positions of 1:\n";
for(auto item:p){
    std::cout<<item[0]<<" , "
             <<item[1]<<"\n";}

std::cout<<"velocity of 1:\n";
for(auto item:v){
    std::cout<<item[0]<<" , "
             <<item[1]<<"\n";}

std::cout<<"positions of 2:\n";
for(auto item:po2){
    std::cout<<item[0]<<" , "
             <<item[1]<<"\n";}

std::cout<<"velocity of 2:\n";
for(auto item:vo2){
    std::cout<<item[0]<<" , "
             <<item[1]<<"\n";}





}

int main(){
 orbit();
}
