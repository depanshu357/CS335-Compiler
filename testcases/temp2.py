def temp(a:int)->int:
    if(a==0):
        return 1
    if(a==1):
        return 1
    # b:list[int]=[11,22,33]
    # i:int=b[0]
    # j:int=b[1]
    # print(i)
    # print(j)
    x:int=temp(a-1)+ temp(a-2)
    data : list[int] = [10,9,8,7,6,5,4,3,2,1]
    data[1] = data[2] * data[3]
    i:int = data[1]
    print(i)
    return x


def main():
    i:int=123
    print(i)
    i=temp(2)
    print(i)
    print("func ended")

