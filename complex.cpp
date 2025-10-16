#include<iostream>
#include<initializer_list>
#include<cmath>

class Complex{

private:
  double real=0.0;
  double img=0.0;
public:

Complex(double a,double b):real{a},img{b}{}
Complex():real{0.0},img{0.0}{}
Complex(std::initializer_list<double> list){
  auto it =list.begin();
  std::size_t size=list.size();
    if(size==0){
      real=0.0;
      img=0.0;
    }
    else if(size==1){
      real=*it;
      img=0.0;
    }
    else if(size==2){
      real=*it;
      ++it;
      img=*it;
    }
    else
      std::cerr<<"2D complex no provided with more then 2 Arguments.";
  }




Complex& operator=(const Complex& source){
  if(this==&source){return *this;}

    this->real=source.real;
    this->img=source.img;
    return *this;
  }
//copy assignment

//Move Semantics
  Complex(Complex&& source)
    :real{source.real},img{source.img}
  {
   source.real=0.0;
   source.img=0.0;
  }

//Move assignment
  Complex& operator=(const Complex&& source){
  if(this==&source){return *this;}

    real=source.real;
    img=source.img;
    return *this;
  }

Complex operator+(const Complex& a){
  return Complex(real+a.real,img+a.img);
  }

Complex operator-(const Complex& a){
  return Complex(real-a.real,img-a.img);
  }

Complex operator*(const Complex& a){
    return Complex((real*a.real)-(img*a.img),(real*a.img)-(img*a.real));
  }

//functions

 friend std::ostream& operator<<(std::ostream& out,const Complex& source);
 friend std::istream& operator>>(std::istream& in,Complex& source);

void conju(){img=(-1)*img;}
Complex conjugate(Complex& c){return Complex(c.real,(-1)*c.img);}

void polar(){
    double z=std::sqrt((real*real)+(img*img));
    real=real/z;
    img=img/z;
  }

Complex polar(Complex& c){
    double z=std::sqrt((c.real*c.real)+(c.img*c.img));
    return Complex(c.real/z,c.img/z);
  }

double mod(){
    return std::sqrt((real*real)+(img*img));
  }

double mod(Complex& c){
    return std::sqrt((c.real*c.real)+(c.img*c.img));
  }

void euler(){
    double a=mod(*this);
    std::cout<<a<<"("<<polar(*this)<<")";
  }

};

std::ostream& operator<<(std::ostream& out,const Complex& source){
  if(source.img>=0)
  out<<source.real<<"+"<<source.img<<"i\n";
  else
  out<<source.real<<source.img<<"i";

  return out;
}
std::istream& operator>>(std::istream& in,Complex& source){
  in>>source.real>>source.img;
  return in;
}


int main(){
while(true){
  std::cout<<"\nEnter no to test";
  Complex z;
  std::cin>>z;
  std::cout<<"mod"<<z.mod()<<"\n";
  z.euler();

  }
}
