/* Determine which of two Scrabble words is worth more.

$ ./scrabble
Player 1: COMPUTER
Player 2: science
Player 1 wins!
Getting Started

Started CS50x in 2021 or prior and need to migrate your work from CS50 IDE to the new VS Code codespace? Be sure to check out our instructions on how to migrate your files!
Open VS Code.

Start by clicking inside your terminal window, then execute cd by itself. You should find that its “prompt” resembles the below.

$
Click inside of that terminal window and then execute

wget https://cdn.cs50.net/2021/fall/labs/2/scrabble.zip
followed by Enter in order to download a ZIP called scrabble.zip in your codespace. Take care not to overlook the space between wget and the following URL, or any other character for that matter!

Now execute

unzip scrabble.zip
to create a folder called scrabble. You no longer need the ZIP file, so you can execute

rm scrabble.zip
and respond with “y” followed by Enter at the prompt to remove the ZIP file you downloaded.

Now type

cd scrabble
followed by Enter to move yourself into (i.e., open) that directory. Your prompt should now resemble the below.

scrabble/ $
If all was successful, you should execute

ls
and you should see a file called scrabble.c. Open that file by executing the below:

code scrabble.c
If you run into any trouble, follow these same steps steps again and see if you can determine where you went wrong!

Background

In the game of Scrabble, players create words to score points, and the number of points is the sum of the point values of each letter in the word.

A
B
C
D
E
F
G
H
I
J
K
L
M
N
O
P
Q
R
S
T
U
V
W
X
Y
Z
1	3	3	2	1	4	2	4	1	8	5	1	3	1	1	3	10	1	1	1	1	4	4	8	4	10
For example, if we wanted to score the word Code, we would note that in general Scrabble rules, the C is worth 3 points, the o is worth 1 point, the d is worth 2 points, and the e is worth 1 point. Summing these, we get that Code is worth 3 + 1 + 2 + 1 = 7 points.

Implementation Details

Complete the implementation of scrabble.c, such that it determines the winner of a short scrabble-like game, where two players each enter their word, and the higher scoring player wins.

Notice that we’ve stored the point values of each letter of the alphabet in an integer array named POINTS.
For example, A or a is worth 1 point (represented by POINTS[0]), B or b is worth 3 points (represented by POINTS[1]), etc.
Notice that we’ve created a prototype for a helper function called compute_score() that takes a string as input and returns an int. Whenever we would like to assign point values to a particular word, we can call this function. Note that this prototype is required for C to know that compute_score() exists later in the program.
In main(), the program prompts the two players for their words using the get_string() function. These values are stored inside variables named word1 and word2.
In compute_score(), your program should compute, using the POINTS array, and return the score for the string argument. Characters that are not letters should be given zero points, and uppercase and lowercase letters should be given the same point values.
For example, ! is worth 0 points while A and a are both worth 1 point.
Though Scrabble rules normally require that a word be in the dictionary, no need to check for that in this problem!
In main(), your program should print, depending on the players’ scores, Player 1 wins!, Player 2 wins!, or Tie!.*/


// NOTE: I left some code commented out because I had originally initialized variables that I didn't need and it was breaking my code!
// I also left some print statements commented out that I used to debug my original code. :P

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int value = 0;
    int index;
    // char c;

    for (int i = 0; i < strlen(word); i++)
    {
        if (isalpha(word[i]))
        {
            // c = toupper(word[i]);
            index = toupper(word[i]) - 65;
            // printf("%i\n", index);
            value = value + (POINTS[index]);
            // printf("%i\n", value);
        }
    }
    return value;
}

// CORRECT
