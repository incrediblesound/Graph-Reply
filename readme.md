Graph Reply
===========
Graph reply is my first attempt at a REPL style program. To run, compile the source code and run the output file. You will be taken to a repl where you can type commands. To close the program enter the command "exit".
```shell
gcc reply.c -o reply
./reply
> new mynode
> save mygraph
> exit
```


WRITE DATA
----------
```code
> new person 
```
Creates a node with label "person"
```code
> link person manager
```
Creates a directed edge from person (source) to manager (target), the nodes are created if they do not exist
```code
> wn person
[(person).data]> John
```
The command wn (write node) sets the data attribute of a given node.
Here we set the data attribute of person to "John".
```code
> wl person manager
[(person->manager).data]> has job
```
The command wl (write link) sets the data attribute of the edge from person to manager, in this case it is given the value "has job".

READ DATA
---------
```code
> id 0
{ id: 0, "name": "person", "data": "John" }
```
Use the id command to get a node label by id.
```code
> rn person
{ id: 0, "name": "person", "data": "John" }
```
Use the rn (read node) command to get node information by label
```code
> rl person manager
{ "source": "person", "target": "manager", "data": "has job" }
```
Use the rl (read link) command to get the edge information for two nodes
```code
> out person
[ { "id": 1, "name": "manager" } ]
```
The command out returns an array of nodes connected to the given node by outgoing edges.
```code
> in manager
[ { "id": 0, "name": "person" } ]
```
The command in returns an array of nodes connected to the given node by incoming edges.
```code
> getn
[node.data]> John
[ { id: 0, "name": "person", "data": "John" } ]
```
The command getn (get node) asks for data and then returns all nodes with the given data.
```code
> getl
[link.data]> has job
[ [0, 1] ]
```
The command getl (get link) asks for data and then returns a pair of ids where the first id is the source and the second the target of an edge with the given data.
```code
> link fish bird
> link bird cat
> path fish cat
{ "hasPath": true, "path": [ 0, 1, 2 ] }
```
The command path takes two nodes as arguments and returns the first path it finds through the graph via outgoing edges from the first node to the second, or returns false if no path exists.

Disk Storage
----
```code
> save my_graph
```
The save command converts the state of the graph into graph-reply commands and saves them to a file with the name given as input. The above command saves the graph in the file my_graph.gph.
```code
> load my_graph
```
The load command loads a previously saved graph into memory from a file.
