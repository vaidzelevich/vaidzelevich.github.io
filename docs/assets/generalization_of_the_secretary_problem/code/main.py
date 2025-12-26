import cpp
import matplotlib.pyplot as plt
import time


def calculate_probabilites(n: int) -> list[float]:
    result = []
    s = 0
    for r in range(n, 1, -1):
        s += 1 / (r - 1)
        result.append((r - 1) / n * s)
    result.append(1 / n)
    result.reverse()
    return result


n = 100
m = 2
num_tests = 1_000_000
start = time.perf_counter()
estimation = cpp.estimate(n, m, num_tests)
print(f'{time.perf_counter() - start:.3f}s')
print(estimation)
print(max(enumerate(estimation), key=lambda arg: arg[1]))
probabilities = calculate_probabilites(n)
print(max(enumerate(probabilities), key=lambda arg: arg[1]))
plt.plot(estimation)
plt.show()
