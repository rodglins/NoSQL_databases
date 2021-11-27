Instalados:
jdk-11.0.13_windows-x64_bin.exe
neo4j-community-4.3.7-windows.zip (arquivos copiados para a pasta: arquivos de programas)

Iniciando o servidor:

--------------------

Resultado:

C:\Program Files\neo4j-community-4.3.7>bin\neo4j console
Directories in use:
home:         C:\Program Files\neo4j-community-4.3.7
config:       C:\Program Files\neo4j-community-4.3.7\conf
logs:         C:\Program Files\neo4j-community-4.3.7\logs
plugins:      C:\Program Files\neo4j-community-4.3.7\plugins
import:       C:\Program Files\neo4j-community-4.3.7\import
data:         C:\Program Files\neo4j-community-4.3.7\data
certificates: C:\Program Files\neo4j-community-4.3.7\certificates
licenses:     C:\Program Files\neo4j-community-4.3.7\licenses
run:          C:\Program Files\neo4j-community-4.3.7\run
Starting Neo4j.
2021-11-26 14:42:14.988+0000 INFO  Starting...
2021-11-26 14:42:28.253+0000 INFO  ======== Neo4j 4.3.7 ========
2021-11-26 14:42:37.352+0000 INFO  Initializing system graph model for component 'security-users' with version -1 and status UNINITIALIZED
2021-11-26 14:42:37.435+0000 INFO  Setting up initial user from defaults: neo4j
2021-11-26 14:42:37.487+0000 INFO  Creating new user 'neo4j' (passwordChangeRequired=true, suspended=false)
2021-11-26 14:42:37.531+0000 INFO  Setting version for 'security-users' to 3
2021-11-26 14:42:37.551+0000 INFO  After initialization of system graph model component 'security-users' have version 3 and status CURRENT
2021-11-26 14:42:37.576+0000 INFO  Performing postInitialization step for component 'security-users' with version 3 and status CURRENT
2021-11-26 14:42:40.367+0000 INFO  Bolt enabled on kubernetes.docker.internal:7687.
2021-11-26 14:42:44.794+0000 INFO  Remote interface available at http://localhost:7474/
2021-11-26 14:42:44.802+0000 INFO  Started.

-------------------

Para acessar o Neo4j:
acesso pelo browser: http://localhost:7474/

-----

origem dos dados: 
https://www.kaggle.com/ajaypalsinghlo/world-happiness-report-2021

Dados com tratamento do header: https://raw.githubusercontent.com/rodglins/NoSQL_databases/master/Neo4j/Desafios/Desafio1_dataset_world-happiness-report-2021.csv

----

// Carrega o  dataset:
// Cria um index:
// Cria relacionamentos entre países da mesma região geográfica:
// Filtra países e regiões:
// Count all nodes
// Count all relationships
// Verifica o status da base de dados:


------------																																											
Referencias:
https://neo4j.com/docs/operations-manual/current/installation/windows/
https://neo4j.com/docs/operations-manual/