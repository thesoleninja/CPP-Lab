
workspace/
mon1.java


1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
class Monitor extends Thread
{
    int s;
    Monitor(int k)
    {    s=k;   }
    public synchronized void waitc()
    {
        if(s<=0){   try{wait();
            System.out.println(Thread.currentThread().getName()+" has owned the monitor.");
        } catch(Exception ex){} }
        System.out.println(Thread.currentThread().getName()+" has owned the monitor.");
        s--;
    }
    public synchronized void signalc()
    {
        s++;
        System.out.println(Thread.currentThread().getName()+" releasing the monitor");
        notify();
    }
}
class P extends Thread
{
    Monitor m;
    public P(Monitor x, String threadName)
    {
        super(threadName);
        m=x;
        start();
    }
    public void run()
    {
        while(true)
        {
            System.out.println(Thread.currentThread().getName()+" NCS");
            m.waitc();
            m.signalc();
            System.out.println(Thread.currentThread().getName()+" exiting the monitor.");
        }
    }
}
class Main
{
    public static void main(String[] args)
    {
        Monitor sem = new Monitor(1);
1:1
workspace/
GET - Idle


[Idle]

Run

GET
Command:

GET http localhost:8080/images
Runner: Shell command
CWD
ENV
CollaborateOutlineDebugger
