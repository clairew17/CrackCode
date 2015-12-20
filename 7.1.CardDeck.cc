//7.1.CardDeck.cc
#include"Card.h"
/*

Design the data structures for a generic deck of cards. Explain how you would sub- class it to implement particular card games.

*/
const string SUIT[SUIT_MAX]={"S","H","D","C"};
const string RANK[RANK_MAX]={"1","2","3","4","5","6","7","8","9","10","J","Q","K"};


Card::Card(){
	suit = GenerateSuit();
	rank = GenerateRank();
}

Card::Card(const int suit_v, const int rank_v){
	suit = suit_v;
	rank = rank_v;
}

int Card::GenerateSuit(){
	return rand()%(SUIT_MAX);
}

int Card::GenerateRank(){
	return rand()%(RANK_MAX);
}

int Card::GetSuit() const
{
	return suit;
}

int Card::GetRank() const
{
	return rank;
}

string Card::Card2Str() const
{
	return SUIT[GetSuit()]+RANK[GetRank()];
}

Deck::Deck(){
	for(int i=0; i<SUIT_MAX;i++){
		for(int j=0;j<RANK_MAX; j++){
			Card card(i,j);
			deck.push_back(card);
		}
	}
}
void Deck::PrintDeck() const{
	int count = 0;
	for(auto d:deck){
		cout << d.Card2Str()<<"\t";
		if(++count == 13){
			cout <<endl;
			count = 0;
		}
	}
}
void Deck::GetOneCard(){
	Card cd(deck.back().GetSuit(), deck.back().GetRank());
	deck.pop_back();
	cout <<"\n Here you are:\n"<< cd.Card2Str()<<endl;
}
