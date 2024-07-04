/* 简单工厂模式---通过工厂生产很多种不同对象
 * 对应工厂类
 * 分离出创造对象的过程
 */
#include "iostream"

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

//定义抽象工厂
enum class Type:char{Sheep, Lion, Bat};
class SmileFactory{
public:
    AbstractSmile* createSmile(Type type){
        AbstractSmile* ptr = nullptr;
        switch (type) {
            case Type::Sheep:
                ptr = new SheepSmile;
                break;
            case Type::Lion:
                ptr = new LionSmile;
                break;
            case Type::Bat:
                ptr = new BatSmile;
                break;
            default:
                break;
        }

        return ptr;
    }
};



int main() {
    SmileFactory* factory = new SmileFactory;
    AbstractSmile* obj = factory->createSmile(Type::Lion);
    obj->ability();
    obj->transform();
    delete factory;
    delete obj;

    return 0;
}