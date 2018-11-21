# 2018-2019 ACM-ICPC Nordic Collegiate Programming Contest (NCPC 2018)
# 101933I

n, s = input().split()
n = int(n)
s = int(s)

arr = [0] * n
for i in range(n):
	arr[i] = input().split()
	arr[i] = (arr[i][0], int(arr[i][1]))

arr.sort(key=lambda x: x[1], reverse=True)

ans = []
for i in range(len(arr)):
	if s >= arr[i][1]:
		s -= arr[i][1]
		ans.append(arr[i][0])
	


if s == 0:
	print(len(ans))
	for i in ans:
		print(i)
else:
	print(0)