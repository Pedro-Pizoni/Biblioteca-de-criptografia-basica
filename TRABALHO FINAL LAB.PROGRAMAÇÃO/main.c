#include <stdio.h>
#include "mycrypto.h"

int main() {
    char original[] = "Pedro, Pizoni!";
    char encrypted[50];
    char decrypted[50];
    int shift = 3;
    char key[] = "Pedro"; // Chave alterada para "Pedro"

    // Teste de Cifra de César
    caesar_encrypt(encrypted, original, shift);
    printf("Caesar Encrypted: %s\n", encrypted);
    caesar_decrypt(decrypted, encrypted, shift);
    printf("Caesar Decrypted: %s\n", decrypted);

    // Teste de Cifra XOR
    xor_encrypt(encrypted, original, key);
    printf("XOR Encrypted: %s\n", encrypted);
    xor_decrypt(decrypted, encrypted, key);
    printf("XOR Decrypted: %s\n", decrypted);

    // Teste de Cifra de Atbash
    atbash_encrypt(encrypted, original);
    printf("Atbash Encrypted: %s\n", encrypted);
    atbash_decrypt(decrypted, encrypted);
    printf("Atbash Decrypted: %s\n", decrypted);

    return 0;
}
