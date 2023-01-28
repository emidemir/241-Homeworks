import java.util.*;

public class driver2{
	public static void main(String arg[])
	{
		System.out.println("Constructers are called, working fine");
		Tetris Game = new Tetris(10,10);
		System.out.println("While calling tetromino constructer, I used 'R' to select a random tetromino" );
		Tetromino Tetro = new Tetromino('R');

		System.out.println("Getters are working fine -> Row : " + Game.getRow() + " Col : " + Game.getCol());
		System.out.println("");

		Vector<Vector<Character>> tempVector = new Vector<Vector<Character>>();

		System.out.println("Tetris Clone function works fine, here is the clone of board vector which is stored on another vector");
		tempVector = Game.clone();

		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				System.out.print(tempVector.get(i).get(j));
			}
			System.out.print('\n');
		}

		System.out.println("Draw function works fine : ");
		Game.Draw();

		System.out.println("Add function works fine, I will add a tetromino to (1,1) position of board");
		Game.Add(Tetro,1,1);

		System.out.println("AddTop methode works fine, this methode adds an element to top row of the board");
		Game.AddTop(Tetro);
		System.out.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		System.out.println("Animate function works fine, But because of the way it works, it will print somewhere above the console. Do not mind it :/");
		Game.animate(Tetro, 1, 2);

		System.out.println("Here is the printed value of tetromino");
		Tetro.printTetromino();
		
		
		System.out.println("We rotated it to right for 90 degree");
		Tetro.tetriminorotateRight90();
		
		System.out.println("Here is the new version of tetromino");
		Tetro.printTetromino();
		

	};
}