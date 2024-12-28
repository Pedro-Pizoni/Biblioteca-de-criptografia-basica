#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include "mycrypto.h"

// Função para testar a cifra de César
void test_caesar() {
    char encrypted[100];
    char decrypted[100];

    caesar_encrypt(encrypted, "upf", 10);
    assert(strcmp(encrypted, "ezp") == 0); 

    // Teste da descriptografia da cifra de César
    caesar_decrypt(decrypted, encrypted, 10);
    assert(strcmp(decrypted, "upf") == 0); 
}

// Função para testar o XOR
void test_xor() {
    char encrypted[100];
    char decrypted[100];
    const char *key = "mykey";

    // Teste do XOR
    xor_encrypt(encrypted, "Pedro", key);
    xor_decrypt(decrypted, encrypted, key);
    assert(strcmp(decrypted, "Pedro") == 0); 
}

// Função para testar a cifra de Atbash
void test_atbash() {
    char encrypted[100];
    char decrypted[100];

    // Teste da cifra de Atbash
    atbash_encrypt(encrypted, "brusso");
    assert(strcmp(encrypted, "yifhhl") == 0); 

    // Teste da descriptografia da cifra de Atbash
    atbash_decrypt(decrypted, encrypted);
    assert(strcmp(decrypted, "brusso") == 0); 
}

// Função principal para executar todos os testes
int main() {
    // Testes de todas as funções
    test_caesar();
    test_xor();
    test_atbash();

    printf("Todos os testes passaram amem jesus :)\n");
    return 0;
}

