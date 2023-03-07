# NPC-problem
对具体的一个NP完全问题进行近似求解（贪心法），并对正确率进行计算，用以算法评价
### 题目
某街道给封控在家的居民们发来了大礼包，大礼包里包含N种不同的瓜果蔬菜。居民们在探究如何更有效地把这些原材料组合做出更美味的菜肴。假定给出大小为N×N的矩阵a，矩阵中每个位置的元素a[i][j] j]∈[0,1]代表第i种蔬菜和第j种蔬菜的排斥程度，a[i][j]越小证明这两种蔬菜越适配，越大越排斥。假设N=3时，给定对称矩阵如下：
|   | 1    | 2    | 3    |
|---|------|------|------|
| 1 | 0.0  | 0.6  | 0.2  |
| 2 | 0.6  | 0.0  | 0.1  |
| 3 | 0.2  | 0.1  | 0.0  |

例如：
对角线上的元素全都是0，证明第i种蔬菜和自己完美搭配，但是第1种蔬菜和第2种蔬菜的匹配程度不够好。假设居民选择某种蔬菜集合𝑆，定义该集合的总排斥度为𝑇 = ΣΣ𝑎[𝑖][𝑗] (𝑗 > 𝑖, 𝑗∈𝑆, 𝑖∈𝑆)。在上述给定匹配矩阵中，选取全部三种蔬菜𝑆={1,2,3}时的总排斥度$$𝑇_𝑆=0.6+0.2+0.1=0.9$$。
 
 
