# FlashGPU
### Simulator for DAC paper "FlashGPU: Placing New Flash Next to GPU Cores".

## Downloads
```
git --recursive clone /path/to/the/repo
```
## Install
```
cd FlashGPU
./build.py --simplessd -j8
```
## Execution
```
cd bin/
./macsim 
```
## FlashGPU overview
![](/img/overview.jpg)
The above figure shows an overview of FlashGPU integration architecture. FlashGPU employs a *flash cache* that handles a write buffer and a read buffer in front of Z-NAND arrays. This cache communicates with access pattern tracker being aware of each warp execution behavior based on its program counter (PC) so that it can decide whether FlashGPU needs to fetch target data in a super-page scheduling manner. Since SMs are designed towards achieving massive parallel computing, it does not fit to implement device management. We thus allocate a few ALU logic, referred to as *flash core*, which installs most flash firmware components, including host interface layer (HIL), flash translation layer (FTL) and flash interface layer (FIL). HIL handles the request by communicating with a router, which is assigned to the flash core, while FTL and FIL manage the address translation and flash protocol/timing, respectively. The flash core also implements our flash cache. 

As shown in the figure, LD/ST instructions running on FlashGPU generate memory requests, which access the L1 cache of SM. In the case of L1 cache misses, the memory requests are forwarded to shared L2 cache via the interconnect network (<font color=red>1</font>). The memory request is firstly staged in the input queue of L2 cache. The L2 cache then processes the memory requests in the input queue in a FIFO manner (<font color=red>2</font>). For L2 cache misses, the memory requests are inserted in the output queue (<font color=red>3</font>), and an entry in MSHR is registered by updating cache line address, memory address and thread ID (<font color=red>4</font>). The requests in the output queue are dispatched, converted to a network packet with the information of source endpoint ID and destination endpoint ID, and forwarded to the flash core over the network (<font color=red>5</font>). If the packet arrives, the flash core's interface controller dispatches such packet from the flash-side router. Afterward, HIL re-constructs the memory requests by extracting the information of memory address, access type and length from the target packet (<font color=red>6</font>). The flash cache then checks if the request hits in its read buffer or write buffer. If there is a miss, the request is required to be served by Z-NAND. FTL translates the target memory address to a physical block address while FIL manages flash protocol and memory transaction (<font color=red>7</font>). The response of the memory request (with data) then is forwarded to L2 cache through the network again (<font color=red>8</font>). In L2 cache, the response is inserted in the fill queue (<font color=red>9</font>). L2 cache extracts the target data and memory address from the response residing on the fill queue. The memory address is used for identifying and releasing the entry of MSHR (<font color=red>9</font>), and then the fetched data is stored in L2 cache (<font color=red>10</font>). This process is also applied to L1 cache so that stalled LD/ST instructions can be resumed from the target SM. 

## Simulation model
![](/img/designmodel.jpg)
We implement our model by revising [MacSim](https://github.com/gthparch/macsim) and [SimpleSSD](http://simplessd.camelab.org/). The above figure shows the key GPU parameters such as the clock frequency of CPU, L1, L2 and network, cache line size, and associativity. The GPU cores (SM) inputs the trace files, which will be provided as a part of our open source framework as well as can be extracted by Ocelot. The memory requests missed from L2 is forwarded to HIL (in SimpleSSD) over network-on-chip (NoC) model as a form of packet. During this process, the input/output queues are also simulated for all endpoints, including caches and Z-SSD in the NoC model side. HIL parses the network packet and communicates the buffer manager that implement. The request is passed through other flash related software, such as FTL and FIL, and then returned back to the NoC model by calculating end-to-end latency of each I/O accesses. In our model, caching all memory requests are performed in MacSim side, while memory requests (missed from the caches) are managed by SimpleSSD.

## Citation
Our paper entitled by "FlashGPU: Placing New Flash Next to GPU Cores" is accepted by Design Automation Conference (DAC) [[ACM](http://delivery.acm.org/10.1145/3320000/3317827/a156-Zhang.pdf?ip=143.248.41.136&id=3317827&acc=ACTIVE%20SERVICE&key=0EC22F8658578FE1%2E7500FBAD1E9579D9%2E4D4702B0C3E38B35%2E4D4702B0C3E38B35&__acm__=1566286021_482fbe93ad05cdfb89f964d14bd94fcf)].

Jie Zhang, Miryeong Kwon, Hyojong Kim, Hyesoon Kim, Myoungsoo Jung,
"**FlashGPU: Placing New Flash Next to GPU Cores**", in the 57th Design Automation Conference, 2019.

## People

* Prof. Myoungsoo Jung (Project Leader) at Korea Advanced Institute of Science and Technology (KAIST) 
(http://camelab.org/pmwiki.php/Main/Members) 


## Mailing list

If you have a question, feel free to send an email to jie@camelab.org.
