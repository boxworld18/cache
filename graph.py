import matplotlib.pyplot as plt

"""
Test 1
Cache Size
"""
# with open('1.txt', 'r') as f:
#     test_sizes = []
#     times = []
    
#     datas = f.readlines()
#     for data in datas:
#         res = data.replace('\n', '').split(' ')
#         test_sizes.append(int(res[0]))
#         times.append(float(res[1]))
        
#     plt.plot(test_sizes, times, marker='o')
#     plt.xscale('log', base=2) # 使用以2为底的对数刻度
#     plt.xlabel('Test Size (KB)')
#     plt.ylabel('Time (s)')
#     plt.title('Test Size vs Time')

#     # 设置 x 轴上的刻度
#     plt.xticks(test_sizes, [str(size) for size in test_sizes])

#     plt.show()

"""
Test 2
Cache Line Size
""" 
# with open('2.txt', 'r') as f:
#     stride = []
#     times = []
    
#     datas = f.readlines()
#     for data in datas:
#         res = data.replace('\n', '').split(' ')
#         stride.append(int(res[0]))
#         times.append(float(res[1]))
        
#     plt.plot(stride, times, marker='o')
#     plt.xscale('log', base=2) # 使用以2为底的对数刻度
#     plt.xlabel('Stride (B)')
#     plt.ylabel('Time (s)')
#     plt.title('Stride vs Time')

#     # 设置 x 轴上的刻度
#     plt.xticks(stride, [str(size) for size in stride])

#     plt.show()

"""
Test 3
Cache Associativity
Method 1
"""
with open('3.txt', 'r') as f:
    stride = []
    times = []
    
    datas = f.readlines()
    for data in datas:
        res = data.replace('\n', '').split(' ')
        stride.append(int(res[0]))
        times.append(float(res[1]))
        
    plt.plot(stride, times, marker='o')
    plt.xlabel('n')
    plt.ylabel('Time (s)')
    plt.title('n vs Time')

    # 设置 x 轴上的刻度
    plt.xticks(stride, [str(size) for size in stride])

    plt.show()

"""
Test 3
Cache Associativity
Method 2
""" 
# with open('3.txt', 'r') as f:
#     stride = []
#     times = []
    
#     datas = f.readlines()
#     for data in datas:
#         res = data.replace('\n', '').split(' ')
#         stride.append(int(res[0]))
#         times.append(float(res[1]))
        
#     plt.plot(stride, times, marker='o')
#     plt.xscale('log', base=2) # 使用以2为底的对数刻度
#     plt.xlabel('test associativity')
#     plt.ylabel('Time (s)')
#     plt.title('test associativity vs Time')

#     # 设置 x 轴上的刻度
#     plt.xticks(stride, [str(size) for size in stride])

#     plt.show()