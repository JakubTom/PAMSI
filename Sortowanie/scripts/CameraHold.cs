using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraHold : MonoBehaviour
{
    private GameObject Respawn;
    private int rozmiar = Settings.ROZMIAR;
    void Start()
    {
        /*
         * public GameObject Źródło;   tak jak u gory
            var zmienna = Źródło.wartość;

            jesli zmienna jest w skrypcie to:
            var zmienna = Źródło.GetComponent<NazwaSkryptu>().wartość;
         */
        //var rozmiar = CameraHoldPoint.GetComponent<Respawn>().rozmiar;
        // transform.position = new Vector3((rozmiar * 2 * 1.1f)/2, 0, (rozmiar * 2 * 1.1f) / 2);

        // Respawn = GameObject.FindWithTag("Respawn");
        // Respawn R = Respawn.GetComponent<Respawn>();
        //var rozmiar = R.rozmiar;
        transform.position = new Vector3((rozmiar * 2 * 1.1f) / 2, 0, (rozmiar * 2 * 1.1f) / 2);

    }

}
