const numbers = [99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0];

function bubbleSort(array) {
  let n = 0;
  for (let i = array.length-1; i >= 0; i--) {
    for(let j = 0; j < i; j++) {
      if(array[j] > array[j+1]) {
        n = array[j];
        array[j] = array[j+1];
        array[j+1] = n;
      }
    }
  }
  return array;
}

bubbleSort(numbers);
console.log(numbers);
