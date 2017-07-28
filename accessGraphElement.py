
# coding: utf-8

# In[ ]:

# Author: Pranta Sarker
# Access the Graph Elements
# Bidirectional graph
# run on jupyter


# In[ ]:

from __future__ import print_function;

node = 3;
edge = 3;

graph = {}; # empty dictionary

for i in range(1 , edge+1):
    x , y = raw_input().split(' ');
    
    a = int(x);
    b = int(y);
    
    graph.setdefault(a , []).append(b);
    graph.setdefault(b , []).append(a);

# Traverse

for i in range(1 , node+1):
    print('node %d is connected with: ' %i , end=' ');
    print(graph[i] , end='\n');

print('');

# Access the elements

for i in range(1 , node+1):
    print('node %d elements are: ' %i , end=' ');
    for j in range(len(graph[i])):
        print(graph[i][j] , end=' ');
    print('');


# In[ ]:

print('#' * 70);


# In[25]:

# Directed Graph
# run on jupyter

from __future__ import print_function;

def init(adjlist , node):
    for i in range(1, node+1):
        adjlist[i] = [];

adjlist = {}; # empty dictionary

node = 3;
edge = 3;

init(adjlist , node); # initialization of dictionary, set empty for all nodes

for i in range(1 , edge+1):
    a , b = raw_input().split(' ');
    x = int(a);
    y = int(b);
    adjlist.setdefault(x , []).append(y);
    #adjlist.setdefault(y , []).append(x);

# Traverse

for i in range(1 , node+1):
    print('node %d is connected with: ' %i , end=' ')
    print(adjlist[i], end='\n');
    

print('-' * 40);

# Print the sorted adjacent list for a node

print('Soretd adjacent list:');

for i in range(1 , node+1):
    print('node %d is connected with: ' %i , end=' ');
    print(sorted(adjlist[i]), end='\n'); # sort the dictionary elements

