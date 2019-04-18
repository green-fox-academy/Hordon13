#ifndef ANIMAL_ANIMAL_H
#define ANIMAL_ANIMAL_H


class Animal {
public:
    Animal();

    int getHunger() const;

    void setHunger(int hunger);

    int getThirst() const;

    void setThirst(int thirst);

    void eat();

    void drink();

    void play();

private:
    int hunger;
    int thirst;
};


#endif
