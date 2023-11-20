#define _CRT_SECURE_NO_WARNINGS
//#define DEBUG
#include<iostream>
#include "Character.h"
using namespace std;


void CCharacter::operator = (const CCharacter& other) {
#ifdef DEBUG
    printf("operator\n");
#endif // DEBUG

    char* __pName = new char[other._nameSize + 1];

    delete[] _pName;
    _pName = __pName;
    _nameSize = other._nameSize;
    _hp = other._hp;
    _maxHp = other._maxHp;
    _attack = other._attack;
    _diffence = other._diffence;
    _pName[_nameSize] = NULL;

    copy(other._pName, other._pName + _nameSize, _pName);
}


bool CCharacter::Heal() {
    if (_hp < _maxHp) {
        _hp += 100;
        if (_hp > _maxHp) {
            _hp = _maxHp;
        }
        return true;
    }
    return false;
}