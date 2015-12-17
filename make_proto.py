#!/usr/bin/python

import os
import re
from subprocess import call

if not (os.path.exists("./src")):
    print "need src dir"
    exit(0)

pName = os.path.split(os.getcwd())[1]

inc = []

def handleProto(elem, rep, func):
    if "static" in elem: return
    if "\tmain" in elem: return
    if elem[0] in ' \t': return
    l = elem.split('\t')
    l = [elem for elem in l if len(elem)]
    if len(l) != 2:
        print elem, "in", rep
        print "should be \'type[\\t]+func_name()\'"
        return
    func.append([l[0], l[1], rep])

pattern = '(?:^|\n)(?!static)([^\n]+)\n{\n'

def getProto(filename, rep, func):
    with open(filename, "r") as f:
        r = re.findall(pattern, f.read())
        if not r: return
        for elem in r: handleProto(elem, rep, func)

def getDir(rep, func):
    global inc
    for root, dirs, files in os.walk(rep):
        files = [f for f in files if f[0] != '.']
        for d in dirs:
            for f in os.listdir(os.path.join(root, d)):
                if f[-2:] == '.h':
                    dirs.remove(d)
                    makeProto(os.path.join(root, d), os.path.join(root, d, f))
                    inc.append(os.path.join(root[2:], d))
        for f in files:
            getProto(os.path.join(root, f), root, func)

def countTab(string, m):
    nb_tab = (m - 1) / 4 + 1
    return max(1, nb_tab - len(string) / 4)

def printProto(f, func, m):
    cur_dir = ""
    for t, r, d in func:
        if d != cur_dir:
            f.write("\n/*\n** ")
            f.write(d)
            f.write("\n*/\n\n")
            cur_dir = d
        f.write(t)
        f.write('\t' * countTab(t, m))
        f.write(r)
        f.write(";\n")

def makeProto(src, inc):
    func = []
    getDir(src, func)
    l = [a for a, _, _ in func]
    m = max(map(len, l))
    with open(inc, "r") as f:
        beginning = f.read().split('** Proto')[0]
    with open(inc, 'w') as f:
        f.write(beginning)
        f.write('** Proto\n*/\n')
        printProto(f, func, m)
        f.write('\n#endif\n')

makeProto('./src', pName + '.h')

with open('.project/incdir', 'w') as f:
    for l in inc:
        f.write('{0}\n'.format(l))

if call(['which', 'norminette']) == 0:
    call(["norminette", "inc/proto.h"])
else: print 'can\'t check norm'
