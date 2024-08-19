//
// Created by 宋健星 on 2024/8/19.
//

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

//! 被通知的一方
//! 抽象观察者
class Observer {
public:
    virtual void update(const string& newspaper) = 0;
};

//! 具体观察者——报纸的具体订阅者
class Subscriber: public Observer{
public:
    Subscriber(const string& s): m_name(s){}

    void update(const string& newspaper) override {
        cout << m_name << " received the newspaper: " << newspaper << endl;
    }

private:
    string m_name;
};

//! 抽象被观察者
class Subject{
public:
    virtual void attach(Observer* observer) = 0; //添加观察者
    virtual void detach(Observer* observer) = 0; //去除观察者
    virtual void notify() = 0; //通知被观察
};

//! 具体的被观察者——各种报纸
class Newspaper: public Subject{
public:
    void attach(Observer* observer) override{
        m_observers.push_back(observer);
    }

    void detach(Observer* observer) override {
        m_observers.erase(remove(m_observers.begin(), m_observers.end(), observer), m_observers.end());
    }

    void notify() override {
        for (Observer* p : m_observers){
            p->update(m_name);
        }
    }

    void setName(const string& name){
        m_name = name;
        notify();
    }

private:
    vector<Observer*> m_observers; //观察者模式的精髓——观察者队列
    string m_name;
};

int main(){
    Newspaper newspaper;

    Subscriber subscriber1("Alice");
    Subscriber subscriber2("Bob");

    newspaper.attach(&subscriber1);
    newspaper.attach(&subscriber2);

    newspaper.setName("Daily Times");
    newspaper.setName("Morning News");

    newspaper.detach(&subscriber1);
    newspaper.setName("Evening Herald");


    return 0;
}


