import java.util.*;

/* God damn It There is no typedef in java :/ */

public class Tetris {
	private final char escCode = 0x1B; 
	private Vector<Vector<Character>> Board;
	private int row;
	private int col;


	/**
	 * This methode retruns the row element (amount of horizontal line on board)
	 * @return
	 */
	public int getRow(){return row;};

	/**
	 * This methode retruns the col element (amount of vertical line on board)
	 * @return
	*/
	public int getCol(){return col;};

	/**
	 * This is Constructer.
	 * @param col	Amount of vertical line on board entered by used
	 * @param row
	 * @return void
	 */
	public Tetris(int col, int row){
		this.col = col;
		this.row = row;

		Board = new Vector<Vector<Character>>();
		
		/*Filling Board vector with emmpty space*/
		for (int i = 0; i < row; ++i){
			Vector<Character> temp = new Vector<Character>();
			for (int k = 0; k < col; ++k){
				temp.add(' ');
			}
			Board.add(temp);
		}
	}

	/**
	 * This methode is used in order to deep copy the Board of Tetris object
	 * If something bad happens about indexis and bounds of Vector, it catches that exception.
	 * @return Return value is a 2D vector of Board element of Tetris object.
	 */
	public Vector<Vector<Character>> clone()
	{
		Vector<Vector<Character>> tempObject = new Vector<Vector<Character>>();

		/*First, allocating space for tempVector. Otherwise, there is no room to copy in tempObject*/
		for (int i = 0; i < this.getRow(); ++i)
		{
			Vector<Character> t = new Vector<Character>();
			tempObject.add(i, t);
		}
		
		/*Initializing tempObject with this.Board vector*/
		try
		{
			for (int i = 0; i < this.getRow(); ++i)
			{
				for (int j = 0; j < this.getCol(); ++j)
				{
					tempObject.get(i).add(this.Board.get(i).get(j));	
				}
			}
		}
		catch(Exception e)
		{
			System.out.println("Clone Function has problem with indexes.");
		}

		/*Return the copied value */
		return tempObject;
	}

	/**
	 * This function draws the Tetris object's board
	 * @return void
	 */
	public void Draw(){
		/*Top boarder of board */
		for (int i = 0; i < col+2; i++)
			System.out.print('#');
		
		System.out.print('\n');

		/*Printing Board */
		for (int i = 0; i < row; ++i){
			System.out.print('#');
			for (int j = 0; j < col; ++j){
				System.out.print(Board.get(i).get(j));
			}
			System.out.print("#\n");
		}

		/*Bottom boarder of board */
		for (int i = 0; i < col+2; i++)
			System.out.print("#");
		}	

	/**
	 * This add function gives ability to add tetromino to a certain place on Board
	 * If the tetromino is overflowing the board because of it's size, function returns false 
	 * @param AddedTetromino	Which tetromino is being added currently into Board
	 * @param xAxis	horizontal index position to be added
	 * @param yAxis vertical index position to be added
	 * @return If function adds the tetromino successfully, returns true, otehrwise false
	 */
	public Boolean Add(Tetromino AddedTetromino, int xAxis, int yAxis){
		
		Vector<Vector<Character>>unit = AddedTetromino.GetTetro();

		int vertical = unit.size();
		int horizontal = unit.get(0).size();
	
		/*If tetromino is about to overflow the board, return false*/
		if (xAxis + horizontal > col)
			return (false);
		if (yAxis + vertical > row)
			return (false);
		
		/*Add the tetromino to it's place*/
		for(int i = 0; i < vertical; i++){
			for(int k = 0; k < horizontal; k++){
				/*If current position is not empty, this means ı cannot add tetromino to this place, returning false*/
				if (Board.get(i+yAxis).get(k+xAxis) != ' ')
				{
					return (false);
				}
				Board.get(i+yAxis).set(k+xAxis, unit.get(i).get(k));
			}
		}
		return (true);
	}

	/**
	 * Adds a tetromino only to top center of the board.
	 * @param Tetro	The tetromino to be added
	 * @return void
	 */
	public void AddTop(Tetromino Tetro){

		/*Adding tetromino at the middle of the row*/
		int START_INDEX = col/2-1;

		Vector<Vector<Character>> tempBoard = Tetro.GetTetro();
		int lenght = tempBoard.get(0).size();
		int height = tempBoard.size();
	
		for (int i = 0; i < height; i++)
		{
			for (int k = 0; k < lenght; k++)
			{
				Board.get(i).set(START_INDEX+k,tempBoard.get(i).get(k));
			}
		}
	}
	/**
	 * Animation logic : 
	 * 1) Create a copy of the board with clone methode to keep the first state of the board
	 * 2) Try to add to a certain place
	 * 3) If not possible (add function returns false), than return false (which means game over)
	 * 4) If true, copy the 2D vector which is created on step 1 into Tetris object's Board element and return step 2
	 * 
	 * Step 2 explanation : 
	 * Function firstly tries to animate the board with horizontal moves, after reaching the amount of steps user entered,
	 * moves the tetromino to bottom untill it hits either ground or another tetromino
	 * @param object
	 * @param dir
	 * @param step
	 * @return
	 */
	public Boolean animate(Tetromino object, int dir, int step){
	
		/*Store the first state of Board */
		Vector<Vector<Character>> Holder = this.clone();
		
		/*Counter for horizontal move*/
		int horizontal = col/2;
		
		/*_________Horizontal Move_____________*/
		for (int i = 0; i < step; i++)
		{
			if (Add(object,horizontal,0) == false)
				return (false);
			Draw();
			horizontal += dir;
			
			this.Board = dummyClass.deepCopy(Holder);
			try {
				Thread.sleep(500);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			/*Move the cursor to position (2,0) */
			System.out.print(String.format("%c[%d;%df",escCode,11,0));
		}

		/*_______VERTICAL MOVE________*/
		int vertical = 0;
		while (Add(object,horizontal,vertical++)){	/*As long as object can be added to board, continue */
			Draw();
			this.Board = dummyClass.deepCopy(Holder);	/*Get back the first state of board for new animation frame */
			
			try {
				Thread.sleep(500);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			System.out.print(String.format("%c[%d;%df",escCode,11,0));
		}
		Add(object,horizontal,vertical-2);	/*-2 explanation: 1 decreased for extra 1 incrementation after function call and 1 for invalid */
		Draw();						/*Add fucntion which means 1 incremented state of vertical is false so that ı must decrement 1*/

		return (true);
	}
	
}
