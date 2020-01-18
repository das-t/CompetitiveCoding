
# Hänschen dreams he is in a shop with an infinite amount of marbles. 
# He is allowed to select n marbles. There are marbles of k different 
# colors. From each color, there are also infinitely many marbles. 
# Hänschen wants to have at least one marble of each color, but still 
# there are a lot of possibilities for his selection. In his effort to 
# make a decision he wakes up. Now he asks you how many possibilities 
# for his selection he would have had. Assume that marbles of equal 
# color can't be distinguished, and the order of the marbles is irrelevant.

def binCoeff(n,r):
    numerator = 1
    denominator = 1
    while(r>n-r):
        r = n-r
    for i in range(0,r):
        numerator *= (n-i)
        denominator *= (i+1)
    return numerator//denominator
    
def main():
    testCases = int(input())
    while(testCases>0):
        testCases -= 1
        marbels,colors = map(int,input().split())
        print(binCoeff(marbels-1,colors-1))

if __name__=="__main__":
    main()