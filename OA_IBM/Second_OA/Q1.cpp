int* performOperations(int arr_count, int* arr, int operations_rows, int operations_columns, int** operations, int* result_count) {
    // Set result count to input array size
    *result_count = arr_count;
    
    // Create a copy of the input array to work with
    int* result = (int*)malloc(arr_count * sizeof(int));
    for(int i = 0; i < arr_count; i++) {
        result[i] = arr[i];
    }
    
    // Process each operation
    for(int op = 0; op < operations_rows; op++) {
        int start = operations[op][0];
        int end = operations[op][1];
        
        // Reverse the subarray between start and end indices
        int left = start;
        int right = end;
        while(left < right) {
            // Swap elements
            int temp = result[left];
            result[left] = result[right];
            result[right] = temp;
            
            left++;
            right--;
        }
    }
    
    return result;
}