import java.util.Vector;

enum Shapes {TypeI,TypeO,TypeT,TypeJ,TypeL,TypeS,TypeZ, TypeEmpty_Block,TypeQuit,TypeRandom};

public class Tetromino{
	private char Type;							/*Tetromino Type*/
	private int row;							/*Row NUmber of Tetromino*/
	private int col;							/*Column number of tetromino*/
	private Vector<Vector<Character>>Tetromino;	/*Tetromino Board*/
	/**
	 * This methodes creates a 2D vector with I chars and assign it to Tetromino element of Tetromino class
	 */
	private void CreateI(){
		row = 4;
		col = 1;
		for (int i = 0; i < 4; ++i)
		{
			Vector<Character> temp = new Vector<>();
			temp.add('I');
			Tetromino.add(temp);
		}
	};
	/**
	 * This methodes creates a 2D vector with O chars and assign it to Tetromino element of Tetromino class
	 */
	private void CreateO(){
		row = 2;
		col = 2;
		for (int i = 0; i < 2; ++i)
		{
			Vector<Character> temp = new Vector<>();
			for (int j = 0; j < 2; ++j)
			{
				temp.add('O');
			}
			Tetromino.add(temp);
		}
	}
	/**
	 * This methodes creates a 2D vector with T chars and assign it to Tetromino element of Tetromino class
	 */
	private void CreateT(){
		row = 3;
		col = 3;
		{
			Vector<Character> tempVector = new Vector<Character>();
			tempVector.add('T');
			tempVector.add('T');
			tempVector.add('T');
			Tetromino.add(tempVector);
		}
		{
			Vector<Character> tempVector = new Vector<Character>();
			tempVector.add(' ');
			tempVector.add('T');
			tempVector.add(' ');
			Tetromino.add(tempVector);
		}
		{
			Vector<Character> tempVector = new Vector<Character>();
			tempVector.add(' ');
			tempVector.add('T');
			tempVector.add(' ');
			Tetromino.add(tempVector);
		}
	}
	/**
	 * This methodes creates a 2D vector with J chars and assign it to Tetromino element of Tetromino class
	 */
	private void CreateJ(){
		row = 3;
		col = 2;

		{
			Vector<Character> tempVector = new Vector<Character>();
			tempVector.add(' ');
			tempVector.add('J');
			Tetromino.add(tempVector);
		}
		{
			Vector<Character> tempVector = new Vector<Character>();
			tempVector.add(' ');
			tempVector.add('J');
			Tetromino.add(tempVector);
		}
		{
			Vector<Character> tempVector = new Vector<Character>();
			tempVector.add('J');
			tempVector.add('J');
			Tetromino.add(tempVector);
		}
	}
	/**
	 * This methodes creates a 2D vector with L chars and assign it to Tetromino element of Tetromino class
	 */
	private void CreateL(){
		row = 3;
		col = 2;

		{
			Vector<Character> tempVector = new Vector<Character>();
			tempVector.add('L');
			tempVector.add(' ');
			Tetromino.add(tempVector);
		}
		{
			Vector<Character> tempVector = new Vector<Character>();
			tempVector.add('L');
			tempVector.add(' ');
			Tetromino.add(tempVector);
		}
		{
			Vector<Character> tempVector = new Vector<Character>();
			tempVector.add('L');
			tempVector.add('L');
			Tetromino.add(tempVector);
		}
	};
	/**
	 * This methodes creates a 2D vector with S chars and assign it to Tetromino element of Tetromino class
	 */
	private void CreateS(){
		row = 2;
		col = 3;

		{
			Vector<Character> tempVector = new Vector<Character>();
			tempVector.add(' ');
			tempVector.add('S');
			tempVector.add('S');
			Tetromino.add(tempVector);
		}

		{
			Vector<Character> tempVector = new Vector<Character>();
			tempVector.add('S');
			tempVector.add('S');
			tempVector.add(' ');
			Tetromino.add(tempVector);
		}	
	};
	/**
	 * This methodes creates a 2D vector with Z chars and assign it to Tetromino element of Tetromino class
	 */
	private void CreateZ(){
		row = 2;
		col = 3;
		{
			Vector<Character> tempVector = new Vector<Character>();
			tempVector.add('S');
			tempVector.add('S');
			tempVector.add(' ');
			Tetromino.add(tempVector);
		}	
		{
			Vector<Character> tempVector = new Vector<Character>();
			tempVector.add(' ');
			tempVector.add('S');
			tempVector.add('S');
			Tetromino.add(tempVector);
		}
	};
	
	/**
	 * This is Tetromino classes constructer.
	 * @param Type This char is deciding which tetromino to be created
	 */
	Tetromino(char Type){

		Tetromino = new Vector<Vector<Character>>();

		if (Type == 'R'){
			char[] RandomTetromino = {'I','O','T','J','L','S','Z'};
			Type = RandomTetromino[(int)Math.random()*7];
		}

		if (Type == 'I'){
			this.Type = Type;
			CreateI();
		
		}else if (Type == 'O'){
			this.Type = Type;
			CreateO();
		}else if (Type == 'T'){
			this.Type = Type;
			CreateT();
		}else if (Type == 'J'){
			this.Type = Type;
			CreateJ();
		}else if (Type == 'L'){
			this.Type = Type;
			CreateL();
		}else if (Type == 'S'){
			this.Type = Type;
			CreateS();
		}else if (Type == 'Z'){
			this.Type = Type;
			CreateZ();
		}
	}

	/**
	 * This methode is only printing the tetromino
	 */
	public void printTetromino(){
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				System.out.println(Tetromino.get(i).get(j));
			}
			System.out.println("\n");
		}
	}

	/**
	 * This methode returns a tetromino to right 90 degree
	 * Logic : 
	 * A 2D vector of T which is
	 * I
	 * I
	 * I
	 * I
	 * 
	 * is continuous on memory like I/I/I/I
	 * If we create another 2D vector as /..../ which has 1 sub vectors in it which has 4 elements
	 * and by starting to copy from last elment of last vector to first element of first vector to this new vector
	 * we can have this /IIII/
	 * IIII
	 */
	public void tetriminorotateRight90(){

		int newLenght = row;	/*Height and lenght variables are gonna change if we rotate tetromino*/
		int newHeight = col;
	
		/*Create new array for rotated tetromino*/
		Vector<Vector<Character>> rotatedTetro = new Vector<Vector<Character>>();

		/*Allocating for 2D vector*/
		for (int i = 0; i < newHeight; ++i)
		{
			Vector<Character> tempVector = new Vector<Character>();
			rotatedTetro.add(tempVector);
		}
	
		int x = 0;	/*This is a counter for index of rotatedTetro*/
		
		/*This is an algorithm which depends on the fact that data is stored as line on memory.*/
		for (int i = 0; i <col ; i++){
			for (int k = row-1; k >= 0; k--){
				rotatedTetro.get(i).add(Tetromino.get(k).get(i));
				x++;
			}
			x = 0;
		}
		
		/*Assign new vector into old one*/
		Tetromino = rotatedTetro;
	
		/*Change old lenght and height variable*/
		col = newLenght;
		row = newHeight;
	}

	/**
	 * This gether method returns a copy of Tetromino vector of Tetromino class
	 * @return
	 */
	public Vector<Vector<Character>> GetTetro(){
		return Tetromino;
	}

}

