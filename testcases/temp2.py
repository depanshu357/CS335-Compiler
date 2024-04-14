def temp(arr:list[int])->None:
    i:int=0
    j:int=0
    # n:int=len(arr)
    n:int=10
    for i in range(0,n):
        
        # Last i elements are already in place
        for j in range(0, n):
            # Traverse the array from 0 to n-i-1
            # Swap if the element found is greater
            # than the next element
            a:int=arr[j]
            b:int=arr[j+1]
            if a > b:
                # x:int = arr[j]
                # y:int = arr[j+1]
                arr[j]=b
                arr[j+1]=a

                


def main():
    data : list[int] = [10,9,8,7,6,5,4,3,2,1]
    temp(data)
    n:int=10
    # n:int=len(data)
    i:int=0
    # print(data[0])
    for i in range(0,n):
        print(data[i])

