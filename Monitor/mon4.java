import java.util.Scanner;
import java.util.Random;
class Monitor extends Thread
{
	int printerNumber;
	synchronized public void startPrint(String name)
	{
		// System.out.println(name+"wants printer");
		try
		{

		if(printerNumber>=3)
		{
			while(printerNumber>=3)
			{
				wait();
			}
		}
		}
		catch(InterruptedException e)
		{
			e.printStackTrace();
		}

		System.out.println(name+" aquired printer "+printerNumber);
		printerNumber=printerNumber+1;

	}
	synchronized public void stopPrint(String name)
	{
		System.out.println("\t\t\t\t"+name+" released the printer");
		printerNumber=printerNumber-1;
		if(printerNumber<3)
		{
		 notifyAll();
		}

	}
}
class P extends Thread
{
	Monitor m;
	String name;
	P(int num,String name,Monitor m)
	{
		this.m=m;
		this.name=name;
	}
	public void run()
	{
		while(true)
		{
			try{sleep(1000);}catch(InterruptedException e){}

			m.startPrint(name);
			System.out.println("\t\t"+name+" ("+getPriority()+") : printing");
			m.stopPrint(name);

			try{sleep(1000);}catch(InterruptedException e){}
		}
	}
}
class Main extends Thread
{
	static int n;
	public static void main(String args[])
	{

 				Scanner sc=new Scanner(System.in);
 				// Random rand = new Random();
				 int range = MAX_PRIORITY - MIN_PRIORITY +1;
				Monitor m=new Monitor();
				System.out.print("Enter the total number of processes : ");
				n=sc.nextInt();
				P threads[]=new P[n];
				for(int i=1;i<=n;i++)
				{
					threads[i-1]=new P(i,i+"",m);
					threads[i-1].setPriority( (int)(Math.random()*range) );
				}
				for(int i=1;i<=n;i++)
				{
					threads[i-1].start();
				}

	}
}