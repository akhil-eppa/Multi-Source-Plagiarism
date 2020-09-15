# -*- coding: utf-8 -*-
"""
Created on Mon Sep  7 14:11:59 2020

@author: Akhil
"""

from __future__ import print_function
import sys
import re

# This is not required if you've installed pycparser into
# your site-packages/ with setup.py
sys.path.extend(['.', '..'])

from pycparser import c_parser, c_ast, parse_file


# A simple visitor for FuncDef nodes that prints the names and
# locations of function definitions.
z=[]
class FuncDefVisitor(c_ast.NodeVisitor):
    def visit_FuncDef(self, node):
        #print('%s at %s' % (node.decl.name, node.decl.coord))
        z.append(str(node.decl.coord))

def show_func_defs(filename):
    # Note that cpp is used. Provide a path to your own cpp or
    # make sure one exists in PATH.
    ast = parse_file(filename, use_cpp=True,
                     cpp_args=r'-Iutils/fake_libc_include')

    v = FuncDefVisitor()
    v.visit(ast)

def get_functions(filename):
    #filename="a1_1.c"
    file=open(filename,"r")
    x=file.read()
    x=re.sub("#include","//#include",x)
    file.close()
    file2=open("t"+filename,"w")
    file2.write(x)
    file2.close()
    name="t"+filename
    l=len(name)
    show_func_defs(name)
    xx=[]
    for i in z:
        xx.append(int(i[l+1:i.find(":",l+1)]))
    return xx
