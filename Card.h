//Card.h
#ifndef CARD_H
#define CARD_H
#include<string>
#include<iostream>
#include<vector>
using namespace std;

const int SUIT_MAX(4);
const int RANK_MAX(13);
class Deck;

class Card
{
	friend class Deck;
public:
	Card();
	Card(const int suit_v, const int rank_v);
	string Card2Str() const;
private:
	int GenerateSuit();
	int GenerateRank();
	int GetSuit() const;
	int GetRank() const;
	int suit;
	int rank;
};

class Deck
{
public:
	Deck();
	void PrintDeck() const;
	void GetOneCard();
private:
	vector<Card> deck;

};

#endif