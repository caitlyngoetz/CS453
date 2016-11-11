public class FileAccess {

	private long max;
	private long sum;
	
	public FileAccess(long max)
	{
		this.max = max;
		this.sum = 0;
	}

	public synchronized void startAccess(long id) throws InterruptedException
	{
		while(sum + id > max) {
			wait();
		}
		sum += id;
	}

	public synchronized void endAccess(long id)
	{
		sum -= id;
		notifyAll();
	}
}
