def highest()->list[int]:
    return [263, 262, 248]

def highest_against()->list[str]:
    return ["PWI,2013", "SRH,2024", "GL,2016"]

def lowest()->list[int]:
    return [49, 68, 70]

def lowest_against()->list[str]:
    return ["KKR, 2017", "SRH, 2022", "RR,2014 and CSK, 2019"]

def binary_search(arr:list[str],x:str)->int:
    low:int = 0
    high:int = len(arr)-1
    while low<=high:
        mid:int = low + (high-low)//2
        if arr[mid] == x:
            return mid
        elif arr[mid]<x:
            low = mid+1
        else:
            high = mid-1
    return -1


def main():
    runs_highest:list[int] = highest()
    runs_highest_against:list[str] = highest_against()
    runs_lowest:list[int] = lowest()
    runs_lowest_against:list[str] = lowest_against()
    
    print("IPL Stats : RCB highest runs in a match")
    i:int  = 0
    for i in range(0,len(runs_highest)):
        print(runs_highest[i])
        print("against - ")
        print(runs_highest_against[i])
        i += 1

    print("IPL Stats : RCB lowest runs in a match")
    j:int = 0
    for j in range(0,len(runs_lowest)):
        print(runs_lowest[j])
        print("against - ")
        print(runs_lowest_against[j])
        j += 1
    
    arr:list[str] = ["CSK", "DC", "GL", "KKR", "LSG", "MI", "PK", "RCB", "RR", "SRH"]
    index:int = binary_search(arr,"RCB")
    print("Index of RCB in sorted array is:")
    print(index)
