#include<iostream>
#include<initializer_list>
#include<memory>
#include<algorithm>

template<typename T>
class ArrayList{

private:
  std::size_t m_length;
  std::size_t m_capacity=0;
  std::unique_ptr<T[]> data=std::make_unique<T[]>(m_capacity);

public:

  ArrayList()
   :m_length{0},m_capacity{0},data{nullptr}
  {
  }//default null constructor


  ArrayList(std::size_t capacity)
   :m_length{0},m_capacity{capacity}
  {
   data=std::make_unique<T[]>(m_capacity);
  }//makes an empty list of specific capacity


  ArrayList(std::initializer_list<T> source)
  {
    m_capacity=source.size();
    m_length=source.size();
    data=std::make_unique<T[]>(m_capacity);

    int i=0;
  for(auto item :source){
    data[i]=item;
      ++i;
    }//for ends
  }


 ~ArrayList(){}//empty destructor


  ArrayList<T>& operator=(const ArrayList<T>& source)
  {
    if(this!=&source){
      m_length=source.m_length;
      m_capacity=source.m_capacity;
      data=std::make_unique<T[]>(m_capacity);

      std::copy(source.data.get(),source.data.get()+m_capacity,data.get());
    }
    return *this;
  }


  ArrayList(const ArrayList<T>& source)
   :m_length(source.m_length),
    m_capacity(source.m_capacity),
    data(std::make_unique<T[]>(source.m_capacity))
  {
    std::copy(source.data.get(),source.data.get()+m_capacity,data.get());
  }//copy constructor


//move constructor
  ArrayList(ArrayList<T>&&) noexcept=default;


//move assignment
  ArrayList<T>& operator=(ArrayList<T>&&) noexcept=default;


T& operator[](std::size_t i)const{
    return data[i];
  }

T& operator[](std::size_t i){
    ++m_length;
    return data[i];
  }



friend std::ostream& operator<<(std::ostream& out,const ArrayList<T>& source)
  {
    out<<"[";
    for(int i=0;i<source.m_length;++i){
      out<<source.data[i]<<" ";
    }
    out<<"]";
    return out;
  }

friend std::istream& operator>>(std::istream& in,ArrayList<T>& source)
  {
    for(int i=0;i<source.m_capacity;++i){
      in>>source.data[i];
      source.m_length++;
    }
    return in;
  }

//member functions


  std::size_t length(){return m_length;}
  std::size_t capacity(){return m_capacity;}
  T getItem(std::size_t index){return data[index];}
  T at(std::size_t index){
    if(index<=m_length){
      return data[index];
    }
    std::cerr<<"Index invalid\n";
  }

  void resize(std::size_t size){
    if(size>m_capacity){
      auto temp=std::move(data);
      data =std::make_unique<T[]>(size);
     std::move(temp.get(),temp.get()+m_capacity,data.get());
      m_capacity=size;
    }
   if(size<m_capacity){
   auto temp=std::move(data);
   m_capacity=size;
   m_length=size;
   data =std::make_unique<T[]>(size);
  std::move(temp.get(),temp.get()+size,data.get());
    }
  }

  void push(T input){
    if(m_capacity==m_length){
      resize(2*m_capacity);
     data[m_length]=input;
      m_length++;
    }
    else {
    data[m_length]=input;
    m_length++;
    }
  }

  void pop(){
    m_length=m_length-1;
  }

  void reserve(std::size_t size){
    m_length=0;
    m_capacity=size;
    resize(size);
  }

};//class ends

int main(){
ArrayList a{1,2,3,4,5};

  std::cout<<"Array is:"<<a
           <<"\nLength:"<<a.length()
           <<"\nCapacity:"<<a.capacity()
           <<std::endl;
a.reserve(10);
  std::cout<<"Array is:"<<a
           <<"\nLength:"<<a.length()
           <<"\nCapacity:"<<a.capacity()
           <<std::endl;

}
