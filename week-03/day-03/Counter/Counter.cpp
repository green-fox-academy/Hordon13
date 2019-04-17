//
// Created by Horváth Donát on 2019-04-17.
//

#include "Counter.h"

Counter::Counter(){
    fieldValue = 0;
    initValue = 0;
}

Counter::Counter(int fieldValue){
    this->fieldValue = fieldValue;
    initValue = fieldValue;
}

int Counter::get()
{
    return fieldValue;
}

void Counter::setFieldValue(int fieldValue)
{
    Counter::fieldValue = fieldValue;
}

int Counter::add()
{
    setFieldValue(++fieldValue);
    return fieldValue;
}

int Counter::add(int num)
{
    fieldValue += num;
    return 0;
}

void Counter::reset()
{
    setFieldValue(initValue);
}
