/*
 * Code for running the Monte Carlo simulation and find out the probabilities of 7-card poker hands.
 * References for comaparing values :  https://en.wikipedia.org/wiki/Poker_probability#Frequency_of_7-card_poker_hands
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define DECK_SIZE 52
#define HAND_SIZE 7

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

typedef unsigned long long ll;
typedef struct card card;
typedef struct odds odds;

struct card
{
    int value; // * 1 -ACE | 11 - JACK | 12 - QUEEN | 13 - KING
    char suit; // * S - Spades | H - Hearts | C - Clubs | D - Diamonds
};

struct odds
{   
    /*
    * ROYAL FLUSH : n_all[0] 
    * STRAIGHT FLUSH : n_all[1] 
    * 4 OF A KIND : n_all[2] 
    * FULL HOUSE : n_all[3] 
    * FLUSH : n_all[4]
    * STRAIGHT : n_all[5]
    * 3 OF A KIND : n_all[6]
    * TWO PAIRS : n_all[7]
    * ONE PAIR : n_all[8]
    * HIGH CARD/ NO MATCH : n_all[9]
    */
    ll n_all[10]; 
};
//* FUNCTION PROTOTYPES
void deck_init(card *deck);
void shuffle_deck(card *deck);
void print_deck(card *deck);
card *make_hand( card *deck);
void print_hand(card *hand);
void sort_hand(card *hand,int hand_size);
void swap_cards(card *a,card *b);
void draw5(card *hand_7, card *draw_5 , odds *total);
int drawisstraight(card *draw);
int drawisflush(card *draw);
int drawhaspairs(card *draw);
int drawisfourkind(card *draw);
int drawisthreekind(card *draw);


int main(){
    card *deck;
    deck = malloc(sizeof(card)*DECK_SIZE);
    odds *total_odds;
    total_odds = malloc(sizeof(odds));
    for (int i = 0; i < 10; i++)
    {
        total_odds->n_all[i] = 0;
    }
    deck_init(deck); //* INITIALIZING ALL CARDS IN THE DECK IN ORDER.

    ll draws;
    printf("Enter number of draws : ");
    scanf("%lld",&draws);
    srand(time(0)); //* SEEDING THE RANDOM NUMBER GENERATOR
    for (ll i = 0; i < draws; i++)
    {
        shuffle_deck(deck);//*SHUFFLING THE DECK
        card *hand_7;
        hand_7 = make_hand(deck);//*MAKING A HAND OF 7 CARDS FROM DECK
        card *draw_5;
        draw_5 = malloc(sizeof(card) * 5);
        draw5(hand_7,draw_5,total_odds);//* ALL 5 CARD COMBOS ARE CHECKED AGAINST DIFFERENT HANDS.
    }

    printf("Probability of royal flushes:%llf%\n", (total_odds->n_all[0] / (draws / 100.0)));
    printf("Probability of straight flushes:%llf%\n", (total_odds->n_all[1] / (draws / 100.0)));
    printf("Probability of four of a kind:%llf%\n", (total_odds->n_all[2] / (draws / 100.0)));
    printf("Probability of full houses:%llf%\n", (total_odds->n_all[3] / (draws / 100.0)));
    printf("Probability of flushes:%llf%\n", (total_odds->n_all[4] / (draws / 100.0)));
    printf("Probability of straights:%llf%\n", (total_odds->n_all[5] / (draws / 100.0)));
    printf("Probability of three of a kind:%llf%\n", (total_odds->n_all[6] / (draws / 100.0)));
    printf("Probability of double pairs:%llf%\n", (total_odds->n_all[7] / (draws / 100.0)));
    printf("Probability of single pairs:%llf%\n", (total_odds->n_all[8] / (draws / 100.0)));
    printf("Probability of high cards:%llf%\n", (total_odds->n_all[9] / (draws / 100.0)));
    return 0;
}
void deck_init(card *deck){
    for (int i = 0; i < DECK_SIZE; i++)
    {
        if(i <= 12)
            deck[i].suit = 'S';
        else if (i <= 25)
            deck[i].suit = 'H';
        else if (i <= 38)
            deck[i].suit = 'C';
        else if (i <= 51)
            deck[i].suit = 'D';

        deck[i].value = i % 13 + 1;
    } 
}
void shuffle_deck(card *deck){
    card temp;
    for (int i = 0; i < DECK_SIZE;i++)
    {
        int rand_num = rand() % (52 -i);
        swap_cards(&deck[i],&deck[rand_num+i]); 
    }
}
void print_deck(card *deck){
    printf("\n<------------------->\n");
    for (int i = 0; i < DECK_SIZE; i++)
    {
        if((deck+i)->suit == 'S')
            printf("%d of Spades\n",(deck+i)->value);
        else if((deck+i)->suit == 'H')
            printf("%d of Hearts\n",(deck+i)->value);
        else if((deck+i)->suit == 'C')
            printf("%d of Clubs\n",(deck+i)->value);
        else if((deck+i)->suit == 'D')
            printf("%d of Diamonds\n",(deck+i)->value);
    }
    printf("\n<------------------->\n");
    
}
card *make_hand( card *deck){
    card *temp_hand;
    temp_hand = malloc(sizeof(card)*HAND_SIZE);
    for (int i = 0; i < HAND_SIZE;i++)
    {
        temp_hand[i] = deck[i];   
    }
    return temp_hand;
}
void print_hand(card *hand){
    printf("\n<------------------->\n");
    for (int i = 0; i < HAND_SIZE; i++)
    {
        if((hand+i)->suit == 'S')
            printf("%d of Spades\n",(hand+i)->value);
        else if((hand+i)->suit == 'H')
            printf("%d of Hearts\n",(hand+i)->value);
        else if((hand+i)->suit == 'C')
            printf("%d of Clubs\n",(hand+i)->value);
        else if((hand+i)->suit == 'D')
            printf("%d of Diamonds\n",(hand+i)->value);
    }
    printf("\n<------------------->\n");
}
void sort_hand(card *hand,int hand_size){
    for (int i = 0; i < hand_size-1; i++)
    {
        for (int j = i+1; j < hand_size; j++)
        {
            if(hand[i].value > hand[j].value)
                swap_cards(&hand[i],&hand[j]);
        }
        
    }
    
}
void swap_cards(card *a,card *b){
    card temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void draw5(card *hand_7, card *draw_5 , odds *total){
    
    ll rf = 0, sf = 0, s = 0, f = 0, foak = 0, fh = 0, toak = 0, tp = 0, op = 0, hc = 0;
    for (int a = 0; a < 6; a++)
    {
        for (int b = a + 1; b < 7; b++)
        {
            //* Cards at a and b not considered.(5 out of 7)
            int j = 0;
            for (int i = 0; i < 7; i++)
            {
                if (i != a && i != b)
                {
                    draw_5[j] = hand_7[i];
                    j++;
                }
            }

            sort_hand(draw_5, 5);
            if (drawisstraight(draw_5) == 1 && drawisflush(draw_5) == 1 && draw_5[0].value == 1 && draw_5[1].value != 2) //3rd and 4th condition check whether 1st card is Ace and 2nd card is not 2(as sorted ascending).
                rf++; //*Royal Flush Flag
            else if (drawisstraight(draw_5) == 1 && drawisflush(draw_5) == 1)
                sf++; //*Straight Flush Flag
            else if (drawisfourkind(draw_5) == 1)
                foak++; //*Four Of A Kind Flag
            else if (drawisthreekind(draw_5) == 2)
                fh++; //*Full House Flag
            else if (drawisflush(draw_5) == 1)
                f++; //*Flush Flag
            else if (drawisstraight(draw_5) == 1)
                s++; //*Straight Flag
            else if (drawisthreekind(draw_5) == 1)
                toak++; //*Three Of A Kind Flag
            else if (drawhaspairs(draw_5) == 2)
                tp++; //*Two Pairs Flag
            else if (drawhaspairs(draw_5) == 1)
                op++; //*One Pair Flag
            else
                hc++; //*High Card Flag

        }
    }
    if (rf > 0)
        (total->n_all[0])++;
    else if (sf > 0)
        (total->n_all[1])++;
    else if (foak > 0)
        (total->n_all[2])++;
    else if (fh > 0)
        (total->n_all[3])++;
    else if (f > 0)
        (total->n_all[4])++;
    else if (s > 0)
        (total->n_all[5])++;
    else if (toak > 0)
        (total->n_all[6])++;
    else if (tp > 0)
        (total->n_all[7])++;
    else if (op > 0)
        (total->n_all[8])++;
    else if (hc > 0)
        (total->n_all[9])++;
}
int drawisstraight(card *draw){
    //* STRAIGHT , ACE HIGH
    if (draw[0].value == 1 && draw[1].value == 10 && draw[2].value == 11 && draw[3].value == 12 && draw[4].value == 13)
        return (TRUE);

    //* OTHER STRAIGHT
    if (draw[0].value != draw[1].value - 1)
        return (FALSE);
    if (draw[1].value != draw[2].value - 1)
        return (FALSE);
    if (draw[2].value != draw[3].value - 1)
        return (FALSE);
    if (draw[3].value != draw[4].value - 1)
        return (FALSE);

    return (TRUE);
}
int drawisflush(card *draw){
    char suit;

    //* OBTAIN FIRST CARD'S SUIT
    suit = draw[0].suit;
    //* COMPARE WITH ALL OTHER CARDS
    for (int x = 1; x < 5; x++)
    {
        if (suit != draw[x].suit)
            return (FALSE);
    }

    return (TRUE);
}
int drawhaspairs(card *draw){
    //* TEST THE FIRST TWO CARDS
    if (draw[0].value == draw[1].value)
    {
        //* CHECK FOR A SECOND PAIR
        if (draw[2].value == draw[3].value || draw[3].value == draw[4].value)
            return (2);
        else
            return (TRUE);
    }

    //* TEST THE SECOND TWO CARDS
    if (draw[1].value == draw[2].value)
    {
        //* CHECK FOR A SECOND PAIR
        if (draw[3].value == draw[4].value)
            return (2);
        else
            return (TRUE);
    }

    //* TEST FOR PAIR AT 3RD POSITION 
    if (draw[2].value == draw[3].value)
        return (TRUE);

    //* TEST FOR PAIR AT FINAL POSITION 
    if (draw[3].value == draw[4].value)
        return (TRUE);

    return (FALSE);
}
int drawisfourkind(card *draw){
    //* TEST THE FIRST FOUR CARDS
    if (draw[0].value == draw[1].value && draw[1].value == draw[2].value && draw[2].value == draw[3].value)
        return (TRUE);
    //* TEST THE LAST FOUR CARDS
    if (draw[1].value == draw[2].value && draw[2].value == draw[3].value && draw[3].value == draw[4].value)
        return (TRUE);

    return (FALSE);
}
int drawisthreekind(card *draw){
    //* TEST THE FIRST THREE CARDS 
    if (draw[0].value == draw[1].value && draw[1].value == draw[2].value)
    {
        //* ALSO TEST FOR FULL HOUSE
        if (draw[3].value == draw[4].value)
            return (2);
        else
            return (1);
    }

    //* TEST THE NEXT THREE CARDS 
    if (draw[1].value == draw[2].value && draw[2].value == draw[3].value)
        return (TRUE);

    //* TEST THE LAST THREE CARDS
    if (draw[2].value == draw[3].value && draw[3].value == draw[4].value)
    {
        //* ALSO TEST FOR FULL HOUSE
        if (draw[0].value == draw[1].value)
            return (2);
        else
            return (1);
    }

    return (FALSE);
}