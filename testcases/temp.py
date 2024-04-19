def z(x:int)->int:
    return 2*x

def main():
    
    i:int
    j:int
    for i in range(1,6):
        for j in range(1,6):
            if(j==3):
                continue
            print(2*j)
        
        if(i==4):
            continue
        print(i)
    
    for j in range(1,5):
        if(j==3):
            continue
        print(j)
    
