#ifndef _POKEMON_GAME_H
#define _POKEMON_GAME_H
typedef struct{
	char name[256];
	int hp;
	int ap;
}Pokemon;
typedef Pokemon* PokemonPtr;
// 新しいポケモンを作成する関数
PokemonPtr New_Pokemon(const char*,int ,int);
// ポケモンの情報を表示する関数
void Display_pokemon(PokemonPtr);
// バトルを行う関数
void Battle_Pokemon(PokemonPtr, PokemonPtr);

#endif // !_POKEMON_GAME_H
