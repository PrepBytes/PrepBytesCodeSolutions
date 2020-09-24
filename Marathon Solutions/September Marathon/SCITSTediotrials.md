#### Approach(GRAPH) [Accepted]

This problem can be thought of as a graph problem. 
The very first step is to compute how many different countries are there.
For this, we apply Depth First Search to calculate how many different connected components are present in the graph where the vertices are represented by the people and the people from the same country form one connected component. 

    def explore(u,d,l,visited):
      visited[u]=1
      l.append(u)
      for i in d[u]:
        if visited[i]==0:
          explore(i,d,l,visited)

    def connect(d,visited):
      l=[]
      ans=[]
      for i in d:
        if visited[i]==0:   
          explore(i,d,l,visited)
          ans.append(l)
          l=[]
        
    return(ans)

so len(ans) gives us the Number of components of graph.  
After we get how many connected components are present, say M, we just need to calculate the number of ways of selecting two persons from two different connected component. 

#### Aproach 1:(TIME LIMIT EXCEEDED)
Let us assume that component i contains Mi people. So, for the number of ways selecting two persons from different components, 
we simply iterate through that final list we got from DFS:

Algorithm:

    def calculate(ans):
        n=len(ans)  
        p=0
        for i in range(n-1):
            for j in range(i+1,n):
                p+=len(ans[i])*len(ans[j])
Complexity analysis:

O(|n|+|e|):Complexity of DFS , n and e are no of vertices and edges.
Time complexity : O(N*(N-1)) + O(|n|+|e|). Assume that N is the Number of components , n and e are no of vertices and edges
                  Since O(N*(N-1))> O(|n|+|e|)

                 T(n)=O(n*(n-1)) 
Thus due to high complexity this algorithm gives T.L.E in large Test Cases.
So we need to optimize the last part.

#### Aproach 2:(ACCEPTED)

Let us assume that component i contains Mi people. So, for the number of ways selecting two persons from different components, 
we subtract the number of ways of selecting two persons from the same component from the total numbers of ways of selecting two persons i.e.

Ways = N choose 2 - (∑(Mi Choose 2) for i = 1 to M)

Algorithm:

    def calculate(ans):
        n=len(ans)
        s=(n*(n-1))//2

        for i in range(n1):
            n=len(l[i])
            s-=(n*(n-1))//2
        print(s)


                   
Complexity analysis:

Time complexity : O(n) + O(|n|+|e|). Assume that N is the Number of components , n and e are no of vertices and edges .


