import java.util.*;
import java.util.Random;
import java.util.concurrent.Semaphore;
class producerconsumer
{
private static final int BUFFER_SIZE=10;
private static volatile Semaphore empty=new Semaphore(BUFFER_SIZE);
private static volatile Semaphore full=new Semaphore(0);
private static volatile Semaphore mutex=new Semaphore(1);
private static volatile ArrayList<Integer> list=new ArrayList<Integer>(BUFFER_SIZE);
static class Producer extends Thread
{
public void run()
{
for(int i=0;i<5;++i)
{
try
{
Random rand= new Random();
empty.acquire();
mutex.acquire();
list.add(rand.nextInt(100));

System.out.println("PRODUCER PRODUCED ITEM"+list.size()+"="+list.get(list.size()-1));
mutex.release();
full.release();
Thread.sleep(1000);
}catch(Exception e)
{
System.out.println("Producer Interrupted");
}
}
}
}
static class Consumer extends Thread
{
public void run()
{
for(int i=0;i<5;++i)
{
try
{
full.acquire();
mutex.acquire();
int removed=list.get(list.size()-1);
list.remove(list.size()-1);

System.out.println("Consumer consumed item"+removed);
mutex.release();
empty.release();
Thread.sleep(1000);
}catch(Exception e)
{
System.out.println("Consumer Interrupted");
}
}
}
}
public static void main(String args[])
{
new Producer().start();
new Consumer().start();
}
}