using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraController : MonoBehaviour
{
    [Header("Speed")]   //Dyrektywa doajaca naglowek dla publicznych zmiennych w inspektorze
    public float scrollSpeed = 15;
    public float zoomSpeed = 25;
    public float rotationSpeed = 25;
    public float scrollKeyboardSpeed = 15;
    [Header("Limits")]
    public float minZoom = 40;
    public float maxZoom = 5;
    public Vector3 minPosition = new Vector3(-100, -100, -100);
    public Vector3 maxPosition = new Vector3(100, 100, 100);
    private GameObject contener;    //Odnosnik do CameraHolder
    private float scrollSpeedUp = 0;    //Pozwala przyspieszac przewijanie

    void Start()
    {
     
        contener = gameObject.transform.parent.gameObject;  //Ustawienie odnosnika do CameraHolder
    }


    void Update()
    {

        //Przyspieszanie za pomoca strzalek
        //jezeli zostanie nacisnieta dowolna strzalka to zwiekszana jest predkosc
        if (Input.GetButton("Horizontal") || Input.GetButton("Vertical"))
        {
            scrollSpeedUp = scrollKeyboardSpeed;
        }
        else
        {
            scrollSpeedUp = 0;
        }

        /*Zoomowanie
         * Wychwytywana zmiana scrolla myszki (Mozna zastosowac GetAxis lecz ta funckja po /10 da ten sam wynik a jest szybsza
         * po && sprawdzane jest czy nie zostal przekroczony limit
         */
        if ((Input.mouseScrollDelta.y / 10) > 0 && gameObject.transform.position.y > maxZoom)
            {
                gameObject.transform.Translate(Vector3.forward * Time.deltaTime * zoomSpeed);
            }
        if ((Input.mouseScrollDelta.y / 10) < 0 && gameObject.transform.position.y < minZoom)
            {
                 gameObject.transform.Translate(Vector3.back * Time.deltaTime * zoomSpeed);
            }

        /*Obracanie Kamery
         * Gdy zostanie nacisniete kolko myszki i przyblizony zostanie kursor myszki do jednej z krawedzi ekranu
         * nastepuje obrot kamery
         * UWAGA! Wlasnie tutaj jest potrzebny CameraHolder
         * gdyby nie on kamera obracalaby sie wokol wlasnej osi a nie wokol punktu na ktory jest skierowana kamera
         */
        if (Input.GetMouseButton(2))
        {
            //Analogicznie do przesuwania kamery jedynei zamiast Translate() jest Rotate()
            if ((Input.mousePosition.y >= Screen.height * 0.95 || Input.GetKey(KeyCode.UpArrow)) && contener.transform.position.z < maxPosition.y)
            {
                contener.transform.Rotate(Vector3.right * Time.deltaTime * rotationSpeed);
            }

            if ((Input.mousePosition.y <= Screen.height * 0.05 || Input.GetKey(KeyCode.DownArrow)) && contener.transform.position.z > minPosition.y)
            {
                contener.transform.Rotate(Vector3.left * Time.deltaTime * rotationSpeed);
            }
            if (Input.mousePosition.x <= Screen.width * 0.05 || Input.GetKey(KeyCode.LeftArrow))
            {
                contener.transform.Rotate(Vector3.down * Time.deltaTime * rotationSpeed);
            }

            if (Input.mousePosition.x >= Screen.width * 0.95 || Input.GetKey(KeyCode.RightArrow))
            {
                contener.transform.Rotate(Vector3.up * Time.deltaTime * rotationSpeed);
            }
        }
        //jesli nie zostanie nacisniety scroll na myszy to przesuwaj kamere w aktualnej plaszczyznie
        else
        {
            /*Kazdy if sprawdza czy pozycja myszki jest mniejsza od 5% szerokosci/wysokosci ekranu
             *albo czy jest wieksza od 95% szerokosci/wysokosci ekranu lub
             *jezeli nastepuje ruch - przy pomocy strzalki && pozycja CameraHolder jest mniejsza od limitu
             *to dokonany zostaje ruch contenra (CameraHold)
             */
            if ((Input.mousePosition.y >= Screen.height * 0.95 || Input.GetKey(KeyCode.UpArrow)) && contener.transform.position.z < maxPosition.y)
            {
                contener.transform.Translate(Vector3.forward * Time.deltaTime * (scrollSpeed + scrollSpeedUp));
            }

            if ((Input.mousePosition.y <= Screen.height * 0.05 || Input.GetKey(KeyCode.DownArrow)) && contener.transform.position.z > minPosition.y)
            {
                contener.transform.Translate(Vector3.back * Time.deltaTime * (scrollSpeed + scrollSpeedUp));
            }

            if ((Input.mousePosition.x <= Screen.width * 0.05 || Input.GetKey(KeyCode.LeftArrow)) && contener.transform.position.x > minPosition.x)
            {
                contener.transform.Translate(Vector3.left * Time.deltaTime * (scrollSpeed + scrollSpeedUp));
            }

            if ((Input.mousePosition.x >= Screen.width * 0.95 || Input.GetKey(KeyCode.RightArrow)) && contener.transform.position.x < maxPosition.x)
            {
                contener.transform.Translate(Vector3.right * Time.deltaTime * (scrollSpeed + scrollSpeedUp));
            }
        }
 
    }   
}
