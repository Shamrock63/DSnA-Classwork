def quickSort(ar):
  if len(ar) == 1:
    return ar
  head = 0
  tail = len(ar)-1
  print("tail",tail)
  print("ar ",ar)
  while tail > head:
    if ar[head] > ar[tail]:
      if head == tail-1:
        ar[head],ar[tail] = ar[tail],ar[head]
        print("ar ",ar)
      else:
        ar[head],ar[tail],ar[tail-1] = ar[tail-1],ar[head],ar[tail]
        print("ar ",ar)
      tail = tail-1
    else:
      head = head+1
  print("ar ",ar)
  if len(ar) == 2:
    return ar
  else:
    return quickSort(ar[:tail]) + [ar[tail]] + quickSort(ar[tail+1:])

#main
numbers = [3,7,8,5,2,1,9,5,4] #9 elements
print(quickSort(numbers))
