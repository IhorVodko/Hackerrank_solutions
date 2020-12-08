#Problem: https://www.hackerrank.com/challenges/xml-1-find-the-score/problem


import sys
import xml.etree.ElementTree as etree

def get_attr_number(node):
    return (len(node.attrib) + sum(get_attr_number(child_node) for child_node in node))

if __name__ == '__main__':
    sys.stdin.readline()
    xml = sys.stdin.read()
    tree = etree.ElementTree(etree.fromstring(xml))
    root = tree.getroot()
    print(get_attr_number(root))
