//mongoDB:

//Manual:
//www.quackit.com/mongodb/tutorial/

//dados: C:\Program Files\MongoDB\Server\5.0\data\
//logs: C:\Program Files\MongoDB\Server\5.0\log\

//add patch: C:\Program Files\MongoDB\Server\5.0\bin

//Prompt>mongo

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


