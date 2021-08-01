//Simulando como se estivesse criando uma rede social:
CREATE(:Client {name : "Rodglins", age: 30, hobbies: ['Bike, Running']})

//Clicar na seta para executar.
//Resultado: Added 1 label, created 1 node, set 3 properties, completed after 50 ms.

//Consulta:

MATCH (rodglins) RETURN rodglins;
//Resultado *(1) Client(1) Rodglins
//Resultado: <id>:0 age:30hobbies:Bike, Running name:Rodglins

//Forma de criar os nos com relacionamentos:
//cria um nó, com relacionamento  e cria outro nó
CREATE (:Client {name: "Zé Colmeia", age: 63, hobbies: ['Comer mel']}) -[:Bloqueado]->(:Client {name: "Catatau", hobbies: ['Ver o amigo Zé Colmeia']})

//Resultado: Added 2 labels, created 2 nodes, set 5 properties, created 1 relationship, completed after 23 ms.

// -[]-> Define um relacionamento
// :Bloqueado //é uma label, opcional

//Listagem(verificar como esta a estrutura):
MATCH (todos) RETURN todos;

//Cria um objeto sem propriedades, com cor diferente pois não compartilha da mesma label:
CREATE (:Object)
//Resultado: Added 1 label, created 1 node, completed after 10 ms.

//Relacionamento entre dois nos que ja existem:
MATCH (rodglin:Client {name: "Rodglins"}), (zecol:Client {name:"Zé Colmeia"}) CREATE (rodglin) -[:Bloqueado]->(zecol)
//Resultado: Created 1 relationship, completed after 10 ms.

//Exclusão do relacionamento(rodglins resolveu desbloquear Zé Colmeia da rede social):
MATCH (rodglin:Client {name: "Rodglins"})-[relaciona:Bloqueado]-() DELETE relaciona
//Resultado: Deleted 1 relationship, completed after 44 ms.
//-() nó anonimo, exclui tds os relacionamento com a label

//------

//Deleta o nó
MATCH (rodglin:Client {name: "Rodglins"}) DELETE rodglin;
//Resultado: Deleted 1 node, completed after 108 ms.

//-----

//Atualizando o dado de um nó (SET):
MATCH (catatau:Client {name: "Catatau"}) SET catatau.age = ['63'];
//Resultado: Set 1 property, completed after 137 ms.

//Os nos podem ter propriedade e os relacionamentos podem ter, alem da label, as propriedades. O fluxo é o mesmo, com a variavel que atribuiu ao relacionamento.
//Pode alter a label, ou criar a label, ou remover a label.

//Atualizando a label:
MATCH(catatau:Client {name: "Catatau"}) SET catatau:Client_Premium
//Resultado: Added 1 label, completed after 18 ms.