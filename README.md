# Manipulação de Listas Duplamente Encadeadas

## Especificações

Programa em C que implemente o funcionamento de um sistema para a clínica, 
recebendo as informações dos pacientes e as organizando em uma
lista duplamente encadeada com comportamento circular. Esse sistema será capaz
de realizar algumas operações:
	
	• Consultar se um registro de um paciente está contido no sistema (lista). 
      Imprimir se existir, caso contrário indicar que não foi encontrado;
	• Imprimir todos os registros de pacientes em ordem crescente;
	• Imprimir todos os registros de pacientes em ordem decrescente.

Além de um código único, cada paciente é representado no sistema por um conjunto de
informações como: nome, sexo (m ou f), idade, peso, altura, e telefone para contato. Claro,
que todas essas informações precisam ser impressas/mostradas pelas operações do sistema.

O programa receberá dois arquivos texto como parâmetros de entrada:
	
	• Arquivo de entrada: um arquivo texto contendo os registros/cadastros dos pacientes.
Cada linha contém a informação de um paciente, na ordem: código, nome, sexo, idade,
peso, altura e telefone para contato. Durante a execução podem ser fornecidos N
pacientes. Esse número é variável. Após os registros, existirá uma linha com um
inteiro único, especificando qual operação será realizada:

	1. impressão na ordem crescente dos registros (segundo o código);
	2. impressão na ordem decrescente dos registros (segundo o código);
	3. consulta se um determinado paciente existe ou não nos registros da clínica.

No caso 3 em específico, haverá mais uma linha com um inteiro único correspondente
ao código que será consultado na lista. Perceba que o código consultado pode ou não
existir nos registros, e é sua tarefa lidar com ambas as situações.

	• arquivo de saída: um arquivo texto onde deverá ser impressa a saída desejada:
	
	1. os registros impressos, um por linha, em ordem crescente de código;
	2. os registros impressos, um por linha, em ordem decrescente de código;
	3. se o código consultado existir, imprimir ele no arquivo de saída. Caso não exista,
imprimir uma mensagem indicando que o código não existe/não foi encontrado.
