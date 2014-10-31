#include <iostream>
#include <vector>
class BlackjackWinner {
public:
	int winnings(int bet, int dealer, int dealerBlackjack, int player,
			int blackjack) {
		if (dealerBlackjack == 1)
			return -1 * bet;
		else if (blackjack == 1)
			return 1.5 * bet;
		else if (dealerBlackjack == blackjack && player > dealer && player < 22)
			return bet;
		else if (dealerBlackjack == blackjack &&  dealer > 22)
			return bet;
		else
			return -1 * bet;
	}

};
