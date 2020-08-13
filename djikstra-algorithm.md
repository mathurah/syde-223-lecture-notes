# Djikstra's Algorithm 
## Properties 
Weight of edge should be positive<br/>
Distance to a node itself is defined as 0<br/>
## Input 
Graph (such as an adjacency matrix)<br/>
A start Node<br/>
An end Node<br/>
## Output 
The shortest path from start Node to end Node 

**The values of the nodes are stored in the form of three *arrays***
1. Whether we have found the shortest distance from startNode to each node in the graph.
2. The current known shortest distance from startNode to each node. 
3. The current known shortest path from startNode to each node in the format 

Essentially, we need to look to our matrix so we can continue to fill out this table.  
![](images/Screen Shot 2020-08-12 at 7.08.55 PM.png)

**Steps**
1. Initialize the three array values using information about the start Node from its adjacent nodes. 
2. Among the nodes whose shortest distance is yet to be found, find the one that is connected to the startNode and call it tempNode. 
3. If not found, no one is connected to startNode and thus there is no path from startNode to endNode. 
4. If found, then this tempNode's shortest path is found. 
5. If tempNode is the endNode, terminate. 
6. Check if the old best paths from startNode to each pending nodes can be improved by going from startNode to this tempNode first and then from tempNode to the pending nodes. If so, improve old routes. 

