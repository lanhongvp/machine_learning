from functools import wraps

class Foo(object):
    def __init__(self,func):
        self._func = func

    def __call__(self):
        print('class decorator running')
        self._func()
        print('class decorator ending')


@Foo
def bar():
    print('bar')

# bar()
def logged(func):
    def with_logging(*args,**kwargs):
        print(func.__name__ + ' was called')
        return func(*args,**kwargs)
    return with_logging


def logged_wrap(func):
    @wraps(func)
    def with_logging(*args,**kwargs):
        print(func.__name__ + ' was called')
        return func(*args,**kwargs)
    return with_logging


@logged_wrap
def f(x):
    return x+x

if __name__=='__main__':
    bar()
    f(3)
    print(f.__name__)
    print(f.__doc__)
