//
// Created by Horváth Donát on 2019-04-24.
//

#include "Aircrafts.h"

int Aircrafts::fight()
{
    int damage = _baseDamage * _ammo;
    _ammo = 0;
    return damage;
}

int Aircrafts::refill(int fillAmount)
{
    while (_ammo < _maxAmmo && fillAmount != 0) {
        _ammo++;
        fillAmount--;
    }
    return fillAmount;
}

Aircrafts::Aircrafts(std::string type, int baseDamage, int maxAmmo, int ammo)
{
    _type = type;
    _baseDamage = baseDamage;
    _maxAmmo = maxAmmo;
    _ammo = ammo;
}

std::string Aircrafts::getType()
{
    return _type;
}

std::string Aircrafts::getStatus()
{
    return "Type " + _type + ", Ammo: " + std::to_string(_ammo) + ", Base Demage: " + std::to_string(_baseDamage) +
           ", All Damage:" + std::to_string(_ammo * _baseDamage);
}

bool Aircrafts::isPriority()
{
    if (_type == "F16") {
        return false;
    } else if (_type == "F35") {
        return true;
    }
}