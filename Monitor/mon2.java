import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.concurrent.ArrayBlockingQueue;
class Monitor
{
    int size;
    ArrayBlockingQueue<Integer> buffer;
    public Monitor(int size)
    {
        this.size = size;
        buffer = new ArrayBlockingQueue<Integer> (size);
        System.out.println("Size of buffer : "+size);
    }
    public void appendD(int D) throws InterruptedException{
        buffer.put(D);
        System.out.println("Item produced : "+D);
        try {
                Thread.sleep(1000);
            } catch (InterruptedException ex) {
                ex.printStackTrace();
            }
    }
    public void takeD() throws InterruptedException
    {
        System.out.println("\t\tItem Consumed : "+buffer.take());
        try {
                Thread.sleep(2000);
            } catch (InterruptedException ex) {
                ex.printStackTrace();
            }
    }
}
class Producer extends Thread
{
    Monitor m;
    int num,size;
    public Producer(Monitor m)
    {
        this.m=m;
        this.size = m.size;
        num=0;
    }
    public void run()
    {
        while(true){
            try{
            m.appendD( (num++)%size);} catch(InterruptedException e){}
        }
    }
}
class Consumer extends Thread
{
    Monitor m;
    public Consumer(Monitor m)
    {
        this.m = m;
    }
    public void run()
    {
        while(true){
            try{m.takeD();} catch(InterruptedException e){}
        }
    }
}
class Main
{
    public static void main(String[] args)
    {
        System.out.print("Enter the size of buffer : ");
        Scanner scan = new Scanner(System.in);
        Monitor m = new Monitor(scan.nextInt());

        Producer p = new Producer(m);
        p.start();

        Consumer c = new Consumer(m);
        c.start();
    }
}