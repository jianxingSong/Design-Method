//
// Created by 宋健星 on 2024/7/29.
//
#include "iostream"

using namespace std;

class Singleton{
public:
    static Singleton* getInstance(int a){
        static Singleton* p = new Singleton(a);
        return p;
    }

    void print(){
        cout << i << endl;
    }

    ~Singleton(){}


private:
    Singleton(int a): i(a){}
    int i;
};

int main(){
    Singleton* p1 = Singleton::getInstance(10);
//    p1->print();
    Singleton* p2 = Singleton::getInstance(100);
//    p2->print();
    cout << p1 << " " << p2 << endl;
    delete p1;


    return  0;
}
