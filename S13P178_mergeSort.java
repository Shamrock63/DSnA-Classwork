import java.util.Arrays;

class Main {
  public static int[] mergeSort(int[] array) {
    if(array.length == 1) {
      return array;
    }
    int mid = array.length/2;
    int[] left = Arrays.copyOfRange(array,0,mid);
    int[] right = Arrays.copyOfRange(array,mid,array.length);
    return merge(
      mergeSort(left),
      mergeSort(right)
    );
  }

  public static int[] merge(int[] left, int[] right) {
    int[] r = new int[left.length + right.length];
    int leftI = 0;
    int rightI = 0;
    //System.arraycopy(left, 0, r, 0, left.length);
    //System.arraycopy(right, 0, r, left.length, right.length);
    for(int i = 0; i < r.length; i++) {
      if(leftI < left.length && rightI < right.length) {
        if(left[leftI] < right[rightI]) {
          r[i] = left[leftI];
          leftI++;
        } else {
          r[i] = right[rightI];
          rightI++;
        }
      } else if(leftI == left.length) {
        r[i] = right[rightI];
        rightI++;
      } else {
        r[i] = left[leftI];
        leftI++;
      }
    }
    return r;
  }
  
  private static int[] numbers = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};
  public static void main(String[] args) {
    int[] answer = new int[numbers.length];
    answer = mergeSort(numbers);
    for(int i = 0; i < answer.length; i++) System.out.print(answer[i] + " ");
  }
}
