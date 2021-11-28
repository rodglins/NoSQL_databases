



Utilizando dois arquivos CSV:


MATCH (n) DETACH DELETE n
Deleted 306 nodes, deleted 323 relationships, completed after 592 ms.


LOAD CSV WITH HEADERS FROM "https://raw.githubusercontent.com/rodglins/NoSQL_databases/master/Neo4j/Desafios/Desafio1_dataset_world-happiness-report-2021_2.csv" AS row
CREATE (n:Paises)
SET n = row,
n.Ladder_score = toInteger(row.Ladder_score), n.Standard_error_of_ladder_score = toInteger(row.Standard_error_of_ladder_score), n.upperwhisker = toInteger(row.upperwhisker), n.lowerwhisker = toInteger(row. lowerwhisker), n.Logged_GDP_per_capita = toInteger(row.Logged_GDP_per_capita),n.Social_support = toInteger(row.Social_support), n.Healthy_life_expectancy = toInteger(row.Healthy_life_expectancy), n.Freedom_to_make_life_choices = toInteger(row.	Freedom_to_make_life_choices), n.Generosity = toInteger(row.Generosity), n.Perceptions_of_corruption = toInteger(row.Perceptions_of_corruption), n.Ladder_score_in_Dystopia = toInteger(row.Ladder_score_in_Dystopia), n.Explained_by_1 = toInteger(row.Explained_by_1), n.Log_GDP_per_capita = toInteger(row.Log_GDP_per_capita), n.Explained_by_2 = toInteger(row.Explained_by_2), n.Social_support = toInteger(row.Social_support), n.Explained_by_3 = toInteger(row.Explained_by_3), n.Healthy_life_expectancy = toInteger(row.Healthy_life_expectancy), n.Explained_by_4 = toInteger(row.Explained_by_4)
Resultado:
Added 149 labels, created 149 nodes, set 5513 properties, completed after 8463 ms.

LOAD CSV WITH HEADERS FROM "https://raw.githubusercontent.com/rodglins/NoSQL_databases/master/Neo4j/Desafios/Desafio1_regiao.csv" AS row
CREATE (n:Regiao)
SET n = row
Resultado:
Added 10 labels, created 10 nodes, set 20 properties, completed after 529 ms.

CREATE INDEX ON :Paises(Country_id)
Added 1 index, completed after 137 ms.

CREATE INDEX ON :Paises(Country_name)
Added 1 index, completed after 8 ms.

CREATE INDEX ON :Regiao(id_regiao)
Added 1 index, completed after 11 ms.

MATCH (p:Paises)
WITH p
MATCH (c:Regiao) 
WHERE c.id_regiao = p.id_regiao
CREATE (c)-[:PART_OF]->(p);
Created 149 relationships, completed after 246 ms.

MATCH (p:Paises)-->(c:Regiao)
RETURN p.Country_name as Country, collect(distinct c.Regional_indicator) as Regiao
Started streaming 149 records after 3 ms and completed after 102 ms.

MATCH (c:Regiao {Regional_indicator:"Latin America and Caribbean"})<--(p:Paises)
RETURN DISTINCT p.Country_name as Paises
Started streaming 20 records after 4 ms and completed after 11 ms.

MATCH (n) RETURN n
