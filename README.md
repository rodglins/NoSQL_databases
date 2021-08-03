# NoSQL_databases
Breve resumo:



NoSQL

1970(BD Relacional)>>1998(NoSQL)>>2009(Reaparição NoSQL)

Intro
Pq surgiu em 2009 e ocupou liugar sginificativo. A internet hoje nunca foi imaginada como antes. Aumentou signifcamente dobra o volume de dados arm. a criacçaõ de aplicaçoes nao convencionais, necessidade de suprir demandas de aplicativos  escalaveis  alem da fliexibilizacao dos dados e armaz. fizessem que nosql surgissem para suprir demanda nao atendidas pelo sql.

Not Only SQL = NO SQL

o correto seria NoRel

--

BD NoSQL substitui os relacionais?
isso não ocorreu, continuam em plena execução, com suas vantagens e desvantagens.

diferenças:

Escalabilidade do Banco de dados relacional é vertical
Aumento da capacidade para um unico recurso
Precisa de upgrade, infla o hardware para suportar Mais processador, memoria e disco rigido. Existem alguns relacionais que escalam de forma horizonal, mySQL Cluster. Essas  replicas sao usadas para leitura de dados.

Escalabilidade do banco de dados NoSQL é horizontal. Particionando os dados (sharding) entre os nós é o mais conhecido. Nativamente são horizontais. 

Maior desempenho da aplicação, conforme a demanda, escalabilidade infinita, principalmente se estiver na nuvem. Pode escalar em determinados periodos, usando mais nós em maior demanda. Qdo não precisar faz o downgrade.

----

BD Relacional. estrutura rigida. precisa modelar e gerar cripts. tabelas, linhas, colunas, pf, fk. Consistencia maior e dados organizados. Linguagem sql de consulta. Usa o disco para performance.

--atomicidade (uma transacao por completo ou em caso de erro, rollback)
--consistencia (em total conformidade com os esquemas definicos)
--isolamento (uma transacao nunca interfere em outra transacao)
--durabilidade (uma vez q transacao concluida o dado jamais sera perdido)

---

BD NoSQL: Schema-free/schemaless. Menos garantia de consitstencia e ausencia de linguagem de consulta. Dificil ter linguagem para fazer a consulta. Cada banco tem uma linguagem. Usa o cluster e a rede para melhor performance.

--Não tem conceito de transacao, soemnte mongo
--abrem mao em disponibilidade e desempenho.

--Basically Avaible (prioridade na disponibilizacao de dados) 
Soft State ( nao precisa ser consistente o tempo todo)
Eventually Consistent (são consistentes em momentos determinados.

Caracteristicas e vantagens:

- Flexibilidade
- Escalabilidade
- Alta performance

Tipos de banco NoSQL

Variedade grande de tecnologias, com a semelhanca de sempre NoSQL:

Principais:
-MongoDB
-Redis
-Cassandra
-Neo4j

Tipos de bd nosql

-Documento Store(docuemntso podem ser json como qualquer estrutura de dados como xml)
-Key Value Store (utilizado na forma de cach, qde parte bd e ferraments de cach)
-Wide Column Store (bd orientado a colunas, é o que menos apresenta diferencas aos relacionais.
-Graph Store (inumefas formas como redes sociais e fraude)
