#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct{
    char nome[50];
    int quantidade;
    int quantidadeMinima;
    float valorComprado;
    float valorVenda;
}Estoque;//estrutura contendo os dados de cada produto

void dadosSalvos(Estoque* estoque, int quantidade) {
    FILE *arquivo = fopen("estoque.dat", "rb"); //Abrindo o arquivo

    if (arquivo == NULL) {
        printf("Nenhum usuário cadastrado ainda.\n");
        return;
    } // Caso não exista o arquivo 

    fread(estoque, sizeof(Estoque), quantidade, arquivo); // Lendo o arquivo

    fclose(arquivo); // Fechando o arquivo
} //Função externa para carregar os produtos já cadastrados

int contarProdutos() {
    FILE *arquivo = fopen("estoque.dat", "rb"); //abrindo o arquivo no modo read binário

    if (arquivo == NULL) {
        return 0;
    } // teste para o caso se não houver usuários 

    fseek(arquivo, 0, SEEK_END);
    int quantidade = ftell(arquivo) / sizeof(Estoque);

    fclose(arquivo);// Fechando o arquivo

    return quantidade;//retornando o número de produtos
}// Função para contar o número de produtos cadastradas

void salvarAlteracao(Estoque* dados, int quantidade) {
    FILE *arquivo = fopen("estoque.dat", "wb+"); // Abrindo o arquivo

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    } // Teste se o arquivo existe

    fwrite(dados, sizeof(Estoque), quantidade, arquivo); //sobrescrevendo os dados antigos

    fclose(arquivo); // Fechando o arquivo
}// Função para salvar as edições feitas no cadastro

void pesquisar(Estoque* estoque, int quantidade){
    dadosSalvos(estoque, quantidade); //pegando os dados salvos
    char nome[50]; //para facilitar a filtragem dos nomes
    int aux; // uma variável para auxiliar
    int encontrar = 0;

    printf("Digite o nome do produto:");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    setbuf(stdin, NULL);

    for(int i = 0; i < quantidade; i++){
        if(strcmp(nome, estoque[i].nome) == 0){
            printf("\nProduto encontrado!\n");
            encontrar = 1;
            aux = i;

            printf("\n+------------------+----------+----------------+----------------+----------------+\n");
            printf("| Nome             | Quantidade | Quantidade Min. | Valor Compra   | Valor Venda     |\n");
            printf("+------------------+----------+----------------+----------------+----------------+\n");
            printf("| %-17s | %8d | %14d | %14.2f | %14.2f |\n",
                estoque[aux].nome, estoque[aux].quantidade, estoque[aux].quantidadeMinima, estoque[aux].valorComprado, estoque[aux].valorVenda);
            printf("+------------------+----------+----------------+----------------+----------------+\n");
            break;
        }
    }

    if(encontrar == 0){
        printf("\nProduto não encontrado\n");
    }//Caso não encontre o nome do produto
}//Função para pesquisar os produtos

void editar(Estoque* estoque, int quantidade){
    int opcao;
    char nome[50];
    int encontrar = 0;
    int aux;
    int alterar;
    int quantidadeFinal;

    do{
        printf("Escolha uma opção: \n");
        printf(" 1 - Adicionar produtos no estoque \n");
        printf(" 2 - Venda / Diminuição de produtos \n");
        printf(" 3 - Sair\n");
        scanf("%d", &opcao);
        setbuf(stdin, NULL);

        switch (opcao)
        {
        case 1://Para adicionar produtos
        
            dadosSalvos(estoque, quantidade);
            printf("Digite o nome do produto: \n");
            fgets(nome, 50, stdin);
            nome[strcspn(nome, "\n")] = '\0';
            setbuf(stdin, NULL);
    
            for(int i = 0; i < quantidade; i++){
                if(strcmp(nome, estoque[i].nome) == 0){
                    printf("Produto encontrado\n");
                    encontrar = 1;
                    aux = i;
                }
    
                if(encontrar == 0){
                    printf("\nProduto não encontrado \n");
                }
            }
    
            printf("Digite a quantidade de produtos que você deseja adicionar: \n");
            scanf("%d", &alterar);
            setbuf(stdin, NULL);
    
            quantidadeFinal = estoque[aux].quantidade + alterar;
            estoque[aux].quantidade = quantidadeFinal;
            break;
        
        case 2: //Para diminuir a quantidade de produtos
            dadosSalvos(estoque, quantidade);
            printf("Digite o nome do produto: \n");
            fgets(nome, 50, stdin);
            nome[strcspn(nome, "\n")] = '\0';
            setbuf(stdin, NULL);
    
            for(int i = 0; i < quantidade; i++){
                if(strcmp(nome, estoque[i].nome) == 0){
                    printf("Produto encontrado\n");
                    encontrar = 1;
                    aux = i;
                }
    
                if(encontrar == 0){
                    printf("\nProduto não encontrado \n");
                }
            }
    
            printf("Digite a quantidade de produtos que saiu do estoque: \n");
            scanf("%d", &alterar);
            setbuf(stdin, NULL);
    
            quantidadeFinal = estoque[aux].quantidade - alterar;
    
            if(quantidadeFinal > 0){
              estoque[aux].quantidade = quantidadeFinal;
    
              if(quantidadeFinal < estoque[aux].quantidadeMinima){
                printf("\nATENÇÃO! \n");
                printf("Qunatidade mínima no estoque atingida, repor o estoque URGENTEMENTE \n");
              }
            }else{
                printf("\nErro! quantidade insuficiente, falta de produto no estoque\n");
            }
                
            break;
        
        case 3:
            printf("Saindo...\n");
            break;
    
        default:
            break;
        }
    }while(opcao != 3);

}//Função para alterar a quantidade de produtos no estoque

void listar(Estoque* estoque, int quantidade) {
    dadosSalvos(estoque, quantidade);

    printf("\n+------------------+----------+----------------+----------------+----------------+\n");
    printf("| Nome             | Quantidade | Quantidade Min. | Valor Compra   | Valor Venda     |\n");
    printf("+------------------+----------+----------------+----------------+----------------+\n");
    for (int i = 0; i < quantidade; i++) {
        printf("| %-17s | %8d | %14d | %14.2f | %14.2f |\n",
            estoque[i].nome, estoque[i].quantidade, estoque[i].quantidadeMinima, estoque[i].valorComprado, estoque[i].valorVenda);
    }
    printf("+------------------+----------+----------------+----------------+----------------+\n");
}

void salvar(Estoque* estoque, int tamanho) {
    FILE *arquivo = fopen("estoque.dat", "ab");// Abrindo o arquivo
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    fwrite(estoque, sizeof(Estoque), tamanho, arquivo);
    fclose(arquivo);
} // Função para salvar o cadastro

void cadastrar(Estoque** estoque, int* tamanho) {
    char escolha;
    int quantidadeAtual = contarProdutos();
    *estoque = (Estoque*) realloc(*estoque, (*tamanho) * sizeof(Estoque));

    for (int i = quantidadeAtual; i < *tamanho; i++) {
        printf("Digite o nome do produto: ");
        fgets((*estoque)[i].nome, 50, stdin);
        (*estoque)[i].nome[strcspn((*estoque)[i].nome, "\n")] = '\0';

        printf("Digite a quantidade comprada: ");
        scanf("%d", &(*estoque)[i].quantidade);
        setbuf(stdin, NULL);

        printf("Digite a quantidade mínima no estoque: ");
        scanf("%d", &(*estoque)[i].quantidadeMinima);
        setbuf(stdin, NULL);

        printf("Digite o valor pago pelo produto: ");
        scanf("%f", &(*estoque)[i].valorComprado);
        setbuf(stdin, NULL);

        printf("Digite o valor de venda: ");
        scanf("%f", &(*estoque)[i].valorVenda);
        setbuf(stdin, NULL);

        printf("Produto cadastrado com sucesso!\n");
        salvar(&(*estoque)[i], 1);

        printf("Deseja cadastrar mais um produto? (S/N): ");
        scanf(" %c", &escolha);
        setbuf(stdin, NULL);

        if (escolha == 'N' || escolha == 'n') {
            break;
        }

        (*tamanho)++;
        *estoque = (Estoque*) realloc(*estoque, (*tamanho) * sizeof(Estoque));
    }
}

int main(){
    int opcao;
    int tamanho = 2;
    int quantidade;

    Estoque* estoque = (Estoque*) malloc(tamanho * sizeof(Estoque));

    do{

        printf("\n==== ESTOQUE ====\n");
        printf("1 - Cadastrar novo produto\n");
        printf("2 - Listar todos os produtos do estoque\n");
        printf("3 - Entrada e saida de produtos\n");
        printf("4 - Pesquisar produto\n");
        printf("5 - Sair\n");
        printf("\nEscolha uma opção:");
        scanf("%d", &opcao);
        setbuf(stdin, NULL);
        
        switch (opcao){
        case 1:
            cadastrar(&estoque, &tamanho);            
            break;
    
        case 2:
            quantidade = contarProdutos();
            listar(estoque, quantidade);
            break;
            
        case 3:
        quantidade = contarProdutos();
        editar(estoque, quantidade);
        salvarAlteracao(estoque, quantidade);
        break;
            
        case 4:
        quantidade = contarProdutos();
        pesquisar(estoque, quantidade);
        break;
            
        case 5: 
        printf("Saindo... \n");
        break;
            
        default:
        printf("Opção inválida\n");
        break;

        }
    }while(opcao != 5);


    free(estoque);
}