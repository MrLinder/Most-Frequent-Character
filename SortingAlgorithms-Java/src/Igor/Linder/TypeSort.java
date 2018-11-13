package Igor.Linder;

public enum TypeSort{
	SELECTION {
		public String nameSort() {
			return "Selection Sorting"; 
		}
	},
		
	INSERTION {
		public String nameSort() {
			return "Insertion Sorting"; 
		}
	};
	
	public abstract String nameSort();
}
