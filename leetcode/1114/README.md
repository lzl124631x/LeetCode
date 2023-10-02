# [1114. Print in Order (Easy)](https://leetcode.com/problems/print-in-order)

<p>Suppose we have a class:</p>
<pre>public class Foo {
  public void first() { print("first"); }
  public void second() { print("second"); }
  public void third() { print("third"); }
}
</pre>
<p>The same instance of <code>Foo</code> will be passed to three different threads. Thread A will call <code>first()</code>, thread B will call <code>second()</code>, and thread C will call <code>third()</code>. Design a mechanism and modify the program to ensure that <code>second()</code> is executed after <code>first()</code>, and <code>third()</code> is executed after <code>second()</code>.</p>
<p><strong>Note:</strong></p>
<p>We do not know how the threads will be scheduled in the operating system, even though the numbers in the input seem to imply the ordering. The input format you see is mainly to ensure our tests' comprehensiveness.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> "firstsecondthird"
<strong>Explanation:</strong> There are three threads being fired asynchronously. The input [1,2,3] means thread A calls first(), thread B calls second(), and thread C calls third(). "firstsecondthird" is the correct output.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [1,3,2]
<strong>Output:</strong> "firstsecondthird"
<strong>Explanation:</strong> The input [1,3,2] means thread A calls first(), thread B calls third(), and thread C calls second(). "firstsecondthird" is the correct output.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>nums</code> is a permutation of <code>[1, 2, 3]</code>.</li>
</ul>

**Companies**:
[Microsoft](https://leetcode.com/company/microsoft), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Concurrency](https://leetcode.com/tag/concurrency/)

**Similar Questions**:
* [Print FooBar Alternately (Medium)](https://leetcode.com/problems/print-foobar-alternately/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/print-in-order
// Author: github.com/lzl124631x
#include <semaphore.h>
class Foo {
protected:
    sem_t firstDone, secondDone;
public:
    Foo() {
        sem_init(&firstDone, 0, 0);
        sem_init(&secondDone, 0, 0);
    }
    void first(function<void()> printFirst) {
        printFirst();
        sem_post(&firstDone);
    }
    void second(function<void()> printSecond) {
        sem_wait(&firstDone);
        printSecond();
        sem_post(&secondDone);
    }
    void third(function<void()> printThird) {
        sem_wait(&secondDone);
        printThird();
    }
};
```

<h2 id="solution">Solution</h2>
<hr>
<h4 id="problems-of-concurrency">Problems of Concurrency</h4>
<blockquote>
<p>The concurrency problems arise from the scenario of <a href="https://en.wikipedia.org/wiki/Concurrent_computing" target="_blank">concurrent computing</a>, where the execution of a program is conducted in multiple processes (or threads) <em>simultaneously</em>.</p>
</blockquote>
<p>By simultaneousness, the processes or threads are not necessarily running independently in different physical CPUs, but more often they interleave in the same physical CPU. <em>Note that, the concurrency could apply to either process or thread, we use the words of "process" and "thread" interchangeably in the following sections.</em></p>
<p>The concurrency is designed to above all enable multitasking, yet it could easily bring some bugs into the program if not applied properly. Depending on the consequences, the problems caused by concurrency can be categorized into three types:</p>
<ul>
<li><strong>race conditions</strong>: the program ends with an undesired output, resulting from the sequence of execution among the processes.
<br>
</li>
<li><strong>deadlocks</strong>: the concurrent processes wait for some necessary resources from each other. As a result, none of them can make progress.
<br>
</li>
<li><strong>resource starvation</strong>: a process is perpetually denied necessary resources to progress its works.</li>
</ul>
<p>In particular, our problem here can be attributed to the race conditions. Before diving into the solutions, we show an example of race condition.</p>
<p>Suppose we have a function called <code>withdraw(amount)</code> which deduces certain amount of money from the balance, if the demanding amount is less than the current balance. At the end, the function returns the remaining balance. The function is defined as follows:</p>

```python
balance = 500
def withdraw(amount):
    if (amount < balance):
        balance -= amount
    return balance
```
<p>As we can see, in the normal case, we expect that the <code>balance</code> would never become negative after the execution of the function, which is also the <em>desired</em> behavior of the function.</p>
<p>However, unfortunately we could run into a <em>race condition</em> where the <code>balance</code> becomes negative. Here is how it could happen. Imagine we have two threads invoking the function at the same time with different input parameters, <em>e.g.</em> for thread #1, <code>withdraw(amount=400)</code> and for thread #2, <code>withdraw(amount=200)</code>. The execution of the two threads is scheduled as  the graph below, where at each time instance, we run exclusively only a statement from either threads.</p>
<p><img src="https://leetcode.com/problems/print-in-order/Figures/1114/1114_race_condition.png" alt="pic"></p>
<p>As one can see, at the end of the above execution flow, we would end up with a negative balance, which is not a desired output.<br>
<br><br>
<br></p>
<h4 id="race-free-concurrency">Race-free Concurrency</h4>
<p>The concurrency problems share one common characteristic: multiple processes/threads share some resources (<em>e.g.</em> the variable <code>balance</code>). Since we cannot eliminate the constraint of resource sharing, the key to prevent the concurrency problems boils down to <strong><em>the coordination of resource sharing</em></strong>.</p>
<p>The idea is that if we could ensure <strong><em>the exclusivity of certain critical code section</em></strong> (<em>e.g.</em> the statements to check and deduce the balance), we could prevent the program from running into certain inconsistent states.</p>
<blockquote>
<p>The solution to the race condition becomes clear: we need <strong>certain mechanism</strong> that could enforce the exclusivity of certain critical code section, <em>i.e.</em> at a given time, only one thread can enter the critical section.</p>
</blockquote>
<p>One can consider the mechanism as a sort of <strong><em>lock</em></strong> that restricts the access of the critical section. Following the previous example, we apply the lock on the critical section, <em>i.e.</em> the statements of balance check and balance deduction. We then rerun the two threads, which could lead to the following flow:</p>
<p><img src="https://leetcode.com/problems/print-in-order/Figures/1114/1114_lock.png" alt="pic"></p>
<p>With the mechanism, once a thread enters the critical section, it would prevent other threads from entering the same critical section. For example, at the timestamp #3, the <code>thread #2</code> enters the critical section. Then at the next timestamp #4, the <code>thread #1</code> could have sneaked into the <em>dangerous</em> critical section if the statement was not protected by the lock. At the end, the two threads run concurrently, while the consistency of the system is maintained, <em>i.e.</em> the balance remains positive.</p>
<p>If the thread is not granted with the access of the critical section, we can say that the thread is <em>blocked</em> or put into <em>sleep</em>, <em>e.g.</em> the <code>thread #1</code> is blocked at the timestamp #4. As one can imagine, once the critical section is released, <em>it would be nice to notify the waiting threads</em>. For instance, as soon as the <code>thread #2</code> releases the critical section at the timestamp #5, the <code>thread #1</code> got notified to take over the critical section.</p>
<blockquote>
<p>As a result, it is often the case that the mechanism also comes with the capability to wake up those waiting peers.</p>
</blockquote>
<p>To summarize, in order to prevent the race condition in concurrency, we need a mechanism that possess two capabilities: 1). access control on critical section. 2). notification to the blocking threads.<br>
<br><br>
<br></p>
<hr>
<h4 id="approach-1-pair-synchronization">Approach 1: Pair Synchronization</h4>
<p><strong>Intuition</strong></p>
<p>The problem asks us to complete three jobs in order, while each job is running in a separated thread. In order to enforce the execution sequence of the jobs, we could create some dependencies between pairs of jobs, <em>i.e.</em> the second job should depend on the completion of the first job and the third job should depend on the completion of the second job.</p>
<blockquote>
<p>The dependency between pairs of jobs construct a <em>partial order</em> on the execution sequence of all jobs, <em>e.g.</em> with <code>A &lt; B</code>, <code>B &lt; C</code>, we could obtain the sequence of <code>A &lt; B &lt; C</code>.</p>
</blockquote>
<p><img src="https://leetcode.com/problems/print-in-order/Figures/1114/1114_partial_order.png" alt="pic"></p>
<p>The dependency can be implemented by the concurrency mechanism as we discussed in the previous section. The idea is that we could use a shared variable named <code>firstJobDone</code> to coordinate the execution order between the first job and the second job. Similarly, we could use another variable <code>secondJobDone</code> to enforce the order of execution between the second and the third jobs.</p>
<p><strong>Algorithm</strong></p>
<ul>
<li>First of all, we initialize the coordination variables <code>firstJobDone</code> and <code>secondJobDone</code>, to indicate that the jobs are not done yet.
<br>
</li>
<li>In the <code>first()</code> function, we have no dependency so that we could get straight down to the job. At the end of the function, we then update the variable <code>firstJobDone</code> to indicate that the first job is done.
<br>
</li>
<li>In the <code>second()</code> function, we check the status of <code>firstJobDone</code>. If it is not updated, we then wait, otherwise we proceed to the task of the second job. And at the end of function, we update the variable <code>secondJobDone</code> to mark the completion of the second job.
<br>
</li>
<li>In the <code>third()</code> function, we check the status of the <code>secondJobDone</code>. Similarly as the <code>second()</code> function, we wait for the signal of the <code>secondJobDone</code>, before proceeding to the task of the third job.
<br>
</li>
</ul>
<p><img src="https://leetcode.com/problems/print-in-order/Figures/1114/1114_flow.png" alt="pic"></p>
<p><strong>Implementation</strong></p>
<p>The implementation of the above algorithm heavily depends on the programming language that one chooses, since different languages provide different <strong>constructs</strong> for the concurrency mechanism. Though some of the constructs such as <a href="https://en.wikipedia.org/wiki/Mutual_exclusion" target="_blank">mutex</a> and <a href="https://en.wikipedia.org/wiki/Semaphore_(programming)" target="_blank">semaphore</a> are present across several programming languages including Java, C++ and Python.</p>
<p>Here we provide a few examples using different constructs across the languages. In particular, one could find a nice <a href="https://leetcode.com/problems/print-in-order/discuss/335939/5-Python-threading-solutions-(Barrier-Lock-Event-Semaphore-Condition)-with-explanation" target="_blank">summary</a> in the Discussion forum about the concurrency constructs in Python.</p>