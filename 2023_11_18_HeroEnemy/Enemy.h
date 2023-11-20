#pragma once
#include "Character.h"


class CHero;

class CEnemy :
	public CCharacter {
public:
	CEnemy(const CEnemy& other);
	CEnemy(const char* pName);
	~CEnemy();

	void Damage(CHero cHero);
	bool Heal();
};