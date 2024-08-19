#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#define AVILABLE_WRONG_GUESSES 6

#ifndef RANDOM_HIDDEN_WORD
#define HIDDEN_WORD "hello"
#define STR_LEN(str) (sizeof(str)-1)
#endif

void print_word(const char *hidden_word, bool *guessed_pos);
void print_wrong_guesses(char *wrong_guesses, uint8_t num_of_wrong_gusses);

int main() {
#ifndef RANDOM_HIDDEN_WORD
    const char *hidden_word = HIDDEN_WORD;
    char wrong_guesses[AVILABLE_WRONG_GUESSES] = {};
    uint8_t num_of_wrong_gusses = 0;
    bool guessed_pos[STR_LEN(HIDDEN_WORD)] = {};
    uint8_t num_of_guessed_symbols = 0;
    while (num_of_wrong_gusses < AVILABLE_WRONG_GUESSES
            && num_of_guessed_symbols < STR_LEN(HIDDEN_WORD)) {
        printf("The word: ");
        print_word(hidden_word, guessed_pos);
        printf("\tWrong guesses: ");
        print_wrong_guesses(wrong_guesses, num_of_wrong_gusses);
        putchar('\n');
        printf("Enter you next letter:\n");
        char entered_symbol = (char)getchar();
        if (isspace(entered_symbol))
            continue;
        while (getchar() != '\n') ;
        bool letter_guessed = false;
        for (uint8_t pos=0; pos < STR_LEN(HIDDEN_WORD); ++pos)
            if (entered_symbol == hidden_word[pos]) {
                guessed_pos[pos] = true;
                letter_guessed = true;
                ++num_of_guessed_symbols;
            }
        if (!letter_guessed)
            wrong_guesses[num_of_wrong_gusses++] = entered_symbol;
    }
    printf("You %s! The word was: %s\n", num_of_wrong_gusses == AVILABLE_WRONG_GUESSES ? "lost" : "win", hidden_word);
#endif // RANDOM_HIDDEN_WORD
    return EXIT_SUCCESS;
}

void print_word(const char *hidden_word, bool *guessed_pos) {
#ifndef RANDOM_HIDDEN_WORD
    for (uint8_t pos=0; pos < STR_LEN(HIDDEN_WORD); ++pos)
        putchar(guessed_pos[pos] ? hidden_word[pos] : '_');
#endif
}

void print_wrong_guesses(char *wrong_guesses, uint8_t num_of_wrong_gusses) {
#ifndef RANDOM_HIDDEN_WORD
    for (uint8_t count=0; count < AVILABLE_WRONG_GUESSES; ++count)
        if (count < AVILABLE_WRONG_GUESSES-num_of_wrong_gusses)
            putchar('+');
        else
            putchar(wrong_guesses[count-(AVILABLE_WRONG_GUESSES-num_of_wrong_gusses)]);
#endif
}
