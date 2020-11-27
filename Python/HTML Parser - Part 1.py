#Problem: https://www.hackerrank.com/challenges/html-parser-part-1/problem


from html.parser import HTMLParser
import sys

lines_total = int(input())
html_code = sys.stdin.read()

class My_HTML_Parser(HTMLParser):
    
    def handle_starttag(self, tag, attrs):
        
        print(f"Start : {tag}")
        for attr in attrs:
            name = attr[0]
            value = attr[1]
            print(f"-> {name} > {value}")   
            
    def handle_endtag(self, tag): 
        print(f"End   : {tag}")
    
    def handle_startendtag(self, tag, attrs):
        
        print(f"Empty : {tag}") 
        for attr in attrs:
            name = attr[0]
            value = attr[1]
            print(f"-> {name} > {value}")   
        

parser = My_HTML_Parser()
parser.feed(html_code)

