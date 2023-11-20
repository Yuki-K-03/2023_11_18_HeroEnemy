#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Hero.h"
#include "Enemy.h"
using namespace std;

// �R���X�g���N�^
CHero::CHero(const char* pName, int hp, int attack, int diffence) {
    // ���O���R�s�[
    _nameSize = strlen(pName);
    _pName = new char[_nameSize + 1];
    strcpy(_pName, pName);

    // ���̃p�����[�^������
    _hp = hp;
    _maxHp = _hp;
    _attack = attack;
    _diffence = diffence;
}

// �R�s�[�R���X�g���N�^
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

// �f�X�g���N�^
CHero::~CHero() {
    if (_pName != NULL)
    {
        delete[] _pName;
        _pName = NULL;
    }
}

void CHero::Damage(CEnemy cEnemy) {
    int damage = cEnemy.GetAttack() / _diffence;
    printf("%s��%d�_���[�W�H�����\n", _pName, damage);
    _hp -= damage;
}