#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Enemy.h"
#include "Hero.h"
using namespace std;


// コンストラクタ
CEnemy::CEnemy(const char* pName) {
    // 名前をコピー
    _nameSize = strlen(pName);
    _pName = new char[_nameSize + 1];
    strcpy(_pName, pName);

    // 他のパラメータ初期化
    _hp = 500;
    _maxHp = _hp;
    _attack = 250;
    _diffence = 50;
}

// コピーコンストラクタ
CEnemy::CEnemy(const CEnemy& other) {
    //printf("copy\n");
    _pName = new char[other._nameSize + 1];
    _nameSize = other._nameSize;
    _hp = other._hp;
    _maxHp = other._maxHp;
    _attack = other._attack;
    _diffence = other._diffence;
    _pName[_nameSize] = NULL;

    copy(other._pName, other._pName + _nameSize, _pName);
}

// デストラクタ
CEnemy::~CEnemy() {
    if (_pName != NULL)
    {
        delete[] _pName;
        _pName = NULL;
    }
}

void CEnemy::Damage(CHero cHero) {
    int damage = cHero.GetAttack() / _diffence;
    printf("%sは%dダメージ食らった\n", _pName, damage);
    _hp -= damage;
}

bool CEnemy::Heal() {
    if (_hp < _maxHp / 2) {
        _hp += 100;
        if (_hp > _maxHp) {
            _hp = _maxHp;
        }
        return true;
    }
    return false;
}