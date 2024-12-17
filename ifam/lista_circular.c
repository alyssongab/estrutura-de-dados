// Lista circular simplesmente encadeada

#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó
typedef struct Node {
    int playerId;           // ID do jogador
    struct Node *next;      // Ponteiro para o próximo nó
} NODE;

// Funções para manipular a lista circular
NODE *criarNo(int playerId);
NODE *adicionarJogador(NODE *head, int playerId);
NODE *removerJogador(NODE *head, int playerId);
void exibirJogadores(NODE *head);
void simularJogo(NODE *head, int rodadas);

int main() {
    NODE *head = NULL;

    // Adicionando jogadores
    head = adicionarJogador(head, 1);
    head = adicionarJogador(head, 2);
    head = adicionarJogador(head, 3);
    head = adicionarJogador(head, 4);

    printf("Jogadores na lista:\n");
    exibirJogadores(head);

    printf("\nSimulando jogo por 6 rodadas...\n");
    simularJogo(head, 6);

    printf("\nRemovendo jogador 3...\n");
    head = removerJogador(head, 3);
    exibirJogadores(head);

    printf("\nSimulando jogo por 4 rodadas...\n");
    simularJogo(head, 4);

    return 0;
}

// Cria um novo nó
NODE *criarNo(int playerId) {
    NODE *novoNo = (NODE *)malloc(sizeof(NODE));
    if (novoNo == NULL) {
        printf("Erro: Memória insuficiente.\n");
        exit(EXIT_FAILURE);
    }
    novoNo->playerId = playerId;
    novoNo->next = novoNo; // Aponta para si mesmo (único nó)
    return novoNo;
}

// Adiciona um jogador à lista circular
NODE *adicionarJogador(NODE *head, int playerId) {
    NODE *novoNo = criarNo(playerId);

    if (head == NULL) {
        return novoNo; // Primeiro jogador na lista
    }

    // Encontrar o último nó
    NODE *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    // Inserir o novo nó no final e fazer a conexão circular
    temp->next = novoNo;
    novoNo->next = head;
    return head;
}

// Remove um jogador da lista circular
NODE *removerJogador(NODE *head, int playerId) {
    if (head == NULL) {
        printf("Erro: Lista vazia.\n");
        return NULL;
    }

    NODE *temp = head;
    NODE *prev = NULL;

    // Caso especial: único jogador na lista
    if (temp->playerId == playerId && temp->next == head) {
        free(temp);
        return NULL;
    }

    // Encontrar o nó a ser removido
    do {
        if (temp->playerId == playerId) {
            if (prev == NULL) { // Remoção do primeiro nó
                NODE *last = head;
                while (last->next != head) {
                    last = last->next;
                }
                head = head->next;
                last->next = head;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            return head;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);

    printf("Jogador %d não encontrado.\n", playerId);
    return head;
}

// Exibe os jogadores na lista
void exibirJogadores(NODE *head) {
    if (head == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    NODE *temp = head;
    do {
        printf("Jogador %d -> ", temp->playerId);
        temp = temp->next;
    } while (temp != head);
    printf("(volta ao início)\n");
}

// Simula o jogo, mostrando os jogadores em sequência
void simularJogo(NODE *head, int rodadas) {
    if (head == NULL) {
        printf("Erro: Lista vazia, não é possível simular.\n");
        return;
    }

    NODE *current = head;
    for (int i = 1; i <= rodadas; i++) {
        printf("Rodada %d: Jogador %d\n", i, current->playerId);
        current = current->next;
    }
}