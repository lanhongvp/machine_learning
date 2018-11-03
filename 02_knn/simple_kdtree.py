from collections import namedtuple
from operator import itemgetter
from pprint import pformat

global step
step = 0

class Node(namedtuple('Node', 'location left_child right_child')):
    # step = step + 1
    # print('step',step)
    def __repr__(self):
        return pformat(tuple(self))

def kdtree(point_list, depth=0):
    global step
    step = step + 1
    print('step',step)
    print('input depth',depth)
    print('point_list before sort\n',point_list)
    try:
        k = len(point_list[0]) # assumes all points have the same dimension
        # print('dimension of point list',k)
    except IndexError as e: # if not point_list:
        print('not in point list')
        return None
    # Select axis based on depth so that axis cycles through all valid values
    axis = depth % k
    print('changed depth',depth)
    print('axis',axis)
    item_axis = itemgetter(axis)
    print('item axis',item_axis)
 
    # Sort point list and choose median as pivot element
    point_list.sort(key=itemgetter(axis))
    print('point_list after sort\n',point_list)
    median = len(point_list) // 2 # choose median
    print('median',median)
 
    # Create node and construct subtrees
    return Node(
        location=point_list[median],
        left_child=kdtree(point_list[:median], depth + 1),
        right_child=kdtree(point_list[median + 1:], depth + 1)
    )

def main():
    
    """Example usage"""
    point_list = [(2,3), (5,4), (9,6), (4,7), (8,1), (7,2)]
    tree = kdtree(point_list)
    print(tree)
    print(type(tree))

if __name__ == '__main__':
    main()