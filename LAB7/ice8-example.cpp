#include <iostream>
using namespace std;

class ECLife {
public:
    ECLife() { cout << "ECLife Constructor\n"; }
    virtual void live() const { cout << "Living like a life form\n"; }
    virtual ~ECLife() { cout << "ECLife Destructor\n"; }
};

class ECSpider : public ECLife {
public:
    ECSpider() { cout << "ECSpider Constructor\n"; }
    void spinWeb() const { cout << "Spinning web like a spider\n"; }
    virtual ~ECSpider() { cout << "ECSpider Destructor\n"; }
};

class ECMan : public ECLife {
public:
    ECMan() { cout << "ECMan Constructor\n"; }
    void speak() const { cout << "Speaking like a man\n"; }
    virtual ~ECMan() { cout << "ECMan Destructor\n"; }
};

class ECSpiderMan : public ECSpider, public ECMan {
public:
    ECSpiderMan() { cout << "ECSpiderMan Constructor\n"; }
    void doHeroStuff() const { cout << "Doing heroic stuff\n"; }
    ~ECSpiderMan() { cout << "ECSpiderMan Destructor\n"; }
};

int main() {
    ECSpiderMan peterParker;

    cout << "\nCalling ECSpiderMan methods:\n";
    peterParker.doHeroStuff();  // Unique method for ECSpiderMan
    peterParker.spinWeb();      // Inherited from ECSpider
    peterParker.speak();        // Inherited from ECMan

    cout << "\nCasting to ECSpider:\n";
    ECSpider* spiderPart = &peterParker;
    spiderPart->spinWeb();
    cout << "Address of ECSpider part: " << spiderPart << endl;

    cout << "\nCasting to ECMan:\n";
    ECMan* manPart = &peterParker;
    manPart->speak();
    cout << "Address of ECMan part: " << manPart << endl;

    cout << "\nCasting to ECLife from ECSpider:\n";
    ECLife* lifePartFromSpider = static_cast<ECLife*>(spiderPart);
    lifePartFromSpider->live();
    cout << "Address of ECLife part from ECSpider: " << lifePartFromSpider << endl;

    cout << "\nCasting to ECLife from ECMan:\n";
    ECLife* lifePartFromMan = static_cast<ECLife*>(manPart);
    lifePartFromMan->live();
    cout << "Address of ECLife part from ECMan: " << lifePartFromMan << endl;

    return 0;
}
