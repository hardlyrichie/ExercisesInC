/*
* Program to count cards
* SoftSys 2020
* Richard Gao
*/

#include <stdio.h>
#include <stdlib.h>

int cardValue(char card_name[]);
int updateValue(int card);

int main()
{
    char card_name[3];
    int count = 0;
    int val;
    do {
        puts("Enter the card_name: ");
        scanf("%2s", card_name);

        val = cardValue(card_name);
        if (val == -1) {
            break;
        }
        count += updateValue(val);

        printf("Current count: %i\n", count);
    } while (1);
    return 0;
}

/* Given a card determine it's numerical value
   
   card_name: character array of the card's name
*/
int cardValue(char card_name[])
{
    int val;
    switch(card_name[0]) {
        case 'K':
        case 'Q':
        case 'J':
            val = 10;
            break;
        case 'A':
            val = 11;
            break;
        case 'X':
            val = -1;
            break;
        default:
            val = atoi(card_name);
            if ((val < 1) || (val > 10)) {
                puts("I don't understand that value!");
            }
    }
    return val;
}

/* Determine the update value to add to count depending on card value
   
   card: int value of the current card
*/
int updateValue(int card)
{
    if ((card > 2) && (card < 7)) {
        return 1;
    } else if (card == 10) {
        return -1;
    }
    return 0;
}