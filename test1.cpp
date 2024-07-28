#include <iostream>
#include <ostream>
using namespace std;

class shape{
  public:
    int width;
    int height;
    int radius;
    double areaNum;
    void area(){
      printf("none");
    }
};
class rectangle : public shape{
  public: 
    rectangle(int x, int y){
      width = x;
      height = y;
      area();
    }
    void area(){
      areaNum = width * height ;
      cout << areaNum << endl;
    }
};
class circle : public shape{
  public:
    const double pi {3.14};
    circle(int x){
      radius = x;
      area();
    }
    void area(){
      areaNum = radius * radius * pi;
      cout << areaNum << endl;
    }
};
int main() {
  rectangle(3,5);
  circle(4);

}
