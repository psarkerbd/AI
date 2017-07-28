
# coding: utf-8

# In[ ]:

# Author: Pranta Sarker
# BFS


# In[ ]:

# lst = [1 , 4 , 6 , 7];
# stack = lst;
# stack.append(10);
# print stack
# stack.pop();
# print stack;

# queue = stack;
# queue.append(30);
# print queue;
# queue.pop(0);
# print queue;


# In[ ]:

from __future__ import print_function;

graph = {};
visited = set();
queue = [];
path = [];
cost = {};
par = {};

def init(node):
    for i in range(1 , node+5):
        par[i] = 0;

def BFS(s):
    global visited;
    global graph;
    global cost;
    if visited is None:
        visited = set();
    visited.add(s);
    cost[s] = 0;
#     print('queuelen = ' , len(queue));
#     print("in queue = " , s);
    queue.append(s);
    while(len(queue) > 0):
#         print('queuelen = ' , len(queue));
        u = queue.pop(0);
#         print("in queue = " , u);
#         print('queuelen = ' , len(queue));
#         print("u = " , u);
        tovisit = (set(graph[u]) - visited);
        for i in tovisit:
            queue.append(i);
            cost[i] = cost[u] + 1;
            par[i] = u;
            visited.add(i);
#             print('v = ' , i);


def BFS_paths(start, goal):
    global par;
    #print("par = " , par , end='\n');
    if(start == goal):
        path.append(goal);
    elif(par[goal] == 0):
        print('No path');
    else:
        BFS_paths(start, par[goal]);
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

node = input("Enter number of Node: ");
edge = input('Enter number of Edges: ');

for i in range(edge):
    a , b = raw_input().split(' ');
    x = int(a);
    y = int(b);
    graph.setdefault(x , []).append(y);
    graph.setdefault(y , []).append(x);
print('Detail:');
for i in range(1 , node+1):
    print('for node ' , i , ': ' , end=' ');
    for j in range(len(graph[i])):
        print(graph[i][j] , end=' ');
    print('');

startNode = input("Enter the Starting Node: ");

finalNode = input("Enter the Final Node: ");

init(node);

BFS(startNode);

# print(cost , end=' ');

if(finalNode in visited):
    BFS_paths(startNode, finalNode);
    print("Connected!\nCost from" , startNode, 'to', finalNode ,'is:' , cost[finalNode]);
    print("Path:");
    show_path();
else:
    print("Not Connected");

