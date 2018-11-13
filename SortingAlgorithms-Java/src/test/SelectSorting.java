package test;

public class SelectSorting {
			
	public Sorting getSort(TypeSort type) {
		
		Sorting sorting =  null;
		
		switch (type) {
		case SELECT: sorting = new Selection();
			
			break;
		
		case BOUBLE: sorting = new Buble();
			
			break;

		}
		
		return sorting; 
	}
	
	
}
