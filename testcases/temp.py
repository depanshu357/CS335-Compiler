a= 20
b= 10
a == 10 , b == 20
x = 10 ; 
y = 20 ;
v = 0
v : x == 10
print(v)

def perm(l):
        # Compute the list of all permutations of l
    if len(l) <= 1:
                  return [l]
    r = []
    for i in range(len(l)):
             s = l[:i] + l[i+1:]
             p = perm(s)
             for x in p:
              r.append(l[i:i+1] + x)
    return r

print(perm([1,2,3]))
# comments in the workspace