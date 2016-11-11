public class FileAccessTest
{
	public static void main(String[] args)
	{
		if(args.length < 3) {
			System.out.println("Usage: java FileAccessTest <numThreads> <max sum> <iterations>");
			System.exit(1);
		}
		int numThreads = Integer.parseInt(args[0]);
		int maxSum = Integer.parseInt(args[1]);
		int iterations = Integer.parseInt(args[2]);

		FileAccess accessor = new FileAccess(maxSum);

		Accessor accessors[] = new Accessor[numThreads]; 
		for(int i = 0; i<numThreads; i++) {
			accessors[i] = new Accessor(i+1, accessor, iterations);
			accessors[i].start();
			System.out.println("Thread " + (i+1) + " starting file access.");
		}
		for(int i = 0; i<numThreads; i++) {
			try {
				System.out.println("Thread " + (i+1) + " ending file access.");
				accessors[i].join(30000);
			} catch (InterruptedException e) {System.err.println(e);}
		}

		for(int i = 0; i<numThreads; i++) {
			if(accessors[i].isAlive()) {
				System.out.println("ALARM!!! ALARM!!! ALARM!!! TIMEOUT!!!");
				accessors[i].interrupt();
			}
		}
	}
}
