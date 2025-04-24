#include <stdio.h>
#include <string.h>
#include <stdlib.h> // rand, srand
#include <time.h>   // time
#include"pokemon_game.h"
// 新しいポケモンを作成する関数
PokemonPtr New_Pokemon(const char* name, int hp, int ap) {
	PokemonPtr new_pokemon = (PokemonPtr)malloc(sizeof(Pokemon));
	if (new_pokemon == NULL) {
		printf("メモリの確保に失敗\n");
		exit(EXIT_FAILURE);
	}
	strcpy(new_pokemon->name,name);
	new_pokemon->hp = hp;
	new_pokemon->ap = ap;
	return new_pokemon;
}
// ポケモンの情報を表示する関数
void Display_pokemon(PokemonPtr pokemon) {
	printf("名前:%s\n",pokemon->name);
	printf("HP:%d\n",pokemon->hp);
	printf("AP:%d\n",pokemon->ap);
}
// バトルを行う関数
void Battle_Pokemon(PokemonPtr pokemon1, PokemonPtr pokemon2) {
	printf("---バトル開始---\n");
	printf("%s vs %s\n", pokemon1->name, pokemon2->name);
	// 簡単な先攻・後攻の決定 (乱数)
	srand((time)NULL);
	PokemonPtr attacker = (rand() % 2 == 0) ? pokemon1 : pokemon2;
	PokemonPtr defender = (attacker==pokemon1) ? pokemon2 : pokemon1;
	while (pokemon1->hp > 0 && pokemon2->hp > 0) {
		printf("\n%sの攻撃!\n", attacker->name);
		defender->hp -= attacker->ap;
		printf("%s に %dのダメージ!\n", defender->name, attacker->ap);
		printf("%s の hp: %d\n", pokemon1->name, pokemon1->hp);
		printf("%s の hp: %d\n", pokemon2->name, pokemon2->hp);
		putchar("a");
		// 勝敗判定
		if (defender->hp <= 0) {
			printf("\n%s は倒れた!",defender->name);
			printf("%s の勝利!\n",attacker->name);
			break;
		}
		// 攻守交代の前にキー入力待ち
		printf("\n[Enter] キーを押して次のターンへ...\n");
		getchar();
		while (getchar() != '\n'); // 改行文字を読み飛ばす (バッファクリア)
		// 攻守交代
		PokemonPtr temp = attacker;
		attacker = defender;
		defender = temp;
	}
	printf("---バトル終了---\n");
}
