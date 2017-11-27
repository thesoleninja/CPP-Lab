class Monitor extends Thread{
    int fork[] = new int[5];

    Monitor(){
        for (int i = 0; i < 5; i++)
                fork[i] = 2;
    }
    public synchronized void takeForks(int i){
        if (fork[i]!=2)
            try{wait();} catch(Exception e){}
        fork[(i+5 + 1) % 5]--;
        fork[(i+5 - 1) % 5]--;
    }
    public synchronized void releaseForks(int i){
        fork[(i+5 + 1) % 5]++;
        fork[(i+5 - 1) % 5]++;
        notify();
    }
}

class Philosopher extends Thread{
    Monitor m;
    int i;
    public Philosopher(Monitor m, int i){
        // super(""+i);
        this.m = m; this.i=i;
        start();
    }
    public void run(){
        while(true){
            System.out.println("\t\t\tPhilosopher "+(i+1)+": thinking.");
            Sleep();
            m.takeForks(i);

            Sleep();
            System.out.println("Philosopher "+(i+1)+":eating.");

            System.out.println("\t\t\t\t\t\tPhilosopher "+(i+1)+":released the forks.");
            m.releaseForks(i);
            Sleep(); Sleep();


        }
    }
    public static void Sleep(){
        try {
                        sleep(1000);
                    } catch (InterruptedException ex) {
                        ex.printStackTrace();
                    }
    }
}

class Main extends Thread{


    public static void main(String []args){
        Monitor m = new Monitor();
        for (int i=0; i<5; i++){
            Philosopher p = new Philosopher(m,i);
        }
    }
}