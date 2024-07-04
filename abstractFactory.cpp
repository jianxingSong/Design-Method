//抽象工厂模式
/*
 * 相对普通工厂模式，抽象工厂模式生产出来的东西更加复杂，需要由多个抽象类共同组成
 */
#include <iostream>

using namespace std;

//船体
class ShipBody{
public:
    virtual string getBody() = 0;
    virtual ~ShipBody(){};
};

//木头船体
class WoodBody: public ShipBody{
public:
    string getBody(){
        return string("使用【木头】制作船体 ");
    }
};

//钢铁船体
class IronBody: public ShipBody{
public:
    string getBody(){
        return string("使用【钢铁】制作船体 ");
    }
};


class MetalBody: public ShipBody{
public:
    string getBody(){
        return string("使用【合成金属】制作船体 ");
    }
};

//引擎
class Engine{
public:
    virtual string getEngine() = 0;
    virtual ~Engine(){}
};

class ManualEngine: public Engine{
public:
    string getEngine(){
        return "使用引擎【手动】";
    }
};

class FireEngine: public Engine{
public:
    string getEngine(){
        return "使用引擎【内燃机】";
    }
};

class NuclearEngine: public Engine{
public:
    string getEngine(){
        return "使用引擎【核能】";
    }
};

//武器
class Weapon{
public:
    virtual string getWeapon() = 0;
    virtual ~Weapon(){}
};

class GunWeapon:public Weapon{
public:
    string getWeapon(){
        return "使用武器【枪】";
    }
};

class CannonWeapon:public Weapon{
public:
    string getWeapon(){
        return "使用武器【加农炮】";
    }
};

class LaserWeapon:public Weapon{
public:
    string getWeapon(){
        return "使用武器【激光】";
    }
};

//船
class Ship{
public:
    Ship(ShipBody* body, Engine* engine, Weapon* weapon):m_body(body), m_engine(engine), m_weapon(weapon){}
    virtual ~Ship(){
        delete m_body;
        delete m_engine;
        delete m_weapon;
    }
    string getProperty(){
        string info = m_body->getBody() + m_engine->getEngine() + m_weapon->getWeapon();
        return info;
    }
private:
    ShipBody* m_body;
    Engine* m_engine;
    Weapon* m_weapon;
};

//抽象的工厂类
class AbstractFactory{
public:
    virtual Ship* createShip() = 0;
    virtual ~AbstractFactory(){}
};

class BasicFactory: public AbstractFactory{
public:
    Ship* createShip(){
        Ship* ship = new Ship(new WoodBody, new ManualEngine, new GunWeapon);
        cout << "基础型船已经建造完成" << endl;
        return ship;
    }
};

class StandardFactory: public AbstractFactory{
public:
    Ship* createShip(){
        Ship* ship = new Ship(new IronBody, new FireEngine, new CannonWeapon);
        cout << "标准型船已经建造完成" << endl;
        return ship;
    }
};

class UltimateFactory: public AbstractFactory{
public:
    Ship* createShip(){
        Ship* ship = new Ship(new MetalBody, new NuclearEngine, new LaserWeapon);
        cout << "高级型船已经建造完成" << endl;
        return ship;
    }
};

int main() {
    AbstractFactory* factory = new UltimateFactory;
    Ship* ship = factory->createShip();
    cout << ship->getProperty() << endl;
    delete factory;
    delete ship;

    return 0;
}
