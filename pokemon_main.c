#include <stdio.h>
#include <string.h>
#include <stdlib.h> // rand, srand
#include <time.h>   // time
#include"pokemon_game.h"
int main(void) {
	//ポケモンを作成
	PokemonPtr pikachu = New_Pokemon("ピカチュウ",100,20);
	PokemonPtr charizard = New_Pokemon("リザードン", 150, 30);
	//ポケモンの情報を提示
	printf("---ポケモン情報---\n");
	Display_pokemon(pikachu);
	printf("\n");
	Display_pokemon(charizard);
	// バトルを実行
	Battle_Pokemon(pikachu, charizard);

	// メモリの解放 (重要！)
	free(pikachu);
	free(charizard);
	pikachu = NULL;
	charizard = NULL;

	return 0;
}
