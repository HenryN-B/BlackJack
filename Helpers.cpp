#include <iostream>
#include "State.h"
#include "Helpers.h"
#include <string>
#include <random>
using namespace std;

int randCard() {
        int card;
        int cardNum;
        std::random_device rd;  
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> d(0, 51);
        cardNum = d(gen);
        //card = deck[cardNum];
        while (card == 0) {
            cardNum = d(gen);
            //card = deck[cardNum];
        }
        return cardNum;
    }

void display(const State &state) {
    // cout << "        \x1B[32mDealer\033[0m"<< endl;
    // cout << "      ";
    // for(int i = 0; i < 10; i++) {
    //     if (dealerCards[i] != 0) {
    //         if (dealerCards[i] > 9 && dealerCards[i] != 11 && !(i == 1 && !(reveal) )) {
    //             cout << "____    ";
    //         } else {
    //             cout << "___    ";
    //         }
    //     }
    // }
    // cout << "\n     ";
    // //middle part of card
    // for(int i = 0; i < 10; i++) {
    //     if (dealerCards[i] != 0) {
    //         if (dealerCards[i] > 9 && dealerCards[i] != 11 && !(i == 1 && !(reveal) )) {
    //             cout << "|    |  ";
    //         } else {
    //             cout << "|   |  ";
    //         }
    //     }
    // }
    // cout << "\n     ";

    // //number part of card

    // for(int i = 0; i < 10; i++) {
    //     if ((dealerCards[i] != 0)) {
    //         if (i == 1 && !(reveal) ) {
    //             cout << "| ? |  ";  
    //         } else if (dealerCards[i] > 9 && dealerCards[i] != 11) {        
    //             cout << "| " << dealerCards[i] << " |  ";    
    //         } else {
    //             if(i == 1 && (reveal)) {
    //                 if (dealerCards[i] == 11) {
    //                     cout << "| " << "A" << " |  ";
    //                 } else {
    //                     cout << "| " << dealerCards[i] << " |  ";
    //                 }
    //             } else {
    //                 if (dealerCards[i] == 11) {
    //                     cout << "| " << "A" << " |  ";
    //                 } else {
    //                     cout << "| " << dealerCards[i] << " |  ";
    //                 }
    //             }
    //         }
    //     }
    // }
    // cout << "\n     ";
    //  //lower part of card
    // for(int i = 0; i < 10; i++) {
    //     if (dealerCards[i] != 0) {
    //         if (dealerCards[i] > 9 && dealerCards[i] != 11 && !(i == 1 && !(reveal) )) {
    //             cout << "|____|  ";
    //         } else {
    //             cout <<"|___|  ";
    //         }
    //     }
    // }
    // if(reveal) {
    //     cout << "\n    Dealer Total:  \x1B[32m" <<  dealerCount << "\033[0m";
    // }
    // cout << "\n\n\n";
    // cout << "       \x1B[31mYour Cards\033[0m"<< endl;
    // //top part of cards
    // cout << "      ";
    // for(int i = 0; i < 10; i++) {
    //     if (playerCards[i] != 0) {
    //         if (playerCards[i] > 9 && playerCards[i] != 11) {
    //             cout << "____    ";
    //         } else {
    //             cout << "___    ";
    //         }
    //     }
    // }
    // cout << "\n     ";
    // //middle part of card
    // for(int i = 0; i < 10; i++) {
    //     if (playerCards[i] != 0) {
    //         if (playerCards[i] > 9 && playerCards[i] != 11) {
    //             cout << "|    |  ";
    //         } else {
    //             cout << "|   |  ";
    //         }
    //     }
    // }
    // cout << "\n     ";
    // //number part of card
    // for(int i = 0; i < 10; i++) {
    //     if (playerCards[i] != 0) {
    //         if (playerCards[i] > 9 && playerCards[i] != 11) {
    //             cout << "| " << playerCards[i] << " |  ";
    //         } else {
    //             if (playerCards[i] == 11) {
    //                 cout << "| " << "A" << " |  ";
    //             } else {
    //                 cout << "| " << playerCards[i] << " |  ";
    //             }
    //         }
    //     }
    // }
    // cout << "\n     ";
    // //lower part of card
    // for(int i = 0; i < 10; i++) {
    //     if (playerCards[i] != 0) {
    //         if (playerCards[i] > 9 && playerCards[i] != 11) {
    //             cout << "|____|  ";
    //         } else {
    //             cout <<"|___|  ";
    //         }
    //     }
    // }
    // cout << "\n    Your Total: \x1B[31m" << playerCount << "\033[0m";
    // cout << "\n---------------------- \n";
}
