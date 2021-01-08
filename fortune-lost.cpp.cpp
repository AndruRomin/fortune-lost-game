// Text Adventure Game Project

#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <stdlib.h>

int main() {

    std::string playerName;

    int gameScene = 0;
    int playerChoice;
    int gamePause = 1500;
    int endGameCounter = 0;

    bool playerDuck = false;
    bool playerRun = false;

    bool gameActive = true;
    bool gameStarted = false;

    bool hasWallet = false;
    bool hasPokerChip = false;
    bool hasCarKeys = false;
    bool hasAllItems = false;

    int gameOverCount = 0;
    int gameScore = 0;


    // Main game loop
    while (gameActive == true) {

        int playerEvent = rand() % 5 + 1;
        int randomEvent = rand() % 10 + 1;
        int triggerEvent = rand() % 10 + 1;

        playerChoice = 0; // Resets the player choice variable before each cycle
        system("cls"); // Clears the screen before each cycle
        
        // Checks to see if the game has been started and checks game events
        if (gameStarted == true) {

            if (endGameCounter > 5) {
                gameStarted = false;
                gameScene = 16;
            }
            
            while (gameStarted == true) {
                
                //Uncomment if you wish to see the random and player event dialog for debugging

                //std::cout << "Random Event: " << randomEvent << " : " << triggerEvent << "\n";
                //std::cout << "Player Event: " << playerEvent << " : " << triggerEvent << "\n";
                //Sleep(gamePause);          

                if (playerDuck == true) {
                    
                    if (playerEvent == triggerEvent) {
                        playerDuck = false;
                        Sleep(gamePause);
                        gameScene = 13;
                    }
                    else if (playerEvent != triggerEvent) {
                        playerDuck = false;
                        gameScore += 10;
                        Sleep(gamePause);
                        gameScene = 15;
                    }
                    break;
                }
                else if (playerRun == true) {
                    
                    if (playerEvent == triggerEvent) {
                        playerRun = false;
                        Sleep(gamePause);
                        gameScene = 13;
                    }
                    else if (playerEvent != triggerEvent) {
                        playerRun = false;
                        gameScore += 10;
                        Sleep(gamePause);
                        gameScene = 14;
                    }
                    break;
                }
                else if (hasWallet == true && hasCarKeys == true && hasPokerChip == true) {
                    hasAllItems = true;
                    break;
                }
                else {
                    break;
                }
            }
        }

        // Add game scene and logic here
        switch (gameScene) {
            
            // Main Title Screen 
            case 0:
                std::cout << "############################| Fortune Lost |############################" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                             Fortune Lost                             #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                          By Andrew Tijerina                          #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                             Version 1.1                              #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "########################################################################" << "\n";
                Sleep(gamePause);
                gameScene = 1;
                break;

            // Player Name Input
            case 1:
                std::cout << "############################| Fortune Lost |############################" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                      What's your name 'Big Chief'?                   #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                  Enter you name below, and hit ENTER:                #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "########################################################################" << "\n";

                std::cin >> playerName;
                Sleep(gamePause);
                gameScene = 2;
                break;
            
            // Loading cutscene to begin game
            case 2:
                std::cout << "############################| Fortune Lost |############################" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                             - LOADING -                              #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#         Well, it looks like your 'fortune' has taken a turn...       #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "########################################################################" << "\n";

                Sleep(gamePause);
                gameScene = 3;
                break;

            // Begin taking input from player and start game, add on scenes to build up suspense
            case 3:
                std::cout << "############################| Fortune Lost |############################" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#     You awaken, your head pounding. The sun beating down on you...   #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#               ...'Where am I?'...                                    #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                           ...'What happened?'...                     #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#       You roll over and pull yourself up: What do you do next?       #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "########################################################################" << "\n";
                std::cout << "         1) Look around   2) Lay back down   3) Scream for help         " << "\n";

                std::cin >> playerChoice;
                gameStarted = true;

                if (playerChoice == 1) {
                    gameScene = 4;
                    gameScore += 10;
                    break;
                }
                else if (playerChoice == 2) {
                    gameScene = 5;
                    gameScore -= 5;
                    break;
                }
                else if (playerChoice == 3) {
                    gameScene = 6;
                    gameScore -= 5;
                    break;
                }
                else {
                    gameActive = false;
                    break;
                }
                break;

            case 4:
                std::cout << "############################| Fortune Lost |############################" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#               You sit up, and take a look around...                  #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                    To your left, a dead body...                      #" << "\n";
                std::cout << "#                    To your right, a poker chip...                    #" << "\n";
                std::cout << "#          Ahead, a lone cactus, with something shining on it          #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                       What do you do next?                           #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "########################################################################" << "\n";
                std::cout << "                  1) Body   2) Poker Chip   3) Cactus                   " << "\n";

                std::cin >> playerChoice;

                if (playerChoice == 1) {
                    gameScene = 7;
                    gameScore += 2;
                    break;
                }
                else if (playerChoice == 2) {
                    gameScene = 8;
                    gameScore += 2;
                    break;
                }
                else if (playerChoice == 3) {
                    gameScene = 9;
                    gameScore += 2;
                    break;
                }
                else {
                    gameActive = false;
                    break;
                }
                break;
            // Game over state 1
            case 5:
                std::cout << "############################| Fortune Lost |############################" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                              GAME OVER                               #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#            Exhausted, you lay back down, just for a minute           #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#            ...You succumb to the heat, and never wake up...          #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "########################################################################" << "\n";
                std::cout << "                          1) Retry   2) Quit                            " << "\n";

                std::cin >> playerChoice;

                if (playerChoice == 1) {
                    gameScene = 2;
                    gameOverCount += 1;
                    break;
                }
                else {
                    gameActive = false;
                    break;
                }
                break;
            // Game over state 2
            case 6:
                std::cout << "############################| Fortune Lost |############################" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                              GAME OVER                               #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#             Helplessly, you let a loud scream for help...            #" << "\n";
                std::cout << "#        You collapse back on the ground, as a gunshot rings out       #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#        The last thing you see, a pair boots standing over you...     #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "########################################################################" << "\n";
                std::cout << "                          1) Retry   2) Quit                            " << "\n";

                std::cin >> playerChoice;

                if (playerChoice == 1) {
                    gameScene = 2;
                    gameOverCount += 1;
                    break;
                }
                else {
                    gameActive = false;
                    break;
                }
                break;

            case 7:
                std::cout << "############################| Fortune Lost |############################" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#          You crawl towards the body, and search the pockets          #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#            He has your wallet in his pocket, nothing else...         #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                    'Why does he have my wallet?'                     #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                       What do you do next?                           #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "########################################################################" << "\n";
                std::cout << "              1) Take Wallet   2) Look Around   3) Return               " << "\n";

                std::cin >> playerChoice;

                if (playerChoice == 1 && hasWallet == false) {
                    std::cout << "You take the wallet, your plane ticket intact, oddly nothing else appears to be missing." << "\n";
                    Sleep(gamePause);
                    gameScore += 15;
                    hasWallet = true;
                    break;
                }
                else if (playerChoice == 1 && hasWallet == true) {
                    std::cout << "You already have the wallet." << "\n";
                    gameScore -= 1;
                    Sleep(gamePause);
                    break;
                }
                else if (playerChoice == 2) {
                    std::cout << "Your eyes keep coming to the Cactus in the distance, something is drawing you towards it." << "\n";
                    Sleep(gamePause);
                    break;
                }
                else if (playerChoice == 3) {
                    triggerEvent = rand() % 10 + 1;
                    gameScene = 10;
                    break;
                }
                else {
                    gameActive = false;
                    break;
                }
                break;

            case 8:
                std::cout << "############################| Fortune Lost |############################" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                You reach down and pickup the poker chip              #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                                 $1000                                #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                    The 4 Chiefs Casino and Resort                    #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                         What do you do next?                         #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "########################################################################" << "\n";
                std::cout << "              1) Take Chip   2) Look Around   3) Return                 " << "\n";

                std::cin >> playerChoice;

                if (playerChoice == 1 && hasPokerChip == false) {
                    std::cout << "You take the chip, something feels oddly familiar about it." << "\n";
                    Sleep(gamePause);
                    gameScore += 15;
                    hasPokerChip = true;
                    break;
                }
                else if (playerChoice == 1 && hasPokerChip == true) {
                    std::cout << "You already have the chip." << "\n";
                    Sleep(gamePause);
                    gameScore -= 1;
                    break;
                }
                else if (playerChoice == 2) {
                    std::cout << "Your eyes keep coming to the Cactus in the distance, something is drawing you towards it." << "\n";
                    Sleep(gamePause);
                    break;
                }
                else if (playerChoice == 3) {
                    triggerEvent = rand() % 10 + 1;
                    gameScene = 10;
                    break;
                }
                else {
                    gameActive = false;
                    break;
                }
                break;

            case 9:
                std::cout << "############################| Fortune Lost |############################" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#   You crawl towards the cactus, the object shining comes into view   #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#            Your car keys are hanging on one of the spines            #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                  'What are my keys doing out here?'                  #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                         What do you do next?                         #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "########################################################################" << "\n";
                std::cout << "              1) Take Keys   2) Look Around   3) Return                 " << "\n";

                std::cin >> playerChoice;

                if (playerChoice == 1 && hasCarKeys == false) {
                    std::cout << "You take the car keys, your valet tag is still attached." << "\n";
                    hasCarKeys = true;
                    Sleep(gamePause);
                    gameScore += 15;
                    break;
                }
                else if (playerChoice == 1 && hasCarKeys == true) {
                    std::cout << "You already have the keys." << "\n";
                    Sleep(gamePause);
                    gameScore -= 1;
                    break;
                }
                else if (playerChoice == 2) {
                    gameScene = 11;
                    break;
                }
                else if (playerChoice == 3 && hasAllItems == true) {
                    std::cout << "There's no way you can go back, you're drained.";
                    Sleep(gamePause);
                    gameScore -= 5;
                    triggerEvent = rand() % 10 + 1;
                    break;
                }
                else if (playerChoice == 3 && hasAllItems == false) {
                    triggerEvent = rand() % 10 + 1;
                    gameScore -= 1;
                    gameScene = 10;
                }
                else {
                    gameActive = false;
                    break;
                }
                break;

            case 10:
                std::cout << "############################| Fortune Lost |############################" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#              You make your way back to where you started...          #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#   The sun beating down on you, you realize you don't have much time  #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                       What do you do next?                           #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "########################################################################" << "\n";
                std::cout << "                   1) Body 2) Poker Chip 3) Cactus                      " << "\n";

                std::cin >> playerChoice;

                if (playerChoice == 1 && hasWallet == true) {
                    std::cout << "There's no reason to go back over there, he's dead." << "\n";
                    Sleep(gamePause);
                    gameScene = 10;
                    break;
                }
                else if (playerChoice == 1 && hasWallet == false) {
                    gameScene = 7;
                    Sleep(gamePause);
                    break;
                }
                else if (playerChoice == 2 && hasPokerChip == true) {
                    std::cout << "You already have the chip, and found nothing else." << "\n";
                    Sleep(gamePause);
                    gameScene = 10;
                    break;
                }
                else if (playerChoice == 2 && hasPokerChip == false) {
                    gameScene = 8;
                    break;
                }
                else if (playerChoice == 3) {
                    gameScene = 9;
                    break;
                }
                else {
                    gameActive = false;
                    break;
                }
                break;

            case 11:
                std::cout << "############################| Fortune Lost |############################" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#          Exhausted and Dehydrated, you fall to your knees...         #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#           You raise your head and look towards the horizon           #" << "\n";
                std::cout << "#     Eyes squinting, you see a dark shape moving from left to right   #" << "\n";
                std::cout << "#   Mind struggling for the word, and with cracked lips, you utter...  #" << "\n";
                std::cout << "#                            '...cars...'                              #" << "\n";
                std::cout << "#                       What do you do next?                           #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "########################################################################" << "\n";
                std::cout << "                         1) Cars   2) Return                            " << "\n";

                std::cin >> playerChoice;

                if (playerChoice == 1) {
                    gameScene = 12;
                    gameScore += 15;
                    break;
                }
                else if (playerChoice == 2) {
                    gameScene = 13;
                    gameScore -= 15;
                    break;
                }
                else {
                    gameActive = false;
                    break;
                }

            case 12:
                std::cout << "############################| Fortune Lost |############################" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#    With a new found energy, you make your way towards the highway    #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#       Suddenly, a shot rings out. A Bullet zips past your ear.       #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                       What do you do next?                           #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "########################################################################" << "\n";
                std::cout << "                          1) Run   2) Duck                              " << "\n";

                std::cin >> playerChoice;

                if (playerChoice == 1) {
                    playerRun = true;
                    endGameCounter += 1;
                    break;
                }
                else if (playerChoice == 2) {
                    playerDuck = true;
                    endGameCounter += 1;
                    break;
                }
                else {
                    gameActive = false;
                    break;
                }

            case 13:
                std::cout << "############################| Fortune Lost |############################" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                               GAME OVER                              #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#              You turn and face a large Native American man           #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#               The scar across his face speaks for itself             #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                  He points his rifle at you and fires                #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "########################################################################" << "\n";
                std::cout << "                          1) Retry   2) Quit                            " << "\n";

                std::cin >> playerChoice;

                if (playerChoice == 1) {
                    gameScene = 11;
                    endGameCounter = 0;
                    gameOverCount += 1;
                    break;
                }
                else {
                    gameActive = false;
                    break;
                }
                break;

            case 14:
                std::cout << "############################| Fortune Lost |############################" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                    The shooter begins to reload                      #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                You run towards the highway faster...                 #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                       What do you do next?                           #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "########################################################################" << "\n";
                std::cout << "                          1) Run   2) Duck                              " << "\n";

                std::cin >> playerChoice;

                if (playerChoice == 1) {
                    playerRun = true;
                    endGameCounter += 1;
                    break;
                }
                else if (playerChoice == 2) {
                    playerDuck = true;
                    endGameCounter += 1;
                    break;
                }
                else {
                    gameActive = false;
                    break;
                }

            case 15:
                std::cout << "############################| Fortune Lost |############################" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#          You hear the rifle cocked and you quickly take cover        #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                       What do you do next?                           #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "########################################################################" << "\n";
                std::cout << "                          1) Run   2) Duck                              " << "\n";

                std::cin >> playerChoice;

                if (playerChoice == 1) {
                    playerRun = true;
                    endGameCounter += 1;
                    break;
                }
                else if (playerChoice == 2) {
                    playerDuck = true;
                    endGameCounter += 1;
                    break;
                }
                else {
                    gameActive = false;
                    break;
                }

            case 16:
                std::cout << "############################| Fortune Lost |############################" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#  You manage to reach the highway as cars zip past quickly. Jumping   #" << "\n";
                std::cout << "#  the barrier, you rush into traffic just as a bullet tears through   #" << "\n";
                std::cout << "#  your shoulder. You fall into the side of a vehicle before nothing   #" << "\n";
                std::cout << "#  but darkness...                                                     #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#  It's later when you awaken at the hospital, that everything comes   #" << "\n";
                std::cout << "#  back. The Casino you were at three days before. The money you won.  #" << "\n";
                std::cout << "#  How angry they were as you left. They drug you out to the desert    #" << "\n";
                std::cout << "#  to die. You remember crashing into the tribal police car, and the   #" << "\n";
                std::cout << "#  multiple gunshots before losing consciousness.                      #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#  You flip whats left of you winnings, the poker chip from the desert #" << "\n";
                std::cout << "#  Thinking to yourself:                                               #" << "\n";
                std::cout << "#                                                                      #" << "\n";
                std::cout << "#                      '...best vacation ever...'                      #" << "\n";
                std::cout << "#                                                                      #" << "\n";                
                std::cout << "########################################################################" << "\n";

                system("pause");
                gameActive = false;
                break;

        } // End of game switch statement

    } // End of main game loop
    std::cout << playerName << ", beat the game with the following stats: " << "\n";
    std::cout << "Game Over's: " << gameOverCount << "\n";
    std::cout << "Score :" << gameScore << "\n";
    return 0;

} // End of main function