package Igor.Linder;

public class Insertion extends ArchetypeSort {

	public Insertion(int[] arr, String name) {
		super(arr, name);
		// TODO Auto-generated constructor stub
	}

	@Override
	public void run() {
		System.out.println(Thread.currentThread().getName() + " -> " + super.nameSort + ": ");
		
	}

}
