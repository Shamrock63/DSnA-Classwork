const numbers = [99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0];

function selectionSort(array) {
  let small;
  let n = 0;
  for (let i = 0; i < array.length; i++) {
    small = i;
    for(let j = i; j < array.length; j++) {
      if(array[j] < array[i] && array[j] < array[small]) {
        small = j;
      }
    }
    n = array[small];
    array[small] = array[i];
    array[i] = n;
  }
  return array;
}

selectionSort(numbers);
console.log(numbers);
