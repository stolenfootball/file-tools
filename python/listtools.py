#!/usr/bin/env python

def rmDups(array):
    ret = []

    for i in array:
        count = ret.count(i)
        if count == 0:
            ret.append(i)

    return ret

def contains(lst, string):
    if lst.count(string) == 0:
        return False
    else:
        return True


















