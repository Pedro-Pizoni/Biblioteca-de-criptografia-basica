#include "mycrypto.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h> // vou utilizar ela para situações como islower, isupper ou isalpha

void caesar_encrypt(char *dest, const char *src, int shift)
{
    int i;
    for (i = 0; src[i] != '\0'; i++) {
        if (isalpha(src[i])) {  // Se o caractere for uma letra
            if (isupper(src[i])) {
                // Desloca letras maiúsculas
                dest[i] = (char)((((src[i] - 'A') + shift) % 26) + 'A');
            } else {
                // Desloca letras minúsculas
                dest[i] = (char)((((src[i] - 'a') + shift) % 26) + 'a');
            }
        } else {
            // Se não for uma letra, apenas copia o caractere
            dest[i] = src[i];
        }
    }
    dest[i] = '\0'; // Adiciona o terminador de string
}

void caesar_decrypt(char *dest, const char *src, int shift)
{
    int i;
    for (i = 0; src[i] != '\0'; i++) {
        if (isalpha(src[i])) {  // Se o caractere for uma letra
            if (isupper(src[i])) {
                // Desfaz o deslocamento das letras maiúsculas
                dest[i] = (char)((((src[i] - 'A') - shift + 26) % 26) + 'A');
            } else {
                // Desfaz o deslocamento das letras minúsculas
                dest[i] = (char)((((src[i] - 'a') - shift + 26) % 26) + 'a');
            }
        } else {
            // Se não for uma letra, apenas copia o caractere
            dest[i] = src[i];
        }
    }
    dest[i] = '\0'; // Adiciona o terminador de string
}

void xor_encrypt(char *dest, const char *src, const char *key)
{
    size_t src_len = strlen(src);
    size_t key_len = strlen(key);

    for (size_t i = 0; i < src_len; i++)
    {
        dest[i] = src[i] ^ key[i % key_len]; // XOR entre caractere da string e da chave
    }
    dest[src_len] = '\0'; // Garantir que a string resultante é terminada por nulo
}

void xor_decrypt(char *dest, const char *src, const char *key)
{
    // A decriptação é idêntica à encriptação com XOR
    xor_encrypt(dest, src, key);
}

// Funções da Cifra de Atbash
void atbash_encrypt(char *dest, const char *src)
{
    int i = 0; // contador
    while (src[i] != '\0')
    { // roda o while ate que seja "digitado" o '\0' null terminator (mostrarei ele mais pra frente)
        char c = src[i];

        if (isalpha(c))
        { // aqui fazemos a verificação se é uma letra do alfabeto
            if (isupper(c))
            {
                dest[i] = 'Z' - (c - 'A');
            } // conversão da letra maiúscula

            else if (islower(c))
            {
                dest[i] = 'z' - (c - 'a');
            } // conversão da letra minúscula
            // é necessário fazer dois processos separados para caracteres maiúsculos e minúsculos, pois suas posições na tabela ASCII são diferentes
        }
        else
        {
            dest[i] = c; // se não for uma letra, copia para o destino
        }

        i++; // avança o código para o próximo caractere
    }
    dest[i] = '\0'; // acaba a string \\ o caractere '\0' se chama null terminator e indica o fim de uma string em C
}

void atbash_decrypt(char *dest, const char *src)
{
    atbash_encrypt(dest, src); // Reutiliza a função de criptografia
}
