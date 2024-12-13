# IMP 阵列模拟代码

## 在线模拟

cd geant4

./make.sh

cd build

./geant4 (par1) (par2)

### 运行参数说明

1、无参数输入，则开启命令行模式。注意每次只能运行一次 /run/beamOn 命令，否则会出现无法预料的错误。

2、第一参数为整数，则 geant4 将运行一次 /run/beamOn (par1) 命令（参数作为 event 数目），并自动拷贝文件至 ../../root 文件夹

3、第一参数为 -v，则开启图形界面（即运行脚本 ./build/scripts/vis.mac）

4、第一参数为其他脚本的路径，则 geant4 将自动运行该脚本

5、第二参数应为整数，指定多线程的数目；若无有效的第二参数，则线程数默认为 2

### 用户定义

1、./geant4/src/StackingAction.cc，定义了一个 TSpline 样条函数，用于模拟吸收片对低能 gamma 效率的抑制。1-TSpline::Eval(E) 表示随机 kill 掉能量为 E 的（衰变产生的） gamma 的概率。可通过修改样条上的数据点位置来调整样条函数形状。

2、./geant4/src/PrimaryGeneratorAction.cc，可修改混合源（包括环境本底源）的比例。

3、./geant4/main.cc 可修改调用自定义纲图文件。目前修改了 65,67Ga 的纲图，去掉了1847和1714两条跃迁。

4、./geant4/src/StackingAction.cc，杀死了 RadioactiveDecay 过程产生的非 gamma 和非 Ga 粒子，即不模拟 Ga 的衰变。其他元素需要在此更改名称。

## 离线分析

1、g4coin.C：按泊松分布规律，随机产生相邻事件的时间间隔，从而给每一步能量沉积加上 timestamp。随后模拟获取系统的触发，组织符合事件，然后将符合事件中相同探头的能量沉积合并，并标记事件来源（以区分真符合与偶然符合）。输出 root/g4coin.root

2、g4anticompton.C：反康，生成 ghit ge ahit ae 。输出 root/g4anticompton.root

3、g4reso.C：卷积探测器分辨，即给 ge 和 ae 加上（能量依赖的）高斯随机数。输出 root/g4reso.root

4、g4hist.C：从 root/g4reso.root 生成原始矩阵 hg2xy、偶然符合矩阵 hg2xyb2、（非偶然符合的）康普顿矩阵 hg2xyb1。输出 root/g4hist.root

5、g4radware.C：radware 方法扣原始矩阵 hg2xy 的本底。输出 root/g4radware.root

### 用户定义

1、g4coin.C，可修改活度（事件率）、符合窗宽度、探测器死时间。

## 运行示例

./run_simulation.sh [nevents]


