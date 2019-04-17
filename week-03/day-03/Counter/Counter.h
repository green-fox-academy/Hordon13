//
// Created by Horváth Donát on 2019-04-17.
//

#ifndef COUNTER_COUNTER_H
#define COUNTER_COUNTER_H


class Counter {
public:
    Counter();
    Counter(int fieldValue);

    int get();
    int add();
    int add(int);
    void reset();

    void setFieldValue(int fieldValue);

private:
    int fieldValue;
    int initValue;
};


#endif //COUNTER_COUNTER_H
