unsort_nums = [42,20,17,13,28,14,23,15]

def BubbleSort0(unsort_nums):
    for i in range(len(unsort_nums)):
        # print('i',i)
        for j in range(len(unsort_nums)-1,0,-1):
            # print('j',j)
            if unsort_nums[j] < unsort_nums[j-1]:
                tmp = unsort_nums[j]
                unsort_nums[j] = unsort_nums[j-1]
                unsort_nums[j-1] = tmp
        # print('nums',unsort_nums)
    return unsort_nums


def BubbleSort1(unsort_nums):
    for i in range(len(unsort_nums)):
        # print('i',i)
        trans_flag = False
        for j in range(len(unsort_nums)-1,0,-1):
            # print('j',j)
            if unsort_nums[j] < unsort_nums[j-1]:
                tmp = unsort_nums[j]
                unsort_nums[j] = unsort_nums[j-1]
                unsort_nums[j-1] = tmp
                trans_flag = True
        if trans_flag == False:
            return unsort_nums


def selectSort(unsort_nums):
    for i in range(len(unsort_nums)):
        minIndex = i
        for j in range(i,len(unsort_nums)):
            if unsort_nums[j]<unsort_nums[minIndex]:
                minIndex = j
            if minIndex != i:
                tmp = unsort_nums[i]
                unsort_nums[minIndex] = unsort_nums[j]
                unsort_nums[j] = tmp   
        # print('nums',unsort_nums)
    return unsort_nums


def insertSort(unsort_nums):
    for i in range(len(unsort_nums)):
        # print('i',i)
        for j in range(i+1,len(unsort_nums)):
            # print('j',j)
            if unsort_nums[j] < unsort_nums[j-1]:
                tmp = unsort_nums[j-1]
                unsort_nums[j-1] = unsort_nums[j]
                unsort_nums[j] = tmp
            else:
                break
            # print('nums',unsort_nums)
    return unsort_nums


def shellSort(unsort_nums):
    incre = len(unsort_nums)
    while True:
        incre = incre//2
        for k in range(incre):
            for i in range(k+incre,len(unsort_nums),incre):
                for j in range(i,k+incre,-incre):
                    if unsort_nums[j] < unsort_nums[j-incre]:
                        tmp = unsort_nums[j-incre]
                        unsort_nums[j-incre] = unsort_nums[j]
                        unsort_nums[j] = tmp
                    else:
                        pass
        if(incre==1):
            break
    return unsort_nums


def quickSort(unsort_nums):
    # i = 1; j = len(unsort_nums); key = unsort_nums[0]
    if len(unsort_nums)<2:
        return unsort_nums
    # for i in range()
    # while()
    else:
        baseValue = unsort_nums[0]
        less = [m for m in unsort_nums[1:] if m < baseValue]
        equal = [w for w in unsort_nums if w==baseValue]
        greater = [n for n in unsort_nums[1:] if n > baseValue]
    return quickSort(less) + equal + quickSort(greater)


    


if __name__ =='__main__':
    print('sorted nums using bubble sort 0: ',BubbleSort0(unsort_nums))
    print('sorted nums using bubble sort 1: ',BubbleSort1(unsort_nums))
    print('sorted nums using select sort:   ',selectSort(unsort_nums))
    print('sorted nums using insert sort:   ',insertSort(unsort_nums))
    print('sorted nums using shell sort:   ',shellSort(unsort_nums))
    print('sorted nums using quick sort:   ',quickSort(unsort_nums))





