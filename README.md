## Sistema de Alocação de Demanda de Transporte 

## Descrição 
&nbsp;
Desenvolvimento de um sistema que, dada uma demanda de transporte de uma
certa quantidade de determinado produto, para alguma localidade do
Brasil ou Exterior, encontra o caminho de menor custo. O custo a ser
considerado pode ser monetário ou menor distância ou tempo de percurso,
considerando os preços dos serviços, tempo de transporte e capacidade
dos diversos modais disponíveis (rodoviário, ferroviário, aéreo e
aquaviário).

### User Stories
&nbsp;
-   **Embarcador**

Um **embarcador** é um agente dos setores econômicos primário,
secundário ou terciário que tem a necessidade de transportar uma
**quantidade** de um **produto** específico, em toneladas, do
**município** *A*, para outro **município** *B*, com o menor **custo**,
em R\$, ou no menor **tempo,** em dias. Como exemplo de embarcador
podemos ter um produtor rural, uma indústria, uma mineradora, um
comerciante ou atravessador, uma distribuidora de combustíveis, ou seja,
qualquer agente capaz de contratar um transportador.
&nbsp;
-   **Modal**

Neste trabalho, será considerado **modal** o meio de transporte com
determinada **capacidade**, em toneladas, para transportar um
**produto** cobrando certo **preço** para realizar o serviço, em
R\$/(km.unidade), e se deslocando com uma **velocidade média**, em km/h.
A unidade de medida do preço pode ser o quilograma, o litro, container
ou outro tipo de medida. Tem-se basicamente 5 tipos de modais:
rodoviário, ferroviário, aquaviário, dutoviário e aéreo. O aquaviário
ainda pode se subdividir em marítimo e fluvial.
&nbsp;
-   **Modal Rodoviário**

O modal **rodoviário** utiliza-se como meio de transporte as rodovias
que podem ou não serem pedagiadas. Assim, além das características da
categoria modal citada anteriormente, este modal ainda pode possuir como
custo adicional as tarifas de **pedágio**.
&nbsp;
-   **Modal Aquaviário**

O meio utilizado no modal **aquaviário** pode ser o marítimo ou fluvial.
O embarque da mercadoria deve ser realizado por meio de terminais
portuários. O terminal para permitir o embarque cobra uma **tarifa** de
utilização que deve ser adicionada ao custo do transporte.
&nbsp;
-   **Modal Aéreo**

No modal aéreo, o embarque da mercadoria é realizado no aeroporto que
também cobra uma **tarifa** do terminal aéreo. O valor da tarifa deve
ser adicionado ao **custo** do transporte.
&nbsp;
-   **Operação de Transporte**

Uma **operação de transporte** é realização do transporte em si. Como
características desta operação, temos: um **tipo de carga;** um
**modal;** o **preço** do serviço, em R\$; e o **caminho** a ser
percorrido entre os municípios de origem e destino. O preço do serviço é
determinado, por sua vez, pela **quantidade do produto** a ser
transportado, em ton, a **distância** entre a origem e o destino, em km,
pelo **preço unitário** da operação, em R\$/(km.unidade) e pelas
**tarifas** adicionais, quando houver. A unidade de medida do preço pode
ser o quilograma, o litro, container ou outro tipo de medida.
&nbsp;
-   **Rota**

A **rota** é o **caminho** percorrido na operação de transporte do
**município** A até o município B.Ao percorrer a rota, a operação de
transporte pode se utilizar de mais de um **modal** disponível. A partir
do caminho é possível obter a **distância total** entre os dois pontos,
bem como o **tempo de transporte** dado o modal utilizado.
&nbsp;
-   **Município**

O **município** é uma localidade geográfica situada em um **estado** e
**país** específico. Um município é caracterizado pelo seu **nome** e as
coordenadas de **latitude** e **longitude** de seu centróide. Para
simplificar o problema, a distância entre dois municípios a ser
considerada será a distância geodésica entre os seus centros. Como as
coordenadas são expressas em graus, devemos utilizar um fator de
conversão de grau para quilômetros para obtermos o resultado.
&nbsp;
-   **Estado, Condado, ou Região Administrativa**

Um **Estado, Província, Condado ou outra divisão administrativa
regional** é uma subdivisão territorial de um **país** que contém um ou
mais municípios. Um estado é caracterizado pelo seu **nome** e o
**país** a que pertence.
&nbsp;
-   **País**

Um **país** é uma região geográfica considerada o território físico de
um ou uns Estado soberano(s), ou de uma menor ou antiga divisão política
dentro de uma região geográfica. Um país é caracterizado por seu
**nome** e o **continente** a que pertence. O Brasil pode ou não ter
**acordo comercial** com o país de destino.

&nbsp;

### Cartões CRC

|**Classe**|Embarcador|
| --- | --- |
|**Responsabilidades**|**Colaborações**|
|produto|Município|
|quantidade|Estado|
|custo|País|


&nbsp;

|Classe|Modal|
| --- | --- |
|Subclasses:|Rodoviário, Aquaviário/Aéreo|
|Responsabilidades|Colaborações|
|preço||
|capacidade||
|velocidade||

&nbsp;

|Classe|Modal Rodoviário|
| --- | --- |
|Superclasse:|Modal|
|Responsabilidades|Colaborações|
|preço||
|capacidade||
|velocidade||
|pedágio||
|tem pedágio||

&nbsp;

|Classe|Modal Aquaviário/Aéreo|
| --- | --- |
|Superclasse:|Modal|
|Responsabilidades|Colaborações|
|preço||
|capacidade||
|velocidade||
|tarifa do terminal||

&nbsp;

|Classe|Operacao de Transporte|
| --- | --- |
|Responsabilidades|Colaborações|
|preço total|Embarcador|
|preço unitário|País|
|rota||
|tipo de carga||

&nbsp;

|Classe|Rota|
| --- | --- |
|Responsabilidades|Colaborações|
|origem|Municipio|
|destino|Modal|
|distância||
|tempo de percurso||
|caminho||

&nbsp;

|Classe|Municipio|
| --- | --- |
|Responsabilidades|Colaborações|
|nome|Pais|
|latitude||
|longitude||

&nbsp;

|Classe|Estado|
| --- | --- |
|Responsabilidades|Colaborações|
|nome|País|

&nbsp;

|Classe|Pais|
| --- | --- |
|Responsabilidades|Colaborações|
|nome||
|continente||
|tem acordo comercial||

