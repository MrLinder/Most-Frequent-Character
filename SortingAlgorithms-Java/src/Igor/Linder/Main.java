package Igor.Linder;

import java.util.Random;

public class Main {
	
	private static Integer[] array;
	private static SortSelection sortSelection;
	
	public Main() {
	}
	
	public void initializing() {
		System.out.println("Source Array:");
		array = getRandomIntegerArray(100);
		sortSelection = new SortSelection(array);
		printArray();
	}
	
	public void SortingAlgorithms() {
		/*Sorting selection = sortSelection.getSort(TypeSort.SELECTION);*/
		
		Thread selection = new Thread(sortSelection.getSort(TypeSort.SELECTION)); 
				selection.start();
				
		Thread insertion = new Thread(sortSelection.getSort(TypeSort.INSERTION));
				insertion.start();
	}
		
	public static void main(String[] args) {
				
		Thread mainThread = new Thread(new Runnable() {
			@Override
			public void run() {
				Main BasicAlgorithms = new Main();
					 BasicAlgorithms.initializing();
					 BasicAlgorithms.SortingAlgorithms();
			}
		});
			
		mainThread.setName("Main\n");
		mainThread.start();
		System.out.println("Thread: " + mainThread.getName());
	}
	
	
	private Integer[] getRandomIntegerArray(Integer n) {
		Random rand = new Random();
		Integer[] arr = new Integer[n];
		
		for (int i = 0; i < arr.length; i++) 
			arr[i] = rand.nextInt(n+1);
		return arr;
	}
			
	private <T> void printArray() {
		printArray(array);
	}
		
	private <T> void printArray(T[] arr) 
	{
		int newStrCount = 0;
		int size = arr.length;
				
		int sizeDeli = size;
		int countDeli = -2;
					
		String[] delimiter = {"%1d ","%2d ","%3d ","%4d ","%5d ","%6d ","%7d ","%8d ","%9d ","%10d "};
				
			while(sizeDeli != 0){
				sizeDeli = sizeDeli/10;
				countDeli++;
			}
					
			for (int i = 0; i < size; i++)
			{
				System.out.printf(delimiter[countDeli], arr[i]);
								
				newStrCount ++;
				if( (size <= 100 && newStrCount  == 25) || (size > 100 && size <= 1000 && newStrCount == 20) || (size > 1000 && newStrCount == 10)) {
					System.out.println();
					newStrCount=0;
				} 
			} 
	}
}




