//
// Created by 宋健星 on 2024/7/2.
//
/* 目的是解决增加简单工厂增加产品就要修改工厂类的问题
 *
 *
 */
#include <iostream>

using namespace std;

//产品父类
class AbstractSmile{
public:
    virtual void transform() = 0;
    virtual void ability() = 0;
    virtual ~AbstractSmile(){}
};

class SheepSmile: public AbstractSmile{
public:
    void transform() override{
        cout << "SheepSmile transform" << endl;
    }

    void ability() override{
        cout << "SheepSmile ability" << endl;
    }
};

class LionSmile: public AbstractSmile{
public:
    void transform() override{
        cout << "LionSmile transform" << endl;
    }

    void ability() override{
        cout << "LionSmile ability" << endl;
    }
};

class BatSmile: public AbstractSmile{
public:
    void transform() override{
        cout << "BatSmile transform" << endl;
    }

    void ability() override{
        cout << "BatSmile ability" << endl;
    }
};

//定义工厂函数制造恶魔果实
class AbstractFactory{
public:
    virtual AbstractSmile* createSmile() = 0;
    virtual ~AbstractFactory(){}
};

class SheepFactory: public AbstractFactory{
public:
    AbstractSmile* createSmile() override{
        return new SheepSmile;
    }
    ~SheepFactory(){}
};

class LionFactory: public AbstractFactory{
public:
    AbstractSmile* createSmile() override{
        return new LionSmile;
    }
    ~LionFactory(){}
};

class BatFactory: public AbstractFactory{
public:
    AbstractSmile* createSmile() override{
        return new BatSmile;
    }
    ~BatFactory(){}
};



int main() {
    AbstractFactory* factory = new LionFactory;
    AbstractSmile* obj = factory->createSmile();
    obj->ability();
    obj->transform();
    delete factory;
    delete obj;

    return 0;
}
