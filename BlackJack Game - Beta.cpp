// main.cpp
#include "Player.h"
#include "Dealer.h"
#include "Shoe.h"
#include "Card.h"
#include "Deck.h"
#include "Queue.h"
#include "Stack.h"
#include <iostream>

int main() {

    // Display welcome message
    std::cout << R"(


:::       ::: :::::::::: :::        ::::::::   ::::::::  ::::    ::::  ::::::::::      ::::::::::: ::::::::       :::::::::  :::            :::      ::::::::  :::    ::: ::::::::::: :::      ::::::::  :::    ::: ::: 
:+:       :+: :+:        :+:       :+:    :+: :+:    :+: +:+:+: :+:+:+ :+:                 :+:    :+:    :+:      :+:    :+: :+:          :+: :+:   :+:    :+: :+:   :+:      :+:   :+: :+:   :+:    :+: :+:   :+:  :+: 
+:+       +:+ +:+        +:+       +:+        +:+    +:+ +:+ +:+:+ +:+ +:+                 +:+    +:+    +:+      +:+    +:+ +:+         +:+   +:+  +:+        +:+  +:+       +:+  +:+   +:+  +:+        +:+  +:+   +:+ 
+#+  +:+  +#+ +#++:++#   +#+       +#+        +#+    +:+ +#+  +:+  +#+ +#++:++#            +#+    +#+    +:+      +#++:++#+  +#+        +#++:++#++: +#+        +#++:++        +#+ +#++:++#++: +#+        +#++:++    +#+ 
+#+ +#+#+ +#+ +#+        +#+       +#+        +#+    +#+ +#+       +#+ +#+                 +#+    +#+    +#+      +#+    +#+ +#+        +#+     +#+ +#+        +#+  +#+       +#+ +#+     +#+ +#+        +#+  +#+   +#+ 
 #+#+# #+#+#  #+#        #+#       #+#    #+# #+#    #+# #+#       #+# #+#                 #+#    #+#    #+#      #+#    #+# #+#        #+#     #+# #+#    #+# #+#   #+#  #+# #+# #+#     #+# #+#    #+# #+#   #+#      
  ###   ###   ########## ########## ########   ########  ###       ### ##########          ###     ########       #########  ########## ###     ###  ########  ###    ###  #####  ###     ###  ########  ###    ### ### 


)" << '\n';


    // Instantiate objects
    Shoe shoe;
    Player player(50); // Initialize player's bankroll with $50
    Dealer dealer;

    // Create and shuffle deck
    shoe.createShoe(4); // Example with 4 decks

    // Game loop
    std::string playerName;
    std::cout << "Enter your name: ";
    std::getline(std::cin, playerName);

    // Display personalized welcome message
    std::cout << "Welcome to Blackjack, " << playerName << "! You'll start with $" << player.getBankroll() << ". Good luck!\n";

    std::string playAgain = "y";
    while (playAgain == "y" || playAgain == "Y") {

        // Check if player has enough money to continue
        if (player.getBankroll() < 2) {
            std::cout << "You don't have enough money to continue." << std::endl;
            break; // End game if player doesn't have enough money to play
        }

        // Ask player for bet amount
        int betAmount;
        std::cout << "Enter bet amount (minimum $2): ";
        while (!(std::cin >> betAmount)) {
            std::cin.clear(); // clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the rest of the line
            std::cout << "Invalid input. Please enter a number: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
        std::cout << "\n\n";



        // Check if bet amount is valid
        if (betAmount < 2 || betAmount > player.getBankroll()) {
            std::cout << "Invalid bet amount. Please enter a value between $2 and your current bankroll ($" << player.getBankroll() << ")." << std::endl;
            continue;
        }

        player.bet(betAmount);

        // Deal cards
        dealer.dealInitialCards(player, shoe);

        // After dealing initial cards
        std::cout << playerName << "'s hand: " << player.getHand() << std::endl;
        std::cout << "Dealer's hand: " << dealer.getHand().at(0) << " and a hidden card" << std::endl;
        std::cout << playerName << "'s total value: " << player.calculateOptimalValue() << std::endl;


        // Check if player or dealer has blackjack
        if (player.calculateOptimalValue() == 21 || dealer.calculateOptimalValue() == 21) {

            // If dealer has blackjack, display dealer's hand and total value
            if (dealer.calculateOptimalValue() == 21) {
                std::cout << "\n";  //Line break
                std::cout << "Dealer's hand: " << dealer.getHand() << std::endl;
                std::cout << "Dealer's total value: " << dealer.calculateOptimalValue() << std::endl;
            }

            // If player has blackjack, display dealer's hand and total value
            if (player.calculateOptimalValue() == 21) {
                std::cout << "\n";  //Line break
            	std::cout << "Dealer's hand: " << dealer.getHand() << std::endl;
                std::cout << "Dealer's total value: " << dealer.calculateOptimalValue() << std::endl;
            }

        	if (player.calculateOptimalValue() == dealer.calculateOptimalValue()) {
                // It's a tie
                player.updateBankroll(betAmount); // Player gets their bet back
                std::cout << R"(
_______________                       __________     ______
____  _/_  /_( )_______   ______ _    __  /___(_)_______  /
 __  / _  __/|/__  ___/   _  __ `/    _  __/_  /_  _ \_  / 
__/ /  / /_    _(__  )    / /_/ /     / /_ _  / /  __//_/  
/___/  \__/    /____/     \__,_/      \__/ /_/  \___/(_)   
)" << '\n';
                std::cout << "Total amount remaining: $" << player.getBankroll() << "\n";

            }
            else if (player.calculateOptimalValue() == 21) {
                // Player wins
                player.updateBankroll(betAmount * 2); // Player gets their bet back plus winnings
                std::cout << R"(


______________                                        _____                            ________________                  ______________            ______ ________             ______  
___  __ \__  /_____ _____  ______________   ___      ____(_)______________   ___      ____(_)_  /___  /_     ______ _    ___  __ )__  /_____ _________  /_______(_)_____ _________  /__
__  /_/ /_  /_  __ `/_  / / /  _ \_  ___/   __ | /| / /_  /__  __ \_  ___/   __ | /| / /_  /_  __/_  __ \    _  __ `/    __  __  |_  /_  __ `/  ___/_  //_/____  /_  __ `/  ___/_  //_/
_  ____/_  / / /_/ /_  /_/ //  __/  /       __ |/ |/ /_  / _  / / /(__  )    __ |/ |/ /_  / / /_ _  / / /    / /_/ /     _  /_/ /_  / / /_/ // /__ _  ,<  ____  / / /_/ // /__ _  ,<   
/_/     /_/  \__,_/ _\__, / \___//_/        ____/|__/ /_/  /_/ /_//____/     ____/|__/ /_/  \__/ /_/ /_/     \__,_/      /_____/ /_/  \__,_/ \___/ /_/|_| ___  /  \__,_/ \___/ /_/|_|  
                    /____/                                                                                                                                /___/                        


)" << '\n';
                std::cout << "Total amount remaining: $" << player.getBankroll() << "\n\n";

            }
            else {
                // Dealer wins, player loses their bet
                std::cout << R"(


________            ______                         _____                            ________________                  ______________            ______ ________             ______  
___  __ \__________ ___  /____________   ___      ____(_)______________   ___      ____(_)_  /___  /_     ______ _    ___  __ )__  /_____ _________  /_______(_)_____ _________  /__
__  / / /  _ \  __ `/_  /_  _ \_  ___/   __ | /| / /_  /__  __ \_  ___/   __ | /| / /_  /_  __/_  __ \    _  __ `/    __  __  |_  /_  __ `/  ___/_  //_/____  /_  __ `/  ___/_  //_/
_  /_/ //  __/ /_/ /_  / /  __/  /       __ |/ |/ /_  / _  / / /(__  )    __ |/ |/ /_  / / /_ _  / / /    / /_/ /     _  /_/ /_  / / /_/ // /__ _  ,<  ____  / / /_/ // /__ _  ,<   
/_____/ \___/\__,_/ /_/  \___//_/        ____/|__/ /_/  /_/ /_//____/     ____/|__/ /_/  \__/ /_/ /_/     \__,_/      /_____/ /_/  \__,_/ \___/ /_/|_| ___  /  \__,_/ \___/ /_/|_|  
                                                                                                                                                       /___/                        


)" << '\n';
                std::cout << "Total amount remaining: $" << player.getBankroll() << "\n\n";

            }
            player.clearHand();
            dealer.clearHand();
            continue; // Skip the rest of the round
        }

        // Player's turn
        while (!player.isBust() && player.wantsToHit()) {
            player.hit(shoe);

            // Display player's hand and total after player hits
            std::cout << playerName << "'s hand: " << player.getHand() << std::endl;
            std::cout << playerName << "'s total value: " << player.calculateOptimalValue() << std::endl;

        }

        
        // Dealer's turn
        dealer.dealerTurn(shoe);

        // After dealer's turn
        std::cout << "\n";  //Line break
        std::cout << "Dealer's hand: " << dealer.getHand() << std::endl;
        std::cout << "Dealer's total value: " << dealer.calculateOptimalValue() << std::endl;

        // Determine winner and adjust bankrolls
        if (player.isBust()) {
            // Dealer wins, player loses their bet
            std::cout << R"(
________            ______                ___       ______              ______
___  __ \__________ ___  /____________    __ |     / /__(_)________________  /
__  / / /  _ \  __ `/_  /_  _ \_  ___/    __ | /| / /__  /__  __ \_  ___/_  / 
_  /_/ //  __/ /_/ /_  / /  __/  /        __ |/ |/ / _  / _  / / /(__  ) /_/  
/_____/ \___/\__,_/ /_/  \___//_/         ____/|__/  /_/  /_/ /_//____/ (_)   
                                           
)" << '\n';
        }
        else if (dealer.isBust() || player.calculateOptimalValue() > dealer.calculateOptimalValue()) {
            // Player wins
            player.updateBankroll(betAmount * 2); // Player gets their bet back plus winnings
            std::cout << R"(
______________                               ___       ______              ______
___  __ \__  /_____ _____  ______________    __ |     / /__(_)________________  /
__  /_/ /_  /_  __ `/_  / / /  _ \_  ___/    __ | /| / /__  /__  __ \_  ___/_  / 
_  ____/_  / / /_/ /_  /_/ //  __/  /        __ |/ |/ / _  / _  / / /(__  ) /_/  
/_/     /_/  \__,_/ _\__, / \___//_/         ____/|__/  /_/  /_/ /_//____/ (_)   
                    /____/                                                       
)" << '\n';
        }
        else if (player.calculateOptimalValue() < dealer.calculateOptimalValue()) {
            // Dealer wins, player loses their bet
            std::cout << R"(
________            ______                ___       ______              ______
___  __ \__________ ___  /____________    __ |     / /__(_)________________  /
__  / / /  _ \  __ `/_  /_  _ \_  ___/    __ | /| / /__  /__  __ \_  ___/_  / 
_  /_/ //  __/ /_/ /_  / /  __/  /        __ |/ |/ / _  / _  / / /(__  ) /_/  
/_____/ \___/\__,_/ /_/  \___//_/         ____/|__/  /_/  /_/ /_//____/ (_)   
                                           
)" << '\n';
        }
        else {
            // It's a tie
            player.updateBankroll(betAmount); // Player gets their bet back
            std::cout << R"(
_______________                       __________     ______
____  _/_  /_( )_______   ______ _    __  /___(_)_______  /
 __  / _  __/|/__  ___/   _  __ `/    _  __/_  /_  _ \_  / 
__/ /  / /_    _(__  )    / /_/ /     / /_ _  / /  __//_/  
/___/  \__/    /____/     \__,_/      \__/ /_/  \___/(_)   
)" << '\n';
        }

        // Print total amount remaining
        std::cout << "Total amount remaining: $" << player.getBankroll() << "\n\n";

        // Clear hands
        player.clearHand();
        dealer.clearHand();

        // Ask player if they want to play another hand
        do {
            std::cout << "Would you like to play another hand? (y/n): ";
            std::getline(std::cin, playAgain);
            if (playAgain != "y" && playAgain != "Y" && playAgain != "n" && playAgain != "N") {
                std::cout << "Invalid response. Please enter 'y' or 'n'.\n";
            }
        } while (playAgain != "y" && playAgain != "Y" && playAgain != "n" && playAgain != "N");
    }

    // Display game over message
    std::cout << R"(
_________                            _______                   ______
__  ____/_____ _______ ________      __  __ \__   ________________  /
_  / __ _  __ `/_  __ `__ \  _ \     _  / / /_ | / /  _ \_  ___/_  / 
/ /_/ / / /_/ /_  / / / / /  __/     / /_/ /__ |/ //  __/  /    /_/  
\____/  \__,_/ /_/ /_/ /_/\___/      \____/ _____/ \___//_/    (_)   
)" << '\n';

    // Display total amount won or lost
    std::cout << "Total amount won or lost: " << (player.getBankroll() - 50) << std::endl;

    // Wait for player to close console window
    system("pause");

    return 0;
}
