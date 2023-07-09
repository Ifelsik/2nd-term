#include <stdio.h>
#include <stdbool.h>

bool is_vowel_letter(char letter){
    char vowels[12] = {'A', 'E', 'I', 'O', 'U', 'Y', 'a', 'e', 'i', 'o', 'u', 'y'};
    for (int i = 0; i < 12; i++)
        if (letter == vowels[i])
            return true;
    return false;
}

bool is_uppercase_letter(char letter) {
    if (letter >= 'A' && letter <= 'Z')
        return true;
    return false;
}

int main() {
    char letter;
    printf("Enter your letter:");
    scanf("%c", &letter);
    if (is_vowel_letter(letter))
        printf("%c is vowel and", letter);
    else
        printf("%c is consonant and", letter);
    if (is_uppercase_letter(letter))
        printf(" uppercase.\n");
    else
        printf(" lowercase.\n");
    return 0;
}
