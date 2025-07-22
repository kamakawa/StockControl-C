# StockControl

Um sistema intuitivo de **gerenciamento de estoque** desenvolvido em C, com foco na manipulação de estruturas de dados, persistência de informações em arquivos binários e gerenciamento dinâmico de memória. Este projeto foi concebido para oferecer uma ferramenta prática de controle de produtos, ideal para pequenos comércios ou para a aplicação de conceitos fundamentais de sistemas de dados.

**Desenvolvido durante meu 2º período da faculdade**, este projeto pessoal serviu como uma base crucial para solidificar meus conhecimentos em linguagem C, abordando desafios de gerenciamento de dados e interação via console de forma autônoma e proativa.

---

## 🚀 Funcionalidades Principais

* **Cadastro de Produtos:** Adicione novos itens ao estoque, registrando nome, quantidade atual, quantidade mínima para alerta, valor de compra e valor de venda.
* **Listagem Completa:** Visualize todos os produtos cadastrados de forma organizada em uma tabela.
* **Controle de Entrada e Saída:** Gerencie o fluxo de produtos, adicionando (reposição) ou subtraindo (venda) itens do estoque.
* **Alerta de Estoque Mínimo:** Receba notificações quando a quantidade de um produto atingir ou ficar abaixo do nível de segurança definido.
* **Pesquisa Dinâmica:** Encontre produtos específicos pelo nome e acesse rapidamente seus detalhes.
* **Persistência de Dados:** Todas as informações do estoque são salvas automaticamente em um arquivo binário (`estoque.dat`), garantindo que seus dados permaneçam intactos entre as sessões do programa.
* **Gerenciamento de Memória:** Implementação de alocação e realocação dinâmica de memória para otimizar o uso de recursos conforme o crescimento do estoque.

---

## 🛠️ Tecnologias Utilizadas

* **Linguagem de Programação:** C
* **Bibliotecas Padrão:** `stdio.h` (entrada/saída), `stdlib.h` (funções gerais, alocação de memória), `string.h` (manipulação de strings), `math.h` (incluída, caso haja expansões futuras que exijam cálculos matemáticos).

---

## Como Compilar e Executar

Para compilar e rodar o **StockControl**, você precisará de um compilador C (como GCC).

1.  **Clone o repositório:**
    ```bash
    git clone [https://github.com/seu-usuario/StockControl.git](https://github.com/seu-usuario/StockControl.git)
    cd StockControl
    ```
    *(Lembre-se de substituir `seu-usuario` pelo seu username no GitHub)*

2.  **Compile o código:**
    ```bash
    gcc main.c -o stockcontrol
    ```
    *(Assumindo que o arquivo principal se chama `main.c`. Se for diferente, ajuste o nome do arquivo)*

3.  **Execute o programa:**
    ```bash
    ./stockcontrol
    ```

---

## 🧠 Conceitos e Habilidades Demonstradas

Este projeto é uma prova prática do meu domínio em:

* **Estruturas de Dados Customizadas (`Structs`):** Definição e manipulação de tipos de dados complexos para representar entidades do mundo real (produtos).
* **Manipulação de Arquivos (File I/O):** Leitura e escrita eficientes de dados binários para garantir a persistência das informações.
* **Ponteiros e Alocação Dinâmica de Memória (`malloc`, `realloc`, `free`):** Gerenciamento flexível e otimizado da memória do sistema.
* **Modularização de Código:** Organização do projeto em funções bem definidas para promover reuso, legibilidade e manutenção.
* **Tratamento de Strings:** Utilização de funções padrão para processar e manipular entradas de texto do usuário.
* **Lógica de Negócio Básica:** Implementação de regras e fluxos para um sistema de controle de estoque.
* **Desenvolvimento CLI (Command Line Interface):** Construção de uma aplicação interativa via linha de comando.

---

## 💡 Próximos Passos (Melhorias Potenciais)

* **Interface Gráfica (GUI):** Integrar uma biblioteca como **Raylib** (ou similar) para criar uma interface visual mais amigável e interativa.
* **Remoção de Produtos:** Adicionar funcionalidade para excluir itens do estoque.
* **Geração de Relatórios:** Implementar a criação de relatórios de estoque, vendas ou produtos com baixo nível.
* **Validação de Entrada Robusta:** Aprimorar as validações de dados para garantir maior integridade do sistema.
* **Organização por ID:** Atribuir um identificador único para cada produto, facilitando a busca e manipulação.

---

## Contato

* **Eric Kamakawa** - [erickamakawa@hotmail.com](mailto:erickamakawa@hotmail.com)
* **LinkedIn:** [linkedin.com/in/erickamakawa](https://www.linkedin.com/in/erickamakawa)
* **GitHub:** [github.com/kamakawa](https://github.com/kamakawa)

---


