<h1>README - Mercado Saulindo</h1>

<h2>Descrição</h2>

Este é um programa em C que simula um sistema de compras em um mercado feito para a atividade avaliativa de Estrutura de Dados. Ele permite o cadastro, listagem, modificação, remoção e compra de produtos, visualização do carrinho de compras e fechamento de pedidos.

<h2>Desenvolvimento</h2>
O sistema foi desenvolvido no Visual Studio Code utilizando a linguagem de programação C, usando conceitos como structs, arrays e funções. 

<h2>Funcionalidades Principais</h2>

<b>1. Cadastrar Produto:</b> Permite adicionar novos produtos ao sistema. Cada produto deve ter um código em números inteiros, um nome em letras e/ou números, e um preço que aceita números decimais.

<b>2. Listar Produtos:</b> Exibe todos os produtos cadastrados. Aqui também é oferecida a opção do usuário trocar as informações de um produto já cadastrado, sendo possível a mudança de nome e preço, mas NÃO é possível mudar o código de um produto.

<b>3. Comprar Produto:</b> Adiciona um produto ao carrinho baseado em seu código. Se o produto já estiver no carrinho, a quantidade dele é aumentada.

<b>4. Visualizar Carrinho:</b> Mostra os produtos no carrinho do cliente e permite a remoção parcial ou total de cada um deles.

<b>5. Fechar Pedido:</b> Exibe um resumo dos produtos no carrinho e calcula o total a ser pago. O usuário pode confirmar ou cancelar o pedido.

<b>6. Sair do Sistema:</b> Encerra o programa.

<h2>Estruturas</h2>

<b>Produto:</b> Estrutura que contém informações sobre o produto, como código, nome e preço.

<b>Carrinho:</b> Estrutura que armazena um produto e sua quantidade no carrinho.

<h2>Uso</h2>
Para executar o programa, siga os passos abaixo:

<b>Compilação:</b> 
Caso não tenha, instale um compilador de C como o GCC. 
Abra um terminal e o diretório do arquivo "mercadofinal.c" e execute o comando "gcc -o mercadofinal mercadofinal.c"

<b>Execução:</b>
Depois de compilar o algoritmo, escreva "mercadofinal.exe" no terminal.

<b>Interação:</b>
Siga as instruções no menu do terminal para interação com o sistema.

<h2>Dependências</h2>

Compilador C (gcc ou equivalente).

Sistema operacional que suporte comandos cls (Windows) ou clear (Linux/Mac).

<h2>Notas</h2>
A entrada de dados é feita via terminal. Certifique-se de fornecer entradas válidas para evitar erros.
O sistema possui um limite de 50 produtos e 50 itens no carrinho.

<h2>Licença</h2>
Este projeto é de domínio público e pode ser utilizado e modificado conforme necessário.
