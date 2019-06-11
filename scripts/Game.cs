using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Game : MonoBehaviour
{
    private GameObject Respawn;
    public struct Move
    {
        public int row;
        public int col;
    };
    private Move bestMove;
    private int MaxDepth=0;

    private List<List<char>> board = new List<List<char>>();
    private int ROZMIAR = Settings.ROZMIAR;
    private int WYGRANA = Settings.WYGRANA;
    private char player = 'x';
    private char opponent = 'o';
    

    void Start()
    {
        Debug.Log("Inicjalizuje");

        //Respawn = GameObject.FindWithTag("Respawn");
        //Respawn R = Respawn.GetComponent<Respawn>();
        //ROZMIAR = R.rozmiar;

        Lista();
       
    }




    //Funkcja Inicjalizujaca Liste
    private void Lista()
    {
        for (int i = 0; i < ROZMIAR; i++)
        {
            board.Add(new List<char>());
        }
        for (int i = 0; i < ROZMIAR; i++)
        {
            for (int j = 0; j < ROZMIAR; j++)
            {
                board[i].Add('_');
            }
        }
    }

    //Funkcja sprawdzajaca czy zostal jakis niezajety element na planszy (jesli jest, zwraca true)
    public bool IsMoveLeft()
    {
        for (int i = 0; i < ROZMIAR; i++)
        {
            for (int j = 0; j < ROZMIAR; j++)
            {
                if (board[i][j] == '_')
                    return true;
            }
        }
        return false;
    }

    //Sprawdza czy ktos wygral
    public int evaluate()
    {
        int licznik = 0;
        int bestscore = 0;
       // int x=0;
        
        //Sprawdza czy w jakims wierszu wygral x lub o
        for (int row = 0; row < ROZMIAR; row++)
        {
            licznik = 0;
           // x = 0;
            for (int col = 0; col < ROZMIAR - 1; col++)
            {
               // if (board[row][col] == opponent || board[row][col + 1] == opponent)
                 //   x++;
                if (board[row][col] !='_' && board[row][col + 1]!='_')
                {
                    if (board[row][col] == board[row][col + 1])
                        licznik++;
                    
                    if (licznik > bestscore)
                    {
                        if (board[row][col] == player)
                            bestscore = licznik;
                    }

                    if (board[row][col] != board[row][col + 1])
                        licznik = 0;
                    if (licznik == WYGRANA - 1)
                    {
                        if (board[row][col] == player)
                            return +1000;
                        if (board[row][col] == opponent)
                            return -1000;
                    }

                }
                //if (x > ROZMIAR - WYGRANA) bestscore = 0;

                if (board[row][col] == '_') licznik = 0;

            }
        }

        //Sprawdza czy w jakiejs kolumnie wygral x lub o
        for (int col = 0; col < ROZMIAR; col++)
        {
            licznik = 0;
            //x = 0;
            for (int row = 0; row < ROZMIAR - 1; row++)
            {
               // if (board[row][col] == opponent || board[row + 1][col] == opponent)
                //    x++;
                if (board[row][col] !='_' && board[row + 1][col]!='_')
                {
                    if (board[row][col] == board[row + 1][col])
                        licznik++;
                    

                    if (licznik > bestscore)
                    {
                        if (board[row][col] == player)
                            bestscore = licznik;

                    }

                    if (board[row][col] != board[row + 1][col])
                        licznik = 0;

                    if (licznik == WYGRANA - 1)
                    {
                        if (board[row][col] == player)
                            return +1000;
                        if (board[row][col] == opponent)
                            return -1000;
                    }
                }
                //if (x > ROZMIAR - WYGRANA) bestscore = 0;
                if (board[row][col] == '_') licznik = 0;
            }
        }

        //Sprawdza czy na jakiejs przekatnej wygral x lub o
        for (int row = 0; row < ROZMIAR; row++)
        {
            licznik = 0;
            //x = 0;
            for (int col = 0; col < row; col++)
            {
                //if (board[row - col][col] == opponent || board[row - col - 1][col + 1] == opponent)
                  //  x++;
                if (board[row - col][col] != '_' && board[row - col - 1][col + 1]!='_')
                {
                    if (board[row - col][col] == board[row - col - 1][col + 1])
                        licznik++;
                    

                    if (licznik > bestscore)
                    {
                        if (board[row - col][col] == player)
                            bestscore = licznik;

                    }

                    if (board[row - col][col] != board[row - col - 1][col + 1])
                        licznik = 0;

                    if (licznik == WYGRANA - 1)
                    {
                        if (board[row - col][col] == player)
                            return +1000;
                        if (board[row - col][col] == opponent)
                            return -1000;
                    }
                }
                //if (x > ROZMIAR - WYGRANA) bestscore = 0;
                if (board[row - col][col] == '_') licznik = 0;
            }
        }

        for (int row = ROZMIAR - 1; row > 0; row--)
        {
            licznik = 0;
            //x = 0;
            for (int col = ROZMIAR - 1; col > row; col--)
            {
                //if (board[row + (ROZMIAR - 1 - col)][col] == opponent || board[row + (ROZMIAR - 1 - col) + 1][col - 1] == opponent)
                 //   x++;
                if (board[row + (ROZMIAR - 1 - col)][col] != '_' && board[row + (ROZMIAR - 1 - col) + 1][col - 1]!='_')
                {
                    if (board[row + (ROZMIAR - 1 - col)][col] == board[row + (ROZMIAR - 1 - col) + 1][col - 1])
                        licznik++;
                    

                    if (licznik > bestscore)
                    {
                        if (board[row + (ROZMIAR - 1 - col)][col] == player)
                            bestscore = licznik;

                    }

                    if (board[row + (ROZMIAR - 1 - col)][col] != board[row + (ROZMIAR - 1 - col) + 1][col - 1])
                        licznik = 0;

                    if (licznik == WYGRANA - 1)
                    {
                        if (board[row + (ROZMIAR - 1 - col)][col] == player)
                            return +1000;
                        if (board[row + (ROZMIAR - 1 - col)][col] == opponent)
                            return -1000;
                    }
                }
                //if (x > ROZMIAR - WYGRANA) bestscore = 0;
                if (board[row + (ROZMIAR - 1 - col)][col] == '_') licznik = 0;

            }
        }

        for (int row = 0; row < ROZMIAR; row++)
        {
            licznik = 0;
            //x = 0;
            for (int col = 0; col < ROZMIAR - 1 - row; col++)
            {
                //if (board[row + col][col] == opponent || board[row + col + 1][col + 1] == opponent)
                 //   x++;
                if (board[row + col][col] != '_' && board[row + col + 1][col + 1] !='_')
                {
                    if (board[row + col][col] == board[row + col + 1][col + 1])
                        licznik++;
                    

                    if (licznik > bestscore)
                    {
                        if (board[row + col][col] == player)
                            bestscore = licznik;

                    }

                    if (board[row + col][col] != board[row + col + 1][col + 1])
                        licznik = 0;

                    if (licznik == WYGRANA - 1)
                    {
                        if (board[row + col][col] == player)
                            return +1000;
                        if (board[row + col][col] == opponent)
                            return -1000;
                    }
                }
               // if (x > ROZMIAR - WYGRANA) bestscore = 0;
                if (board[row + col][col] == '_') licznik = 0;
            }
        }

        for (int row = ROZMIAR - 2; row >= 0; row--)
        {
            licznik = 0;
            //x = 0;
            for (int col = ROZMIAR - 1; col > ROZMIAR - 1 - row; col--)
            {
                //if (board[row - (ROZMIAR - 1 - col)][col] == opponent || board[row - (ROZMIAR - 1 - col) - 1][col - 1] == opponent)
                  //  x++;
                if (board[row - (ROZMIAR - 1 - col)][col] != '_' && board[row - (ROZMIAR - 1 - col) - 1][col - 1]!='_')
                {
                    if (board[row - (ROZMIAR - 1 - col)][col] == board[row - (ROZMIAR - 1 - col) - 1][col - 1])
                        licznik++;
                   

                    if (licznik > bestscore)
                    {
                        if (board[row - (ROZMIAR - 1 - col)][col] == player)
                            bestscore = licznik;

                    }

                    if (board[row - (ROZMIAR - 1 - col)][col] != board[row - (ROZMIAR - 1 - col) - 1][col - 1])
                        licznik = 0;

                    if (licznik == WYGRANA - 1)
                    {
                        if (board[row - (ROZMIAR - 1 - col)][col] == player)
                            return +1000;
                        if (board[row - (ROZMIAR - 1 - col)][col] == opponent)
                            return -1000;
                    }
                }
                //if (x > ROZMIAR - WYGRANA) bestscore = 0;
                if (board[row - (ROZMIAR - 1 - col)][col] == '_') licznik = 0;

            }
        }

        return bestscore;
    }

    //Zwraca wiekszą z 2 wartości
    private int max(int a, int b)
    {
        if (a > b)
            return a;
        else
            return b;
    }

    //Zwarca mniejsza z 2 wartosci
    private int min(int a, int b)
    {
        if (a < b)
            return a;
        else
            return b;
    }

    //Algorytm minimax
    private int minimax(int depth, bool isMax)
    {
        int score = evaluate();
        //Debug.Log("Score = " + score);
        //Jezeli Maximizer wygral zwroc jego wygrany wynik
         if (score == 1000)
         return score;

        //Jezeli Minimizer wygral zwroc jego wygrany wynik
         if (score == -1000)
         return score;

        if (depth > MaxDepth)
            return  score;

        //Jezlei nie ma wiecej ruchow i nikt nie wygral zwroc 0 jako remis
        if (IsMoveLeft() == false)
            return 0;

        //Jezeli jest ruch maximizera
        if (isMax)
        {
            int best = -1000000;

            //Sprawdzanie wszystkich komorek
            for (int i = 0; i < ROZMIAR; i++)
            {
                for (int j = 0; j < ROZMIAR; j++)
                {
                    //Sprawdza kiedy komorki sa puste
                    if (board[i][j] == '_')
                    {
                        //Zrob ruch
                        board[i][j] = player;

                        //Sprawdz czy jest dobry
                        best = max(best, minimax(depth + 1, !isMax));
                       
                        //Cofnij ruch
                        board[i][j] = '_';
                    }
                }
            }
            return best;
        }

        //Jezeli jest ruch minimizera 
        else
        {
            int best = 1000000;

            //Sprawdzanie wszystkich komorek
            for (int i = 0; i < ROZMIAR; i++)
            {
                for (int j = 0; j < ROZMIAR; j++)
                {
                    //Sprawdza kiedy komorki sa puste
                    if (board[i][j] == '_')
                    {
                        //Zrob ruch
                        board[i][j] = opponent;
                    
                        //Sprawdz czy jest dobry
                        best = min(best, minimax(depth + 1, !isMax));
                        
                        //Cofnij ruch
                        board[i][j] = '_';
                    }
                }
            }
            return best;
        }
    }

    //Zwraca najlepszy możliwy ruch dla player
    private Move findBestMove()
    {

        int bestVal = -1000000;
        Move bestMove;
        bestMove.row = -1;
        bestMove.col = -1;

        for (int i = 0; i < ROZMIAR; i++)
        {
            for (int j = 0; j < ROZMIAR; j++)
            {
                //Sprawdza kiedy komorki sa puste
                if (board[i][j] == '_')
                {
                    //Zrob ruch
                    board[i][j] = player;

                    //wywolaj minimac dla tego ruchu
                    int moveVal = minimax(0, false);

                    //Cofnij Ruch
                    board[i][j] = '_';

                    //Debug.Log("w Ruhu [" + i + "] [" + j + "]  uzyskam" + moveVal + "w rzedzie");
                    //Debug.Log("Wartosc =" + moveVal);
                    //Jesli wykonany ruch jest bardziej oplacalny ustaw nowa wartosc
                    if (moveVal > bestVal)
                    {
                        bestMove.row = i;
                        bestMove.col = j;
                        bestVal = moveVal;
                        //Debug.Log("w Ruhu [" + i + "] [" + j + "]  uzyskam" + bestVal + "w rzedzie");
                    }
                }
               
            }
        }
        
        return bestMove;
    }

    //Zaktualizyj dane najlepszego ruchu
    public void MakeMove()
    {
        bestMove = findBestMove();

    }
    //Zwraca szukana wspolrzedna X
    public int GetX()
    {
     return bestMove.row;
    }
    //Zwraca szukana wspolrzedna Y
    public int GetZ()
    {
        return bestMove.col;
    }
    //Zrob najlepszy ruch
    public void Ruch()
    {
        board[bestMove.row][bestMove.col] = player;
    }

    //Dodaj ruch z myszki do tablicy
    public void Myszka(int a, int b)
    {
         board[a][b] = opponent;
    }

    public bool Czywolne(int a,int b)
    {
        if (board[a][b] == '_')
            return true;
        else
            return false;
    }
    
 
   


}
