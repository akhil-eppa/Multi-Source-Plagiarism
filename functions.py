# -*- coding: utf-8 -*-
"""
Created on Mon Sep  7 14:11:59 2020

@author: Akhil
"""

from __future__ import print_function

import re
from pathlib import Path

from pycparser import c_ast, c_generator, parse_file
from pycparser.c_ast import FuncDef

z = []


class FuncDefVisitor(c_ast.NodeVisitor):
    def visit_FuncDef(self, node):
        z.append(str(node.decl.coord))


def show_func_defs(filename):
    ast = parse_file(filename, use_cpp=True, cpp_args=[r"-Ifake_headers", r"-nostdinc"])
    generator = c_generator.CGenerator()
    for node in ast.ext:
        if isinstance(node, FuncDef):
            yield generator.visit(node.decl), generator.visit(node.body)


def get_parsed_lines(filename):
    lines = 0
    for _, body in show_func_defs(filename):
        lines += len(list(filter(lambda x: x, body.split("\n")))) + 1
    return lines


def get_functions(filename):
    preproc_filename = f"{Path(Path(filename).name).stem}_preproc.c"
    with open(filename) as file:
        x = file.read()
        # x = re.sub("#include", "//#include", x)
        with open(preproc_filename, "w") as preproc:
            preproc.write(x)

    decl_to_func = {}
    for decl, body in show_func_defs(preproc_filename):
        decl_to_func[decl] = body
    Path(preproc_filename).unlink()
    return decl_to_func


if __name__ == "__main__":
    a = get_parsed_lines("test.c")
    print(a)
