import java.util.*;

public class Accessor extends Thread
{
	private FileAccess accessor;
	private Random sleeper;
	private final int RANGE = 5;
	private int id;
	private int iterations;

	public Accessor(int id, FileAccess accessor, int iterations)
	{
		this.accessor = accessor;
		this.id = id;
		this.iterations = iterations;
		sleeper = new Random();
	}

	public void run()
	{
		for(int i = 0; i < iterations; i++) {
			try {
				accessor.startAccess(id);
				Thread.sleep(SleepTime());
				accessor.endAccess(id);
				Thread.sleep(SleepTime());
			} catch (InterruptedException e) {
				break;
			}
		}
	}

	private int SleepTime()
	{
		return (sleeper.nextInt(RANGE)+1) * 100;
	}
}
