This implementation of a Deque fully works with the provided test.cpp file. The output I got in the local machines after calling "make run" was:

time -p ./DequeTest
---- Deque_MyClass, 14
-1
Mary
3
Tom
0
Mike
1
Joe
2
Mary
0
Mike
0
Mike
0
Mike
1
Joe
2
Mary
1
Joe
0
Mike
1
Joe
2
Mary
2
Mary
0
Mike
1
Joe
2
Mary
1
Joe
0
Mike
0
Mike
1
Joe
2
Mary
1
Joe
0
Mike
1
Joe
2
Mary
2
Mary
0
Mike
1
Joe
2
Mary
2
Mary
0
Mike
0
Mike
1
Joe
2
Mary
1
Joe
0
Mike
1
Joe
2
Mary
2
Mary
0
Mike
1
Joe
2
Mary
0
Mike
1
Joe
2
Mary
---- Deque_int, 10
-1
3
0
1
2
0: 0
1: 1
2: 2
10001 max size
2250755 push_backs, 2249612 push_fronts, 2256641 pop_backs, 2253709 pop_fronts, 17 size
Sum of all integers between 0 and 10000000 calculated using a deque is 49999995000000.
48 allocations totalling 934837180 bytes
real 3.24
user 3.21
sys 0.02

