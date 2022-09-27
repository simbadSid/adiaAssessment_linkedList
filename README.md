# Simply-linked list with optimized backward-exploration


## Proposed algorithms
In this project, we propose two list implementations using a simply-linked list.
Using these algorithms, we manage to perform both forward and backward list-exploration with a linear algorithmic complexity and no memory overhead.

### Algorithm "SimplyLinkedList_0_orderRefactor":
When an exploration is required following a pattern that is not the current pattern of the list, then the list is reverted before it explored.

### Algorithm "SimplyLinkedList_1_twoPointersInOne":
In this implementation we replace the "next" pointer of each node with a single value containing a combination of the addresses of the previous and the next nodes.
Using this combination function, we are able to compute the next node of each node knowing its address and the address of its previous node.
Similarly and with the same operation, we are able to compute the previous node of each node knowing its address and the address of its next node.

Let us call Merge() the function used to combine two addresses.
Let us also assume that this function:
  * is associative
  * is commutative
  * admits a neutral element (e.g. 0)
  * insures that Merge(x, x) = 0 for eac address x

  Consequently, knowing the addresses of:
  * a given node at a position n (hence knowing Merge(n-1, n+1))
  * the address of its predecessor (respectively successor) n-1 (respectively n+1)

  we are able to compute the address of its successor (respectively predecessor) n+1 as follows:
  ```
  Merge(n, n-1) = Merge(Merge(n-1, n+1), n-1)
                = Merge(Merge(n+1, n-1), n-1)
                = Merge(n+1, Merge(n-1, n-1))
                = Merge(n+1, 0)
                = n+1
  ```


## Experimental benchmark
In the following figure, we present the experimental execution time of each algorithm in each considered scenario. 
<p float="left">
  <img src="/resource/benchmark_0_orderRefactor.png"    width="400" />
  <img src="/resource/benchmark_1_twoPointersInOne.png" width="400" /> 
</p>

We also compare the performance of the two algorithms per considered scenario
<p float="left">
  <img src="/resource/benchmark_onlyForward.png"    width="400" />
  <img src="/resource/benchmark_onlyBackward.png" width="400" /> 
  <img src="/resource/benchmark_onlyBackward.png"    width="400" />
  <img src="/resource/benchmark_randomForwardBackward.png" width="400" /> 
</p>

Each experimental result that is presented is the average time of 5 executions on the same input.
This experimental benchmark has been tested on an x86 machine implementing two 10-core Intel Xeon E5-2660v2 (2.2GHz) chips.
A linux (3.16.7-4) operating system has been used based on the Debian kernel 3.16.7.
The default kernel allocation policy (first touch) has been used to obtain all the presented results.
The \textit{g++ 4.4.7} has been used to compile the code along with the -O3 option (maximum optimization level).

## Build and test
This project uses the CMake framework.
In order to build the project, we need to run the following command
```
mkdir bin
cd bin
cmake ../
make;
```

Building the project results in generating the following executable files:
* __bin/main\<scenarioName\>__: benchmarks the proposed implementation/scenario with different list sizes.
* __bin/main\<scenarioName\>verbose__: runs the corresponding implementation/scenario in a verbose mode.

In order to test the functional correctness of our algorithms, we have implemented a set of unit tests.
These tests may be run using:
```
cd bin
cmake ../
make;
ctes
```
The test framework that we used (CTest) is integrated within the CMake framework and requires no external installation.