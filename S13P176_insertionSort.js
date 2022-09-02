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
}

function selectionSortInstructor(array) {
// Instructor lied. He said to reference the dance. I did. Then, instead of iterating like they did, he used a JS specific function to skip around.
// From testing, this isn't even a faster solution. It does, however, include some  JS functions I haven't used before.
// Adding it in here so I can analyze his approach.
  const length = array.length;
  for(let i = 0; i < length; i++) {
    if(array[i] < array[0]) {
      // apparently splice both modifies the array and returns the data that got deleted
      // Suddenly, this makes a lot more sense.
      array.unshift(array.splice(i,1)[0]);
    } else {
      // big issue spotted: This iterates all of [0,i] even if that range has been sorted. Likely, these wasted loops are where the lag is coming from. If you're already looping back to 0 in previous loops, you need to make the logical step that the space you've already traversed is sorted relative to itself. We only need to traverse until we reach the insertion point.
      for(let j = 1; j < i; j++) {
        // Checks from 0 to i instead of i to 0
        if(array[i] > array[j-1] && array[i] < array[j]) {
          array.splice(j,0,array.splice(i,1)[0]);
        }
      }
    }
  }
}

selectionSort(numbers);
console.log(numbers);
