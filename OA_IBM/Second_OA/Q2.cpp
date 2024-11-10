int* reassignedPriorities(int priorities_count, int* priorities, int* result_count) {
    // Set the result count to match input array size
    *result_count = priorities_count;
    
    // Allocate memory for result array
    int* result = (int*)malloc(priorities_count * sizeof(int));
    
    // First, create a sorted copy of unique values to map priorities
    int* unique = (int*)malloc(priorities_count * sizeof(int));
    int unique_count = 0;
    
    // Copy unique values
    for(int i = 0; i < priorities_count; i++) {
        bool found = false;
        for(int j = 0; j < unique_count; j++) {
            if(unique[j] == priorities[i]) {
                found = true;
                break;
            }
        }
        if(!found) {
            unique[unique_count++] = priorities[i];
        }
    }
    
    // Sort unique values
    for(int i = 0; i < unique_count - 1; i++) {
        for(int j = 0; j < unique_count - i - 1; j++) {
            if(unique[j] > unique[j + 1]) {
                int temp = unique[j];
                unique[j] = unique[j + 1];
                unique[j + 1] = temp;
            }
        }
    }
    
    // Create mapping from old priorities to new ones
    // New priorities will start from 1 and increment by 1
    for(int i = 0; i < priorities_count; i++) {
        for(int j = 0; j < unique_count; j++) {
            if(priorities[i] == unique[j]) {
                result[i] = j + 1;
                break;
            }
        }
    }
    
    // Free temporary array
    free(unique);
    
    return result;
}