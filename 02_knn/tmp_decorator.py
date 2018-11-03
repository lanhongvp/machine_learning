import logging

def use_logging(func):

    def wrapper(*args,**kwargs):
        logging.warn('%s is runnning' % func.__name__)
        return func(*args,**kwargs)

    return wrapper


def bar():
    print('simple decorator i am bar')


@use_logging
def foo():
    print('i am foo using grammer candy')


if __name__ =='__main__':
    bar = use_logging(bar)
    bar()
    foo()