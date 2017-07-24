#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    // a card's value and suit are retrieved as follows:
    // num % 13  = retrieves a value
    // num / 13  = retrieves a suit
    string values[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };
    string suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    
    char separator[2]; // used to leave a blank line between each case's output
    separator[0] = separator[1] = '\0'; // first it leaves no line
    
    int T; // number of tasks left to do
        
    scanf("%d", &T);
    
    while(T--) // a trick used instead of for-loop, will repeat exactly T times
    {
        printf("%s", separator); // separate cases in the output
        separator[0] = '\n';
        
        int numShufflesKnown;
        scanf("%d", &numShufflesKnown);
        
        int shuffles[101][52]; // shuffles known to a dealer
        for (int i = 0; i < numShufflesKnown; ++i) // read i-th shufffle
            for (int j = 0; j < 52; ++j)
            {
                scanf("%d", &shuffles[i][j]); // move the j-th to position shuffle[i][j]
                --shuffles[i][j];
            }
        
        cin.ignore(); // we use it get to the new line of the input
        int numShufflesDone = 0;
        int orderOfShuffles[101]; // TODO: document this variable
        
        string temp;
        while ((getline(cin, temp)) && (temp != ""))
            orderOfShuffles[numShufflesDone++] = atoi(temp.c_str()) - 1;
            
        for (int i = 0; i < 52; ++i)
        {
            int pos = i;
            for (int c = numShufflesDone - 1; c >= 0; --c)
                pos = shuffles[orderOfShuffles[c]][pos];
            
            printf("%s of %s\n", values[pos % 13].c_str(), suits[pos / 13].c_str());
        }
    }
    
    return 0;
}
