import numpy as np

# definition is here
def peak_1D(arr, left, right):
    middle = (left + right) / 2
    if (left != right):
        if (arr[middle] < arr[middle-1]):
            return peak_1D(arr, left, middle)
        elif (arr[middle] < arr[middle+1]):
            return peak_1D(arr, middle, right)
        else:
            return middle+1
    else:
        return left+1

# definition is here
def max(arr):
    max_pos = 0
    for i in range(len(arr)):
        if (arr[i] > arr[max_pos]):
            max_pos = i
    return max_pos

# definition is here
def peak_2D(mat, above, bottom, cols):
    

# Code demo
arr = np.array([1, 2, 3, 4, 5, 4, 3, 2, 1])
peak = peak_1D(arr, 0, 8)
print peak
