# Trabalho de Aeds - Hotel Descanso Garantido

* Gabriel Peçanha Diniz
* Tiago Boaventura Amaral
   
## Descrição

O Hotel Descanso Garantido é um hotel localizado no centro de Itacaré – BA, com um forte compromisso em proporcionar um excelente atendimento e fidelizar seus clientes. O hotel conta com uma equipe composta por recepcionistas, auxiliares de limpeza, garçons e um gerente. Até o momento, o hotel realizava o controle de estadias, clientes e funcionários através de planilhas do Excel e registros em cadernos, o que frequentemente resultava em problemas organizacionais, incluindo conflitos de reserva, onde um mesmo quarto era reservado para mais de um cliente. Por isso, foi desenvolvido um sistema em linguagem C para resolver esses problemas e melhorar a eficiência operacional.

### Menu

    ---------------------------------
         HOTEL DESCANSO GARANTIDO
    ---------------------------------
    1. Cadastrar Cliente
    2. Cadastrar Funcionario
    3. Cadastrar Estadia
    4. Cadastrar Quarto
    5. Mostrar estadia do Cliente
    6. Pesquisar Cliente
    7. Pesquiasar Funcionario
    8. Dar Baixa na Estadia
    9. Encerrar programa
    
    Digite a opcao desejada: 

## Bibliotecas Usadas

* **Stdio.h**: possui as funções printf e scanf em C são essenciais para exibir dados formatados na tela e capturar entrada do usuário, respectivamente. Enquanto fprintf e fscanf são usadas para escrever e ler dados formatados em arquivos, permitindo manipulação eficiente de informações em contextos de armazenamento persistente. Essas funções são fundamentais para a interação com o usuário e para o processamento de dados em programas C.
* **Stdlib.h**: é usada para alocar os itens dinamicamente na memória.
* **String.h**: é uma biblioteca que traz diversas funções importantes sobre string, uma das usadas no trabalho foi a 'strcmp'.

## Funções utilizadas no projeto

* **cadastrar_cliente(cliente cli[])**: uma função usada para cadastrar cliente, tendo como paramêtro a struct de cliente, sendo solicitada cada informação para preencher o cliente.
* **cadastrar_funcionario(funcionario fun[])**: uma função usada para cadastrar funcionário, tendo como paramêtro a struct de funcionário, sendo solicitada cada informação para preencher o funcionário.
* **validar_data(datas dat)**: uma função que é chamada na função de cadastrar estadia, no qual verifica se a data digitada é válida, ou seja, vê se ela é depois do ano de 2023 que é o do ano passado, verifica se possui mais de 30 dias ou se o mes digitado é maior do que 12 ou menor do que 1, garantindo com que o usuario nao cadastre a data errada.
* **data_maior_que(datas dat1, datas dat2)**: uma função que é chamada na função de cadastrar estadia, no qual verifica se a data de saida é maior do que a data de entrada, pois nao é possivel realizar uma estadia no tempo passado.
* **cadastrar_estadia(estadia est[], cliente cli[], quarto qua[])**: uma função usada para cadastrar estadia, tendo como paramêtro a struct de estadia, cliente, quarto, sendo solicitada cada informação para preencher a estadia.
* **dar_baixa_estadia(estadia est[], quarto qua[], cliente cli[])**:  uma função usada para dar baixa na estadia, tendo como paramêtro a struct de estadia, cliente, quarto, sendo solicitada o codigo da estadia que voce deseja realizar a baixa.
* **pesquisar(cliente cli[], funcionario fun[])**: uma função usada para pesquisar informações sobre os clientes e os funcionários, tendo como paramêtro a struct de cliente e funcionário, além disso, ela conta com a possibilidade de pesquisar através do código ou nome do cliente/funcionário.
* **exibir_estadia(estadia est[], cliente cli[])**: uma função usada para exibir as estadias de um código digitado pelo usuário, tendo como paramêtro a struct de cliente e estadia.
* **print_file(cliente cli[], funcionario fun[], estadia est[], quarto qua[])**: a função tem como paramêtro todas as structs do projeto, sendo a cliente, funcionario, estadia e quarto, no qual ela printa todas as informações em seus devidos txts, sendo respectivamente, clientes.txt, funcionarios.txt, estadias.txt, quartos.txt, sendo a primeira linha a quantidade total de cada elemento do arquivo, e depois cada uma de suas informações sendo separadas por um ?
* **read_file(cliente cli[], funcionario fun[], estadia est[], quarto qua[])**: uma função usada para scanear todas as informações já armazenadas nos arquivos.
* **main()**: e a função main onde possui o menu, o chamado de cada função e a declaração das structs.

## Quartos

* É importante ressaltar que oos quartos do hotel já estão cadastrados no arquivo txt chamado quartos, sendo possivel adicionar novos caso necessário.
