#include <iostream>
#include <cstring>
#include <string>
#include <clocale>

using namespace std;

/** Абстрактный музыкант - не является обязательной составляющей паттерна, введен для упрощения кода */
class Musician {

    const char* name;

public:
    Musician(const char* name) {
        this->name = name;
    }

    virtual ~Musician() {}

protected:
    void output(const char* text) {
        std::cout << this->name << " " << text << "." << std::endl;
    }
};

/** Конкретные музыканты */
class Vocalist: public Musician {

public:
    Vocalist(const char* name): Musician(name) {}

    void singCouplet(const int coupletNumber) {
        char* text = strdup("спел куплет №");
        strncat(text, std::to_string(coupletNumber).c_str(), 15);
        output(text);
    }

    void singChorus() {
        output("спел припев");
    }
};

class Guitarist: public Musician {

public:
    Guitarist(const char* name): Musician(name) {}

    void playCoolOpening() {
        output("начинает с крутого вступления");
    }

    void playCoolRiffs() {
        output("играет крутые риффы");
    }

    void playAnotherCoolRiffs() {
        output("играет другие крутые риффы");
    }

    void playIncrediblyCoolSolo() {
        output("выдает невероятно крутое соло");
    }

    void playFinalAccord() {
        output("заканчивает песню мощным аккордом");
    }
};

class Bassist: public Musician {

public:
    Bassist(const char* name): Musician(name) {}

    void followTheDrums() {
        output("следует за барабанами");
    }

    void changeRhythm(const char* type) {
        char* text = strdup("перешел на ритм ");
        strncat(text, type, 15);
        strncat(text, "a", 15);
        output(text);
    }

    void stopPlaying() {
        output("заканчивает играть");
    }
};

class Drummer: public Musician {

public:
    Drummer(const char* name): Musician(name) {}

    void startPlaying() {
        output("начинает играть");
    }

    void stopPlaying() {
        cout << "заканчивает играть";
        //output("заканчивает играть");
    }
};

/** Фасад, в данном случае - знаменитая рок-группа */
class BlackSabbath {

    Vocalist* vocalist;
    Guitarist* guitarist;
    Bassist* bassist;
    Drummer* drummer;

public:

    BlackSabbath() {
        vocalist = new Vocalist("Оззи Осборн");
        guitarist = new Guitarist("Тони Айомми");
        bassist = new Bassist("Гизер Батлер");
        drummer = new Drummer("Билл Уорд");
    }

    void playCoolSong() {
        guitarist->playCoolOpening();
        drummer->startPlaying();
        bassist->followTheDrums();
        guitarist->playCoolRiffs();
        vocalist->singCouplet(1);
        bassist->changeRhythm("припев");
        guitarist->playAnotherCoolRiffs();
        vocalist->singChorus();
        bassist->changeRhythm("куплет");
        guitarist->playCoolRiffs();
        vocalist->singCouplet(2);
        bassist->changeRhythm("припев");
        guitarist->playAnotherCoolRiffs();
        vocalist->singChorus();
        bassist->changeRhythm("куплет");
        guitarist->playIncrediblyCoolSolo();
        guitarist->playCoolRiffs();
        vocalist->singCouplet(3);
        bassist->changeRhythm("припев");
        guitarist->playAnotherCoolRiffs();
        vocalist->singChorus();
        bassist->changeRhythm("куплет");
        guitarist->playCoolRiffs();
        bassist->stopPlaying();
        drummer->stopPlaying();
        guitarist->playFinalAccord();
    }
};

int main() {
//    std::string stroka;
//    std::setlocale(LC_ALL,"Russian_Russia.1251") ;
//    std::cout << L"Введите строку==>> ";
//    std::getline (std::cin,stroka,'\n');
//    std::cout << "\n Вот ваша строка=====";
//    std::setlocale(LC_ALL,"rus_rus.866");
//    std::cout << stroka <<'\n';
//    std::system ("pause");

    std::cout << "Привет" << endl;
    std::cout << "OUTPUT:" << std::endl;
    BlackSabbath* band = new BlackSabbath();
    band->playCoolSong();
    return 0;
}

/**
 * OUTPUT:
 * Тони Айомми начинает с крутого вступления.
 * Билл Уорд начинает играть.
 * Гизер Батлер следует за барабанами.
 * Тони Айомми играет крутые риффы.
 * Оззи Осборн спел куплет №1.
 * Гизер Батлер перешел на ритм припевa.
 * Тони Айомми играет другие крутые риффы.
 * Оззи Осборн спел припев.
 * Гизер Батлер перешел на ритм куплетa.
 * Тони Айомми играет крутые риффы.
 * Оззи Осборн спел куплет №2.
 * Гизер Батлер перешел на ритм припевa.
 * Тони Айомми играет другие крутые риффы.
 * Оззи Осборн спел припев.
 * Гизер Батлер перешел на ритм куплетa.
 * Тони Айомми выдает невероятно крутое соло.
 * Тони Айомми играет крутые риффы.
 * Оззи Осборн спел куплет №3.
 * Гизер Батлер перешел на ритм припевa.
 * Тони Айомми играет другие крутые риффы.
 * Оззи Осборн спел припев.
 * Гизер Батлер перешел на ритм куплетa.
 * Тони Айомми играет крутые риффы.
 * Гизер Батлер заканчивает играть.
 * Билл Уорд заканчивает играть.
 * Тони Айомми заканчивает песню мощным аккордом.
 */
