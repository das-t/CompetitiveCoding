# Print nth Catalan Number. The first few Catalan numbers 
# for n = 0, 1, 2, 3, … are 1, 1, 2, 5, 14,.. 

def catalynNumber(index):
    catalynValue = 1
    for i in range(0,index):
        catalynValue *= 2*(2*i+1)
        catalynValue //= (i+2)
    return catalynValue

def main():
    number = int(input())
    print(catalynNumber(number))

if __name__=="__main__":
    main()