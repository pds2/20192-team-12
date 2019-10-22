## Sistema de Alocação de Demanda de Transporte

## Descrição

Desenvolvimento de um sistema que, dada uma demanda de transporte de uma certa quantidade de determinado produto, para alguma localidade do Brasil ou Exterior, encontra o caminho de menor custo. O custo a ser considerado pode ser monetário ou menor distância ou tempo de percurso, considerando os preços dos serviços, tempo de transporte e capacidade dos diversos modais disponíveis (rodoviário, ferroviário, aéreo e aquaviário).

### User Stories

#### Embarcador

Como **embarcador** - agente dos setores econômicos primário, secundário ou terciário - tem a necessidade de transportar uma **quantidade** de um **produto** específico, em toneladas, do **município** *A*, para outro **município** *B*, com o menor custo, em R\$, ou no menor **tempo,** em dias. Como exemplo de embarcador podemos ter um produtor rural, uma indústria, uma mineradora, um comerciante ou atravessador, uma distribuidora de combustíveis, ou seja, qualquer agente capaz de contratar um transportador.

Critérios de aceitação:
- Exibir o produto  e a quantidade a ser transportada;
- Exibir a localidade de origem e destino do produto;

#### Modal

Como **modal** - meio de transporte - possui determinada **capacidade**, em toneladas, para transportar um **produto**, cobrando certo **preço** para realizar o serviço, em R\$/(km.unidade de medida), e se desloca com uma **velocidade média**, em km/h, de um município A para um município B. A unidade de medida do preço pode ser tonelada (ton), litro (L), container(TEU) ou outro tipo de medida. Tem-se basicamente 5 tipos de modais: rodoviário, ferroviário, aquaviário, dutoviário e aéreo. O aquaviário ainda pode se subdividir em marítimo e fluvial.

Critérios de aceitação:
- Exibir a capacidade do veículo por unidade de medida;
- Exibir o preço unitário do serviço de transporte em R$/km.unidade de medida;
- Exibir a velocidade média;

#### Modal Rodoviário 

Como modal **rodoviário**, utiliza como via de transporte as rodovias que podem ou não cobrarem **pedágio**. O valor pago pelo pedágio deve ser incluído no **preço**  do serviço de transporte, como custo adicional.

Critérios de aceitação:
- Exibir a capacidade do veículo por unidade de medida;
- Exibir o preço unitário do serviço de transporte em R$/km.unidade de medida;
- Exibir se o caminho tem ou não tem pedágio;
- Exibir o valor do pedágio;
- Exibir a velocidade média;


#### Modal Aquaviário

Como modal **aquaviário**, utiliza como via o meio marítimo ou fluvial. O embarque da mercadoria deve ser realizado por meio de terminais portuários. O terminal para permitir o embarque cobra uma **taxa** de utilização que deve ser adicionada ao **preço**  do serviço de transporte.

Critérios de aceitação:
- Exibir a capacidade do veículo por unidade de medida;
- Exibir o preço unitário do serviço de transporte em R$/km.unidade de medida;
- Exibir o preço da taxa do terminal;
- Exibir a velocidade média;

#### Modal Aéreo

Como modal aéreo, realiza o embarque da mercadoria no aeroporto que cobra uma **tarifa** de utilização do terminal aéreo, em R$. O valor da taxa deve ser adicionado ao **preço** do transporte.

Critérios de aceitação:
- Exibir a capacidade do veículo por unidade de medida;
- Exibir o preço unitário do serviço de transporte em R$/km.unidade de medida;
- Exibir o preço da taxa do terminal;
- Exibir a velocidade média;

#### Operação de Transporte

Como **operação de transporte**, promete realizar o transporte de um **tipo de carga**, por um **modal** específico, cobrando o **preço** do serviço, em R\$, utilizando uma **rota** a ser percorrido entre os municípios de origem e destino. O preço do serviço é determinado, por sua vez, pela **quantidade do produto** a ser transportado por unidade de medida, a **distância** entre a origem e o destino, em km, pelo **preço unitário** da operação, em R\$/(km.unidade de medida) e pelas **tarifas** adicionais, quando houver. A unidade de medida do preço pode ser tonelada (ton), litro (L), container(TEU) ou outro tipo de medida.

Critérios de aceitação:
- Exibir o tipo de carga e a quantidade a ser transportada;
- Exibir a origem e destino da viagem;
- Exibir a rota;
- Exibir o(s) modal(is) utilizado(s) e o respectivo preço unitário;
- Calcular o preço do total do serviço;

#### Rota

Como **rota**, exibe o **caminho** percorrido na operação de transporte do **município** A até o município B. Ao percorrer a rota, a operação de transporte pode se utilizar de mais de um **modal** disponível. A partir do caminho é possível obter a **distância total** entre os dois pontos, bem como o **tempo de transporte** dado o modal utilizado.

Critérios de aceitação:
- Exibir as localidades que compõem a rota;
- Exibir o caminho;
- Calcular a distância;
- Calcular o tempo total de transporte, em horas;

#### Operador de Trasnporte

Como **operador de transporte**,  é responsável por realizar receber as solicitações (**operações de transporte**) de todos os **embarcadores** e dar a resposta adequada indicando se uma determinada **conexão** é possível ou não. Caso a conexão seja possível será calculada a rota que melhor se ajusta à demanda do embarcador - minimização de custo ou de tempo. 

Critérios de aceitação:
- Exibir o número de pontos de parada;
- Exibir o número de modais necessários;
- Exibir se existe conexão direta;
- Exibir a localidade mais próxima que tem rota.
- Exibir a rota que minimiza o custo financeiro;
- Exibir a rota que minimiza o custo de tempo;


#### Município

Como **município**,  está situado em um **estado** e **país** específico, possuindo um **nome** e as coordenadas geográficas **latitude** e **longitude** de seu centróide. Para simplificar o problema, a distância entre dois municípios a ser considerada pode ser a distância geodésica entre os seus centros. Como as coordenadas são expressas em graus, deve-se utilizar um fator de conversão de grau para quilômetros para obtermos o resultado.

Critérios de aceitação:
- Exibir o nome do município;
- Exibir o estado e o país em que o município se encontra;
- Exibir as coordenadas geográficas do municípios;

#### Estado, Condado, ou Região Administrativa

Como **Estado, Província, Condado ou outra divisão administrativa regional** encontra-se situado em um **país** que contém um ou mais municípios. Um estado é caracterizado pelo seu **nome** e o **país** a que pertence.

Critérios de aceitação:
- Exibir o nome do estado;
- Exibir o país em que o estado se encontra;

#### País

Como  **país** de destino, encontra-se localizado em um continente que pode ou não ter **acordo comercial** com o Brasil. Um país pode ser caracterizado por seu **nome** e o **continente** a que pertence.

Critérios de aceitação:
- Exibir o nome do país;
- Exibir o nome do continente;
- Exibir se o Brasil tem ou não acordo comercial com o país de destino.

### Cartões CRC

|Classe|Embarcador|
| --- | --- |
|**Responsabilidades**|**Colaborações**|
|produto|Município|
|quantidade|Estado|
||País|

|Classe|Modal|
| --- | --- |
|**Subclasses:**|**Rodoviário, Aquaviário/Aéreo**|
|**Responsabilidades**|**Colaborações**|
|preço unitário||
|capacidade||
|velocidade||

|Classe|Modal Rodoviário|
| --- | --- |
|**Superclasse:**|Modal|
|**Responsabilidades**|**Colaborações**|
|preço unitário||
|capacidade||
|velocidade||
|pedágio||
|tem pedágio||

|Classe|Modal Aquaviário/Aéreo|
| --- | --- |
|**Superclasse:**|Modal|
|**Responsabilidades**|**Colaborações**|
|preço unitário||
|capacidade||
|velocidade||
|taxa do terminal||

|Classe|Operador de Transporte|
| --- | --- |
|**Responsabilidades**|**Colaborações**|
|quantidade a transportar|Localidade|
|rota|Embarcador|
|preço unitário||
|preço total||
|||

|Classe|Rota|
| --- | --- |
|**Responsabilidades**|**Colaborações**|
|origem|Municipio|
|destino|Modal|
|distância||
|tempo de percurso||
|caminho||

|Classe|Localidade|
| --- | --- |
|**Responsabilidades**|**Colaborações**|
|municipio||
|estado||
|pais||
|tem acordo comercial||