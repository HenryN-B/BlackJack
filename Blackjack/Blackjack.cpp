#include <chrono>
#include <ctime>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <random>
#include <string>
#include "Blackjack.h"
using namespace std;

    //function to get random card
    int Blackjack::randCard() {
        int card;
        int cardNum;
        std::random_device rd;  
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> d(0, 51);
        cardNum = d(gen);
        card = deck[cardNum];
        while (card == 0) {
            cardNum = d(gen);
            card = deck[cardNum];
        }
        return cardNum;
    }
    
    //shuffles the deck and puts all cards back into the deck 
    int* Blackjack::shuffleDeck(){
        const int deckSize = 52;
        int* deck = new int[deckSize];
        std::ifstream inputFile("deck.txt");
        if (!inputFile.is_open()) {
            throw std::runtime_error("Failed to open file: deck.txt");
        }
        int index = 0; 
        int num;
        while (inputFile >> num && index < deckSize) {
            deck[index] = num;
            index ++;
        }
        reSuffle = false;
        return deck;
    }
    
    //
    void Blackjack::deal() {
        for(int i = 0; i < 4; i++) {
            if(i%2 == 1) {
                hit("Player");
            } else {
                hit("Dealer");
            }
        }
    }

    void Blackjack::winCheck() {
        if(playerCount == 21 && playerHitCount == 0) {
            reveal = true;
            printGameBoard();
            cout << "Black Jack! Player Wins.";
            money = (money) + bet*1.5;
        } else if(playerCount > 21) {
            reveal = true;
            printGameBoard();
            cout << "Player Bust! Dealer Wins.";
            money -= bet;
        } else if (dealerCount > 21) {
            cout << "Dealer Bust! Player Wins.";
            money = (money-bet) + bet*2;
        } else if(playerCount == dealerCount) {
            cout << "Tie!";
        } else if(playerCount > dealerCount) {
            cout << "Player is closer to 21! Player Wins.";
            money = (money-bet) + bet*2;
        } else if(dealerCount > playerCount) {
            cout << "Dealer is closer to 21! Dealer Wins.";
            money -= bet;
        } else {
            cout << "Something went wrong lmao idk not going to fix it";
        }
    }

    void Blackjack::hit(string str) {
        int count =0;
        int cards[12] = {0};
        bool A;
        int hCount =0;

        if (str == "Player") {
            count = playerCount;
            for(int i = 0; i < 13; i++) {
                cards[i] = playerCards[i];
            }
            A = aceP;
            hCount =playerHitCount;

        } else {
            count = dealerCount;
            for(int i = 0; i < 13; i++) {
                cards[i] = dealerCards[i];
            }
            A = aceD;
            hCount = dealerHitCount;
        }
        int cardNum = randCard();
        int card = deck[cardNum];
        if(A) {
            if(card == 11) {
               if(count+card > 21) {
                    count += card;
                    deck[cardNum] = 0;
                    count -= 10;
                    cards[hCount] = card;
                } 
            } else {
                if(count+card > 21) {
                    count += card;
                    deck[cardNum] = 0;
                    count -= 10;
                    A = false;
                     cards[hCount] = card;
                } else {
                    deck[cardNum] = 0;
                    count += card;
                     cards[hCount] = card;
                }
            }
        } else {
            if(card == 11) {
                    A = true;
                    if(count+card > 21) {
                        
                        count += card;
                        count -= 10;
                        deck[cardNum] = 0;
                        A = false;
                        cards[hCount] = card;
                    } else {
                        count += card;
                        deck[cardNum] = 0;
                         cards[hCount] = card;
                    }
                } else {
                    count += card;
                    deck[cardNum] = 0;
                    cards[hCount] = card;
                }
        } 
        if (str == "Player") {
            playerCount = count;
            for(int i = 0; i < 13; i++) {
                playerCards[i] = cards[i];
            }
            aceP = A;
           playerHitCount++; 
        } else {
            dealerCount = count;
            for(int i = 0; i < 13; i++) {
                dealerCards[i] = cards[i];
            }
            aceD = A;
            dealerHitCount++;
        }
    }

    void Blackjack::stay() {
        reveal = true;
        while(dealerCount < 17) {
            hit("Dealer");
        }
        printGameBoard();
    }

    void Blackjack::printGameBoard() {
        cout << "        \x1B[32mDealer\033[0m"<< endl;


         cout << "      ";
        for(int i = 0; i < 10; i++) {
            if (dealerCards[i] != 0) {
                if (dealerCards[i] > 9 && dealerCards[i] != 11 && !(i == 1 && !(reveal) )) {
                    cout << "____    ";
                } else {
                    cout << "___    ";
                }
            }
        }
        cout << "\n     ";
        //middle part of card
        for(int i = 0; i < 10; i++) {
            if (dealerCards[i] != 0) {
                if (dealerCards[i] > 9 && dealerCards[i] != 11 && !(i == 1 && !(reveal) )) {
                    cout << "|    |  ";
                } else {
                    cout << "|   |  ";
                }
            }
        }
        cout << "\n     ";

        //number part of card

        for(int i = 0; i < 10; i++) {
            if ((dealerCards[i] != 0)) {
                if (i == 1 && !(reveal) ) {
                    cout << "| ? |  ";  
                } else if (dealerCards[i] > 9 && dealerCards[i] != 11) {
                    
                        cout << "| " << dealerCards[i] << " |  ";
                    
                } else {
                    if(i == 1 && (reveal)) {
                         if (dealerCards[i] == 11) {
                            cout << "| " << "A" << " |  ";
                        } else {
                            cout << "| " << dealerCards[i] << " |  ";
                        }
                    } else {
                        if (dealerCards[i] == 11) {
                            cout << "| " << "A" << " |  ";
                        } else {
                            cout << "| " << dealerCards[i] << " |  ";
                        }
                    }
                }
            }

        }
        cout << "\n     ";
         //lower part of card
        for(int i = 0; i < 10; i++) {
            if (dealerCards[i] != 0) {
                if (dealerCards[i] > 9 && dealerCards[i] != 11 && !(i == 1 && !(reveal) )) {
                    cout << "|____|  ";
                } else {
                    cout <<"|___|  ";
                }
            }
        }
        if(reveal) {
            cout << "\n    Dealer Total:  \x1B[32m" <<  dealerCount << "\033[0m";
        }

        cout << "\n\n\n";
        cout << "       \x1B[31mYour Cards\033[0m"<< endl;



        //top part of cards
        cout << "      ";
        for(int i = 0; i < 10; i++) {
            if (playerCards[i] != 0) {
                if (playerCards[i] > 9 && playerCards[i] != 11) {
                    cout << "____    ";
                } else {
                    cout << "___    ";
                }
            }
        }
        cout << "\n     ";
        //middle part of card
        for(int i = 0; i < 10; i++) {
            if (playerCards[i] != 0) {
                if (playerCards[i] > 9 && playerCards[i] != 11) {
                    cout << "|    |  ";
                } else {
                    cout << "|   |  ";
                }
            }
        }
        cout << "\n     ";

        //number part of card

        for(int i = 0; i < 10; i++) {
            if (playerCards[i] != 0) {
                if (playerCards[i] > 9 && playerCards[i] != 11) {
                    cout << "| " << playerCards[i] << " |  ";
                } else {
                    if (playerCards[i] == 11) {
                        cout << "| " << "A" << " |  ";
                    } else {
                        cout << "| " << playerCards[i] << " |  ";
                    }
                }
            }
        }
        cout << "\n     ";


       
         //lower part of card
        for(int i = 0; i < 10; i++) {
            if (playerCards[i] != 0) {
                if (playerCards[i] > 9 && playerCards[i] != 11) {
                    cout << "|____|  ";
                } else {
                    cout <<"|___|  ";
                }
            }
        }


        cout << "\n    Your Total: \x1B[31m" << playerCount << "\033[0m";
        cout << "\n---------------------- \n";
    }

    void Blackjack::askForBet() {
        while((bet < 1) || bet > money) {
            cout << "Balance:\x1B[35m " << money << "\033[0m\nAmount to Bet: \x1B[35m" << endl;
            cin >> bet;
            cout << "\033[0m";
            if(bet == -410) {
                money = 10000000;
            }
            if (std::cin.fail()) {
                cin.clear();                           
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "\n\x1B[33mInvalid input. Please enter a valid number.\033[0m" << endl;
            } else if(bet > money || bet < 1) {
                cout << "\n\x1B[33mInvalid bet amount. Please enter a bet between 1 and your current balance.\033[0m" << endl;
            }
            cout << "\n\n\n";
        }
    }

    void Blackjack::countReSet() {
        if(money < 1) {
            cout << "Out of money!" << endl;;
            delete  [] deck;
            exit(1);
        }
        playerCount = 0;
        dealerCount = 0;
        bet = 0;
        aceP = false;
        aceD = false;
        reveal = false;
        for(int i = 0; i<11; i++) {
            dealerCards[i] = 0;
        }
        for(int i = 0; i<11; i++) {
            playerCards[i] = 0;
        }
       playerHitCount = 0;
        dealerHitCount = 0;
        //checking reShuffle
        int zeroCount = 0;
        for(int i = 0; i < 52; i++) {
            if(deck[i] == 0 ) {
                zeroCount++;
            }
        }
        if( zeroCount > 40) {
            cout << "ReShuffling Deck." << endl;
            delete  [] deck;
            reSuffle = true;
        }

    }

    Blackjack::Blackjack() {
        reSuffle = false;
        aceP = false;
        aceD = false;
        reveal = false;
        playerCount = 0;
        dealerCount = 0;
        playerHitCount = 0;
        dealerHitCount =0;
        deck = shuffleDeck();
        bet = 0;
        money = 100;
    }

    void Blackjack::play() {
        int con = 1;
        int hs = 0;
        cout << "this runs 2";
        while (con != 0) {
            countReSet();
            if(reSuffle) {
               deck = shuffleDeck();
            }
            askForBet();
            deal();
            while ( !(reveal) && playerCount < 22) {
                printGameBoard();
                cout << "\x1B[33mWould you like to Hit or Stay \nHit: 1 \nStay: 2\033[0m" << endl;
                cin >> hs;
                cout << "\n\n\n";
                if (std::cin.fail()) {
                    cin.clear();                           
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } else if(hs == 1) {
                    cout << endl;
                    hit("Player");
                } else if(hs == 2) {
                    cout << endl;
                    stay();
                    
                } else if( hs != (1 || 2)) {
                    continue;
                } 
            }
            if(!(reveal));
            winCheck();
            cout << "\n\x1B[33mwould you like to keep playing? \nno: 0 \nyes: 1\033[0m" << endl;
            cin >> con;
            if(con == 0) {
                delete  [] deck;
            }
            if (std::cin.fail()) {
                cin.clear();                           
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                con = 1;
            } 
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        }
    }
