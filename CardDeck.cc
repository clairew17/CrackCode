#include"Card.h"

int main(){
	srand(time(NULL));
	Card mycard(1,2);
	//cout < SUIT[card.get_suit()]<<endl;
	//cout < RANK[card.get_rank()]<<endl;
	cout << mycard.Card2Str() << endl;

	cout << "My Deck:\n";

	Deck mydeck;
	mydeck.PrintDeck();
	
	mydeck.GetOneCard();
	mydeck.GetOneCard();


	return 0;
}