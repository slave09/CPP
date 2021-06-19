#include<iostream>
using namespace std;

class Exception{
  public:
  Exception(){
    try{
      throw(400);
    }
    catch(int error_code){
      cout << error_code;
    }
  }
};

int main(){
  Exception exception = Exception();
  return 0;
}