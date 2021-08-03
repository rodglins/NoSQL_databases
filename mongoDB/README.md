# MongoDB
**Intro MongoDB**

Código aberto
Alta performance
Schema-free
Utiliza bjson(json) para armazenamento dos dados
Suporte a indices (fazer consultas complexas, garantir integridade)
Auto-Sharding (escalamento horizontal, permite vertical tendo replicas de leitura. Facilmente consegue colocar maquinas novas para operar com ele)
MapReduce (ferramenta de consutla e agregação, precisa processar grande volume de dados e ter um resultado)
GridFS (armazenamento de arquivos, qdo precisar fazer upload, precisa salvar arquivo de origim)

Rica linguagem de consulta, para fazer quase td dentro do banco de dados.

**Estruturação**
Document ==> Tupla/Registro (menor unidade do mongo, documento auto contido e auto-descritivo)
Collection ==> Tabela (tds nossos documentos, esquema livre, aplioca aos docuemtnso a auto-descrição, varios tipos de doc)
Embedding/linking ==> Join (dentro do documentos com a subestrutura dentro dele.)

**Quando usar:**
Grande volume de dados. (BigData) 
Dados nao necessariamente estruturados (inicia o bd mesmo sem esquema)

**Qdo não usar:**
-Necessidade de relacionamento/joins 
-propriedades ACID e transacoes sao importantes
-Curiosodade: diversas entidades de pagamento nao homologam sistemas cujos dados financeiros dos clientes nao estejam em bancos de dados relacionais tradicionais.

Empresas que usam: Linkedin, MTV, Globo

-----

**Instalando MondoDB utilizando Docker:** 
crie , implemente, teste em ambiente separado , ex. nuvem, containerização.
Docker compose: arquivo, especifica propriedades dentro de cada container, consegue fazer links entre diferentes containeres, p q tenha todo sistema da aplicação para subir com tds dependencias.

**Docker:**
docs.docker.com/compose/
hub.docker.com

-imagem oficial no dockerhub:
-Pesquisar mongo 

-Criando arquivo docker-compose.yml:

-criando a imagem com base no arquivo: docker-compose.yml
docker-compose up -d

-listando os container:
docker container ps



**Manual:**
www.quackit.com/mongodb/tutorial/

dados: C:\Program Files\MongoDB\Server\5.0\data\
logs: C:\Program Files\MongoDB\Server\5.0\log\

add patch: C:\Program Files\MongoDB\Server\5.0\bin

Prompt>mongo



----



-Para executar o mongo em interface grafica:
-https://robomongo.org
-realizar cadastro, baixar e instalar
-Create connection>Direct Connection/dio/localhost>auth /admin/dio/dio/Test>Close>Salvar

-----

**MongoDB Cloud**
MongoDB ATLAS
https://cloud.mongodb.com/

Create cluster (Deploy a cloud database) >> free>> >>azure>>create cluster
command line tool (instruções)
nerwork access>add ip address>add current ip address>confirm

Databases>Database Deployments>Cluster0>Connect

download mongosh
Add <your mongosh's download directory>/bin to your $PATH variable
mongosh "mongodb+srv://cluster0.jmcys.mongodb.net/myFirstDatabase" --username rodglins

show databases



----

**MongoDB Compass**

Acessar MongoDB Cloud>> Connect to Cluster0>>Connect you application>>copiar connection string>>

trocar a senha pela sua, trocar usuario pelo seu login no mongo cloud:
mongodb+srv://usuario:senha@cluster0.jmcys.mongodb.net/myFirstDatabase?retryWrites=true&w=majority

----

**Schema Design**

-**Embedding:** Documentos autocontido  (tds dados dentro do documento, sem referencia para outro documento)

Prós:
-Consulta informações em uma unica query
-Atualiza o registro em um unica operação
-Atomicidade
Contras:
-Limite de 16 mb por documento

-**Referência:** Documentos com dependencia de outros documentos ou collections
Prós:
-Documentos pequenos
-Não duplica informações
-Usado quando os dados nao sao acessados em todas as consultas. Se precisar acessar a referencia não é indicada.
Contras: Duas ou mais queries ou utilização do $lookup

Recomendações de acordo com os relacionamentos:
One-to-one: prefira atributos chave-valor no documento

Recomendações de acordo com relacionmentos:
One-to-few: prefira embendding
-indicado quando não tera muita informação.

Recomendações de acordo com os relacionamentos:
One-to-many e many-to-many: prefira referencia

-------

**Schema Design**

https://www.mongodb.com/blog/post/building-with-patterns-a-summary

---------

**Boas práticas:**

Evite documentos muito grandes
Use nome dos campos objetivos e curtos
Analise as suas queries utilizando explain()
Atualize apenas os campos alterados
Evite negações em queries

Lista/Arrays dentro dos documentos nao pode crescer sem limite. Pode ser um problema para a performance.

-------

**BSON:** 
-É uma serialização codificada em binario de documentos semelhantes a JSON
-Contem extensões que permitem a representação de tipos de dados que não fazem parte da especificação JSON. Por exemplo, BSON tem um tipo Date, ObjectId

----

Info:
https://docs.mongodb.com/manual/tutorial/query-documents/

-------

**-Performance e índices:**

-Relaciona tds os documentos e informações. Dar direcionamento ao banco onde está a informação.

-Usando Robo 3T 1.4 conectado ao SRV do Mongo.

----

**-Agregações:**
-é o procedimento de processar dados em uma ou mais etapas, onde o resultado de cada etapa é utilizado na etapa seguinte, de modo a retornar um resultado combinado.

-2 tipos, pipeline e proposito unic:

Agregações de proposito unico:
count 
distinct
Elas não permitem as customizações das agregações utilizando pipeline.

-importar um banco de dados de teste para o cluster.

-MongoDB Cloud
-MongoDB ATLAS
-https://cloud.mongodb.com/
-Database Deployments>Load Sample Dataset>Load
