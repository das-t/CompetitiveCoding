# Alice is learning mathematical functions. In his assignment, teacher
# has asked him to evaluate h(x)= f(x)+g(x) where
# f(x)=3x^2-x+10 and g(x)=4x^3+2x^2-5x+4.

def main():
    value = int(input())
    result = 4*value*value*value+5*value*value-6*value+14
    print(result)

if __name__=="__main__":
    main()