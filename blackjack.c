#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


int chips = 50;
int highScore = 200;
pthread_mutex_t lock;

private int bet = 0;
private int hasAce = 0;
private int dealerHasAce = 0;
private char action = ‘’;
private int deck[52];
private handVal = 0;
private int dealerVal = 0;
private int stand = 0;
private int hasBlackjack = 0;


void *play(void *var)
{
	if (chips > 0) {
		pthread_mutex_lock(&lock);
		printf(“You have %d chips. Please enter your bet:”, chips);
		scanf(“%d”, &bet);
		if (bet > chips) {
			bet = chips; }
		playerCard();
		dealerCard();
		playerCard();
		printf(“The dealer has %d, and an upside down card.”, dealerVal”);
		if (handVal == 21) {
			blackjack();
		}
		while(stand != 1 && handVal < 21) {
			printf(‘Type “h” to hit, “s” to stand, or “d” to double’);
scanf(“%c”, action);
switch(acion) {
	case ‘h’:
		playerCard();
		if (handVal > 21) {
			stand = 1; }
		break;
	case ‘s’:
		stand =1;
		break;
	case ‘d’:
		if (bet <= (2 * chips) {
			bet = bet*2;
			playerCard();
			stand = 1;
		}
		else {
			printf(“You do not have enough chips to double.”);
		}
		break;
	default:
		printf(“Please type “h”, “s”, or “d”);
		break;
}
		}
		while (dealerVal >= 16 && handVal < 22) {
				dealerCard();
		}
		if(handVal < 22) {
			if (handVal > dealerVal || hasBlackjack = 1) {
				printf(“Your Hand is a %d, and the dealers hand is %d. You win!”, handVal, dealerVal);
				win();
			}
			else {
if (handVal == dealerVal) {
	tie();
}
else {
	printf(“Your Hand is a %d, and the dealers hand is %d. You lose.”, handVal, dealerVal);
lose();
}
			else {
				printf(“You have busted. You lose.”);
				lose();
			}
		pthread_mutex_unlock(&lock);
		shuffle();
		play();
}
	else {
		gameOver();
	}
}

int main()
{
	pthread_t tid;
pthread_create(&tid, NULL, play, (void *)&tid);
	pthread_exit(NULL);
pthread_mutex_destroy(&lock);
	return 0;
}

int playerCard()
{
	//checks if card is still in deck
	int card;
	int inDeck = 0;
	while (inDeck != 1)  {
		card = rand() % 52;
		if (deck[card] == 0) {
			Deck[card] = 1;
			inDeck = 1; }}
	inDeck = 0;
	card = (card/4) + 1;
	if (card == 1) {
		if (handVal <= 10) {
			handVal += 11;
			hasAce = 1; }
		else{
			handVal += 1; }
		print(“You were dealt an Ace. Your Hand Value is %d.\n”, handVal);
		return 0; }
	if (card <= 10) {
		handVal += card;
if (hasAce == 1 && handVal > 21) {
handVal -= 10;
hasAce = 0; }
		print(“You were dealt a %d. Your Hand Value is %d.\n”, card, handVal);
		return 0; }
	if (card = 11) {
		handVal += 10;
if (hasAce == 1 && handVal > 21) {
handVal -= 10; 
hasAce = 0; }
		print(“You were dealt a Jack. Your Hand Value is %d.\n”, handVal);
		return 0; }
if (card = 11) {
		handVal += 10;
if (hasAce == 1 && handVal > 21) {
handVal -= 10; 
hasAce = 0; }
		print(“You were dealt a Jack. Your Hand Value is %d.\n”, handVal);
		return 0; }
	handVal += 10;
if (hasAce == 1 && handVal > 21) {
handVal -= 10;
hasAce = 0; }
	print(“You were dealt a King. Your Hand Value is %d.\n”, handVal);
	return 0;
}

int dealerCard()
{
int card;
	int inDeck = 0;
	while (inDeck != 1)  {
		card = rand() % 52;
		if (deck[card] == 0) {
			Deck[card] = 1;
			inDeck = 1; }}
	inDeck = 0;
	card = (card/4) + 1;
	if (card == 1) {
		if (dealerVal <= 10) {
			dealerVal += 11;
			hasAce=1; }
		else {
			dealerVal += 1; }
		return 0; }
	if (card <= 10) {
		dealerVal += card;
		if (dealerHasAce == 1 && dealerVal > 21) {
			dealerHasAce = 0;	
dealerVal -= 10; }
return 0; } 
	if (card = =11) {
		dealerVal+= 10;
if (dealerHasAce == 1 && dealerVal > 21) {
dealerHasAce -= 10;
hasAce = 0;	}
		return 0; }
if (card == 12) {
		handVal += 10;
		if (dealerHasAce == 1 && dealerVal > 21) {
dealerVal -= 10;
dealerHasAce = 0; }	
		return 0;
	dealerVal += 10;
	if (dealerHasAce == 1 && dealerVal > 21) {
dealerVal -= 10;
hasAce = 0; }	
	return 0;
}

void shuffle()
{
	//is executed on a thread that is not being used
hasAce = 0;
dealerHasAce = 0;
handVal = 0;
dealerVal = 0;	
Action = ‘’;
for (i = 0; i < 52;  i++)
		deck[i] = 0;
}


void win() {
	chips += bet;
}

void lose() {
	chips -= bet;
}

void blackJack() {
	printf(“Blackjack! You win triple.”);
	chips += bet;
}

Void tie() {
	printf(“Draw”);
} 
