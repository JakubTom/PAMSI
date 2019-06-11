using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class AI : MonoBehaviour
{
    public GameObject kolko;
    public GameObject krzyrzyk;
    private GameObject Objekt;
    private Vector3 vector = new Vector3(0, 5, 0);
    //public Respawn CameraHoldPoint;
    //private int ROZMIAR;
    private GameObject Plansza;
    Vector3 NowyPionek = new Vector3();
    //public Text GameOverText;
   //public GameObject game_over;

    private int XO;
    private int ZO;

    private int XX;
    private int ZX;

    void Start()
    {
        Plansza = GameObject.FindWithTag("Plansza");
        // var rozmiar = CameraHoldPoint.GetComponent<Respawn>().rozmiar;
        //ROZMIAR = rozmiar;
        
    }

    void Update()
    {   
         

    }
    private void OnMouseDown()
    {
        NowyPionek = transform.position;
        
        XX = (int)(NowyPionek.x / 2.2f);
        ZX = (int)(NowyPionek.z / 2.2f);
        Debug.Log("Kliknieto na obiekt o wspolrzednych x= " + XX + " z = " + ZX);
        Game game = Plansza.GetComponent<Game>();

        if (game.Czywolne(XX,ZX) && game.evaluate() != -1000 && game.evaluate() != 1000)
        {
            if (game.IsMoveLeft() == true)
            {
                //dodanie ruchu gracza do tablicy planszy
                game.Myszka(XX, ZX);

                //Dodanie obiektu na Plansze
                Objekt = GameObject.Instantiate(krzyrzyk);
                Objekt.transform.position = transform.position + vector;
            }

            if (game.evaluate() == -1000)
            {
                Debug.Log("Wygrales!");
               // game_over.SetActive(true);
               // GameOverText.text = "You won!";
            }

            if (game.IsMoveLeft() == true && game.evaluate() != -1000)
            {
                //Ruch komputera
                game.MakeMove();  //wywolanie funkcji findBestMove
                Debug.Log("Komputer rusza sie na X = " + game.GetX() + " z = " + game.GetZ());
                game.Ruch();    //Zaktualizowanie talicy 


                Objekt = GameObject.Instantiate(kolko);
                Objekt.transform.position = new Vector3(game.GetX() * 2.2f, 0, game.GetZ() * 2.2f) + vector;
            }

            if (game.evaluate() == 1000)
            {
                Debug.Log("Przegrałeś!");
                // game_over.SetActive(true);
                //GameOverText.text = "You lose!";
            }

            if (game.IsMoveLeft() == false && game.evaluate() != 1000 && game.evaluate() != -1000)
            {
                Debug.Log("Remis!");
                // game_over.SetActive(true);
                // GameOverText.text = "Draw!";
            }
        }

    }
}
