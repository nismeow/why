#include <stdio.h>

int i;

// Read wordlist and return random word
char *word(char *filename);

// Display Hangman state

// void draw()
// {
//     //draws one each time a guess is incorrect
char *stage[] = {

    "  |=====|\n"
    "        |\n"
    "        |\n"
    "        |\n"
    "       ===\n",

    "  |=====|\n"
    "  O     |\n"
    "        |\n"
    "        |\n"
    "       ===\n",

    "  |=====|\n"
    "  O     |\n"
    "  |     |\n"
    "        |\n"
    "       ===\n",

    "  |=====|\n"
    "  O     |\n"
    "  |-    |\n"
    "        |\n"
    "       ===\n",

    "  |=====|\n"
    "  O     |\n"
    " -|-    |\n"
    "        |\n"
    "       ===\n",

    "  |=====|\n"
    "  O     |\n"
    " -|-    |\n"
    "  /     |\n"
    "       ===\n",

    "   |=====|\n"
    "   O     |\n"
    "  -|-    |\n"
    "  //     |\n"
    "       ===\n"

};