#pragma once
#include "Character.h"


class CEnemy;

class CHero :
	public CCharacter {
public:
public:
	CHero(const CHero& other);
	CHero(const char* pName, int hp, int attack, int diffence);
	~CHero();

	void Damage(CEnemy cEnemy);
};