#include <cstdio>
using std::puts;

struct Weapon {
    virtual void attack() = 0;
    virtual ~Weapon() {}
};

struct Sword : Weapon {
    virtual void attack() override { puts("Slash!"); }
};

struct Bow : Weapon {
    virtual void attack() override { puts("Pew!"); }
};

struct Hero {
    virtual Weapon* getWeapon() = 0;
    virtual int getSpeed() = 0;
    virtual ~Hero() {}
};

struct Knight : Hero {
    virtual Weapon* getWeapon() override { return new Sword(); }
    virtual int getSpeed() override { return 10; }
};

struct Rogue : Hero {
    virtual Weapon* getWeapon() override { return new Bow(); }
    virtual int getSpeed() override { return 15; }
};

int main() {
    Hero* elf = new Knight();
    if (true /*there is a monster*/) {
        Weapon* wpn = elf->getWeapon();
        wpn->attack();
        delete wpn;
    }
    delete elf;
    return 0;
}
