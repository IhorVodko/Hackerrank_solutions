#Problem: https://www.hackerrank.com/challenges/designer-pdf-viewer/problem


def designerPdfViewer(h, word):

    alh = list(string.ascii_lowercase)
    wide = len(word)
    high = max([x[1] for x in [*zip(alh, h)] if x[0] in list(word)])

    return wide*high
