# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c mycrypto.c tests.c # definindo todos os meu arquivos .c
OBJ = main.o mycrypto.o tests.o #definindo os arquivos que irao ser criados .o
EXEC = mycrypto # arquivo .C mais relevante
TEST_EXEC = testcrypto # ARQUIVO TESTE QUE IRA SER CRIADO 

# A regra de compilação é que para tudo ser compilado tem que ser gerado o arquivo mycrypto e testcrypto
all: $(EXEC) $(TEST_EXEC)

$(EXEC): main.o mycrypto.o # o arquivo mycrypto depende de main.o e mycrypto.o
	$(CC) $(CFLAGS) main.o mycrypto.o -o $(EXEC) 

$(TEST_EXEC): tests.o mycrypto.o
	$(CC) $(CFLAGS) tests.o mycrypto.o -o $(TEST_EXEC) 

# Regras para compilar os arquivos .o
main.o: main.c # main.o depende de main.c e abaixo compila main.c em main.o como objetos
	$(CC) $(CFLAGS) -c main.c -o main.o 

mycrypto.o: mycrypto.c mycrypto.h
	$(CC) $(CFLAGS) -c mycrypto.c -o mycrypto.o

tests.o: tests.c mycrypto.h
	$(CC) $(CFLAGS) -c tests.c -o tests.o

# Limpeza dos arquivos .o e executáveis
clean:
	rm -f *.o $(EXEC) $(TEST_EXEC)

# Regra para rodar os testes
test: $(TEST_EXEC)
	./$(TEST_EXEC)
	