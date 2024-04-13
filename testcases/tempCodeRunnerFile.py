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
    print("The fib of ")
    print(a)
    print(" is ")
    print(x)
    return x


def main():
    i:int=123
    print(i)
    i=temp(5)
    print(i)
    print("func ended")
