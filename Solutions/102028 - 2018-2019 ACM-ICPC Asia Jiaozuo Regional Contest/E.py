# 2018-2019 ACM-ICPC Asia Jiaozuo Regional Contest
# 102028E


def gcd(a, b):
	return a if b == 0 else gcd(b, a % b)

def isprime(n):
    i = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += 1
    return True

primes = []
for i in range(2, 100000):
    if isprime(i):
        primes.append(i)

def main():
    t = int(input())
    while t > 0:
        t -= 1
        n = int(input())
        if n == 1:
            print("1/1")
        else:
            q = 1
            p = 1
            i = 0
            while p * primes[i] <= n:
                p *= primes[i]
                q *= primes[i] + 1
                i += 1
            g = gcd(int(p), int(q))
            # print("%s/%s %s" % (int(p), int(q), g))
            p /= g
            q /= g
            print("%s/%s" % (int(p), int(q)))

main()