#!/usr/bin/env python

import os

def reader(index, wfile):
    line = ""
    offset = long(index)

    if offset >= os.path.getsize(wfile.name):
        return "Index out of bounds -> File size: " + str(os.path.getsize(wfile.name)) + "   Index: " + str(offset)
    elif offset <= 0:
        return "Cannot have null or negative index -> Index: " + str(offset)
    else:
        wfile.seek(offset, 0)
        line = wfile.readline()
        nextletter = 'f'

        while nextletter != '\n' and offset != 0:
            offset = offset - 1
            wfile.seek(offset)
            nextletter = wfile.read(1)
            line = nextletter + line

    line = line.strip()
    return line


def searcher(word, wfile, top, bottom, last, count):

    middle = ((bottom - top) / 2) + top
    midword = reader(middle, wfile)
    split = midword.split()
    small_midword = split[0]

    if midword == last:
        count = count + 1
    if count == 5:
        return None

    else:
        if midword != last:
            count = 0

        if word == small_midword:
            return midword
        elif word < small_midword:
            return searcher(word, wfile, top, middle, midword, count)
        elif word > small_midword:
            return searcher(word, wfile, middle, bottom, midword, count)
        else:
            return "Something has gone horribly wrong"


def binSearch(word, filename):
    wfile = open(filename, "r")
    top = 0
    bottom = os.path.getsize(filename)
    last = ""
    count = 0
    result = searcher(word, wfile, top, bottom, last, count)
    wfile.close()
    return result
  

def readLine(index, filename):
    myfile = open(filename, "r")
    result = reader(index, myfile)
    return result


#print binSearch("run", "/home/perditus/Projects/midnight/python/dict/index.verb")
