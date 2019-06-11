using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Respawn : MonoBehaviour
{
    public Light lightPrefab;
    
    private int rozmiar = Settings.ROZMIAR;
    public GameObject podstawka;
    private GameObject P;
    void Start()
    {
        //Debug.Log(" Wywołalem sie");
        Vector3 vector = new Vector3(0,0,0);
        //Tworzenie obiektu podstawki
        //P = GameObject.Instantiate(podstawka);   //Stworzenie obiektu na scenie
        //P.name = "Podstawka";   //Zmiana nazwy Obiektu
        //P.transform.position = transform.position;  //Przypisanie polożenia stworzonego obiketu
        for (int j = 0; j < rozmiar; j++)
        {
            for (int i = 0; i < rozmiar; i++)
            {
                vector = new Vector3(2 * i, 0, 2 * j);
                P = GameObject.Instantiate(podstawka);
                P.transform.position = transform.position + vector * 1.1f;
            }
        }


        //Tworzenie obiektu swiatla
        Light light = GameObject.Instantiate(lightPrefab);  //Stworzenie obiektu na scenie
        light.color = Color.white;  //Ustawienie koloru swiatla
        light.intensity = 0.5f; //Ustawienie intensywnosci swiatla
        RenderSettings.ambientLight = Color.white * 0.7f;  //Sswietlenie ambientowe - oswietla kada czesc obiektu - z kazdej strony
    }

    
    void Update()
    {
        
    }
}
