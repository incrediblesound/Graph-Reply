Graph Reply
===========
Graph reply is my first attempt at a REPL style program.


WRITE DATA
----------

> new person 
Creates a node with label "person"

> link person manager
Creates an edge from person (source) to job (target), the nodes are created if they do not exist

> wn person
[(person).data]> John
The command wn (write node) sets the data attribute of node "name".
Here we set the data attribute of person to "John".

> wl person manager
[(person->manager).data]> has job
The command wl (write link) sets the data attribute of the edge from person to manager, in this case it is given the value "has job".

READ DATA
---------

> id 0
{ id: 0, "name": "person", "data": "John" }
Use the id command to get a node label by id.

> rn person
{ id: 0, "name": "person", "data": "John" }
Use the rn (read node) command to get node information by label

> rl person manager
{ "source": "person", "target": "manager", "data": "has job" }
Use the rl (read link) command to get the edge information for two nodes

> out person
[ { "id": 1, "name": "manager" } ]
The command out returns an array of nodes connected to the given node by outgoing edges.

> in manager
[ { "id": 0, "name": "person" } ]
The command in returns an array of nodes connected to the given node by incoming edges.

> getn
[node.data]> John
[ { id: 0, "name": "person", "data": "John" } ]
The command getn (get node) asks for data and then returns all nodes with the given data.

> getl
[link.data]> has job
[ [0, 1] ]
The command getl (get link) asks for data and then returns a pair of ids where the first id is the source and the second the target of an edge with the given data.

> link fish bird
> link bird cat
> path fish cat
{ "hasPath": true, "path": [ 0, 1, 2 ] }
The command path takes two nodes as arguments and returns the first path it finds through the graph via outgoing edges from the first node to the second, or returns false if no path exists.

Disk Storage
----

> save my_graph
The save command converts the state of the graph into graph-reply commands and saves them to a file with the name given as input. The above command saves the graph in the file my_graph.gph.

> load my_graph
The load command loads a previously saved graph into memory from a file.