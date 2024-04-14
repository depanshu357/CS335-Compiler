def temp(a:list[int])->int:
    i:int = a[7]
    return a[8]


def main():
    data : list[int] = [10,9,8,7,6,5,4,3,2,1]
    i:int = temp(data)
    print(i)

