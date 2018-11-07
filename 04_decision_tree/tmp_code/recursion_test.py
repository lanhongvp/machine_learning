
# a = [1,2,3]
step = 3

def test_recursion(step):
    print('step',step)
    
    a = [1,2,3]
    b = [1,2,3,4]
    tmp_dict = {}
    if step==1:
        print('length a is ',len(a))
        return len(a)
    for i in range(len(a)):
        print('I am in the loop,i:%d'%i)
        # step = len(a)-i
        tmp_dict[i] = test_recursion(step-1)
    return b

test_recursion(step)