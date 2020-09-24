#Parallelopied property- It has three sets of four parallel edges and the edges within each set have equal measurement of length.

t = int(input())
while(t>0):
	arr = list(map(int, input().split()))
	ans=True
	for i in range(12):
		k=0
		for j in range(12):
			if(arr[i]==arr[j]):
				k+=1

		if(k%4 !=0):
			ans=False
			break
	if(ans is False):
		print("no")
	else:
		print("yes")
	t=t-1
