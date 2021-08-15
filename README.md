# Teste-IC
IC ProVANT Simulator - Software Problem

## Realização: 
- IDE ultilizado: Visual Studio Code 
- Compilador utilizado: GCC 9.3.0

## Simulação:
A simulação das funções utilizadas basea-se no envio de informações do cliente ao servidor e é realizada no arquivo **main.cpp** no qual é incluido o arquivo **classes.hpp** que contem as classes Message e Fletcher16. Na primeira string de entrada da classe Message são intercalados 2 valores da sequência de Fibonacci e da sequência de números triangulares. Assim inicializa-se a classe em uma variável chamada mensagem na qual serão testadas as funções da classe e a geração dos coeficientes de Fletcher. 

## Saída:
A saída gerada é a seguinte:
```
Bloco 1  -  [C_0]: 0  [C_1]: 0

Bloco 2  -  [C_0]: 1  [C_1]: 1

Bloco 3  -  [C_0]: 2  [C_1]: 3

Bloco 4  -  [C_0]: 5  [C_1]: 8

Bloco 5  -  [C_0]: 7  [C_1]: 15

Bloco 6  -  [C_0]: 10  [C_1]: 25

Bloco 7  -  [C_0]: 16  [C_1]: 41

Bloco 8  -  [C_0]: 26  [C_1]: 67

Bloco 9  -  [C_0]: 21  [C_1]: 62

Bloco 10  -  [C_0]: 34  [C_1]: 101

Bloco 11  -  [C_0]: 36  [C_1]: 98

Bloco 12  -  [C_0]: 55  [C_1]: 156

Bloco 13  -  [C_0]: 66  [C_1]: 164

Mensagem armazenada: 0 1 1 3 2 3 6 10 5 8 15 21 30

Mensagem limpa:

```
