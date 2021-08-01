--Criação do keyspace (banco de dados) com propriedades de replicação:
CREATE KEYSPACE fenda_biquini WITH replication = {'class':  'SimpleStrategy', 'replication_factor': 1};

-- usa o keyspace para não ter que fazer referencia a ele durante todo o projeto:
use fenda_biquini; 

--cria coluna clients:
CREATE COLUMNFAMILY clients (name TEXT PRIMARY KEY, age INT);

--Valida a coluna:
SELECT * FROM clients;
--Resultado:  
--name | age
------+-----
--(0 rows)

--Inserindo dados:
INSERT INTO clients (name, age) VALUES ('Rodglins', 38);

--Inserindo com JSON:
INSERT INTO clients JSON '{"name": "Zé Colméia"}';

--consulta TIMESTAMP:
SELECT age, WRITETIME(age) FROM clients;

--sintaxes de consulta:
SELECT * FROM clients WHERE name ='Rodglins';

--consulta retorno como JSON:
SELECT JSON * FROM clients;
SELECT JSON * FROM clients WHERE name ='Rodglins';

--Atualizando:
UPDATE clients SET age=33 WHERE name='Zé Colméia';

--Alterando colunas:
ALTER COLUMNFAMILY clients ADD hobby text;

--Atualizando com a nova coluna:
UPDATE clients SET hobby='Procurar mel' WHERE name='Zé Colméia';

--fazendo consulta com os WRITETIME:
SELECT age, WRITETIME(age), hobby, WRITETIME(hobby FROM clients;
SELECT age, WRITETIME(age), hobby, WRITETIME(hobby) FROM clients WHERE name='Zé Colméia';

--deletar um registro:
DELETE FROM clients WHERE name='Rodglins';

--visualiza o esquema do banco de dados detalhado:
SELECT * FROM system_schema.columns WHERE keyspace_name='fenda_biquini';