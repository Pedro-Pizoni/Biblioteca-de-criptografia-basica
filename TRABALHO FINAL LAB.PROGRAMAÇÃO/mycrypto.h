// mycrypto.h
#ifndef MYCRYPTO_H
#define MYCRYPTO_H

void caesar_encrypt(char *output, const char *input, int shift);
void caesar_decrypt(char *output, const char *input, int shift); //  chama a cifra como a linha de cima, mas utiliza o shift ao contrario ( para resolver)
void xor_encrypt(char *output, const char *input, const char *key);
void xor_decrypt(char *output, const char *input, const char *key);
void atbash_encrypt(char *output, const char *input);
void atbash_decrypt(char *output, const char *input);

#endif // MYCRYPTO_H
