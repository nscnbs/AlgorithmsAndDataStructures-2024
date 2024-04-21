#Lista 2 Illia Azler 239537

from matplotlib import pyplot as plt
from functools import reduce
import math


#def algorithm_summary(file: str, length=5): # k=10 i n={10,...,50}
def algorithm_summary(file: str, length=50): # k=100 i n={1000,...,50000}
    with open(file) as file:
        comparisons = [[] for _ in range(0, length)]
        swaps = [[] for _ in range(0, length)]
        time = [[] for _ in range(0, length)]

        for line in file:
            line = line.strip().split()
            if len(line) < 4:
                break
            #n = int(int(line[0])/10-1) # k=10 i n={10,...,50}
            n = int(int(line[0])/1000-1) # k=100 i n={1000,...,50000}

            comparisons[n].append(int(line[1]))
            swaps[n].append(int(line[2]))
            time[n].append(float(line[3]))

        comparisons_avg = [sum(comp)/len(comp) for comp in comparisons]
        swaps_avg = [sum(swap)/len(swap) for swap in swaps]
        time_avg = [sum(t)/len(t) for t in time]

        #comps_over_n = [c * 1.0 / (i+10) for i, c in enumerate(comparisons_avg)] # k=10 i n={10,...,50}
        #swaps_over_n = [s * 1.0 / (i+10) for i, s in enumerate(swaps_avg)] # k=10 i n={10,...,50}

        comps_over_n = [c * 1.0 / (i+1000) for i, c in enumerate(comparisons_avg)]  # k=100 i n={1000,...,50000}
        swaps_over_n = [s * 1.0 / (i+1000) for i, s in enumerate(swaps_avg)]  # k=100 i n={1000,...,50000}


        return comparisons_avg, swaps_avg, time_avg, comps_over_n, swaps_over_n

# k=10 i n={10,...,50}
#quick_c, quick_s, quick_t, quick_c_n, quick_s_n = algorithm_summary('D:\\Studia\\VI sem\\AiSD\\Lista2\\logs\\quick-k-10-n-10-50.log')
#merge_c, merge_s, merge_t, merge_c_n, merge_s_n = algorithm_summary('D:\\Studia\\VI sem\\AiSD\\Lista2\\logs\\merge-k-10-n-10-50.log')
#hybrid_quick_c, hybrid_quick_s, hybrid_quick_t, hybrid_quick_c_n, hybrid_quick_s_n = algorithm_summary('D:\\Studia\\VI sem\\AiSD\\Lista2\\logs\\hybryd_quick-k-10-n-10-50.log')
#insert_c, insert_s, insert_t, insert_c_n, insert_s_n = algorithm_summary('D:\\Studia\\VI sem\\AiSD\\Lista2\\logs\\insert-k-10-n-10-50.log')
#dual_c, dual_s, dual_t, dual_c_n, dual_s_n = algorithm_summary('D:\\Studia\\VI sem\\AiSD\\Lista2\\logs\\dual-k-10-n-10-50.log')
#hybrid_c, hybrid_s, hybrid_t, hybrid_c_n, hybrid_s_n = algorithm_summary('D:\\Studia\\VI sem\\AiSD\\Lista2\\logs\\hybryd-k-10-n-10-50.log')

#k=100 i n={1000,...,50000}
quick_c, quick_s, quick_t, quick_c_n, quick_s_n = algorithm_summary('D:\\Studia\\VI sem\\AiSD\\Lista2_2024\\logs\\quick-k-100-n-1000-50000.log')
merge_c, merge_s, merge_t, merge_c_n, merge_s_n = algorithm_summary('D:\\Studia\\VI sem\\AiSD\\Lista2_2024\\logs\\merge-k-100-n-1000-50000.log')
hybrid_quick_c, hybrid_quick_s, hybrid_quick_t, hybrid_quick_c_n, hybrid_quick_s_n = algorithm_summary('D:\\Studia\\VI sem\\AiSD\\Lista2_2024\\logs\\hybryd_quick-k-100-n-1000-50000.log')
dual_c, dual_s, dual_t, dual_c_n, dual_s_n = algorithm_summary('D:\\Studia\\VI sem\\AiSD\\Lista2_2024\\logs\\dual-k-100-n-1000-50000.log')
hybrid_c, hybrid_s, hybrid_t, hybrid_c_n, hybrid_s_n = algorithm_summary('D:\\Studia\\VI sem\\AiSD\\Lista2_2024\\logs\\hybryd-k-100-n-1000-50000.log')


#x = list(range(10, 51, 10)) # k=10 i n={10,...,50}
x = list(range(1000, 50001, 1000)) # k=100 i n={1000,...,50000}

quick_coefficient = []
#n = 10 # k=10 i n={10,...,50}
n = 1000 # k=100 i n={1000,...,50000}
for q in quick_c:
    quick_coefficient.append(q * 1.0 / (n * math.log(n)))
    #n += 10 # k=10 i n={10,...,50}
    n += 1000 # k=100 i n={1000,...,50000}
sum_ = reduce(lambda a, b: a + b, quick_coefficient)
#avg_ = sum_ / 5 # k=10 i n={10,...,50}
avg_ = sum_ / 50 # k=100 i n={1000,...,50000}
print(r'stala przy czynniku n ln(n) wyniosla', avg_, 'dla QuickSorta')


quick_coefficient = []
#n = 10 # k=10 i n={10,...,50}
n = 1000 # k=100 i n={1000,...,50000}
for q in dual_c:
    quick_coefficient.append(q * 1.0 / (n * math.log(n)))
    #n += 10 # k=10 i n={10,...,50}
    n += 1000 # k=100 i n={1000,...,50000}
sum_ = reduce(lambda a, b: a + b, quick_coefficient)
#avg_ = sum_ / 5 # k=10 i n={10,...,50}
avg_ = sum_ / 50 # k=100 i n={1000,...,50000}
print(r'stala przy czynniku n ln(n) wyniosla', avg_, 'dla DualPivotQuickSorta')

plt.figure(figsize=(10, 6))

#plt.plot(x, insert_c, color='grey', label='Insertion Sort', linewidth=2)
plt.plot(x, merge_c, color='blue', label='Merge Sort', linewidth=2)
plt.plot(x, quick_c, color='red', label='Quick Sort', linewidth=2)
plt.plot(x, dual_c, color='green', label='Dual Pivot Quick Sort', linewidth=2)
plt.plot(x, hybrid_quick_c, color='purple', label='Hybrid Quick Sort', linewidth=2)
plt.plot(x, hybrid_c, color='orange', label='Hybrid Sort', linewidth=2)

plt.title('Comparisons Average')
plt.ylabel('Comparisons')
#plt.xlabel('n {10 ... 50}') # k=10 i n={10,...,50}
plt.xlabel('n {1000 ... 50000}') #k=100 i n={1000,...,50000}
plt.grid(True)
plt.legend()

plt.show()
plt.close()

plt.figure(figsize=(10, 6))

#plt.plot(x, insert_s, color='grey', label='Insertion Sort', linewidth=2)
plt.plot(x, merge_s, color='blue', label='Merge Sort', linewidth=2)
plt.plot(x, quick_s, color='red', label='Quick Sort', linewidth=2)
plt.plot(x, dual_s, color='green', label='Dual Pivot Quick Sort', linewidth=2)
plt.plot(x, hybrid_quick_s, color='purple', label='Hybrid Quick Sort', linewidth=2)
plt.plot(x, hybrid_s, color='orange', label='Hybrid Sort', linewidth=2)

plt.title('Swaps Average')
plt.ylabel('Swaps')
#plt.xlabel('n {10 ... 50}') # k=10 i n={10,...,50}
plt.xlabel('n {1000 ... 50000}') #k=100 i n={1000,...,50000}
plt.grid(True)
plt.legend()

plt.show()
plt.close()

plt.figure(figsize=(10, 6))

#plt.plot(x, insert_c_n, color='grey', label='Insertion Sort', linewidth=2)
plt.plot(x, merge_c_n, color='blue', label='Merge Sort', linewidth=2)
plt.plot(x, quick_c_n, color='red', label='Quick Sort', linewidth=2)
plt.plot(x, dual_c_n, color='green', label='Dual Pivot Quick Sort', linewidth=2)
plt.plot(x, hybrid_quick_c_n, color='purple', label='Hybrid Quick Sort', linewidth=2)
plt.plot(x, hybrid_c_n, color='orange', label='Hybrid Sort', linewidth=2)

plt.title(r'$\frac{c}{n}$ Average')
plt.ylabel(r'$\frac{c}{n}$')
#plt.xlabel('n {10 ... 50}') # k=10 i n={10,...,50}
plt.xlabel('n {1000 ... 50000}') #k=100 i n={1000,...,50000}
plt.grid(True)
plt.legend()

plt.show()
plt.close()

plt.figure(figsize=(10, 6))

#plt.plot(x, insert_s_n, color='grey', label='Insertion Sort', linewidth=2)
plt.plot(x, merge_s_n, color='blue', label='Merge Sort', linewidth=2)
plt.plot(x, quick_s_n, color='red', label='Quick Sort', linewidth=2)
plt.plot(x, dual_s_n, color='green', label='Dual Pivot Quick Sort', linewidth=2)
plt.plot(x, hybrid_quick_s_n, color='purple', label='Hybrid Quick Sort', linewidth=2)
plt.plot(x, hybrid_s_n, color='orange', label='Hybrid Sort', linewidth=2)

plt.title(r'$\frac{s}{n}$ Average')
plt.ylabel(r'$\frac{s}{n}$')
#plt.xlabel('n {10 ... 50}') # k=10 i n={10,...,50}
plt.xlabel('n {1000 ... 50000}') #k=100 i n={1000,...,50000}
plt.grid(True)
plt.legend()

plt.show()
plt.close()
