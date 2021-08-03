//mongoDB:

//lista as bases:
show databases ()

//cria uma base de dados chamada loja:
use loja()

//lista a tabela produtos:
db.produtos.find()

//insere linha na tabela produtos:
db.produtos.insert({ codigo: "01", descricao:"caneta"}) () 
db.produtos.insert({ codigo: "02", descricao:"lapis", cor: "vermelha"})
db.produtos.insert({ codigo: "03", cor: "azul"})

//conectando ao mongo local:
mongo --host 127.0.0.1:27017 -p dio -u dio

//listando as databases:
show databases

//Criando arquivo docker-compose.yml: para acesso via docker

//criando a imagem com base no arquivo: docker-compose.yml
docker-compose up -d

//listando os container:
docker container ps

//conectando ao mongo local:
mongo --host 127.0.0.1:27017 -p dio -u dio

//listando as databases:
//show databases

//Para executar o mongo em interface grafica:
//https://robomongo.org
//realizar cadastro, baixar e instalar
//Create connection>Direct Connection/dio/localhost>auth /admin/dio/dio/Test>Close>Salvar

//MongoDB Cloud
mongosh "mongodb+srv://cluster0.jmcys.mongodb.net/myFirstDatabase" --username rodglins
show databases

//MongoDB Compass
mongodb+srv://rodglins:pass@cluster0.jmcys.mongodb.net/myFirstDatabase?retryWrites=true&w=majority

//Operações e manipulação de dados:
show databases;

//Criando ou acessando a base de dados:
use rodglins

//Criando uma collection:
db.createCollection("test", {capped: true, max: 2, size: 2});

//Exibindo as collections:
show collections;

//Inserindo dados na colletcion IMPLICITA:
db.test.insertOne({"nome": "Teste 1"});
db.test.insertOne({"nome": "Teste 2"});
db.test.insertOne({"nome": "Teste 3"}); //qdo insere a 3, a 1 expira.

//Exibindo as collections
db.test.find({});

//Inserindo dados na colletcion EXPLICITA:
db.test1.insertOne({"age": 10});
db.test1.insertOne({"age": 10});
db.test1.insertOne({"age": 10});
db.test1.insertOne({"age": 10});
db.test1.insertOne({"age": 10});

//Exibindo as collections
db.test1.find({});

//Inserindo dados de forma IMPLICITA:
db.clients.insertOne([{"name" : "Zé Colméia", "age" : 63},{"name": "Catatau"}])
db.clients.insertOne([{"name":"Rodrigo", "age": 30}])
db.clients.insertOne({"name": "Catatau2", "age": 30})
db.clients.insertOne({"name": "Rodrigo", "age": 38})

//Exibindo os documentos:
db.clients.find({});

//Atualizando um documento:
db.clients.updateOne({ _id: ObjectId("61086a0a29220d33e0472acd")}, {$inc: { age: 40 } })
db.clients.updateOne({ _id: ObjectId("61095a9462a6c7110b43bd7e")}, {$set :{"age" : 38}})
db.clients.updateMany({"age" : 40}, {$set :{"age" : 63}})

//Buscas:
db.cliets.find({"age": 63})
db.clients.find({"age": 63, "name": "Catatau"})

//primeiro que tiver o parametro
db.clients.find({"age": 63}).limit(1)

//busca por intervalo IN:
db.clients.find({"age": {$in: [30,63]}})

//busca com parametro OU:
db.clients.find({$or: [{"name" : "Catatau"},{"name" : "Catatau2"}]})
db.clients.find({$or: [{"name" : "Catatau"},{"age" : 63}]})

//Busca operador LT (ex: cliente com idade abaixo de um valor específico):
db.clients.find({"age" : {$lt: 63}})

//Busca operador LTE (ex: cliente com idade menor ou igual ao valor):
db.clients.find({"age" : {$lte: 63}})

//Exclui apenas o primeiro que recuperar
deleteMany - exclui tudo que recuperar

//Apagando um documento:
db.clients.deleteOne({"age": 30})
db.clients.deleteOne({ _id: ObjectId("6109576f62a6c7110b43bd7d")})
//Resultado: { acknowledged: true, deletedCount: 1 }

//Apagando vários documentos:
db.clients.deleteMany({"age": 38})
//Resultado: { acknowledged: true, deletedCount: 2 }


//Usando Robo 3T 1.4 conectado ao SRV do Mongo.
//Script para popular a collection, inserindo 10.000 registros:
for(var i=0; i< 10000; i++){
db.clients.insert({name: "Cliente" + i, age:i});
}

//Verificando a quantidade de registros na collection:
db.getCollection('clients').count({})
db.getCollection('clients').find({})
db.getCollection('clients').find({_id: ObjectId("61096dd2ba2ad1ba26b4c680")}).explain(true)

//realizando a indexação:
db.getCollection('clients').createIndex({name:1}, {"name": "idx_name"})

//buscando um documento:
db.getCollection('clients').find({name: "Cliente0"}).explain(true)


//Agregações:
//https://cloud.mongodb.com/
//Database Deployments>Load Sample Dataset>Load

//realizando a contagem da coleção restaurants:
db.getCollection('restaurants').count({})

//mostra todos os campos para um determinado valor:
db.getCollection('restaurants').distinct({"cuisine"})

//As pipelines mais básicas fornecem elementos "filtros" e "operadores". Operadores $group, $addFields, entre outros.

//$group:
//agrupar dados de acordo com campo, contar, media, valor max, valor min, etc.
db.getCollection('restaurants').aggregate([{$group: {_id: "$cuisine", total: {$sum: 1}}}])
//cada um que encontra do grupo ele adiciona um contador.

//$addFields
//consegue adicionar para o resultado um novo campo sem alterar a collection de origem:
db.getCollection('restaurants').aggregate([{$addFields : {"teste": true}}])

//Funções $sum, $avg, $max, $min

//max:
//maior id dentro do grupo:
db.getCollection('restaurants').aggregate([{$group: {_id: "$cuisine", total: {$sum: 1}, id_maximo: {$max: "$restaurant_id"} }}])

//min:
//menor id dentro do grupo:
db.getCollection('restaurants').aggregate([{$group: {_id: "$cuisine", total: {$sum: 1}, id_maximo: {$min: "$restaurant_id"} }}])

//avg
//somente funciona no campo tipo number


//Operadores lógicos: $and, $or, $not $nor

//AND - recupera resgistros com determinado critério:
db.getCollection('restaurants').aggregate([{$match : {$and:[{cuisine: "American"}, {borough: "Brooklyn"}]}}])

//OR 
db.getCollection('restaurants').aggregate([{$match : {$or:[{cuisine: "American"}, {borough: "Brooklyn"}]}}])

//NOR
db.getCollection('restaurants').aggregate([{$match : {$nor:[{cuisine: "American"}, {borough: "Brooklyn"}]}}])

//Operadores de comparação:
//>-Maior que. No mongo: $gt
//<-Menor que, no mongo: $lt
//<>-Diferente de, no mongo: $nte
//<=-Menor ou igual, no mongo $lte
//>=Maior ou igual, no mongo $gte