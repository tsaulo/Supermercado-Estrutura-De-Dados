#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// declaração das funções
void cadastrarProduto();
void menu();
void listarProdutos();
int temNoCarrinho(int codigo);
void comprarProduto();
void visualizarCarrinho();
void fecharPedido();
void infoCarrinho(int i);
void infoProduto(int i);
void mudarInformacoes();
void removerProduto(int cod);
void esperar ();

// struct para os produtos
typedef struct {
    int codigo;          // codigo do produto
    char nome[30];      // nome do produto
    float preco;        // preço do produto
} Produto; 

// struct para o carrinho
typedef struct {
    Produto produto;    // produto
    int quantidade;     // quantidade do produto
} Carrinho; 

Produto produtos[50];  // array de produtos
Carrinho carrinho[50]; // array dos itens no carrinho

int quantP = 0; // produtos cadastrados
int quantC = 0; // produtos no carrinho

// função principal
int main() {
    menu(); // chama a função menu
    return 0;
}

// função para esperar por uma tecla
void esperar() {
    printf("\nPressione qualquer tecla para voltar ao menu...");
    getchar(); 
    getchar(); 
}

// função do menu principal
void menu() {
    int opcao;
    do {
        system("cls"); // limpa a tela 
        // exibe as opções do menu
        printf("Bem-vindo(a) ao Mercado Saulindo, o que deseja?\n");
        printf("1 - Cadastrar Produto\n");
        printf("2 - Listar Produtos\n");
        printf("3 - Comprar Produto\n");
        printf("4 - Visualizar Carrinho\n");
        printf("5 - Fechar Pedido\n");
        printf("6 - Sair do Sistema\n");
        scanf("%d", &opcao); // lê a opção do usuário
        switch (opcao) {
            case 1:
                cadastrarProduto(); // cadastra um novo produto
                break;
            case 2:
                listarProdutos(); // lista os produtos cadastrados
                break;
            case 3:
                comprarProduto(); // compra de produto
                break;
            case 4:
                visualizarCarrinho(); // exibe o carrinho de compras
                break;
            case 5:
                fecharPedido(); // fecha o pedido do carrinho
                break;
            case 6:
                printf("Saindo do sistema...\n"); // mensagem de saída
                break;
            default:
                printf("Opção inválida!\n"); // opção inválida
                break;
        }
    } while (opcao != 6); // mantém o loop até que a opção seja sair
}

// função para cadastrar um novo produto
void cadastrarProduto() {
    system("cls"); // limpa a tela
    printf("Cadastro de Produtos\n");
    if (quantP < 50) { // verifica se há espaço para produtos
        printf("Digite o codigo do produto: ");
        scanf("%d", &produtos[quantP].codigo); // lê o código 
        printf("Digite o nome do produto: ");
        fflush(stdin); // limpa a entrada
        fgets(produtos[quantP].nome, sizeof(produtos[quantP].nome), stdin); // lê o nome 
        produtos[quantP].nome[strcspn(produtos[quantP].nome, "\n")] = '\0'; // remove a nova linha
        printf("Digite o preco do produto: ");
        scanf("%f", &produtos[quantP].preco); // lê o preço 
        quantP++; // aumenta a quantidade de produtos cadastrados
        printf("\nProduto adicionado!");
    } else {
        printf("Limite de produtos cadastrados atingido!\n");
    }
    esperar(); // espera pela entrada do usuário
}

// função para listar os produtos
void listarProdutos() {
    system("cls"); // limpa a tela
    printf("Produtos cadastrados:\n");
    if (quantP == 0) {
        printf("\nNenhum produto cadastrado!\n"); // caso não haja produtos
    } else {
        for (int i = 0; i < quantP; i++) {
            infoProduto(i); // exibe informações de cada produto
            mudarInformacoes();
        }
    }
    esperar(); // espera pela entrada do usuário
}

// função para exibir as informações de um produto
void infoProduto(int i) {
    printf("---------------------------\n");
    printf("Codigo do produto: %d\n", produtos[i].codigo); // código
    printf("Nome do produto: %s\n", produtos[i].nome); // nome
    printf("Preco do produto: %.2f\n", produtos[i].preco); // preço
    printf("---------------------------\n");
}

// função para exibir as informações de um produto  no carrinho
void infoCarrinho(int i) {
    printf("---------------------------\n");
    printf("Codigo do produto: %d \n", carrinho[i].produto.codigo); // código
    printf("Nome do produto: %s \n", carrinho[i].produto.nome); // nome
    printf("Preco do produto: %.2f \n", carrinho[i].produto.preco); // preço
    printf("Quantidade do produto: %d \n", carrinho[i].quantidade); // quantidade
    printf("---------------------------\n");
}

// função para remover um produto do carrinho
void removerProduto(int cod) {
    for (int i = 0; i < quantC; i++) {
        if (carrinho[i].produto.codigo == cod) {
            // se a quantidade do produto no carrinho for maior que 1
            if (carrinho[i].quantidade > 1) {
                int quantidadeRemover;
                printf("A quantidade atual do produto '%s' e %d.\n", carrinho[i].produto.nome, carrinho[i].quantidade);
                printf("Quantas unidades deseja remover? (Max: %d): ", carrinho[i].quantidade);
                scanf("%d", &quantidadeRemover);

                // verifica se a quantidade a ser removida é válida
                if (quantidadeRemover > 0 && quantidadeRemover <= carrinho[i].quantidade) {
                    carrinho[i].quantidade -= quantidadeRemover; // Atualiza a quantidade
                    printf("%d unidade(s) do produto '%s' removida(s) com sucesso!\n", quantidadeRemover, carrinho[i].produto.nome);
                    // se a quantidade se torna zero, remove o produto do carrinho
                    if (carrinho[i].quantidade == 0) {
                        // move os produtos para frente
                        for (int j = i; j < quantC - 1; j++) {
                            carrinho[j] = carrinho[j + 1];
                        }
                        quantC--; // reduz a quantidade de produtos no carrinho
                    }
                } else {
                    printf("Quantidade inválida! Deve ser entre 1 e %d.\n", carrinho[i].quantidade);
                }
            } else {
                // se a quantidade do produto é 1, remove o produto do carrinho
                printf("Removendo o produto '%s' do carrinho.\n", carrinho[i].produto.nome);
                for (int j = i; j < quantC - 1; j++) {
                    carrinho[j] = carrinho[j + 1]; // move os produtos para frente
                }
                quantC--; // reduz a quantidade de produtos no carrinho
            }
            return; // sai da função após a remoção
        }
    }
    printf("Código não encontrado no carrinho!\n");
}

// função para visualizar os itens no carrinho
void visualizarCarrinho() {
    system("cls"); // limpa a tela
    printf("Carrinho:\n");
    if (quantC == 0) {
        printf("O carrinho esta vazio.\n"); // mensagem se o carrinho estiver vazio
        esperar();
        return;
    } else {
        for (int i = 0; i < quantC; i++) {
            infoCarrinho(i); // função que exibe informações de cada item no carrinho
        }
    }

    printf("\nDeseja remover algo da sua lista de compras? Se sim digite o codigo do produto, se nao digite 0: ");
    int cod;
    scanf("%d", &cod); // lê o código
    if (cod != 0) {
        removerProduto(cod); // função para remover o produto
    }
    esperar(); // espera pela entrada do usuário
}

// função para fechar o pedido
void fecharPedido() {
    system("cls");
    printf("Fechar Pedido:\n");
    
    // verifica se o carrinho está vazio
    if (quantC == 0) {
        printf("O carrinho esta vazio.\n");
        esperar(); // espera pela entrada do usuário
        return;
    }

    // Exibe os produtos no carrinho
    printf("Produtos no carrinho:\n");
    for (int i = 0; i < quantC; i++) {
        infoCarrinho(i); //função para exibir a informação dos produtos
    }

    // total do pedido
    float total = 0.0;
    for (int i = 0; i < quantC; i++) {
        total += carrinho[i].produto.preco * carrinho[i].quantidade; // soma os preços
    }
    
    printf("O total do seu pedido e R$ %.2f\n", total);
    printf("Fechar pedido?\n1. Sim\n2. Nao ");
    
    int x;
    scanf("%d", &x);
    
    // se o usuário confirmar
    if (x == 1) {
        printf("Pedido fechado! Volte sempre!\n");
        quantC = 0; // limpa o carrinho
    } else {
        printf("Pedido nao fechado.\n");
    }
    
    esperar(); // espera pela entrada do usuário
}

//função para comprar produto
void comprarProduto() {
    int codigo;
    system("cls");
    printf("Comprar produtos:\n");

    // verifica se há produtos cadastrados
    if (quantP == 0) {
        printf("\nNenhum produto cadastrado!\n");
        esperar(); // espera pela entrada do usuário
        return;
    }

    // exibe os produtos
    printf("Produtos cadastrados:\n");
    for (int i = 0; i < quantP; i++) {
        infoProduto(i);
    }

    // solicita o código do produto
    printf("Digite o codigo do produto para adiciona-lo no carrinho: ");
    scanf("%d", &codigo);

    // verifica se o código do produto é valido
    int encontrado = 0;
    for (int i = 0; i < quantP; i++) {
        if (codigo == produtos[i].codigo) {
            encontrado = 1;

            // verifica se o produto já está no carrinho
            for (int j = 0; j < quantC; j++) {
                if (carrinho[j].produto.codigo == codigo) {
                    carrinho[j].quantidade++; // aumenta a quantidade no carrinho
                    printf("Quantidade do produto '%s' aumentada para %d!\n", produtos[i].nome, carrinho[j].quantidade);
                    esperar(); // espera pela entrada do usuário
                    return;
                }
            }

            // se o produto não estiver no carrinho, adiciona ele
            carrinho[quantC].produto = produtos[i];
            carrinho[quantC].quantidade = 1; // define a quantidade inicial como 1
            quantC++;
            printf("\nProduto '%s' adicionado ao carrinho!\n", produtos[i].nome);
            esperar(); // espera pela entrada do usuário
            return;
        }
    }

    if (!encontrado) {
        printf("\nCodigo invalido!\n");
        esperar(); // espera pela entrada do usuário
    }
}

// função para verificar se um produto está no carrinho
int temNoCarrinho(int codigo) {
    for (int i = 0; i < quantC; i++) {
        if (codigo == carrinho[i].produto.codigo) {
            return 1; // retorna 1 se encontrado
        }
    }
    return 0; // retorna 0 se não encontrado
}

// função para mudar informações de um produto cadastrado
void mudarInformacoes() {
    int opcao, codigo;
    printf("Deseja mudar alguma informacao dos produtos cadastrados?\n1.Sim\n2.Nao\n");
    scanf("%d", &opcao); // lê a entrada
    if (opcao == 1) {
        printf("Digite o codigo do produto:\n");
        scanf("%d", &codigo); // lê o código do produto

        int encontrado = 0; // inicializa a variável encontrado
        for (int i = 0; i < quantP; i++) {
            if (codigo == produtos[i].codigo) { // verifica se o código existe
                encontrado = 1; // marca como encontrado
                printf("Mudando o nome:\n");
                fflush(stdin); // limpa a entrada
                fgets(produtos[i].nome, sizeof(produtos[i].nome), stdin); // le o nome
                produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0'; // remove a nova linha

                printf("Mudando o preco:\n");
                scanf("%f", &produtos[i].preco); // lê o preço
                printf("Produto modificado com sucesso!\n"); 
                break; // quebra o loop
            }
        }
        if (!encontrado) {
            printf("Codigo nao encontrado!\n"); // se nao encontrar
        }
    }
}
