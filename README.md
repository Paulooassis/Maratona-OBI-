# Trabalho de Aeds - Hotel Descanso Garantido

   
## Descrição

O Hotel Descanso Garantido é um hotel localizado no centro de Itacaré – BA, com um forte compromisso em proporcionar um excelente atendimento e fidelizar seus clientes. O hotel conta com uma equipe composta por recepcionistas, auxiliares de limpeza, garçons e um gerente. Até o momento, o hotel realizava o controle de estadias, clientes e funcionários através de planilhas do Excel e registros em cadernos, o que frequentemente resultava em problemas organizacionais, incluindo conflitos de reserva, onde um mesmo quarto era reservado para mais de um cliente. Por isso, foi desenvolvido um sistema em linguagem C para resolver esses problemas e melhorar a eficiência operacional.

## Bibliotecas Usadas

* **Stdio.h**: possui as funções printf e scanf em C são essenciais para exibir dados formatados na tela e capturar entrada do usuário, respectivamente. Enquanto fprintf e fscanf são usadas para escrever e ler dados formatados em arquivos, permitindo manipulação eficiente de informações em contextos de armazenamento persistente. Essas funções são fundamentais para a interação com o usuário e para o processamento de dados em programas C.
* **Stdlib.h**: é usada para alocar os itens dinamicamente na memória.
* **String.h**: é uma biblioteca que traz diversas funções importantes sobre string, uma das usadas no trabalho foi a 'strcmp'.

### Menu

- **Descrição**: Esse é a imagem principal do nosso menu, no qual já vem com quartos cadastrados em seu txt e é possível escolher as demais opções com suas devidas telas.
- **Estrutura**:

========== Menu Principal ==========
1. Cadastrar Cliente
2. Cadastrar Funcionario
3. Cadastrar Estadia
4. Exibir Estadia de Cliente
5. Dar Baixa em Estadia
6. Pesquisar
7. Sair
   
====================================

Digite a opcao desejada: 

## Funções utilizadas no projeto

* **cadastrar_cliente(cliente cli[])**: uma função usada para cadastrar cliente, tendo como paramêtro a struct de cliente, sendo solicitada cada informação para preencher o cliente.
* **cadastrar_funcionario(funcionario fun[])**: uma função usada para cadastrar funcionário, tendo como paramêtro a struct de funcionário, sendo solicitada cada informação para preencher o funcionário.
* **validar_data(datas dat)**: uma função que é chamada na função de cadastrar estadia, no qual verifica se a data digitada é válida, ou seja, vê se ela é depois do ano de 2023 que é o do ano passado, verifica se possui mais de 30 dias ou se o mes digitado é maior do que 12 ou menor do que 1, garantindo com que o usuario nao cadastre a data errada.
* **data_maior_que(datas dat1, datas dat2)**: uma função que é chamada na função de cadastrar estadia, no qual verifica se a data de saida é maior do que a data de entrada, pois nao é possivel realizar uma estadia no tempo passado.
* **cadastrar_estadia(estadia est[], cliente cli[], quarto qua[])**: uma função usada para cadastrar estadia, tendo como paramêtro a struct de estadia, cliente, quarto, sendo solicitada cada informação para preencher a estadia.
* **dar_baixa_estadia(estadia est[], quarto qua[], cliente cli[])**:  uma função usada para dar baixa na estadia, tendo como paramêtro a struct de estadia, cliente, quarto, sendo solicitada o codigo da estadia que voce deseja realizar a baixa.
* **pesquisar(cliente cli[], funcionario fun[])**: 
