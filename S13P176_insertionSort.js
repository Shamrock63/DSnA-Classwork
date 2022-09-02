const numbers = [99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0];

function selectionSort(array) {
  let n = 0;
  for (let i = 1; i < array.length; i++) {
    if(array[i] < array[i-1]) {
      let j = i;
      while(array[j] < array[j-1]) {
        n = array[j];
        array[j] = array[j-1];
        array[j-1] = n;
        j--;
      }
    }
  }
  return array;
}

selectionSort(numbers);
console.log(numbers);
