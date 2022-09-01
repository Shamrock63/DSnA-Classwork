def recurFibonacci(n):
  if n < 2:
    return n
  return recurFibonacci(n-1) + recurFibonacci(n-2)

def iterFibonacci(n): # 2
  x = 0
  y = 1
  if n < 2:
    z = n
  for i in range(n-1):
    z = x + y
    x = y
    y = z
  return z

print(iterFibonacci(0))
print(iterFibonacci(1))
print(iterFibonacci(2))
print(iterFibonacci(3))
print(iterFibonacci(4))
print(iterFibonacci(5))
print(iterFibonacci(6))
print(iterFibonacci(7))

print(recurFibonacci(0))
print(recurFibonacci(1))
print(recurFibonacci(2))
print(recurFibonacci(3))
print(recurFibonacci(4))
print(recurFibonacci(5))
print(recurFibonacci(6))
print(recurFibonacci(7))
