#pragma once


class CCharacter {
public:
    void operator = (const CCharacter& other);

public:
    char* GetName() { return _pName; }
    int GetAttack() const { return _attack; }
    int GetDiffence() const { return _diffence; }
    int GetHp() const { return _hp; }
    void SetHp(int hp) { _hp = hp; }

public:
    bool Heal();

protected:
    char* _pName;
    int _nameSize;

protected:
    int _maxHp;
    int _hp;
    int _attack;
    int _diffence;
};