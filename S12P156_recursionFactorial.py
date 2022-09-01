def findFactorialRecursive(x):
  if x == 1:
    return 1
  return x * findFactorialRecursive(x-1)

def findFactorialIterative(x):
  y = 1
  for i in range(x):
    y = y * (i+1)
  return y

print(findFactorialIterative(5))
print(findFactorialRecursive(5))
