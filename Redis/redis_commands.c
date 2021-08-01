//Definindo uma chave:
SET user1:name "Rodglins"

//Recuperando a inforamção, tem q conhecer o nome da chave:
GET user1:name

//Adicionando um JSON para a estrutura:
SET user '{"name": "Zé Colméia", "age": 63}'

//Consultando a chave:
GET user

//Especificar tempo para a chave expirar:
SET user2:name "Catatau" EX 10
//Consutando:
GET user2:name
//"Catatau"
//Após 10 segundos:
//(nil) #deixa de existir

//Outra forma de verificar se a chave existe (retorna 0 se não existe):
EXISTS user2:name

//Manipulando colections, lists, sets, hashset:

//inserindo dado numa lista:
LPUSH user1:hobbies "Pedalar"
LPUSH user1:hobbies "Cinema"

//acessando o dado por indice:
LINDEX user1:hobbies 0
LINDEX user1:hobbies 1

//listando tds valores da lista ou intervalo:
LRANGE user1:hobbies 0 1 //recupera o registo 0 e 1
LRANGE user1:hobbies 0 0 //recupera apenas o registro 0

//IDENTIFICAR O TIPO DE VALOR DENTRO DE UMA CHAVE:
TYPE user1:name
TYPE user1:hobbies

//tempo de expiração de uma chave:
TTL user1:name //sem expiração retorna -1

SET user2.name "Catatau" EX 60
//Mostra contagem regressiva, ou expirado retorna -2
TTL user2.name 
//Contagem regressiva em milisegundos
PTTL user2.name 

//Apagando o registro:
DEL user2.name