#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Hero.h"
#include "Enemy.h"
using namespace std;

// コンストラクタ
CHero::CHero(const char* pName, int hp, int attack, int diffence) {
    // 名前をコピー
    _nameSize = strlen(pName);
    _pName = new char[_nameSize + 1];
    strcpy(_pName, pName);

    // 他のパラメータ初期化
    _hp = hp;
    _maxHp = _hp;
    _attack = attack;
    _diffence = diffence;
}

// コピーコンストラクタ
CHero::CHero(const CHero& other) {
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
CHero::~CHero() {
    if (_pName != NULL)
    {
        delete[] _pName;
        _pName = NULL;
    }
}

void CHero::Damage(CEnemy cEnemy) {
    int damage = cEnemy.GetAttack() / _diffence;
    printf("%sは%dダメージ食らった\n", _pName, damage);
    _hp -= damage;
}