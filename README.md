This is a multithreaded Blackjack program, coded in C.

This was created during my Operating Systems class. It was created to run in a Linux virtual machines.

The program's purpose is to run different hands of Blackjack on various threads. 
While on one machine, it does not simultaneously run hands, it is meant to be a framework for a casino website or something similar.
This would allow it to run hands server-side, which would be important if any stakes were involved.
The program as it stands however is strictly to play Blackjack, and stores a number of chips for each user. 
It also stores a "high score" of chips, the goal being to beat the high score before going bankrupt.
In its current state, it is largely a proof of concept to work with multithreading.

The program stores an array which represents different cards. When a card is drawn, the program knows and cannot draw the same card again. By representing this with an integer array, we can keep space complexity low.
The program also uses scope effectively to give each thread its own deck.
