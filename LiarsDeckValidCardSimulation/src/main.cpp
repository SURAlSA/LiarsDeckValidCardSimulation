#include "util.h"

int main(int argc, char* argv[]) 
{

    if (argc != 2) 
    {
        cerr << "Usage: " << argv[0] << " n" << endl;
        return 1;
    }

    int n = atoi(argv[1]);
    const int deckSize = 20;
    const int totalValidCards = 8;
    const int sizeOfHand = 5;
    const int Deviser = n / 10;
    int DeviserPercent = 0;

    srand(time(0)); // Seed the random number generator

    int results[sizeOfHand + 1] = {0}; // Initialize results array to store outcomes

    for (int i = 0; i < n; i++) 
    {
        bool simulatedDeck[deckSize] = {false}; // Reset deck: all cards initially invalid
        int validCardsPlaced = 0;

        // Randomly place 8 valid cards in the deck
        while (validCardsPlaced < totalValidCards) 
        {
            int position = getRandomInt(0, deckSize - 1);

            if (!simulatedDeck[position]) 
            { // Only place if position is currently invalid
                simulatedDeck[position] = true; // Mark card as valid
                validCardsPlaced++;
            }
        }

        // Randomly draw 5 unique cards and count the number of valid cards in the hand
        int validCardsInHand = 0;
        unordered_set<int> drawnCards; // To track drawn card positions

        for (int j = 0; j < sizeOfHand; j++) 
        {
            int drawPosition;
            do 
            {
                drawPosition = getRandomInt(0, deckSize - 1);
            } 
            while (drawnCards.count(drawPosition)); // Ensure unique draw

            drawnCards.insert(drawPosition); // Mark this card as drawn

            if (simulatedDeck[drawPosition]) 
            {
                validCardsInHand++;
            }
        }

        results[validCardsInHand]++; // Increment result count for the number of valid cards drawn

        if (i % Deviser == 0)
        {
            cout << DeviserPercent * 10 << "%" << endl;
            DeviserPercent++;
        }
    }
    cout << "100%" << endl;

    // Display the results of the simulation
    for (int j = 0; j <= sizeOfHand; j++) 
    {
        cout << j << " Valid Cards: " << results[j] << endl;
    }

    return 0;
}
