#Problem: https://www.hackerrank.com/challenges/detect-html-tags-attributes-and-attribute-values/problem


from html.parser import HTMLParser

class My_HTML_Parser(HTMLParser):
    def handle_starttag(self, tag, attrs):
        print(tag)
        [print(f"-> {attr[0]} > {attr[1]}") for attr in attrs]
        
html_code = "\n".join([input() for _ in range(int(input()))])                 
parser = My_HTML_Parser()
parser.feed(html_code)
parser.close()
