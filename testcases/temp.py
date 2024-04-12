def temp(a:int)->int:
    if(a==0):
        return 1
    if(a==1):
        return 1
    return temp(a-1)+ temp(a-2)

def main():
    i:int=123
    print(i)
    i=temp(5)
    print(i)
    # i=temp(12)
    # print(i)
    # i=4
    # i:int = 4 and 5 
