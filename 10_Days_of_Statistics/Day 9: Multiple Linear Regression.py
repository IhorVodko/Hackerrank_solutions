#Problem: https://www.hackerrank.com/challenges/s10-multiple-linear-regression/problem


from sklearn import linear_model

def pred(y, x, x_pred):

    lm = linear_model.LinearRegression()
    lm.fit(x, y)
    y_pred = lm.predict(x_pred)
    return y_pred

def main():
    m, n = map(int, input().strip().split())
    y, x, x_pred = [[] for _ in range(3)]
    for _ in range(n):
        *features, y_val = map(float, input().strip().split())
        x.append(features)
        y.append(y_val)

    for _ in range(int(input())):
        features = [float(i) for i in input().strip().split()]
        x_pred.append(features)

    solution = pred(y, x, x_pred)
    for sol in solution:
        print(round(sol, 2))

if __name__ == "__main__":
    main()
