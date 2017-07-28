
# coding: utf-8

# In[ ]:

# Graph Traverse
# By: dictionary


# Trial

from __future__ import print_function;

node = 3;
edge = 3;

adjlist = {}; # empty dictionary

for i in range(1 , edge+1): # 1-base indexing 
    x , y = raw_input().split(' ');
    
    a = int(x);
    b = int(y);
    # use setdefualt to make a list on defult dictionary key
    adjlist.setdefault(a , []).append(b);
    adjlist.setdefault(b , []).append(a); # for directed graph just comment this line

for i in range(1 , node+1): # node start from 1
    print('node %d is connected with: ' % i , end=' ');
    print(adjlist[i]);


# In[ ]:

#-------------------------------------------------------------------------------------------#


# In[4]:

# Main code start from here.......
# Graph traverse by dictionary

from __future__ import print_function

node = input('Enter number of node: ');
edge = input('Enter number of edge: ');

adjList = {} # empty dictionary

for i in range(1 , edge+1):
    x = input('Enter first node: ');
    y = input('Enter second node: ');
    
    adjList.setdefault(x , []).append(y);
    adjList.setdefault(y , []).append(x);
    
for i in range(1 , node+1):
    print('node %d is connected with: ' %i , end = '');
    print(adjList[i] , end='\n');

