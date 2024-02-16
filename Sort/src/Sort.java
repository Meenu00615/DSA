public class Sort{
    public static void printArray(int []arr){
        for(int i=0; i<arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
    public static void main(String[] args){
        //defining array
        int[] arr = {7, 8, 3, 1, 2};

        //bubble sort n-1, last element will itself arrange
        //loop
        for(int i=0; i<arr.length-1; i++){
            for(int j=0; j<arr.length-i-1; j++){  //because at first i was 0 then further so on it because -i
                //condition
                if(arr[j]> arr[j+1]){    //one index and another i+1 index here
                    //swap
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;

                }
            }
        }
        printArray(arr);
    }
} 

