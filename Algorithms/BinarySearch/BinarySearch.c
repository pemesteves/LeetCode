int search(int* nums, int numsSize, int target){
    int pivot, left = 0, right = numsSize-1;
    
    while(left <= right){
        pivot = (right-left)/2 + left;

        if(nums[pivot] == target)
            return pivot;

        if(target > nums[pivot]){
            left = pivot + 1;
        }else{
            right = pivot - 1;
        }
    }
    return -1;
}