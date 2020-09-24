#python3

def explore(u,d,l,visited):
  
  visited[u]=1
  l.append(u)
  for i in d[u]:
    if visited[i]==0:
      explore(i,d,l,visited)
def connect(d,visited):
  l=[]
  l1=[]
  for i in d:
    if visited[i]==0:   
      explore(i,d,l,visited)
      l1.append(l)
      l=[]
      
  return(l1)
  
n,m=map(int,input().split())
d={}
for i in range(n):
  d[i]=[]

for i in range(m):
  u,v=map(int,input().split())
  d[u].append(v)
  d[v].append(u)
visited=[0]*(n)

l=connect(d,visited)
n1=len(l)
s=(n*(n-1))//2

for i in range(n1):
    n=len(l[i])
    s-=(n*(n-1))//2
print(s)


