
# coding: utf-8

# In[1]:

# Author: Pranta Sarker
# Algorithm : DFS


# In[ ]:

from __future__ import print_function;

#global graph, visited;

graph = {};
visited = set();
par = {};
path = [];

def init(node):
    for i in range(1 , node+5):
        par[i] = 0;

def DFS(u):
    global graph;
    global visited;
    if visited is None:
        visited = set();
    visited.add(u);
    tovisit = (set(graph[u]) - visited);
    # subtraction between set elements, such as a={1, 2}, b={1, 2, 3}..
    # in that case above line work as: {1, 2} - {1, 2, 3} = {3}, which index = 0
    for i in tovisit:
        par[i] = u;
        DFS(i);
    return visited;

def dfs_paths(start, goal):
    global par;
    #print("par = " , par , end='\n');
    if(start == goal):
        path.append(goal);
    elif(par[goal] == 0):
        print('No path');
    else:
        dfs_paths(start, par[goal]);
        path.append(goal);
        
def show_path():
    global path;
    fl = False;
    for i in range(len(path)):
        if(fl == False):
            print(path[i] , end=' ');
            fl = True;
        else:
            print('->' , path[i] , end=' ');
    
    
node = input('Enter number of nodes: ');
edge = input('Enter number of edges: ');
    
print('Enter nodes:');

for i in range(edge):
    a, b = raw_input().split(' ');
    x = int(a);
    y = int(b);
    graph.setdefault(x , []).append(y);
    graph.setdefault(y , []).append(x);

# print('Detail:');
    
# for i in range(1 , node+1):
#     print('Node' , i , 'is connected with: ');
#     for j in range(len(graph[i])):
#         print(graph[i][j] , end=' ');
#     print('');

print('Connectivity Check:');

startNode = input('Enter the Start Node: ');
reachNode = input('Enter for which node you want to check connectivity: ');

init(node);

DFS(startNode);

if(reachNode in visited):
    print('Yes,' , startNode, 'and', reachNode, 'are Connected');
    print('Path: ');
    dfs_paths(startNode, reachNode);
    show_path();
else:
    print(startNode, 'and', reachNode, 'are Not Connected');
    print('No Path');


# In[ ]:



