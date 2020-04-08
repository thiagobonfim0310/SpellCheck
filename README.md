# SpellCheck
O spell checker - que em português significa “verificador de palavras” - tem como objetivo alertar o usuário sobre a presença de palavras com erros gramaticais em um texto qualquer. Ele realiza testes com as palavras de um texto, comparando-as com um dicionário utilizado na sua implementação. Presume-se que o dicionário esteja correto e atualizado, o que possibilita a boa execução do corretor ortográfico. 
Para a implementação do spell checker, neste trabalho, será utilizado a tabela hash. Essa estrutura de dados torna a busca, comparação das palavras do texto e a construção do dicionário mais eficiente, uma vez que para uma quantidade limitada de entradas com um universo muito maior de possíveis chaves - como é o caso de strings em um texto - operações comuns para dicionários tais como busca e inserção tem um custo constante O(1) para um caso médio. O método consiste em utilizar funções de hash  que calculam o índice para palavra a ser verificada ou inserida no vetor que armazena o dicionário.