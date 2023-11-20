#include <iostream>
#include <ctime>
#include "Character.h"
#include "Hero.h"
#include "Enemy.h"
using namespace std;

const int MAX_NAME = 16;

void Show(CCharacter cCharacter) {
    printf("名前：%s\n", cCharacter.GetName());
    printf("体力：%d\n", cCharacter.GetHp());
    printf("攻撃力：%d, ", cCharacter.GetAttack());
    printf("防御力：%d\n", cCharacter.GetDiffence());
}

int main()
{
    srand((int)time(NULL));
    int turn = 1;
    bool gameEnd = false;
    bool turnEnd = false;
    char name[MAX_NAME] = { " " };
    char* pName = &name[0];
    int hp = 0;
    int attack = 0;
    int diffence = 0;

    printf("・ステータス入力\n");
    printf("ヒーロー名\n> ");
    cin >> name;
    printf("HP\n> ");
    cin >> hp;
    printf("Attack\n>");
    cin >> attack;
    printf("Diffence\n>");
    cin >> diffence;

    CHero cHero(&name[0], hp, attack, diffence);

    printf("エネミー名\n>");
    cin >> name;
    CEnemy cEnemy(&name[0]);

    printf("\nステータス表示\n");
    Show(cHero);
    Show(cEnemy);

    int select = 0;
    do {
        if (turn == 1) {
            // プレイヤーターン
            turnEnd = true;
            printf("攻撃 : 1\, 回復 : 2\n> ");
            cin >> select;

            switch (select)
            {
            case 1:
                printf("%sの攻撃\n", cHero.GetName());
                cEnemy.Damage(cHero);
                turn *= -1;
                break;
            case 2:
                if (cHero.Heal()) {
                    printf("%sは回復した\n", cHero.GetName());
                    turn *= -1;
                }
                break;
            default:
                break;
            }
            if (cEnemy.GetHp() <= 0) { break; }
        }
        else {
            // エネミーターン
            int action = rand() % 2;

            switch (action)
            {
            case 0:
                printf("%sの攻撃\n", cEnemy.GetName());
                cHero.Damage(cEnemy);
                break;
            case 1:
                if (!cEnemy.Heal()) {
                    cHero.Damage(cEnemy);
                }
                else {
                    printf("%sは回復した\n", cEnemy.GetName());
                }
                break;
            default:
                break;
            }
            if (cHero.GetHp() <= 0) { gameEnd = true; }
            else { turn *= -1; }
        }

        printf("\n残りHP\n");
        printf("%s : %d\n", cEnemy.GetName(), cEnemy.GetHp());
        printf("%s : %d\n", cHero.GetName(), cHero.GetHp());
        printf("\n");

    } while (!gameEnd);
}