# Jumli_Almashud_cyclic

--------------------------------------------------------------------------------------------------------------------------------------------------------------------

#How to Use

When the program runs, it will ask:

Enter number of vertices:

You enter the number of nodes. For example: 4 (for A, B, C, D)

Then it will ask you to enter the adjacency matrix row-by-row:

Row for A: 0 1 0 0
Row for B: 0 0 1 0
Row for C: 0 0 0 1
Row for D: 1 0 0 0

That represents:

A → B

B → C

C → D

D → A

(Which forms a cycle)

--------------------------------------------------------------------------------------------------------------------------------------------------------------------

#Sample Output

#With Cycle

DFS Output:

Cycle Detected using DFS: A B C D A

BFS Output:

Cycle Detected using BFS.
