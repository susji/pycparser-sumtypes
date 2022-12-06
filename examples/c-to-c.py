#------------------------------------------------------------------------------
# pycparser: c-to-c.py
#
# Example of using pycparser.c_generator, serving as a simplistic translator
# from C to AST and back to C.
#
# Eli Bendersky [https://eli.thegreenplace.net/]
# License: BSD
#------------------------------------------------------------------------------
from __future__ import print_function
import os
import sys

# This is not required if you've installed pycparser into
# your site-packages/ with setup.py
sys.path.extend(['.', '..'])

from pycparser import c_generator, CParser


def handle_file(filename):
    with open(filename, "r") as f:
        text = f.read()

    parser = CParser(lex_optimize=False, yacc_optimize=False)
    return parser.parse(text, filename, debug=bool(os.getenv("DEBUG", False)))


def translate_to_c(filename):
    """ Simply use the c_generator module to emit a parsed AST.
    """
    ast = handle_file(filename)
    generator = c_generator.CGenerator()
    print(generator.visit(ast))


if __name__ == "__main__":
    if len(sys.argv) > 1:
        translate_to_c(sys.argv[1])
    else:
        print("Please provide a filename as argument")
