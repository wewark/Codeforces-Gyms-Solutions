def gcd(a,b):
	if(a==0):
		return b
	else:
		return gcd(b%a,a)
 
from math import *
k,n=map(int,input().split())
if(k==n-1):
	print(0)
elif(k==n):
	print('1/'+str(factorial(n)))
else:
	fact=[1,1,2]
	for i in range(3,max(n-k,k)+1):
		fact.append(fact[-1]*i)
 
	if((n-k)%2==0):
		num=1
	else:
		num=-1
	prod=1
	for i in range(n-k,0,-1):
		prod*=i
		if(i%2==1):
			num+=prod
		else:
			num-=prod
 
	den=fact[k]*fact[n-k]
 
	g=gcd(num,den)
	num=num//g
	den=den//g
	print(str(num)+"/"+str(den))
