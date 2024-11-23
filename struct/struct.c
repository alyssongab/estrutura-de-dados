/*

    - Considere que um aluno possui um livro favorito, que, por simplificação, possui um título, número de páginas e preço.

        - Codifique a struct de livro e adapte a struct de aluno

    - Crie as funções de criação (C), Delete (D) e de Impressão para a Struct Aluno e Livro

    - Na função de Delete, garanta que o ponteiro é atribuído como NULL depois da desalocação

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Livro
typedef struct {
    char titulo[100];
    unsigned int paginas;
    float preco;
} Livro;

// Aluno
typedef struct {
    char nome[100];
    unsigned int idade;
    Livro *livro_fav;
} Aluno;


/*
******************* LIVRO ******************
*/

// "Construtor" para livros
Livro *criarLivro(const char *titulo, unsigned int pags, 
                    float preco){
    Livro *livro = (Livro*) calloc(1, sizeof(Livro));

    strcpy(livro->titulo, titulo);
    livro->paginas = pags;
    livro->preco = preco;

    return livro;
}

// Imprimir na tela o livro
void *imprimirLivro(const Livro *livro) {
    printf("\t-Título: %s\n", livro->titulo);
    printf("\t-Número de páginas: %d\n", livro->paginas);
    printf("\t-Preço: R$ %.2f\n", livro->preco);
    puts("+----------------------------------+");
}


void destruirLivro(Livro **livro_ref) {
    printf("Desalocando livro...\n");
    Livro *livro = *livro_ref;
    free(livro);
    *livro_ref = NULL;
}

// Fazer a cópia do livro para armazenar na struct Aluno
Livro *copiarLivro(const Livro *livro) {
    return criarLivro(livro->titulo, livro->paginas, livro->preco); 
}

/*
***************** ALUNO ****************
*/

// Criar aluno. "construtor"
Aluno *criarAluno(const char *nome, int idade, const Livro *livro_fav){
    Aluno *aluno = (Aluno*) calloc(1, sizeof(Aluno));

    if(aluno != NULL) {
        strcpy(aluno->nome, nome);
        aluno->idade = idade;
        // aluno->livro_fav = livro; MANEIRA PERIGOSA.
        aluno->livro_fav = copiarLivro(livro_fav);

        return aluno;
    }
    else{
        printf("Erro na criação!\n");
        exit(1);
    }

}

// Imprimir aluno
void *imprimirAluno(const Aluno *aluno) {
    puts("+----------------------------------+");
    printf("\tNome: %s\n", aluno->nome);
    printf("\tIdade: %i\n", aluno->idade);
    puts("\tLivro Favorito:");
    imprimirLivro(aluno->livro_fav);
}

// Desalocar aluno
void destruirAluno(Aluno **aluno_ref){
    printf("Desalocando aluno...\n");
    Aluno *aluno = *aluno_ref;
    // Primeiro destruir o livro que está sendo apontado por aluno
    destruirLivro(&aluno->livro_fav);
    printf("(Copia do livro que foi desalocado)\n");
    // Agora desalocar o aluno.
    free(aluno);
    *aluno_ref = NULL;
}

int main() {

    // system("clear");

    Livro *livro_harry = criarLivro("Harry Potter", 200, 60);

    imprimirLivro(livro_harry);
    puts("");

    Aluno *gabriel = criarAluno("Gabriel", 21, livro_harry);
    imprimirAluno(gabriel);

    destruirLivro(&livro_harry);
    printf("livro_harry == NULL? %d\n", livro_harry == NULL);

    imprimirAluno(gabriel);

    destruirAluno(&gabriel);
    printf("gabriel == NULL ? ");
    if(gabriel == NULL) {
        printf("sim");
    }
    else{
        printf("não");
    }

    printf("\n\n<Pressione qualquer tecla para continuar>");
    getchar();

    return 0;
}